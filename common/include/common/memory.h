/**
 ******************************************************************************
 * @file    memory.h
 * @author  Richard Davies
 * @date    29/Dec/2020
 * @brief   Memory Management Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup memory_api Memory Management
 *   @brief    Flash and EEPROM access and management functionality
 *
 *   This module provides functions for accessing and managing non-volatile
 *   memory, including:
 *   - Flash memory read/write operations
 *   - EEPROM data storage
 *   - Device state and configuration storage
 *   - Sensor readings storage
 *   - Logging data management
 * @}
 ******************************************************************************
 */

#ifndef MEMORY_H
#define MEMORY_H

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rcc.h>
#include <stdint.h>

#include "config/board_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup memory_api
 * @{
 */

/**
 * @brief Initialize memory subsystems
 * @return None
 */
void mem_init(void);

/**
 * @name EEPROM Operations
 * @{
 */

/**
 * @brief Write a 32-bit word to EEPROM
 * @param address EEPROM address
 * @param data 32-bit data to write
 * @return true if successful, false otherwise
 */
bool mem_eeprom_write_word(uint32_t address, uint32_t data);

/**
 * @brief Write a 16-bit half-word to EEPROM
 * @param address EEPROM address
 * @param data 16-bit data to write
 * @return true if successful, false otherwise
 */
bool mem_eeprom_write_half_word(uint32_t address, uint16_t data);

/**
 * @brief Write a byte to EEPROM
 * @param address EEPROM address
 * @param data 8-bit data to write
 * @return true if successful, false otherwise
 */
bool mem_eeprom_write_byte(uint32_t address, uint8_t data);

/**
 * @brief Write a 32-bit word to EEPROM using a pointer
 * @param ptr Pointer to EEPROM address
 * @param data 32-bit data to write
 * @return true if successful, false otherwise
 */
bool mem_eeprom_write_word_ptr(uint32_t* ptr, uint32_t data);
/** @} */

/**
 * @name Flash Operations
 * @{
 */

/**
 * @brief Erase a flash page
 * @param address Address within the page to erase
 * @return true if successful, false otherwise
 */
bool mem_flash_erase_page(uint32_t address);

/**
 * @brief Write a 32-bit word to flash
 * @param address Flash address
 * @param data 32-bit data to write
 * @return true if successful, false otherwise
 */
bool mem_flash_write_word(uint32_t address, uint32_t data);

/**
 * @brief Write half a page (64 bytes) to flash
 * @param address Flash address
 * @param data Pointer to 16 words (64 bytes) of data
 * @return true if successful, false otherwise
 */
bool mem_flash_write_half_page(uint32_t address, uint32_t* data);
/** @} */

/**
 * @name Sensor Reading Management
 * @{
 */

/**
 * @brief Save a temperature reading to storage
 * @param reading Temperature reading value
 * @return None
 */
void mem_save_reading(int16_t reading);

/**
 * @brief Get the device state
 * @return Device state as a 32-bit value
 */
uint32_t mem_get_dev_state(void);

/**
 * @brief Get the device number
 * @return Device number
 */
uint32_t mem_get_dev_num(void);

/**
 * @brief Get the current message number
 * @return Message number
 */
uint32_t mem_get_msg_num(void);

/**
 * @brief Update the message number
 * @param new New message number
 * @return None
 */
void mem_update_msg_num(uint32_t new);

/**
 * @brief Get the number of stored readings
 * @return Number of readings
 */
uint32_t mem_get_num_readings(void);

/**
 * @brief Get a specific temperature reading
 * @param reading_num Reading index
 * @return Temperature reading value
 */
int16_t mem_get_reading(uint32_t reading_num);
/** @} */

/**
 * @name Log Management
 * @{
 */

/**
 * @brief Get the log data
 * @param log Buffer to store log data (must be EEPROM_LOG_SIZE bytes)
 * @return None
 */
void mem_get_log(char log[EEPROM_LOG_SIZE]);

/**
 * @brief Clear the log data
 * @return None
 */
void mem_wipe_log(void);

/**
 * @brief Print the log data
 * @return None
 */
void mem_print_log(void);
/** @} */

/**
 * @name Encryption Key Management
 * @{
 */

/**
 * @brief Get the AES encryption key
 * @param aes_key Buffer to store the key (16 bytes)
 * @return None
 */
void mem_get_aes_key(uint8_t* aes_key);

/**
 * @brief Set the AES encryption key
 * @param aes_key Buffer containing the key (16 bytes)
 * @return None
 */
void mem_set_aes_key(uint8_t* aes_key);

/**
 * @brief Get the expanded AES key
 * @param aes_key_exp Buffer to store the expanded key
 * @return None
 */
void mem_get_aes_key_exp(uint8_t* aes_key_exp);

/**
 * @brief Set the expanded AES key
 * @param aes_key_exp Buffer containing the expanded key
 * @return None
 */
void mem_set_aes_key_exp(uint8_t* aes_key_exp);
/** @} */

/**
 * @brief Clear all stored readings
 * @return None
 */
void mem_wipe_readings(void);

/**
 * @name Backup Register Operations
 * @{
 */

/**
 * @brief Program a backup register
 * @param reg Register number
 * @param data Data to write
 * @return None
 */
void mem_program_bkp_reg(uint8_t reg, uint32_t data);

/**
 * @brief Read from a backup register
 * @param reg Register number
 * @return Register value
 */
uint32_t mem_read_bkp_reg(uint8_t reg);
/** @} */

/** @} */ /* End of memory_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // MEMORY_H
