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

#include "common/memory.h"
#include "common/log.h"

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

static bootloader_t *bootloader = ((bootloader_t *)(EEPROM_BOOTLOADER_BASE));

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */

/** @addtogroup BOOTLOADER_UTILS_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void boot_init(void)
{
    // Save reset flags and clear register
    mem_eeprom_write_word((uint32_t)&bootloader->reset_flags, RCC_CSR & RCC_CSR_RESET_FLAGS);
    RCC_CSR |= RCC_CSR_RMVF;

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

void boot_deinit(void)
{
    // Reset all peripherals
    RCC_AHBRSTR  = 0xFFFFFFFF; RCC_AHBRSTR  = 0x00000000;
    RCC_APB2RSTR = 0xFFFFFFFF; RCC_APB2RSTR = 0x00000000;
    RCC_APB1RSTR = 0xFFFFFFFF; RCC_APB1RSTR = 0x00000000;
    RCC_IOPRSTR  = 0xFFFFFFFF; RCC_IOPRSTR  = 0x00000000;
}

void boot_jump_to_application(uint32_t address)
{
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

    // Deinitialize all used peripherals
    boot_deinit();

    // Enable interruptsf
    __asm__ volatile("CPSIE I\n");

    start();

    while (1)
    {
    };
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
    rcc_periph_clock_enable(RCC_CRC);

    serial_printf("Checksum value: %8x\n", crc);

    // Check against expected
    return (crc == expected ? true : false);
}



/** @} */

/** @addtogroup BOOTLOADER_UTILS_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */
/** @} */