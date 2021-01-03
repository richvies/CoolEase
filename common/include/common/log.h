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

#define ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS   0x0000
#define ERR_BOOT_PROG_TOO_BIG                       0x0001
#define ERR_BOOT_PROG_BAD_CHECKSUM                  0x0002
#define ERR_BOOT_PROG_FLASH_ERASE                   0x0003
#define ERR_BOOT_PROG_FLASH_WRITE_1                 0x0004
#define ERR_BOOT_PROG_FLASH_WRITE_2                 0x0005

#define ERR_USB_PAGE_CHECKSUM_BAD                   0x0101    
#define ERR_USB_PAGE_ERASE_FAIL                     0x0102
#define ERR_USB_PROGRAM_UPPER_HALF_PAGE_FAIL        0x0103
#define ERR_USB_PROGRAM_LOWER_HALF_PAGE_FAIL        0x0104

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
uint8_t log_get_byte(uint16_t index);
void log_read_reset(void);
uint8_t log_read(void);
uint16_t log_size(void);
void log_erase(void);

void serial_printf(const char *format, ...);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // LOG_H 

