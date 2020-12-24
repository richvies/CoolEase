	#include "coolease/testing.h"

	#include <string.h>
	#include <stdbool.h>

	#include <libopencm3/stm32/rcc.h>
	#include <libopencm3/stm32/flash.h>
	#include <libopencm3/stm32/gpio.h>
	#include <libopencm3/stm32/flash.h>
	#include <libopencm3/stm32/timer.h>
	#include <libopencm3/stm32/lptimer.h>
	#include <libopencm3/stm32/pwr.h>

	#include "coolease/aes.h"
	#include "coolease/battery.h"
	#include "coolease/board_defs.h"
	#include "coolease/memory.h"
	#include "coolease/reset.h"
	#include "coolease/rfm.h"
	#include "coolease/serial_printf.h"
	#include "coolease/si7051.h"
	#include "coolease/sim.h"
	#include "coolease/timers.h"
	#include "coolease/tmp112.h"

void flash_led(uint16_t milliseconds, uint8_t num_flashes)
{
	gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED);
	gpio_clear(LED_PORT, LED);
	for(uint8_t i = 0; i < num_flashes; i++)
	{
		gpio_set(LED_PORT, LED);
		timers_delay_milliseconds(milliseconds / 4);
		gpio_clear(LED_PORT, LED);
		timers_delay_milliseconds(3 * milliseconds / 4);
	}
}

void testing_wakeup(void)
{
	spf_serial_printf("Reset\n");
	reset_print_cause();
	
	batt_init();
	batt_update_voltages();

	spf_serial_printf("Battery = %uV\n", batt_voltages[BATT_VOLTAGE]);
	#ifdef _HUB
	spf_serial_printf("Power = %uV\n", batt_voltages[PWR_VOLTAGE]);
	#endif
}

void testing_standby(uint32_t standby_time)
{
	spf_serial_printf("Testing Standby for %i seconds\n", standby_time);

	timers_rtc_init(standby_time);

	// rfm_init();
	// rfm_end();

	// tmp112_init();
	// tmp112_end();

	// #ifdef _HUB
	// sim_init();
	// sim_reset_hold();
	// #endif

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);
	
	spf_serial_printf("Entering Standby\n");
	timers_enter_standby();
}

void testing_rf(void)
{
	spf_serial_printf("Testing RF\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);

    rfm_packet_t *packet_received;
    rfm_packet_t packet_send;

	char msg[16] = {'H', 'E', 'L', 'L', '0', '\n', 0};

	packet_send.data.buffer[0] = msg[0];

    for (;;)
	{
		rfm_transmit_packet(packet_send);
		spf_serial_printf("Sent\n");

		rfm_start_listening();
		for (int i = 0; i < 300000; i++) __asm__("nop");
		if(rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			spf_serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			spf_serial_printf("Packet Received\n");

			for(int i = 0; i < RFM_PACKET_LENGTH; i++)
				spf_serial_printf("%02x, ", packet_received->data.buffer[i]);

			spf_serial_printf("\n");
		}

		for (int i = 0; i < 300000; i++) __asm__("nop");
	}
}

void testing_rf_listen(void)
{
	spf_serial_printf("Testing RF Listen\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

    rfm_packet_t *packet_received;

    for (;;)
	{
		if(rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet_received = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();
			spf_serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			spf_serial_printf("Packet Received\n");

			for(int i = 0; i < RFM_PACKET_LENGTH; i++)
				spf_serial_printf("%02x, ", packet_received->data.buffer[i]);

			spf_serial_printf("\n");
		}

		for (int i = 0; i < 300000; i++) __asm__("nop");
	}
}

void testing_sensor(uint32_t dev_num)
{
	spf_serial_printf("Testing Sensor\n");

	// uint16_t start = timers_millis();

	// Set wakeup every 2 minutes
	timers_rtc_init(2);

	// Read temperature
	uint8_t num_readings = 4;
	int16_t readings[4] = {0xFF, 0xFF, 0xFF, 0xFF};

	tmp112_init();
	tmp112_read_temperature(readings, num_readings);
	tmp112_end();

	int32_t sum = 0;
	for(int i = 0; i < num_readings; i++)
		sum += readings[i];
	int16_t temp_avg = sum/num_readings;

	spf_serial_printf("Temp: %i\n", temp_avg);

	// Create and send packet
	rfm_packet_t packet;

	// Temperature reading
	packet.data.buffer[RFM_PACKET_TEMP_0] = temp_avg;
	packet.data.buffer[RFM_PACKET_TEMP_1] = temp_avg >> 8;

	// Sensor ID
	packet.data.buffer[RFM_PACKET_DEV_NUM_0] = dev_num;
	packet.data.buffer[RFM_PACKET_DEV_NUM_1] = dev_num >> 8;
	packet.data.buffer[RFM_PACKET_DEV_NUM_2] = dev_num >> 16;
	packet.data.buffer[RFM_PACKET_DEV_NUM_3] = dev_num >> 24;
	// packet.data.buffer[RFM_PACKET_DEV_NUM_0] = mem_get_dev_num();
	// packet.data.buffer[RFM_PACKET_DEV_NUM_1] = mem_get_dev_num() >> 8;
	// packet.data.buffer[RFM_PACKET_DEV_NUM_2] = mem_get_dev_num() >> 16;
	// packet.data.buffer[RFM_PACKET_DEV_NUM_3] = mem_get_dev_num() >> 24;

	// Message number
	packet.data.buffer[RFM_PACKET_MSG_NUM_0] = mem_get_msg_num();
	packet.data.buffer[RFM_PACKET_MSG_NUM_1] = mem_get_msg_num() >> 8;
	packet.data.buffer[RFM_PACKET_MSG_NUM_2] = mem_get_msg_num() >> 16;
	packet.data.buffer[RFM_PACKET_MSG_NUM_3] = mem_get_msg_num() >> 24;

	// Transmitter power
	int8_t power = 0;
	packet.data.buffer[RFM_PACKET_POWER] = power;

	// Battery voltage
	batt_update_voltages();
	packet.data.buffer[RFM_PACKET_BATTERY_0] = batt_voltages[BATT_VOLTAGE];
	packet.data.buffer[RFM_PACKET_BATTERY_1] = batt_voltages[BATT_VOLTAGE] >> 8;

	// Packet length fixed at the moment
	// packet.length = RFM_PACKET_LENGTH;

	// Print data
	spf_serial_printf("Sending: "); for(int i = 0; i < 16; i++){spf_serial_printf("%02X ", packet.data.buffer[i]);} spf_serial_printf("\n");

	// Encrypt message
	aes_ecb_encrypt(packet.data.buffer);

	// Transmit message
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// rfm_config_for_lora(RFM_BW_500KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_64CPS, true, 0);
	rfm_transmit_packet(packet);
	spf_serial_printf("Packet Sent %u\n", mem_get_msg_num());

	// Continuous TX for a couple seconds
	// rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, -3);
	// rfm_set_tx_continuous();
	// timers_delay_milliseconds(500);

	rfm_end();

	// Update message_number done in mem_save_reading() at the moment
	// mem_update_msg_num(mem_get_msg_num() + 1);
	// Save reading and update message num only if transmitted without turning off
	mem_save_reading(temp_avg);

	spf_serial_printf("\n");

	// uint16_t end = timers_millis();
	// spf_serial_printf("Time: %u\n",(uint16_t)(end - start));

	// Go back to sleep
	timers_enter_standby();
}

void testing_receiver(uint32_t dev_num)
{
	spf_serial_printf("Testing Receiver\n");

	// Sensors
	num_sensors = 3;
	sensors[0].dev_num = dev_num;
	sensors[1].dev_num = 0x12345678;
	sensors[2].dev_num = 0x87654321;

	sensor_t *sensor = NULL;

	// Start listening on rfm
	rfm_packet_t *packet = NULL;
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	// Get First message number
	spf_serial_printf("Waiting for first message\n");
	bool recv = false;
	while(!recv)
	{
		// Wait for first packet to arrive
		while(!rfm_get_num_packets());

		// Get packet, decrypt and organise
		packet = rfm_get_next_packet();
		aes_ecb_decrypt(packet->data.buffer);
		rfm_organize_packet(packet);

		// Print data received
		spf_serial_printf("Received "); for(int i = 0; i < 16; i++){spf_serial_printf("%02X ", packet->data.buffer[i]);} spf_serial_printf("\n");

		// Skip if not correct device number
		sensor = get_sensor(packet->data.device_number);
		if(sensor == NULL)
		{
			spf_serial_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
			continue;
		}
		else
		{
			sensor->msg_num 		= packet->data.msg_number;
			sensor->msg_num_start 	= packet->data.msg_number;
			spf_serial_printf("First Message Number: %i %i\n", packet->data.msg_number, sensor->msg_num);
			recv = true;
		}
	}

	spf_serial_printf("Ready\n");

	for(;;)
	{
		if(rfm_get_num_packets())
		{
			while(rfm_get_num_packets())
			{
				// Get packet, decrypt and organise
				packet = rfm_get_next_packet();
				aes_ecb_decrypt(packet->data.buffer);
				rfm_organize_packet(packet);

				// Check CRC
				if( !packet->crc_ok )
				{
					spf_serial_printf("CRC Fail\n");
					flash_led(100, 5);
					continue;
				}
				else
				{
					spf_serial_printf("CRC OK\n");
				}

				// Get sensor from device number
				sensor = get_sensor(packet->data.device_number);

				// Skip if wrong device number
				if(sensor == NULL)
				{
					spf_serial_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
					flash_led(100, 3);
					continue;
				}

				// Update sensor ok packet counter
				sensor->ok_packets++;
				flash_led(100, 1);

				// Check if message number is correct
				if(packet->data.msg_number != ++sensor->msg_num)
				{
					spf_serial_printf("Missed Message %i\n", sensor->msg_num);
				}

				sensor->total_packets = packet->data.msg_number - sensor->msg_num_start;

				// Print packet details
				spf_serial_printf("Device ID: %08x\n", packet->data.device_number);
				spf_serial_printf("Packet RSSI: %i dbm\n", packet->rssi);
				spf_serial_printf("Packet SNR: %i dB\n", packet->snr);
				spf_serial_printf("Power: %i\n", packet->data.power);
				spf_serial_printf("Battery: %uV\n", packet->data.battery);
				spf_serial_printf("Temperature: %i\n", packet->data.temperature);
				spf_serial_printf("Message Number: %i\n", packet->data.msg_number);
				spf_serial_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);
			}
		}
	}	
}

void testing_hub(void)
{
	// spf_serial_printf("Testing Hub\n");

	// uint32_t total_packets = 0;
	// uint32_t ok_packets = 0;
	// uint32_t missed_packets = 0;
	// uint32_t prev_msg_num = 0;
	// uint32_t start_msg_num = 0;
	// uint32_t recv_msg_num = 0;

	// // Start listening on rfm
	// rfm_packet_t received_packet;

	// rfm_init();
	// rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, false, 0);
	// rfm_start_listening();

	// // Get First message number
	// spf_serial_printf("Waiting for first message\n");
	// bool recv = false;
	// while(!recv)
	// {
	// 	while(!rfm_get_next_packet(&received_packet));
	// 	aes_ecb_decrypt(received_packet.data);
	// 	uint32_t dev_num_rec = received_packet.data[RFM_PACKET_DEV_NUM_0] | received_packet.data[RFM_PACKET_DEV_NUM_1] << 8 | received_packet.data[RFM_PACKET_DEV_NUM_2] << 16 | received_packet.data[RFM_PACKET_DEV_NUM_3] << 24;
	// 	if(dev_num_rec != DEV_NUM_CHIP)
	// 		continue;
	// 	else
	// 	{
	// 		recv_msg_num = received_packet.data[RFM_PACKET_MSG_NUM_1] << 8 | received_packet.data[RFM_PACKET_MSG_NUM_0];
	// 		prev_msg_num = recv_msg_num;
	// 		start_msg_num = recv_msg_num;
	// 		mem_update_msg_num(prev_msg_num);
	// 		spf_serial_printf("First Message Number: %i, %i, %i\n", recv_msg_num, prev_msg_num, mem_get_msg_num());
	// 		recv = true;
	// 	}
	// }

	// spf_serial_printf("Ready\n");

	// for(;;)
	// {
	// 	if(rfm_get_next_packet(&received_packet))
	// 	{
	// 		aes_ecb_decrypt(received_packet.data);

	// 		uint32_t dev_num_rec = received_packet.data[RFM_PACKET_DEV_NUM_0] | received_packet.data[RFM_PACKET_DEV_NUM_1] << 8 | received_packet.data[RFM_PACKET_DEV_NUM_2] << 16 | received_packet.data[RFM_PACKET_DEV_NUM_3] << 24;

	// 		if(dev_num_rec == DEV_NUM_CHIP)
	// 			spf_serial_printf("From Chip Antenna\n");
	// 		else if(dev_num_rec == DEV_NUM_PCB)
	// 			spf_serial_printf("From PCB antenna\n");
	// 		else
	// 			continue;

	// 		// spf_serial_printf("Device ID: %04x\n", dev_num);

	// 		if(received_packet.crc_ok)spf_serial_printf("CRC OK\n");
	// 		else spf_serial_printf("CRC Fail\n");

	// 		spf_serial_printf("Power: %i\n", received_packet.data[RFM_PACKET_POWER]);
			
	// 		uint16_t battery = ((received_packet.data[RFM_PACKET_BATTERY_1] << 8) | received_packet.data[RFM_PACKET_BATTERY_0]);
	// 		spf_serial_printf("Battery: %uV\n", battery);

	// 		spf_serial_printf("Packet RSSI: %i dbm\n", received_packet.rssi);
	// 		spf_serial_printf("Packet SNR: %i dB\n", received_packet.snr);

	// 		recv_msg_num = received_packet.data[RFM_PACKET_MSG_NUM_0] | received_packet.data[RFM_PACKET_MSG_NUM_1] << 8 | received_packet.data[RFM_PACKET_MSG_NUM_2] << 16 | received_packet.data[RFM_PACKET_MSG_NUM_3] << 24;
	// 		prev_msg_num = mem_get_msg_num();
	// 		spf_serial_printf("Message Number: %i\n", recv_msg_num);

	// 		if(recv_msg_num != ++prev_msg_num)
	// 			spf_serial_printf("Missed Message %i\n", prev_msg_num);
				

	// 		int16_t temp = received_packet.data[RFM_PACKET_TEMP_1] << 8 | received_packet.data[RFM_PACKET_TEMP_0];
	// 		spf_serial_printf("Temperature: %i\n", temp);

	// 		total_packets = recv_msg_num - start_msg_num;

	// 		if(received_packet.data[RFM_PACKET_POWER] == 0 && received_packet.crc_ok)
	// 		{
	// 			ok_packets++;
	// 			flash_led(100, 1);
	// 		}
	// 		else
	// 			flash_led(100, 5);

	// 		mem_update_msg_num(prev_msg_num);

	// 		spf_serial_printf("Accuracy: %i / %i packets\n\n", ok_packets, total_packets);

	// 		rfm_end();

	// 		sim_init();
	// 		sim_connect();
	
	// 		sim_send_temp_and_num(&dev_num_rec, &temp, &battery, &total_packets, &ok_packets, &received_packet.rssi, 1);
	// 		spf_serial_printf("Sent %i\n\n", total_packets);
	
	// 		sim_end();

	// 		rfm_init();
	// 		rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// 		rfm_start_listening();
	// 	}
	// }
}

void testing_voltage_scale(uint8_t scale)
{
	spf_serial_printf("Testing Voltage Scale\n");

	rfm_init();
	rfm_end();

	#ifdef _HUB
	sim_init();
	sim_end();

	#else
	// tmp112_init();
	// tmp112_end();
	#endif


	spf_serial_printf("Testing Voltage Scaling\n");
	spf_serial_printf("Current Scaling: %08x\n", PWR_CR);

	batt_set_voltage_scale(scale);

	spf_serial_printf("New Scaling: %08x\n", PWR_CR);

	for (;;)
	{
		for(int i = 0; i < 1000000; i++){__asm__("nop");}
	}
}

void testing_low_power_run(void)
{
	spf_serial_printf("Testing LP Run\n");

	rfm_init();
	rfm_end();

	#ifdef _HUB
	sim_init();
	sim_end();

	#else
	// tmp112_init();
	// tmp112_end();
	#endif

	spf_serial_printf("Testing Low Power Run\n");

	// rcc_periph_clock_enable(RCC_GPIOA);
	// gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1 | GPIO4 | GPIO7 | GPIO9 | GPIO10 | GPIO13 | GPIO14);
	// rcc_periph_clock_disable(RCC_GPIOA);

	batt_set_low_power_run();

	for (;;)
	{
	}
}

void testing_eeprom(void)
{
	spf_serial_printf("Testing EEPROM\n");

	rcc_periph_clock_enable(RCC_MIF);

	for(;;)
	{
		spf_serial_printf("Device: %04x\n", mem_get_dev_num());
		spf_serial_printf("Message: %04x\n", mem_get_msg_num());

		// mem_update_msg_num(mem_get_msg_num() + 1);

		timers_delay_milliseconds(500);
	}
}

void testing_eeprom_keys(void)
{
	spf_serial_printf("Testing EEPROM Encryption Keys\n");

	mem_init();

	uint8_t aes_key[16];
	for(int i = 0; i < 16; i++)
	{
		aes_key[i] = i;
	}
	mem_set_aes_key(aes_key);

	uint8_t aes_key_exp[176];
	mem_get_aes_key_exp(aes_key_exp);


	spf_serial_printf("AES Key: ");
	for(int i = 0; i < 16; i++){spf_serial_printf("%02x ", aes_key[i]);}

	spf_serial_printf("\n\nAES Key Exp: ");
	for(int i = 0; i < 176; i++){spf_serial_printf("%02x ", aes_key_exp[i]);}

	aes_expand_key();
	mem_get_aes_key_exp(aes_key_exp);

	spf_serial_printf("\n\nAES Key Exp: ");
	for(int i = 0; i < 176; i++){spf_serial_printf("%02x ", aes_key_exp[i]);}
}

void testing_eeprom_wipe(void)
{
	spf_serial_printf("Testing EEPROM Wipe\n");

	rcc_periph_clock_enable(RCC_MIF);

	int address = 0x08080000;

	while(address <  0x080807FF)
	{
		spf_serial_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	address = 0x08080000;

	while(address <  0x080807FF)
	{
		eeprom_program_word(address, 0x00);
		address += 4;
	}

	address = 0x08080000;

	while(address <  0x080807FF)
	{
		spf_serial_printf("%08x : %08x\n", address, MMIO32(address));
		address += 4;
	}

	spf_serial_printf("Done\n");
}

void testing_lptim(void)
{
	spf_serial_printf("Testing LP Timer\n");

	timers_lptim_init();

	for(;;)
	{
		spf_serial_printf("LPTim Count: %i\n", lptimer_get_counter(LPTIM1));
		for(int i = 0; i < 1000; i++){__asm__("nop");}
	}
}

void testing_si7051(uint8_t num_readings)
{
	spf_serial_printf("Testing SI7051\n");

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

void testing_tmp112(uint8_t num_readings)
{
	spf_serial_printf("Testing TMP112\n");

	int16_t readings[num_readings];

    for (;;)
	{
		tmp112_init();
		tmp112_read_temperature(readings, num_readings);
		tmp112_end();

		for(int i = 0; i < num_readings; i++)
			spf_serial_printf("Temp %i: %i Deg C\n", i+1, readings[i]);
			
		timers_delay_milliseconds(1000);
	}
}

void testing_rfm(void)
{
	spf_serial_printf("Testing RFM\n");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, -5);
	rfm_set_tx_continuous();
}

void testing_reset_eeprom(void)
{
	spf_serial_printf("Resetting MEM\n");

	rcc_periph_clock_enable(RCC_MIF);
	eeprom_program_word(0x08080000, 0);
	eeprom_program_word(0x08080004, 6);
	eeprom_program_word(0x08080008, 2);
	eeprom_program_word(0x0808000C, 0);

	spf_serial_printf("%04x : %i\n", 0x08080000, MMIO32(0x08080000));
	spf_serial_printf("%04x : %i\n", 0x08080004, MMIO32(0x08080004));
	spf_serial_printf("%04x : %i\n", 0x08080008, MMIO32(0x08080008));
	spf_serial_printf("%04x : %i\n", 0x0808000C, MMIO32(0x0808000C));
	spf_serial_printf("Done\n");
}

void testing_encryption(void)
{
	spf_serial_printf("Testing Encryption\n");

	aes_init();
	mem_init();

	uint8_t data[16] = {'H', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '1', '2', '3', '4', '5'};
	for(int i = 0; i < 16; i++){spf_serial_printf("%c ", data[i]);}
	spf_serial_printf("\n");

	aes_ecb_encrypt(data);
	for(int i = 0; i < 16; i++){spf_serial_printf("%c ", data[i]);}
	spf_serial_printf("\n");

	aes_ecb_decrypt(data);
	for(int i = 0; i < 16; i++){spf_serial_printf("%c ", data[i]);}
	spf_serial_printf("\n");
}

void testing_sim(void)
{
	spf_serial_printf("Testing Sim\n");

	// Hub device number
	uint32_t dev_num = mem_get_dev_num();

	// Start listening on rfm
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	uint8_t	 	num_vals			= 3;
	uint32_t 	ids[3] 				= {0x00000001, 0x00000010, 0x00000100};
	int16_t	 	temps[3] 			= {-634, -312, 512};
	uint16_t	battery[3] 			= {345, 301, 276};
	uint32_t	total_packets[3] 	= {1, 1, 1};
	uint32_t	ok_packets[3]		= {1,1,1};
	int8_t 		rssi[3]				= {1,1,1};

	for(;;)
	{
		// Create Sim Message
		uint8_t sim_buf[256];
		uint8_t sim_idx = 0;
		sim_buf[sim_idx++] = dev_num >> 24; 
		sim_buf[sim_idx++] = dev_num >> 16; 
		sim_buf[sim_idx++] = dev_num >> 8; 
		sim_buf[sim_idx++] = dev_num;

		for(uint8_t i = 0; i < num_vals; i++)
		{
			sim_buf[sim_idx++] = ids[i] 			>> 24;	sim_buf[sim_idx++] = ids[i] 			>> 16; sim_buf[sim_idx++] = ids[i] 				>> 8; sim_buf[sim_idx++] = ids[i];
			sim_buf[sim_idx++] = temps[i] 			>> 8; 	sim_buf[sim_idx++] = temps[i];
			sim_buf[sim_idx++] = battery[i] 		>> 8; 	sim_buf[sim_idx++] = battery[i];
			sim_buf[sim_idx++] = total_packets[i] 	>> 24;	sim_buf[sim_idx++] = total_packets[i]	>> 16; sim_buf[sim_idx++] = total_packets[i]	>> 8; sim_buf[sim_idx++] = total_packets[i];
			sim_buf[sim_idx++] = ok_packets[i]		>> 24;	sim_buf[sim_idx++] = ok_packets[i]		>> 16; sim_buf[sim_idx++] = ok_packets[i]		>> 8; sim_buf[sim_idx++] = ok_packets[i];
			sim_buf[sim_idx++] = rssi[i]			>> 8; 	sim_buf[sim_idx++] = rssi[i];
		}

		// Send Data
		sim_init();
		sim_connect();

		sim_send_data(sim_buf, sim_idx);

		spf_serial_printf("Sent\n\n");

		sim_end();

		temps[2]++;

		timers_delay_milliseconds(5000);

		// Update message number
		for(uint8_t i = 0; i < num_vals; i++)
		{
			total_packets[i]++;
			ok_packets[i]++;
		}
	}
}

void testing_sim_serial_pass_through(void)
{
	spf_serial_printf("Testing sim serial pass through\n");
	sim_serial_pass_through();
}

bool testing_timeout(void)
{
	spf_serial_printf("Testing Timeout\n");
	
	timeout_init();

	// TIMEOUT(test_func(90), 5000000);
	// WAIT_US(test_func(90), 65000);
	// WAIT_MS(test_func(90), 1000);

	while(!timeout(4094967296, "TEST", 0))
	{
		timers_delay_microseconds(1);
	}

	return true;
}

void testing_log(void)
{
	spf_serial_printf("Testing Log\n");

	mem_log_printf("Testing Log\n");

	for(int i = 0; i < 10; i++)
	{
		mem_log_printf("Number: %i\n", i);
	}

	spf_serial_printf("Done\n");

	mem_print_log();
}

void testing_analog_watchdog(void)
{
	spf_serial_printf("Testing Analog Watchdog\n");
	batt_enable_interrupt();
	// batt_enable_comp();

	for(;;)
	{
		__asm__("nop");
	}
}