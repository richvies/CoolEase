/**
 ******************************************************************************
 * @file    sim.c
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   Sim Source File
 *  
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "hub/sim.h"

#include <string.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/cm3/nvic.h>

#include "common/aes.h"
#include "common/board_defs.h"
#include "common/bootloader_utils.h"
#include "common/log.h"
#include "common/memory.h"
#include "common/printf.h"
#include "common/timers.h"

/** @addtogroup SIM_FILE 
 * @{
 */

// Sim Info Commands
#define ECHO_OFF			ATE0
#define ECHO_ON			 	ATE1
#define	PRODUCT_ID			ATI	  		// SIM800 R14.18
#define GET_CAPABILITIES 	AT+GCAP 	// +CGSM
#define GET_CMD_LIST		AT+CLIST

// Configuration
#define RESET_DEFUALT_CONFIG	ATZ
#define SET_FACTORY_CONFIG		AT&F
#define SET_FUNCTIONALOTY		AT+CFUN 	//1 = full, 4 = disable rf, 0 = minimum
#define SLOW_CLOCK				AT+CSCLK
#define SLEEP_MODE				AT+CSCLK=1
#define GET_TIMESTAMP			AT+CLTS
#define CHECK_SIM				AT+CSMINS
#define GET_NET_SURVEY			AT+CNETSCAN
#define SWITCH_ON_EDGE			AT+CEGPRS
#define POWER_OFF				AT+CPOWD=1

// Network
#define GET_OPERATORS    	AT+COPS
#define PREFFERED_OPS  		AT+CPOL
#define NETWORK_REG			AT+CREG
#define SIGNAL_QUALITY		AT+CSQ
#define HTTP_ENABLE_SSL		AT+HTTPSSL=1



/** @addtogroup SIM_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

#define SIM_BUFFER_SIZE 64U

static char		sim_rx_buf[SIM_BUFFER_SIZE];
static char		sim_tx_buf[SIM_BUFFER_SIZE];
static uint8_t 	sim_rx_head, sim_rx_tail;
static uint8_t 	sim_tx_head, sim_tx_tail;

static char		last_reply[SIM_BUFFER_SIZE];

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void usart_setup(void);
static void _putchar(char character);

// internal test if char is a digit (0-9)
// \return true if char is a digit
static inline bool _is_digit(char ch);

// internal ASCII string to uint32_t conversion
static uint32_t _atoi(const char **str);


/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void sim_init(void)
{
	log_printf("Sim Init\n");

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

    usart_setup();

    gpio_mode_setup(SIM_RESET_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SIM_RESET);
    gpio_set_output_options(SIM_RESET_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, SIM_RESET);
	gpio_clear(SIM_RESET_PORT, SIM_RESET);
	timers_delay_milliseconds(500);
	gpio_set(SIM_RESET_PORT, SIM_RESET);
	timers_delay_milliseconds(5000);

	sim_rx_head = 0; sim_rx_tail = 0;
	sim_tx_head = 0; sim_tx_tail = 0;

	memset(last_reply, 0, sizeof(last_reply));

	// Enable interrupt for RX/TX
	usart_enable_rx_interrupt(SIM_USART);
	// usart_enable_tx_interrupt(SIM_USART);
	nvic_enable_irq(SIM_USART_NVIC);
  	nvic_set_priority(SIM_USART_NVIC, 0);

	sim_printf("ate0\r\n");
	TIMEOUT(1000000, "SIM: ate0", 0, check_for_response("OK"), ;, ;);
	sim_printf("at+cfun=1\r\n");
	TIMEOUT(1000000, "SIM: at+cfun=1", 0, check_for_response("OK"), ;, ;);
	sim_printf("at+csclk=0\r\n");
	TIMEOUT(1000000, "SIM: at+csclk=0", 0, check_for_response("OK"), ;, ;);

	log_printf("Sim Init Done\n");
}

void sim_end(void)
{
	// sim_printf("at+cpowd=1\r\n");
	// TIMEOUT(5000000, "SIM: at+cpowd=1", 0, check_for_response("POWER DOWN"), ;);

	sim_printf("at+cfun=0\r\n");
	TIMEOUT(10000000, "SIM: at+cfun=0", 0, check_for_response("OK"), ;, ;);

	sim_printf("at+csclk=1\r\n");
	TIMEOUT(10000000, "SIM: at+csclk=1", 0, check_for_response("OK"), ;, ;);

	usart_disable(SIM_USART);
	rcc_periph_clock_disable(SIM_USART_RCC);

	log_printf("Sim End Done\n");
}

void sim_printf(const char* format, ...)
{	
	va_list va;
	va_start(va, format);
	fnprintf(_putchar, format, va);
  	va_end(va);
	
	while(!usart_get_flag(SIM_USART, USART_ISR_TC)) {__asm__("nop");}
}

bool check_for_response(char *str)
{
	bool found = false;

	static char check_buf[SIM_BUFFER_SIZE];
	static uint8_t check_idx = 0;
	
	// Go through RX Buf
	while( sim_rx_tail != sim_rx_head )
	{
		// Get next char from RX Buf
		char character = sim_rx_buf[sim_rx_tail];
		sim_rx_tail = (sim_rx_tail + 1) % SIM_BUFFER_SIZE;

		check_buf[check_idx] = character;
		check_idx = (check_idx + 1) % SIM_BUFFER_SIZE;

		// serial_printf("%c", character);

		// End of reply
		if(character == '\n')
		{
			// Null Terminate String
			check_buf[check_idx] = '\0';
			check_idx = (check_idx + 1) % SIM_BUFFER_SIZE;

			// Only bother copying reply if longer than 2 chars
			// SIM800 sometimes sends lots of \r\n only messages
			if(strlen(check_buf) > 2)
			{
				// Check for target substring
				if( strstr(check_buf, str) )
					found = true;

				#if DEBUG
				serial_printf("Check for response l%i %s\n", strlen(check_buf), check_buf);
				#endif

				// Copy into last reply buffer
				strcpy(last_reply, check_buf);
			}

			// Reset ckeck buf
			memset(check_buf, 0, sizeof(check_buf));
			check_idx = 0;
		}

		// Substring found
		if(found)
			return true;
	}
	
	// Substring not found
	return false;

}

void sim_serial_pass_through(void)
{	
	// Disable interrupts
	usart_disable_rx_interrupt(SIM_USART);
	usart_disable_tx_interrupt(SIM_USART);
	nvic_disable_irq(SIM_USART_NVIC);

    log_printf("Ready\n");

    while(1)
    {
		// serial_printf("hello %i %i\n", sim_tx_head, sim_tx_tail);

		// Data received from serial monitor
		// Append to sim tx buffer
        if(usart_get_flag(SPF_USART, USART_ISR_RXNE))
		{
			sim_tx_buf[sim_tx_head] = usart_recv(SPF_USART);
			sim_tx_head = (sim_tx_head + 1) % SIM_BUFFER_SIZE;
		}

		// Data received from sim
		// Pass to serial monitor
		// Sim baud is much slower than serial monitor
		// -> can pass straight from sim to monitor
        if(usart_get_flag(SIM_USART, USART_ISR_RXNE))
		{
            usart_send(SPF_USART, usart_recv(SIM_USART));
		}

		
		// Pass data to sim when ready
		// -> if sim usart transmit buffer empty
		if(usart_get_flag(SIM_USART, USART_ISR_TXE))
		{
			if ((SIM_BUFFER_SIZE + sim_tx_head - sim_tx_tail) % SIM_BUFFER_SIZE)
			{
				usart_send(SIM_USART, sim_tx_buf[sim_tx_tail]);
				sim_tx_tail = (sim_tx_tail + 1) % SIM_BUFFER_SIZE;
			}
		}
    }
}

bool sim_available(void)
{
	return (sim_rx_head != sim_rx_tail);
}

char sim_read(void)
{
	char tail = 0;
	if (sim_available())
	{
		tail = sim_rx_buf[sim_rx_tail];
		sim_rx_tail = (sim_rx_tail + 1) % SIM_BUFFER_SIZE;
	}

	return tail;
}


void sim_print_capabilities(void)
{
	sim_printf("at+gcap\r\n");
}

void sim_connect(void)
{
	sim_printf("at\r\n");
	TIMEOUT(10000000, "SIM: at", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+cfun=1\r\n");
	TIMEOUT(10000000, "SIM: at+cfun=1", 0, check_for_response("OK"), ;, ;);
	TIMEOUT(20000000, "SIM: SMS Ready", 0, check_for_response("SMS Ready"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+cpol=0,0,\"T-Mobile\"\r\n");
	// TIMEOUT(10000000, "at+cpol=0,0,\"T-Mobile\"", 0, check_for_response("OK"), ;, ;);

	sim_printf("at+creg=1\r\n");
	TIMEOUT(60000000, "SIM: at+creg=1", 0, check_for_response("+CREG: 5"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+creg=0\r\n");
	TIMEOUT(60000000, "SIM: at+creg=0", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+cops=?\r\n");
	// TIMEOUT(60000000, "at+cops=?", 0, check_for_response("OK"), ;, ;);
	// timers_delay_milliseconds(100);
}

void sim_send_data(uint8_t *data, uint8_t len)
{
	sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	TIMEOUT(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httpinit\r\n");
	TIMEOUT(1000000, "SIM: at+httpinit", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httppara=cid,1\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=cid,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=");
	for(uint8_t i = 0; i < len; i++){ sim_printf("%02X", data[i]); }
	sim_printf("N\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+httppara=url,www.google.com\r\n");
	// timers_delay_milliseconds(100);

	sim_printf("at+sapbr=1,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=1,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpaction=0\r\n");
	TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_for_response("OK"), ;, ;);
	TIMEOUT(60000000, "SIM: at+httpaction=0", 0, check_for_response("+HTTPACTION"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpread\r\n");
	TIMEOUT(2000000, "SIM: at+httpread", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpterm\r\n");
	TIMEOUT(1000000, "SIM: at+httpterm", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=0,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=0,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
}

bool sim_get_bin(void)
{
	sim_connect();

	uint32_t file_size = 0;

	sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	TIMEOUT(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httpinit\r\n");
	TIMEOUT(1000000, "SIM: at+httpinit", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httppara=cid,1\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=cid,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httppara=url,http://cooleasetest.000webhostapp.com/hub.bin\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=url,http://cooleasetest.000webhostapp.com/hub.bin", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=1,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=1,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpaction=0\r\n");
	TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_for_response("OK"), ;, ;);
	TIMEOUT( 60000000, "SIM: at+httpaction=0", 0, check_for_response("+HTTPACTION"), 
			if(_is_digit(last_reply[19])) 
			{
				char *ptr = &last_reply[19];
				file_size = _atoi((const char **)&ptr);
			}, );
	
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=0,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=0,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	serial_printf("Filesize %i\n", file_size);

	if (file_size)
	{
		// Todo: make sure num pages is an even integer, otherwise will program garbage at end
		uint16_t num_half_pages = ( file_size / (FLASH_PAGE_SIZE / 2) ) + 1;

		serial_printf("Num half pages %i\n", num_half_pages);

		// Get data and program
		for(uint16_t n = 0; n < num_half_pages; n++)
		{
			serial_printf("------------------------------\n");
			serial_printf("-----------Half Page %i-------\n", n);
			serial_printf("------------------------------\n");

			// Half page buffer
			// Using union so that data can be read from as bytes and programmed as u32
			// this automatically deals with endianness
			union
			{
				uint8_t buf8[64];
				uint32_t buf32[16];
			}half_page;

			// HTTPREAD command and get number of bytes read
			// Number may be less than half page depending on how many are left in bin file
			// SIM800 signifies how many bytes are returned
			uint8_t num_bytes = 0;
			sim_printf("at+httpread=%i,%i\r\n", (n * FLASH_PAGE_SIZE / 2), (FLASH_PAGE_SIZE / 2) );
			TIMEOUT(2000000, "SIM: at+httpread", 0, check_for_response("+HTTPREAD"),
					if(_is_digit(last_reply[11])) 
					{
						char *ptr = &last_reply[11];
						num_bytes = _atoi((const char **)&ptr);
					}, );

			// SIM800 now returns that number of bytes
			for (uint8_t i = 0; i < num_bytes; i++)
			{
				while(!sim_available()){};
				half_page.buf8[i] = (uint8_t)sim_read();
			}
			// Wait for final ok reply
			TIMEOUT(20000000, "SIM: at+httpread", 0, check_for_response("OK"), ;, ;);

			// Print out for debugging
			serial_printf("Got half page %8x\n", (n * FLASH_PAGE_SIZE / 2));
			// for (uint8_t i = 0; i < num_bytes; i++)
			// {
			// 	if(!(i % 4))
			// 	{
			// 		// Print 32 bit version every 4 bytes
			// 		serial_printf("\n%8x\n", half_page.buf32[(i / 4)]);
			// 	}
			// 	serial_printf("%2x ", half_page.buf8[i]);
			// }

			serial_printf("\nHalf page Done\nProgramming\n");

			// Program half page
			static bool lower = true;
			uint32_t crc = boot_get_half_page_checksum(half_page.buf32);
			if(boot_program_half_page(lower, crc, n / 2, half_page.buf32))
			{
				serial_printf("Programming success\n");
			}
			else
			{
				serial_printf("Programming Fail\n");
			}
			
			lower = !lower;
		}
		serial_printf("Programming Done\n\n");
	}

	// sim_serial_pass_through();

	sim_printf("at+httpterm\r\n");
	TIMEOUT(1000000, "SIM: at+httpterm", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_end();

	boot_jump_to_application(FLASH_APP_ADDRESS);

	return true;
}

// Send Temperature
/*
void sim_send_temp(rfm_packet_t *packets,  uint8_t len)
{
	// sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_for_response("OK"), ;, ;);
	
	// sim_printf("at+httpinit\r\n");
	// TIMEOUT(10000000, "SIM: at+httpinit", 0, check_for_response("OK"), ;, ;);
	
	// sim_printf("at+httppara=cid,1\r\n");
	// TIMEOUT(10000000, "SIM: at+httppara=cid,1", 0, check_for_response("OK"), ;, ;);
	
	// // sim_printf("at+httppara=url,www.circuitboardsamurai.com/upload.php?s=%08x", mem_get_dev_num());
	// for(uint8_t i = 0; i < len; i++){ sim_printf("%08X%04hX%04hX", ids[i], temps[i], battery[i]); }
	// sim_printf("N\r\n");
	// TIMEOUT(10000000, "SIM: at+httppara=url,www.circuitboardsamurai.com/upload.php?s=", 0, check_for_response("OK"), ;, ;);
	
	// sim_printf("at+sapbr=1,1\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=1,1", 0, check_for_response("OK"), ;, timers_delay_milliseconds(1000);sim_printf("at+sapbr=1,1\r\n");log_printf("else code\n"););
	
	// sim_printf("at+httpaction=0\r\n");
	// TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_for_response("OK"), ;, timers_delay_milliseconds(1000);sim_printf("at+httpaction=0\r\n");log_printf("else code\n"););
	// TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_for_response("+HTTPACTION"), ;, ;);

	// sim_printf("at+httpread\r\n");
	// TIMEOUT(10000000, "SIM: at+httpread", 0, check_for_response("OK"), ;, ;);
	
	// sim_printf("at+httpterm\r\n");
	// TIMEOUT(10000000, "SIM: at+httpterm", 0, check_for_response("OK"), ;, ;);
	
	// sim_printf("at+sapbr=0,1\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=0,1", 0, check_for_response("OK"), ;, ;);
}

void sim_send_temp_and_num(rfm_packet_t *packets,  uint8_t len)
{
	sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	TIMEOUT(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httpinit\r\n");
	TIMEOUT(1000000, "SIM: at+httpinit", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httppara=cid,1\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=cid,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httppara=url,www.circuitboardsamurai.com/upload_save_all.php?s=%08X", mem_get_dev_num());
	for(uint8_t i = 0; i < len; i++){ sim_printf("%08X%04hX%04hX%08X%08X%04hX", packets[i].device_number, packets[i].temperature, packets[i].battery, total_packets[i], ok_packets[i], packets[i].rssi); }
	sim_printf("N\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=url,www.circuitboardsamurai.com/upload.php?s=", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=1,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=1,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpaction=0\r\n");
	TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_for_response("OK"), ;, ;);
	TIMEOUT(60000000, "SIM: at+httpaction=0", 0, check_for_response("+HTTPACTION"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpread\r\n");
	TIMEOUT(2000000, "SIM: at+httpread", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpterm\r\n");
	TIMEOUT(1000000, "SIM: at+httpterm", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=0,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=0,1", 0, check_for_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
}
*/


/** @} */

/** @addtogroup SIM_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void usart_setup(void) 
{
	rcc_periph_clock_enable(SIM_USART_RCC);

	gpio_mode_setup(SIM_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SIM_USART_TX);
	gpio_mode_setup(SIM_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, SIM_USART_RX);
    
    gpio_set_output_options(SIM_USART_TX_PORT, GPIO_PUPD_PULLUP, GPIO_OSPEED_2MHZ, SIM_USART_TX);

    gpio_set_af(SIM_USART_TX_PORT, SIM_USART_AF, SIM_USART_TX);
    gpio_set_af(SIM_USART_RX_PORT, SIM_USART_AF, SIM_USART_RX);
    
    rcc_periph_reset_pulse(SIM_USART_RCC_RST);
	usart_disable(SIM_USART);
	usart_set_baudrate(SIM_USART, SIM_USART_BAUD);
	usart_set_databits(SIM_USART, 8);
	usart_set_stopbits(SIM_USART,USART_STOPBITS_1);
	usart_set_mode(SIM_USART, USART_MODE_TX_RX);
	usart_set_parity(SIM_USART, USART_PARITY_NONE);
	usart_set_flow_control(SIM_USART, USART_FLOWCONTROL_NONE);
	usart_enable(SIM_USART);
}

static void _putchar(char character)
{
	usart_send_blocking(SIM_USART, character);

	#if DEBUG
	usart_send_blocking(SPF_USART, character);	
	#endif
}

static inline bool _is_digit(char ch)
{
    return (ch >= '0') && (ch <= '9');
}

static uint32_t _atoi(const char **str)
{
    uint32_t i = 0U;
    while (_is_digit(**str))
    {
        i = i * 10U + (uint32_t)(*((*str)++) - '0');
    }
    return i;
}

/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Interrupts
/*////////////////////////////////////////////////////////////////////////////*/

void usart2_isr(void)
{
	// serial_printf("Sim ISR: %8x\n", USART2_ISR);

	// Received data from sim
	// Read data (clears flag automatically)
	if (usart_get_flag(SIM_USART, USART_ISR_RXNE))
	{
		sim_rx_buf[sim_rx_head] = usart_recv(SIM_USART);
		sim_rx_head = (sim_rx_head + 1) % SIM_BUFFER_SIZE;
		#if DEBUG
		// usart_send(SPF_USART, usart_recv(SIM_USART));
		#endif
	}

	// Transmit buffer empty
	// Fill it (clears flag automatically)
	if(usart_get_flag(SIM_USART, USART_ISR_TXE))
	{
		// Fill it if data waiting
		if ((SIM_BUFFER_SIZE + sim_tx_head - sim_tx_tail) % SIM_BUFFER_SIZE)
		{
			usart_send(SIM_USART, sim_tx_buf[sim_tx_tail]);
			sim_tx_tail = (sim_tx_tail + 1) % SIM_BUFFER_SIZE;
		}
	}
}

/** @} */
/** @} */
