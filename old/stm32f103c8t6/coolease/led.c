#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "coolease/led.h"

void led_init(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_AFIO);

	gpio_primary_remap(AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_OFF, 0);

	gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO15);
	gpio_set_mode(GPIOB,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_PUSHPULL,GPIO3|GPIO4|GPIO5);

	gpio_clear(GPIOA,GPIO15);
	gpio_clear(GPIOB,GPIO3|GPIO4|GPIO5);
}