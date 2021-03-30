/**
 ******************************************************************************
 * @file    bootloader_utils.c
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Bootloader_utils Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>

#include "common/bootloader_utils.h"

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/crc.h>
#include <libopencm3/stm32/gpio.h>

#include "common/memory.h"
#include "common/log.h"
#include "common/reset.h"
#include "common/timers.h"

/** @addtogroup BOOTLOADER_UTILS_FILE 
 * @{
 */

/** @addtogroup BOOTLOADER_UTILS_INT 
 * @{
 */

/**
 * Mask for RCC_CSR defining which bits may trigger an entry into boot_info mode:
 * - Any watchdog reset
 * - Any soft reset
 * - A pin reset (aka manual reset)
 * - A firewall reset
 */
#define BOOTLOADER_RCC_CSR_ENTRY_MASK (RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PINRSTF | RCC_CSR_FWRSTF)

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static bool verify_half_page_checksum(uint32_t data[16], uint32_t expected);

/** @} */

/** @addtogroup BOOTLOADER_UTILS_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void boot_init(void)
{
    uint32_t *mem_eeprom_write_word_ptrNULL;
    uint8_t *u8ptr = NULL;
    uint32_t val = 0;

    log_printf("**********\nStart\n**********\n");

    // If first power on, setup some data
    if ((boot_info->init_key != BOOT_INIT_KEY) && (boot_info->init_key != BOOT_INIT_KEY2))
    {
        BOOT_LOG("First Run\n");

        // Reset RTC (+Backup Registers)
        timers_rtc_unlock();
        RCC_CSR |= RCC_CSR_RTCRST;
        RCC_CSR &= ~RCC_CSR_RTCRST;
        timers_rtc_lock();

        // Boot info
        mem_eeprom_write_word_ptr(&boot_info->app_init_key, 0);

        mem_eeprom_write_word_ptr(&boot_info->upg_in_progress, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_version_to_download, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_num_recovery_attempts, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_new_app_installed, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_done, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_state, 0);
        mem_eeprom_write_word_ptr(&boot_info->upg_flags, 0);

        // Set initialized
        mem_eeprom_write_word_ptr(&boot_info->init_key, BOOT_INIT_KEY);
    }

    serial_printf(".Dev ID: %u\n", boot_info->dev_id);
    serial_printf(".VTOR: %8x\n", boot_info->vtor);
    serial_printf(".PWD: %s\n", boot_info->pwd);
    serial_printf(".AES: ");
    for (uint8_t i = 0; i < 16; i++)
    {
        serial_printf("%2x ", boot_info->aes_key[i]);
    }
    serial_printf("\n");

    // This should only ever be called once after a reset
    timers_rtc_init();
    reset_save_flags();
    // reset_print_cause();

    // If watchdogs keep causing reset then there is problem 
    val = mem_read_bkp_reg(BKUP_NUM_IWDG_RESET);
    if (reset_get_flags() & RCC_CSR_IWDGRSTF)
    {
        BOOT_LOG("->Watchdog Reset!\n");
        
        mem_program_bkp_reg(BKUP_NUM_IWDG_RESET, val + 1);

        // Caused by app, not bootloader
        if (mem_read_bkp_reg(BKUP_BOOT_OK) == BOOT_OK_KEY)
        {
            log_printf(".App\n");
            mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, boot_info->app_num_iwdg_reset + 1);
        }
        // Caused by bootloader, much much worse
        else
        {
            log_printf(".Boot\n");
        }
    }
    // Otherwise reset count to 0
    else
    {
        mem_program_bkp_reg(BKUP_NUM_IWDG_RESET, 0);

        if (boot_info->app_num_iwdg_reset)
        {
            mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, 0);
        }
    } 

    BOOT_LOG("IWDG %i\n", mem_read_bkp_reg(BKUP_NUM_IWDG_RESET));

    // Start watchdog
    timers_iwdg_init(10000);

    // Magic value must be set every time bootloader runs succesfully, before calling main app
    mem_program_bkp_reg(BKUP_BOOT_OK, 0);
}

void boot_jump_to_application(uint32_t address)
{
    mem_program_bkp_reg(BKUP_BOOT_OK, BOOT_OK_KEY);
    
    // Update vector table offset
    SCB_VTOR = address;

    // Update main stack pointer
    __asm__("msr msp, %0"
            :
            : "r"(MMIO32(address)));

    // Get start address of program
    void (*start)(void) = (void *)MMIO32(address + 4);

    start();

    while (1)
    {
        // Should not get here
        __asm__ volatile("nop");
    };
}

void boot_fallback(void)
{
    // Try to redownload new firmware
    // If still not working fallback to safe version for the time being
    log_printf("Bootloader Fallback\n");
}


bool boot_program_half_page(bool lower, uint32_t crc_expected, uint32_t page_num, uint32_t data[16])
{
    bool success = false;

    // Check crc32
    if (!verify_half_page_checksum(data, crc_expected))
    {
        log_error(ERR_USB_PAGE_CHECKSUM_BAD);
    }
    // Program half page
    else if (!mem_flash_write_half_page(FLASH_APP_ADDRESS + (page_num * FLASH_PAGE_SIZE) + (lower ? 0 : (FLASH_PAGE_SIZE / 2)), data))
    {
        if (lower)
        {
            log_error(ERR_USB_PROGRAM_LOWER_HALF_PAGE_FAIL);
        }
        else
        {
            log_error(ERR_USB_PROGRAM_UPPER_HALF_PAGE_FAIL);
        }
    }
    // Everything went well
    else
    {
        success = true;
    }

    return success;
}

bool boot_program_application(uint32_t *data, uint32_t start_address, uint32_t len, uint32_t crc)
{
    log_printf("boot_program_application");

    bool res = true;

    /** Check for Errors 
     * Start address &
     * Size of new program
     * CRC checksum
    */
    if (start_address < FLASH_APP_ADDRESS || start_address > FLASH_END)
    {
        log_error(ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS);
        res = false;
    }
    else if (len > FLASH_APP_ADDRESS - FLASH_APP_END)
    {
        log_error(ERR_BOOT_PROG_TOO_BIG);
        res = false;
    }
    else if (!boot_verify_checksum(data, len, crc))
    {
        log_error(ERR_BOOT_PROG_BAD_CHECKSUM);
        res = false;
    }
    

    /** Program flash if looks good */
    else
    {
        // Num pages to program
        uint16_t num_pages = ((len / FLASH_PAGE_SIZE) + 1);
        log_printf("Prog %i pgs\n", num_pages);

        for (uint32_t address = start_address; address < start_address + len; address += FLASH_PAGE_SIZE)
        {
            // Erase page first
            if (!mem_flash_erase_page(address))
            {
                log_error(ERR_BOOT_PROG_FLASH_ERASE);
                res = false;
            }
            // Flash first half page
            else if (!mem_flash_write_half_page(address, &data[0]))
            {
                log_error(ERR_BOOT_PROG_FLASH_WRITE_1);
                res = false;
            }
            // Flash second half page
            else if (!mem_flash_write_half_page(address, &data[16]))
            {
                log_error(ERR_BOOT_PROG_FLASH_WRITE_2);
                res = false;
            }

            // Stop programming if flash error
            if (res == false)
            {
                break;
            }
        }
    }

    return res;
}

bool boot_verify_checksum(uint32_t *data, uint32_t len, uint32_t expected)
{
    log_printf("boot_verify_checksum\n");  

    // Initialize CRC Peripheral
    rcc_periph_clock_enable(RCC_CRC);
    crc_reset();
    crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
    crc_reverse_output_enable();

    // Calc CRC32
    uint32_t crc = ~crc_calculate_block(data, len);

    // Deinit
    crc_reset();
    rcc_periph_clock_disable(RCC_CRC);

    serial_printf("Checksum value: %8x\n", crc);

    // Check against expected
    return (crc == expected ? true : false);
}

uint32_t boot_get_half_page_checksum(uint32_t data[16])
{
    // Initialize CRC Peripheral
    rcc_periph_clock_enable(RCC_CRC);
    crc_reset();
    crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
    crc_reverse_output_enable();
    CRC_INIT = 0xFFFFFFFF;

    // Calc CRC32
    uint32_t crc = ~crc_calculate_block(data, 16);

    // Deinit
    crc_reset();
    rcc_periph_clock_disable(RCC_CRC);

    return crc;
}

/** @} */

/** @addtogroup BOOTLOADER_UTILS_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static bool verify_half_page_checksum(uint32_t data[FLASH_PAGE_SIZE / 2], uint32_t expected)
{
    // log_printf("boot_verify_checksum\n");

    // for(uint16_t i = 0; i < 16; i++)
    // {
    //     serial_printf("%8x ", hid_out_report.buf[i]);
    // }
    // serial_printf("\n%8x", expected);

    // Initialize CRC Peripheral
    rcc_periph_clock_enable(RCC_CRC);
    crc_reset();
    crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
    crc_reverse_output_enable();
    CRC_INIT = 0xFFFFFFFF;
    
    // serial_printf("\n%8x\n", CRC_INIT);

    // Calc CRC32
    uint32_t crc = ~crc_calculate_block(data, 16);

    // Deinit
    crc_reset();
    rcc_periph_clock_disable(RCC_CRC);

    // serial_printf("Checksum value: %8x\n", crc);

    // Check against expected
    return (crc == expected ? true : false);
}

/** @} */
/** @} */