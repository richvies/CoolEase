#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/timer.h>

#include "coolease/rf_scan.h"
#include "coolease/cc1101.h"
#include "coolease/serial_printf.h"
#include "coolease/timers.h"
#include "coolease/led.h"

static uint8_t channel_number = 0;
static uint8_t test_number = 0;
static bool receiver = false;

void exti2_isr(void)
{
	exti_reset_request(EXTI2);
	gpio_toggle(GPIOB, GPIO4);
	rfs_next();
}

void tim2_isr(void)
{
	timer_clear_flag(TIM2, TIM_SR_UIF);
	gpio_toggle(GPIOB, GPIO4);
	rfs_next();
}

void rfs_init(bool r, uint8_t power)
{
	timers_tim2_init();
	led_init();	
	cc1101_init();

	cc1101_set_tx_pa_table_index(power);

	spf_serial_printf("%c", 255);

	channel_number = 0;
	test_number = 0;
	receiver = r;

	if(receiver)
	{
		exti_reset_request(EXTI2);
    	exti_select_source(EXTI2, GPIOA);
		exti_set_trigger(EXTI2, EXTI_TRIGGER_FALLING);
		exti_enable_request(EXTI2);
    	
		nvic_enable_irq(NVIC_EXTI2_IRQ);
    	nvic_set_priority(NVIC_EXTI2_IRQ, 0);
	}
	else
	{
		timer_clear_flag(TIM2, TIM_SR_UIF);
		timer_enable_irq(TIM2, TIM_DIER_UIE);
		
		nvic_enable_irq(NVIC_TIM2_IRQ);
		nvic_set_priority(NVIC_EXTI2_IRQ, 0);
	}
	
}

void rfs_next(void)
{
	cc1101_packet_t packet;
	if(receiver)
	{
		// Get received packet and print info to serial
		if(cc1101_get_packet(&packet))
		{
			//spf_serial_printf("Received: %i Channel: %i Test: %i ", packet.length, packet.data[0], packet.data[1]);
			//spf_serial_printf("RSSI: %i LQI: %i\n", packet.rssi, packet.lqi);

			_putchar(packet.data[0]);
			_putchar(packet.rssi);
			_putchar(packet.lqi);
			_putchar(255);

			// Update next test channel
			cc1101_change_channel(packet.data[2]);
		}
	}

	else
	{
		// Change to current test channel
		cc1101_change_channel(channel_number);

		// Put current channel and test number into packet
		packet.data[0] = channel_number;
		packet.data[1] = test_number;

		// Update channel every x number of tests
		test_number++;
		if(test_number >= 4)
		{
			test_number = 0;
			channel_number ++;

			if(channel_number == 251)
				while(1){}
		}

		// Put next test channel and number into packet for receiver to update
		packet.data[2] = channel_number;
		packet.data[3] = test_number;
		
		// Set packet length
		packet.length = 4;

		cc1101_transmit_packet(packet);

		// Print test information to serial
		/*spf_serial_printf("Sending Channel: %i Test: %i ", packet.data[0], packet.data[1]);

		if(cc1101_transmit_packet(packet))
			spf_serial_printf("Success\n");
		else
			spf_serial_printf("Failed\n");*/
	}
}