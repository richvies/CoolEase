#include "common/aes.h"

#include <stdbool.h>

#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"
#include "common/serial_printf.h"
#include "common/timers.h"
#include "common/memory.h"

// Flash and EEPROM Read by Word, Half Word or byte
// Flash and EEPROM erase by page
// Flash programmed by word or half page
// EEPROM programmed by word, half word or byte

#define FLASH_PAGE_SIZE     128
#define FLASH_NUM_PAGES     512
#define FLASH_START         0x08000000           
#define FLASH_END           0x08010000   

#define EEPROM_PAGE_SIZE    4
#define EEPROM_NUM_PAGES    512
#define EEPROM_START        0x08080000
#define EEPROM_END          0x08080800

#define STATE_FIRST_RUN     (1 << 0)
#define STATE_ATTACHED      (1 << 1)

// Logging
#define LOG_START           0x08080400 
static uint32_t log_add =   LOG_START;


// Temperature readings saved in flash, 8Kb
#define READINGS_START              ( FLASH_END - 8192 )
#define MAX_READINGS                2048
static uint32_t next_reading_add =  READINGS_START;

// Other device information saved in EEPROM
static uint32_t dev_state_add       = 0x08080000;
static uint32_t dev_num_add         = 0x08080004;
static uint32_t aes_key_add         = 0x08080100;
static uint32_t aes_key_exp_add     = 0x08080200;
static uint32_t msg_num_add         = 0x08080300;

static uint32_t msg_num             = 0;

static void flash_erase_page(uint32_t add);


void        mem_init(void)
{
    rcc_periph_clock_enable(RCC_MIF);

    // Wipe readings if first time turning on, and update device state
    if(!MMIO32(dev_state_add))
    {
        mem_wipe_readings();
        mem_program_word(dev_state_add, 0x11111111);
    }

    // Get number of messages and next reading memory location
    msg_num = MMIO32(msg_num_add);
    while(MMIO32(next_reading_add) != 0x00000000)
    {
        // spf_serial_printf("%08x : %08x\n", next_reading_add, MMIO32(next_reading_add));
        msg_num++;
        next_reading_add += 4;
    }
}


void        mem_program_word(uint32_t address, uint32_t data)
{
    flash_unlock();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO32(address) = data;

    while (FLASH_SR & FLASH_SR_BSY);
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock();
}

bool        mem_program_half_word(uint32_t address, uint16_t data)
{
    if( !(address >= EEPROM_START && address < EEPROM_END) )
        return false;

    flash_unlock();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO16(address) = data;
    while (FLASH_SR & FLASH_SR_BSY);
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock();

    return true;
}

bool        mem_program_byte(uint32_t address, uint8_t data)
{
    if( !(address >= EEPROM_START && address < EEPROM_END) )
        return false;

    flash_unlock();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO8(address) = data;
    while (FLASH_SR & FLASH_SR_BSY);
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock();

    return true;
}

void        mem_save_reading(int16_t reading)
{
    msg_num++;
    mem_program_word(next_reading_add, reading);
    next_reading_add += 4;

    if(msg_num % MAX_READINGS == 0)
    {
        mem_program_word(msg_num_add, msg_num);
        mem_wipe_readings();
        next_reading_add = READINGS_START;
    }
}


uint32_t    mem_get_dev_state(void)
{
    return MMIO32(dev_state_add);
}

uint32_t    mem_get_dev_num(void)
{
    return MMIO32(dev_num_add);
}

uint32_t    mem_get_msg_num(void)
{
    return msg_num;
}

void        mem_update_msg_num(uint32_t new)
{
    mem_program_word(msg_num_add, new);
}


uint32_t    mem_get_num_readings(void)
{
    return msg_num;
}

int16_t     mem_get_reading(uint32_t reading_num)
{
    return MMIO32(READINGS_START + (reading_num * 4));
}


int         mem_log_printf(const char* format, ...)
{
  	va_list va;
  	va_start(va, format);
  	const int ret = vprintf_log(format, va);
  	va_end(va);

	return ret;
}

void        _putchar_log(char character)
{
    mem_program_byte(log_add++, character);
    if(log_add >= LOG_START + LOG_SIZE)
            log_add = LOG_START; 
}

void        mem_wipe_log(void)
{
    
}

void        mem_get_log(char log[LOG_SIZE])
{
    for(uint16_t i = 0; i < LOG_SIZE; i++)
    {
        log[i] = MMIO32(LOG_START + i);
    }
}

void        mem_print_log(void)
{
    spf_serial_printf("LOG START\n");
    for(uint16_t i = 0; i < LOG_SIZE; i++)
    {
        spf_serial_printf("%c", MMIO8(LOG_START + i));
    }   
    spf_serial_printf("LOG END\n");
}


void        mem_get_aes_key(uint8_t *aes_key)
{
    uint32_t tmp;

    for(int i = 0; i < 4; i++)
    {
        tmp = MMIO32(aes_key_add + (i * 4));

        aes_key[i * 4]          = tmp;
        aes_key[(i * 4) + 1]    = tmp >> 8;
        aes_key[(i * 4) + 2]    = tmp >> 16;
        aes_key[(i * 4) + 3]    = tmp >> 24;
    } 
}

void        mem_set_aes_key(uint8_t *aes_key)
{
    uint32_t tmp = 0;

    for(int i = 0; i < 4; i++)
    {
        tmp |= aes_key[i * 4];
        tmp |= aes_key[(i * 4) + 1] << 8;
        tmp |= aes_key[(i * 4) + 2] << 16;
        tmp |= aes_key[(i * 4) + 3] << 24;

        eeprom_program_word(aes_key_add + (i * 4), tmp);

        tmp = 0;
    } 
}

void        mem_get_aes_key_exp(uint8_t *aes_key_exp)
{
    uint32_t tmp;

    for(int i = 0; i < 44; i++)
    {
        tmp = MMIO32(aes_key_exp_add + (i * 4));

        aes_key_exp[i * 4]          = tmp;
        aes_key_exp[(i * 4) + 1]    = tmp >> 8;
        aes_key_exp[(i * 4) + 2]    = tmp >> 16;
        aes_key_exp[(i * 4) + 3]    = tmp >> 24;
    } 
}

void        mem_set_aes_key_exp(uint8_t *aes_key_exp)
{
    uint32_t tmp = 0;

    for(int i = 0; i < 44; i++)
    {
        tmp |= aes_key_exp[i * 4];
        tmp |= aes_key_exp[(i * 4) + 1] << 8;
        tmp |= aes_key_exp[(i * 4) + 2] << 16;
        tmp |= aes_key_exp[(i * 4) + 3] << 24;

        eeprom_program_word(aes_key_exp_add + (i * 4), tmp);

        tmp = 0;
    } 
}

void        mem_wipe_readings(void)
{
    spf_serial_printf("Mem Wipe Readings\n");

    uint32_t page_add = READINGS_START;

    while( page_add < FLASH_END )
    {
        // spf_serial_printf("Erasing %08X\n", page_add);
        flash_erase_page(page_add);
        page_add += FLASH_PAGE_SIZE;
    }

    spf_serial_printf("Done\n", page_add);
}

static void flash_erase_page(uint32_t add)
{
    flash_unlock();

    FLASH_PECR |= FLASH_PECR_ERASE | FLASH_PECR_PROG; 
    
    MMIO32(add) = (uint32_t)0;

    while ((FLASH_SR & FLASH_SR_BSY) != 0);

    if ((FLASH_SR & FLASH_SR_EOP) != 0) {
        FLASH_SR = FLASH_SR_EOP; }

    FLASH_PECR &= ~(FLASH_PECR_ERASE | FLASH_PECR_PROG);

    flash_lock();
}
