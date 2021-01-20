#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"
#include "common/timers.h"
#include "sensor/tmp112.h"
#include "common/log.h"

// Helper functions for setting up i2c communication
static void tmp112_clock_setup(void);
static void tmp112_i2c_setup(void);
static void i2c_transfer(uint32_t i2c, uint8_t addr, uint8_t *w, size_t wn, uint8_t *r, size_t rn);

void tmp112_init(void)
{
	log_printf("TMP Init\n");

	tmp112_clock_setup();
	tmp112_i2c_setup();
}

void tmp112_end(void)
{
	log_printf("TMP End\n");

    // Device enters shutdown after oneshot conversion with SD bit set
	uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	// uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_CM_MSB, TMP112_CONFIG_CM_LSB};
	i2c_transfer(TEMP_I2C, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

	// Send stop bit
	i2c_send_stop(TEMP_I2C);

	// Disable i2c Peripheral and Clock. GPIO clock still enabled
	i2c_peripheral_disable(TEMP_I2C);
	rcc_periph_clock_disable(TEMP_I2C_RCC);
}

void tmp112_reset(void)
{
	log_printf("TMP Reset\n");

	uint8_t cmd[1] = {TMP112_RESET_CMD};
	i2c_transfer(TEMP_I2C, TMP112_GEN_CALL_ADDR, cmd, 1, NULL, 0);
}

void tmp112_read_temperature(int16_t* readings, uint8_t num_readings)
{
	for (int i = 0; i < num_readings; i++)
	{
        // Set One Shot bit in config register to start conversion
	    uint8_t config[3] = {TMP112_SEL_CONFIG_REG, TMP112_CONFIG_OS_MSB, TMP112_CONFIG_OS_LSB};
	    i2c_transfer(TEMP_I2C, TMP112_I2C_ADDRESS, config, 3, NULL, 0);

        // Delay 50ms for conversion to complete
        timers_delay_microseconds(50000);

	    // Select temperature register
	    uint8_t select_temp[1] = {TMP112_SEL_TEMP_REG};
        i2c_transfer(TEMP_I2C, TMP112_I2C_ADDRESS, select_temp, 1, NULL, 0);
		
        // Each reading is made up of two 8 bit values
		uint8_t reading_msb_lsb[2] = {0,0};

		// Read temperature register and return msb/ lsb of measurement
		i2c_transfer(TEMP_I2C, TMP112_I2C_ADDRESS, NULL, 0, reading_msb_lsb, 2);
		
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
	// i2c_send_stop(TEMP_I2C);
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
}

static void tmp112_i2c_setup(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
  	rcc_periph_clock_enable(TEMP_I2C_RCC);

	gpio_mode_setup(TEMP_I2C_SCL_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, TEMP_I2C_SCL);
	gpio_mode_setup(TEMP_I2C_SDA_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, TEMP_I2C_SDA);
	
	gpio_set_output_options(TEMP_I2C_SCL_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, TEMP_I2C_SCL);
	gpio_set_output_options(TEMP_I2C_SDA_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, TEMP_I2C_SDA);
	
	gpio_set_af(TEMP_I2C_SCL_PORT, TEMP_I2C_AF, TEMP_I2C_SCL);
	gpio_set_af(TEMP_I2C_SDA_PORT, TEMP_I2C_AF, TEMP_I2C_SDA);

	rcc_periph_reset_pulse(TEMP_I2C_RCC_RST);
	i2c_peripheral_disable(TEMP_I2C);
	i2c_clear_stop(TEMP_I2C);
	// i2c_set_speed(TEMP_I2C, i2c_speed_sm_100k, (uint32_t)rcc_apb1_frequency/1000000);
	
    // 2Mhz input, so tpresc = 500ns 
    i2c_set_prescaler(TEMP_I2C, 0);
    i2c_set_scl_low_period(TEMP_I2C, 10-1); // 5usecs
    i2c_set_scl_high_period(TEMP_I2C, 8-1); // 4usecs
    i2c_set_data_hold_time(TEMP_I2C, 1); // 0.5usecs
    i2c_set_data_setup_time(TEMP_I2C, 2-1); // 1usecs
	i2c_peripheral_enable(TEMP_I2C);
}

static void i2c_transfer(uint32_t i2c, uint8_t addr, uint8_t *w, size_t wn, uint8_t *r, size_t rn)
 {
    /*  waiting for busy is unnecessary. read the RM */
    if (wn) 
	{
        i2c_set_7bit_address(i2c, addr);
        i2c_set_write_transfer_dir(i2c);
        i2c_set_bytes_to_transfer(i2c, wn);

        if (rn) 
		{
            i2c_disable_autoend(i2c);
        } 
		else 
		{
            i2c_enable_autoend(i2c);
        }
            
		i2c_send_start(i2c);

        while (wn--) 
		{	
			timers_delay_microseconds(1);
			TIMEOUT(100000, "TMP I2C:", ((wn << 16) | *w), i2c_transmit_int_status(i2c), ;, ;);
			// timeout_init();
			// while (!timeout(100000, "TMP I2C", (wn << 16) | *w)) 
			// {         
			// 	if (i2c_transmit_int_status(i2c)) 
			// 	{
            //        	break;
            //     }
            // }

            i2c_send_data(i2c, *w++);
        }

        /* not entirely sure this is really necessary.
         * RM implies it will stall until it can write out the later bits
         */
        if (rn) 
		{
            while (!i2c_transfer_complete(i2c));
        }
    }

    if (rn) 
	{
        /* Setting transfer properties */
        i2c_set_7bit_address(i2c, addr);
        i2c_set_read_transfer_dir(i2c);
        i2c_set_bytes_to_transfer(i2c, rn);
        /* start transfer */
        i2c_send_start(i2c);
        /* important to do it afterwards to do a proper repeated start! */
        i2c_enable_autoend(i2c);

        for (size_t i = 0; i < rn; i++) 
		{
			TIMEOUT(100000, "TMP I2C Recv:", (rn << 16), i2c_received_data(i2c), ;, ;);
            r[i] = i2c_get_data(i2c);
        }
    }
 }
 