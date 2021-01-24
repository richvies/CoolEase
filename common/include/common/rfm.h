/**
 ******************************************************************************
 * @file       rfm.h
 * @author     Richard Davies
 * @date       25/Dec/2020
 * @brief      Rfm Header File
 *  
 * @defgroup   RFM_FILE  Rfm
 * @brief      
 * 
 * Manages the Radio Module
 * - Initializes rfm for LORA
 * - Initialization of SPI peripheral
 * 
 * @note     
 * 
  * @{
  * @defgroup   RFM_API  RFM API
  * @brief      Programming interface and key macros
  * 
  * @defgroup   RFM_INT  RFM Internal
  * @brief      Static Vars, Functions & Internal Macros
  * 
  * @defgroup   RFM_REG  RFM Registers
  * @brief      Register Descriptions
  * @}
 ******************************************************************************
 */

#ifndef RFM_H
#define RFM_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup RFM_REG
 * 
 * Definitiion of registers in RFM95
 * @{
 */
// #region RFM Registers
#define RFM_REG_00_FIFO                                0x00 ///< @brief Shared TX/RX FIFO Address
#define RFM_REG_01_OP_MODE                             0x01 ///< Operating Mode @ref RFM_IRQ
#define RFM_REG_02_RESERVED                            0x02
#define RFM_REG_03_RESERVED                            0x03
#define RFM_REG_04_RESERVED                            0x04
#define RFM_REG_05_RESERVED                            0x05
#define RFM_REG_06_FRF_MSB                             0x06
#define RFM_REG_07_FRF_MID                             0x07
#define RFM_REG_08_FRF_LSB                             0x08
#define RFM_REG_09_PA_CONFIG                           0x09
#define RFM_REG_0A_PA_RAMP                             0x0a
#define RFM_REG_0B_OCP                                 0x0b
#define RFM_REG_0C_LNA                                 0x0c
#define RFM_REG_0D_FIFO_ADDR_PTR                       0x0d
#define RFM_REG_0E_FIFO_TX_BASE_ADDR                   0x0e
#define RFM_REG_0F_FIFO_RX_BASE_ADDR                   0x0f
#define RFM_REG_10_FIFO_RX_CURRENT_ADDR                0x10
#define RFM_REG_11_IRQ_FLAGS_MASK                      0x11
#define RFM_REG_12_IRQ_FLAGS                           0x12
#define RFM_REG_13_RX_NB_BYTES                         0x13
#define RFM_REG_14_RX_HEADER_CNT_VALUE_MSB             0x14
#define RFM_REG_15_RX_HEADER_CNT_VALUE_LSB             0x15
#define RFM_REG_16_RX_PACKET_CNT_VALUE_MSB             0x16
#define RFM_REG_17_RX_PACKET_CNT_VALUE_LSB             0x17
#define RFM_REG_18_MODEM_STAT                          0x18
#define RFM_REG_19_PKT_SNR_VALUE                       0x19
#define RFM_REG_1A_PKT_RSSI_VALUE                      0x1a
#define RFM_REG_1B_RSSI_VALUE                          0x1b
#define RFM_REG_1C_HOP_CHANNEL                         0x1c
#define RFM_REG_1D_MODEM_CONFIG1                       0x1d
#define RFM_REG_1E_MODEM_CONFIG2                       0x1e
#define RFM_REG_1F_SYMB_TIMEOUT_LSB                    0x1f
#define RFM_REG_20_PREAMBLE_MSB                        0x20
#define RFM_REG_21_PREAMBLE_LSB                        0x21
#define RFM_REG_22_PAYLOAD_LENGTH                      0x22
#define RFM_REG_23_MAX_PAYLOAD_LENGTH                  0x23
#define RFM_REG_24_HOP_PERIOD                          0x24
#define RFM_REG_25_FIFO_RX_BYTE_ADDR                   0x25
#define RFM_REG_26_MODEM_CONFIG3                       0x26

#define RFM_REG_27_PPM_CORRECTION                      0x27
#define RFM_REG_28_FEI_MSB                             0x28
#define RFM_REG_29_FEI_MID                             0x29
#define RFM_REG_2A_FEI_LSB                             0x2a
#define RFM_REG_2C_RSSI_WIDEBAND                       0x2c
#define RFM_REG_31_DETECT_OPTIMIZE                     0x31
#define RFM_REG_33_INVERT_IQ                           0x33
#define RFM_REG_37_DETECTION_THRESHOLD                 0x37
#define RFM_REG_39_SYNC_WORD                           0x39

#define RFM_REG_40_DIO_MAPPING1                        0x40
#define RFM_REG_41_DIO_MAPPING2                        0x41
#define RFM_REG_42_VERSION                             0x42

#define RFM_REG_4B_TCXO                                0x4b
#define RFM_REG_4D_PA_DAC                              0x4d
#define RFM_REG_5B_FORMER_TEMP                         0x5b
#define RFM_REG_61_AGC_REF                             0x61
#define RFM_REG_62_AGC_THRESH1                         0x62
#define RFM_REG_63_AGC_THRESH2                         0x63
#define RFM_REG_64_AGC_THRESH3                         0x64


#define RFM_LONG_RANGE_MODE                       0x80
#define RFM_ACCESS_SHARED_REG                     0x40
#define RFM_LOW_FREQUENCY_MODE                    0x08
#define RFM_MODE                                  0x07
#define RFM_MODE_SLEEP                            0x00
#define RFM_MODE_STDBY                            0x01
#define RFM_MODE_FSTX                             0x02
#define RFM_MODE_TX                               0x03
#define RFM_MODE_FSRX                             0x04
#define RFM_MODE_RXCONTINUOUS                     0x05
#define RFM_MODE_RXSINGLE                         0x06
#define RFM_MODE_CAD                              0x07

#define RFM_PA_SELECT                             0x80
#define RFM_MAX_POWER                             0x70
#define RFM_OUTPUT_POWER                          0x0f

// RFM_REG_0A_PA_RAMP                             0x0a
#define RFM_LOW_PN_TX_PLL_OFF                     0x10
#define RFM_PA_RAMP_MASK                          0x0f
#define RFM_PA_RAMP_3_4MS                         0x00
#define RFM_PA_RAMP_2MS                           0x01
#define RFM_PA_RAMP_1MS                           0x02
#define RFM_PA_RAMP_500US                         0x03
#define RFM_PA_RAMP_250US                         0x04
#define RFM_PA_RAMP_125US                         0x05
#define RFM_PA_RAMP_100US                         0x06
#define RFM_PA_RAMP_62US                          0x07
#define RFM_PA_RAMP_50US                          0x08
#define RFM_PA_RAMP_40US                          0x09
#define RFM_PA_RAMP_31US                          0x0a
#define RFM_PA_RAMP_25US                          0x0b
#define RFM_PA_RAMP_20US                          0x0c
#define RFM_PA_RAMP_15US                          0x0d
#define RFM_PA_RAMP_12US                          0x0e
#define RFM_PA_RAMP_10US                          0x0f

// RFM_REG_0B_OCP                                 0x0b
#define RFM_OCP_ON                                0x20
#define RFM_OCP_TRIM                              0x1f

// RFM_REG_0C_LNA                                 0x0c
#define RFM_LNA_GAIN                              0xe0
#define RFM_LNA_GAIN_G1                           0x20
#define RFM_LNA_GAIN_G2                           0x40
#define RFM_LNA_GAIN_G3                           0x60                
#define RFM_LNA_GAIN_G4                           0x80
#define RFM_LNA_GAIN_G5                           0xa0
#define RFM_LNA_GAIN_G6                           0xc0
#define RFM_LNA_BOOST_LF                          0x18
#define RFM_LNA_BOOST_LF_DEFAULT                  0x00
#define RFM_LNA_BOOST_HF                          0x03
#define RFM_LNA_BOOST_HF_DEFAULT                  0x00
#define RFM_LNA_BOOST_HF_150PC                    0x03

// RFM_REG_11_IRQ_FLAGS_MASK                      0x11
#define RFM_RX_TIMEOUT_MASK                       0x80
#define RFM_RX_DONE_MASK                          0x40
#define RFM_PAYLOAD_CRC_ERROR_MASK                0x20
#define RFM_VALID_HEADER_MASK                     0x10
#define RFM_TX_DONE_MASK                          0x08
#define RFM_CAD_DONE_MASK                         0x04
#define RFM_FHSS_CHANGE_CHANNEL_MASK              0x02
#define RFM_CAD_DETECTED_MASK                     0x01
#define RFM_IRQ_ALL                               0xFF
#define RFM_IRQ_NONE                              0x00

// RFM_REG_12_IRQ_FLAGS                           0x12
#define RFM_IRQ_RX_TIMEOUT                        0x80
#define RFM_IRQ_RX_DONE                           0x40
#define RFM_IRQ_PAYLOAD_CRC_ERROR                 0x20
#define RFM_IRQ_VALID_HEADER                      0x10
#define RFM_IRQ_TX_DONE                           0x08
#define RFM_IRQ_CAD_DONE                          0x04
#define RFM_IRQ_FHSS_CHANGE_CHANNEL               0x02
#define RFM_IRQ_CAD_DETECTED                      0x01

// RFM_REG_18_MODEM_STAT                          0x18
#define RFM_RX_CODING_RATE                        0xe0
#define RFM_MODEM_STATUS_CLEAR                    0x10
#define RFM_MODEM_STATUS_HEADER_INFO_VALID        0x08
#define RFM_MODEM_STATUS_RX_ONGOING               0x04
#define RFM_MODEM_STATUS_SIGNAL_SYNCHRONIZED      0x02
#define RFM_MODEM_STATUS_SIGNAL_DETECTED          0x01

// RFM_REG_1C_HOP_CHANNEL                         0x1c
#define RFM_PLL_TIMEOUT                           0x80
#define RFM_RX_PAYLOAD_CRC_IS_ON                  0x40
#define RFM_FHSS_PRESENT_CHANNEL                  0x3f

// RFM_REG_1D_MODEM_CONFIG1                       0x1d
#define RFM_BW                                    0xf0

#define RFM_BW_7_8KHZ                             0x00
#define RFM_BW_10_4KHZ                            0x10
#define RFM_BW_15_6KHZ                            0x20
#define RFM_BW_20_8KHZ                            0x30
#define RFM_BW_31_25KHZ                           0x40
#define RFM_BW_41_7KHZ                            0x50
#define RFM_BW_62_5KHZ                            0x60
#define RFM_BW_125KHZ                             0x70
#define RFM_BW_250KHZ                             0x80
#define RFM_BW_500KHZ                             0x90

#define RFM_CODING_RATE                           0x0e
#define RFM_CODING_RATE_4_5                       0x02
#define RFM_CODING_RATE_4_6                       0x04
#define RFM_CODING_RATE_4_7                       0x06
#define RFM_CODING_RATE_4_8                       0x08

#define RFM_IMPLICIT_HEADER_MODE_ON               0x01

// RFM_REG_1E_MODEM_CONFIG2                       0x1e
#define RFM_SPREADING_FACTOR                      0xf0
#define RFM_SPREADING_FACTOR_64CPS                0x60
#define RFM_SPREADING_FACTOR_128CPS               0x70
#define RFM_SPREADING_FACTOR_256CPS               0x80
#define RFM_SPREADING_FACTOR_512CPS               0x90
#define RFM_SPREADING_FACTOR_1024CPS              0xa0
#define RFM_SPREADING_FACTOR_2048CPS              0xb0
#define RFM_SPREADING_FACTOR_4096CPS              0xc0
#define RFM_TX_CONTINUOUS_MODE                    0x08

#define RFM_PAYLOAD_CRC_ON                        0x04
#define RFM_SYM_TIMEOUT_MSB                       0x03

// RFM_REG_26_MODEM_CONFIG3  
#define RFM_MOBILE_NODE                           0x08 // HopeRF term
#define RFM_LOW_DATA_RATE_OPTIMIZE                0x08 // Semtechs term
#define RFM_AGC_AUTO_ON                           0x04

// RFM_REG_40_DIO_MAPPING1  
#define RFM_IO_0_IRQ_RX_DONE                      (0 << 6)
#define RFM_IO_0_IRQ_TX_DONE                      (1 << 6)
#define RFM_IO_0_IRQ_CAD_DONE                     (2 << 6)

#define RFM_IO_1_IRQ_RX_TIMEOUT                   (0 << 4)
#define RFM_IO_1_IRQ_FHSS_CHANGE                  (1 << 4)
#define RFM_IO_1_IRQ_CAD_DETECTED                 (2 << 4)

#define RFM_IO_2_IRQ_FHSS_CHANGE                  (0 << 2)

#define RFM_IO_3_IRQ_CAD_DONE                     (0 << 0)
#define RFM_IO_3_IRQ_VALID_HEADER                 (1 << 0)
#define RFM_IO_3_IRQ_CRC_ERROR                    (2 << 0)

// RFM_REG_40_DIO_MAPPING2  
#define RFM_IO_4_IRQ_CAD_DETECTED                 (0 << 6)
#define RFM_IO_4_IRQ_PLL_LOCK                     (1 << 6)

#define RFM_IO_5_IRQ_MODE_READY                   (0 << 4)
#define RFM_IO_5_IRQ_CLKOUT                       (1 << 4)

// RFM_REG_4D_PA_DAC                              0x4d
#define RFM_PA_DAC_DISABLE                        0x04
#define RFM_PA_DAC_ENABLE                         0x07
#define RFM_PA_DAC_MASK                           0x07
// #endregion
/** @} */

/** @addtogroup RFM_API
 * @{
 */

/** @brief Max number of octets the LORA Rx/Tx FIFO can hold */
#define RFM_FIFO_SIZE 255

/** @brief This is the maximum number of bytes that can be carried by the LORA */
#define RFM_MAX_PAYLOAD_LEN RFM_FIFO_SIZE

/** @brief The length of the headers we add to to the packet */
#define RFM_HEADER_LEN 4

/** @brief This is the maximum message length that can be supported by this driver */
#define RFM_PACKET_DATA_LEN_MAX (RFM_MAX_PAYLOAD_LEN - RFM_HEADER_LEN)

/** @brief The crystal oscillator frequency of the module */
#define RFM_FXOSC 32000000.0

/** @brief The Frequency Synthesizer step = RFM_FXOSC / 2^^19 */
#define RFM_FSTEP  (RFM_FXOSC / 524288)

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief RFM data packet structure 
 * 
 * Defines the packet structure for the radio module
*/
typedef struct rfm_packet_s
{
    #define RFM_PACKET_LENGTH 16
    #define RFM_TX_TIMEOUT 100000

    // Data Buffer
    union {
        uint8_t buffer[RFM_PACKET_LENGTH];

        struct{
                uint32_t    device_number;
                uint32_t    msg_number;
                int8_t      power;
                uint16_t    battery;
                int16_t     temperature;
        };     
    }data;
    
    // Usefull info
    uint8_t     flags;
    bool        crc_ok;
    int8_t      snr;
    int16_t     rssi;  

    // Basic message organization
    enum
    {
        RFM_PACKET_DEV_NUM_0 = 0,    RFM_PACKET_DEV_NUM_1, RFM_PACKET_DEV_NUM_2, RFM_PACKET_DEV_NUM_3,
        RFM_PACKET_MSG_NUM_0,        RFM_PACKET_MSG_NUM_1, RFM_PACKET_MSG_NUM_2, RFM_PACKET_MSG_NUM_3,
        RFM_PACKET_POWER, 
        RFM_PACKET_BATTERY_0, RFM_PACKET_BATTERY_1, 
        RFM_PACKET_TEMP_0, RFM_PACKET_TEMP_1
    }packet_data_e;

}rfm_packet_t;

/** @brief Size of buffer that holds RFM packets
 */
#define PACKETS_BUF_SIZE 16

/* Updated when packet received 
// extern uint8_t      packets_head = 0;
// extern uint8_t      packets_tail = 0;
// extern rfm_packet_t packets_buf[PACKETS_BUF_SIZE];
*/

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void rfm_init(void);
void rfm_reset(void);
void rfm_end(void);
void rfm_calibrate_crystal(void);
void rfm_config_for_lora(uint8_t BW, uint8_t CR, uint8_t SF, bool crc_turn_on, int8_t power);
void rfm_config_for_gfsk(void);
void rfm_set_power(int8_t power, uint8_t ramp_time);
void rfm_get_stats(void);
void rfm_reset_stats(void);
uint8_t rfm_get_version(void);

void            rfm_start_listening(void);
void            rfm_get_packets(void);
rfm_packet_t*   rfm_get_next_packet(void);
uint8_t         rfm_get_num_packets(void);

bool rfm_transmit_packet(rfm_packet_t packet);
void rfm_set_tx_continuous(void);
void rfm_clear_tx_continuous(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // RFM_H 