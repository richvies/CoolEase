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

#include "libopencm3/cm3/scb.h"
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
#include "common/printf.h"

#include "hub/hub_test.h"
#include "hub/cusb.h"
#include "hub/sim.h"

#define NET_LOG          \
	log_printf("NET: "); \
	log_printf

// TODO
// Http post with ssl, logging
// Pass version to bootloader

/** @addtogroup HUB_FILE 
 * @{
 */

#define HUB_CHECK_TIME 60
#define NET_SLEEP_TIME_DEFAULT 300
#define HUB_PLUGGED_IN_VALUE 1111

/** @addtogroup HUB_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static bool hub_plugged_in;

static uint32_t latest_app_version;

static sensor_t sensors[MAX_SENSORS];
static uint8_t num_sensors;

static char sim_buf[1536];
static uint16_t sim_buf_idx = 0;
static uint32_t post_len;

static bool log_upload_pending;
static bool pwr_upload_pending;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void);
static void test(void);
static void hub(void);
static void hub2(void);

static uint32_t get_timestamp(void);

static void check_for_packets(void);

static bool upload_pending(void);
static void clear_upload_pending(void);
static uint8_t temps_pending(void);

static void append_temp(void);
static void append_log(void);

static void update_latest_app_version(void);

static void sim_buf_clear(void);
static uint32_t sim_buf_append_printf(const char *format, ...);
static void _putchar_buffer(char character);

static void net_task(void);

typedef enum
{
	NET_0 = 0,
	NET_UPLOAD_FIRST_PACKET,
	NET_INIT,
	NET_HARD_RESET,
	NET_REGISTERING,
	NET_REGISTERED,
	NET_CONNECTING,
	NET_CONNECTED,
	NET_RUNNING,
	NET_HTTPINIT,
	NET_HTTPPOST,
	NET_HTTPREADY,
	NET_HTTP_DONE,
	NET_ASSEMBLE_PACKET,
	NET_POST,
	NET_SLEEP_START,
	NET_SLEEP_TRY_POST_AGAIN,
	NET_GO_TO_SLEEP,
	NET_SLEEP,
	NET_PARSE_RESPONSE,
	NET_SEND_ERROR_SMS,
	NET_ERROR,
	NET_NUM_STATES,
} net_state_t;

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
	(void)hub2;

	init();

	// Check if first time running
	if (app_info->init_key != APP_INIT_KEY)
	{
		log_printf("APP: First Run\n");

        serial_printf(".Ver: v%u\n", VERSION);
        serial_printf(".Boot Ver: v%u\n", shared_info->boot_version);
		serial_printf(".Dev ID: %u\n", app_info->dev_id);
        serial_printf(".PWD: %s\n", app_info->pwd);
        serial_printf(".AES: ");
        for (uint8_t i = 0; i < 16; i++)
        {
            serial_printf("%2x ", app_info->aes_key[i]);
        }
        serial_printf("\n");

		mem_eeprom_write_word_ptr(&shared_info->app_curr_version, VERSION);
        mem_eeprom_write_word_ptr(&shared_info->app_ok_key, SHARED_APP_OK_KEY);

		mem_eeprom_write_word_ptr(&app_info->init_key, APP_INIT_KEY);

		// Sensor init - IDs, active or not,

		// Reset to signal OK to bootloader
		timers_pet_dogs();
		timers_delay_milliseconds(1000);
		scb_reset_system();
	}

	log_printf("Hub Start\n");

	test();

	hub();

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

sensor_t *get_sensor(uint32_t dev_id)
{
	sensor_t *sensor = NULL;

	for (uint8_t i = 0; i < num_sensors; i++)
	{
		if (dev_id == sensors[i].dev_id)
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
	// cusb_init();
	timers_lptim_init();
	log_init();
	aes_init(app_info->aes_key);
	batt_init();
	flash_led(100, 1);
}

static void test(void)
{
	// Test bootloader watchdog handling
	serial_printf(".Testing 000 Do Nothing\n");
	while (1)
	{
		timers_pet_dogs();
		timers_delay_milliseconds(1000);
	}
	
	// test_bkp_reg();
	// test_revceiver_basic();
	// test_sim_timestamp();
	// test_sim_send_sms();
	// test_sim_init();
	// test_sim_send_sms();
	// test_sim_serial_passthrough();
	// test_sim_get_request();
	// test_sim_get_request_version();
	// test_sim_post();

	// test_sim_get_request();

	for (;;)
	{
		log_printf("Hub App Testing\n\n");
		timers_delay_milliseconds(1000);
	}
}

static void hub(void)
{
	/**/
	// Register with cloud

	// Power checking
	batt_enable_interrupt();

	// USB checking

	// Sensors to listen for
	sensors[num_sensors++].dev_id = 0x00000001;

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

	// Assume plugged in at first
	hub_plugged_in = true;

	// Initial upload
	pwr_upload_pending = true;
	log_upload_pending = true;

	for (;;)
	{
		// Check for packets
		check_for_packets();

		// Keep record of id, num packets, temperature, battery for each sensor
		// Timestamp packets

		// Check if hub plugged in or out since last check
		// Notify cloud if it has
		if (hub_plugged_in ^ batt_is_plugged_in())
		{
			pwr_upload_pending = true;
		}
		hub_plugged_in = batt_is_plugged_in();

		// Logging time?
		if (RTC_ISR & RTC_ISR_WUTF)
		{
			timers_clear_wakeup_flag();
			log_upload_pending = true;
		}

		// Deal with modem and uploading to azure
		net_task();

		timers_pet_dogs();

		timers_delay_milliseconds(100);

		// PRINT_OK();
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
				sensor->msg_appended = false;
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

static bool upload_pending(void)
{
	return (temps_pending() || log_upload_pending || pwr_upload_pending);
}

static void clear_upload_pending(void)
{
	log_upload_pending = false;
	pwr_upload_pending = false;

	for (uint8_t i = 0; i < num_sensors; i++)
	{
		sensor_t *sensor = &sensors[i];
		if (sensor->msg_pend && sensor->msg_appended)
		{
			sensor->msg_pend = false;
			sensor->msg_appended = false;
		}
	}
}

static void append_temp(void)
{
	uint8_t num_pending = temps_pending();
	sim_buf_append_printf("&num_temp=%u", num_pending);

	if (num_pending)
	{
		for (uint16_t i = 0; i < num_sensors; i++)
		{
			sensor_t *sensor = &sensors[i];

			if (sensor->msg_pend)
			{
				sim_printf("&id%u=%8u", i, sensor->dev_id);
				sim_printf("&temp%u=%i", i, sensor->temperature);
				sim_printf("&batt%u=%i", i, sensor->battery);
				sim_printf("&rssi%u=%i", i, sensor->rssi);

				sensor->msg_appended = true;
			}
		}
	}
}

static void append_log(void)
{
	sim_buf_append_printf("&log=\n-----LOG START------\n");

	log_read_reset();
	for (uint16_t i = 0; i < log_size(); i++)
	{
		sim_buf_append_printf("%c", log_read());
	}

	sim_buf_append_printf("\n-----LOG END------\n");
}

static void update_latest_app_version(void)
{
	if (sim800.http.response_size)
	{
		uint8_t buf[64] = {0};
		uint8_t num_bytes = sim_http_read_response(0, sim800.http.response_size, buf);

		// Parse bytes
		for (uint8_t i = 0; i < num_bytes; i++)
		{
			// ASCII to char
			latest_app_version = (latest_app_version * 10) + (uint8_t)(buf[i] - '0');
		}
	}

	serial_printf("Latest Version: %u\n", latest_app_version);
}

static void hub2(void)
{
	// log_printf("Testing Hub 2\n");

	// // Enable power voltgae checking
	// batt_enable_interrupt();

	// // Hub device number
	// uint32_t dev_id = mem_get_dev_num();

	// // Sensors
	// sensor_t *sensor = NULL;
	// num_sensors = 3;
	// sensors[0].dev_id = DEV_NUM_CHIP;
	// sensors[1].dev_id = 0x12345678;
	// sensors[2].dev_id = 0x87654321;

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
	// 		sim_buf[sim_buf_idx++] = dev_id >> 24;
	// 		sim_buf[sim_buf_idx++] = dev_id >> 16;
	// 		sim_buf[sim_buf_idx++] = dev_id >> 8;
	// 		sim_buf[sim_buf_idx++] = dev_id;

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
	// 				log_printf("First message from %u\nNumber: %i\n", sensor->dev_id, sensor->msg_num_start);
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

static void net_task(void)
{
	static net_state_t net_state = NET_0;
	static net_state_t net_next_state;
	static net_state_t net_fallback_state;

	static uint32_t net_sleep_start;
	static uint32_t net_sleep_time_ms = NET_SLEEP_TIME_DEFAULT;
	static bool net_sleep_expired;

	net_sleep_expired = (uint32_t)(timers_millis() - net_sleep_start) > net_sleep_time_ms;

	sim800.state = SIM_ERROR;

	switch (net_state)
	{
	// Upload inital message
	case NET_0:
		NET_LOG("FIRST UPLOAD\n");
		net_next_state = NET_UPLOAD_FIRST_PACKET;

		sim800.state = SIM_SUCCESS;

		break;
	
	case NET_UPLOAD_FIRST_PACKET:
		net_next_state = NET_REGISTERING;
		net_fallback_state = NET_UPLOAD_FIRST_PACKET;

		sim800.state = sim_init();
		break;

	case NET_INIT:

		net_next_state = NET_REGISTERING;
		net_fallback_state = NET_INIT;

		if (hub_plugged_in == false)
		{
			// If unplugged, only upload when data waiting and sleep time expired
			if (upload_pending() == true && net_sleep_expired == true)
			{
				net_next_state = NET_REGISTERING;
			}
			else
			{
				net_next_state = NET_GO_TO_SLEEP;
			}
		}

		sim800.state = sim_init();

		break;

	case NET_REGISTERING:
		net_next_state = NET_REGISTERED;
		net_fallback_state = NET_INIT;

		sim800.state = sim_register_to_network();
		break;

	case NET_REGISTERED:
		NET_LOG("Registered\n");
		net_next_state = NET_CONNECTING;
		net_fallback_state = NET_INIT;

		sim800.state = SIM_SUCCESS;
		break;

	case NET_CONNECTING:
		net_next_state = NET_CONNECTED;
		net_fallback_state = NET_REGISTERING;

		sim800.state = sim_open_bearer("data.rewicom.net", "", "");
		break;

	case NET_CONNECTED:
		NET_LOG("Connected\n");

		net_next_state = NET_RUNNING;
		net_fallback_state = NET_CONNECTING;
		sim800.state = SIM_SUCCESS;
		break;

	case NET_RUNNING:
		net_next_state = NET_RUNNING;
		net_fallback_state = NET_CONNECTING;

		if (upload_pending())
		{
			NET_LOG("Upload\n");
			net_next_state = NET_ASSEMBLE_PACKET;
		}
		sim800.state = sim_is_connected();
		break;

	case NET_ASSEMBLE_PACKET:
		net_next_state = NET_HTTPPOST;
		net_fallback_state = NET_CONNECTED;

		sim_buf_clear();

		sim_buf_append_printf(  "pwd=%s"
								"&id=%8u"
								"&hub_batt=%u"
								"&hub_pwr=%u"
								"&hub_plugged_in=%u"
								"&version=get",
							  	app_info->pwd, 
								app_info->dev_id, 
								batt_voltages[BATT_VOLTAGE], 
								batt_voltages[PWR_VOLTAGE], 
								hub_plugged_in ? HUB_PLUGGED_IN_VALUE : ~HUB_PLUGGED_IN_VALUE );

		if (temps_pending())
		{
			append_temp();
		}
		if (log_upload_pending)
		{
			append_log();
		}

		sim_buf_append_printf("\0\0");

		sim800.state = SIM_SUCCESS;

		// serial_printf("--------\nMSG: %s\n--------\n", sim_buf);
		break;

	case NET_HTTPPOST:
		net_next_state = NET_HTTP_DONE;

		if (hub_plugged_in)
		{
			// Test connection and try post again
			net_fallback_state = NET_RUNNING;
		}
		else
		{
			// Sleep and try post again in a few minutes to conserve battery
			net_sleep_time_ms = 120;
			net_fallback_state = NET_SLEEP_START;
		}

		latest_app_version = 0;

		sim800.state = sim_http_post_str("http://rickceas.azurewebsites.net/CE/hub.php", sim_buf, false, 3);
		break;

	case NET_HTTP_DONE:
		if (hub_plugged_in)
		{
			net_next_state = NET_CONNECTED;
			net_fallback_state = NET_CONNECTED;
		}
		else
		{
			net_sleep_time_ms = 600;
			net_next_state = NET_SLEEP_START;
			net_fallback_state = NET_SLEEP_START;
		}

		update_latest_app_version();
		clear_upload_pending();

		// Goto next state
		sim800.state = SIM_SUCCESS;

		serial_printf("HTTP: %u %u\n", sim800.http.status_code, sim800.http.response_size);
		break;

	case NET_SLEEP_START:
		net_next_state = NET_GO_TO_SLEEP;
		sim800.state = SIM_SUCCESS;

		// Start timer
		net_sleep_start = timers_millis();
		break;

	case NET_GO_TO_SLEEP:
		net_next_state = NET_SLEEP;
		net_fallback_state = NET_INIT;

		sim800.state = sim_sleep();
		break;

	case NET_SLEEP:
		net_next_state = NET_SLEEP;
		net_fallback_state = NET_SLEEP;

		sim800.state = SIM_SUCCESS;

		if (hub_plugged_in || (net_sleep_expired && upload_pending()))
		{
			net_next_state = NET_INIT;
		}
		// Sim sometimes wakes up randomly, NET_INIT will put back to sleep
		else if (sim_printf_and_check_response(100, "OK", "AT\r"))
		{
			net_next_state = NET_INIT;
		}
		break;

	case NET_ERROR:
		NET_LOG("ERROR State\n");
		net_next_state = NET_INIT;
		sim800.state = SIM_SUCCESS;
		break;

	default:
		NET_LOG("DEFAULT State\n");
		net_next_state = NET_INIT;
		sim800.state = SIM_SUCCESS;
		break;
	}

	if (sim800.state == SIM_SUCCESS)
	{
		net_state = net_next_state;
	}
	else if (sim800.state == SIM_ERROR || sim800.state == SIM_TIMEOUT)
	{
		NET_LOG("SIM ERR %u fb %u\n", net_state, net_fallback_state);
		net_state = net_fallback_state;
	}
}

static void sim_buf_clear(void)
{
	for (uint16_t i = 0; i < sim_buf_idx; i++)
	{
		sim_buf[i] = '\0';
	}
	sim_buf_idx = 0;
}

static uint32_t sim_buf_append_printf(const char *format, ...)
{
	va_list va;
	va_start(va, format);
	uint32_t res = fnprintf(_putchar_buffer, format, va);
	va_end(va);

	return res;
}

static void _putchar_buffer(char character)
{
	sim_buf[sim_buf_idx++] = character;
}

/** @} */

/** @} */
