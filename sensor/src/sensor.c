/**
 ******************************************************************************
 * @file    sensor.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Sensor Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>

#include "common/aes.h"
#include "common/battery.h"
#include "common/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/memory.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/test.h"
#include "common/timers.h"

#include "sensor/tmp112.h"
#include "sensor/si7051.h"
#include "sensor/sensor_test.h"
#include "sensor/sensor.h"

/** @addtogroup SENSOR_FILE 
 * @{
 */

#define SENSOR_SLEEP_TIME 600
#define APP_ADDRESS 0x08004000

/** @addtogroup SENSOR_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static dev_info_t *dev_info = ((dev_info_t *)(EEPROM_DEV_INFO_BASE));

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void sensor(void);
static void test(void);
static void init(void);
static void flash_led_failsafe(void);
static void send_packet(void);

/** @} */

/** @addtogroup SENSOR_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

int main(void)
{
	// Stop unused warnings
	(void)test;
	(void)sensor;

	init();

	// test();
	sensor();

	for (;;)
	{
		serial_printf("Loop\n");
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
	gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,  SPF_USART_RX);
	// FTDI Connected
    // gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, SPF_USART_TX);
	// gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  SPF_USART_RX);
	// gpio_set_output_options(SPF_USART_RX_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, SPF_USART_RX);
	// gpio_set(SPF_USART_RX_PORT, SPF_USART_RX);

    // Batt Sense
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);
    
    // RFM
    // SPI
    gpio_mode_setup(RFM_SPI_MISO_PORT,  GPIO_MODE_ANALOG,   GPIO_PUPD_NONE,       RFM_SPI_MISO);

    gpio_mode_setup(RFM_SPI_SCK_PORT,   GPIO_MODE_INPUT,    GPIO_PUPD_PULLDOWN,   RFM_SPI_SCK);
    gpio_mode_setup(RFM_SPI_MOSI_PORT,  GPIO_MODE_INPUT,    GPIO_PUPD_PULLDOWN,   RFM_SPI_MOSI);

    gpio_mode_setup(RFM_SPI_NSS_PORT,   GPIO_MODE_INPUT,    GPIO_PUPD_PULLUP,     RFM_SPI_NSS);
    gpio_mode_setup(RFM_RESET_PORT,     GPIO_MODE_INPUT,    GPIO_PUPD_PULLUP,     RFM_RESET);

    // DIO
	// Input or analog, seems to make no difference
    gpio_mode_setup(RFM_IO_0_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_0);
    gpio_mode_setup(RFM_IO_1_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_1);
    gpio_mode_setup(RFM_IO_2_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_2);
    gpio_mode_setup(RFM_IO_3_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_3);
    gpio_mode_setup(RFM_IO_4_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_4);
    gpio_mode_setup(RFM_IO_5_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_5);

    // TMP
    gpio_mode_setup(TEMP_I2C_SCL_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, TEMP_I2C_SCL);
	gpio_mode_setup(TEMP_I2C_SDA_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, TEMP_I2C_SDA);
}

/** @} */

/** @addtogroup SENSOR_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void init(void)
{
	clock_setup_msi_2mhz();
	timers_lptim_init();
    log_init();
	aes_init(dev_info->aes_key);
	batt_init();

	print_aes_key(dev_info);
	
	// flash_led(100, 5);
    log_printf("Sensor Start\n");
	(void)flash_led_failsafe;
}

static void sensor(void)
{	
	serial_printf("Device: %8x\n", dev_info->dev_num);
	send_packet();

	timers_rtc_init();
	timers_set_wakeup_time(SENSOR_SLEEP_TIME);
	timers_enable_wut_interrupt();

	for (;;)
	{
		// Enter standby
		set_gpio_for_standby();
		timers_enter_standby();
	}
}

static void test(void)
{
	// timers_measure_lsi_freq();
	
	// serial_printf("Dev Info Location: %8x %8x %8x\n", EEPROM_DEV_INFO_BASE, &dev_info->aes_key[0], dev_info->aes_key);
	// test_encryption(dev_info->aes_key);

	// test_eeprom_read();
	// test_log();
	
	// rfm_init();
	// rfm_end();

	// test_sensor_standby(10);

	// tmp112_init();
	// tmp112_end();

	// test_tmp112(10);
	
	// test_wakeup();
	// test_sensor_rf_vs_temp_cal();
	// test_sensor_standby(5);
	// test_rf();
	// test_rf_listen();
	// test_sensor(DEV_NUM_CHIP);
	// test_sensor(0x12345678);
	// test_receiver(3);
	// test_receiver(DEV_NUM_PCB);
	// test_voltage_scale(2);
	// test_low_power_run();
	// test_eeprom();
	// test_eeprom_keys();
	// test_eeprom_wipe();
	// test_lptim();
	// test_si7051(5);
	// test_tmp112(5);
	// test_rfm();
	// test_reset_eeprom();
	// test_encryption();
	// test_timeout();
	// test_log();
}


static void flash_led_failsafe(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO14);
	for(;;)
	{
		for (uint32_t i = 0; i < 100000; i++) { __asm__("nop"); }
		gpio_set(GPIOA, GPIO14);
		for (uint32_t i = 0; i < 100000; i++) { __asm__("nop"); }
		gpio_clear(GPIOA, GPIO14);
	}
}

static void send_packet(void)
{
	/*////////////////////////*/
	// Update Battery
	/*////////////////////////*/
	batt_update_voltages();
	log_printf("Batt %u\n", batt_voltages[BATT_VOLTAGE]);

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
	// Prevent divide by zero
	if(num_readings) 
	{
		temp_avg = sum/num_readings;
	}
	log_printf("Temp: %i\n", temp_avg);

	/*////////////////////////*/
	// Assemble & Encrypt Packet
	/*////////////////////////*/
	rfm_packet_t packet;
	packet.data.device_number = dev_info->dev_num;
	packet.data.battery = batt_voltages[BATT_VOLTAGE];
	packet.data.temperature = temp_avg;
	packet.data.msg_number = 0;

	aes_ecb_encrypt(packet.data.buffer);

	/*////////////////////////*/
	// Send Packet
	/*////////////////////////*/
	rfm_init();
	rfm_config_for_lora(RFM_BW_125KHZ, RFM_CODING_RATE_4_5, RFM_SPREADING_FACTOR_128CPS, true, 0);
	rfm_transmit_packet(packet);
	rfm_end();
	log_printf("Sent\n");
}

// Override default rtc interrupt handler
void rtc_isr(void)
{ 
	// scb_reset_system();

    exti_reset_request(EXTI20);

    if(RTC_ISR & RTC_ISR_WUTF)
    { 
        pwr_disable_backup_domain_write_protect();
        rtc_unlock();
	    rtc_clear_wakeup_flag();
        pwr_clear_standby_flag();
        rtc_lock();
	    pwr_enable_backup_domain_write_protect();
    }

	init();

    log_printf("RTC ISR\n");

	send_packet();
}

/** @} */
/** @} */
