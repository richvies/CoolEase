/**
 ******************************************************************************
 * @file    aes.h
 * @author  Richard Davies
 * @brief   AES Encryption Module Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup crypto_api Cryptography
 *   @brief    Encryption and security-related functionality
 *   @{
 *     @defgroup aes_api AES Encryption
 *     @brief    AES-128 encryption/decryption implementation
 *   @}
 * @}
 ******************************************************************************
 */

#ifndef AES_H
#define AES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup crypto_api
 * @{
 */

/** @addtogroup aes_api
 * @{
 */

/**
 * @brief AES block length in bytes (128-bit blocks)
 */
#define AES_BLOCKLEN 16

/**
 * @brief AES key length in bytes (128-bit key)
 */
#define AES_KEY_LEN 16

/**
 * @brief Size of expanded AES key
 */
#define AES_KEY_EXP_SIZE 176

/**
 * @brief Initialize AES encryption with the provided key
 * @param key 16-byte (128-bit) encryption key
 * @return None
 */
void aes_init(uint8_t key[16]);

/**
 * @brief Encrypt a block using AES-ECB mode
 * @param buf 16-byte buffer containing data to encrypt (in-place)
 * @return None
 */
void aes_ecb_encrypt(uint8_t* buf);

/**
 * @brief Decrypt a block using AES-ECB mode
 * @param buf 16-byte buffer containing data to decrypt (in-place)
 * @return None
 */
void aes_ecb_decrypt(uint8_t* buf);

/**
 * @brief Generate cryptographically secure random bytes
 * @param buf Buffer to store random bytes
 * @param len Number of random bytes to generate
 * @return None
 */
void aes_generate_random(uint8_t* buf, uint8_t len);

/** @} */ /* End of aes_api group */
/** @} */ /* End of crypto_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // AES_H
