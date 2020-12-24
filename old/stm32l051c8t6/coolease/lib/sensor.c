#include "coolease/battery.h"
#include "coolease/reset.h"
#include "coolease/serial_printf.h"
#include "coolease/testing.h"
#include "coolease/timers.h"

int main(void) 
{
	timers_lptim_init();
	// for(int i = 0; i < 1000000; i++){__asm__("nop");}
	spf_serial_printf("Sensor Start\n");
	
	// testing_wakeup();
	// testing_standby(60);
	// testing_rf();
	// testing_rf_listen();
	// testing_tmp112a(5);
	testing_sensor();
	// testing_receiver();
	// testing_voltage_scale(2);
	// testing_low_power_run();
	// testing_eeprom();
	// testing_lptim();
	// testing_si7051(5);
	// testing_sx126x();
	// testing_reset_eeprom();


	for (;;)
	{
		spf_serial_printf("Loop\n");
		timers_delay_milliseconds(5000);
	}
	return 0;

}