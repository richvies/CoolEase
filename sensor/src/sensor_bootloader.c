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

#define BACKUP_VERSION 100

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void deinit(void);

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
	boot_init();

	// If first power on
	if (boot_info->init_key != BOOT_INIT_KEY2)
	{
		BOOT_LOG("First App Check\n");

		serial_printf(".Boot: %8u\n", VERSION);

		mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_fail_runs, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, 0);

		// Set initialized
		mem_eeprom_write_word_ptr(&boot_info->init_key, BOOT_INIT_KEY2);
	}

	// Setup eeprom for first run of new app
	if (boot_info->app_init_key != BOOT_APP_INIT_KEY)
	{
		BOOT_LOG("Setup App\n");

		// Boot Info
		mem_eeprom_write_word_ptr(&boot_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_fail_runs, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_num_iwdg_reset, 0);

		mem_eeprom_write_word_ptr(&boot_info->app_version, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_update_version, 0);
		mem_eeprom_write_word_ptr(&boot_info->app_previous_version, 0);

		// Shared Info
		mem_eeprom_write_word_ptr(&shared_info->boot_version, VERSION);
		mem_eeprom_write_word_ptr(&shared_info->upg_pending, 0);
		mem_eeprom_write_word_ptr(&shared_info->upg_flags, boot_info->upg_flags);

		mem_eeprom_write_word_ptr(&shared_info->app_ok_key, 0);
		mem_eeprom_write_word_ptr(&shared_info->app_curr_version, 0);
		mem_eeprom_write_word_ptr(&shared_info->app_next_version, 0);

		// App Info
		mem_eeprom_write_word_ptr(&app_info->init_key, 0);
		mem_eeprom_write_word_ptr(&app_info->dev_id, boot_info->dev_id);
		mem_eeprom_write_word_ptr(&app_info->registered_key, 0);

		uint8_t *u8ptr = NULL;

		for (uint8_t i = 0; i < sizeof(app_info->aes_key); i++)
		{
			u8ptr = &app_info->aes_key[i];
			mem_eeprom_write_byte((uint32_t)u8ptr, boot_info->aes_key[i]);
		}

		for (uint8_t i = 0; i < sizeof(app_info->pwd); i++)
		{
			u8ptr = (uint8_t *)&app_info->pwd[i];
			mem_eeprom_write_byte((uint32_t)u8ptr, boot_info->pwd[i]);
		}

		mem_eeprom_write_word_ptr(&boot_info->app_init_key, BOOT_APP_INIT_KEY);
	}

	BOOT_LOG("Jump %8x\n\n----------\n\n", boot_info->vtor);

	// serial print finish
	timers_delay_milliseconds(500);

	// Deinit peripherals
	deinit();

	// Run Application
	timers_pet_dogs();
	boot_jump_to_application(boot_info->vtor);

	for (;;)
	{
		serial_printf("Sensor Bootloader Loop\n\n");
		__asm__("nop");
	}

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

	flash_led(40, 3);
}

static void deinit(void)
{
	log_end();
	timers_lptim_end();
	rcc_periph_clock_disable(RCC_GPIOA);
	rcc_periph_clock_disable(RCC_GPIOB);
	clock_setup_msi_2mhz();
}

/** @} */
/** @} */