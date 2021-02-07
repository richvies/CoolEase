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

#include "hub/hub.h"

#include <string.h>

#include "libopencm3/cm3/nvic.h"
#include "libopencm3/stm32/syscfg.h"
#include "libopencm3/stm32/rtc.h"

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/log.h"
#include "common/memory.h"
#include "common/reset.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/timers.h"
#include "common/test.h"

#include "hub/hub_test.h"
#include "hub/cusb.h"
#include "hub/sim.h"

// TODO
// Http post with ssl, logging
// Pass version to bootloader

/** @addtogroup HUB_FILE 
 * @{
 */

#define HUB_CHECK_TIME 60

/** @addtogroup HUB_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static sensor_t sensors[MAX_SENSORS];
static uint8_t num_sensors = 0;
static dev_info_t *dev_info = ((dev_info_t *)(EEPROM_DEV_INFO_BASE));
static uint8_t sim_buf[256];
static uint32_t online_version = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void test(void);
static void hub(void);
static void hub2(void);
static void hub_download_info(void);

static void check_for_packets(void);
static uint8_t temps_pending(void);

static uint32_t get_timestamp(void);
static bool upload_and_get_version(void);
static bool post_init(void);
static void append_temp(void);
static void append_log(void);
static uint32_t post_and_get_version(void);

/** @} */

/** @addtogroup HUB_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	// Stop unused warnings
	(void)test;
	(void)hub;
	(void)hub2;
	(void)hub_download_info;

	init();

	test();

	hub();

	// test_hub2();

	for (;;)
	{
		log_printf("Hub Loop\n\n");
		timers_delay_milliseconds(1000);
	}

	return 0;
}

void set_gpio_for_standby(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

	// LED
	gpio_mode_setup(LED_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, LED);

	// Serial Print
	// FTDI not connected
	usart_disable(SPF_USART);
	rcc_periph_clock_disable(SPF_USART_RCC);
	gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, SPF_USART_TX);
	gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, SPF_USART_RX);
	// FTDI Connected
	// gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, SPF_USART_TX);
	// gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  SPF_USART_RX);
	// gpio_set_output_options(SPF_USART_RX_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, SPF_USART_RX);
	// gpio_set(SPF_USART_RX_PORT, SPF_USART_RX);

	// Batt Sense
	gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);
	gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);

	// RFM
	// SPI
	gpio_mode_setup(RFM_SPI_MISO_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_SPI_MISO);

	gpio_mode_setup(RFM_SPI_SCK_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, RFM_SPI_SCK);
	gpio_mode_setup(RFM_SPI_MOSI_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, RFM_SPI_MOSI);

	gpio_mode_setup(RFM_SPI_NSS_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, RFM_SPI_NSS);
	gpio_mode_setup(RFM_RESET_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, RFM_RESET);

	// DIO
	// Input or analog, seems to make no difference
	gpio_mode_setup(RFM_IO_0_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_0);
	gpio_mode_setup(RFM_IO_1_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_1);
	gpio_mode_setup(RFM_IO_2_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_2);
	gpio_mode_setup(RFM_IO_3_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_3);
	gpio_mode_setup(RFM_IO_4_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_4);
	gpio_mode_setup(RFM_IO_5_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_5);

	// SIM
	gpio_mode_setup(SIM_USART_TX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_PULLUP, SIM_USART_TX);
	gpio_mode_setup(SIM_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_PULLUP, SIM_USART_RX);
}

sensor_t *get_sensor(uint32_t dev_num)
{
	sensor_t *sensor = NULL;

	for (uint8_t i = 0; i < num_sensors; i++)
	{
		if (dev_num == sensors[i].dev_num)
			sensor = &sensors[i];
	}
	return sensor;
}

/** @} */

/** @addtogroup HUB_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void)
{
	clock_setup_hsi_16mhz();
	cusb_init();
	timers_lptim_init();
	log_init();
	aes_init(dev_info->aes_key);
	batt_init();

	print_aes_key(dev_info);

	// flash_led(100, 5);
	log_printf("Hub Start\n");
}

static void test(void)
{
	// test_sim_get_request();
	// test_sim_get_request_version();
	// test_sim_post();
	// test_sim_serial_passthrough();

	for (;;)
	{
		serial_printf("Hub Loop\n");
		timers_delay_milliseconds(1000);
	}
}

static void hub(void)
{
	/* Initial setup */
	// Watchdog

	// Power checking
	batt_enable_interrupt();

	// USB checking

	// Check if first time running
	if (dev_info->init_key != INIT_KEY)
	{
		serial_printf("Dev Info: First Power On\n");

		mem_eeprom_write_word((uint32_t)&dev_info->init_key, INIT_KEY);
		// Sensor init - IDs, active or not,
	}

	// Sensors to listen for
	sensors[num_sensors++].dev_num = 0x00000001;

	// Start listening on rfm
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_start_listening();

	// Get timestamp from sim
	uint32_t timestamp = get_timestamp();

	// Init rtc, one hour wakeup flag for logging & checking software
	timers_rtc_init();
	timers_set_wakeup_time(HUB_CHECK_TIME);
	timers_disable_wut_interrupt();

	for (;;)
	{
		// Check for packets
		check_for_packets();

		// Keep record of id, num packets, temperature, battery for each sensor
		// Timestamp packets

		// Upload and reset pending message flags
		if (upload_and_get_version())
		{
			if (RTC_ISR & RTC_ISR_WUTF)
			{
				timers_clear_wakeup_flag();
			}

			for (uint16_t i = 0; i < num_sensors; i++)
			{
				sensors[i].msg_pend = false;
			}
		}
	}
}

static uint32_t get_timestamp(void)
{
	uint32_t stamp = 0;

	if (!sim_init())
	{
	}
	else if (!sim_register_to_network())
	{
	}
	else if (!sim_get_timestamp())
	{
	}
	else if (!sim_end())
	{
	}

	return stamp;
}

static void check_for_packets(void)
{
	if (rfm_get_num_packets() > 0)
	{
		log_printf("RFM: %u Pkts\n", rfm_get_num_packets());

		while (rfm_get_num_packets())
		{
			// Get packet, decrypt and organise
			rfm_packet_t *packet = rfm_get_next_packet();
			aes_ecb_decrypt(packet->data.buffer);

			// Get sensor from device number
			sensor_t *sensor = get_sensor(packet->data.device_number);

			// Skip if wrong device number
			if (sensor == NULL)
			{
				log_printf("Wrong # : %08X\n", packet->data.device_number);
				continue;
			}
			else
			{
				if (!sensor->active)
				{
					sensor->active = true;
					sensor->msg_pend = false;
					sensor->msg_num = 0;
				}

				sensor->power = packet->data.power;
				sensor->battery = packet->data.battery;
				sensor->temperature = packet->data.temperature;
				sensor->msg_num++;
				sensor->msg_pend = true;
				sensor->rssi = packet->rssi;
			}

			// Print packet details
			serial_printf("Device ID: %08x\n", packet->data.device_number);
			serial_printf("Packet RSSI: %i dbm\n", packet->rssi);
			serial_printf("Packet SNR: %i dB\n", packet->snr);
			serial_printf("Power: %i\n", packet->data.power);
			serial_printf("Battery: %uV\n", packet->data.battery);
			serial_printf("Temperature: %i\n", packet->data.temperature);
			serial_printf("Message Number: %i\n", packet->data.msg_number);
		}
	}
}

static uint8_t temps_pending(void)
{
	// Upload if any valid temp packets
	uint8_t res = 0;
	for (uint8_t i = 0; i < num_sensors; i++)
	{
		if (sensors[i].msg_pend)
		{
			++res;
		}
	}

	return res;
}

static bool upload_and_get_version(void)
{
	uint32_t version = 0;

	if (temps_pending() || (RTC_ISR & RTC_ISR_WUTF))
	{
		serial_printf("upload_and_get_version()\n");

		if (!post_init())
		{
		}
		else
		{
			// Sensor readings
			append_temp();

			// Everyday hour, upload log
			if (RTC_ISR & RTC_ISR_WUTF)
			{
				append_log();
			}

			sim_printf_and_check_response(10000, "OK", "\r");

			// Post
			version = post_and_get_version();

			sim_http_term();
		}
		sim_end();
	}

	if (version != 0)
	{
		online_version = version;
		return true;
	}

	return false;
}

static bool post_init(void)
{
	bool res = false;

	if (!sim_init())
	{
	}
	else if (!sim_register_to_network())
	{
	}
	// else if (!sim_http_post_init("https://cooleasetest.000webhostapp.com/hub.php", 2000, 10000))
	// {
	// }
	else
	{
		sim_printf("pwd=%s&id=%8u&version=get", dev_info->pwd, dev_info->dev_num);
		res = true;
	}

	return res;
}

static void append_temp(void)
{
	uint8_t num_pending = temps_pending();
	if (num_pending)
	{
		sim_printf("&num_temp=%u", num_pending);

		for (uint16_t i = 0; i < num_sensors; i++)
		{
			if (sensors[i].msg_pend)
			{
				sim_printf("&dev%8u=%i", sensors[i].dev_num, sensors[i].temperature);
			}
		}
	}
}

static void append_log(void)
{
	sim_printf("&log=\n-----LOG START------\n");

	log_read_reset();
	for (uint16_t i = 0; i < log_size(); i++)
	{
		sim_printf("%c", log_read());
	}

	sim_printf("\n-----LOG END------\n");
}

static uint32_t post_and_get_version(void)
{
	// uint32_t resp_len = sim_http_post(1);
	uint32_t version = 0;
	// if (resp_len)
	// {
	// 	uint8_t num_bytes = sim_http_read_response(0, resp_len);

	// 	// SIM800 now returns that number of bytes
	// 	for (uint8_t i = 0; i < num_bytes; i++)
	// 	{
	// 		while (!sim_available())
	// 		{
	// 		}
	// 		// ASCII to char
	// 		version = (version * 10) + (uint8_t)(sim_read() - '0');
	// 	}
	// 	serial_printf("Online Version: %u\n", version);
	// }

	return version;
}

static void hub2(void)
{
	// log_printf("Testing Hub 2\n");

	// // Enable power voltgae checking
	// batt_enable_interrupt();

	// // Hub device number
	// uint32_t dev_num = mem_get_dev_num();

	// // Sensors
	// sensor_t *sensor = NULL;
	// num_sensors = 3;
	// sensors[0].dev_num = DEV_NUM_CHIP;
	// sensors[1].dev_num = 0x12345678;
	// sensors[2].dev_num = 0x87654321;

	// // Start listening on rfm
	// rfm_packet_t *packet = NULL;
	// rfm_init();
	// rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// rfm_start_listening();

	// // Useful var
	// bool upload_packets = false;
	// uint8_t sim_buf[256];
	// uint8_t sim_buf_idx = 0;

	// log_printf("Ready\n");

	// for (;;)
	// {
	// 	// log_printf("Packets:%u\n", rfm_get_num_packets());

	// 	// Check for packets and upload if any from sensors
	// 	if (rfm_get_num_packets() > 0)
	// 	{
	// 		log_printf("GetPkts %u\n", rfm_get_num_packets());

	// 		upload_packets = false;
	// 		sim_buf_idx = 0;

	// 		// Hub device number and voltage stored first
	// 		sim_buf[sim_buf_idx++] = dev_num >> 24;
	// 		sim_buf[sim_buf_idx++] = dev_num >> 16;
	// 		sim_buf[sim_buf_idx++] = dev_num >> 8;
	// 		sim_buf[sim_buf_idx++] = dev_num;

	// 		sim_buf[sim_buf_idx++] = batt_voltages[PWR_VOLTAGE] >> 8;
	// 		sim_buf[sim_buf_idx++] = batt_voltages[PWR_VOLTAGE];

	// 		while (rfm_get_num_packets())
	// 		{
	// 			// log_printf("Pkts %u\n", rfm_get_num_packets());

	// 			// Get packet, decrypt and organise
	// 			packet = rfm_get_next_packet();
	// 			aes_ecb_decrypt(packet->data.buffer);

	// 			// Check CRC
	// 			if (!packet->crc_ok)
	// 			{
	// 				log_printf("CRC Fail\n");
	// 				log_printf("!Crc\n");
	// 				flash_led(100, 5);
	// 				continue;
	// 			}
	// 			else
	// 			{
	// 				log_printf("CRC OK\n");
	// 				log_printf("CrcOk\n");
	// 			}

	// 			// Get sensor from device number
	// 			sensor = get_sensor(packet->data.device_number);

	// 			// Skip if wrong device number
	// 			if (sensor == NULL)
	// 			{
	// 				log_printf("Wrong Dev Num: %08X\n", packet->data.device_number);
	// 				log_printf("WDN%08X\n", packet->data.device_number);
	// 				flash_led(100, 3);
	// 				continue;
	// 			}
	// 			else
	// 			{
	// 				// Good packet to upload
	// 				upload_packets = true;
	// 				flash_led(100, 1);
	// 				log_printf("PktOk\n", packet->data.device_number);
	// 			}

	// 			// Initialize sensor if first message received
	// 			if (!sensor->active)
	// 			{
	// 				sensor->msg_num = packet->data.msg_number;
	// 				sensor->msg_num_start = packet->data.msg_number;
	// 				sensor->total_packets = 0;
	// 				sensor->ok_packets = 0;
	// 				sensor->active = true;
	// 				log_printf("First message from %u\nNumber: %i\n", sensor->dev_num, sensor->msg_num_start);
	// 			}
	// 			// Check if message number is correct
	// 			else if (++sensor->msg_num != packet->data.msg_number)
	// 			{
	// 				log_printf("Missed Message %i\n", sensor->msg_num);
	// 				// log_printf("Missed Message %i\n", sensor->msg_num);
	// 				sensor->msg_num = packet->data.msg_number;
	// 			}

	// 			// Update sensor packet info
	// 			sensor->ok_packets++;
	// 			sensor->total_packets = 1 + packet->data.msg_number - sensor->msg_num_start;

	// 			// Print packet details
	// 			// print_packet_details();
	// 			log_printf("Device ID: %08x\n", packet->data.device_number);
	// 			log_printf("Packet RSSI: %i dbm\n", packet->rssi);
	// 			log_printf("Packet SNR: %i dB\n", packet->snr);
	// 			log_printf("Power: %i\n", packet->data.power);
	// 			log_printf("Battery: %uV\n", packet->data.battery);
	// 			log_printf("Temperature: %i\n", packet->data.temperature);
	// 			log_printf("Message Number: %i\n", packet->data.msg_number);
	// 			log_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);
	// 			// Log packet details
	// 			// log_printf("Device ID: %08x\n", packet->data.device_number);
	// 			// log_printf("Packet RSSI: %i dbm\n", packet->rssi);
	// 			// log_printf("Packet SNR: %i dB\n", packet->snr);
	// 			// log_printf("Power: %i\n", packet->data.power);
	// 			// log_printf("Battery: %uV\n", packet->data.battery);
	// 			// log_printf("Temperature: %i\n", packet->data.temperature);
	// 			// log_printf("Message Number: %i\n", packet->data.msg_number);
	// 			// log_printf("Accuracy: %i / %i packets\n\n", sensor->ok_packets, sensor->total_packets);

	// 			// Append Sim Packet
	// 			// packets[i].device_number, packets[i].temperature, packets[i].battery, total_packets[i], ok_packets[i], packets[i].rssi); }
	// 			sim_buf[sim_buf_idx++] = packet->data.device_number >> 24;
	// 			sim_buf[sim_buf_idx++] = packet->data.device_number >> 16;
	// 			sim_buf[sim_buf_idx++] = packet->data.device_number >> 8;
	// 			sim_buf[sim_buf_idx++] = packet->data.device_number;
	// 			sim_buf[sim_buf_idx++] = packet->data.temperature >> 8;
	// 			sim_buf[sim_buf_idx++] = packet->data.temperature;
	// 			sim_buf[sim_buf_idx++] = packet->data.battery >> 8;
	// 			sim_buf[sim_buf_idx++] = packet->data.battery;
	// 			sim_buf[sim_buf_idx++] = sensor->total_packets >> 24;
	// 			sim_buf[sim_buf_idx++] = sensor->total_packets >> 16;
	// 			sim_buf[sim_buf_idx++] = sensor->total_packets >> 8;
	// 			sim_buf[sim_buf_idx++] = sensor->total_packets;
	// 			sim_buf[sim_buf_idx++] = sensor->ok_packets >> 24;
	// 			sim_buf[sim_buf_idx++] = sensor->ok_packets >> 16;
	// 			sim_buf[sim_buf_idx++] = sensor->ok_packets >> 8;
	// 			sim_buf[sim_buf_idx++] = sensor->ok_packets;
	// 			sim_buf[sim_buf_idx++] = packet->rssi >> 8;
	// 			sim_buf[sim_buf_idx++] = packet->rssi;
	// 		}
	// 	}

	// 	// Upload to server	if good packets
	// 	if (upload_packets)
	// 	{
	// 		log_printf("Uploading\n");
	// 		log_printf("SimUp\n");
	// 		sim_init();
	// 		log_printf("SimInit\n");
	// 		sim_register_to_network();
	// 		log_printf("SimCnt\n");
	// 		sim_send_data(sim_buf, sim_buf_idx);
	// 		log_printf("SimDone\n\n");
	// 		sim_end();

	// 		upload_packets = false;
	// 	}

	// 	// Redownload hub info if reset sequence (plug out for between 1 -10s)
	// 	if (batt_rst_seq)
	// 	{
	// 		batt_rst_seq = false;
	// 		hub_download_info();
	// 		log_printf("BattRst\n");
	// 	}

	// 	timers_delay_milliseconds(1);
	// }
}

static void hub_download_info(void)
{
	log_printf("Hub Redownload Info\n");
}

/** @} */

/** @} */
