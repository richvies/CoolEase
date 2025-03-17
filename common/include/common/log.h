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

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup LOG_API
 * @{
 */

/** @addtogroup LOG_ERR Logging Errors
 * @{
 */

#define ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS 0x0000
#define ERR_BOOT_PROG_TOO_BIG                     0x0001
#define ERR_BOOT_PROG_BAD_CHECKSUM                0x0002
#define ERR_BOOT_PROG_FLASH_ERASE                 0x0003
#define ERR_BOOT_PROG_FLASH_WRITE_1               0x0004
#define ERR_BOOT_PROG_FLASH_WRITE_2               0x0005

#define ERR_USB_PAGE_CHECKSUM_BAD            0x0101
#define ERR_USB_PAGE_ERASE_FAIL              0x0102
#define ERR_USB_PROGRAM_UPPER_HALF_PAGE_FAIL 0x0103
#define ERR_USB_PROGRAM_LOWER_HALF_PAGE_FAIL 0x0104

#define ERR_SIM_AT                0x0200
#define ERR_SIM_CFUN_0            0x0201
#define ERR_SIM_CFUN_1            0x0202
#define ERR_SIM_CREG_NONE         0x0203
#define ERR_SIM_CREG_0            0x0204
#define ERR_SIM_SAPBR_CONFIG      0x0205
#define ERR_SIM_HTTPINIT          0x0206
#define ERR_SIM_HTTPPARA_CID      0x0207
#define ERR_SIM_HTTPPARA_URL      0x0208
#define ERR_SIM_SAPBR_CONNECT     0x0209
#define ERR_SIM_HTTP_GET          0x020A
#define ERR_SIM_HTTPACTION_0      0x020B
#define ERR_SIM_HTTP_GET_TIMEOUT  0x020C
#define ERR_SIM_HTTPTERM          0x020D
#define ERR_SIM_HTTP_READ_TIMEOUT 0x020E
#define ERR_SIM_SAPBR_DISCONNECT  0x020F
#define ERR_SIM_INIT_NO_RESPONSE  0x0210
#define ERR_SIM_ATE_0             0x0211
#define ERR_SIM_CREG_QUERY        0x0212
#define ERR_SIM_INIT              0x0213
#define ERR_SIM_SET_FULL_FUNCTION 0x0214
#define ERR_SIM_HTTP_TERM         0x0215
#define ERR_SIM_CSCLK_1           0x0216
#define ERR_SIM_HTTPSSL           0x0217
#define ERR_SIM_HTTP_CONTENT      0x0218
#define ERR_SIM_HTTPACTION_1      0x0219
#define ERR_SIM_HTTP_POST_TIMEOUT 0x0220
#define ERR_SIM_AUTOBAUD          0x0221
#define ERR_SIM_CLTS              0x0222

/** @} */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void     log_init(void);
void     log_end(void);
void     log_printf(const char* format, ...);
void     log_error(uint16_t error);
uint8_t  log_get_byte(uint16_t index);
void     log_read_reset(void);
uint8_t  log_read(void);
uint16_t log_size(void);
void     log_erase(void);
void     log_create_backup(void);
void     log_erase_backup(void);

void serial_printf(const char* format, ...);
bool serial_available(void);
char serial_read(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // LOG_H
