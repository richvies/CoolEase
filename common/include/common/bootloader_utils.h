/**
 ******************************************************************************
 * @file    bootloader_utils.h
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Bootloader Utilities Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup bootloader_api Bootloader Utilities
 *   @brief    Common bootloader functionality for firmware updates
 *
 *   This module provides utilities for bootloader operations including:
 *   - Application verification and launching
 *   - Flash memory programming
 *   - Checksum verification
 *   - Fallback mechanisms for failed updates
 * @}
 ******************************************************************************
 */

 #ifndef BOOTLOADER_UTILS_H
 #define BOOTLOADER_UTILS_H

 // Includes
 #include <stdbool.h>
 #include <stdint.h>

 #include "common/memory.h"

 #ifdef __cplusplus
 extern "C" {
 #endif

 /** @addtogroup common
  * @{
  */

 /** @addtogroup bootloader_api
  * @{
  */

 /**
  * @brief Bootloader logging macro
  *
  * Convenience macro for bootloader-specific logging with prefix
  */
 #define BOOT_LOG                                                               \
     log_printf("BOOT: ");                                                      \
     log_printf

 /**
  * @brief Initialize bootloader systems
  * @return None
  */
 void boot_init(void);

 /**
  * @brief Clean up and terminate bootloader operations
  * @return None
  */
 void boot_deinit(void);

 /**
  * @brief Jump to application at specified address
  * @param address Start address of the application
  * @return None
  */
 void boot_jump_to_application(uint32_t address);

 /**
  * @brief Execute fallback procedure when boot fails
  * @return None
  */
 void boot_fallback(void);

 /**
  * @brief Program half of a flash page
  * @param lower true for lower half, false for upper half
  * @param crc_expected Expected CRC value for verification
  * @param page_num Flash page number
  * @param data Array of 16 words (64 bytes) to program
  * @return true if successful, false otherwise
  */
 bool boot_program_half_page(bool lower, uint32_t crc_expected,
                             uint32_t page_num, uint32_t data[16]);

 /**
  * @brief Program a complete application to flash
  * @param data Pointer to application data
  * @param start_address Start address for programming
  * @param len Length of application data in bytes
  * @param crc Expected CRC value for verification
  * @return true if successful, false otherwise
  */
 bool boot_program_application(uint32_t* data, uint32_t start_address,
                               uint32_t len, uint32_t crc);

 /**
  * @brief Verify data checksum
  * @param data Pointer to data
  * @param len Length of data in bytes
  * @param expected Expected checksum value
  * @return true if checksum matches, false otherwise
  */
 bool boot_verify_checksum(uint32_t* data, uint32_t len, uint32_t expected);

 /**
  * @brief Calculate checksum for half page of data
  * @param data Array of 16 words (64 bytes)
  * @return Calculated checksum value
  */
 uint32_t boot_get_half_page_checksum(uint32_t data[16]);

 /** @} */ /* End of bootloader_api group */
 /** @} */ /* End of common group */

 #ifdef __cplusplus
 }
 #endif

 #endif // BOOTLOADER_UTILS_H
