/**
 ******************************************************************************
 * @file    hub.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Hub Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#include "libopencm3/cm3/nvic.h"

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/memory.h"
#include "common/reset.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/serial_printf.h"
#include "common/timers.h"
#include "common/test.h"

#include "hub/hub_test.h"
#include "hub/sim.h"

/** @addtogroup HUB_FILE 
 * @{
 */

/** @addtogroup HUB_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void test_hub2(void);
static void hub_download_info(void);

/** @} */

/** @addtogroup HUB_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	spf_init();
	timers_lptim_init();
	timers_tim6_init();
  	// gpio_init();
	// mem_init();
	// aes_init();
	// batt_init();

	for(int i = 0; i < 100000; i++){__asm__("nop");};

	spf_serial_printf("Hub Start\n");
	flash_led(100, 5);

	test_mem_write_read();

	// Read Bootloader ID causes hard fault
	// spf_serial_printf("%08x : %08x\n", 0x1FF00FFE, tst);

	// rfm_init();
	// rfm_end();

	// sim_init();
	// sim_end();

	// test_wakeup();
	// test_rf();
	// test_rf_listen();
	// test_receiver(DEV_NUM_CHIP);
	// test_hub();
	// test_rfm();
	// test_sensor();
	// test_sim();
	// test_sim_serial_pass_through();
	// if( test_timeout() ) spf_serial_printf("Good\n"); else spf_serial_printf("Timeout\n");
	// test_analog_watchdog();
	// test_cusb_poll();

	// test_hub2();


	for (;;)
	{
		spf_serial_printf("Hub Loop\n\n");
		timers_delay_milliseconds(1000);
	}

    // test_hub2();

  return 0;
}

/** @} */

/** @addtogroup HUB_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void test_hub2(void)
{
	spf_serial_printf("Testing Hub 2\n");

	// Enable power voltgae checking
	batt_enable_interrupt();

	// Hub device number
	uint32_t dev_num = mem_get_dev_num();

	// Sensors
	sensor_t *sensor = NULL;
	num_sensors = 3;
	sensors[0].dev_num = DEV_NUM_CHIP;
	sensors[1].dev_num = 0x12345678;
	sensors[2].dev_num = 0x87654321;

	// Start listening on rfm
	rfm_packet_t *packet = NULL;
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, false, 0);
	rfm_start_listening();

	// Useful var
	bool 	upload_packets 	= false;
	uint8_t sim_buf[256];
	uint8_t sim_buf_idx 	= 0;

	spf_serial_printf("Ready\n");

	for(;;)
	{
		// spf_serial_printf("Packets:%u\n", rfm_get_num_packets());

		// Check for packets and upload if any from sensors
		if(rfm_get_num_packets() > 0)
		{
			mem_log_printf("GetPkts %u\n", rfm_get_num_packets());

			upload_packets = false;
			sim_buf_idx = 0;

			// Hub device number and voltage stored first
			sim_buf[sim_buf_idx++] = dev_num >> 24; 
			sim_buf[sim_buf_idx++] = dev_num >> 16; 
			sim_buf[sim_buf_idx++] = dev_num >> 8; 
			sim_buf[sim_buf_idx++] = dev_num;

			sim_buf[sim_buf_idx++] = batt_voltages[PWR_VOLTAGE] >> 8;
			sim_buf[sim_buf_idx++] = batt_voltages[PWR_VOLTAGE];

			while(rfm_get_num_packets())
			{
				// spf_serial_printf("Pkts %u\n", rfm_get_num_packets());

				// Get packet, decrypt and organise
				packet = rfm_get_next_packet();
				aes_ecb_decrypt(packet->data.buffer);
				rfm_organize_packet(packet);

				// Check CRC
				if( !packet->crc_ok )
				{
					spf_serial_printf("CRC Fail\n");
					mem_log_printf("!Crc\n");
					flash_led(100, 5);
					continue;
				}
				else
				{
					spf_serial_printf("CRC OK\n");
					mem_log_printf("CrcOk\n");
				}

				// Get sensor from device number
				sensor = get_sensor(packet->data.device_number);

				// Skip if wrong device number
				if(sensor == NULL)
				{
					spf_serial_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
					mem_log_printf("WDN%08X\n", packet->data.device_number);
					flash_led(100, 3);
					continue;
				}
				else
				{
					// Good packet to upload
					upload_packets = true;
					flash_led(100, 1);
					mem_log_printf("PktOk\n", packet->data.device_number);
				}

				// Initialize sensor if first message received
				if(!sensor->active)
				{
					sensor->msg_num 		= packet->data.msg_number;
					sensor->msg_num_start 	= packet->data.msg_number;
					sensor->total_packets 	= 0;
					sensor->ok_packets 		= 0;
					sensor->active = true;
					spf_serial_printf("First message from %u\nNumber: %i\n",sensor->dev_num, sensor->msg_num_start);
				}
				// Check if message number is correct
				else if(++sensor->msg_num != packet->data.msg_number)
				{
					spf_serial_printf("Missed Message %i\n", sensor->msg_num);
					// mem_log_printf("Missed Message %i\n", sensor->msg_num);
					sensor->msg_num = packet->data.msg_number;
				}

				// Update sensor packet info
				sensor->ok_packets++;
				sensor->total_packets = 1 + packet->data.msg_number - sensor->msg_num_start;

				// Print packet details
				spf_serial_printf("Device ID: %08x\n", packet->data.device_number);
				spf_serial_printf("Packet RSSI: %i dbm\n", packet->rssi);
				spf_serial_printf("Packet SNR: %i dB\n", packet->snr);
				spf_serial_printf("Power: %i\n", packet->data.power);
				spf_serial_printf("Battery: %uV\n", packet->data.battery);
				spf_serial_printf("Temperature: %i\n", packet->data.temperature);
				spf_serial_printf("Message Number: %i\n", packet->data.msg_number);
				spf_serial_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);
				// Log packet details
				// mem_log_printf("Device ID: %08x\n", packet->data.device_number);
				// mem_log_printf("Packet RSSI: %i dbm\n", packet->rssi);
				// mem_log_printf("Packet SNR: %i dB\n", packet->snr);
				// mem_log_printf("Power: %i\n", packet->data.power);
				// mem_log_printf("Battery: %uV\n", packet->data.battery);
				// mem_log_printf("Temperature: %i\n", packet->data.temperature);
				// mem_log_printf("Message Number: %i\n", packet->data.msg_number);
				// mem_log_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);

				// Append Sim Packet
				// packets[i].device_number, packets[i].temperature, packets[i].battery, total_packets[i], ok_packets[i], packets[i].rssi); }
				sim_buf[sim_buf_idx++] = packet->data.device_number 		>> 24;	sim_buf[sim_buf_idx++] = packet->data.device_number 		>> 16; sim_buf[sim_buf_idx++] = packet->data.device_number 		>> 8; sim_buf[sim_buf_idx++] = packet->data.device_number;
				sim_buf[sim_buf_idx++] = packet->data.temperature 		>> 8; 	sim_buf[sim_buf_idx++] = packet->data.temperature;
				sim_buf[sim_buf_idx++] = packet->data.battery 			>> 8; 	sim_buf[sim_buf_idx++] = packet->data.battery;
				sim_buf[sim_buf_idx++] = sensor->total_packets		>> 24;	sim_buf[sim_buf_idx++] = sensor->total_packets		>> 16; sim_buf[sim_buf_idx++] = sensor->total_packets		>> 8; sim_buf[sim_buf_idx++] = sensor->total_packets;
				sim_buf[sim_buf_idx++] = sensor->ok_packets			>> 24;	sim_buf[sim_buf_idx++] = sensor->ok_packets			>> 16; sim_buf[sim_buf_idx++] = sensor->ok_packets			>> 8; sim_buf[sim_buf_idx++] = sensor->ok_packets;
				sim_buf[sim_buf_idx++] = packet->rssi				>> 8; 	sim_buf[sim_buf_idx++] = packet->rssi;
			}
		}

		// Upload to server	if good packets
		if(upload_packets)
		{		
			spf_serial_printf("Uploading\n");
			mem_log_printf("SimUp\n");
			sim_init();
			mem_log_printf("SimInit\n");
			sim_connect();
			mem_log_printf("SimCnt\n");
			sim_send_data(sim_buf, sim_buf_idx);
			spf_serial_printf("SimDone\n\n");
			sim_end();

			upload_packets = false;
		}

		// Redownload hub info if reset sequence (plug out for between 1 -10s)
		if(batt_rst_seq)
		{
			batt_rst_seq = false;
			hub_download_info();
			mem_log_printf("BattRst\n");
		}

		timers_delay_milliseconds(1);
	}
}

static void hub_download_info(void)
{
	spf_serial_printf("Hub Redownload Info\n");
}

/** @} */

/*////////////////////////////////////////////////////////////////////////////*/
// Interrupts
/*////////////////////////////////////////////////////////////////////////////*/

void nmi_handler(void)
{
  spf_serial_printf("nmi\n");
	while(1)
	{
		
	}
}

void hard_fault_handler(void)
{
  spf_serial_printf("hard fault\n");
	while(1)
	{

	}
}

/** @} */




