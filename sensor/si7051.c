#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/rtc.h>

#include "sensor/si7051.h"
#include "common/board_defs.h"

// Helper functions for setting up i2c communication
static void si7051_clock_setup(void);
static void si7051_i2c_setup(void);

void si7051_init(void)
{
	si7051_clock_setup();
	si7051_i2c_setup();
}

void si7051_end(void)
{
    // Device enters shutdown after oneshot conversion with SD bit set
	// uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	// i2c_transfer7(I2C1, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

	// Send stop bit
	i2c_send_stop(TEMP_I2C);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(TEMP_I2C);
	rcc_periph_clock_disable(TEMP_I2C_RCC);
}

void si7051_read_temperature(int16_t* readings, uint8_t num_readings)
{
	// Set resolution of si7051 to 14 bits by writing user register
	uint8_t data[2] = {SI7051_CMD_WRITE_REG, SI7051_USER_REG_VAL};
	i2c_transfer7(TEMP_I2C, SI7051_I2C_ADDRESS, data, 2, NULL, 0);

	// Command for making temperature measurement
	uint8_t cmd[1] = {SI7051_CMD_MEASURE_HOLD};

	// Each reading is made up of two 8 bit values
	uint8_t reading_msb_lsb[2] = {0,0};

	for (int i = 0; i < num_readings; i++)
	{
		// Transfer measure command and return msb/ lsb of measurement
		i2c_transfer7(TEMP_I2C, SI7051_I2C_ADDRESS, cmd, 1, reading_msb_lsb, 2);
		
		// Convert to degrees celcius and store in array
		uint32_t temp = reading_msb_lsb[0] << 24 | reading_msb_lsb[1] << 16;
		temp = temp >> 16;
		temp = temp * 17572;
		temp = temp / 65536;
		temp = temp - 4685;

		readings[i] = temp;
	}
}

void si7051_reset(void)
{
	uint8_t cmd[1] = {SI7051_CMD_RESET};
	i2c_transfer7(TEMP_I2C, SI7051_I2C_ADDRESS, cmd, 1, NULL, 0);
}

static void si7051_clock_setup(void)
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
}

static void si7051_i2c_setup(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
  	rcc_periph_clock_enable(TEMP_I2C_RCC);

	gpio_mode_setup(TEMP_I2C_SCL_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, TEMP_I2C_SCL);
	gpio_mode_setup(TEMP_I2C_SDA_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, TEMP_I2C_SDA);
	
	gpio_set_output_options(TEMP_I2C_SCL_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, TEMP_I2C_SCL);
	gpio_set_output_options(TEMP_I2C_SDA_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, TEMP_I2C_SDA);
	
	gpio_set_af(TEMP_I2C_SCL_PORT, TEMP_I2C_AF, TEMP_I2C_SCL);
	gpio_set_af(TEMP_I2C_SDA_PORT, TEMP_I2C_AF, TEMP_I2C_SDA);

	i2c_peripheral_disable(TEMP_I2C);
	i2c_clear_stop(TEMP_I2C);
	// i2c_set_speed(I2C1, i2c_speed_sm_100k, (uint32_t)rcc_apb1_frequency/1000000);
	
    // 2Mhz input, so tpresc = 500ns 
    i2c_set_prescaler(TEMP_I2C, 0);
    i2c_set_scl_low_period(TEMP_I2C, 10-1); // 5usecs
    i2c_set_scl_high_period(TEMP_I2C, 8-1); // 4usecs
    i2c_set_data_hold_time(TEMP_I2C, 1); // 0.5usecs
    i2c_set_data_setup_time(TEMP_I2C, 2-1); // 1usecs
	i2c_peripheral_enable(TEMP_I2C);
}
