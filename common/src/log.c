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

#ifdef DEBUG
#ifdef _HUB
#include "hub/cusb.h"
#endif
#endif

/** @addtogroup LOG_FILE 
 * @{
 */

/** @addtogroup LOG_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

// Vars used during normal operation
// Prevent wearing down eeprom with lots of writes
static uint16_t write_index;
static uint16_t read_index;

// Persistant data
typedef struct 
{
	uint16_t size;
	uint16_t write_index;
	uint8_t  log[];
}log_t;

static log_t *logger = ((log_t *)(EEPROM_LOG_BASE));


/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void _putchar_main(char character);
static void _putchar_mem(char character);

#ifdef DEBUG
static void usart_setup(void);
static void _putchar_spf(char character);
#ifdef _HUB
static void _putchar_usb(char character);
#endif
#endif

/** @} */

/** @addtogroup LOG_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void log_init(void)
{	
	// Copy persistant to volatile
	write_index = logger->write_index;
	read_index 	= write_index;

	log_printf("\n\nLog Init\n----------------\n");

    #ifdef DEBUG
	#ifdef _HUB
	// Init usb first so that uart has correct clock speed to set baud rate
	cusb_init();
	#endif
    usart_setup();
	for(int i = 0; i < 100000; i++){__asm__("nop");};
    #endif
}

void log_printf(const char *format, ...)
{
	va_list va;
	va_start(va, format);
	fnprintf(_putchar_main, format, va);
  	va_end(va);

    // Wait for uart to finish if serial print is used
    #ifdef DEBUG
    while(!usart_get_flag(SPF_USART, USART_ISR_TC)) {}
    #endif
}

void log_error(uint16_t error)
{
	log_printf("Error %i\n", error);
}

void serial_printf(const char *format, ...)
{
	#ifdef DEBUG
	va_list va;
	va_start(va, format);
	fnprintf(_putchar_spf, format, va);
  	va_end(va);

    // Wait for uart to finish if serial print is used
    while(!usart_get_flag(SPF_USART, USART_ISR_TC)) {}
    #endif
}

uint8_t log_get_byte(uint16_t index)
{
	uint8_t byte;

	if (index > logger->size)
	{
		byte = 0;
	}
	else
	{
		byte = logger->log[index];
	}
	
	return byte;
}

uint8_t log_read(void)
{
	uint8_t byte;

	read_index = (read_index + 1) % logger->size;

	if(read_index == logger->write_index)
	{
		byte = 0;
	}
	else
	{
		byte = logger->log[read_index];
		// serial_printf("Log Reading %8x %c\n", EEPROM_LOG_BASE + read_index, byte);
	}

	return byte;	
}

void log_read_reset(void)
{
	read_index = logger->write_index;
}

uint16_t log_size(void)
{
	return logger->size;
}



/** @} */

/** @addtogroup LOG_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void _putchar_main(char character)
{
	_putchar_mem(character);

	#ifdef DEBUG
	_putchar_spf(character);
	#ifdef _HUB
	_putchar_usb(character);
	#endif
	#endif			
}

static void _putchar_mem(char character)
{
	// serial_printf("Logging %8x\n", EEPROM_LOG_BASE+logger->write_index);

	mem_eeprom_write_byte((uint32_t)&(logger->log[write_index]), character);
	write_index = (write_index + 1)%EEPROM_LOG_SIZE;
}

#ifdef DEBUG

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

static void _putchar_spf(char character)
{
	usart_send_blocking(SPF_USART, character);	
}

#ifdef _HUB
static void _putchar_usb(char character)
{
	cusb_send(character);
}
#endif // _HUB
#endif // DEBUG



/** @} */
/** @} */
