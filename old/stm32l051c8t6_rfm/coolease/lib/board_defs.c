#include "coolease/board_defs.h"

#include <stdint.h>
#include <stddef.h>

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