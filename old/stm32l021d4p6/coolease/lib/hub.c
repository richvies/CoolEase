#include "coolease/battery.h"
#include "coolease/reset.h"
#include "coolease/serial_printf.h"
#include "coolease/timers.h"
#include "coolease/rf_scan.h"
#include "coolease/cc1101.h"
#include "coolease/sim800.h"
#include "coolease/testing.h"


int main(void)
{
	spf_serial_printf("Hub Start\n");

	timers_lptim_init();
	
	// testing_rf_listen();
	// testing_hub();
	// testing_receiver();
	testing_sim800();

	for (;;)
	{
		// spf_serial_printf("Loop\n");
		for(int i = 0; i < 1000000; i++){__asm__("nop");}
	}
	return 0;
}
