#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/adc.h>

#include "si4432.h"
#include "coolease/serial_printf.h"

/*
 * SI4432 status registers
 */
#define DEV_TYPE 0x00
#define DEV_VERSION 0x01
#define DEV_STATUS 0x02
#define INT_STATUS_1 0x03
#define INT_STATUS_2 0x04

/*
 * SI4432 configuration registers
 */
#define INT_ENABLE_1 0x05
#define INT_ENABLE_2 0x06
#define OPERATION_CONTROL_1 0x07
#define OPERATION_CONTROL_2 0x08

#define IF_FILTER_BW 0x1C
#define FREQ_DEVIATION 0x72
#define FREQ_OFFSET_1 0x73
#define FREQ_OFFSET_2 0x74
#define FREQBAND 0x75
#define FREQCARRIER_H 0x76
#define FREQCARRIER_L 0x77
#define FREQCHANNEL 0x79
#define CHANNEL_STEPSIZE 0x7A

#define MODULATION_MODE_1 0x70
#define MODULATION_MODE_2 0x71
#define TX_DATARATE_1 0x6E
#define TX_DATARATE_0 0x6F
#define TX_POWER 0x6D

#define HEADER_CONTROL_1 0x32
#define HEADER_CONTROL_2 0x33
#define PREAMBLE_LENGTH 0x34
#define PREAMBLE_DETECTION 0x35
#define SYNC_WORD_3 0x36
#define SYNC_WORD_2 0x37
#define TRANSMIT_PK_LEN 0x3E
#define RECEIVED_PK_LEN 0x4B
#define FIFO 0x7F

#define AFC_LOOP_GEARSHIFT_OVERRIDE 0x1D
#define AFC_TIMING_CONTROL 0x1E
#define CLOCK_RECOVERY_GEARSHIFT 0x1F
#define CLOCK_RECOVERY_OVERSAMPLING 0x20
#define CLOCK_RECOVERY_OFFSET_2 0x21
#define CLOCK_RECOVERY_OFFSET_1 0x22
#define CLOCK_RECOVERY_OFFSET_0 0x23
#define CLOCK_RECOVERY_TIMING_GAIN_1 0x24
#define CLOCK_RECOVERY_TIMING_GAIN_0 0x25
#define AFC_LIMITER 0x2A
#define AGC_OVERRIDE 0x69

#define DATAACCESS_CONTROL 0x30
#define EZMAC_STATUS 0x31


/*
 * SI4432 status & interrupts
 */
// DEV_STATUS
#define DEV_STATUS_RX_EMPTY		(1 << 5)

// INT_1
#define INT_1_FIFO_ERR	(1 << 7)
#define INT_1_PK_SENT	(1 << 2)
#define INT_1_PK_VALID	(1 << 1)
#define INT_1_CRC_ERR	(1 << 0)

// INT_2
#define INT_2_SYNC_DET	(1 << 7)
#define INT_2_PRE_DET	(1 << 6)
#define INT_2_CHIP_RDY	(1 << 1)
#define INT_2_POR		(1 << 0)


/*
 * Useful one line function definitions 
 */

// Radio States
#define set_state_standby() 	write_reg_single(OPERATION_CONTROL_1, 0x00)
#define set_state_ready() 		write_reg_single(OPERATION_CONTROL_1, 0x01)
#define set_state_rx() 			write_reg_single(OPERATION_CONTROL_1, 0x04)
#define set_state_tx() 			write_reg_single(OPERATION_CONTROL_1, 0x08)
#define set_state_reset() 		write_reg_single(OPERATION_CONTROL_1, 0x80)

// Interrupt pin
#define GPIO_IRQ				GPIO3			

/*
 * Static function decls
 */
static void clock_setup(void);
static void spi_setup(void);

static void spi_chip_select(void);
static void spi_chip_deselect(void);
static bool interrupt_pending(void);
static void wait_for_interrupt(void);

static void write_reg_single(uint8_t reg, uint8_t value);
static uint8_t read_reg_single(uint8_t reg);
static void write_reg_burst(uint8_t reg_addr, const uint8_t buffer[], uint8_t len);
static void read_reg_burst(uint8_t reg_addr, uint8_t buffer[], uint8_t len);

static void write_config_regs(void);
static void print_config_regs(void);

static void flush_tx_fifo(void);
static void flush_rx_fifo(void);
static void flush_fifo(void);

/*
 * Global function definitions
 */

/*
 * si4432_init
 * 
 * Initialize SI4432 radio
 */
void si4432_init() 
{
  // Configure device clock and spi port
  clock_setup();
  spi_setup();  

  // Config GDO0/ GDO1 (radio events/ interrupts) as inputs
  gpio_set_mode(GPIOA,                 
                GPIO_MODE_INPUT, 
                GPIO_CNF_INPUT_FLOAT, GPIO_IRQ);          
  
  // Reset si4432
  si4432_reset();       
}

/*
 * si4432_reset
 * 
 * Reset and reconfigure si4432 uint8_t
 * Also set tx power level to index 0
 */
void si4432_reset(void) 
{
  	// Strobe csn bit
  	spi_chip_deselect();
  	spi_chip_select();
  	spi_chip_deselect();
  	spi_chip_select();

	// Reset radio and wait until ready
	set_state_reset();	
	wait_for_interrupt();

	// Clear interrupts
	read_reg_single(INT_STATUS_1);
	read_reg_single(INT_STATUS_2);
	
	// Disable all interrupts
	write_reg_single(INT_ENABLE_1, 0x00);             
	write_reg_single(INT_ENABLE_2, 0x00);  

	// Put radio in standby
	set_state_standby();
	
  	// Reconfigure si4432 registers
  	write_config_regs();    
	print_config_regs();            
}

/**
 * si4432_end
 * 
 * Shut down si4432
 * Disable spi perpheral and clock
 */
void si4432_end(void)
{
  set_state_standby();
  spi_disable(SPI1);
  rcc_periph_clock_disable(RCC_SPI1);
}

/*
 * si4432_transmit_packet
 * 
 * Send data packet via RF
 * 
 * 'packet'	Packet to be transmitted. First byte is the destination address
 *
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */
bool si4432_transmit_packet(si4432_packet_t packet) 
{
	// Clear transmit FIFO
	flush_tx_fifo();

	// Set transmit packet length
	write_reg_single(TRANSMIT_PK_LEN, packet.length);

	// Fill FIFO with data to send
	write_reg_burst(FIFO, packet.data, packet.length);

	// Enable package sent & FIFO error interrupts
	write_reg_single(INT_ENABLE_1, INT_1_PK_SENT|INT_1_FIFO_ERR);
	write_reg_single(INT_ENABLE_2, 0x00);

	// Clear interrupts
	read_reg_single(INT_STATUS_1);
	read_reg_single(INT_STATUS_2);

	// Transmit packet
	set_state_tx();

	// Wait for packet sent or FIFO error
	wait_for_interrupt();

	// Enter standby
	set_state_standby();

	// Read/ Clear interrupt register
	uint8_t interrupt = read_reg_single(INT_STATUS_1);

	// Disable interrupts
	write_reg_single(INT_ENABLE_1, 0x00);

	// If packet sent, return true
	if (interrupt & INT_1_PK_SENT)
		return true;

	// If FIFO error, flush fifo
	else if(interrupt & INT_1_FIFO_ERR)
		flush_fifo();

	// Default return false
	return false;
}

/*
 * si4432_start_listening
 * 
 * Clear transmit fifo
 * Enable interrupts
 * Enter receive state
 */
void si4432_start_listening(void) 
{
	flush_rx_fifo();

	// Enable FIFO error, valid packet received & CRC error interrupts
	write_reg_single(INT_ENABLE_1, INT_1_FIFO_ERR | INT_1_PK_VALID | INT_1_CRC_ERR);
	write_reg_single(INT_ENABLE_2, 0x00);

	//read interrupt uint8_t to clean them
	read_reg_single(INT_STATUS_1);
	read_reg_single(INT_STATUS_2);

	set_state_rx();
}

/*
 * si4432_get_packet
 * 
 * Read data packet from RX FIFO
 *
 * 'packet'	Container for the packet received
 * 
 * Return:
 * 	Amount of bytes received
 */
uint8_t si4432_get_packet(si4432_packet_t *packet) 
{
	// Default return value
	packet->length = 0;

	if(interrupt_pending())
	{
		// Enter ready state until packet is dealt with
		set_state_ready();

		// Read interrupt register
		uint8_t interrupt = read_reg_single(INT_STATUS_1);

		// Disable interrupts
		write_reg_single(INT_ENABLE_1, 0x00);

		// If valid packet received
		if(interrupt & INT_1_PK_VALID)
		{
			// Get recived packet length
			packet->length = read_reg_single(RECEIVED_PK_LEN);

			// Get received packet data
			read_reg_burst(FIFO, packet->data, packet->length);
		}

		flush_rx_fifo();
	}
	
	return packet->length;
}

/*
 * si4432_change_channel
 * 
 * Change currently used channel
 * Value from 1 to 10
 */
void si4432_change_channel(uint8_t chnl) 
{
	write_reg_single(FREQCHANNEL, chnl);
}


/*
 * Static function definitions
 */

/*
 * Enable internal oscillator
 * Set sysclock -> 8MHz
 */
static void clock_setup(void)
{
	// Enable HSI Osc 8Mhz
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	// Select HSI as SYSCLK Source
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	// Set prescalers for AHB, ADC, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);		// AHB -> 8MHz
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);		// ADC -> 4MHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_NODIV);		// APB1 -> 8Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);		// APB2 -> 8MHz

	// Set flash, 8MHz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 8000000;
	rcc_apb1_frequency = 8000000;
	rcc_apb2_frequency = 8000000;
}

/*
 * Enable gpio & spi clocks
 * Reset and reconfigure gpio & spi peripheral
 */
static void spi_setup(void)
{
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_SPI1);

  gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO_SPI1_NSS);
  gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_SPI1_SCK|GPIO_SPI1_MOSI);
  gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO_SPI1_MISO);

  gpio_set(GPIOA, GPIO_SPI1_NSS);

  rcc_periph_reset_pulse(RST_SPI1); 

  spi_disable(SPI1);
  spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_4,
                    SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1,
                    SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
  spi_enable(SPI1);
}


static void spi_chip_select(void)
{
	gpio_clear(GPIOA, GPIO_SPI1_NSS);
	__asm__("nop");
	__asm__("nop");
}

static void spi_chip_deselect(void)
{
	gpio_set(GPIOA, GPIO_SPI1_NSS);
}   

static bool interrupt_pending(void)
{
	return gpio_get(GPIOA, GPIO_IRQ) ? false : true;
}

static void wait_for_interrupt(void)
{
	while(gpio_get(GPIOA, GPIO_IRQ))
		__asm__("nop");
}


static void write_reg_single(uint8_t reg, uint8_t value) 
{
	write_reg_burst(reg, &value, 1);
}

static uint8_t read_reg_single(uint8_t reg) 
{
	uint8_t val = 0xFF;
	read_reg_burst(reg, &val, 1);
	return val;
}

static void write_reg_burst(uint8_t reg_addr, const uint8_t buffer[], uint8_t len) 
{

	uint8_t addr = (uint8_t) reg_addr | 0x80; 	// set MSB

  	spi_chip_select();                         	// spi_chip_select SI4432

  	spi_xfer(SPI1, addr);             			// Send register address
  	for(int i=0 ; i<len ; i++)
  	  spi_xfer(SPI1, buffer[i]);      			// Send value

  	spi_chip_deselect();                       // spi_chip_deselect SI4432  
}

static void read_reg_burst(uint8_t reg_addr, uint8_t buffer[], uint8_t len) 
{
	uint8_t addr = (uint8_t) reg_addr & 0x7F; 	// clear MSB

  	spi_chip_select();                     		// spi_chip_select SI4432

  	spi_xfer(SPI1, addr);                 		// Send register address
  	for(int i=0 ; i<len ; i++)
  	  buffer[i] = spi_xfer(SPI1, 0xFF);    		// Read result byte by byte

  	spi_chip_deselect();                     	// spi_chip_deselect SI4432
}


static void write_config_regs() 
{
	write_reg_single(IF_FILTER_BW, 0x8E);
	write_reg_single(FREQ_DEVIATION, 0xE8);
	write_reg_single(FREQ_OFFSET_1, 0x00);
	write_reg_single(FREQ_OFFSET_2, 0x00);
	write_reg_single(FREQBAND, 0x73);
	write_reg_single(FREQCARRIER_H, 0x64);
	write_reg_single(FREQCARRIER_L, 0x00);
	write_reg_single(FREQCHANNEL, 0x00);
	write_reg_single(CHANNEL_STEPSIZE, 0x00);

	write_reg_single(MODULATION_MODE_1, 0x2C);
	write_reg_single(MODULATION_MODE_2, 0x07);
	write_reg_single(TX_DATARATE_1, 0x09);
	write_reg_single(TX_DATARATE_0, 0xD2);
	write_reg_single(TX_POWER, 0x18);

	write_reg_single(HEADER_CONTROL_1, 0x00);
	write_reg_single(HEADER_CONTROL_2, 0x02);
	write_reg_single(SYNC_WORD_3, 0xD3);
	write_reg_single(SYNC_WORD_2, 0x91);

	write_reg_single(AFC_LOOP_GEARSHIFT_OVERRIDE, 0x3C);
	write_reg_single(AFC_TIMING_CONTROL, 0x02);
	write_reg_single(CLOCK_RECOVERY_GEARSHIFT, 0x03);
	write_reg_single(CLOCK_RECOVERY_OVERSAMPLING, 0x18);
	write_reg_single(CLOCK_RECOVERY_OFFSET_2, 0xE0);
	write_reg_single(CLOCK_RECOVERY_OFFSET_1, 0x03);
	write_reg_single(CLOCK_RECOVERY_OFFSET_0, 0x46);
	write_reg_single(CLOCK_RECOVERY_TIMING_GAIN_1, 0x00);
	write_reg_single(CLOCK_RECOVERY_TIMING_GAIN_0, 0x02);
	write_reg_single(AFC_LIMITER, 0xFF);
	write_reg_single(AGC_OVERRIDE, 0x60);

	write_reg_single(DATAACCESS_CONTROL, 0x85);
}

static void print_config_regs() 
{

	uint8_t allValues[0x7F];

	read_reg_burst(DEV_TYPE, allValues, 0x7F);

	for (uint8_t i = 0; i < 0x7f; ++i)
		spf_serial_printf("REG %02x = %02x", (int) DEV_TYPE + i, (int) allValues[i]);

}


static void flush_tx_fifo() 
{
	write_reg_single(OPERATION_CONTROL_2, 0x01);
	write_reg_single(OPERATION_CONTROL_2, 0x00);
}

static void flush_rx_fifo() 
{
	write_reg_single(OPERATION_CONTROL_2, 0x02);
	write_reg_single(OPERATION_CONTROL_2, 0x00);
}

static void flush_fifo() 
{
	write_reg_single(OPERATION_CONTROL_2, 0x03);
	write_reg_single(OPERATION_CONTROL_2, 0x00);
}

