#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/adc.h>

#include "coolease/cc1101.h"
#include "coolease/serial_printf.h"

/*
 * Type of transfers
 */
#define WRITE_BURST              0x40
#define READ_SINGLE              0x80
#define READ_BURST               0xC0

/*
 * Type of register for single read
 * Status registers can only be read individually
 */
#define CONFIG_REGISTER   READ_SINGLE
#define STATUS_REGISTER   READ_BURST

/*
 * Command strobes
 */
#define SRES              0x30        // Reset CC1101 chip
#define SFSTXON           0x31        // Enable and calibrate frequency synthesizer (if MCSM0.FS_AUTOCAL=1). If in RX (with CCA):
                                      // Go to a wait state where only the synthesizer is running (for quick RX / TX turnaround).
#define SXOFF             0x32        // Turn off crystal oscillator
#define SCAL              0x33        // Calibrate frequency synthesizer and turn it off. SCAL can be strobed from IDLE mode without
                                      // setting manual calibration mode (MCSM0.FS_AUTOCAL=0)
#define SRX               0x34        // Enable RX. Perform calibration first if coming from IDLE and MCSM0.FS_AUTOCAL=1
#define STX               0x35        // In IDLE state: Enable TX. Perform calibration first if MCSM0.FS_AUTOCAL=1.
                                      // If in RX state and CCA is enabled: Only go to TX if channel is clear
#define SIDLE             0x36        // Exit RX / TX, turn off frequency synthesizer and exit Wake-On-Radio mode if applicable
#define SWOR              0x38        // Start automatic RX polling sequence (Wake-on-Radio) as described in Section 19.5 if
                                      // WORCTRL.RC_PD=0
#define SPWD              0x39        // Enter power down mode when CSn goes high
#define SFRX              0x3A        // Flush the RX FIFO buffer. Only issue SFRX in IDLE or RXFIFO_OVERFLOW states
#define SFTX              0x3B        // Flush the TX FIFO buffer. Only issue SFTX in IDLE or TXFIFO_UNDERFLOW states
#define SWORRST           0x3C        // Reset real time clock to Event1 value
#define SNOP              0x3D        // No operation. May be used to get access to the chip status byte

/*
 * CC1101 configuration registers
 */
#define IOCFG2            0x00        // GDO2 Output Pin Configuration
#define IOCFG1            0x01        // GDO1 Output Pin Configuration
#define IOCFG0            0x02        // GDO0 Output Pin Configuration
#define FIFOTHR           0x03        // RX FIFO and TX FIFO Thresholds
#define SYNC1             0x04        // Sync Word, High Byte
#define SYNC0             0x05        // Sync Word, Low Byte
#define PKTLEN            0x06        // Packet Length
#define PKTCTRL1          0x07        // Packet Automation Control
#define PKTCTRL0          0x08        // Packet Automation Control
#define ADDR              0x09        // Device Address
#define CHANNR            0x0A        // Channel Number
#define FSCTRL1           0x0B        // Frequency Synthesizer Control
#define FSCTRL0           0x0C        // Frequency Synthesizer Control
#define FREQ2             0x0D        // Frequency Control Word, High Byte
#define FREQ1             0x0E        // Frequency Control Word, Middle Byte
#define FREQ0             0x0F        // Frequency Control Word, Low Byte
#define MDMCFG4           0x10        // Modem Configuration
#define MDMCFG3           0x11        // Modem Configuration
#define MDMCFG2           0x12        // Modem Configuration
#define MDMCFG1           0x13        // Modem Configuration
#define MDMCFG0           0x14        // Modem Configuration
#define DEVIATN           0x15        // Modem Deviation Setting
#define MCSM2             0x16        // Main Radio Control State Machine Configuration
#define MCSM1             0x17        // Main Radio Control State Machine Configuration
#define MCSM0             0x18        // Main Radio Control State Machine Configuration
#define FOCCFG            0x19        // Frequency Offset Compensation Configuration
#define BSCFG             0x1A        // Bit Synchronization Configuration
#define AGCCTRL2          0x1B        // AGC Control
#define AGCCTRL1          0x1C        // AGC Control
#define AGCCTRL0          0x1D        // AGC Control
#define WOREVT1           0x1E        // High Byte Event0 Timeout
#define WOREVT0           0x1F        // Low Byte Event0 Timeout
#define WORCTRL           0x20        // Wake On Radio Control
#define FREND1            0x21        // Front End RX Configuration
#define FREND0            0x22        // Front End TX Configuration
#define FSCAL3            0x23        // Frequency Synthesizer Calibration
#define FSCAL2            0x24        // Frequency Synthesizer Calibration
#define FSCAL1            0x25        // Frequency Synthesizer Calibration
#define FSCAL0            0x26        // Frequency Synthesizer Calibration
#define RCCTRL1           0x27        // RC Oscillator Configuration
#define RCCTRL0           0x28        // RC Oscillator Configuration
#define FSTEST            0x29        // Frequency Synthesizer Calibration Control
#define PTEST             0x2A        // Production Test
#define AGCTEST           0x2B        // AGC Test
#define TEST2             0x2C        // Various Test Settings
#define TEST1             0x2D        // Various Test Settings
#define TEST0             0x2E        // Various Test Settings

/*
 * CC1101 Status registers
 */
#define PARTNUM           0x30        // Chip ID
#define VERSION           0x31        // Chip ID
#define FREQEST           0x32        // Frequency Offset Estimate from Demodulator
#define LQI               0x33        // Demodulator Estimate for Link Quality
#define RSSI              0x34        // Received Signal Strength Indication
#define MARCSTATE         0x35        // Main Radio Control State Machine State
#define WORTIME1          0x36        // High Byte of WOR Time
#define WORTIME0          0x37        // Low Byte of WOR Time
#define PKTSTATUS         0x38        // Current GDOx Status and Packet Status
#define VCO_VC_DAC        0x39        // Current Setting from PLL Calibration Module
#define TXBYTES           0x3A        // Underflow and Number of Bytes
#define RXBYTES           0x3B        // Overflow and Number of Bytes
#define RCCTRL1_STATUS    0x3C        // Last RC Oscillator Calibration Result
#define RCCTRL0_STATUS    0x3D        // Last RC Oscillator Calibration Result 

/*
 * PATABLE & FIFO's
 */
#define PATABLE           0x3E        // PATABLE address
#define TXFIFO            0x3F        // TX FIFO address
#define RXFIFO            0x3F        // RX FIFO address

/*
 *  PATABLE values
 */
// uint8_t PA_TABLE_VAL[8] = {0x03, 0x1d, 0x37, 0x50, 0x86, 0xcd, 0xc5, 0xc0};
uint8_t PA_TABLE_VAL[8] = {0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

/*
 * Useful one line function definitions 
 */

// Enter state
#define set_idle_state()          send_cmd_strobe(SIDLE)
#define set_tx_state()            send_cmd_strobe(STX)
#define set_rx_state()            send_cmd_strobe(SRX)

// Flush FIFOs
#define flush_rx_fifo()           send_cmd_strobe(SFRX)
#define flush_tx_fifo()           send_cmd_strobe(SFTX)

// SPI Comms Functions
#define wait_miso_low()           while(gpio_get(GPIOA, GPIO_SPI1_MISO))
#define spi_chip_select()         gpio_clear(GPIOA, GPIO_SPI1_NSS)
#define spi_chip_deselect()       gpio_set(GPIOA, GPIO_SPI1_NSS)
#define wait_gdo_0_high()         while(!(gpio_get(GPIOA, GPIO2)))
#define wait_gdo_0_low()          while(gpio_get(GPIOA, GPIO2))

/*
 * Static function decls
 */
static void clock_setup(void);
static void spi_setup(void);

static uint8_t send_cmd_strobe(uint8_t cmd);
static void write_reg_single(uint8_t regAddr, uint8_t value);
static uint8_t read_reg_single(uint8_t regAddr, uint8_t regType);
static void write_reg_burst(uint8_t regAddr, uint8_t *buffer, uint8_t len);
static void read_reg_burst(uint8_t *buffer, uint8_t regAddr, uint8_t len);

static void write_config_regs(void);
static void print_config_regs(void);

static void set_power_down_state(void);

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

  // Config GDO0/ GDO1 (radio events/ interrupts) as inputs
  gpio_set_mode(GPIOA,                 
                GPIO_MODE_INPUT, 
                GPIO_CNF_INPUT_FLOAT, GPIO2|GPIO3);          
  
  // Reset CC1101
  cc1101_reset();                     

  // Put cc1101 in idle state
  set_idle_state();

  // Print config registers
  //print_config_regs();

  set_rx_state();
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
  cc1101_set_tx_pa_table_index(0);                         
}

/**
 * cc1101_end
 * 
 * Shut down CC1101
 * Disable spi perpheral and clock
 */
void cc1101_end(void)
{
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
 
  // Go to idle state first
  set_idle_state();

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

  // Enter back into RX state
  set_rx_state();

  // Return ok or error
  return res;
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
      packet->rssi = read_reg_single(RXFIFO, CONFIG_REGISTER);

      // Read LQI and CRC_OK
      uint8_t val = read_reg_single(RXFIFO, CONFIG_REGISTER);
      packet->lqi = val & 0x7F;
      packet->crc_ok = val & 0x80;
    }
  }
  // No packet waiting in RX FIFO 
  else
    packet->length = 0;

  // Enter IDLE statea and flush RX FIFO
  set_idle_state();       
  flush_rx_fifo(); 

  // Back to RX state
  set_rx_state();

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

float cc1101_temperature(void)
{
  cc1101_init();

  set_idle_state();
  write_reg_single(PTEST, 0XBF);
  write_reg_single(IOCFG0, 0X80);

  rcc_periph_clock_enable(RCC_ADC1);
  adc_power_off(ADC1);
  rcc_periph_reset_pulse(RST_ADC1);
  adc_disable_scan_mode(ADC1);
  adc_set_single_conversion_mode(ADC1);
  adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_41DOT5CYC);
  adc_enable_external_trigger_regular(ADC1, ADC_CR2_EXTSEL_SWSTART);
  adc_power_on(ADC1);
  adc_reset_calibration(ADC1);
  adc_calibrate(ADC1);

  rcc_periph_clock_enable(RCC_GPIOA);
  gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_ANALOG, GPIO2);

  for(int i = 0; i < 8000; i++) __asm__("nop");

  uint8_t channels[1] = {2};
  uint16_t tmp = 0;

  adc_set_regular_sequence(ADC1, 1, channels);

  for(int i = 0; i < 10; i++)
  {
    adc_start_conversion_regular(ADC1);
    while (!adc_eoc(ADC1));

    tmp += adc_read_regular(ADC1);
  }
    tmp /= 10;

  spf_serial_printf("Reading: %04x\n", tmp);

  float v_sense = (float)tmp * 3.3f / 4096;
  spf_serial_printf("Voltage: %f\n", v_sense);
        
  v_sense = (( v_sense - 0.747f ) / .00247f );
  //readings[i] = v_sense;
  spf_serial_printf("Temperature: %f\n\n", v_sense);

  write_reg_single(PTEST, 0X7F);
  cc1101_end();

  return v_sense;
}

/*
 * Static function definitions
 */

/*
 * Enable external oscillator
 * Set sysclock -> 52MHz
 * Output clock for radio on MCO pin -> 26Mhz
 */
static void clock_setup(void)
{
	// Enable HSI Osc 8Mhz
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	// Select HSI as SYSCLK Source
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	// Enable HSE Osc and wait to sabalize
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);

	// Set prescalers for AHB, ADC, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);		// AHB -> 52MHz
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV4);	// ADC -> 13MHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);		// APB1 -> 26Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);		// APB2 -> 52MHz

	// Set flash, 52MHz -> 2 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	// Set PLL multiplication factor to 13 -> 8 * 13 = 104MHz
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL13);
	// Set HSE as PLL Source
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);
	// Set PLL Prescale to 2 -> 104 / 2 = 52MHz
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2);
	// Enable PLL Osc and wait to stabalize
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);
	// spi_chip_select PLL as SYSCLK
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 52000000;
	rcc_apb1_frequency = 26000000;
	rcc_apb2_frequency = 52000000;

	// Enable MCO (PA8) divide by 2 -> 52 / 2 = 26Mhz for radio
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO8);
	rcc_set_mco(RCC_CFGR_MCO_PLL_DIV2);
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
  spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64,
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
static uint8_t send_cmd_strobe(uint8_t cmd) 
{
  spi_chip_select();               // spi_chip_select CC1101
  wait_miso_low();          // Wait until MISO goes low

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
static void write_reg_single(uint8_t regAddr, uint8_t value) 
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
static uint8_t read_reg_single(uint8_t regAddr, uint8_t regType)
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
static void write_reg_burst(uint8_t regAddr, uint8_t *buffer, uint8_t len)
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
static void read_reg_burst(uint8_t *buffer, uint8_t regAddr, uint8_t len) 
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
static void write_config_regs(void) 
{
// Sync word qualifier mode = 30/32 sync word bits detected 
// CRC autoflush = false 
// Channel spacing = 199.951172 
// Data format = Normal mode 
// Data rate = 1.19948 
// RX filter BW = 812.500000 
// PA ramping = false 
// Preamble count = 4 
// Whitening = false 
// Address config = No address check 
// Carrier frequency = 867.999939 
// Device address = 0 
// TX power = 0 
// Manchester enable = false 
// CRC enable = true 
// Deviation = 5.157471 
// Packet length mode = Variable packet length mode. Packet length configured by the first byte after sync word 
// Packet length = 255 
// Modulation format = ASK/OOK 
// Base frequency = 867.999939 
// Channel number = 0 
//
// Rf settings for CC1101
write_reg_single(IOCFG2,0x2F);  //GDO2 Output Pin Configuration
write_reg_single(IOCFG1,0x2E);  //GDO1 Output Pin Configuration
write_reg_single(IOCFG0,0x06);  //GDO0 Output Pin Configuration
write_reg_single(FIFOTHR,0x07); //RX FIFO and TX FIFO Thresholds
write_reg_single(SYNC1,0xD3);   //Sync Word, High Byte
write_reg_single(SYNC0,0x91);   //Sync Word, Low Byte
write_reg_single(PKTLEN,0xFF);  //Packet Length
write_reg_single(PKTCTRL1,0x04);//Packet Automation Control
write_reg_single(PKTCTRL0,0x05);//Packet Automation Control
write_reg_single(ADDR,0x00);    //Device Address
write_reg_single(CHANNR,0x00);  //Channel Number
write_reg_single(FSCTRL1,0x06); //Frequency Synthesizer Control
write_reg_single(FSCTRL0,0x00); //Frequency Synthesizer Control
write_reg_single(FREQ2,0x21);   //Frequency Control Word, High Byte
write_reg_single(FREQ1,0x62);   //Frequency Control Word, Middle Byte
write_reg_single(FREQ0,0x76);   //Frequency Control Word, Low Byte
write_reg_single(MDMCFG4,0x05); //Modem Configuration
write_reg_single(MDMCFG3,0x83); //Modem Configuration
write_reg_single(MDMCFG2,0x33); //Modem Configuration
write_reg_single(MDMCFG1,0x22); //Modem Configuration
write_reg_single(MDMCFG0,0xF8); //Modem Configuration
write_reg_single(DEVIATN,0x15); //Modem Deviation Setting
write_reg_single(MCSM2,0x07);   //Main Radio Control State Machine Configuration
write_reg_single(MCSM1,0x30);   //Main Radio Control State Machine Configuration
write_reg_single(MCSM0,0x18);   //Main Radio Control State Machine Configuration
write_reg_single(FOCCFG,0x14);  //Frequency Offset Compensation Configuration
write_reg_single(BSCFG,0x6C);   //Bit Synchronization Configuration
write_reg_single(AGCCTRL2,0x03);//AGC Control 0x03 to 0x07
write_reg_single(AGCCTRL1,0x00);//AGC Control
write_reg_single(AGCCTRL0,0x92);//AGC Control 0x91 or 0x92
write_reg_single(WOREVT1,0x87); //High Byte Event0 Timeout
write_reg_single(WOREVT0,0x6B); //Low Byte Event0 Timeout
write_reg_single(WORCTRL,0xFB); //Wake On Radio Control
write_reg_single(FREND1,0x56);  //Front End RX Configuration
write_reg_single(FREND0,0x11);  //Front End TX Configuration
write_reg_single(FSCAL3,0xE9);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL2,0x2A);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL1,0x00);  //Frequency Synthesizer Calibration
write_reg_single(FSCAL0,0x1F);  //Frequency Synthesizer Calibration
write_reg_single(RCCTRL1,0x41); //RC Oscillator Configuration
write_reg_single(RCCTRL0,0x00); //RC Oscillator Configuration
write_reg_single(FSTEST,0x59);  //Frequency Synthesizer Calibration Control
write_reg_single(PTEST,0x7F);   //Production Test
write_reg_single(AGCTEST,0x3F); //AGC Test
write_reg_single(TEST2,0x88);   //Various Test Settings
write_reg_single(TEST1,0x31);   //Various Test Settings
write_reg_single(TEST0,0x09);   //Various Test Settings
}

/*
 * printCCregs
 * 
 * Print CC1101 registers on serial port
 * serial_print() must be implemented
 */
static void print_config_regs(void) 
{
  for(int i = 0x00; i <= 0x2E; i++)
    spf_serial_printf("Register %02x: %02x\n", i, read_reg_single(i, CONFIG_REGISTER));
}


/*
 * set_power_down_state
 * 
 * Put CC1101 into power-down state
 */
static void set_power_down_state(void) 
{
  // Comming from RX state, we need to enter the IDLE state first
  send_cmd_strobe(SIDLE);

  // Enter Power-down state
  send_cmd_strobe(SPWD);
}
