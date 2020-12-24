#ifndef CC1101_H
#define CC1101_H

#include <stdint.h>
#include <stdbool.h>

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
    uint8_t rssi;

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

float cc1101_temperature(void);

#endif