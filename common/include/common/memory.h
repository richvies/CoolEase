/**
 ******************************************************************************
 * @file    memory.h
 * @author  Richard Davies
 * @date    29/Dec/2020
 * @brief   Memory Header File
 *  
 * @defgroup   MEMORY_FILE  Memory
 * @brief      
 * 
 * Read and write to eeprom and flash is working 12/29/2020
 * 
 * @note     
 * 
 * @{
 * @defgroup   MEMORY_API  Memory API
 * @brief      
 * 
 * @defgroup   MEMORY_INT  Memory Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef MEMORY_H
#define MEMORY_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <libopencm3/stm32/flash.h>     
#include <libopencm3/stm32/rcc.h>  


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup MEMORY_API
 * @{
 */

// Flash and EEPROM Read by Word, Half Word or byte
// Flash and EEPROM erase by page (128 bytes / 4 bytes)
// Flash programmed by word or half page
// EEPROM programmed by word, half word or byte

/*////////////////////////////////////////////////////////////////////////////*/
// Flash Map
/*////////////////////////////////////////////////////////////////////////////*/

#define FLASH_PAGE_SIZE     128U
#define FLASH_NUM_PAGES     512U
#define FLASH_START         0x08000000U           
#define FLASH_APP_START     0x08004000U  
#define FLASH_APP_END       0x0800C000U       
#define FLASH_END           0x08010000U   

#define FLASH_BOOTLOADER_ADDRESS    0x08000000U
#define FLASH_APP_ADDRESS           0x08004000U

/*////////////////////////////////////////////////////////////////////////////*/
// EEPROM Map
/*////////////////////////////////////////////////////////////////////////////*/

#define EEPROM_PAGE_SIZE    4U
#define EEPROM_NUM_PAGES    512U
#define EEPROM_START        0x08080000U
#define EEPROM_SIZE         2048U
#define EEPROM_END          EEPROM_START + EEPROM_SIZE


// Size of sections within eeprom
#define EEPROM_BOOTLOADER_INFO_SIZE 256U
#define EEPROM_DEV_INFO_SIZE        256U
#define EEPROM_LOG_SIZE             1024U

#if ((EEPROM_BOOTLOADER_INFO_SIZE + EEPROM_DEV_INFO_SIZE + EEPROM_LOG_SIZE) > EEPROM_SIZE)
#warning "EEPROM: Data does not fit"
#endif

// Bootloader Information
#define EEPROM_BOOTLOADER_INFO_BASE      EEPROM_START
#define EEPROM_BOOTLOADER_INFO_END       EEPROM_BOOTLOADER_INFO_BASE + EEPROM_BOOTLOADER_INFO_SIZE

// Device information
#define EEPROM_DEV_INFO_BASE             EEPROM_BOOTLOADER_INFO_END          
#define EEPROM_DEV_INFO_END              EEPROM_DEV_INFO_BASE + EEPROM_DEV_INFO_SIZE 

// Logging
#define EEPROM_LOG_BASE                 EEPROM_DEV_INFO_END
#define EEPROM_LOG_END                  EEPROM_LOG_BASE + EEPROM_LOG_SIZE


/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void mem_init(void);

bool mem_eeprom_write_word(uint32_t address, uint32_t data);
bool mem_eeprom_write_half_word(uint32_t address, uint16_t data);
bool mem_eeprom_write_byte(uint32_t address, uint8_t data);

bool mem_flash_erase_page(uint32_t address);
bool mem_flash_write_word(uint32_t address, uint32_t data);
bool mem_flash_write_half_page(uint32_t address, uint32_t data[FLASH_PAGE_SIZE/2]);

void mem_save_reading(int16_t reading);

uint32_t mem_get_dev_state(void);
uint32_t mem_get_dev_num(void);
uint32_t mem_get_msg_num(void);
void     mem_update_msg_num(uint32_t new);
uint32_t mem_get_num_readings(void);
int16_t  mem_get_reading(uint32_t reading_num);

void mem_get_log(char log[EEPROM_LOG_SIZE]);
void mem_wipe_log(void);
void mem_print_log(void);

void mem_get_aes_key(uint8_t *aes_key);
void mem_set_aes_key(uint8_t *aes_key);
void mem_get_aes_key_exp(uint8_t *aes_key_exp);
void mem_set_aes_key_exp(uint8_t *aes_key_exp);

void mem_wipe_readings(void);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // MEMORY_H 