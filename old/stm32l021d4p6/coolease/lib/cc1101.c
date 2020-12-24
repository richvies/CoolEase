#include <stdint.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>

#include "coolease/board_defs.h"
#include "coolease/cc1101.h"
#include "coolease/serial_printf.h"

static volatile cc1101_packet_t received_packet = {0};
static volatile uint8_t num_messges = 0;
static uint8_t PA_TABLE_VAL[8] = {0x03, 0x1d, 0x37, 0x50, 0x86, 0xcd, 0xc5, 0xc0};

/*
 * Global function definitions
 */

/*
 * cc1101_init
 * 
 * Initialize CC1101 radio
 */
void cc1101_init(void)
{
  // Configure device clock and spi port
  clock_setup();
  spi_setup();  

  // Config GDO0 as input
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_RF_GDO_0);          
  
  // Reset CC1101
  cc1101_reset();       

  // Put cc1101 in idle state
  set_idle_state();

  // Print config registers
  // print_config_regs();

  #ifdef _HUB
  // Open RF Switch
  rf_switch_open();
  #endif  
}

/*
 * cc1101_reset
 * 
 * Reset and reconfigure CC1101 registers
 * Also set tx power level to index 0
 */
void cc1101_reset(void) 
{
  // Strobe csn bit
  spi_chip_deselect();
  spi_chip_select();
  spi_chip_deselect();
  spi_chip_select();
  

  // Wait until MISO goes low & send reset command
  wait_miso_low();                          
  send_cmd_strobe(SRES);   
  wait_miso_low();                        
  spi_chip_deselect();

  // Reconfigure CC1101
  write_config_regs(); 

  // Configure PATABLE
  write_reg_burst(PATABLE, PA_TABLE_VAL, 8);
  cc1101_set_tx_pa_table_index(1);                         
}

/**
 * cc1101_end
 * 
 * Shut down CC1101
 * Disable spi perpheral and clock
 */
void cc1101_end(void)
{
  
  #ifdef _HUB
  // Open RF Switch
  rf_switch_open();
  #endif

  set_power_down_state();
  spi_disable(SPI1);
  rcc_periph_clock_disable(RCC_SPI1);   
}

/*
 * cc1101_transmit_packet
 * 
 * Send data packet via RF
 * 
 * 'packet'	Packet to be transmitted. First byte is the destination address
 *
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */
bool cc1101_transmit_packet(cc1101_packet_t packet)
{
  // Used to signify error with send
  bool res = false;
 
  // Go to idle state first & flush buffer
  set_idle_state();
  flush_tx_fifo();

  #ifdef _HUB
  // Close RF Switch
  rf_switch_close();
  #endif 

  // Disable interrupts used for receiving data
  exti_disable_request(EXTI0);
	nvic_disable_irq(NVIC_EXTI0_1_IRQ);

  // Put pakcet length at the first position of the TX FIFO
  write_reg_single(TXFIFO,  packet.length);
  
  // Write rest of packet data into the TX FIFO
  write_reg_burst(TXFIFO, packet.data, packet.length);

  // Enter TX state
  set_tx_state();

  // Wait for the sync word to be transmitted
  wait_gdo_0_high();

  // Wait until the end of the packet transmission
  wait_gdo_0_low();

  // Check that the TX FIFO is empty
  if((read_reg_single(TXBYTES, STATUS_REGISTER) & 0x7F) == 0)
    res = true;

  // Go to Idle state and flush buffer
  set_idle_state();
  flush_tx_fifo();       

  #ifdef _HUB
  // Open RF Switch
  rf_switch_open();
  #endif 

  // Return ok or error
  return res;
}

/*
 * cc1101_start_listening
 * 
 * Enter rx state
 * Close RF Switch if Hub
 */
void cc1101_start_listening(void)
{
  set_idle_state();       
  flush_rx_fifo(); 

  #ifdef _HUB
  // Close RF Switch
  rf_switch_close();
  #endif   

  exti_reset_request(EXTI0);
  exti_select_source(EXTI0, GPIOA);
	exti_set_trigger(EXTI0, EXTI_TRIGGER_FALLING);
	exti_enable_request(EXTI0);
  	
	nvic_enable_irq(NVIC_EXTI0_1_IRQ);
  nvic_set_priority(NVIC_EXTI0_1_IRQ, 0);

  set_rx_state();
}

/*
 * cc1101_get_packet
 * 
 * Read data packet from RX FIFO
 *
 * 'packet'	Container for the packet received
 * 
 * Return:
 * 	Amount of bytes received
 */
uint8_t cc1101_get_packet(cc1101_packet_t *packet)
{
  if(!num_messges)
    return 0;

  // Go to idle while getting data
  set_idle_state(); 

  // Get value of rxBytes register
  uint8_t rxBytes = read_reg_single(RXBYTES, STATUS_REGISTER);

  // Any byte waiting to be read and no overflow?
  if (rxBytes & 0x7F && !(rxBytes & 0x80))
  {
    // Read data length
    packet->length = read_reg_single(RXFIFO, CONFIG_REGISTER);

    // If packet is too long, discard it
    if (packet->length > CC1101_PACKET_DATA_LEN)
      packet->length = 0;
    
    else
    {
      // Read data packet
      read_reg_burst(packet->data, RXFIFO, packet->length);

      // Read RSSI
      packet->rssi = (read_reg_single(RXFIFO, CONFIG_REGISTER) / 2) - 74 ;

      // Read LQI and CRC_OK
      uint8_t val = read_reg_single(RXFIFO, CONFIG_REGISTER);
      packet->lqi = val & 0x7F;
      packet->crc_ok = val & 0x80;
    }
  }
  // No packet waiting in RX FIFO 
  else
    packet->length = 0;

  // Flush RX FIFO      
  flush_rx_fifo(); 

  // Back to RX state
  set_rx_state();

  num_messges--;

  // Return length of packet
  return packet->length;
}

/*
 * cc1101_set_tx_pa_table_index
 * 
 * Set PATABLE values
 * 
 * @param paLevel amplification value
 */
void cc1101_set_tx_pa_table_index(uint8_t paTableIndex)
{
  // Only values from 0 - 7 allowed
  if (paTableIndex > 7)
    paTableIndex = 7;

  // Selects PA Table index
  uint8_t reg = read_reg_single(FREND0, CONFIG_REGISTER);
  reg &= 0xF8;
  reg |= paTableIndex;

  write_reg_single(FREND0, reg);
}

/*
 * cc1101_change_channel
 * 
 * Change currently used channel
 * Value from 1 to 10
 */
void cc1101_change_channel(uint8_t chnl)
{
  write_reg_single(CHANNR, chnl);
}

/*
 * Enable external oscillator
 * Set sysclock -> 52MHz
 * Output clock for radio on MCO pin -> 26Mhz
 */
void clock_setup(void)
{
	// Enable MSI Osc 2.097Mhz
	rcc_osc_on(RCC_MSI);
	rcc_wait_for_osc_ready(RCC_MSI);

	// Set MSI to 2.097Mhz
	rcc_set_msi_range(5);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 2.097Mhz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 2.097Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 2.097Mhz

	// Set flash, 2.097Mhz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 2097000;
	rcc_apb1_frequency = 2097000;
	rcc_apb2_frequency = 2097000;
}

/*
 * Enable gpio & spi clocks
 * Reset and reconfigure gpio & spi peripheral
 */
void spi_setup(void)
{
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_SPI1);

  gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_SPI1_NSS);
  gpio_set(GPIOA, GPIO_SPI1_NSS);

  gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_SPI1_SCK | GPIO_SPI1_MOSI | GPIO_SPI1_MISO);
  
  gpio_set_af(GPIOA, GPIO_AF0, GPIO_SPI1_MOSI);
  gpio_set_af(GPIOA, GPIO_AF5, GPIO_SPI1_SCK | GPIO_SPI1_MISO);

  rcc_periph_reset_pulse(RST_SPI1); 

  spi_disable(SPI1);
  spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_32,
                    SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1,
                    SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
  spi_enable(SPI1);
}


/*
 * send_cmd_strobe
 * 
 * Send command strobe to the CC1101 IC via SPI
 * 
 * 'cmd'	Command strobe
 */     
uint8_t send_cmd_strobe(uint8_t cmd) 
{
  spi_chip_select();              // spi_chip_select CC1101
  wait_miso_low();                // Wait until MISO goes low

  // Send strobe command and read status byte
  uint8_t status_byte = spi_xfer(SPI1, cmd);

  spi_chip_deselect();             // spi_chip_deselect CC1101

  return status_byte;
}

/*
 * write_reg_single
 * 
 * Write single register into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'value'	Value to be writen
 */
void write_reg_single(uint8_t regAddr, uint8_t value) 
{
  spi_chip_select();          // spi_chip_select CC1101
  wait_miso_low();            // Wait until MISO goes low

  spi_xfer(SPI1, regAddr);    // Send register address
  spi_xfer(SPI1, value);      // Send value

  spi_chip_deselect();        // spi_chip_deselect CC1101
}

/*
 * read_reg_single
 * 
 * Read CC1101 register via SPI
 * 
 * 'regAddr'	Register address
 * 'regType'	Type of register: CONFIG_REGISTER or STATUS_REGISTER
 * 
 * Return:
 * 	Data byte returned by the CC1101 IC
 */
uint8_t read_reg_single(uint8_t regAddr, uint8_t regType)
{
  uint8_t addr, val;
  addr = regAddr | regType;

  spi_chip_select();                // spi_chip_select CC1101
  wait_miso_low();                  // Wait until MISO goes low

  spi_xfer(SPI1, addr);             // Send register address
  val = spi_xfer(SPI1, 0xFF);       // Transmit Dummy & Read result    

  spi_chip_deselect();              // spi_chip_deselect CC1101

  return val;
}

/*
 * write_reg_burst
 * 
 * Write multiple registers into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'buffer'	Data to be writen
 * 'len'	Data length
 */
void write_reg_burst(uint8_t regAddr, uint8_t *buffer, uint8_t len)
{
  uint8_t addr, i;
  addr = regAddr | WRITE_BURST;             // Enable burst transfer

  spi_chip_select();                        // spi_chip_select CC1101
  wait_miso_low();                          // Wait until MISO goes low

  spi_xfer(SPI1, addr);                     // Send register address
  for(i=0 ; i<len ; i++)
    spi_xfer(SPI1, buffer[i]);              // Send value

  spi_chip_deselect();                      // spi_chip_deselect CC1101  
}

/*
 * read_reg_burst
 * 
 * Read burst data from CC1101 via SPI
 * 
 * 'buffer'	Buffer where to copy the result to
 * 'regAddr'	Register address
 * 'len'	Data length
 */
void read_reg_burst(uint8_t *buffer, uint8_t regAddr, uint8_t len) 
{
  uint8_t addr, i;
  addr = regAddr | READ_BURST;

  spi_chip_select();                             // spi_chip_select CC1101
  wait_miso_low();                        // Wait until MISO goes low

  spi_xfer(SPI1, addr);                 // Send register address
  for(i=0 ; i<len ; i++)
    buffer[i] = spi_xfer(SPI1, 0xFF);    // Read result byte by byte

  spi_chip_deselect();                           // spi_chip_deselect CC1101
}


/*
 * setCCregs
 * 
 * Configure CC1101 registers
 */
void write_config_regs(void) 
{
  write_reg_single(IOCFG2,0x2E);  //GDO2 Output Pin Configuration
  write_reg_single(IOCFG1,0x2E);  //GDO1 Output Pin Configuration
  write_reg_single(IOCFG0,0x06);  //GDO0 Output Pin Configuration

  #include "../cc1101_settings/ASK_868_10k.h"
}

/*
 * printCCregs
 * 
 * Print CC1101 registers on serial port
 * serial_print() must be implemented
 */
void print_config_regs(void) 
{
  for(int i = 0x00; i <= 0x2E; i++)
    spf_serial_printf("Register %02x: %02x\n", i, read_reg_single(i, CONFIG_REGISTER));

  for(int i = 0x2F; i <= 0x3E; i++)
    spf_serial_printf("Register %02x: %02x\n", i, read_reg_single(i, STATUS_REGISTER));
}


/*
 * set_power_down_state
 * 
 * Put CC1101 into power-down state
 */
void set_power_down_state(void) 
{
  // Comming from RX state, we need to enter the IDLE state first
  set_idle_state();

  // Enter Power-down state
  set_pwd_state();
}

void exti0_1_isr(void)
{
	exti_reset_request(EXTI0);
  num_messges++;
}