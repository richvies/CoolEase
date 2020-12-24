#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/rtc.h>

#include "coolease/board_defs.h"
#include "coolease/si7051.h"

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
	i2c_send_stop(I2C1);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(I2C1);
	rcc_periph_clock_disable(RCC_I2C1);
}

void si7051_read_temperature(int16_t* readings, uint8_t num_readings)
{
	// Set resolution of si7051 to 14 bits by writing user register
	uint8_t data[2] = {SI7051_CMD_WRITE_REG, SI7051_USER_REG_VAL};
	i2c_transfer7(I2C1, SI7051_I2C_ADDRESS, data, 2, NULL, 0);

	// Command for making temperature measurement
	uint8_t cmd[1] = {SI7051_CMD_MEASURE_HOLD};

	// Each reading is made up of two 8 bit values
	uint8_t reading_msb_lsb[2] = {0,0};

	for (int i = 0; i < num_readings; i++)
	{
		// Transfer measure command and return msb/ lsb of measurement
		i2c_transfer7(I2C1, SI7051_I2C_ADDRESS, cmd, 1, reading_msb_lsb, 2);
		
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
	/*
	// Wait until i2c bus is free
    while ((I2C_SR2(I2C1) & I2C_SR2_BUSY)) {}

	// Send start condition then wait until start is generated and in master mode
	i2c_send_start(I2C1);
    while (!((I2C_SR1(I2C1) & I2C_SR1_SB) & (I2C_SR2(I2C1) & (I2C_SR2_MSL | I2C_SR2_BUSY)))) {}
	
	// Send slave address + write bit
	I2C_DR(I2C1) = (uint8_t)((SI7051_I2C_ADDRESS << 1) | I2C_WRITE);
    while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR));
    (void)I2C_SR2(I2C1);

	// Send reset command
	I2C_DR(I2C1) = SI7051_CMD_RESET;
	while (!(I2C_SR1(I2C1) & (I2C_SR1_BTF))) {}

	// Send stop bit
	i2c_send_stop(I2C1);
	*/
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
	rcc_periph_clock_enable(RCC_GPIOB);
  	rcc_periph_clock_enable(RCC_I2C1);

	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_I2C1_SCL | GPIO_I2C1_SDA);
	
	gpio_set_output_options(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, GPIO_I2C1_SCL | GPIO_I2C1_SDA);
	
	gpio_set_af(GPIOB, GPIO_AF1, GPIO_I2C1_SCL | GPIO_I2C1_SDA);

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