#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "coolease/board_defs.h"
#include "coolease/serial_printf.h"

// Implemetation required by printf
void _putchar(char character)
{
	usart_send_blocking(USART2, character);
}

/**
 * Static Function Decls
 */

static void clock_setup(void);
static void usart_setup(void);

/**
 * Global Function Definitions
 */

int spf_serial_printf(const char* format, ...)
{
	clock_setup();
	usart_setup();
	
  	va_list va;
  	va_start(va, format);
  	const int ret = vprintf(format, va);
  	va_end(va);

	while(!usart_get_flag(USART2, USART_ISR_TC)) {__asm__("nop");}

	usart_disable(USART2);
	rcc_periph_clock_disable(RCC_USART2);
	
	return ret;
}

/*
 * Static Function Definitions
 */

static void clock_setup(void) 
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART2);
}

static void usart_setup(void) 
{
	/**
	 * TX - GPIO9
	 * RX - GPIO10
	 */

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_USART2_TX | GPIO_USART2_RX);

    gpio_set_output_options(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_USART2_TX);

    gpio_set_af(GPIOA, GPIO_AF4, GPIO_USART2_TX | GPIO_USART2_RX);

	usart_disable(USART2);
	usart_set_baudrate(USART2, 38400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_enable(USART2);
}
