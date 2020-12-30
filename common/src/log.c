/**
 ******************************************************************************
 * @file    log.c
 * @author  Richard Davies
 * @date    30/Dec/2020
 * @brief   Log Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "common/log.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"
#include "common/memory.h"
#include "common/printf.h"
#include "common/log.h"

/** @addtogroup LOG_FILE 
 * @{
 */

/** @addtogroup LOG_INT 
 * @{
 */

#define LOG_SIZE    1024
#define LOG_START   EEPROM_END - LOG_SIZE

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static uint32_t curr_address =   LOG_START;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void clock_setup(void);
static void usart_setup(void);
static void _putchar(char character, void* buffer, size_t idx, size_t maxlen);

/** @} */

/** @addtogroup LOG_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void log_init(void)
{
    curr_address = 0;

    #ifdef DEBUG
    clock_setup();
    usart_setup();
    #endif
}

void log_printf(enum log_type type, const char *format, ...)
{
    char buffer[1];

	va_list va;
	va_start(va, format);

    switch (type)
    {
    case MAIN:
        _vsnprintf(_putchar, buffer, (size_t)-1, format, va);
        break;
    
    default:
        break;
    }

  	va_end(va);

    // Wait for uart to finish if serial print is used
    #ifdef DEBUG
    while(!usart_get_flag(SPF_USART, USART_ISR_TC)) {__asm__("nop");}
    #endif
}

/** @} */

/** @addtogroup LOG_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

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
    rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

	gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SPF_USART_TX);
	gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SPF_USART_RX);
    
    gpio_set_output_options(SPF_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, SPF_USART_TX);

    gpio_set_af(SPF_USART_TX_PORT, SPF_USART_AF, SPF_USART_TX);
    gpio_set_af(SPF_USART_RX_PORT, SPF_USART_AF, SPF_USART_RX);
    
	rcc_periph_clock_enable(SPF_USART_RCC);
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

static void _putchar(char character, void* buffer, size_t idx, size_t maxlen)
{
	(void)buffer; (void)idx; (void)maxlen;

    mem_eeprom_write_byte(curr_address++, character);

    #ifdef DEBUG
	usart_send_blocking(SPF_USART, character);	
    #endif		
}

/** @} */
/** @} */
