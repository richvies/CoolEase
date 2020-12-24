#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/rtc.h>
#include "coolease/si7051.h"

// Helper functions for setting up i2c communication
static void si7051_clock_setup(void);
static void si7051_i2c_setup(void);

void si7051_setup_and_read_temperature(float* readings, uint8_t num_readings)
{
	si7051_clock_setup();
	si7051_i2c_setup();

	// Wait until i2c bus is free
    while ((I2C_SR2(I2C1) & I2C_SR2_BUSY)) {}

	// Send start condition then wait until start is generated and in master mode
	i2c_send_start(I2C1);
    while (!((I2C_SR1(I2C1) & I2C_SR1_SB) & (I2C_SR2(I2C1) & (I2C_SR2_MSL | I2C_SR2_BUSY)))) {}
	
	// Send slave address + write bit
	I2C_DR(I2C1) = (uint8_t)((SI7051_I2C_ADDRESS << 1) | I2C_WRITE);
    while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR));
    (void)I2C_SR2(I2C1);

	// Send write user register command
	I2C_DR(I2C1) = SI7051_CMD_WRITE_REG;
	while (!(I2C_SR1(I2C1) & (I2C_SR1_BTF))) {}

	// Send user register value
	I2C_DR(I2C1) = SI7051_USER_REG_VAL;
	while (!(I2C_SR1(I2C1) & (I2C_SR1_BTF))) {}

	// Get Measurements
	for (int i = 0; i < num_readings; i++)
	{
		// Send repeated start
		i2c_send_start(I2C1);
		while (!((I2C_SR1(I2C1) & I2C_SR1_SB) & (I2C_SR2(I2C1) & (I2C_SR2_MSL | I2C_SR2_BUSY)))) {}

		// Send slave address + write bit
		I2C_DR(I2C1) = (uint8_t)((SI7051_I2C_ADDRESS << 1) | I2C_WRITE);
    	while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR)) {}
    	(void)I2C_SR2(I2C1);

		// Send measure command
		I2C_DR(I2C1) = SI7051_CMD_MEASURE_HOLD;
		while (!(I2C_SR1(I2C1) & (I2C_SR1_BTF))) {}

		// Send repeated start + enable acknowledge
		i2c_send_start(I2C1);
		i2c_enable_ack(I2C1);
		while (!((I2C_SR1(I2C1) & I2C_SR1_SB) & (I2C_SR2(I2C1) & (I2C_SR2_MSL | I2C_SR2_BUSY)))) {}

		// Send slave address + read bit
		I2C_DR(I2C1) = (uint8_t)((SI7051_I2C_ADDRESS << 1) | I2C_READ);
    	while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR)) {}
    	(void)I2C_SR2(I2C1);

		// Read first byte + disable acknowledge
		while (!(I2C_SR1(I2C1) & I2C_SR1_RxNE)) {}
		uint8_t msb = i2c_get_data(I2C1);
		i2c_disable_ack(I2C1);

		// Read second byte
		while (!(I2C_SR1(I2C1) & I2C_SR1_RxNE)) {}
		uint8_t lsb = i2c_get_data(I2C1);

		// Convert and store in array
		float temp = msb << 8 | lsb;
		readings[i] = (175.72 * temp) / 65536 - 46.85;
	}

	// Send stop bit
	i2c_send_stop(I2C1);
}

void si7051_setup_and_read_temperature2(float* readings, uint8_t num_readings)
{
	si7051_clock_setup();
	si7051_i2c_setup();

	// Set resolution of si7051 to 14 bits by writing user register
	uint8_t data[2] = {SI7051_CMD_WRITE_REG, SI7051_USER_REG_VAL};
	i2c_transfer7(I2C1, SI7051_I2C_ADDRESS, data, 2, NULL, 0);

	// Get temperature readings
	uint8_t cmd[1] = {SI7051_CMD_MEASURE_HOLD};
	for (int i = 0; i < num_readings; i++)
	{
		// Each reading is made up of two 8 bit values
		uint8_t reading_msb_lsb[2] = {0,0};

		// Transfer measure command and return msb/ lsb of measurement
		i2c_transfer7(I2C1, SI7051_I2C_ADDRESS, cmd, 1, reading_msb_lsb, 2);
		
		// Convert to degrees celcius and store in array
		float temp = reading_msb_lsb[0] << 8 | reading_msb_lsb[1];
		readings[i] = (175.72 * temp) / 65536 - 46.85;
	}

	// Send stop bit
	i2c_send_stop(I2C1);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(I2C1);
	rcc_periph_clock_disable(RCC_I2C1);

}

void si7051_reset(void)
{
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
}

static void si7051_clock_setup(void)
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

static void si7051_i2c_setup(void)
{
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN, GPIO6|GPIO7);
	gpio_primary_remap(0,0);

	i2c_peripheral_disable(I2C1);
	i2c_clear_stop(I2C1);
	i2c_set_speed(I2C1, i2c_speed_sm_100k, (uint32_t)rcc_apb1_frequency/1000000);
	i2c_peripheral_enable(I2C1);
}