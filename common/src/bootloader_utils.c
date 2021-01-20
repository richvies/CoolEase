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
 * Mask for RCC_CSR defining which bits may trigger an entry into bootloader mode:
 * - Any watchdog reset
 * - Any soft reset
 * - A pin reset (aka manual reset)
 * - A firewall reset
 */
#define BOOTLOADER_RCC_CSR_ENTRY_MASK (RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PINRSTF | RCC_CSR_FWRSTF)

/**
 * Magic code value to make the bootloader ignore any of the entry bits set in
 * RCC_CSR and skip to the user program anyway, if a valid program start value
 * has been programmed.
 */
#define BOOTLOADER_MAGIC_SKIP 0x3C65A95A


/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

typedef enum
{
    RESET = 0,
    CONNECTED,
    GET_LOG
} bootloader_state_t;

typedef struct
{
    uint32_t vtor;
    uint32_t magic_code;
    uint32_t reset_flags;
    bootloader_state_t state;
    uint8_t  num_reset;
}bootloader_t;

static bootloader_t *bootloader = ((bootloader_t *)(EEPROM_BOOTLOADER_INFO_BASE));

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
    log_printf("Boot Init\n");
    reset_print_cause();

    // Save reset flags and clear register
    mem_eeprom_write_word((uint32_t)&bootloader->reset_flags, RCC_CSR & RCC_CSR_RESET_FLAGS);
    RCC_CSR |= RCC_CSR_RMVF;

    serial_printf("VTOR: %8x Flags: %8x Code: %8x Num Reset: %i State: %i\n", bootloader->vtor, bootloader->reset_flags, bootloader->magic_code, bootloader->num_reset, bootloader->state);

    // If watchdogs keep causing reset then there is problem with app code
    // Todo, use RTC backup registers instead
    if(bootloader->reset_flags & (RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF))
    {
        if(bootloader->num_reset >= 3)
        {
            // panic!!
            boot_fallback();
        }
        else
        {
            mem_eeprom_write_byte((uint32_t)&bootloader->num_reset, bootloader->num_reset + 1);
        }
    }
    // Otherwise reset count to 0 if not already
    else if(bootloader->num_reset)
    {
        mem_eeprom_write_byte((uint32_t)&bootloader->num_reset, 0);
    }    

    // If the program address is set and there are no entry bits set in the CSR (or the magic code is programmed appropriate), start the user program
    if (bootloader->vtor &&
            (!(bootloader->reset_flags & BOOTLOADER_RCC_CSR_ENTRY_MASK) || bootloader->magic_code == BOOTLOADER_MAGIC_SKIP))
    {
        if (bootloader->magic_code)
        {
            mem_eeprom_write_word((uint32_t)&bootloader->magic_code, 0);
        }
        boot_jump_to_application(bootloader->vtor);
    }
}

// This works perfectly before jumping to application
void boot_deinit(void)
{
    // Reset all peripherals
    RCC_AHBRSTR  = 0xFFFFFEFF; RCC_AHBRSTR  = 0x00000000;
    RCC_APB2RSTR = 0xFFFFFFFF; RCC_APB2RSTR = 0x00000000;
    RCC_APB1RSTR = 0xFFFFFFFF; RCC_APB1RSTR = 0x00000000;
    RCC_IOPRSTR  = 0xFFFFFFFF; RCC_IOPRSTR  = 0x00000000;

    // Reenable STLink
}

void boot_jump_to_application(uint32_t address)
{
    log_printf("Boot Jump to %8x\n", address);

    // Disable Interrupts
    __asm__ volatile("CPSID I\n");

    // Update vector table offset
    SCB_VTOR = address;

    // Update main stack pointer
    __asm__("msr msp, %0"
            :
            : "r"(MMIO32(address)));

    // Get start address of program
    void (*start)(void) = (void *)MMIO32(address + 4);

    // Deinitialize peripherals
    boot_deinit();

    // Start Watchdog
    // timers_iwdg_init(5000);

    // Enable interrupts
    __asm__ volatile("CPSIE I\n");

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
    if (start_address < FLASH_APP_START || start_address > FLASH_END)
    {
        log_error(ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS);
        res = false;
    }
    else if (len > FLASH_APP_START - FLASH_APP_END)
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