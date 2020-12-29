#include "common/serial_printf.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"


//  Static Function Decls
static void clock_setup(void);
static void usart_setup(void);

//  Global Function Definitions

void spf_init(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

	clock_setup();
	usart_setup();
}

int spf_serial_printf(const char* format, ...)
{	
  	va_list va;
  	va_start(va, format);
  	const int ret = vprintf_spf(format, va);
  	va_end(va);

	while(!usart_get_flag(SPF_USART, USART_ISR_TC)) {__asm__("nop");}
	
	return ret;
}

// Implemetation required by printf
void _putchar_spf(char character)
{
	usart_send_blocking(SPF_USART, character);
}


//  Static Function Definitions
static void clock_setup(void) 
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

static void usart_setup(void) 
{
	rcc_periph_clock_enable(SPF_USART_RCC);

	gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SPF_USART_TX);
	gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SPF_USART_RX);
    
    gpio_set_output_options(SPF_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, SPF_USART_TX);

    gpio_set_af(SPF_USART_TX_PORT, SPF_USART_AF, SPF_USART_TX);
    gpio_set_af(SPF_USART_RX_PORT, SPF_USART_AF, SPF_USART_RX);
    
    rcc_periph_reset_pulse(SPF_USART_RCC_RST);
	usart_disable(SPF_USART);
	usart_set_baudrate(SPF_USART, SPF_USART_BAUD);
	usart_set_databits(SPF_USART, 8);
	usart_set_stopbits(SPF_USART,USART_STOPBITS_1);
	usart_set_mode(SPF_USART, USART_MODE_TX_RX);
	usart_set_parity(SPF_USART, USART_PARITY_NONE);
	usart_set_flow_control(SPF_USART, USART_FLOWCONTROL_NONE);
	usart_enable(SPF_USART);
}
