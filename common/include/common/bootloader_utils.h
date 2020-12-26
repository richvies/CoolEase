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

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup BOOTLOADER_UTILS_API
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Exported Variables
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Exported Function Declarations
////////////////////////////////////////////////////////////////////////////////

void boot_deinit(void);
void boot_jump_to_application(uint32_t address);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* BOOTLOADER_UTILS_H */