#include "hub/sim.h"

#include <string.h>
#include <stdbool.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/cm3/nvic.h>

#include "common/board_defs.h"
#include "common/printf.h"
#include "common/log.h"
#include "common/timers.h"
#include "common/aes.h"

char 	sim_rx_buf[256];
uint8_t sim_rx_head, sim_rx_tail;

char	msg[256];
uint8_t	msg_idx;

// Static Function Decls
static void clock_setup(void);
static void usart_setup(void);
static void _putchar(char character, void* buffer, size_t idx, size_t maxlen);


// Global Function Definitions
void sim_init(void)
{
	log_printf(MAIN, "Sim Init\n");

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);

    clock_setup();
    usart_setup();

    gpio_mode_setup(SIM_RESET_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SIM_RESET);
    gpio_set_output_options(SIM_RESET_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, SIM_RESET);
	gpio_clear(SIM_RESET_PORT, SIM_RESET);
	timers_delay_milliseconds(500);
	gpio_set(SIM_RESET_PORT, SIM_RESET);
	timers_delay_milliseconds(5000);

	sim_rx_head = 0;
	sim_rx_tail = 0;

	memset(msg, 0, 256);
	msg_idx = 0;

	sim_printf("ate0\r\n");
	TIMEOUT(1000000, "SIM: ate0", 0, check_response("OK"), ;, ;);

	log_printf(MAIN, "Sim Init Done\n");
}

void sim_end(void)
{
	// sim_printf("at+cpowd=1\r\n");
	// TIMEOUT(5000000, "SIM: at+cpowd=1", 0, check_response("POWER DOWN"), ;);

	sim_printf("at+cfun=4\r\n");
	TIMEOUT(10000000, "SIM: at+cfun=4", 0, check_response("OK"), ;, ;);

	sim_printf("at+csclk=1\r\n");
	TIMEOUT(10000000, "SIM: at+csclk=1", 0, check_response("OK"), ;, ;);

	usart_disable(SIM_USART);
	rcc_periph_clock_disable(SIM_USART_RCC);

	log_printf(MAIN, "Sim End Done\n");
}


void sim_connect(void)
{
	sim_printf("at\r\n");
	TIMEOUT(10000000, "SIM: at", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+cfun=1\r\n");
	TIMEOUT(10000000, "SIM: at+cfun=1", 0, check_response("OK"), ;, ;);
	TIMEOUT(20000000, "SIM: SMS Ready", 0, check_response("SMS Ready"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+cpol=0,0,\"T-Mobile\"\r\n");
	// TIMEOUT(10000000, "at+cpol=0,0,\"T-Mobile\"", 0, check_response("OK"), ;, ;);

	sim_printf("at+creg=1\r\n");
	TIMEOUT(60000000, "SIM: at+creg=1", 0, check_response("+CREG: 5"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+creg=0\r\n");
	TIMEOUT(60000000, "SIM: at+creg=0", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+cops=?\r\n");
	// TIMEOUT(60000000, "at+cops=?", 0, check_response("OK"), ;, ;);
	// timers_delay_milliseconds(100);
}

/*
void sim_send_temp(rfm_packet_t *packets,  uint8_t len)
{
	// sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_response("OK"), ;, ;);
	
	// sim_printf("at+httpinit\r\n");
	// TIMEOUT(10000000, "SIM: at+httpinit", 0, check_response("OK"), ;, ;);
	
	// sim_printf("at+httppara=cid,1\r\n");
	// TIMEOUT(10000000, "SIM: at+httppara=cid,1", 0, check_response("OK"), ;, ;);
	
	// // sim_printf("at+httppara=url,www.circuitboardsamurai.com/upload.php?s=%08x", mem_get_dev_num());
	// for(uint8_t i = 0; i < len; i++){ sim_printf("%08X%04hX%04hX", ids[i], temps[i], battery[i]); }
	// sim_printf("N\r\n");
	// TIMEOUT(10000000, "SIM: at+httppara=url,www.circuitboardsamurai.com/upload.php?s=", 0, check_response("OK"), ;, ;);
	
	// sim_printf("at+sapbr=1,1\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=1,1", 0, check_response("OK"), ;, timers_delay_milliseconds(1000);sim_printf("at+sapbr=1,1\r\n");log_printf(MAIN, "else code\n"););
	
	// sim_printf("at+httpaction=0\r\n");
	// TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_response("OK"), ;, timers_delay_milliseconds(1000);sim_printf("at+httpaction=0\r\n");log_printf(MAIN, "else code\n"););
	// TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_response("+HTTPACTION"), ;, ;);

	// sim_printf("at+httpread\r\n");
	// TIMEOUT(10000000, "SIM: at+httpread", 0, check_response("OK"), ;, ;);
	
	// sim_printf("at+httpterm\r\n");
	// TIMEOUT(10000000, "SIM: at+httpterm", 0, check_response("OK"), ;, ;);
	
	// sim_printf("at+sapbr=0,1\r\n");
	// TIMEOUT(10000000, "SIM: at+sapbr=0,1", 0, check_response("OK"), ;, ;);
}

void sim_send_temp_and_num(rfm_packet_t *packets,  uint8_t len)
{
	sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	TIMEOUT(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httpinit\r\n");
	TIMEOUT(1000000, "SIM: at+httpinit", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httppara=cid,1\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=cid,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httppara=url,www.circuitboardsamurai.com/upload_save_all.php?s=%08X", mem_get_dev_num());
	for(uint8_t i = 0; i < len; i++){ sim_printf("%08X%04hX%04hX%08X%08X%04hX", packets[i].device_number, packets[i].temperature, packets[i].battery, total_packets[i], ok_packets[i], packets[i].rssi); }
	sim_printf("N\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=url,www.circuitboardsamurai.com/upload.php?s=", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=1,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=1,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpaction=0\r\n");
	TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_response("OK"), ;, ;);
	TIMEOUT(60000000, "SIM: at+httpaction=0", 0, check_response("+HTTPACTION"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpread\r\n");
	TIMEOUT(2000000, "SIM: at+httpread", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpterm\r\n");
	TIMEOUT(1000000, "SIM: at+httpterm", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=0,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=0,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
}
*/

void sim_send_data(uint8_t *data, uint8_t len)
{
	sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
	TIMEOUT(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httpinit\r\n");
	TIMEOUT(1000000, "SIM: at+httpinit", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
	
	sim_printf("at+httppara=cid,1\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=cid,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=");
	for(uint8_t i = 0; i < len; i++){ sim_printf("%02X", data[i]); }
	sim_printf("N\r\n");
	TIMEOUT(1000000, "SIM: at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	// sim_printf("at+httppara=url,www.google.com\r\n");
	// timers_delay_milliseconds(100);

	sim_printf("at+sapbr=1,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=1,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpaction=0\r\n");
	TIMEOUT(20000000, "SIM: at+httpaction=0", 0, check_response("OK"), ;, ;);
	TIMEOUT(60000000, "SIM: at+httpaction=0", 0, check_response("+HTTPACTION"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpread\r\n");
	TIMEOUT(2000000, "SIM: at+httpread", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+httpterm\r\n");
	TIMEOUT(1000000, "SIM: at+httpterm", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);

	sim_printf("at+sapbr=0,1\r\n");
	TIMEOUT(60000000, "SIM: at+sapbr=0,1", 0, check_response("OK"), ;, ;);
	timers_delay_milliseconds(100);
}

bool check_response(char *str)
{
	bool found = false;
	
	// Go through RX Buf
	while( sim_rx_tail != sim_rx_head )
	{
		// Get next char from RX Buf
		char character = sim_rx_buf[sim_rx_tail++];
		msg[msg_idx++] = character;

		// log_printf(MAIN, "%c", character);

		// End of message
		if(character == '\n')
		{
			// Null Terminate String
			msg[msg_idx++] = '\0';

			// Check for target substring
			if( strstr(msg, str) )
				found = true;
			
			// Reset Message Buf
			memset(msg, 0, 256);
			msg_idx = 0;
		}

		// Substring found
		if(found)
			return true;
	}
	
	// Substring not found
	return false;

}


int sim_printf(const char* format, ...)
{	
	char buffer[1];

	va_list va;
	va_start(va, format);
  	const int ret = _vsnprintf(_putchar, buffer, (size_t)-1, format, va);
  	va_end(va);
	
	while(!usart_get_flag(SIM_USART, USART_ISR_TC)) {__asm__("nop");}

	return ret;
}

static void _putchar(char character, void* buffer, size_t idx, size_t maxlen)
{
	(void)buffer; (void)idx; (void)maxlen;
	usart_send_blocking(SIM_USART, character);
	usart_send_blocking(SPF_USART, character);	
}


void sim_serial_pass_through(void)
{
	// Disable interrupt for RX
	usart_disable_rx_interrupt(SIM_USART);
	nvic_disable_irq(NVIC_USART1_IRQ);

    sim_init();

    log_printf(MAIN, "Ready\n");

    while(1)
    {
        if(usart_get_flag(SIM_USART, USART_ISR_RXNE))
            usart_send(SPF_USART, usart_recv(SIM_USART));

        if(usart_get_flag(SPF_USART, USART_ISR_RXNE))
            usart_send(SIM_USART, usart_recv(SPF_USART));
    }
}


// Static Function Definitions
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

	// Enable interrupt for RX
	usart_enable_rx_interrupt(SIM_USART);
	nvic_enable_irq(SIM_USART_NVIC);
  	nvic_set_priority(SIM_USART_NVIC, 0);
}


// Interrupt routines
void usart2_isr(void)
{
	usart_send(SPF_USART, usart_recv(SIM_USART));

	sim_rx_buf[sim_rx_head++] = usart_recv(SIM_USART);
}
