/**
 ******************************************************************************
 * @file    rfm.h
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Rfm Header File
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

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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

////////////////////////////////////////////////////////////////////////////////
// Exported Variables
////////////////////////////////////////////////////////////////////////////////

/** @brief RFM data packet structure 
 * 
 * Defines the packet structure for the radio module
*/
typedef struct rfm_packet_s
{
    #define RFM_PACKET_LENGTH 16

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

////////////////////////////////////////////////////////////////////////////////
// Exported Function Declarations
////////////////////////////////////////////////////////////////////////////////

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
void            rfm_organize_packet(rfm_packet_t *packet);

bool rfm_transmit_packet(rfm_packet_t packet);
void rfm_set_tx_continuous(void);
void rfm_clear_tx_continuous(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RFM_H */