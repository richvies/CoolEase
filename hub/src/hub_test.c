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
#include "common/memory.h"

#include "hub/cusb.h"
#include "hub/hub_bootloader.h"
#include "hub/sim.h"

/** @addtogroup HUB_TEST_FILE 
 * @{
 */

/** @addtogroup HUB_TEST_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */

/** @addtogroup HUB_TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void test_cusb_poll(void)
{
  cusb_init();
  cusb_test_poll();
}

void test_sim(void)
{
	log_printf(MAIN, "Testing Sim\n");

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

		log_printf(MAIN, "Sent\n\n");

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

void test_sim_serial_pass_through(void)
{
	log_printf(MAIN, "Testing sim serial pass through\n");
	sim_serial_pass_through();
}

void test_hub(void)
{
	// log_printf(MAIN, "Testing Hub\n");

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
	// log_printf(MAIN, "Waiting for first message\n");
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
	// 		log_printf(MAIN, "First Message Number: %i, %i, %i\n", recv_msg_num, prev_msg_num, mem_get_msg_num());
	// 		recv = true;
	// 	}
	// }

	// log_printf(MAIN, "Ready\n");

	// for(;;)
	// {
	// 	if(rfm_get_next_packet(&received_packet))
	// 	{
	// 		aes_ecb_decrypt(received_packet.data);

	// 		uint32_t dev_num_rec = received_packet.data[RFM_PACKET_DEV_NUM_0] | received_packet.data[RFM_PACKET_DEV_NUM_1] << 8 | received_packet.data[RFM_PACKET_DEV_NUM_2] << 16 | received_packet.data[RFM_PACKET_DEV_NUM_3] << 24;

	// 		if(dev_num_rec == DEV_NUM_CHIP)
	// 			log_printf(MAIN, "From Chip Antenna\n");
	// 		else if(dev_num_rec == DEV_NUM_PCB)
	// 			log_printf(MAIN, "From PCB antenna\n");
	// 		else
	// 			continue;

	// 		// log_printf(MAIN, "Device ID: %04x\n", dev_num);

	// 		if(received_packet.crc_ok)log_printf(MAIN, "CRC OK\n");
	// 		else log_printf(MAIN, "CRC Fail\n");

	// 		log_printf(MAIN, "Power: %i\n", received_packet.data[RFM_PACKET_POWER]);
			
	// 		uint16_t battery = ((received_packet.data[RFM_PACKET_BATTERY_1] << 8) | received_packet.data[RFM_PACKET_BATTERY_0]);
	// 		log_printf(MAIN, "Battery: %uV\n", battery);

	// 		log_printf(MAIN, "Packet RSSI: %i dbm\n", received_packet.rssi);
	// 		log_printf(MAIN, "Packet SNR: %i dB\n", received_packet.snr);

	// 		recv_msg_num = received_packet.data[RFM_PACKET_MSG_NUM_0] | received_packet.data[RFM_PACKET_MSG_NUM_1] << 8 | received_packet.data[RFM_PACKET_MSG_NUM_2] << 16 | received_packet.data[RFM_PACKET_MSG_NUM_3] << 24;
	// 		prev_msg_num = mem_get_msg_num();
	// 		log_printf(MAIN, "Message Number: %i\n", recv_msg_num);

	// 		if(recv_msg_num != ++prev_msg_num)
	// 			log_printf(MAIN, "Missed Message %i\n", prev_msg_num);
				

	// 		int16_t temp = received_packet.data[RFM_PACKET_TEMP_1] << 8 | received_packet.data[RFM_PACKET_TEMP_0];
	// 		log_printf(MAIN, "Temperature: %i\n", temp);

	// 		total_packets = recv_msg_num - start_msg_num;

	// 		if(received_packet.data[RFM_PACKET_POWER] == 0 && received_packet.crc_ok)
	// 		{
	// 			ok_packets++;
	// 			flash_led(100, 1);
	// 		}
	// 		else
	// 			flash_led(100, 5);

	// 		mem_update_msg_num(prev_msg_num);

	// 		log_printf(MAIN, "Accuracy: %i / %i packets\n\n", ok_packets, total_packets);

	// 		rfm_end();

	// 		sim_init();
	// 		sim_connect();
	
	// 		sim_send_temp_and_num(&dev_num_rec, &temp, &battery, &total_packets, &ok_packets, &received_packet.rssi, 1);
	// 		log_printf(MAIN, "Sent %i\n\n", total_packets);
	
	// 		sim_end();

	// 		rfm_init();
	// 		rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// 		rfm_start_listening();
	// 	}
	// }
}


/** @} */

/** @addtogroup HUB_TEST_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */
/** @} */