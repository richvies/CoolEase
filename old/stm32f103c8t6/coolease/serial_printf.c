#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include "coolease/serial_printf.h"

// Implemetation required by printf
void _putchar(char character)
{
	usart_send_blocking(USART1,character);
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

	// usart_wait_for_send_ready(hello);

	return ret;
}

/*
 * Static Function Definitions
 */

static void clock_setup(void) 
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART1);
}

static void usart_setup(void) 
{
	gpio_set_mode(GPIOA,GPIO_MODE_OUTPUT_50_MHZ,GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,GPIO_USART1_TX);
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_PULL_UPDOWN, GPIO_USART1_RX);

    gpio_set(GPIOA, GPIO_USART1_RX);

	usart_disable(USART1);
	usart_set_baudrate(USART1,38400);
	usart_set_databits(USART1,8);
	usart_set_stopbits(USART1,USART_STOPBITS_1);
	usart_set_mode(USART1,USART_MODE_TX_RX);
	usart_set_parity(USART1,USART_PARITY_NONE);
	usart_set_flow_control(USART1,USART_FLOWCONTROL_NONE);
	usart_enable(USART1);
}
