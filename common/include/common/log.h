/**
 ******************************************************************************
 * @file    log.h
 * @author  Richard Davies
 * @date    30/Dec/2020
 * @brief   Log Header File
 *  
 * @defgroup   LOG_FILE  Log
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   LOG_API  Log API
 * @brief      
 * 
 * @defgroup   LOG_INT  Log Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef LOG_H
#define LOG_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup LOG_API
 * @{
 */

/** @addtogroup LOG_ERR Logging Errors
 * @{
 */

#define ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS   0
#define ERR_BOOT_PROG_TOO_BIG                       1
#define ERR_BOOT_PROG_BAD_CHECKSUM                  2
#define ERR_BOOT_PROG_FLASH_ERASE                   3
#define ERR_BOOT_PROG_FLASH_WRITE_1                 4
#define ERR_BOOT_PROG_FLASH_WRITE_2                 5

/** @} */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/
void log_init(void);
void log_printf(const char *format, ...);
void log_error(uint16_t error);
uint8_t log_get(uint16_t index);

void serial_printf(const char *format, ...);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // LOG_H 
