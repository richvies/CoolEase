#include "coolease/aes.h"
#include "coolease/battery.h"
#include "coolease/board_defs.h"
#include "coolease/memory.h"
#include "coolease/reset.h"
#include "coolease/rf_scan.h"
#include "coolease/rfm.h"
#include "coolease/serial_printf.h"
#include "coolease/si7051.h"
#include "coolease/sim.h"
#include "coolease/testing.h"
#include "coolease/timers.h"
#include "coolease/tmp112.h"

int main(void) 
{
	gpio_init();
	spf_init();
	mem_init();
	aes_init();
	batt_init();
	timers_lptim_init();
	timers_tim6_init();

	for(int i = 0; i < 100000; i++){__asm__("nop");};


	spf_serial_printf("Sensor Start\n");
	flash_led(100, 5);

	rfm_init();
	rfm_end();

	tmp112_init();
	tmp112_end();
	
	// testing_wakeup();
	// testing_standby(60);
	testing_rf();
	// testing_rf_listen();
	// testing_sensor(DEV_NUM_CHIP);
	// testing_sensor(0x12345678);
	// testing_receiver(3);
	// testing_receiver(DEV_NUM_PCB);
	// testing_voltage_scale(2);
	// testing_low_power_run();
	// testing_eeprom();
	// testing_eeprom_keys();
	// testing_eeprom_wipe();
	// testing_lptim();
	// testing_si7051(5);
	// testing_tmp112(5);
	// testing_rfm();
	// testing_reset_eeprom();
	// testing_encryption();
	// testing_timeout();
	// testing_log();


	for (;;)
	{
		// testing_sensor(DEV_NUM_CHIP);
		spf_serial_printf("Loop\n");
		timers_delay_milliseconds(1000);
	}
	return 0;

}

