// #include "common/rf_scan.h"

// #include <libopencm3/stm32/gpio.h>
// #include <libopencm3/stm32/exti.h>
// #include <libopencm3/cm3/nvic.h>
// #include <libopencm3/stm32/timer.h>

// #include "common/rfm.h"
// #include "common/log.h"
// #include "common/timers.h"

// static uint8_t channel_number = 0;
// static uint8_t test_number = 0;
// static bool receiver = false;

// /*void exti0_1_isr(void)
// {
// 	exti_reset_request(EXTI0);
// 	rfs_next();
// }*/

// void tim2_isr(void)
// {
// 	timer_clear_flag(TIM2, TIM_SR_UIF);
// 	rfs_next();
// }

// void rfs_init(bool r, uint8_t power)
// {
// 	rfm_init();

// 	rfm_set_tx_pa_table_index(power);

// 	log_printf("%c", 255);

// 	channel_number = 0;
// 	test_number = 0;
// 	receiver = r;

// 	if(receiver)
// 	{
// 		exti_reset_request(EXTI2);
//     	exti_select_source(EXTI2, GPIOA);
// 		exti_set_trigger(EXTI2, EXTI_TRIGGER_FALLING);
// 		exti_enable_request(EXTI2);
    	
// 		nvic_enable_irq(NVIC_EXTI2_3_IRQ);
//     	nvic_set_priority(NVIC_EXTI2_3_IRQ, IRQ_PRIORITY_RFM);
// 	}
// 	else
// 	{
// 		timer_clear_flag(TIM2, TIM_SR_UIF);
// 		timer_enable_irq(TIM2, TIM_DIER_UIE);
		
// 		nvic_enable_irq(NVIC_TIM2_IRQ);
// 		nvic_set_priority(NVIC_TIM2_IRQ, IRQ_PRIORITY_RFM);
// 	}
	
// }

// void rfs_next(void)
// {
// 	rfm_packet_t packet;
// 	if(receiver)
// 	{
// 		// Get received packet and print info to serial
// 		if(rfm_get_packet(&packet))
// 		{
// 			//log_printf("Received: %i Channel: %i Test: %i ", packet.length, packet.data.buffer[0], packet.data.buffer[1]);
// 			//log_printf("RSSI: %i LQI: %i\n", packet.rssi, packet.lqi);

// 			_putchar(packet.data.buffer[0]);
// 			_putchar(packet.rssi);
// 			_putchar(packet.lqi);
// 			_putchar(255);

// 			// Update next test channel
// 			rfm_change_channel(packet.data.buffer[2]);
// 		}
// 	}

// 	else
// 	{
// 		// Change to current test channel
// 		rfm_change_channel(channel_number);

// 		// Put current channel and test number into packet
// 		packet.data.buffer[0] = channel_number;
// 		packet.data.buffer[1] = test_number;

// 		// Update channel every x number of tests
// 		test_number++;
// 		if(test_number >= 4)
// 		{
// 			test_number = 0;
// 			channel_number ++;

// 			if(channel_number == 251)
// 				while(1){}
// 		}

// 		// Put next test channel and number into packet for receiver to update
// 		packet.data.buffer[2] = channel_number;
// 		packet.data.buffer[3] = test_number;
		
// 		// Set packet length
// 		packet.length = 4;

// 		rfm_transmit_packet(packet);

// 		// Print test information to serial
// 		/*log_printf("Sending Channel: %i Test: %i ", packet.data.buffer[0], packet.data.buffer[1]);

// 		if(rfm_transmit_packet(packet))
// 			log_printf("Success\n");
// 		else
// 			log_printf("Failed\n");*/
// 	}
// }
