#include "coolease/battery.h"
#include "coolease/cc1101.h"
#include "coolease/reset.h"
#include "coolease/serial_printf.h"
#include "coolease/testing.h"
#include "coolease/timers.h"
#include "coolease/tmp112.h"

int main(void) 
{
	spf_serial_printf("Sensor Start\n");
	
	timers_lptim_init();

	// for(int i = 0; i < 1000000; i++){__asm__("nop");}
	
	testing_wakeup();
	testing_standby(600);
	// testing_rf();
	// testing_rf_listen();
	// testing_tmp112a(5);
	// testing_sensor();
	// testing_receiver();
	// testing_voltage_scale(2);
	// testing_low_power_run();
	// testing_eeprom();
	// testing_lptim();
	// testing_sdr();


	for (;;)
	{
		spf_serial_printf("Loop\n");
		// timers_delay_milliseconds(1000);
		for(int i = 0; i < 100; i++){timers_delay_microseconds(10000);}
		
		// for(int i = 0; i < 1100000; i++){__asm__("nop");}
	}
	return 0;

}