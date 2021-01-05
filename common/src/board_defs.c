#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"

#include <stdint.h>
#include <stddef.h>

void clock_setup_msi_2mhz(void) 
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


sensor_t 	sensors[MAX_SENSORS];
uint8_t 	num_sensors = 0;

sensor_t *get_sensor(uint32_t dev_num)
{
	sensor_t *sensor = NULL;

	for(uint8_t i = 0; i < num_sensors; i++)
	{
		if(dev_num == sensors[i].dev_num)
			sensor = &sensors[i];
	}
	return sensor;
}

void gpio_init(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
  	rcc_periph_clock_enable(RCC_GPIOB);

    // Default is Analog, NoPUPD except PA13/14
	// Input Mode 	00
	// Output 		01
	// Analog 		11
	// GPIO_MODER(GPIOA) = 0x00000000; GPIO_MODER(GPIOB) = 0x00000000;
	// GPIO_MODER(GPIOA) = 0x55555555; GPIO_MODER(GPIOB) = 0x55555555;
	GPIO_MODER(GPIOA) = 0xFFFFFFFF; GPIO_MODER(GPIOB) = 0xFFFFFFFF;

    // Output Low/ High 
    // GPIO_ODR(GPIOA) = 0x00000100; GPIO_ODR(GPIOB) = 0x00000000;
    // GPIO_ODR(GPIOA) = 0xFFFFFFFF; GPIO_ODR(GPIOB) = 0xFFFFFFFF;

	// None 		00
	// Pullup		01
	// PullDown		10       
    GPIO_PUPDR(GPIOA) = 0x00000000; GPIO_PUPDR(GPIOB) = 0x00000000;
    // GPIO_PUPDR(GPIOA) = 0x55555555; GPIO_PUPDR(GPIOB) = 0x55555555;
    // GPIO_PUPDR(GPIOA) = 0xAAAAAAAA; GPIO_PUPDR(GPIOB) = 0xAAAAAAAA;
}