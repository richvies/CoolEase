#include <stdint.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>

#include "coolease/board_defs.h"
#include "coolease/serial_printf.h"
#include "coolease/sx126x.h"
#include "coolease/timers.h"

// SPI Comms Functions
#define spi_chip_select()         gpio_clear(GPIOA, GPIO_SPI_NSS)
#define spi_chip_deselect()       gpio_set(GPIOA, GPIO_SPI_NSS)

#define wait_while_busy()         while(gpio_get(GPIOA, GPIO_RF_BUSY))
#define wait_rf_io_1_high()       while(!(gpio_get(GPIOA, GPIO_RF_IO_1)))

// Volatile variable incremented by ISR in RX mode
static volatile uint8_t num_messges = 0;

static uint8_t spi_buf[10];

// Static Function Decls

static void     clock_setup(void);
static void     spi_setup(void);
static uint8_t  get_status(void);
static uint16_t get_irq_status(void);
static void     spi_transfer(uint8_t cmd, uint8_t *out_buffer, uint8_t out_len, uint8_t *in_buffer, uint8_t in_len);
static void     spi_write_single(uint8_t cmd, uint8_t out);
static void     set_frequency(uint32_t frequency_hz);
static void     calibrate_image(uint32_t frequency);
static void     set_dio_irq( uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask );
static void     clear_irq_status(uint16_t irq);
static void     set_standby_mode(void);
static void     set_tx_mode(void);
static void     set_rx_mode(void);
static void     set_sleep_mode(void);


// Global Function Definitions

void sx126x_init(void) 
{ 
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);

  // Configure device clock and spi port
  clock_setup();
  spi_setup();  

  // Config Inputs
  gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_RF_IO_1 | GPIO_RF_IO_2 | GPIO_RF_IO_3 | GPIO_RF_BUSY);  

  // Config Outputs 
  gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_RF_TX_SW | GPIO_RF_RX_SW | GPIO_RF_RESET);  
  gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_RF_TX_SW | GPIO_RF_RX_SW | GPIO_RF_RESET);

  // Close Both RX and TX Paths
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);

  spi_chip_deselect();

  sx126x_reset();

  set_standby_mode();
}

void sx126x_reset(void)
{
  // Reset device
  gpio_clear(GPIOB, GPIO_RF_RESET);
  timers_delay_milliseconds(1);

  gpio_set(GPIOB, GPIO_RF_RESET);
  timers_delay_milliseconds(1);

  set_standby_mode();

  // Get device status
  spf_serial_printf("Device Status: %02x\n", get_status());

  // Calibrate
  spi_write_single( SX126X_CMD_CALIBRATE, (SX126X_CALIBRATE_IMAGE_ON | SX126X_CALIBRATE_ADC_BULK_P_ON | SX126X_CALIBRATE_ADC_BULK_N_ON | SX126X_CALIBRATE_ADC_PULSE_ON | SX126X_CALIBRATE_PLL_ON | SX126X_CALIBRATE_RC13M_ON | SX126X_CALIBRATE_RC64K_ON) );

  // Set regulator mode
  spi_write_single(SX126X_CMD_SET_REGULATOR_MODE, SX126X_REGULATOR_LDO);

  // Set buffer base address
  spi_buf[0] = 0x00; spi_buf[1] = 0x00;
  spi_transfer(SX126X_CMD_SET_BUFFER_BASE_ADDRESS, spi_buf, 2, NULL, 0);

  // PA Config: DutyCycle, hpMax, deviceSel, paLut
  spi_buf[0] = 0x03; spi_buf[1] = 0x05; spi_buf[2] = 0x00; spi_buf[3] = 0x01;
  spi_transfer(SX126X_CMD_SET_PA_CONFIG, spi_buf, 4, NULL, 0);

  // Set overcurrent protection to 140mA
  spi_buf[0] = 0x08; spi_buf[1] = 0xE7; spi_buf[2] = 0x38;
  spi_transfer(SX126X_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  // Set power
  sx126x_set_power(0, SX126X_PA_RAMP_200U);
  
  // Set DIO Interrupts & Clear any pending
  set_dio_irq( SX126X_IRQ_NONE,  //all interrupts disabled
                      SX126X_IRQ_NONE, //interrupts on DIO1
                      SX126X_IRQ_NONE,  //interrupts on DIO2
                      SX126X_IRQ_NONE); //interrupts on DIO3
  
  clear_irq_status(SX126X_IRQ_ALL);

  // Calibrate image
  calibrate_image(SX126X_FREQUENCY);

  // Set frequency
  set_frequency(SX126X_FREQUENCY);
}

void sx126x_end(void)
{
  set_sleep_mode();

  // Close Both RX and TX Paths
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);

  spi_disable(SPI2);
  rcc_periph_clock_disable(RCC_SPI2);
}

void sx126x_config_for_lora(void) 
{
  // Select Lora as packet type
  spi_write_single(SX126X_CMD_SET_PACKET_TYPE, SX126X_PACKET_TYPE_LORA);

  spi_write_single(SX126X_CMD_STOP_TIMER_ON_PREAMBLE, false);
  spi_write_single(SX126X_CMD_SET_LORA_SYMB_NUM_TIMEOUT, 0);

  // Set Lora Syn Words
  spi_buf[0] = 0x07; spi_buf[1] = 0x40; spi_buf[2] = 0x32;
  spi_transfer(SX126X_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  spi_buf[0] = 0x07; spi_buf[1] = 0x41; spi_buf[2] = 0x32;
  spi_transfer(SX126X_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  // Modulation Params {spreadingFactor, bandwidth, codingRate, lowDataRateOptimize};
  spi_buf[0] = 0x07; spi_buf[1] = SX126X_LORA_BW_125_0; spi_buf[2] = SX126X_LORA_CR_4_5; spi_buf[3] = SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_OFF;
  spi_transfer(SX126X_CMD_SET_MODULATION_PARAMS, spi_buf, 4, NULL, 0);

  // Packet Params {preambleLength1, preambleLength2, Fixed length, Payload Length, CRC ON, InvertIQ OFF};
  spi_buf[0] = 0x00; spi_buf[1] = 0x06; spi_buf[2] = SX126X_LORA_HEADER_IMPLICIT; spi_buf[3] = SX126X_PACKET_LENGTH; spi_buf[4] = SX126X_LORA_CRC_OFF; spi_buf[5] = SX126X_LORA_IQ_STANDARD; 
  spi_transfer(SX126X_CMD_SET_PACKET_PARAMS, spi_buf, 6, NULL, 0);
}

void sx126x_config_for_gfsk(void)
{
  // Select GFSK as packet type
  spi_write_single(SX126X_CMD_SET_PACKET_TYPE, SX126X_PACKET_TYPE_GFSK);

  spi_write_single(SX126X_CMD_STOP_TIMER_ON_PREAMBLE, false);

  // Set GFSK Sync words
  spi_buf[0] = 0x06; spi_buf[1] = 0xC0; spi_buf[2] = 0x14;
  spi_transfer(SX126X_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  spi_buf[0] = 0x06; spi_buf[1] = 0xC1; spi_buf[2] = 0x24;
  spi_transfer(SX126X_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  // Modulation Params {br1, br2, br3, Gauss BT, BW, Fdev1, Fdev2, Fdev3};
  uint32_t br = 102400;
  uint32_t fdev = 19922;
  spi_buf[0] = br >> 16; spi_buf[1] = br >> 8; spi_buf[2] = br; spi_buf[3] = 0x09; spi_buf[4] = SX126X_GFSK_RX_BW_93_8; spi_buf[5] = fdev >> 16; spi_buf[6] = fdev >> 8; spi_buf[7] = fdev;
  spi_transfer(SX126X_CMD_SET_MODULATION_PARAMS, spi_buf, 8, NULL, 0);

  // Packet Params {preambleLength1, preambleLength2, Preamble detect, Sync Length, Addr Comp, Fixed Lengh, Payload length, CRC, Whitening};
  spi_buf[0] = 0x00; spi_buf[1] = 0x10; spi_buf[2] = 0x04; spi_buf[3] = 0x10; spi_buf[4] = 0x00; spi_buf[5] = 0x00; spi_buf[6] = 0x10; spi_buf[7] = 0x00; spi_buf[8] = 0x00;
  spi_transfer(SX126X_CMD_SET_PACKET_PARAMS, spi_buf, 9, NULL, 0);
}

void sx126x_set_power(int8_t power, uint8_t ramp_time)
{
    if( power > 22 )
    {
        power = 22;
    }
    else if( power < -3 )
    {
        power = -3;
    }
    
    spi_buf[0] = power; spi_buf[1] = ramp_time;
    spi_transfer(SX126X_CMD_SET_TX_PARAMS, spi_buf, 2, NULL, 0);
}

void sx126x_get_stats(uint8_t* stats)
{
  spi_transfer(SX126X_CMD_GET_STATS, NULL, 0, stats, 6);
}

void sx126x_reset_stats(void)
{
  spi_transfer(SX126X_CMD_RESET_STATS, NULL, 0, NULL, 0);
}


void sx126x_start_listening()
{
  // Go to standby
  set_standby_mode();       

  // Set buffer offset to 0
  spi_buf[0] = 0x00; spi_buf[1] = 0x00;
  spi_transfer(SX126X_CMD_SET_BUFFER_BASE_ADDRESS, spi_buf, 2, NULL, 0);

  // Open only RX path
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);
  gpio_set(GPIOB, GPIO_RF_RX_SW);   

  // Set RX Done IRQ on IO1
  set_dio_irq(SX126X_IRQ_RX_DONE | SX126X_IRQ_CRC_ERR, SX126X_IRQ_RX_DONE, SX126X_IRQ_CRC_ERR, SX126X_IRQ_NONE);
  clear_irq_status(SX126X_IRQ_ALL);

  // Enable interrupt on MCU for RX done
  exti_reset_request(EXTI6);
  exti_select_source(EXTI6, GPIOA);
	exti_set_trigger(EXTI6, EXTI_TRIGGER_RISING);
	exti_enable_request(EXTI6);
  	
	nvic_enable_irq(NVIC_EXTI4_15_IRQ);
  nvic_set_priority(NVIC_EXTI4_15_IRQ, 0);

  // Start listening
  set_rx_mode();
}

uint8_t sx126x_get_packet(sx126x_packet_t* packet) 
{
  if(!num_messges)
    return 0;

  // Enter standby mode while getting data
  set_standby_mode();

  // Get packet length and offset
  spi_transfer(SX126X_CMD_GET_RX_BUFFER_STATUS, NULL, 0, spi_buf, 2);

  // Read packet data at offset 0
  spi_buf[0] = 0;
  spi_transfer(SX126X_CMD_READ_BUFFER, spi_buf, 1, packet->data, SX126X_PACKET_LENGTH);

  // Get Packet Status
  // spi_transfer(SX126X_CMD_GET_PACKET_STATUS, NULL, 0, packet->packet_status, 3);

  // Check CRC
  if(gpio_get(GPIOA, GPIO_RF_IO_2))
    packet->crc_ok = false;
  else
    packet->crc_ok = true;

  // Clear interrupts 
  clear_irq_status(SX126X_IRQ_ALL);

  // Decrement number of pending messages
  num_messges--;

  // Set buffer offset to zero
  spi_buf[0] = 0x00; spi_buf[1] = 0x00;
  spi_transfer(SX126X_CMD_SET_BUFFER_BASE_ADDRESS, spi_buf, 2, NULL, 0);

  // Go back to listening
  set_rx_mode();
  
  return SX126X_PACKET_LENGTH;
}

bool sx126x_transmit_packet(sx126x_packet_t packet)
{
  // Used to signify error with send
  bool res = false;
 
  // Go to standby and set buffer offset
  set_standby_mode();       

  // Set buffer offset to 0
  spi_buf[0] = 0x00; spi_buf[1] = 0x00;
  spi_transfer(SX126X_CMD_SET_BUFFER_BASE_ADDRESS, spi_buf, 2, NULL, 0);

  // Close only TX path
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);
  gpio_set(GPIOB, GPIO_RF_TX_SW);   

  // Disable interrupts used for receiving data
  exti_disable_request(EXTI6);
	nvic_disable_irq(NVIC_EXTI4_15_IRQ);

  // Set TX Done IRQ on IO1
  set_dio_irq(SX126X_IRQ_TX_DONE, SX126X_IRQ_TX_DONE, SX126X_IRQ_NONE, SX126X_IRQ_NONE);
  clear_irq_status(SX126X_IRQ_ALL);

  // Write packet data.
  wait_while_busy();
  spi_chip_select();
  timers_delay_microseconds(1);
  wait_while_busy();

  spi_xfer(SPI2, SX126X_CMD_WRITE_BUFFER);                
  spi_xfer(SPI2, 0); 
  for(uint8_t i = 0 ; i < SX126X_PACKET_LENGTH ; i++)
    spi_xfer(SPI2, packet.data[i]); 
  
  spi_chip_deselect();     
  timers_delay_microseconds(1);

  // Enter TX state
  set_tx_mode();

  // Wait for TX to finish
  wait_rf_io_1_high();

  // Clear interrupt
  clear_irq_status(SX126X_IRQ_TX_DONE);

  // Go to standby and set buffer offset
  set_standby_mode(); 

  spi_buf[0] = 0x00; spi_buf[1] = 0x00;
  spi_transfer(SX126X_CMD_SET_BUFFER_BASE_ADDRESS, spi_buf, 2, NULL, 0);

  // Open Switch
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);

  // Return ok or error
  return res;
}

void sx126x_set_tx_continuous(void)
{
  // Open only TX path
  gpio_clear(GPIOB, GPIO_RF_TX_SW | GPIO_RF_RX_SW);
  gpio_set(GPIOB, GPIO_RF_TX_SW); 

  spi_transfer(SX126X_CMD_SET_TX_CONTINUOUS_WAVE, NULL, 0, NULL, 0);

  // Get device status
  spf_serial_printf("Device Status: %02x\n", get_status());
}

// Static Function Definitions

static void clock_setup(void)
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

static void spi_setup(void)
{
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_SPI2);

  gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_SPI_NSS);
  gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO_SPI_NSS);
  gpio_set(GPIOA, GPIO_SPI_NSS);

  gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_SPI_SCK | GPIO_SPI_MOSI | GPIO_SPI_MISO);
  gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO_SPI_SCK | GPIO_SPI_MOSI | GPIO_SPI_MISO);
  
  gpio_set_af(GPIOB, GPIO_AF0, GPIO_SPI_MOSI | GPIO_SPI_SCK | GPIO_SPI_MISO);
 
  rcc_periph_reset_pulse(RST_SPI2); 

  spi_disable(SPI2);
  spi_init_master(SPI2, SPI_CR1_BAUDRATE_FPCLK_DIV_8,
                    SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1,
                    SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
  spi_enable(SPI2);
}

static uint8_t get_status(void)
{
  spi_chip_select();
  timers_delay_milliseconds(1);
  wait_while_busy();

  uint8_t status = 0xFF;
  spi_xfer(SPI2, SX126X_CMD_GET_STATUS);
  status = spi_xfer(SPI2, SX126X_CMD_NOP);

  return status;   
}

static uint16_t get_irq_status(void)
{
  spi_transfer(SX126X_CMD_GET_IRQ_STATUS, NULL, 0, spi_buf, 2);
  spi_transfer(SX126X_CMD_GET_IRQ_STATUS, NULL, 0, spi_buf, 2);
  uint16_t irq_status = ( (spi_buf[0] << 8) | spi_buf[1] );

  return irq_status;
}

static void spi_transfer(uint8_t cmd, uint8_t* out_buffer, uint8_t out_len, uint8_t* in_buffer, uint8_t in_len)
{
  wait_while_busy();
  spi_chip_select();
  timers_delay_microseconds(1);

  wait_while_busy();

  spi_xfer(SPI2, cmd);                   

  for(uint8_t i = 0 ; i < out_len ; i++)
  {
    spi_xfer(SPI2, out_buffer[i]);     
  }        

  if(in_len)
  {
    // First byte is always status
    spi_xfer(SPI2, SX126X_CMD_NOP);

    for(uint8_t i = 0 ; i < in_len ; i++)
    {
      in_buffer[i] = spi_xfer(SPI2, SX126X_CMD_NOP);  
    } 
  }

  spi_chip_deselect();     
  timers_delay_microseconds(1);
}

static void spi_write_single(uint8_t cmd, uint8_t out)
{
  uint8_t out_buffer[1] = {out};
  spi_transfer(cmd, out_buffer, 1, NULL, 0);
}

static void set_frequency(uint32_t frequency_hz)
{
  frequency_hz /= 1000000;
  frequency_hz *= FREQ_CALC;

  uint8_t buf[4];
  buf[0] = (uint8_t)(frequency_hz >> 24);
  buf[1] = (uint8_t)(frequency_hz >> 16);
  buf[2] = (uint8_t)(frequency_hz >> 8);
  buf[3] = (uint8_t)(frequency_hz);

  spi_transfer(SX126X_CMD_SET_RF_FREQUENCY, buf, 4, NULL, 0);
}

static void calibrate_image(uint32_t frequency)
{
  uint8_t calFreq[2] = {0xE1, 0xE9};

  if( frequency > 900000000 )
  {
      calFreq[0] = 0xE1;
      calFreq[1] = 0xE9;
  }
  else if( frequency > 850000000 )
  {
      calFreq[0] = 0xD7;
      calFreq[1] = 0xDB;
  }
  else if( frequency > 770000000 )
  {
      calFreq[0] = 0xC1;
      calFreq[1] = 0xC5;
  }
  else if( frequency > 460000000 )
  {
      calFreq[0] = 0x75;
      calFreq[1] = 0x81;
  }
  else if( frequency > 425000000 )
  {
      calFreq[0] = 0x6B;
      calFreq[1] = 0x6F;
  }
  spi_transfer(SX126X_CMD_CALIBRATE_IMAGE, calFreq, 2, NULL, 0);
}

static void set_dio_irq( uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask )
{
    uint8_t buf[8];

    buf[0] = (uint8_t)((irqMask >> 8) & 0x00FF);
    buf[1] = (uint8_t)(irqMask & 0x00FF);
    buf[2] = (uint8_t)((dio1Mask >> 8) & 0x00FF);
    buf[3] = (uint8_t)(dio1Mask & 0x00FF);
    buf[4] = (uint8_t)((dio2Mask >> 8) & 0x00FF);
    buf[5] = (uint8_t)(dio2Mask & 0x00FF);
    buf[6] = (uint8_t)((dio3Mask >> 8) & 0x00FF);
    buf[7] = (uint8_t)(dio3Mask & 0x00FF);
    spi_transfer(SX126X_CMD_SET_DIO_IRQ_PARAMS, buf, 8, NULL, 0);
}

static void clear_irq_status(uint16_t irq)
{
    uint8_t buf[2];

    buf[0] = (uint8_t)(((uint16_t)irq >> 8) & 0x00FF);
    buf[1] = (uint8_t)((uint16_t)irq & 0x00FF);
    spi_transfer(SX126X_CMD_CLEAR_IRQ_STATUS, buf, 2, NULL, 0);
}

static void set_standby_mode(void)
{  
  spi_write_single(SX126X_CMD_SET_STANDBY, SX126X_STANDBY_RC);
}

static void set_tx_mode(void)
{  
  spi_buf[0] = 0x00;
  spi_buf[1] = 0x00;
  spi_buf[2] = 0x00;

  spi_transfer(SX126X_CMD_SET_TX, spi_buf, 3, NULL, 0);
}

static void set_rx_mode(void)
{
  // spi_buf[0] = (uint8_t) (SX126X_RX_TIMEOUT_INF >> 16);
  // spi_buf[1] = (uint8_t) (SX126X_RX_TIMEOUT_INF >> 8);
  // spi_buf[2] = (uint8_t) (SX126X_RX_TIMEOUT_INF);

  spi_buf[0] = 0x00;
  spi_buf[1] = 0x00;
  spi_buf[2] = 0x00;

  spi_transfer(SX126X_CMD_SET_RX, spi_buf, 3, NULL, 0);
}

static void set_sleep_mode(void)
{
  spi_write_single( SX126X_CMD_SET_SLEEP, (SX126X_SLEEP_START_COLD | SX126X_SLEEP_RTC_OFF) );
}

// Interrupt routines

void exti4_15_isr(void)
{
	exti_reset_request(EXTI6);
  clear_irq_status(SX126X_IRQ_RX_DONE);
  num_messges++;
}