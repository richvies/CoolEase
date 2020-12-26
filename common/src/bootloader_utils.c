/**
 ******************************************************************************
 * @file    bootloader_utils.c
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Bootloader_utils Source File
 *  
 ******************************************************************************
 */

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include "common/bootloader_utils.h"

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/common.h>

/** @addtogroup BOOTLOADER_UTILS_FILE 
 * @{
 */

/** @addtogroup BOOTLOADER_UTILS_INT 
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Static Variables
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Static Function Declarations
////////////////////////////////////////////////////////////////////////////////

/** @} */

/** @addtogroup BOOTLOADER_UTILS_API
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Exported Function Definitions
////////////////////////////////////////////////////////////////////////////////
void boot_deinit(void)
{

}

void boot_jump_to_application(uint32_t address)
{
  // Disable Interrupts
  __asm__ volatile ("CPSID I\n");

  // Update vector table offset
  SCB_VTOR = address;

  // Update main stack pointer
  __asm__("msr msp, %0" : : "r" (MMIO32(address)));

  // Get start address of program
  void (*start)(void) = (void*)MMIO32(address + 4);

  // Enable interrupts
  __asm__ volatile ("CPSIE I\n");

  start();

  while(1){ };
}

/** @} */

/** @addtogroup BOOTLOADER_UTILS_INT
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Static Function Definitions
////////////////////////////////////////////////////////////////////////////////

/** @} */
/** @} */