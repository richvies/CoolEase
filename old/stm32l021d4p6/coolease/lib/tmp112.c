#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/flash.h>

#include "coolease/board_defs.h"
#include "coolease/timers.h"
#include "coolease/tmp112.h"
#include "coolease/serial_printf.h"

// Helper functions for setting up i2c communication
static void tmp112_clock_setup(void);
static void tmp112_i2c_setup(void);

void tmp112_init(void)
{
	tmp112_clock_setup();
	tmp112_i2c_setup();
}

void tmp112_end(void)
{
    // Device enters shutdown after oneshot conversion with SD bit set
	uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

	// Send stop bit
	i2c_send_stop(I2C1);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(I2C1);
	rcc_periph_clock_disable(RCC_I2C1);
}

void tmp112_read_temperature(int16_t* readings, uint8_t num_readings)
{
	for (int i = 0; i < num_readings; i++)
	{
        // Set One Shot bit in config register to start conversion
	    uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	    i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

        // Delay 50ms for conversion to complete
        timers_delay_microseconds(50000);

	    // Select temperature register
	    uint8_t select_temp[1] = {TMP112_SEL_TEMP_REG};
        i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, select_temp, 1, NULL, 0);
		
        // Each reading is made up of two 8 bit values
		uint8_t reading_msb_lsb[2] = {0,0};

		// Read temperature register and return msb/ lsb of measurement
		i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, NULL, 0, reading_msb_lsb, 2);
		
		// Convert to degrees celcius and store in array
		int32_t temp = reading_msb_lsb[0] << 24 | reading_msb_lsb[1] << 16;
        temp = temp >> 20;

		temp *= 625;
		temp /= 100;
		readings[i] = temp;
	}

	// Sending stopbit causes i2c to stop working
	// stopbit sent in tmp112_end funtion instead
	// Send stop bit
	// i2c_send_stop(I2C1);
}

static void tmp112_clock_setup(void)
{
	// Enable MSI Osc 2.097Mhz
	rcc_osc_on(RCC_MSI);
	rcc_wait_for_osc_ready(RCC_MSI);

	// Set MSI to 2.097Mhz
	rcc_set_msi_range(5);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 2.097Mhz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 2.097Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 2.097Mhz

	// Set flash, 2.097Mhz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 2097000;
	rcc_apb1_frequency = 2097000;
	rcc_apb2_frequency = 2097000;


	// // Enable MSI Osc 2.097Mhz
	// rcc_osc_on(RCC_MSI);
	// rcc_wait_for_osc_ready(RCC_MSI);

	// // Set MSI to 4.194Mhz
	// rcc_set_msi_range(6);

	// // Set prescalers for AHB, APB1, APB2
	// rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 4.194Mhz
	// rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 4.194Mhz
	// rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 4.194Mhz

	// // Set flash, 4.194Mhz -> 0 waitstates
	// flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// // Set Peripheral Clock Frequencies used
	// rcc_ahb_frequency = 4194000;
	// rcc_apb1_frequency = 4194000;
	// rcc_apb2_frequency = 4194000;
}

static void tmp112_i2c_setup(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
  	rcc_periph_clock_enable(RCC_I2C1);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_I2C1_SCL | GPIO_I2C1_SDA);
	
	gpio_set_output_options(GPIOA, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, GPIO_I2C1_SCL | GPIO_I2C1_SDA);
	
	gpio_set_af(GPIOA, GPIO_AF1, GPIO_I2C1_SCL | GPIO_I2C1_SDA);

	i2c_peripheral_disable(I2C1);
	i2c_clear_stop(I2C1);
	// i2c_set_speed(I2C1, i2c_speed_sm_100k, (uint32_t)rcc_apb1_frequency/1000000);
	
    // 2Mhz input, so tpresc = 500ns 
    i2c_set_prescaler(I2C1, 0);
    i2c_set_scl_low_period(I2C1, 10-1); // 5usecs
    i2c_set_scl_high_period(I2C1, 8-1); // 4usecs
    i2c_set_data_hold_time(I2C1, 1); // 0.5usecs
    i2c_set_data_setup_time(I2C1, 2-1); // 1usecs
	i2c_peripheral_enable(I2C1);
}