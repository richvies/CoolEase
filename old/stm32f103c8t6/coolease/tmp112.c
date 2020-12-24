#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/rtc.h>
#include "coolease/tmp112.h"
#include "coolease/serial_printf.h"

// Helper functions for setting up i2c communication
static void tmp112_clock_setup(void);
static void tmp112_i2c_setup(void);

void tmp112_setup_and_read_temperature(float* readings, uint8_t num_readings)
{
	tmp112_clock_setup();
	tmp112_i2c_setup();

	for (int i = 0; i < num_readings; i++)
	{
        // Set One Shot bit in config register to start conversion
	    uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	    i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

        // Delay for conversion to complete
        for(int j = 0; j < 8000000; j++){__asm__("nop");}

	    // Select temperature register
	    uint8_t select_temp[1] = {TMP112_SEL_TEMP_REG};
        i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, select_temp, 1, NULL, 0);
		
        // Each reading is made up of two 8 bit values
		uint8_t reading_msb_lsb[2] = {0,0};

		// Read temperature register and return msb/ lsb of measurement
		i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, NULL, 0, reading_msb_lsb, 2);
		
		// Convert to degrees celcius and store in array
		int16_t temp = reading_msb_lsb[0] << 8 | reading_msb_lsb[1];
        temp = temp >> 4;
        float temp_float = (float)temp;
		readings[i] = temp_float * 0.0625;
	}

	// Send stop bit
	i2c_send_stop(I2C1);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(I2C1);
	rcc_periph_clock_disable(RCC_I2C1);

}

static void tmp112_clock_setup(void)
{
	// Enable HSI Osc 8Mhz
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	// Select HSI as SYSCLK Source
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	// Set prescalers for AHB, ADC, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);		// AHB -> 8MHz
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);		// ADC -> 4MHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_NODIV);		// APB1 -> 8Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);		// APB2 -> 8MHz

	// Set flash, 8MHz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 8000000;
	rcc_apb1_frequency = 8000000;
	rcc_apb2_frequency = 8000000;

	// Enable Peripheral Clocks
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_I2C1);
}

static void tmp112_i2c_setup(void)
{
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN, GPIO6|GPIO7);
    gpio_set(GPIOB, GPIO6 | GPIO7);
	gpio_primary_remap(0,0);

	i2c_peripheral_disable(I2C1);
	i2c_clear_stop(I2C1);
	i2c_set_speed(I2C1, i2c_speed_sm_100k, (uint32_t)rcc_apb1_frequency/1000000);
	i2c_peripheral_enable(I2C1);
}