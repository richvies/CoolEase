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

#include "common/bootloader_utils.h"

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/rcc.h>

#include "common/memory.h"
#include "common/log.h"

/** @addtogroup BOOTLOADER_UTILS_FILE 
 * @{
 */

/** @addtogroup BOOTLOADER_UTILS_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

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
    // Reset all peripherals
    RCC_AHBRSTR = 0xFFFFFFFF;
    RCC_AHBRSTR = 0x00000000;
    RCC_APB2RSTR = 0xFFFFFFFF;
    RCC_APB2RSTR = 0x00000000;
    RCC_APB1RSTR = 0xFFFFFFFF;
    RCC_APB1RSTR = 0x00000000;
    RCC_IOPRSTR = 0xFFFFFFFF;
    RCC_IOPRSTR = 0x00000000;
}

void boot_deinit(void)
{
    // Reset all peripherals
    RCC_AHBRSTR = 0xFFFFFFFF;
    RCC_AHBRSTR = 0x00000000;
    RCC_APB2RSTR = 0xFFFFFFFF;
    RCC_APB2RSTR = 0x00000000;
    RCC_APB1RSTR = 0xFFFFFFFF;
    RCC_APB1RSTR = 0x00000000;
    RCC_IOPRSTR = 0xFFFFFFFF;
    RCC_IOPRSTR = 0x00000000;
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

bool boot_program_application(uint32_t *data, uint32_t start_address, uint32_t len)
{
    log_printf(BOOT, "Program Application");

    // Return if new program is too large
    if(len > (FLASH_START_APP - FLASH_START))
    {
        log_printf(BOOT, "App size too big");
        return false;
    }

    // C truncates integer division so the number of pages is 1 more than result
    uint16_t num_pages = ((len / FLASH_PAGE_SIZE) + 1);

    for (uint32_t address = start_address; address < start_address + len; address += FLASH_PAGE_SIZE)
    {   
        // Erase page first
        mem_flash_erase_page(address);

        // Flash first half page
        mem_flash_write_half_page(address, &data[0]);

        // Flash second half page
        mem_flash_write_half_page(address, &data[16]);
    }

    return true;
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