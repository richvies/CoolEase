#ifndef AES_H
#define AES_H

#include <stdint.h>

#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only

#define AES_KEY_LEN 16   // Key length in bytes
#define AES_KEY_EXP_SIZE 176

void aes_init(void);
void aes_expand_key(void);
void aes_ecb_encrypt(uint8_t* buf);
void aes_ecb_decrypt(uint8_t* buf);
void aes_generate_random(uint8_t *buf, uint8_t len);


#endif // _AES_H_
