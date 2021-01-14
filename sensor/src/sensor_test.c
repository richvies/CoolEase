/**
 ******************************************************************************
 * @file    sensor_test.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Sensor testing Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "sensor/sensor_test.h"

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

#include "sensor/sensor_bootloader.h"
#include "sensor/si7051.h"
#include "sensor/tmp112.h"

/** @addtogroup SENSOR_TEST_FILE 
 * @{
 */

/** @addtogroup SENSOR_TEST_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */

/** @addtogroup SENSOR_TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void test_sensor_init(const char *test_name)
{
	clock_setup_msi_2mhz();
	log_init();
	timers_lptim_init();
	timers_tim6_init();

	for (uint32_t i = 0; i < 10000; i++)
	{
		__asm__("nop");
	}

	serial_printf("%s\n------------------\n\n", test_name);
}


void test_si7051(uint8_t num_readings)
{
	log_printf("Testing SI7051\n");

	int16_t readings[num_readings];

    for (;;)
	{
		si7051_init();
		si7051_read_temperature(readings, num_readings);
		si7051_end();

		for(int i = 0; i < num_readings; i++)
			log_printf("Temp %i: %i Deg C\n", i+1, readings[i]);
			
		timers_delay_milliseconds(1000);
	}
}

void test_tmp112(uint8_t num_readings)
{
	log_printf("Testing TMP112\n");

	int16_t readings[num_readings];

    for (;;)
	{
		tmp112_init();
		tmp112_read_temperature(readings, num_readings);
		tmp112_end();

		for(int i = 0; i < num_readings; i++)
			log_printf("Temp %i: %i Deg C\n", i+1, readings[i]);
			
		timers_delay_milliseconds(1000);
	}
}

void test_sensor(uint32_t dev_num)
{
	log_printf("Testing Sensor\n");

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

	log_printf("Temp: %i\n", temp_avg);

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
	log_printf("Sending: "); for(int i = 0; i < 16; i++){log_printf("%02X ", packet.data.buffer[i]);} log_printf("\n");

	// Encrypt message
	aes_ecb_encrypt(packet.data.buffer);

	// Transmit message
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	// rfm_config_for_lora(RFM_BW_500KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_64CPS, true, 0);
	rfm_transmit_packet(packet);
	log_printf("Packet Sent %u\n", mem_get_msg_num());

	// Continuous TX for a couple seconds
	// rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, -3);
	// rfm_set_tx_continuous();
	// timers_delay_milliseconds(500);

	rfm_end();

	// Update message_number done in mem_save_reading() at the moment
	// mem_update_msg_num(mem_get_msg_num() + 1);
	// Save reading and update message num only if transmitted without turning off
	mem_save_reading(temp_avg);

	log_printf("\n");

	// uint16_t end = timers_millis();
	// log_printf("Time: %u\n",(uint16_t)(end - start));

	// Go back to sleep
	timers_enter_standby();
}

void test_sensor_rf_vs_temp_cal(void)
{
	test_sensor_init("test_sensor_rf_vs_temp_cal()");

	/*////////////////////////*/
	// Get Average Temperature
	/*////////////////////////*/
	uint8_t max_readings = 4;
	int16_t readings[4] = {22222, 22222, 22222, 22222};
	tmp112_init();
	tmp112_read_temperature(readings, max_readings);
	tmp112_end();
	int32_t sum = 0;
	uint8_t num_readings = 0;
	int16_t temp_avg = 22222;
	for(int i = 0; i < max_readings; i++)
	{
		if(readings[i] != 22222)
		{
			sum += readings[i];
			num_readings++;
		}
	}
	// Only calc avg if num_readings > 0
	if(num_readings)
	{
		temp_avg = sum/num_readings;
	}
	serial_printf("Temp: %i\n", temp_avg);

	/*////////////////////////*/
	// Send Temperature
	/*////////////////////////*/
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_packet_t packet;
	packet.data.temperature = temp_avg;
	rfm_transmit_packet(packet);
	serial_printf("Sent\n");

	/*////////////////////////*/
	// 1 Second High Pulse
	/*////////////////////////*/
	

	for (;;)
	{
		
	}
}



/** @} */

/** @addtogroup SENSOR_TEST_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */
/** @} */