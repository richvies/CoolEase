/**
 ******************************************************************************
 * @file    sensor_bootloader.c
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Sensor Bootloader Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "sensor/sensor_bootloader.h"

#include "common/aes.h"
#include "common/battery.h"
#include "common/bootloader_utils.h"
#include "common/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/test.h"
#include "common/timers.h"

#include "sensor/tmp112.h"
#include "sensor/si7051.h"
#include "sensor/sensor_test.h"

/** @addtogroup SENSOR_BOOTLOADER_FILE 
 * @{
 */

/** @addtogroup SENSOR_BOOTLOADER_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void flash_led_failsafe(void);

/** @} */

/** @addtogroup SENSOR_BOOTLOADER_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	init();

	boot_jump_to_application(FLASH_APP_ADDRESS);

	log_printf("Bootloader Run\n");

    return 0;
}

/** @} */

/** @addtogroup SENSOR_BOOTLOADER_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void)
{
	clock_setup_msi_2mhz();
	timers_lptim_init();
    log_init();
	flash_led(40, 2);

    log_printf("Sensor Bootloader Init\n");
	(void)flash_led_failsafe;
}

static void flash_led_failsafe(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO14);
	for(;;)
	{
		for (uint32_t i = 0; i < 100000; i++) { __asm__("nop"); }
		gpio_set(GPIOA, GPIO14);
		for (uint32_t i = 0; i < 100000; i++) { __asm__("nop"); }
		gpio_clear(GPIOA, GPIO14);
	}
}

/** @} */
/** @} */