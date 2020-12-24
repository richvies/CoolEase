#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "sim800.h"
#include "serial_printf.h"

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
}

void sim800_serial_pass_through(void)
{
    sim800_init();

    spf_serial_printf("Ready\n");

    while(1)
    {
        if(usart_get_flag(USART3, USART_SR_RXNE))
            usart_send_blocking(USART1, usart_recv_blocking(USART3));

        if(usart_get_flag(USART1, USART_SR_RXNE))
            usart_send_blocking(USART3, usart_recv_blocking(USART1));
    }
}

/**
 * Static Function Definitions
 */

static void clock_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_USART3);
}

static void usart_setup(void) 
{
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART3_TX);
    gpio_set_mode(GPIOB, GPIO_MODE_INPUT, GPIO_CNF_INPUT_PULL_UPDOWN, GPIO_USART3_RX);

    gpio_set(GPIOB, GPIO_USART3_RX);

	usart_disable(USART3);
	usart_set_baudrate(USART3, 38400);
	usart_set_databits(USART3, 8);
	usart_set_stopbits(USART3,USART_STOPBITS_1);
	usart_set_mode(USART3, USART_MODE_TX_RX);
	usart_set_parity(USART3, USART_PARITY_NONE);
	usart_set_flow_control(USART3, USART_FLOWCONTROL_NONE);
	usart_enable(USART3);
}