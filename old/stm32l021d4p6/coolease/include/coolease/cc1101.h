#include <stdint.h>
#include <stdbool.h>

#ifndef CC1101_H
#define CC1101_H

/*
 * Type of transfers
 */
#define WRITE_BURST         0x40
#define READ_SINGLE         0x80
#define READ_BURST          0xC0

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

// RF Switch Defs
#define RF_SWITCH_CLOSED    0x2F
#define RF_SWITCH_OPEN      0x6F

/*
 * Useful one line function definitions 
 */

// Enter state
#define set_idle_state()          send_cmd_strobe(SIDLE)
#define set_tx_state()            send_cmd_strobe(STX)
#define set_rx_state()            send_cmd_strobe(SRX)
#define set_pwd_state()           send_cmd_strobe(SPWD)

// Flush FIFOs
#define flush_rx_fifo()           send_cmd_strobe(SFRX)
#define flush_tx_fifo()           send_cmd_strobe(SFTX)

// SPI Comms Functions
#define wait_miso_low()           while(gpio_get(GPIOA, GPIO_SPI1_MISO))
#define spi_chip_select()         gpio_clear(GPIOA, GPIO_SPI1_NSS)
#define spi_chip_deselect()       gpio_set(GPIOA, GPIO_SPI1_NSS)
#define wait_gdo_0_high()         while(!(gpio_get(GPIOA, GPIO_RF_GDO_0)))
#define wait_gdo_0_low()          while(gpio_get(GPIOA, GPIO_RF_GDO_0))

#define rf_switch_open()          write_reg_single(IOCFG2, RF_SWITCH_OPEN)
#define rf_switch_close()         write_reg_single(IOCFG2, RF_SWITCH_CLOSED)

/*
 * Buffer and data lengths
 */
#define CC1101_PACKET_BUFFER_LEN        64
#define CC1101_PACKET_DATA_LEN          CC1101_PACKET_BUFFER_LEN - 3

/*
 * CC1101 data packet structure
 */
typedef struct
{
    /**
     * Data length
     */
    uint8_t length;

    /**
     * Data buffer
     */
    uint8_t data[CC1101_PACKET_DATA_LEN];

    /**
     * CRC OK flag
     */
    bool crc_ok;

    /**
     * Received Strength Signal Indication
     */
    int8_t rssi;

    /**
     * Link Quality Index
     */
    uint8_t lqi;

}cc1101_packet_t;

/**
 * Global Function Decls
 */

/*
 * init
 * 
 * Initialize CC1101 radio
 *
 * @param freq Carrier frequency
 * @param mode Working mode (speed, ...)
 */
void cc1101_init(void);

/*
 * reset
 * 
 * Reset CC1101
 */
void cc1101_reset(void);

/**
 * cc1101_end
 * 
 * Shut down CC1101
 * Disable spi perpheral and clock
 */
void cc1101_end(void);

/*
 * sendData
 * 
 * Send data packet via RF
 * 
 * 'packet'	Packet to be transmitted. First byte is the destination address
 *
 *  Return:
 *    True if the transmission succeeds
 *    False otherwise
 */
bool cc1101_transmit_packet(cc1101_packet_t packet);

/*
 * cc1101_start_listening
 * 
 * Enter rx state
 * Close RF Switch if Hub
 */
void cc1101_start_listening(void);

/*
 * receiveData
 * 
 * Read data packet from RX FIFO
 *
 * 'packet'	Container for the packet received
 * 
 * Return:
 * 	Amount of bytes received
 */
uint8_t cc1101_get_packet(cc1101_packet_t *packet);

/*
 * setTxPowerAmp
 * 
 * Set PATABLE values
 * 
 * @param paLevel amplification value
 */
void cc1101_set_tx_pa_table_index(uint8_t paTableIndex);

/*
 * Change currently used channel
 * Value from 1 to 10
 */
void cc1101_change_channel(uint8_t chnl);

/*
 * Enable external oscillator
 * Set sysclock -> 52MHz
 * Output clock for radio on MCO pin -> 26Mhz
 */
void clock_setup(void);

/*
 * Enable gpio & spi clocks
 * Reset and reconfigure gpio & spi peripheral
 */
void spi_setup(void);

/*
 * send_cmd_strobe
 * 
 * Send command strobe to the CC1101 IC via SPI
 * 
 * 'cmd'	Command strobe
 */     
uint8_t send_cmd_strobe(uint8_t cmd);

/*
 * write_reg_single
 * 
 * Write single register into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'value'	Value to be writen
 */
void write_reg_single(uint8_t regAddr, uint8_t value);

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
uint8_t read_reg_single(uint8_t regAddr, uint8_t regType);

/*
 * write_reg_burst
 * 
 * Write multiple registers into the CC1101 IC via SPI
 * 
 * 'regAddr'	Register address
 * 'buffer'	Data to be writen
 * 'len'	Data length
 */
void write_reg_burst(uint8_t regAddr, uint8_t *buffer, uint8_t len);

/*
 * read_reg_burst
 * 
 * Read burst data from CC1101 via SPI
 * 
 * 'buffer'	Buffer where to copy the result to
 * 'regAddr'	Register address
 * 'len'	Data length
 */
void read_reg_burst(uint8_t *buffer, uint8_t regAddr, uint8_t len);

/*
 * setCCregs
 * 
 * Configure CC1101 registers
 */
void write_config_regs(void);

/*
 * printCCregs
 * 
 * Print CC1101 registers on serial port
 * serial_print() must be implemented
 */
void print_config_regs(void);

/*
 * set_power_down_state
 * 
 * Put CC1101 into power-down state
 */
void set_power_down_state(void);


#endif