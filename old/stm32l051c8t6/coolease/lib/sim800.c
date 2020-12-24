#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "coolease/board_defs.h"
#include "coolease/serial_printf.h"
#include "coolease/sim800.h"

/**
 * Static Function Decls
 */

static void clock_setup(void);
static void usart_setup(void);

/**
 * Global Function Definitions
 */

void sim800_init(void)
{
    clock_setup();
    usart_setup();

    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_SIM_RST);
    gpio_set_output_options(GPIOA, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, GPIO_SIM_RST);
    gpio_set(GPIOA, GPIO_SIM_RST);
}

void sim800_reset_hold(void) {gpio_clear(GPIOA, GPIO_SIM_RST);};
void sim800_reset_release(void) {gpio_set(GPIOA, GPIO_SIM_RST);};

/**
 * Static Function Definitions
 */

static void clock_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART2);
}

static void usart_setup(void) 
{
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_USART2_TX | GPIO_USART2_RX);
    
    gpio_set_output_options(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_USART2_TX);

    gpio_set_af(GPIOA, GPIO_AF4, GPIO_USART2_TX | GPIO_USART2_RX);
    
    rcc_periph_reset_pulse(RST_USART2);
	usart_disable(USART2);
	usart_set_baudrate(USART2, 38400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2,USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_enable(USART2);
}