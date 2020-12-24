#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdint.h>

/**
 * crypt_init
 * 
 * Seed random generator
 * Initialize AES context
*/
void crypt_init(void);

void crypt_update_random_seed(void);

/**
 * crypt_encrypt_message
 * 
 * Take message and convert to 16 byte encrypted packet
 * Message 5 bytes long, rest is random
 * B0 - Group #
 * B1 - Dev #
 * B2 - Ver #
 * B3 - Mesage #
 * B3 - V Batt
 * B4 - Temp
 */
void crypt_encrypt_message(uint8_t (*message), uint8_t (*cpiher_text));

/**
 * crypt_decrypt_message
 * 
 * Take cipher text and convert to 5 message
 * Cipher text 16 bytes long
 * B0 - Group #
 * B1 - Dev #
 * B2 - Ver #
 * B3 - Mesage #
 * B3 - V Batt
 * B4 - Temp
 */
void crypt_decrypt_message(uint8_t (*cipher_text), uint8_t (*message));




// Monocypher Implementation
/*void encrypt_message(uint8_t* plain_text, uint8_t* cipher_text, uint8_t* message);
int decrypt_message(uint8_t* plain_text, uint8_t* cipher_text, uint8_t* message);*/

#endif