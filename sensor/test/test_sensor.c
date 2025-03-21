/**
 ******************************************************************************
 * @file    sensor_test.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Sensor testing Source File
 *
 * @defgroup testing Testing
 * @{
 *   @defgroup sensor_test Sensor Tests
 *   @brief    Test functions for Sensor device
 *
 * @}
 ******************************************************************************
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/lptimer.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#include "common/aes.h"
#include "common/battery.h"
#include "common/log.h"
#include "common/memory.h"
#include "common/reset.h"
#include "common/rfm.h"
#include "common/timers.h"
#include "config/board_defs.h"

#include "sensor/sensor.h"
#include "sensor/sensor_bootloader.h"
#include "sensor/si7051.h"
#include "sensor/tmp112.h"

/** @addtogroup testing
 * @{
 */

/** @addtogroup sensor_test Sensor Tests
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Utils
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Temperature Sensor
/*////////////////////////////////////////////////////////////////////////////*/

void test_si7051(uint8_t num_readings) {
    log_printf("Testing SI7051\n");

    int16_t readings[num_readings];

    for (;;) {
        si7051_init();
        si7051_read_temperature(readings, num_readings);
        si7051_end();

        for (int i = 0; i < num_readings; i++)
            log_printf("Temp %i: %i Deg C\n", i + 1, readings[i]);

        timers_delay_milliseconds(1000);
    }
}

void test_tmp112(uint8_t num_readings) {
    log_printf("Testing TMP112\n");

    int16_t readings[num_readings];

    for (;;) {
        tmp112_init();
        tmp112_read_temperature(readings, num_readings);
        tmp112_end();

        for (int i = 0; i < num_readings; i++)
            log_printf("Temp %i: %i Deg C\n", i + 1, readings[i]);

        timers_delay_milliseconds(1000);
    }
}

void test_sensor(uint32_t dev_id) {
    log_printf("Testing Sensor\n");

    // uint16_t start = timers_millis();

    timers_rtc_init();
    timers_set_wakeup_time(5);
    timers_enable_wut_interrupt();

    // Read temperature
    uint8_t num_readings = 4;
    int16_t readings[4] = {0xFF, 0xFF, 0xFF, 0xFF};

    tmp112_init();
    tmp112_read_temperature(readings, num_readings);
    tmp112_end();

    int32_t sum = 0;
    for (int i = 0; i < num_readings; i++)
        sum += readings[i];
    int16_t temp_avg = sum / num_readings;

    log_printf("Temp: %i\n", temp_avg);

    // Create and send packet
    rfm_packet_t packet;

    // Temperature reading
    packet.data.buffer[RFM_PACKET_TEMP_0] = temp_avg;
    packet.data.buffer[RFM_PACKET_TEMP_1] = temp_avg >> 8;

    // Sensor ID
    packet.data.buffer[RFM_PACKET_DEV_NUM_0] = dev_id;
    packet.data.buffer[RFM_PACKET_DEV_NUM_1] = dev_id >> 8;
    packet.data.buffer[RFM_PACKET_DEV_NUM_2] = dev_id >> 16;
    packet.data.buffer[RFM_PACKET_DEV_NUM_3] = dev_id >> 24;
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
    packet.data.battery = batt_get_batt_voltage();

    // Packet length fixed at the moment
    // packet.length = RFM_PACKET_LENGTH;

    // Print data
    log_printf("Sending: ");
    for (int i = 0; i < 16; i++) {
        log_printf("%02X ", packet.data.buffer[i]);
    }
    log_printf("\n");

    // Encrypt message
    aes_ecb_encrypt(packet.data.buffer);

    // Transmit message
    rfm_init();
    rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5,
                        RFM_SPREADING_FACTOR_128CPS, true, 0);
    // rfm_config_for_lora(RFM_BW_500KHZ, RFM_CODING_RATE_4_5,
    // RFM_SPREADING_FACTOR_64CPS, true, 0);
    rfm_transmit_packet(packet);
    log_printf("Packet Sent %u\n", mem_get_msg_num());

    // Continuous TX for a couple seconds
    // rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5,
    // RFM_SPREADING_FACTOR_128CPS, true, -3); rfm_set_tx_continuous();
    // timers_delay_milliseconds(500);

    rfm_end();

    // Update message_number done in mem_save_reading() at the moment
    // mem_update_msg_num(mem_get_msg_num() + 1);
    // Save reading and update message num only if transmitted without turning
    // off
    mem_save_reading(temp_avg);

    log_printf("\n");

    // uint16_t end = timers_millis();
    // log_printf("Time: %u\n",(uint16_t)(end - start));

    // Go back to sleep
    set_gpio_for_standby();
    timers_enter_standby();
}

/*////////////////////////////////////////////////////////////////////////////*/
// RF
/*////////////////////////////////////////////////////////////////////////////*/

void test_sensor_rf_vs_temp_cal(void) {
    test_init("test_sensor_rf_vs_temp_cal()");

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
    for (int i = 0; i < max_readings; i++) {
        if (readings[i] != 22222) {
            sum += readings[i];
            num_readings++;
        }
    }
    // Only calc avg if num_readings > 0
    if (num_readings) {
        temp_avg = sum / num_readings;
    }
    serial_printf("Temp: %i\n", temp_avg);

    /*////////////////////////*/
    // Assemble Packet
    /*////////////////////////*/
    rfm_packet_t packet;
    packet.data.temperature = temp_avg;
    packet.data.msg_number = 0;
    packet.data.device_number = 0xAD7503BF;

    /*////////////////////////*/
    // Send Packet
    /*////////////////////////*/
    rfm_init();
    rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5,
                        RFM_SPREADING_FACTOR_128CPS, true, 0);
    rfm_transmit_packet(packet);
    serial_printf("Sent\n");

    /*////////////////////////*/
    // 1 Second High Pulse
    /*////////////////////////*/
    rfm_set_tx_continuous();
    timers_delay_milliseconds(1000);
    rfm_end();

    /*////////////////////////*/
    // Enter Standby for 30 seconds
    // Resets in RTC ISR
    /*////////////////////////*/
    timers_rtc_init();
    timers_set_wakeup_time(30);
    timers_enable_wut_interrupt();
    set_gpio_for_standby();
    timers_enter_standby();
}

/*////////////////////////////////////////////////////////////////////////////*/
// Power
/*////////////////////////////////////////////////////////////////////////////*/

void test_sensor_standby(uint32_t standby_time) {
    test_init("test_sensor_standby()");

    serial_printf("%i seconds\n", standby_time);

    rfm_init();
    rfm_end();

    tmp112_init();
    tmp112_end();

    // log_printf("Entering Standby\n");
    timers_rtc_init();
    timers_set_wakeup_time(standby_time);
    timers_enable_wut_interrupt();
    set_gpio_for_standby();
    timers_enter_standby();
}

/** @} */

/** @} */