/**
 ******************************************************************************
 * @file    bootloader_utils.h
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Bootloader_utils Header File
 *  
 * @defgroup   BOOTLOADER_UTILS_FILE  Bootloader_utils
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   BOOTLOADER_UTILS_API  Bootloader_utils API
 * @brief      
 * 
 * @defgroup   BOOTLOADER_UTILS_INT  Bootloader_utils Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef BOOTLOADER_UTILS_H
#define BOOTLOADER_UTILS_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup BOOTLOADER_UTILS_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/


/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void boot_init(void);
void boot_deinit(void);
void boot_jump_to_application(uint32_t address);
bool boot_program_application(uint32_t *data, uint32_t start_address, uint32_t len, uint32_t crc);
bool boot_verify_checksum(uint32_t *data, uint32_t len, uint32_t expected);
void boot_fallback(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // BOOTLOADER_UTILS_H 