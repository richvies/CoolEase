#ifndef si4432_H
#define si4432_H

#include <stdint.h>
#include <stdbool.h>

/*
 * Buffer and data lengths
 */
#define SI4432_PACKET_BUFFER_LEN        64
#define SI4432_PACKET_DATA_LEN          SI4432_PACKET_BUFFER_LEN - 3

/*
 * SI4432 data packet structure
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
    uint8_t data[SI4432_PACKET_DATA_LEN];
    
}si4432_packet_t;


/**
 * Global Function Decls
 */

/*
 * si4432_init
 * 
 * Initialize SI4432 radio
 */
void si4432_init(void);

/*
 * si4432_reset
 * 
 * Reset and reconfigure si4432 uint8_t
 * Also set tx power level to index 0
 */
void si4432_reset(void);

/**
 * si4432_end
 * 
 * Shut down si4432
 * Disable spi perpheral and clock
 */
void si4432_end(void);

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
bool si4432_transmit_packet(si4432_packet_t packet);

/*
 * si4432_start_listening
 * 
 * Clear transmit fifo
 * Enable interrupts
 * Enter receive state
 */
void si4432_start_listening(void);

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
uint8_t si4432_get_packet(si4432_packet_t *packet);

/*
 * si4432_change_channel
 * 
 * Change currently used channel
 * Value from 1 to 10
 */
void si4432_change_channel(uint8_t chnl);

#endif /* si4432_H_ */
