/**
 ******************************************************************************
 * @file    sensor.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Sensor Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/memory.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/test.h"
#include "common/timers.h"

#include "sensor/tmp112.h"
#include "sensor/si7051.h"
#include "sensor/sensor_test.h"

/** @addtogroup SENSOR_FILE 
 * @{
 */

#define APP_ADDRESS 0x08004000

/** @addtogroup SENSOR_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static sensor_t *dev = ((sensor_t *)(EEPROM_DEV_INFO_BASE));

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void flash_led_failsafe(void);

/** @} */

/** @addtogroup SENSOR_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	init();

	serial_printf("Dev Info Location: %8x %8x %8x\n", EEPROM_DEV_INFO_BASE, &dev->aes_key[0], dev->aes_key);
	
	// test_encryption(dev->aes_key);

	// test_eeprom_read();
	// test_log();
	
	// rfm_init();
	// rfm_end();

	// tmp112_init();
	// tmp112_end();

	// test_tmp112(10);
	
	// test_wakeup();
	// test_standby(60);
	// test_rf();
	// test_rf_listen();
	// test_sensor(DEV_NUM_CHIP);
	// test_sensor(0x12345678);
	// test_receiver(3);
	// test_receiver(DEV_NUM_PCB);
	// test_voltage_scale(2);
	// test_low_power_run();
	// test_eeprom();
	// test_eeprom_keys();
	// test_eeprom_wipe();
	// test_lptim();
	// test_si7051(5);
	// test_tmp112(5);
	// test_rfm();
	// test_reset_eeprom();
	// test_encryption();
	// test_timeout();
	// test_log();


	for (;;)
	{
		// test_sensor(DEV_NUM_CHIP);
		serial_printf("Loop\n");
		timers_delay_milliseconds(1000);
	}

	return 0;
}

/** @} */

/** @addtogroup SENSOR_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void)
{
	clock_setup_msi_2mhz();
	timers_lptim_init();
	timers_tim6_init();
    log_init();
	aes_init(dev->aes_key);
	
	flash_led(100, 5);
    log_printf("Sensor Start\n");
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
