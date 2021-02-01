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
#include <libopencm3/cm3/cortex.h>

#include "common/board_defs.h"
#include "common/log.h"
#include "common/memory.h"
#include "common/timers.h"
#include "common/printf.h"

/** @addtogroup SIM_FILE 
 * @{
 */

#define PRINT_ERROR(cmd, err)   \
	serial_printf("SIM ERR: "); \
	serial_printf(#cmd);        \
	serial_printf(" ");         \
	serial_printf(#err);        \
	serial_printf("\n")

// Info Commands
#define PRODUCT_ID ATI			   // SIM800 R14.18
#define GET_CAPABILITIES AT + GCAP // +CGSM
#define GET_CMD_LIST AT + CLIST
#define CHECK_SIM AT + CSMINS
#define GET_TIMESTAMP AT + CLTS

// Configuration
#define SELECT_CHAR_SET AT + CSCS // *IRA/ GSM/ HEX
#define ECHO_OFF ATE0
#define ECHO_ON ATE1
#define SET_FUNCTIONALOTY AT + CFUN //1 = full, 4 = disable rf, 0 = minimum
#define SLOW_CLOCK AT + CSCLK
#define SLEEP_MODE AT + CSCLK = 1
#define POWER_OFF AT + CPOWD = 1 // Always turns back on automatically for some reason
#define SET_FACTORY_CONFIG AT &F
#define RESET_DEFUALT_CONFIG ATZ
#define SWITCH_ON_EDGE AT + CEGPRS

// Network
#define GET_OPERATORS AT + COPS
#define PREFFERED_OPS AT + CPOL
#define NETWORK_REG AT + CREG
#define SIGNAL_QUALITY AT + CSQ
#define GET_NET_SURVEY AT + CNETSCAN

// HTTP
#define HTTP_ENABLE_SSL AT + HTTPSSL = 1

/** @addtogroup SIM_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

enum
{
	OFF = 0,
	RESET,
	SLEEP,
	MIN_FUNCTION,
	FULL_FUNCTION
} function;

enum
{
	NONE = 0,
	HOME,
	SEARCHING,
	DENIED,
	UNKNOWN,
	ROAMING
} registration_status;

enum
{
	HTTP_TERM = 0,
	HTTP_INIT,
	HTTP_ACTION,
	HTTP_DONE
} http_state;

#define SIM_BUFFER_SIZE 64U

static char sim_rx_buf[SIM_BUFFER_SIZE];
static char sim_tx_buf[SIM_BUFFER_SIZE];
static uint8_t sim_tx_head = 0;
static uint8_t sim_tx_tail = 0;
static uint8_t sim_rx_head = 0;
static uint8_t sim_rx_tail = 0;
static bool sim_rx_overflow = false;
static uint32_t rx_timeout = 0;

static char last_reply[SIM_BUFFER_SIZE];
static char timestamp[18];

static const char base_url_str[] = "http://cooleasetest.000webhostapp.com/";

static uint32_t _timer = 0;
static uint32_t _timeout_ms = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void reset(void);

static void usart_setup(void);
static void _putchar(char character);

/** @brief Internal test if char is a digit (0-9) */
static inline bool _is_digit(char ch);

/** @brief internal ASCII string to uint32_t conversion */
static uint32_t _atoi(const char **str);

/** @brief Check all unread received characters for ceratin response 
 * 
 * Adds received chars to temporary buffer until  received
 * Then appends a \0 and checks if message contains expected response
 * If expected is found then stores response in last_reply buffer
 */
static bool check_response(const char *expected_response);

/** @brief Wait until correct response received or timeout 
 * 
 * Check response + timeout
 */
static bool wait_and_check_response(uint32_t timeout_ms, const char *expected_response);

/** @brief Repeatedly send AT command until SIM autbauding kicks in i.e. "OK" received
 * 
 * Recommended pg.29 SIM800_Hardware Design_V1.10.pdf
 * 100ms timeout for each attempt
 * 
 */
static sim_state_t try_autobaud(void);
static sim_state_t disable_echo(void);
static sim_state_t enable_local_timestamp(void);
static sim_state_t enable_full_function(void);

/** @brief Wrapper for SAPBR=1,1 command 
 * 
 * Adds delay of 1 second after opening bearer to prevent issues with next command coming to quickly 
 * Issue mainly with calling httpaction
 */
static bool open_bearer(void);

static void timeout_init(uint32_t new_timeout_ms);

static bool timeout(void);

/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Setup & Communication
/*////////////////////////////////////////////////////////////////////////////*/

sim_state_t sim_init(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		log_printf("Sim Init\n");
		reset();
		state++;
		break;
	case 1:
		res = try_autobaud();
		if (res == SIM_SUCCESS)
		{
			res = SIM_BUSY;
			state++;
		}
		break;
	case 2:
		res = disable_echo();
		if (res == SIM_SUCCESS)
		{
			res = SIM_BUSY;
			state++;
		}
		break;
	case 3:
		res = enable_local_timestamp();
		if (res == SIM_SUCCESS)
		{
			res = SIM_BUSY;
			state++;
		}
		break;
	case 4:
		res = enable_full_function();
		if (res == SIM_SUCCESS)
		{
			function = FULL_FUNCTION;
			res = SIM_BUSY;
			state++;
		}
		break;
	case 5:
		res = SIM_SUCCESS;
		break;
	default:
		state = 0;
		res = SIM_ERROR;
		break;
	}

	return res;
}

static void reset(void)
{
	function = OFF;

	// Setup USART
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	usart_setup();

	timers_delay_milliseconds(1000);

	// Enable interrupts for RX/TX
	usart_enable_rx_interrupt(SIM_USART);
	// usart_enable_tx_interrupt(SIM_USART);
	nvic_enable_irq(SIM_USART_NVIC);
	nvic_set_priority(SIM_USART_NVIC, IRQ_PRIORITY_SIM);

	// Reset SIM800
	gpio_mode_setup(SIM_RESET_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SIM_RESET);
	gpio_set_output_options(SIM_RESET_PORT, GPIO_OTYPE_OD, GPIO_OSPEED_2MHZ, SIM_RESET);
	gpio_clear(SIM_RESET_PORT, SIM_RESET);
	timers_delay_milliseconds(500);
	gpio_set(SIM_RESET_PORT, SIM_RESET);

	// Init RX, TX & Reply Buffers
	sim_rx_head = sim_rx_tail = sim_tx_head = sim_tx_tail = 0;
	memset(last_reply, 0, sizeof(last_reply));

	function = RESET;
	registration_status = NONE;
	http_state = HTTP_TERM;
}

bool sim_set_full_function(void)
{
	log_printf("Sim Set FF\n");

	bool result = false;

	if (function == FULL_FUNCTION)
	{
		result = true;
	}
	else
	{
		// Reset sim if off or in sleep mode
		// Currently no connection to DTR so only way to get sim out of sleep is to reset
		if (function == OFF || function == SLEEP)
		{
			if (!sim_init())
			{
				log_error(ERR_SIM_INIT);
			}
		}
		// Set full functionality
		if (!sim_printf_and_check_response(10000, "OK", "AT+CFUN=1\r"))
		{
			log_error(ERR_SIM_CFUN_1);
		}
		else
		{
			function = FULL_FUNCTION;
			result = true;
		}
	}

	return result;
}

bool sim_end(void)
{
	log_printf("Sim End\n");

	bool result = false;

	if (!sim_printf_and_check_response(5000, "OK", "AT+CFUN=0\r"))
	{
		serial_printf("ATCFUN0\n");
		log_error(ERR_SIM_CFUN_0);
	}
	else if (!sim_printf_and_check_response(5000, "OK", "AT+CFUN?\r"))
	{
		serial_printf("ATCFUN0\n");
		log_error(ERR_SIM_CFUN_0);
	}
	else if (!sim_printf_and_check_response(5000, "OK", "AT+CSCLK=1\r"))
	{
		log_error(ERR_SIM_CSCLK_1);
	}
	else
	{
		function = SLEEP;
		registration_status = NONE;
		result = true;
	}

	usart_disable(SIM_USART);
	rcc_periph_clock_disable(SIM_USART_RCC);

	return result;
}

void sim_printf(const char *format, ...)
{
	va_list va;
	va_start(va, format);
	fnprintf(_putchar, format, va);
	va_end(va);
	rx_timeout = timers_millis();
}

bool sim_printf_and_check_response(uint32_t timeout_ms, const char *expected_response, const char *format, ...)
{
	// Write to SIM800
	va_list va;
	va_start(va, format);
	fnprintf(_putchar, format, va);
	va_end(va);

	rx_timeout = timers_millis();

	return wait_and_check_response(timeout_ms, expected_response);
}

void sim_serial_pass_through(void)
{
	// Disable interrupts
	usart_disable_rx_interrupt(SIM_USART);
	usart_disable_tx_interrupt(SIM_USART);
	nvic_disable_irq(SIM_USART_NVIC);

	log_printf("Ready\n");

	while (1)
	{
		// serial_printf("hello %i %i\n", sim_tx_head, sim_tx_tail);

		// Data received from serial monitor
		// Append to sim tx buffer
		if (usart_get_flag(SPF_USART, USART_ISR_RXNE))
		{
			sim_tx_buf[sim_tx_head] = usart_recv(SPF_USART);
			sim_tx_head = (sim_tx_head + 1) % SIM_BUFFER_SIZE;
		}

		// Data received from sim
		// Pass to serial monitor
		// Sim baud is much slower than serial monitor
		// -> can pass straight from sim to monitor
		if (usart_get_flag(SIM_USART, USART_ISR_RXNE))
		{
			usart_send(SPF_USART, usart_recv(SIM_USART));
		}

		// Pass data to sim when ready
		// -> if sim usart transmit buffer empty
		if (usart_get_flag(SIM_USART, USART_ISR_TXE))
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

/*////////////////////////////////////////////////////////////////////////////*/
// Device information
/*////////////////////////////////////////////////////////////////////////////*/

void sim_print_capabilities(void)
{
	sim_printf("at+gcap");
}

/*////////////////////////////////////////////////////////////////////////////*/
// Network Configuration
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_register_to_network(void)
{
	bool result = false;

	// Try connect for (attemp * 2) seconds
	for (uint8_t attempt = 0; attempt < 30; attempt++)
	{
		// Query current registration status
		if (!sim_printf_and_check_response(1000, "+CREG", "AT+CREG?\r"))
		{
			log_error(ERR_SIM_CREG_QUERY);
		}
		// Parse response
		else
		{
			// Is registered, Home / Roaming
			if (last_reply[9] == '1' || last_reply[9] == '5')
			{
				result = true;
			}
			// Is searching, denied or unknown
			else if (last_reply[9] == '2' || last_reply[9] == '3' || last_reply[9] == '4')
			{
				result = false;
			}

			// Enum uses same values as in SIM800 AT cmds manual
			// Just need to convert from ascii to value
			registration_status = last_reply[9] - '0';

			// Break if registered succesfully or error
			if (registration_status == 1 || registration_status == 3 || registration_status == 4 || registration_status == 5)
			{
				break;
			}

			serial_printf("Register Attempt %i : %s\n", attempt, last_reply);
		}
		timers_delay_milliseconds(2000);
	}

	return result;
}

uint32_t sim_get_timestamp(void)
{
	if (!sim_printf_and_check_response(1000, "CCLK", "AT+CCLK?\r"))
	{
	}
	else
	{
		memcpy(timestamp, &last_reply[8], sizeof(timestamp) - 1);
		timestamp[sizeof(timestamp)] = '\0';
		serial_printf("Timestamp: %s\n", timestamp);
		wait_and_check_response(1000, "OK");
	}

	// uint32_t stamp = timestamp;

	return 0;
}

/*////////////////////////////////////////////////////////////////////////////*/
// Internet Access
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_tcp_init(const char *url_str, uint16_t port, bool ssl)
{
	if (!sim_printf_and_check_response(1000, "OK", "AT+CSTT=\"data.rewicom.net\",\"\",\"\"\r"))
	{
		log_error(ERR_SIM_SAPBR_CONFIG);
	}
	else if (!sim_printf_and_check_response(5000, "OK", "AT+CIICR\r"))
	{
		log_error(ERR_SIM_SAPBR_CONFIG);
	}
	else if (!sim_printf_and_check_response(1000, "10", "AT+CIFSR\r"))
	{
		log_error(ERR_SIM_SAPBR_CONFIG);
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+CIPSSL=%u\r", (ssl ? 1 : 0)))
	{
		log_error(ERR_SIM_HTTPINIT);
	}
	else if (!sim_printf_and_check_response(10000, "CONNECT OK", "AT+CIPSTART=\"TCP\",\"%s\",%u\r", url_str, port))
	{
		log_error(ERR_SIM_HTTPPARA_CID);
	}
	else
	{
		// sim_serial_pass_through();
		sim_printf("AT+CIPSEND\r\n");
		timers_delay_milliseconds(500);
		return true;
	}

	return false;
}

bool sim_http_init(const char *url_str)
{
	// Terminate any old http stack
	if (http_state != HTTP_TERM)
	{
		if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPTERM\r"))
		{
			log_error(ERR_SIM_HTTP_TERM);
			return 0;
		}
		else
		{
			http_state = HTTP_TERM;
		}
	}

	if (!sim_printf_and_check_response(1000, "OK", "AT+SAPBR=3,1,\"APN\",\"data.rewicom.net\"\r"))
	{
		log_error(ERR_SIM_SAPBR_CONFIG);
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPINIT\r"))
	{
		log_error(ERR_SIM_HTTPINIT);
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPPARA=\"CID\",\"1\"\r"))
	{
		log_error(ERR_SIM_HTTPPARA_CID);
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPPARA=\"URL\",\"%s\"\r", url_str))
	{
		log_error(ERR_SIM_HTTPPARA_URL);
	}
	else
	{
		return true;
	}

	http_state = HTTP_INIT;

	return false;
}

bool sim_http_term(void)
{
	bool result = false;

	if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPTERM\r"))
	{
		log_error(ERR_SIM_HTTPTERM);
	}
	else
	{
		http_state = HTTP_TERM;
		result = true;
	}

	return result;
}

bool sim_http_enable_ssl(void)
{
	return sim_printf_and_check_response(1000, "OK", "AT+HTTPSSL=1\r");
}

bool sim_http_disable_ssl(void)
{
	return sim_printf_and_check_response(1000, "OK", "AT+HTTPSSL=0\r");
}

uint32_t sim_http_get(const char *url_str)
{
	uint32_t file_size = 0;

	if (!sim_http_init(url_str))
	{
	}
	else if (!sim_http_disable_ssl())
	{
		log_error(ERR_SIM_HTTPSSL);
	}
	else if (!open_bearer())
	{
		log_error(ERR_SIM_SAPBR_CONNECT);
	}
	else if (!sim_printf_and_check_response(10000, "OK", "AT+HTTPACTION=0\r"))
	{
		http_state = HTTP_ACTION;
		log_error(ERR_SIM_HTTPACTION_0);
	}
	// Wait for download
	else if (!wait_and_check_response(120000, "+HTTPACTION"))
	{
		log_error(ERR_SIM_HTTP_GET_TIMEOUT);
	}
	// All good, get length of response
	else
	{
		// Status code
		char *ptr = &last_reply[15];
		uint16_t status_code = _atoi((const char **)&ptr);

		if (status_code == 200)
		{
			// Response length
			if (_is_digit(last_reply[19]))
			{
				ptr = &last_reply[19];
				file_size = _atoi((const char **)&ptr);
			}
		}
		else
		{
			log_printf("HTTP Stat: %u\n", status_code);
		}

		if (!sim_printf_and_check_response(60000, "OK", "AT+SAPBR=0,1\r"))
		{
			log_error(ERR_SIM_SAPBR_DISCONNECT);
		}
	}

	http_state = HTTP_DONE;

	return file_size;
}

uint32_t sim_https_get(const char *url_str)
{
	uint32_t file_size = 0;

	if (!sim_http_init(url_str))
	{
	}
	else if (!sim_http_enable_ssl())
	{
		log_error(ERR_SIM_HTTPSSL);
	}
	else if (!open_bearer())
	{
		log_error(ERR_SIM_SAPBR_CONNECT);
	}
	else if (!sim_printf_and_check_response(10000, "OK", "AT+HTTPACTION=0\r"))
	{
		http_state = HTTP_ACTION;
		log_error(ERR_SIM_HTTPACTION_0);
	}
	// Wait for download
	else if (!wait_and_check_response(120000, "+HTTPACTION"))
	{
		log_error(ERR_SIM_HTTP_GET_TIMEOUT);
	}
	// All good, get length of response
	else
	{
		// Status code
		char *ptr = &last_reply[15];
		uint16_t status_code = _atoi((const char **)&ptr);

		if (status_code == 200)
		{
			// Response length
			if (_is_digit(last_reply[19]))
			{
				ptr = &last_reply[19];
				file_size = _atoi((const char **)&ptr);
			}
		}
		else
		{
			log_printf("HTTP Stat: %u\n", status_code);
		}

		if (!sim_printf_and_check_response(60000, "OK", "AT+SAPBR=0,1\r"))
		{
			log_error(ERR_SIM_SAPBR_DISCONNECT);
		}
	}

	http_state = HTTP_DONE;

	return file_size;
}

uint32_t sim_http_read_response(uint32_t address, uint32_t num_bytes)
{
	uint32_t num_ret = 0;

	// Request num_bytes of data
	if (!sim_printf_and_check_response(2000, "+HTTPREAD", "AT+HTTPREAD=%u,%u\r", address, num_bytes))
	{
		log_error(ERR_SIM_HTTP_READ_TIMEOUT);
	}
	else
	{
		// Get actual number of bytes returned
		if (_is_digit(last_reply[11]))
		{
			char *ptr = &last_reply[11];
			num_ret = _atoi((const char **)&ptr);
		}
	}

	return num_ret;
}

bool sim_http_post_init(const char *url_str, uint16_t len, uint16_t ms)
{
	if (!sim_http_init(url_str))
	{
	}
	else if (!sim_http_enable_ssl())
	{
		log_error(ERR_SIM_HTTPSSL);
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+HTTPPARA=\"CONTENT\",\"application/x-www-form-urlencoded\"\r"))
	{
		log_error(ERR_SIM_HTTP_CONTENT);
	}
	else if (!sim_printf_and_check_response(2000, "DOWNLOAD", "AT+HTTPDATA=%u,%u\r", len, ms))
	{
	}
	else
	{
		return true;
	}

	return false;
}

uint32_t sim_http_post(uint8_t num_tries)
{
	uint32_t file_size = 0;

	if (!open_bearer())
	{
		log_error(ERR_SIM_SAPBR_CONNECT);
	}
	else
	{
		for (uint8_t i = 0; i < num_tries; i++)
		{

			if (!sim_printf_and_check_response(10000, "OK", "AT+HTTPACTION=1\r"))
			{
				http_state = HTTP_ACTION;
				log_error(ERR_SIM_HTTPACTION_1);
			}
			// Wait for download
			else if (!wait_and_check_response(120000, "+HTTPACTION"))
			{
				log_error(ERR_SIM_HTTP_POST_TIMEOUT);
			}
			// All good, get length of response
			else
			{
				// Status code
				char *ptr = &last_reply[15];
				uint16_t status_code = _atoi((const char **)&ptr);

				if (status_code == 200)
				{
					// Response length
					if (_is_digit(last_reply[19]))
					{
						ptr = &last_reply[19];
						file_size = _atoi((const char **)&ptr);
					}
					break;
				}
				else
				{
					log_printf("HTTP Stat: %u\n", status_code);
				}
			}
		}
	}

	if (!sim_printf_and_check_response(60000, "OK", "AT+SAPBR=0,1\r"))
	{
		log_error(ERR_SIM_SAPBR_DISCONNECT);
	}

	return file_size;
}

uint32_t sim_http_post_str(const char *url_str, const char *str, uint8_t num_tries)
{
	uint32_t len = strlen(str);

	uint32_t resp_len = 0;

	if (!sim_http_post_init(url_str, len, 10000))
	{
	}
	else if (!sim_printf_and_check_response(11000, "OK", "%s", str))
	{
	}
	else
	{
		resp_len = sim_http_post(num_tries);
	}

	return resp_len;
}

bool sim_send_data(uint8_t *data, uint8_t data_len)
{
	bool result = false;

	char url_str[sizeof(base_url_str) + 3 + data_len];

	strcpy(url_str, base_url_str);
	strcat(url_str, "?s=");

	uint16_t url_len = strlen(url_str);
	uint16_t i = 0;

	// serial_printf("%s %i %i\n",url_str, url_len, sizeof(url_str));

	for (i = url_len; i < url_len + data_len; i++)
	{
		url_str[i] = data[i - url_len];
	}

	url_str[i] = '\0';

	if (sim_http_get(url_str))
	{
		result = sim_http_term();
	}

	// serial_printf("URL: l%i %s\n", strlen(url_str), url_str);

	return result;
}

/*////////////////////////////////////////////////////////////////////////////*/
// SMS
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_send_sms(const char *phone_number, const char *str)
{
	bool result = false;

	// Set text mode
	if (!sim_printf_and_check_response(1000, "OK", "AT+CMGF=1\r"))
	{
	}
	else if (!sim_printf_and_check_response(1000, "OK", "AT+CSCS=\"GSM\"\r"))
	{
	}
	// else if (!sim_printf_and_check_response(1000, "OK", "AT+CMGS=\"%s\"\r%s%c\r", phone_number, str, 0x1A))
	// {
	// }
	else
	{
		sim_serial_pass_through();
		result = true;
	}

	return result;
}

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
	usart_set_stopbits(SIM_USART, USART_STOPBITS_1);
	usart_set_mode(SIM_USART, USART_MODE_TX_RX);
	usart_set_parity(SIM_USART, USART_PARITY_NONE);
	usart_set_flow_control(SIM_USART, USART_FLOWCONTROL_NONE);
	usart_enable(SIM_USART);

	usart_disable_rx_timeout_interrupt(SIM_USART);
	usart_set_rx_timeout_value(SIM_USART, 100000);
	usart_disable_rx_timeout(SIM_USART);
	USART_ICR(SPF_USART) |= USART_ICR_RTOCF;
	usart_enable_rx_timeout(SIM_USART);

	usart_enable_rx_interrupt(SIM_USART);

	nvic_clear_pending_irq(SIM_USART_NVIC);
	nvic_set_priority(SIM_USART_NVIC, IRQ_PRIORITY_SIM);
	nvic_enable_irq(SIM_USART_NVIC);
}

static void _putchar(char character)
{
	bool done = false;

	while (!done)
	{
		CM_ATOMIC_BLOCK()
		{
			if ((sim_tx_head == sim_tx_tail) && usart_get_flag(SIM_USART, USART_ISR_TXE))
			{
				usart_send(SIM_USART, character);
				done = true;
			}
			else
			{
				uint8_t i = (sim_tx_head + 1) % SIM_BUFFER_SIZE;

				if (i == sim_tx_tail)
				{
					done = false;
				}
				else
				{

					sim_tx_buf[sim_tx_head] = character;

					sim_tx_head = i;

					usart_enable_tx_interrupt(SIM_USART);

					done = true;
				}
			}
		}
		__asm__("nop");
	}

#if DEBUG
	serial_printf("%c", character);
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

static bool check_response(const char *expected_response)
{
	return (strstr(last_reply, expected_response) != NULL);
}

static bool response_done(char terminating_char)
{
	bool terminated = false;

	static char check_buf[SIM_BUFFER_SIZE];
	static uint8_t check_idx = 0;

	// Go through RX Buf
	while (sim_rx_tail != sim_rx_head)
	{
		rx_timeout = timers_millis();

		// Get next char from RX Buf
		char character = sim_rx_buf[sim_rx_tail];
		sim_rx_tail = (sim_rx_tail + 1) % SIM_BUFFER_SIZE;

		check_buf[check_idx] = character;
		check_idx = (check_idx + 1) % SIM_BUFFER_SIZE;

		// End of reply
		if (character == terminating_char)
		{
			terminated = true;
			break;
		}
	}

	bool timeout = (timers_millis() - rx_timeout) > 100;
	if (timeout)
	{
		serial_printf("RX Timeout\n");
	}
	if (terminated)
	{
		serial_printf("Terminated\n");
	}
	if (terminated || timeout)
	{
		if (check_idx)
		{
			// Null Terminate String
			check_buf[check_idx] = '\0';

			// Copy into last reply buffer
			strcpy(last_reply, check_buf);

			// Reset ckeck buf
			memset(check_buf, 0, check_idx);
			check_idx = 0;

#if DEBUG
			serial_printf("Sim Response %s: %s\n", timeout ? "TO" : "OK", last_reply);
#endif
		}

		return true;
	}

	// Response not finished
	return false;
}

static bool wait_and_check_response(uint32_t timeout_ms, const char *expected_response)
{
	bool result = false;
	uint32_t counter = 0;
	uint16_t time = timers_millis();
	while (counter < timeout_ms)
	{
		response_done('\n');
		if (check_response(expected_response))
		{
			result = true;
			break;
		}
		counter += (uint16_t)(timers_millis() - time);
		time = timers_millis();
	}

	return result;
}

static sim_state_t basic_cmd_response(char *cmd_str, uint32_t timeout_ms)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		sim_printf(cmd_str);
		timeout_init(timeout_ms);
		state++;
		break;
	case 1:
		res = SIM_BUSY;
		if (response_done('\n'))
		{
			if (check_response("OK"))
			{
				res = SIM_SUCCESS;
				state = 0;
			}
			else if (check_response("ERROR"))
			{
				res = SIM_FAIL;
				state = 0;
			}
			else
			{
				res = SIM_BUSY;
			}
		}
		else if (timeout())
		{
			res = SIM_TIMEOUT;
			state = 0;
		}

		break;
	default:
		res = SIM_ERROR;
		state = 0;
		break;
	}

	switch (res)
	{
	case SIM_FAIL:
	case SIM_TIMEOUT:
	case SIM_ERROR:
		PRINT_ERROR(cmd_str, res);
		break;

	default:
		break;
	}

	return res;
}

static sim_state_t try_autobaud(void)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	timers_delay_milliseconds(50);

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		sim_printf("AT\r");
		timeout_init(5000);
		state++;
		break;
	case 1:
		res = SIM_BUSY;

		if (response_done('\n'))
		{
			if (check_response("OK"))
			{
				res = SIM_SUCCESS;
				state = 0;
			}
			else if (check_response("ERROR"))
			{
				res = SIM_FAIL;
				state = 0;
			}
			else
			{
				sim_printf("AT\r");
				res = SIM_BUSY;
			}
		}
		else if (timeout())
		{
			res = SIM_TIMEOUT;
			state = 0;
		}

		break;

	default:
		res = SIM_ERROR;
		state = 0;
		break;
	}

	switch (res)
	{
	case SIM_FAIL:
	case SIM_TIMEOUT:
	case SIM_ERROR:
		log_error(ERR_SIM_AUTOBAUD);
		break;

	default:
		break;
	}

	return res;
}

static sim_state_t disable_echo(void)
{
	sim_state_t res = basic_cmd_response("ATE0\r", 5000);

	switch (res)
	{
	case SIM_FAIL:
	case SIM_TIMEOUT:
	case SIM_ERROR:
		log_error(ERR_SIM_ATE_0);
		break;

	default:
		break;
	}

	return res;
}

static sim_state_t enable_local_timestamp(void)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		sim_printf("AT+CLTS?\r");
		timeout_init(1000);
		state++;
		break;
	case 1:
		res = SIM_BUSY;
		if (response_done('\n'))
		{
			if (check_response("+CLTS: 1"))
			{
				res = SIM_SUCCESS;
				state = 0;
			}
			else if (check_response("+CLTS: 0"))
			{
				sim_printf("AT+CLTS=1;&W\r");
				res = SIM_BUSY;
				state = 2;
			}
			else if (check_response("ERROR"))
			{
				res = SIM_FAIL;
				state = 0;
			}
		}
		else if (timeout())
		{
			res = SIM_TIMEOUT;
			state = 0;
		}
		break;
	case 2:
		res = SIM_BUSY;
		reset();
		state++;
		break;
	case 3:
		res = try_autobaud();
		if (res == SIM_SUCCESS)
		{
			state++;
		}
		break;
	case 4:
		res = disable_echo();
		if (res == SIM_SUCCESS)
		{
			state++;
		}
		break;
	default:
		res = SIM_ERROR;
		state = 0;
		break;
	}


	switch (res)
	{
	case SIM_FAIL:
	case SIM_TIMEOUT:
	case SIM_ERROR:
		log_error(ERR_SIM_CLTS);
		break;

	default:
		break;
	}

	return res;
}

static sim_state_t enable_full_function(void)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		sim_printf("AT+CFUN?\r");
		timeout_init(1000);
		state++;
		break;
	case 1:
		res = SIM_BUSY;
		if (response_done('\n'))
		{
			if (check_response("+CFUN: 1"))
			{
				res = SIM_SUCCESS;
				state = 0;
			}
			else if (check_response("+CFUN: 0"))
			{
				sim_printf("AT+CFUN=1\r");
				res = SIM_BUSY;
				state = 1;
			}
			else if (check_response("ERROR"))
			{
				res = SIM_FAIL;
				state = 0;
			}
		}
		else if (timeout())
		{
			res = SIM_TIMEOUT;
			state = 0;
		}
		break;
	default:
		res = SIM_ERROR;
		state = 0;
		break;
	}


	switch (res)
	{
	case SIM_FAIL:
	case SIM_TIMEOUT:
	case SIM_ERROR:
		log_error(ERR_SIM_SET_FULL_FUNCTION);
		break;

	default:
		break;
	}

	return res;
}

static bool open_bearer(void)
{
	bool result = false;

	// If connection fails
	if (!sim_printf_and_check_response(90000, "OK", "AT+SAPBR=1,1\r"))
	{
		result = false;
	}
	// If connection succeeds, delay for some time
	else
	{
		timers_delay_milliseconds(1000);
		result = true;
	}

	return result;
}

static void timeout_init(uint32_t timeout_ms)
{
	_timeout_ms = timeout_ms;
	_timer = timers_millis();
}

static bool timeout(void)
{
	return ((timers_millis() - _timer) > _timeout_ms);
}

/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Interrupts
/*////////////////////////////////////////////////////////////////////////////*/

SIM_ISR()
{
	// serial_printf("Sim ISR: %8x\n", USART2_ISR);

	// Received data from sim
	// Read data (clears flag automatically)
	if (usart_get_flag(SIM_USART, USART_ISR_RXNE))
	{
		char c = usart_recv(SIM_USART);
		if (((sim_rx_head + 1) % SIM_BUFFER_SIZE) == sim_rx_tail)
		{
			// Read overflow
			sim_rx_overflow = true;
		}
		else
		{
			sim_rx_buf[sim_rx_head] = c;
			sim_rx_head = (sim_rx_head + 1) % SIM_BUFFER_SIZE;
		}
	}

	// Transmit buffer empty
	// Fill it (clears flag automatically)
	if (usart_get_flag(SIM_USART, USART_ISR_TXE))
	{
		// Fill it if data waiting
		if ((SIM_BUFFER_SIZE + sim_tx_head - sim_tx_tail) % SIM_BUFFER_SIZE)
		{
			usart_send(SIM_USART, sim_tx_buf[sim_tx_tail]);
			sim_tx_tail = (sim_tx_tail + 1) % SIM_BUFFER_SIZE;
		}
		// Otherwise tranfer is done, disable interrupt (prevent irq firing constantly waiting for TX Data Reg to be filled)
		else
		{
			usart_disable_tx_interrupt(SIM_USART);
		}
	}
}

/** @} */
/** @} */
