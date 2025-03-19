/**
 ******************************************************************************
 * @file    memory.c
 * @author  Richard Davies
 * @date    29/Dec/2020
 * @brief   Memory Source File
 *
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "common/memory.h"

#include <stdbool.h>
#include <stdint.h>

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rtc.h>

#include "common/aes.h"
#include "common/log.h"
#include "common/timers.h"
#include "config/board_defs.h"

/** @addtogroup MEMORY_FILE
 * @{
 */

#define _RAM __attribute__((section(".data#"), noinline))

#define STATE_FIRST_RUN (1 << 0)
#define STATE_ATTACHED  (1 << 1)

// Temperature readings saved in flash, 8Kb
#define READINGS_START (FLASH_END - 8192)
#define MAX_READINGS   2048

/** @addtogroup MEMORY_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static uint32_t next_reading_add = READINGS_START;

// Other device information saved in EEPROM
static uint32_t dev_state_add = 0x08080000;
static uint32_t dev_num_add = 0x08080004;
static uint32_t aes_key_add = 0x08080100;
static uint32_t aes_key_exp_add = 0x08080200;
static uint32_t msg_num_add = 0x08080300;

static uint32_t msg_num = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static _RAM bool mem_flash_do_page_erase(uint32_t address);
static _RAM bool
mem_flash_do_write_half_page(uint32_t address,
                             uint32_t data[FLASH_PAGE_SIZE / 2]);

/** @} */

/** @addtogroup MEMORY_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void mem_init(void) {
    rcc_periph_clock_enable(RCC_MIF);

    // // Wipe readings if first time turning on, and update device state
    // if(!MMIO32(dev_state_add))
    // {
    //     mem_wipe_readings();
    //     mem_eeprom_write_word(dev_state_add, 0x11111111);
    // }

    // // Get number of messages and next reading memory location
    // msg_num = MMIO32(msg_num_add);
    // while(MMIO32(next_reading_add) != 0x00000000)
    // {
    //     // serial_printf("%08x : %08x\n", next_reading_add,
    //     MMIO32(next_reading_add)); msg_num++; next_reading_add += 4;
    // }
}

bool mem_eeprom_write_word(uint32_t address, uint32_t data) {
    if (!(address >= EEPROM_START && address < EEPROM_END))
        return false;

    if (MMIO32(address) == data)
        return true;

    flash_unlock_pecr();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO32(address) = data;

    while (FLASH_SR & FLASH_SR_BSY)
        ;
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock_pecr();

    return true;
}

bool mem_eeprom_write_half_word(uint32_t address, uint16_t data) {
    if (!(address >= EEPROM_START && address < EEPROM_END))
        return false;

    if (MMIO16(address) == data)
        return true;

    flash_unlock_pecr();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO16(address) = data;

    while (FLASH_SR & FLASH_SR_BSY)
        ;
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock_pecr();

    return true;
}

bool mem_eeprom_write_byte(uint32_t address, uint8_t data) {
    if (!(address >= EEPROM_START && address < EEPROM_END)) {
        serial_printf("Mem: EE W out of bounds %8x %2x\n", address, data);
        return false;
    }

    if (MMIO8(address) == data)
        return true;

    flash_unlock_pecr();
    FLASH_PECR &= ~FLASH_PECR_FTDW;

    MMIO8(address) = data;

    while (FLASH_SR & FLASH_SR_BSY)
        ;
    if (FLASH_SR & FLASH_SR_EOP)
        FLASH_SR = FLASH_SR_EOP;

    flash_lock_pecr();

    return true;
}

bool mem_eeprom_write_word_ptr(uint32_t* ptr, uint32_t data) {
    return mem_eeprom_write_word((uint32_t)ptr, data);
}

bool mem_flash_erase_page(uint32_t address) {
    bool    ret = false;
    uint8_t num_tries;

    // Check page aligned
    if (address & 0x7F)
        return false;

    num_tries = 0;
    while ((false == ret) && (num_tries < 3)) {
        flash_unlock();
        ret = mem_flash_do_page_erase(address);
        flash_lock();

        num_tries++;
    }

    if (false == ret) {
        log_printf("MEM: ERR flash erase fail\n");
    }

    return ret;
}

bool mem_flash_write_half_page(uint32_t address, uint32_t* data) {
    bool    ret = false;
    uint8_t num_tries;

    if ((uint32_t)address & 0x3F)
        return false; // not half-page aligned

    num_tries = 0;
    while ((false == ret) && (num_tries < 3)) {
        flash_unlock();
        ret = mem_flash_do_write_half_page(address, data);
        flash_lock();

        num_tries++;
    }

    if (false == ret) {
        log_printf("MEM: ERR flash write hp fail\n");
    }

    return ret;
}

bool mem_flash_write_word(uint32_t address, uint32_t data) {
    bool     ret = false;
    uint32_t timer;

    flash_unlock();

    MMIO32(address) = data;

    // wait for completion
    timer = timers_millis();
    while (1) {
        if (true != (FLASH_SR & FLASH_SR_BSY)) {
            ret = true;
            break;
        } else if (timers_millis() - timer < 100) {
            break;
        }
    }

    flash_lock();

    if ((ret) && (FLASH_SR & FLASH_SR_EOP)) {
        FLASH_SR |= FLASH_SR_EOP;
        ret = true;
    } else {
        ret = false;
        log_printf("MEM: ERR flash write hp fail\n");
    }

    return ret;
}

void mem_save_reading(int16_t reading) {
    msg_num++;
    mem_eeprom_write_word(next_reading_add, reading);
    next_reading_add += 4;

    if (msg_num % MAX_READINGS == 0) {
        mem_eeprom_write_word(msg_num_add, msg_num);
        mem_wipe_readings();
        next_reading_add = READINGS_START;
    }
}

uint32_t mem_get_dev_state(void) {
    return MMIO32(dev_state_add);
}

uint32_t mem_get_dev_num(void) {
    return MMIO32(dev_num_add);
}

uint32_t mem_get_msg_num(void) {
    return msg_num;
}

void mem_update_msg_num(uint32_t new) {
    mem_eeprom_write_word(msg_num_add, new);
}

uint32_t mem_get_num_readings(void) {
    return msg_num;
}

int16_t mem_get_reading(uint32_t reading_num) {
    return MMIO32(READINGS_START + (reading_num * 4));
}

void mem_wipe_log(void) {
}

void mem_get_log(char log[EEPROM_LOG_SIZE]) {
    for (uint16_t i = 0; i < EEPROM_LOG_SIZE; i++) {
        log[i] = MMIO32(EEPROM_LOG_BASE + i);
    }
}

void mem_print_log(void) {
    serial_printf("LOG START\n");
    for (uint16_t i = 0; i < EEPROM_LOG_SIZE; i++) {
        serial_printf("%c", MMIO8(EEPROM_LOG_BASE + i));
    }
    serial_printf("LOG END\n");
}

void mem_get_aes_key(uint8_t* aes_key) {
    uint32_t tmp;

    for (int i = 0; i < 4; i++) {
        tmp = MMIO32(aes_key_add + (i * 4));

        aes_key[i * 4] = tmp;
        aes_key[(i * 4) + 1] = tmp >> 8;
        aes_key[(i * 4) + 2] = tmp >> 16;
        aes_key[(i * 4) + 3] = tmp >> 24;
    }
}

void mem_set_aes_key(uint8_t* aes_key) {
    uint32_t tmp = 0;

    for (int i = 0; i < 4; i++) {
        tmp |= aes_key[i * 4];
        tmp |= aes_key[(i * 4) + 1] << 8;
        tmp |= aes_key[(i * 4) + 2] << 16;
        tmp |= aes_key[(i * 4) + 3] << 24;

        eeprom_program_word(aes_key_add + (i * 4), tmp);

        tmp = 0;
    }
}

void mem_get_aes_key_exp(uint8_t* aes_key_exp) {
    uint32_t tmp;

    for (int i = 0; i < 44; i++) {
        tmp = MMIO32(aes_key_exp_add + (i * 4));

        aes_key_exp[i * 4] = tmp;
        aes_key_exp[(i * 4) + 1] = tmp >> 8;
        aes_key_exp[(i * 4) + 2] = tmp >> 16;
        aes_key_exp[(i * 4) + 3] = tmp >> 24;
    }
}

void mem_set_aes_key_exp(uint8_t* aes_key_exp) {
    uint32_t tmp = 0;

    for (int i = 0; i < 44; i++) {
        tmp |= aes_key_exp[i * 4];
        tmp |= aes_key_exp[(i * 4) + 1] << 8;
        tmp |= aes_key_exp[(i * 4) + 2] << 16;
        tmp |= aes_key_exp[(i * 4) + 3] << 24;

        eeprom_program_word(aes_key_exp_add + (i * 4), tmp);

        tmp = 0;
    }
}

void mem_wipe_readings(void) {
    serial_printf("Mem Wipe Readings\n");

    uint32_t page_add = READINGS_START;

    while (page_add < FLASH_END) {
        // serial_printf("Erasing %08X\n", page_add);
        mem_flash_erase_page(page_add);
        page_add += FLASH_PAGE_SIZE;
    }

    serial_printf("Done\n", page_add);
}

void mem_program_bkp_reg(uint8_t reg, uint32_t data) {
    if (reg < 5) {
        timers_rtc_unlock();
        RTC_BKPXR(reg) = data;
        timers_rtc_lock();
    }
}

uint32_t mem_read_bkp_reg(uint8_t reg) {
    uint32_t data = 0;

    if (reg < 5) {
        data = RTC_BKPXR(reg);
    }
    return data;
}

/** @} */

/** @addtogroup MEMORY_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/**
 * RAM-located function which actually performs page erases.
 *
 * address: Page-aligned address to erase
 */
static _RAM bool mem_flash_do_page_erase(uint32_t address) {
    bool     ret = false;
    uint32_t counter = rcc_ahb_frequency / 10;

    // erase operation
    FLASH_PECR |= FLASH_PECR_ERASE | FLASH_PECR_PROG;
    MMIO32(address) = (uint32_t)0;

    // wait for completion
    while (1) {
        if (false == (FLASH_SR & FLASH_SR_BSY)) {
            ret = true;
            break;
        } else if (counter == 0) {
            break;
        }

        --counter;
    }

    if ((ret) && (FLASH_SR & FLASH_SR_EOP)) {
        // completed without incident
        FLASH_SR = FLASH_SR_EOP;
        ret = true;
    } else {
        // there was an error
        FLASH_SR = FLASH_SR_FWWERR | FLASH_SR_PGAERR | FLASH_SR_WRPERR;
        ret = false;
    }

    FLASH_PECR &= ~(FLASH_PECR_ERASE | FLASH_PECR_PROG);

    return ret;
}

/**
 * RAM-located function which actually performs half-page writes on previously
 * erased pages.
 *
 * address: Half-page aligned address to write
 * data: Array to 16 32-bit words to write
 */
static _RAM bool
mem_flash_do_write_half_page(uint32_t address,
                             uint32_t data[FLASH_PAGE_SIZE / 2]) {
    bool     ret = false;
    uint8_t  i;
    uint32_t counter = rcc_ahb_frequency / 10;

    // half-page program operation
    FLASH_PECR |= FLASH_PECR_PROG | FLASH_PECR_FPRG;
    for (i = 0; i < 16; i++) {
        MMIO32(address) = data[i]; // the actual address written is unimportant
                                   // as these words will be queued
    }

    // wait for completion
    while (1) {
        if (true != (FLASH_SR & FLASH_SR_BSY)) {
            ret = true;
            break;
        } else if (counter == 0) {
            break;
        }
        --counter;
    }

    if ((ret) && (FLASH_SR & FLASH_SR_EOP)) {
        // completed without incident
        FLASH_SR = FLASH_SR_EOP;
        ret = true;
    } else {
        // there was an error
        FLASH_SR = FLASH_SR_FWWERR | FLASH_SR_NOTZEROERR | FLASH_SR_PGAERR |
                   FLASH_SR_WRPERR;
        ret = false;
    }

    FLASH_PECR &= ~(FLASH_PECR_PROG | FLASH_PECR_FPRG);

    return ret;
}

/** @} */
/** @} */
