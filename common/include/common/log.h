/**
 ******************************************************************************
 * @file    log.h
 * @author  Richard Davies
 * @date    30/Dec/2020
 * @brief   Logging System Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup log_api Logging
 *   @brief    System logging and error reporting functionality
 * @}
 ******************************************************************************
 */

#ifndef LOG_H
#define LOG_H

// Includes
#include <stdbool.h>
#include <stdint.h>

#include "board_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup log_api
 * @{
 */

/**
 * @defgroup log_error_codes Error Codes
 * @brief System-wide error code definitions
 * @{
 */

/** @name Bootloader Error Codes
 * @{
 */
#define ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS                              \
    0x0000                           /**< Program start address is invalid */
#define ERR_BOOT_PROG_TOO_BIG 0x0001 /**< Program exceeds available memory */
#define ERR_BOOT_PROG_BAD_CHECKSUM                                             \
    0x0002 /**< Program checksum verification failed */
#define ERR_BOOT_PROG_FLASH_ERASE 0x0003 /**< Flash erase operation failed */
#define ERR_BOOT_PROG_FLASH_WRITE_1                                            \
    0x0004 /**< Flash write operation failed (stage 1) */
#define ERR_BOOT_PROG_FLASH_WRITE_2                                            \
    0x0005 /**< Flash write operation failed (stage 2) */
/** @} */

/** @name USB Error Codes
 * @{
 */
#define ERR_USB_PAGE_CHECKSUM_BAD                                              \
    0x0101 /**< USB page checksum verification failed */
#define ERR_USB_PAGE_ERASE_FAIL 0x0102 /**< USB page erase operation failed */
#define ERR_USB_PROGRAM_UPPER_HALF_PAGE_FAIL                                   \
    0x0103 /**< Failed to program upper half of page */
#define ERR_USB_PROGRAM_LOWER_HALF_PAGE_FAIL                                   \
    0x0104 /**< Failed to program lower half of page */
/** @} */

/** @name SIM800 Error Codes
 * @{
 */
#define ERR_SIM_AT                0x0200 /**< AT command error */
#define ERR_SIM_CFUN_0            0x0201 /**< Set minimum functionality failed */
#define ERR_SIM_CFUN_1            0x0202 /**< Set full functionality failed */
#define ERR_SIM_CREG_NONE         0x0203 /**< Network registration failed */
#define ERR_SIM_CREG_0            0x0204 /**< Network registration query failed */
#define ERR_SIM_SAPBR_CONFIG      0x0205 /**< Bearer configuration failed */
#define ERR_SIM_HTTPINIT          0x0206 /**< HTTP initialization failed */
#define ERR_SIM_HTTPPARA_CID      0x0207 /**< HTTP CID parameter setting failed */
#define ERR_SIM_HTTPPARA_URL      0x0208 /**< HTTP URL parameter setting failed */
#define ERR_SIM_SAPBR_CONNECT     0x0209 /**< Bearer connection failed */
#define ERR_SIM_HTTP_GET          0x020A /**< HTTP GET request failed */
#define ERR_SIM_HTTPACTION_0      0x020B /**< HTTP action 0 failed */
#define ERR_SIM_HTTP_GET_TIMEOUT  0x020C /**< HTTP GET request timed out */
#define ERR_SIM_HTTPTERM          0x020D /**< HTTP termination failed */
#define ERR_SIM_HTTP_READ_TIMEOUT 0x020E /**< HTTP read operation timed out */
#define ERR_SIM_SAPBR_DISCONNECT  0x020F /**< Bearer disconnection failed */
#define ERR_SIM_INIT_NO_RESPONSE                                               \
    0x0210                        /**< No response during initialization */
#define ERR_SIM_ATE_0      0x0211 /**< Echo disable failed */
#define ERR_SIM_CREG_QUERY 0x0212 /**< Network registration query failed */
#define ERR_SIM_INIT       0x0213 /**< Initialization failed */
#define ERR_SIM_SET_FULL_FUNCTION                                              \
    0x0214 /**< Setting full functionality failed */
#define ERR_SIM_HTTP_TERM         0x0215 /**< HTTP termination failed */
#define ERR_SIM_CSCLK_1           0x0216 /**< Sleep mode setting failed */
#define ERR_SIM_HTTPSSL           0x0217 /**< HTTP SSL setting failed */
#define ERR_SIM_HTTP_CONTENT      0x0218 /**< HTTP content setting failed */
#define ERR_SIM_HTTPACTION_1      0x0219 /**< HTTP action 1 failed */
#define ERR_SIM_HTTP_POST_TIMEOUT 0x0220 /**< HTTP POST request timed out */
#define ERR_SIM_AUTOBAUD          0x0221 /**< Autobaud detection failed */
#define ERR_SIM_CLTS              0x0222 /**< Local timestamp setting failed */
/** @} */

/** @} */ /* End of log_error_codes group */

/**
 * @brief Initialize the logging system
 * @return None
 */
void log_init(void);

/**
 * @brief Terminate logging operations
 * @return None
 */
void log_end(void);

/**
 * @brief Log a formatted message
 * @param format Format string
 * @param ... Variable arguments
 * @return None
 */
void log_printf(const char* format, ...);

/**
 * @brief Log a system error
 * @param error Error code
 * @return None
 */
void log_error(uint16_t error);

/**
 * @brief Get a byte from the log buffer
 * @param index Index in the log buffer
 * @return Byte value at the specified index
 */
uint8_t log_get_byte(uint16_t index);

/**
 * @brief Reset the log read pointer
 * @return None
 */
void log_read_reset(void);

/**
 * @brief Read a byte from the log buffer
 * @return Next byte from the log buffer
 */
uint8_t log_read(void);

/**
 * @brief Get the current size of the log buffer
 * @return Size of the log buffer in bytes
 */
uint16_t log_size(void);

/**
 * @brief Erase the log buffer
 * @return None
 */
void log_erase(void);

/**
 * @brief Create a backup of the log buffer
 * @return None
 */
void log_create_backup(void);

/**
 * @brief Erase the log backup
 * @return None
 */
void log_erase_backup(void);

/**
 * @brief Print formatted message to serial output
 * @param format Format string
 * @param ... Variable arguments
 * @return None
 */
void serial_printf(const char* format, ...);

/**
 * @brief Check if serial data is available
 * @return true if data available, false otherwise
 */
bool serial_available(void);

/**
 * @brief Read a character from serial input
 * @return Character read
 */
char serial_read(void);

/**
 * @brief Print AES key information
 * @param info Application information structure
 * @return None
 */
void print_aes_key(app_info_t* info);

/** @} */ /* End of log_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // LOG_H
