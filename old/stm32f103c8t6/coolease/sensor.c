#include <string.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/iwdg.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/f1/bkp.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/cortex.h>

#include "coolease/battery.h"
#include "coolease/cc1101.h"
#include "coolease/encryption.h"
#include "coolease/led.h"
#include "coolease/reset.h"
#include "coolease/rf_scan.h"
#include "coolease/serial_printf.h"
#include "coolease/si4432.h"
#include "coolease/si7051.h"
#include "coolease/sim800.h"
#include "coolease/stm_temp.h"
#include "coolease/tmp112.h"
#include "coolease/timers.h"

int main(void) 
{
	for (int i = 0; i < 1000; i++) __asm__("nop");

	spf_serial_printf("\nReset\n");
	// reset_print_cause();
	// timers_standby_check();
	// timers_iwdg_init();
	// timers_rtc_init();

	// timers_prepare_and_enter_standby(30);

	// spf_serial_printf("Battery voltage greater than 2.%i V\n", batt_get_voltage());

	// timers_tim2_init();
	// led_init();	

	// cc1101_init();


	// rfs_init(TRANSMITTER, 0);

	// crypt_init();
	// uint8_t message[5] = {1,2,101,0,0};
	// uint8_t message_num = 1;

	// gpio_set(GPIOB, GPIO4);

	// spf_serial_printf("Preparing Standby\n");

	// sim800_serial_pass_through();

	// si4432_packet_t packet;
	// si4432_init();


	for (;;)
	{
		// message[3] = message_num; message[4] = 6;
		// spf_serial_printf("\n\nMessage %i: ", message_num); for(int i = 0; i < 5; i++) spf_serial_printf("%i, ", message[i]);

		// crypt_encrypt_message(message, packet.data);
		// spf_serial_printf("\nEncrypted: "); for(int i = 0; i < 16; i++) spf_serial_printf("%i, ", packet.data[i]);

		// crypt_decrypt_message(packet.data, message);
		// spf_serial_printf("\nDecrypted Message %i: ", message_num); for(int i = 0; i < 5; i++) spf_serial_printf("%i, ", message[i]);

		// message_num++;

		// crypt_update_random_seed();

		// float readings[1] = {1};
		// stm_temp_read(readings, 1);
		
		spf_serial_printf("LOOP\n");
		for (int i = 0; i < 3000000; i++) __asm__("nop");
	}
	return 0;
}
