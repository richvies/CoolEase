	#include <libopencm3/stm32/rcc.h>
	#include <libopencm3/stm32/flash.h>
	#include <libopencm3/stm32/gpio.h>
	#include <libopencm3/stm32/flash.h>
	#include <libopencm3/stm32/timer.h>
	#include <libopencm3/stm32/lptimer.h>

	#include "coolease/board_defs.h"
	#include "coolease/battery.h"
	#include "coolease/encryption.h"
	#include "coolease/reset.h"
	#include "coolease/rf_scan.h"
	#include "coolease/serial_printf.h"
	#include "coolease/si7051.h"
	#include "coolease/sim800.h"
	#include "coolease/testing.h"
	#include "coolease/timers.h"
	#include "coolease/sx126x.h"

void testing_wakeup(void)
{
	for (int i = 0; i < 500000; i++) __asm__("nop");
	spf_serial_printf("\nReset\n");
	reset_print_cause();
	spf_serial_printf("Battery voltage greater than 2.%i V\n", batt_get_voltage());
}

void testing_standby(uint32_t standby_time)
{
	spf_serial_printf("Testing Standby for %i seconds\n", standby_time);

	timers_delay_milliseconds(5000);

	timers_rtc_init(standby_time);

	// cc1101_init();
	// cc1101_end();

	// tmp112_init();
	// tmp112_end();

	// #ifdef _HUB
	// sim800_init();
	// sim800_reset_hold();
	// #endif

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);
	
	timers_enter_standby();
}


void testing_rf(void)
{
    // cc1101_init();

	// #ifdef _HUB
	// sim800_init();
	// sim800_reset_hold();
	// rf_switch_close();
	// #endif

	// uint8_t val = 0x40;

    // cc1101_packet_t packet_send;
    // packet_send.length = 10;
    // cc1101_packet_t packet_received;

    // for (;;)
	// {
	// 	for(int i = 0; i < 10; i++) packet_send.data[i] = val;
	// 	val++;

	// 	if(cc1101_transmit_packet(packet_send))
	// 		spf_serial_printf("Packet Sent %02x\n", packet_send.data[0]);


	// 	for(int i = 0; i < 100000; i++) __asm__("nop");

	// 	if(cc1101_get_packet(&packet_received))
	// 		spf_serial_printf("Received Packet %02x\n", packet_received.data[0]);

	// 	for(int i = 0; i < 100000; i++) __asm__("nop");

	// 	spf_serial_printf("Loop\n");

	// 	for (int i = 0; i < 300000; i++) __asm__("nop");
	// }
}

void testing_rf_listen(void)
{
	sx126x_init();

	#ifdef _HUB
	// Todo
	#endif
	
	sx126x_start_listening();

    sx126x_packet_t packet_received;

    for (;;)
	{
		if(sx126x_get_packet(&packet_received))
		{
			spf_serial_printf("Packet Received\n");

			for(int i = 0; i < SX126X_PACKET_LENGTH; i++)
				spf_serial_printf("%02x, ", packet_received.data[i]);

			spf_serial_printf("\n");
		}

		for (int i = 0; i < 300000; i++) __asm__("nop");
	}
}

void testing_sensor(void)
{
	// Set wakeup every 1 minute
	timers_rtc_init(2);

	if(MMIO32(0x08080000) == 0)
	{
		flash_unlock();
		MMIO32(0x08080000) = 12;
		MMIO32(0x08080004) = 6;
		MMIO32(0x08080008) = 2;
		MMIO32(0x0808000C) = 0;
	}

	uint32_t dev_number = 0x10295be6;
	uint32_t message_number = MMIO32(0x0808000C);

	uint32_t power_index = 0;

	// Read temperature
	uint8_t num_readings = 4;
	int16_t readings[4] = {2345, 2345, 2345, 2345};

	// si7051_init();
	// si7051_read_temperature(readings, num_readings);
	// si7051_end();

	int32_t sum = 0;
	for(int i = 0; i < num_readings; i++)
		sum += readings[i];
	int16_t temp_avg = sum/num_readings;

	// Create and send packet
	sx126x_packet_t packet;
	uint8_t i = 0;

	packet.data[i++] = temp_avg >> 8;
	packet.data[i++] = temp_avg;

	packet.data[SX126X_PACKET_DEV_NUM_3] = dev_number >> 24;
	packet.data[SX126X_PACKET_DEV_NUM_2] = dev_number >> 16;
	packet.data[SX126X_PACKET_DEV_NUM_1] = dev_number >> 8;
	packet.data[SX126X_PACKET_DEV_NUM_0] = dev_number;

	packet.data[SX126X_PACKET_POWER] = power_index;

	// Have to take measurement multiple times for some reason
	uint8_t batt = batt_get_voltage();
	batt = batt_get_voltage();
	packet.data[SX126X_PACKET_BATTERY] = batt;

	packet.data[SX126X_PACKET_MSG_NUM_3] = message_number >> 24;
	packet.data[SX126X_PACKET_MSG_NUM_2] = message_number >> 16;
	packet.data[SX126X_PACKET_MSG_NUM_1] = message_number >> 8;
	packet.data[SX126X_PACKET_MSG_NUM_0] = message_number;

	packet.data[SX126X_PACKET_TEMP_1] = temp_avg >> 8;
	packet.data[SX126X_PACKET_TEMP_0] = temp_avg;

	sx126x_init();
	sx126x_config_for_lora();
	// sx126x_config_for_gfsk();
	sx126x_transmit_packet(packet);
	sx126x_end();

	// Update message_number
	flash_unlock();
	MMIO32(0x0808000C)++;
	MMIO32(0x08080010) = power_index;

	spf_serial_printf("Packet Sent\n");

	// Go back to sleep
	timers_enter_standby();
}

void testing_receiver(void)
{
	// #ifdef _HUB
	// // Todo
	// #endif

	// spf_serial_printf("Testing Receiver\n");

	// uint16_t total_packets = 0;
	// uint16_t ok_packets = 0;

	// // Start listening on sx126x
	// sx126x_packet_t received_packet;
	// uint8_t stats[6] = {0, 0, 0, 0, 0, 0};
	// uint16_t message_num = 0;
	// sx126x_init();
	// sx126x_config_for_lora();
	// // sx126x_config_for_gfsk();
	// sx126x_start_listening();

	// spf_serial_printf("Ready\n");

	// for(;;)
	// {
	// 	if(sx126x_get_packet(&received_packet))
	// 	{
	// 		spf_serial_printf("Message Received. Length: %i. \n", SX126X_PACKET_LENGTH);

	// 		spf_serial_printf("Packet RSSI 1: %i dbm\n", (-received_packet.packet_status[0]/2));
	// 		spf_serial_printf("Packet SNR 2: %i\n", (received_packet.packet_status[1]/4));
	// 		spf_serial_printf("Packet RSSI 2 3: %i\n", (-received_packet.packet_status[2]/2));

	// 		if(received_packet.crc_ok)spf_serial_printf("CRC OK\n");
	// 		else spf_serial_printf("CRC Fail\n");

	// 		// spf_serial_printf("Customer ID: %i\n", received_packet.data[0]);
	// 		// spf_serial_printf("Device ID: %i\n", received_packet.data[1]);
			
	// 		// spf_serial_printf("Power: %i\n", received_packet.data[2]);
	// 		// spf_serial_printf("Battery: 2.%iV\n", received_packet.data[3]);

	// 		uint16_t message_number = received_packet.data[4] << 8 | received_packet.data[5];
	// 		spf_serial_printf("Message Number: %i\n", message_number);

	// 		if(message_num != message_number)
	// 		{
	// 			spf_serial_printf("Missed Message %i\n", message_num+1);
	// 			message_num = message_number;
	// 			total_packets++;
	// 		}

	// 		int16_t temp = received_packet.data[6] << 8 | received_packet.data[7];
	// 		// spf_serial_printf("Temperature: %i\n", temp);

	// 		total_packets++;
	// 		message_num++;

	// 		if(received_packet.data[0] == 111 && received_packet.data[1] == 222 && received_packet.data[2] == 0 && temp == 2345 && received_packet.crc_ok)
	// 		{
	// 			ok_packets++;
	// 		}

	// 		spf_serial_printf("Accuracy: %i / %i packets\n\n", ok_packets, total_packets);
	// 	}
	// }	
}

void testing_hub(void)
{
	// // Put sim800 in reset
	// sim800_init();
	// sim800_reset_hold();

	// // Start listening on cc1101
	// cc1101_init();
	// cc1101_start_listening();
	// cc1101_packet_t packet;

	// spf_serial_printf("Ready\n");

	// for(;;)
	// {
	// 	if(cc1101_get_packet(&packet))
	// 	{
	// 		spf_serial_printf("Message Received. Length: %i\n", packet.length);
	// 		spf_serial_printf("Customer ID: %i\n", packet.data[0]);
	// 		spf_serial_printf("Device ID: %i\n", packet.data[1]);
	// 		spf_serial_printf("Message Number: %i\n", packet.data[2]);
	// 		int16_t temp = packet.data[3] << 8 | packet.data[4];
	// 		spf_serial_printf("Temperature: %i\n\n", temp);
	// 	}

	// 	for(int i = 0; i < 1000000; i++){__asm__("nop");}
	// }
}

void testing_voltage_scale(uint8_t scale)
{
	// cc1101_init();
	// cc1101_end();

	// tmp112_init();
	// tmp112_end();

	// #ifdef _HUB
	// sim800_init();
	// sim800_reset_hold();
	// #endif

	// spf_serial_printf("Testing Voltage Scaling\n");
	// spf_serial_printf("Current Scaling: %08x\n", PWR_CR);

	// batt_set_voltage_scale(scale);

	// spf_serial_printf("New Scaling: %08x\n", PWR_CR);

	// for (;;)
	// {
	// 	for(int i = 0; i < 1000000; i++){__asm__("nop");}
	// }
}

void testing_low_power_run(void)
{
	// cc1101_init();
	// cc1101_end();

	// tmp112_init();
	// tmp112_end();

	// #ifdef _HUB
	// sim800_init();
	// sim800_reset_hold();
	// #endif

	// spf_serial_printf("Testing Low Power Run\n");

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);

	// batt_set_low_power_run();

	// for (;;)
	// {
	// }
}

void testing_eeprom(void)
{

	for(;;)
	{

		for(int i = 0; i < 1000000; i++){__asm__("nop");}
	}
}

void testing_lptim(void)
{
	timers_lptim_init();

	for(;;)
	{
		spf_serial_printf("LPTim Count: %i\n", lptimer_get_counter(LPTIM1));
		for(int i = 0; i < 1000; i++){__asm__("nop");}
	}
}

void testing_si7051(uint8_t num_readings)
{
	int16_t readings[num_readings];

    for (;;)
	{
		si7051_init();
		si7051_read_temperature(readings, num_readings);
		si7051_end();

		for(int i = 0; i < num_readings; i++)
			spf_serial_printf("Temp %i: %i Deg C\n", i+1, readings[i]);
			
		timers_delay_milliseconds(1000);
	}
}

void testing_sx126x(void)
{
	sx126x_init();
	sx126x_config_for_lora();
	sx126x_set_tx_continuous();
}

void testing_reset_eeprom(void)
{
	flash_unlock();
	MMIO32(0x08080000) = 12;
	MMIO32(0x08080004) = 6;
	MMIO32(0x08080008) = 2;
	MMIO32(0x0808000C) = 0;	
}