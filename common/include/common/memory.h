#ifndef MEM_H
#define MEM_H

#include <stdint.h>
#include <libopencm3/stm32/flash.h>     
#include <libopencm3/stm32/rcc.h>   

#define LOG_SIZE            1024


void mem_init(void);

void mem_eeprom_write_word(uint32_t address, uint32_t data);
bool mem_eeprom_write_half_word(uint32_t address, uint16_t data);
bool mem_eeprom_write_byte(uint32_t address, uint8_t data);

void mem_flash_erase_page(uint32_t address);
bool mem_flash_write_half_page(uint32_t address, uint32_t *data);

void mem_save_reading(int16_t reading);

uint32_t mem_get_dev_state(void);
uint32_t mem_get_dev_num(void);
uint32_t mem_get_msg_num(void);
void mem_update_msg_num(uint32_t new);
uint32_t mem_get_num_readings(void);
int16_t mem_get_reading(uint32_t reading_num);

int mem_log_printf(const char* format, ...);
void mem_get_log(char log[LOG_SIZE]);
void mem_wipe_log(void);
void mem_print_log(void);

void mem_get_aes_key(uint8_t *aes_key);
void mem_set_aes_key(uint8_t *aes_key);
void mem_get_aes_key_exp(uint8_t *aes_key_exp);
void mem_set_aes_key_exp(uint8_t *aes_key_exp);

void mem_wipe_readings(void);

#endif