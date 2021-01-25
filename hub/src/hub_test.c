/**
 ******************************************************************************
 * @file    hub_test.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Hub testing Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "hub/hub_test.h"

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/lptimer.h>
#include <libopencm3/stm32/pwr.h>

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/timers.h"
#include "common/test.h"
#include "common/memory.h"

#include "hub/cusb.h"
#include "hub/hub_bootloader.h"
#include "hub/sim.h"
#include "hub/hub.h"

/** @addtogroup HUB_TEST_FILE 
 * @{
 */

/** @addtogroup HUB_TEST_API
 * @{
 */


/*////////////////////////////////////////////////////////////////////////////*/
// Main
/*////////////////////////////////////////////////////////////////////////////*/

void test_hub(void)
{
	// log_printf("Testing Hub\n");

	// uint32_t total_packets = 0;
	// uint32_t ok_packets = 0;
	// uint32_t missed_packets = 0;
	// uint32_t prev_msg_num = 0;
	// uint32_t start_msg_num = 0;
	// uint32_t recv_msg_num = 0;

	// // Start listening on rfm
	// rfm_packet_t received_packet;

	// rfm_init();
	// rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// rfm_start_listening();

	// // Get First message number
	// log_printf("Waiting for first message\n");
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
	// 		log_printf("First Message Number: %i, %i, %i\n", recv_msg_num, prev_msg_num, mem_get_msg_num());
	// 		recv = true;
	// 	}
	// }

	// log_printf("Ready\n");

	// for(;;)
	// {
	// 	if(rfm_get_next_packet(&received_packet))
	// 	{
	// 		aes_ecb_decrypt(received_packet.data);

	// 		uint32_t dev_num_rec = received_packet.data[RFM_PACKET_DEV_NUM_0] | received_packet.data[RFM_PACKET_DEV_NUM_1] << 8 | received_packet.data[RFM_PACKET_DEV_NUM_2] << 16 | received_packet.data[RFM_PACKET_DEV_NUM_3] << 24;

	// 		if(dev_num_rec == DEV_NUM_CHIP)
	// 			log_printf("From Chip Antenna\n");
	// 		else if(dev_num_rec == DEV_NUM_PCB)
	// 			log_printf("From PCB antenna\n");
	// 		else
	// 			continue;

	// 		// log_printf("Device ID: %04x\n", dev_num);

	// 		if(received_packet.crc_ok)log_printf("CRC OK\n");
	// 		else log_printf("CRC Fail\n");

	// 		log_printf("Power: %i\n", received_packet.data[RFM_PACKET_POWER]);

	// 		uint16_t battery = ((received_packet.data[RFM_PACKET_BATTERY_1] << 8) | received_packet.data[RFM_PACKET_BATTERY_0]);
	// 		log_printf("Battery: %uV\n", battery);

	// 		log_printf("Packet RSSI: %i dbm\n", received_packet.rssi);
	// 		log_printf("Packet SNR: %i dB\n", received_packet.snr);

	// 		recv_msg_num = received_packet.data[RFM_PACKET_MSG_NUM_0] | received_packet.data[RFM_PACKET_MSG_NUM_1] << 8 | received_packet.data[RFM_PACKET_MSG_NUM_2] << 16 | received_packet.data[RFM_PACKET_MSG_NUM_3] << 24;
	// 		prev_msg_num = mem_get_msg_num();
	// 		log_printf("Message Number: %i\n", recv_msg_num);

	// 		if(recv_msg_num != ++prev_msg_num)
	// 			log_printf("Missed Message %i\n", prev_msg_num);

	// 		int16_t temp = received_packet.data[RFM_PACKET_TEMP_1] << 8 | received_packet.data[RFM_PACKET_TEMP_0];
	// 		log_printf("Temperature: %i\n", temp);

	// 		total_packets = recv_msg_num - start_msg_num;

	// 		if(received_packet.data[RFM_PACKET_POWER] == 0 && received_packet.crc_ok)
	// 		{
	// 			ok_packets++;
	// 			flash_led(100, 1);
	// 		}
	// 		else
	// 			flash_led(100, 5);

	// 		mem_update_msg_num(prev_msg_num);

	// 		log_printf("Accuracy: %i / %i packets\n\n", ok_packets, total_packets);

	// 		rfm_end();

	// 		sim_init();
	// 		sim_register_to_network();

	// 		sim_send_temp_and_num(&dev_num_rec, &temp, &battery, &total_packets, &ok_packets, &received_packet.rssi, 1);
	// 		log_printf("Sent %i\n\n", total_packets);

	// 		sim_end();

	// 		rfm_init();
	// 		rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// 		rfm_start_listening();
	// 	}
	// }
}

/*////////////////////////////////////////////////////////////////////////////*/
// RF
/*////////////////////////////////////////////////////////////////////////////*/

void test_hub_rf_vs_temp_cal(void)
{
	test_init("test_hub_rf_vs_temp_cal()");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	rfm_packet_t *packet;

	for (;;)
	{
		if (rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();

			// serial_printf("Packet Received\n");
			// serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			if(packet->data.device_number != 0xAD7503BF)
			{
				// serial_printf("Wrong Dev Num\n");
			}
			else
			{
				serial_printf("Temperature: %i\n", packet->data.temperature);
			}
			// serial_printf("\n");
		}
	}
}

void test_revceiver_basic(void)
{
	test_init("test_revceiver_basic()");

	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	rfm_packet_t *packet;

	for (;;)
	{
		if (rfm_get_num_packets())
		{
			uint16_t timer = timers_micros();
			packet = rfm_get_next_packet();
			uint16_t timer2 = timers_micros();

			// serial_printf("Packet Received\n");
			// serial_printf("%i us\n", (uint16_t)(timer2 - timer));

			aes_ecb_decrypt(packet->data.buffer);

			serial_printf("Packet CRC %s\n", packet->crc_ok? "Ok" : "Bad");
			if(!packet->crc_ok)
			{
				continue;
			}

			if(packet->data.device_number != 1)
			{
				serial_printf("Wrong Dev Num %u\n", packet->data.device_number);
			}
			else
			{
				serial_printf("ID: %i\n", packet->data.device_number);
				serial_printf("Battery: %i\n", packet->data.battery);
				serial_printf("Temperature: %i\n", packet->data.temperature); 
				serial_printf("Packet RSSI: %i dbm\n", packet->rssi);
				serial_printf("Packet SNR: %i dB\n", packet->snr);
			}
			serial_printf("\n");
		}
	}
}

void test_receiver(uint32_t dev_num)
{
	test_init("test_receiver()");

	// Sensors
	uint8_t num_sensors = 3;
	sensor_t sensors[3];
	
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
	serial_printf("Waiting for first message\n");
	bool recv = false;
	while (!recv)
	{
		// Wait for first packet to arrive
		while (!rfm_get_num_packets())
		{
		}

		// Get packet, decrypt and organise
		packet = rfm_get_next_packet();
		aes_ecb_decrypt(packet->data.buffer);

		// Print data received
		serial_printf("Received ");
		for (int i = 0; i < 16; i++)
		{
			serial_printf("%02X ", packet->data.buffer[i]);
		}
		serial_printf("\n");

		// Skip if not correct device number
		sensor = get_sensor(packet->data.device_number);
		if (sensor == NULL)
		{
			serial_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
			continue;
		}
		else
		{
			sensor->msg_num = packet->data.msg_number;
			serial_printf("First Message Number: %i %i\n", packet->data.msg_number, sensor->msg_num);
			recv = true;
		}
	}

	serial_printf("Ready\n");

	for (;;)
	{
		if (rfm_get_num_packets())
		{
			while (rfm_get_num_packets())
			{
				// Get packet, decrypt and organise
				packet = rfm_get_next_packet();
				aes_ecb_decrypt(packet->data.buffer);

				// Check CRC
				if (!packet->crc_ok)
				{
					serial_printf("CRC Fail\n");
					flash_led(100, 5);
					continue;
				}
				else
				{
					serial_printf("CRC OK\n");
				}

				// Get sensor from device number
				sensor = get_sensor(packet->data.device_number);

				// Skip if wrong device number
				if (sensor == NULL)
				{
					serial_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
					flash_led(100, 3);
					continue;
				}

				// Update sensor ok packet counter
				sensor->ok_packets++;
				flash_led(100, 1);

				// Check if message number is correct
				if (packet->data.msg_number != ++sensor->msg_num)
				{
					serial_printf("Missed Message %i\n", sensor->msg_num);
				}

				sensor->total_packets = packet->data.msg_number - sensor->msg_num_start;

				// Print packet details
				serial_printf("Device ID: %08x\n", packet->data.device_number);
				serial_printf("Packet RSSI: %i dbm\n", packet->rssi);
				serial_printf("Packet SNR: %i dB\n", packet->snr);
				serial_printf("Power: %i\n", packet->data.power);
				serial_printf("Battery: %uV\n", packet->data.battery);
				serial_printf("Temperature: %i\n", packet->data.temperature);
				serial_printf("Message Number: %i\n", packet->data.msg_number);
				serial_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);
			}
		}
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// USB Tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_cusb_poll(void)
{
	test_init("test_cusb_poll()");

	// Initialize USB and wait for connection before erasing eeprom
	// Otherwise causes usb config problems
	cusb_init();
	serial_printf("USB Initialized\nWaiting for connection\n");
	while (!cusb_connected())
	{
	};
	serial_printf("USB Connected\n");

	while (1)
	{
		cusb_poll();
	}
}

void test_cusb_get_log(void)
{
	test_init("test_cusb_get_log()");

	// Initialize USB and wait for connection before erasing eeprom
	// Otherwise causes usb config problems
	cusb_init();
	serial_printf("USB Initialized\nWaiting for connection\n");
	while (!cusb_connected())
	{
	};
	serial_printf("USB Connected\n");

	serial_printf("Wiping Log\n");
	log_erase();
	serial_printf("Writing Log\n");
	for (uint16_t i = 0; i < 10; i++)
	{
		log_printf("Test %i\n", i);
	}
	log_read_reset();
	serial_printf("\nPrinting Log\n\n");
	for (uint16_t i = 0; i < log_size(); i++)
	{
		serial_printf("%c", log_read());
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// SIM800 Tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_sim_end(void)
{
	for(;;)
	{
		sim_init();
		sim_set_full_function();
		sim_register_to_network();
		timers_delay_milliseconds(3000);
		sim_end();
		timers_delay_milliseconds(5000);
	}
}

void test_sim_serial_passtrhough(void)
{
	test_init("test_sim_serial_passtrhough()");

	if (!sim_init())
	{
		serial_printf("Sim init fail\n");
	}
	else if (!sim_set_full_function())
	{
		serial_printf("Sim can't enter full function mode\n");
	}
	else if (!sim_register_to_network())
	{
		serial_printf("Sim not able to register to network\n");
	}
	else
	{
		sim_serial_pass_through();
	}

	serial_printf("Sim Passthrough Error\n");
}

void test_sim(void)
{
	test_init("test_sim()");

	// Hub device number
	uint32_t dev_num = mem_get_dev_num();

	// Start listening on rfm
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	uint8_t num_vals = 3;
	uint32_t ids[3] = {0x00000001, 0x00000010, 0x00000100};
	int16_t temps[3] = {-634, -312, 512};
	uint16_t battery[3] = {345, 301, 276};
	uint32_t total_packets[3] = {1, 1, 1};
	uint32_t ok_packets[3] = {1, 1, 1};
	int8_t rssi[3] = {1, 1, 1};

	for (;;)
	{
		// Create Sim Message
		uint8_t sim_buf[256];
		uint8_t sim_idx = 0;
		sim_buf[sim_idx++] = dev_num >> 24;
		sim_buf[sim_idx++] = dev_num >> 16;
		sim_buf[sim_idx++] = dev_num >> 8;
		sim_buf[sim_idx++] = dev_num;

		for (uint8_t i = 0; i < num_vals; i++)
		{
			sim_buf[sim_idx++] = ids[i] >> 24;
			sim_buf[sim_idx++] = ids[i] >> 16;
			sim_buf[sim_idx++] = ids[i] >> 8;
			sim_buf[sim_idx++] = ids[i];
			sim_buf[sim_idx++] = temps[i] >> 8;
			sim_buf[sim_idx++] = temps[i];
			sim_buf[sim_idx++] = battery[i] >> 8;
			sim_buf[sim_idx++] = battery[i];
			sim_buf[sim_idx++] = total_packets[i] >> 24;
			sim_buf[sim_idx++] = total_packets[i] >> 16;
			sim_buf[sim_idx++] = total_packets[i] >> 8;
			sim_buf[sim_idx++] = total_packets[i];
			sim_buf[sim_idx++] = ok_packets[i] >> 24;
			sim_buf[sim_idx++] = ok_packets[i] >> 16;
			sim_buf[sim_idx++] = ok_packets[i] >> 8;
			sim_buf[sim_idx++] = ok_packets[i];
			sim_buf[sim_idx++] = rssi[i] >> 8;
			sim_buf[sim_idx++] = rssi[i];
		}

		// Send Data
		sim_init();
		sim_register_to_network();

		sim_send_data(sim_buf, sim_idx);

		log_printf("Sent\n\n");

		sim_end();

		temps[2]++;

		timers_delay_milliseconds(5000);

		// Update message number
		for (uint8_t i = 0; i < num_vals; i++)
		{
			total_packets[i]++;
			ok_packets[i]++;
		}
	}
}

void test_sim_get_request(void)
{
	test_init("test_sim_get_request()");

	uint8_t num_tests = 20;
	uint8_t num_pass = 0;

	for (uint8_t test_num = 1; test_num <= num_tests; test_num++)
	{
		serial_printf("------------------------------\n");
		serial_printf("-----------Test %i------------\n", test_num);
		serial_printf("------------------------------\n");

		if (!sim_init())
		{
			serial_printf("Sim init fail\n");
		}
		else if (!sim_set_full_function())
		{
			serial_printf("Sim can't enter full function mode\n");
		}
		else if (!sim_register_to_network())
		{
			serial_printf("Sim not able to register to network\n");
		}
		else
		{
			uint32_t response_size = sim_http_get("www.google.com");

			if (!response_size)
			{
				serial_printf("Sim get request error\n");
			}
			else
			{
				serial_printf("Response Size %i\n", response_size);
				num_pass++;
				// sim_http_read_response(0, response_size);
			}
		}

		serial_printf("Passed %i/%i\n\n*******************\n\n", num_pass, test_num);

		// sim_serial_pass_through();
	}

	serial_printf("------------------------------\n");
	serial_printf("Test Finished %i/%i Passed\n", num_pass, num_tests);
	serial_printf("------------------------------\n");
}

/** @} */
/** @} */