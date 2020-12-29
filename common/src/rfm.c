/**
 ******************************************************************************
 * @file    rfm.c
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Rfm Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "common/rfm.h"

#include <stdint.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/cm3/nvic.h>

#include "common/board_defs.h"
#include "common/serial_printf.h"
#include "common/timers.h"


/** @addtogroup  RFM_FILE
 * @{
 */

/** @addtogroup  RFM_INT
 *  @{
 */

/** @brief  Set RFM NSS Pin. Start SPI transaction
 */
#define spi_chip_select()         gpio_clear(RFM_SPI_NSS_PORT, RFM_SPI_NSS)

/** @brief  Clear RFM NSS Pin. End SPI transaction
 */
#define spi_chip_deselect()       gpio_set(RFM_SPI_NSS_PORT, RFM_SPI_NSS)

/** @brief  Stalls until RFM IO Pin 0 is asserted high
 * 
 * RFM is setup to assert this pin upon succesful transmission of a packet.
 * See @ref rfm_transmit_packet()
 */
#define wait_rf_io_0_high()       while(!(gpio_get(RFM_IO_0_PORT, RFM_IO_0)))

/** @} */

/** @addtogroup  RFM_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Signals if automatic CRC checking is currently enabled on the RFM */
static bool crc_on              = false;
static uint8_t random_data[16]  = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};


// Updated when packet received 
static uint8_t      packets_head = 0;
static uint8_t      packets_tail = 0;
static uint8_t      packets_read = 0;
static rfm_packet_t packets_buf[PACKETS_BUF_SIZE];

/** @} */

/** @addtogroup  RFM_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void clock_setup(void);
static void spi_setup(void);
static uint8_t spi_read_single(uint8_t reg);
static void spi_read_burst(uint8_t reg, uint8_t *buf, uint8_t len);
static void spi_write_single(uint8_t reg, uint8_t data);
static void spi_write_burst(uint8_t reg, uint8_t *buf, uint8_t len);
static void set_frequency(uint32_t frequency_hz);
static void set_dio_irq(uint8_t io0_3, uint8_t io4_5);
static void set_preamble_length(uint16_t num_sym);
static void print_registers(void);
static void clear_buffer(void);
static inline void mask_irq(uint8_t irq);
static inline void unmask_irq(uint8_t irq);
static inline uint8_t get_irq(void);
static inline void clear_irq(uint8_t irq);
static inline void set_standby_mode(void);
static inline void set_tx_mode(void);
static inline void set_rx_mode(void);
static inline void set_sleep_mode(void);

/** @} */


/** @addtogroup    RFM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Initialize radio module
 *     
 * Initializes the clock and spi peripheral
 * Resets the radio and configures for LORA    
 */
void rfm_init(void) 
{ 
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_SYSCFG);

  // Configure device clock and spi port
  clock_setup();
  spi_setup();  

  // Config Inputs
  gpio_mode_setup(RFM_IO_0_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_0);
  gpio_mode_setup(RFM_IO_1_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_1);
  gpio_mode_setup(RFM_IO_2_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_2);
  gpio_mode_setup(RFM_IO_3_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_3);
  gpio_mode_setup(RFM_IO_4_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_4);
  gpio_mode_setup(RFM_IO_5_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, RFM_IO_5);

  // Config Output 
  gpio_mode_setup(RFM_RESET_PORT,         GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, RFM_RESET);  
  gpio_set_output_options(RFM_RESET_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, RFM_RESET);
  gpio_set(RFM_RESET_PORT, RFM_RESET);

  spi_chip_deselect();

  set_sleep_mode();

  rfm_reset();

  spf_serial_printf("RFM Init Done\n");
}

void rfm_reset(void)
{
  // Reset device
  gpio_clear(RFM_RESET_PORT, RFM_RESET);
  timers_delay_milliseconds(1);

  gpio_set(RFM_RESET_PORT, RFM_RESET);
  timers_delay_milliseconds(1);

  timers_delay_milliseconds(10);

  print_registers();

  set_sleep_mode();

  spf_serial_printf("RFM Reset Done\n");
}

void rfm_end(void)
{
  set_standby_mode();
  set_sleep_mode();

  spi_disable(RFM_SPI);
  rcc_periph_clock_disable(RFM_SPI_RCC);

  spf_serial_printf("RFM End Done\n");
}

void rfm_calibrate_crystal(void)
{
  // Use ClkOut to calibrate crystal
}

void rfm_config_for_lora(uint8_t BW, uint8_t CR, uint8_t SF, bool crc_turn_on, int8_t power) 
{
  // Go to sleep mode to be able to change packet type
  set_sleep_mode();

  // Select Lora as packet type
  spi_write_single(RFM_REG_01_OP_MODE, RFM_MODE_SLEEP | RFM_LONG_RANGE_MODE);

  // Go to standby mode to set other parameters
  set_standby_mode();

  // print_registers();

  // Set frequency
  set_frequency(868000000);

  // Set power
  rfm_set_power(power, RFM_PA_RAMP_40US);

  // Set RX Timeout
  spi_write_single(RFM_REG_1F_SYMB_TIMEOUT_LSB, 0x64);
  
  // Actual preamble length = value + 4
  set_preamble_length(6);

  // Set Bandwidth, Coding rate & Turn off explicit header
  spi_write_single(RFM_REG_1D_MODEM_CONFIG1, BW | CR | 1);
  // spi_write_single(RFM_REG_1D_MODEM_CONFIG1, BW | CR | !explicit_header_turn_on);
  // explicit_header_on = explicit_header_turn_on;

  // // FSK Register settings for CRC
  // if(crc_turn_on)
  // {
  //   spf_serial_printf("Turn on CRC\n");

  //   // Access Shared Registers
  //   spi_write_single(RFM_REG_01_OP_MODE, ( spi_read_single(RFM_REG_01_OP_MODE) | RFM_ACCESS_SHARED_REG ));

  //   // RegPacketConfig1 (0x30)
  //   spi_write_single(0x30, 0x18 );

  //   // Access back to LORA Registers
  //   spi_write_single(RFM_REG_01_OP_MODE, ( spi_read_single(RFM_REG_01_OP_MODE) & ~RFM_ACCESS_SHARED_REG ));
  // }

  // Set Spreading factor and CRC
  spi_write_single(RFM_REG_1E_MODEM_CONFIG2, SF | (crc_turn_on << 2));
  crc_on = crc_turn_on;

  // Pg. 24 settings if SF = 6, Header must be implicit and change a couple of register values
  if(SF == RFM_SPREADING_FACTOR_64CPS)
  {
    spi_write_single(0x31, (spi_read_single(0x31) & ~0xF8) | 0x05);
    spi_write_single(0x37, 0x0C);
  }

  // Set Packet Length
  spi_write_single(RFM_REG_22_PAYLOAD_LENGTH, RFM_PACKET_LENGTH);

  // spi_write_single(RFM_REG_0C_LNA, 0x20);
  // spi_write_single(RFM_REG_26_MODEM_CONFIG3, 0x00);

  // print_registers();

  // Go to sleep mode
  set_sleep_mode();
}

void rfm_config_for_gfsk(void)
{
  // // Select GFSK as packet type
  // spi_write_single(RFM_CMD_SET_PACKET_TYPE, RFM_PACKET_TYPE_GFSK);

  // spi_write_single(RFM_CMD_STOP_TIMER_ON_PREAMBLE, false);

  // // Set GFSK Sync words
  // spi_buf[0] = 0x06; spi_buf[1] = 0xC0; spi_buf[2] = 0x14;
  // spi_transfer(RFM_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  // spi_buf[0] = 0x06; spi_buf[1] = 0xC1; spi_buf[2] = 0x24;
  // spi_transfer(RFM_CMD_WRITE_REGISTER, spi_buf, 3, NULL, 0);

  // // Modulation Params {br1, br2, br3, Gauss BT, BW, Fdev1, Fdev2, Fdev3};
  // uint32_t br = 102400;
  // uint32_t fdev = 19922;
  // spi_buf[0] = br >> 16; spi_buf[1] = br >> 8; spi_buf[2] = br; spi_buf[3] = 0x09; spi_buf[4] = RFM_GFSK_RX_BW_93_8; spi_buf[5] = fdev >> 16; spi_buf[6] = fdev >> 8; spi_buf[7] = fdev;
  // spi_transfer(RFM_CMD_SET_MODULATION_PARAMS, spi_buf, 8, NULL, 0);

  // // Packet Params {preambleLength1, preambleLength2, Preamble detect, Sync Length, Addr Comp, Fixed Lengh, Payload length, CRC, Whitening};
  // spi_buf[0] = 0x00; spi_buf[1] = 0x10; spi_buf[2] = 0x04; spi_buf[3] = 0x10; spi_buf[4] = 0x00; spi_buf[5] = 0x00; spi_buf[6] = 0x10; spi_buf[7] = 0x00; spi_buf[8] = 0x00;
  // spi_transfer(RFM_CMD_SET_PACKET_PARAMS, spi_buf, 9, NULL, 0);
}

void rfm_set_power(int8_t power, uint8_t ramp_time)
{
  if( power > 20 )
      power = 20;
  // else if( power < -3 )
  //     power = -3;

  if(ramp_time > 0x0F)
    ramp_time = 0x0F;

  // Pout = 2 + OutputPower (+3dBm if DAC enabled)
  spi_write_single(RFM_REG_4D_PA_DAC, (spi_read_single(RFM_REG_4D_PA_DAC) & ~RFM_PA_DAC_MASK) | RFM_PA_DAC_DISABLE);

	// Set the MaxPower register to 0x7 => MaxPower = 10.8 + 0.6 * 7 = 15dBm
	// So Pout = 17 - (15 - power) = 2 + power
	spi_write_single(RFM_REG_09_PA_CONFIG, RFM_PA_SELECT | RFM_MAX_POWER | (power-2));

  // Set ramp time
  spi_write_single(RFM_REG_0A_PA_RAMP, (spi_read_single(RFM_REG_0A_PA_RAMP) & ~RFM_PA_RAMP_MASK) | ramp_time);
}

void rfm_get_stats(void)
{
  // spi_transfer(RFM_CMD_GET_STATS, NULL, 0, stats, 6);
}

void rfm_reset_stats(void)
{
  // spi_transfer(RFM_CMD_RESET_STATS, NULL, 0, NULL, 0);
}

uint8_t rfm_get_version(void)
{
  return spi_read_single(RFM_REG_42_VERSION);
}


void rfm_start_listening(void)
{
  // Go to standby mode
  set_standby_mode();       

  // Set buffer offset to 0
  clear_buffer();

  // Set RX Done IRQ on IO0
  set_dio_irq(RFM_IO_0_IRQ_RX_DONE | RFM_IO_1_IRQ_RX_TIMEOUT | RFM_IO_2_IRQ_FHSS_CHANGE | RFM_IO_3_IRQ_CRC_ERROR, RFM_IO_4_IRQ_CAD_DETECTED | RFM_IO_5_IRQ_MODE_READY);
  
  // Unmask interrupt for RX Done
  mask_irq(RFM_IRQ_ALL);
  unmask_irq(RFM_RX_TIMEOUT_MASK | RFM_RX_DONE_MASK | RFM_VALID_HEADER_MASK | RFM_PAYLOAD_CRC_ERROR_MASK);
  clear_irq(RFM_IRQ_ALL);

  // Enable interrupt on MCU for RX done GPIO_RF_IO_0
  exti_reset_request(RFM_IO_0_EXTI);
  exti_select_source(RFM_IO_0_EXTI, RFM_IO_0_PORT);
	exti_set_trigger(RFM_IO_0_EXTI, EXTI_TRIGGER_RISING);
	exti_enable_request(RFM_IO_0_EXTI);
  	
	nvic_enable_irq(RFM_IO_0_NVIC);
  nvic_set_priority(RFM_IO_0_NVIC, 0);

  // Start listening
  set_rx_mode();
}

void rfm_organize_packet(rfm_packet_t *packet)
{
      // Organize Data
      packet->data.device_number  = packet->data.buffer[RFM_PACKET_DEV_NUM_3] << 24 | packet->data.buffer[RFM_PACKET_DEV_NUM_2] << 16 | packet->data.buffer[RFM_PACKET_DEV_NUM_1] << 8 | packet->data.buffer[RFM_PACKET_DEV_NUM_0];
      packet->data.msg_number     = packet->data.buffer[RFM_PACKET_MSG_NUM_3] << 24 | packet->data.buffer[RFM_PACKET_MSG_NUM_2] << 16 | packet->data.buffer[RFM_PACKET_MSG_NUM_1] << 8 | packet->data.buffer[RFM_PACKET_MSG_NUM_0];
      packet->data.power          = packet->data.buffer[RFM_PACKET_POWER];
      packet->data.battery        = packet->data.buffer[RFM_PACKET_BATTERY_1] << 8  | packet->data.buffer[RFM_PACKET_BATTERY_0];
      packet->data.temperature    = packet->data.buffer[RFM_PACKET_TEMP_1]    << 8  | packet->data.buffer[RFM_PACKET_TEMP_0];
}

void rfm_get_packets(void)
{
  if(packets_tail != packets_head)
  {
    // Enter standby mode while getting data
    set_standby_mode();

    // Set buffer offset to zero
    clear_buffer();

    while(packets_tail != packets_head)
    {
      spf_serial_printf("Get %u %u\n", packets_head, packets_tail);

      // Read data from RFM
      spi_read_burst(RFM_REG_00_FIFO, packets_buf[packets_tail].data.buffer, RFM_PACKET_LENGTH);

      // Increment pointer
      packets_tail = (packets_tail + 1) % PACKETS_BUF_SIZE;
    }

    // Set buffer offset to zero
    clear_buffer();

    // Go back to listening
    set_rx_mode();
  }
}

rfm_packet_t* rfm_get_next_packet(void)
{
  rfm_get_packets();

  spf_serial_printf("Read %u\n", packets_read);
  rfm_packet_t *packet = &packets_buf[packets_read];

  packets_read = (packets_read + 1) % PACKETS_BUF_SIZE;

  return packet;
}

uint8_t rfm_get_num_packets(void)
{
  return ((uint16_t)(PACKETS_BUF_SIZE + packets_head - packets_read)) % PACKETS_BUF_SIZE;
}

/** @brief Transmit packet
 * 
 * Clears buffers, enables interrupt, writes packet data and enters TX mode\n
 * RFM interrupt on IO0 is asserted on susccesful transmitssion\n
 * Enters sleep mode when complete.
 * 
 * @param   packet rfm packet to send @ref rfm_packet_t
 * @retval  bool true if transmitted succesfully, false if timeout
 */
bool rfm_transmit_packet(rfm_packet_t packet)
{
  /* Go to standby and clear buffer */
  set_standby_mode(); 
  clear_buffer();       
  
  /* Disable MCU interrupt used for receiving data */
  exti_disable_request(RFM_IO_0_EXTI);
	nvic_disable_irq(RFM_IO_0_NVIC);

  /* Enable TX Done IRQ on RFM (IO0) */ 
  set_dio_irq(RFM_IO_0_IRQ_TX_DONE | RFM_IO_1_IRQ_RX_TIMEOUT | RFM_IO_2_IRQ_FHSS_CHANGE | RFM_IO_3_IRQ_CRC_ERROR, RFM_IO_4_IRQ_CAD_DETECTED | RFM_IO_5_IRQ_MODE_READY);
  mask_irq(RFM_IRQ_ALL);
  unmask_irq(RFM_TX_DONE_MASK);
  clear_irq(RFM_IRQ_ALL);

  /* Write packet length */
  // if(packet.length == 0)
  //   	packet.length = 1;
  // spi_write_single(RFM_REG_22_PAYLOAD_LENGTH, packet.length);

  /* Write packet data */
  spi_write_burst(RFM_REG_00_FIFO, packet.data.buffer, RFM_PACKET_LENGTH);
  // spi_write_burst(RFM_REG_00_FIFO, packet.data, packet.length);
  // spf_serial_printf("SPI Pointer: %02x : %02x\n", RFM_REG_0D_FIFO_ADDR_PTR, spi_read_single(RFM_REG_0D_FIFO_ADDR_PTR));

  /* Wait for clear channel */
   
  // About 50ms to send packet currently
  // uint16_t start = timers_millis();

  /* Enter TX state */
  set_tx_mode();

  // wait_rf_io_0_high();
  // uint16_t end = timers_millis();
  // spf_serial_printf("Transmit Time: %u ms\n", (uint16_t)(end - start));
  // bool sent = true;

  bool sent = false;
  TIMEOUT(100000, "RFM TX", 0, gpio_get(RFM_IO_0_PORT, RFM_IO_0), sent = true;, ;);

  /* Clear interrupt */
  mask_irq(RFM_IRQ_ALL);
  clear_irq(RFM_IRQ_ALL);

  /* Clear buffer */
  clear_buffer(); 

  /* Go to sleep */
  set_sleep_mode(); 

  return sent;
}

void rfm_set_tx_continuous(void)
{
  spi_write_burst(RFM_REG_00_FIFO, random_data, 16);

  clear_buffer();
  
  uint8_t current = spi_read_single(RFM_REG_1E_MODEM_CONFIG2);
  spi_write_single(RFM_REG_1E_MODEM_CONFIG2, current | RFM_TX_CONTINUOUS_MODE);
  set_tx_mode();
}

void rfm_clear_tx_continuous(void)
{
  set_standby_mode();
  spi_write(RFM_REG_1E_MODEM_CONFIG2, spi_read_single(RFM_REG_1E_MODEM_CONFIG2) & ~RFM_TX_CONTINUOUS_MODE);
}

/** @} */

/** @addtogroup RFM_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Setup Clock
 * 
 * Initializes clock to be 2Mhz and sets baud divider to 8
 */
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
  // Set GPIO Mode
  gpio_mode_setup(RFM_SPI_MISO_PORT,  GPIO_MODE_AF,     GPIO_PUPD_NONE,   RFM_SPI_MISO);

  gpio_mode_setup(RFM_SPI_SCK_PORT,   GPIO_MODE_AF,     GPIO_PUPD_NONE,   RFM_SPI_SCK);
  gpio_mode_setup(RFM_SPI_MOSI_PORT,  GPIO_MODE_AF,     GPIO_PUPD_NONE,   RFM_SPI_MOSI);
  gpio_mode_setup(RFM_SPI_NSS_PORT,   GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, RFM_SPI_NSS);

  // Push Pull for outputs
  gpio_set_output_options(RFM_SPI_SCK_PORT,   GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, RFM_SPI_SCK);
  gpio_set_output_options(RFM_SPI_MOSI_PORT,  GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, RFM_SPI_MOSI);
  gpio_set_output_options(RFM_SPI_NSS_PORT,   GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, RFM_SPI_NSS);
  
  // Set NSS pin high
  gpio_set(RFM_SPI_NSS_PORT, RFM_SPI_NSS);

  // Set alternate function
  gpio_set_af(RFM_SPI_MISO_PORT,  RFM_SPI_AF, RFM_SPI_MISO);

  gpio_set_af(RFM_SPI_SCK_PORT,   RFM_SPI_AF, RFM_SPI_SCK);
  gpio_set_af(RFM_SPI_MOSI_PORT,  RFM_SPI_AF, RFM_SPI_MOSI);
  
  // Init SPI
  rcc_periph_clock_enable(RFM_SPI_RCC);
  rcc_periph_reset_pulse(RFM_SPI_RST); 
  spi_disable(RFM_SPI);
  spi_init_master(RFM_SPI, SPI_CR1_BAUDRATE_FPCLK_DIV_8,
                    SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1,
                    SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
  spi_enable(RFM_SPI);
}

/** @brief SPI Read Register
 * 
 * Reads a register from the rfm
 * 
 * @param reg Register to read
 * @retval Value read from register
 */
static uint8_t spi_read_single(uint8_t reg)
{
  spi_chip_select();
  timers_delay_microseconds(1);

  spi_xfer(RFM_SPI, reg);                   
  uint8_t in =  spi_xfer(RFM_SPI, 0x00);                   
    
  spi_chip_deselect(); 
  timers_delay_microseconds(1);

  return in;
}

static void spi_read_burst(uint8_t reg, uint8_t *buf, uint8_t len)
{
  spi_chip_select();
  timers_delay_microseconds(1);

  spi_xfer(RFM_SPI, reg);

  for(int i = 0; i < len; i++)
  {                 
    buf[i] =  spi_xfer(RFM_SPI, 0x00);  
  }                 

  spi_chip_deselect();     
  timers_delay_microseconds(1);
}

static void spi_write_single(uint8_t reg, uint8_t data)
{
  // Set MSB for write operation
  uint8_t cmd = 0x80 | reg;

  spi_chip_select();
  timers_delay_microseconds(1);

  spi_xfer(RFM_SPI, cmd);                 
  spi_xfer(RFM_SPI, data);             

  spi_chip_deselect(); 
  timers_delay_microseconds(1);

  uint8_t curr_data = spi_read_single(reg);

  // spf_serial_printf("%02x : %02x\n", reg, data);

  if(reg == RFM_REG_12_IRQ_FLAGS)    
    return;

  TIMEOUT(10000, "RFM SPI Write", ((reg << 16) | data), (curr_data == data), ;, timers_delay_microseconds(100); curr_data = spi_read_single(reg););

  // spf_serial_printf("%02x : %02x : %02x\n", reg, data, curr_data);
}

static void spi_write_burst(uint8_t reg, uint8_t *buf, uint8_t len)
{
  spi_chip_select();
  timers_delay_microseconds(1);

  // Set MSB for write operation
  uint8_t cmd = 0x80 | reg;

  spi_xfer(RFM_SPI, cmd);  

  for(int i = 0; i < len; i++)
  {                 
    spi_xfer(RFM_SPI, buf[i]); 
  }                  

  spi_chip_deselect();     
  timers_delay_microseconds(1);
}

static void set_frequency(uint32_t frequency_hz)
{
    // Frf = FRF / FSTEP
    uint32_t frf = frequency_hz / RFM_FSTEP;
    spi_write_single(RFM_REG_06_FRF_MSB, (frf >> 16) & 0xff);
    spi_write_single(RFM_REG_07_FRF_MID, (frf >> 8) & 0xff);
    spi_write_single(RFM_REG_08_FRF_LSB, frf & 0xff);

    // _usingHFport = (centre >= 779.0);
}

static void set_dio_irq(uint8_t io0_3, uint8_t io4_5)
{
  spi_write_single(RFM_REG_40_DIO_MAPPING1, io0_3);
  spi_write_single(RFM_REG_41_DIO_MAPPING2, io4_5);
}

static void set_preamble_length(uint16_t num_sym)
{
    spi_write_single(RFM_REG_20_PREAMBLE_MSB, num_sym >> 8);
    spi_write_single(RFM_REG_21_PREAMBLE_LSB, num_sym & 0xff);
}

static void print_registers(void)
{
  uint8_t registers[] = { 0x01, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x014, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x4b, 0x4d};

  uint8_t i;
  for (i = 0; i < sizeof(registers); i++)
  {
	  spf_serial_printf("%02x : %02x\n", registers[i], spi_read_single(registers[i]));
  }
}

static void clear_buffer(void)
{
    spi_write_single(RFM_REG_0D_FIFO_ADDR_PTR, 0);
    spi_write_single(RFM_REG_0E_FIFO_TX_BASE_ADDR, 0);
    spi_write_single(RFM_REG_0F_FIFO_RX_BASE_ADDR, 0);
}

// static uint16_t calculate_crc(rfm_packet_t *packet)
// {
// }

// From section 4.1.5 of SX1276/77/78/79
// Ferror = FreqError * 2**24 * BW / Fxtal / 500
// int RH_RF95::frequencyError()
// {
//     int32_t freqerror = 0;
// 
//     // Convert 2.5 bytes (5 nibbles, 20 bits) to 32 bit signed int
//     // Caution: some C compilers make errors with eg:
//     // freqerror = spiRead(RH_RF95_REG_28_FEI_MSB) << 16
//     // so we go more carefully.
//     freqerror = spiRead(RH_RF95_REG_28_FEI_MSB);
//     freqerror <<= 8;
//     freqerror |= spiRead(RH_RF95_REG_29_FEI_MID);
//     freqerror <<= 8;
//     freqerror |= spiRead(RH_RF95_REG_2A_FEI_LSB);
//     // Sign extension into top 3 nibbles
//     if (freqerror & 0x80000)
// 	freqerror |= 0xfff00000;
// 
//     int error = 0; // In hertz
//     float bw_tab[] = {7.8, 10.4, 15.6, 20.8, 31.25, 41.7, 62.5, 125, 250, 500};
//     uint8_t bwindex = spiRead(RH_RF95_REG_1D_MODEM_CONFIG1) >> 4;
//     if (bwindex < (sizeof(bw_tab) / sizeof(float)))
// 	error = (float)freqerror * bw_tab[bwindex] * ((float)(1L << 24) / (float)RH_RF95_FXOSC / 500.0);
//     // else not defined
// 
//     return error;
// }


static inline void mask_irq(uint8_t irq)
{
  spi_write_single(RFM_REG_11_IRQ_FLAGS_MASK, spi_read_single(RFM_REG_11_IRQ_FLAGS_MASK) | irq); 
}

static inline void unmask_irq(uint8_t irq)
{
  spi_write_single(RFM_REG_11_IRQ_FLAGS_MASK, spi_read_single(RFM_REG_11_IRQ_FLAGS_MASK) & ~irq); 
}

static inline uint8_t get_irq(void)
{
  return spi_read_single(RFM_REG_12_IRQ_FLAGS);
}

static inline void clear_irq(uint8_t irq)
{
  // uint8_t reg = 0;
  // reg &= ~irq;
  // reg |= irq;
  // spf_serial_printf("Clear %02x : %02x\n", irq, reg);
  spi_write_single(RFM_REG_12_IRQ_FLAGS, irq);
}

static inline void set_tx_mode(void)
{ 
  spi_write_single(RFM_REG_01_OP_MODE, (spi_read_single(RFM_REG_01_OP_MODE) & ~RFM_MODE) | RFM_MODE_TX);
}

static inline void set_rx_mode(void)
{
  spi_write_single(RFM_REG_01_OP_MODE, (spi_read_single(RFM_REG_01_OP_MODE) & ~RFM_MODE) | RFM_MODE_RXCONTINUOUS);
}

static inline void set_standby_mode(void)
{
  spi_write_single(RFM_REG_01_OP_MODE, (spi_read_single(RFM_REG_01_OP_MODE) & ~RFM_MODE) | RFM_MODE_STDBY);
}

static inline void set_sleep_mode(void)
{
  spi_write_single(RFM_REG_01_OP_MODE, (spi_read_single(RFM_REG_01_OP_MODE) & ~RFM_MODE) |  RFM_MODE_SLEEP);
}

/** @} */

/** @addtogroup  RFM_API
 *  @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Interrupts
/*////////////////////////////////////////////////////////////////////////////*/

void exti4_15_isr(void)
{
  uint16_t timer = timers_micros();
  
  exti_reset_request(RFM_IO_0_EXTI);
  exti_reset_request(RFM_IO_0_EXTI);

  // Store IRQ Flags
  packets_buf[packets_head].flags = get_irq();
  clear_irq(RFM_IRQ_ALL);
  clear_irq(RFM_IRQ_ALL);

  // Get signal strength
  packets_buf[packets_head].rssi = spi_read_single(RFM_REG_1A_PKT_RSSI_VALUE);
  packets_buf[packets_head].rssi -= 137;
  packets_buf[packets_head].snr = spi_read_single(RFM_REG_19_PKT_SNR_VALUE) / 4;

  // Check for CRC error
  packets_buf[packets_head].crc_ok = !(packets_buf[packets_head].flags & RFM_IRQ_PAYLOAD_CRC_ERROR);

  packets_head = (packets_head + 1) % PACKETS_BUF_SIZE;

  uint16_t time = timers_micros() - timer;
  // spf_serial_printf("ISR %u %u %u\n", time, packets_head, packets_tail);
}

/** @} */
/** @} */