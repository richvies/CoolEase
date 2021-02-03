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

enum cmd_type
{
	CMD_TEST = 0,
	CMD_READ,
	CMD_WRITE,
	CMD_EXEC
};

typedef enum sim_function
{
	FUNC_MIN = 0,
	FUNC_FULL = 1,
	FUNC_NO_RF = 4,
	FUNC_OFF,
	FUNC_RESET,
	FUNC_SLEEP
} sim_function_t;
static sim_function_t sim_func = FUNC_OFF;

typedef enum registration_status
{
	REG_NONE = 0,
	REG_HOME,
	REG_SEARCHING,
	REG_DENIED,
	REG_UNKNOWN,
	REG_ROAMING
} registration_status_t;
static registration_status_t reg_status = REG_NONE;

typedef enum http_state
{
	HTTP_TERM = 0,
	HTTP_INIT,
	HTTP_ACTION,
	HTTP_DONE
} http_state_t;
static http_state_t http_state = HTTP_TERM;

#define SIM_BUFFER_SIZE 64U

static char sim_rx_buf[SIM_BUFFER_SIZE];
static char sim_tx_buf[SIM_BUFFER_SIZE];
static uint8_t sim_tx_head = 0;
static uint8_t sim_tx_tail = 0;
static uint8_t sim_rx_head = 0;
static uint8_t sim_rx_tail = 0;
static bool sim_rx_overflow = false;

static char param_buf[SIM_BUFFER_SIZE];
static char reply_buf[SIM_BUFFER_SIZE];
static char timestamp[18];

static const char base_url_str[] = "http://cooleasetest.000webhostapp.com/";

static uint32_t _timer = 0;
static uint32_t _timeout_ms = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static sim_state_t command(enum cmd_type type, char *cmd_str, char *val_str, uint32_t timeout_ms);
static sim_state_t read_command(char *cmd_str, uint32_t timeout_ms);
static sim_state_t write_command(char *cmd_str, char *val_str, uint32_t timeout_ms);
static sim_state_t exec_command(char *cmd_str, uint32_t timeout_ms);
static sim_state_t set_param(char *cmd_str, char *val_str, uint32_t timeout_ms);

/** @brief Wait until correct response received or timeout 
 * 
 * Check response + timeout
 */
static bool wait_and_check_response(uint32_t timeout_ms, const char *expected_response);
/** @brief Read all unread characters until terminated or no rx in 100ms */
static bool response_done(char terminating_char);
/** @brief Search for string in reply_buf */
static bool check_response(const char *expected_response);
/** @brief Search for parameter value in param_buf */
static bool check_param_response(char *cmd_str, char *exp_val_str);
static void timeout_init(uint32_t new_timeout_ms);
static bool timeout(void);

static sim_state_t reset_and_wait_ready(void);
/** @brief Repeatedly send AT command until SIM autbauding kicks in i.e. "OK" received
 * 
 * Recommended pg.29 SIM800_Hardware Design_V1.10.pdf
 * 100ms timeout for each attempt
 * 
 */
static sim_state_t try_autobaud(void);
static sim_state_t disable_echo(void);
static sim_state_t toggle_local_timestamp(bool on);
static sim_state_t set_function(sim_function_t func);
static sim_state_t config_saved_params(void);
/** @brief Wrapper for SAPBR=1,1 command 
 * 
 * Adds delay of 1 second after opening bearer to prevent issues with next command coming to quickly 
 * Issue mainly with calling httpaction
 */
static sim_state_t open_bearer(void);

static void reset(void);
static void usart_setup(void);
static void clear_rx_buf(void);
static void _putchar(char character);

/** @brief Internal test if char is a digit (0-9) */
static inline bool _is_digit(char ch);

/** @brief internal ASCII string to uint32_t conversion */
static uint32_t _atoi(const char **str);

/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Comms
/*////////////////////////////////////////////////////////////////////////////*/

void sim_printf(const char *format, ...)
{
	va_list va;
	va_start(va, format);
	fnprintf(_putchar, format, va);
	va_end(va);
}

bool sim_printf_and_check_response(uint32_t timeout_ms, const char *expected_response, const char *format, ...)
{
	// Write to SIM800
	va_list va;
	va_start(va, format);
	fnprintf(_putchar, format, va);
	va_end(va);

	return wait_and_check_response(timeout_ms, expected_response);
}

void sim_serial_pass_through(void)
{
	log_printf("Ready\n");

	while (1)
	{
		// Data received from serial monitor
		// Append to sim tx buffer
		if (serial_available())
		{
			sim_printf("%c", serial_read());
		}

		// Data received from sim
		// Pass to serial monitor
		// Sim baud is much slower than serial monitor
		// -> can pass straight from sim to monitor
		if (sim_available())
		{
			serial_printf("%c", sim_read());
		}
	}
}

bool sim_available(void)
{
	return ((sim_rx_head + SIM_BUFFER_SIZE - sim_rx_tail) % SIM_BUFFER_SIZE);
}

char sim_read(void)
{
	char c = 0;
	if (sim_available())
	{
		c = sim_rx_buf[sim_rx_tail];
		sim_rx_tail = (sim_rx_tail + 1) % SIM_BUFFER_SIZE;
	}

	return c;
}

static sim_state_t command(enum cmd_type type, char *cmd_str, char *val_str, uint32_t timeout_ms)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	// Send command
	case 0:
		res = SIM_BUSY;
		state++;

		timers_delay_milliseconds(10);

		clear_rx_buf();
		timeout_init(timeout_ms);

		switch (type)
		{
		case CMD_TEST:
			sim_printf("AT%s=?\r", cmd_str);
			break;
		case CMD_READ:
			sim_printf("AT%s?\r", cmd_str);
			break;
		case CMD_WRITE:
			sim_printf("AT%s=%s\r", cmd_str, val_str);
			break;
		case CMD_EXEC:
			sim_printf("AT%s\r", cmd_str);
			break;
		default:
			break;
		}

		break;
	// Parse response, waits until finished if timeout is small
	case 1:
		res = SIM_BUSY;
		do
		{
			if (timeout())
			{
				log_printf("SIM ERR: CMD TO %u %s %s\n", type, cmd_str, val_str);
				state = 'X';
				break;
			}
			else if (response_done('\n'))
			{
				if (check_response("OK"))
				{
					state = 'S';
					break;
				}
				else if (check_response("ERROR"))
				{
					log_printf("SIM ERR: CMD FA %u %s %s\n", type, cmd_str, val_str);
					state = 'X';
					break;
				}
				// Save parameter value e.g. +CLTS: 1
				else if (check_response(cmd_str))
				{
					strcpy(param_buf, reply_buf);
				}
			}
		} while (timeout_ms < 150);
		break;
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	case 'X':
	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	return res;
}

static sim_state_t test_command(char *cmd_str, uint32_t timeout_ms)
{
	return command(CMD_TEST, cmd_str, "", timeout_ms);
}

// All end with OK. Only returns success if cmd_str found in response e,g, +clts
static sim_state_t read_command(char *cmd_str, uint32_t timeout_ms)
{
	return command(CMD_READ, cmd_str, "", timeout_ms);
}

// All end with OK or error
static sim_state_t write_command(char *cmd_str, char *val_str, uint32_t timeout_ms)
{
	return command(CMD_WRITE, cmd_str, val_str, timeout_ms);
}

static sim_state_t exec_command(char *cmd_str, uint32_t timeout_ms)
{
	return command(CMD_EXEC, cmd_str, "", timeout_ms);
}

static sim_state_t set_param(char *cmd_str, char *val_str, uint32_t timeout_ms)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = read_command(cmd_str, timeout_ms);
		break;
	// If here then sim returned value of paramter e.g. +CLTS: 1 and it is stored in param_buf
	case 1:
		res = SIM_BUSY;

		if (check_param_response(cmd_str, val_str))
		{
			state = 'S';
		}
		else
		{
			state++;
		}

		break;
	case 2:
		res = write_command(cmd_str, val_str, timeout_ms);
		break;
	case 3:
		res = read_command(cmd_str, timeout_ms);
		break;
	case 4:
		res = SIM_BUSY;

		if (check_param_response(cmd_str, val_str))
		{
			state = 'S';
		}
		else
		{
			state = 'X';
		}
		break;
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	case 'X':
	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	// Go to next state
	if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static bool wait_and_check_response(uint32_t timeout_ms, const char *expected_response)
{
	bool result = false;
	uint32_t timer = timers_millis();

	while ((timers_millis() - timer) < timeout_ms)
	{
		if (response_done('\n') && check_response(expected_response))
		{
			result = true;
			break;
		}
	}

	return result;
}

static bool check_response(const char *expected_response)
{
	return (strstr(reply_buf, expected_response) != NULL);
}

// Assumes parameter response is in param_buf
static bool check_param_response(char *cmd_str, char *exp_val_str)
{
	// E.g. Sim response from read commnad: "AT+CLTS?" -> "+CLTS: 1"

	// Look for command e.g. "+CLTS"
	char *tmp = strstr(param_buf, cmd_str);

	if (tmp != NULL)
	{
		// Check for expected value
		if (strstr(param_buf, exp_val_str) != NULL)
		{
			return true;
		}
	}
	return false;
}

static bool response_done(char terminating_char)
{
	static char check_buf[SIM_BUFFER_SIZE];
	static uint8_t check_idx = 0;

	static uint32_t rx_timeout = 0;

	// Go through unread RX Buf until terminating char found
	bool terminated = false;
	while (sim_rx_tail != sim_rx_head)
	{
		// Reset rx timeout for every new char received
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

	// Copy message to buffer if terminated or no rx in 100ms
	bool timeout = (timers_millis() - rx_timeout) > 100;
	if (terminated || timeout)
	{
		// Null Terminate String
		check_buf[check_idx] = '\0';

		// Copy into last reply buffer
		strcpy(reply_buf, check_buf);

#if DEBUG
		if (check_idx > 2)
		{
			serial_printf("Sim Response %s: %s\n", timeout ? "TO" : "TE", reply_buf);
		}
#endif

		// Reset ckeck buf
		memset(check_buf, 0, check_idx);
		check_idx = 0;

		return true;
	}

	// Response not finished
	return false;
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

/*////////////////////////////////////////////////////////////////////////////*/
// Setup
/*////////////////////////////////////////////////////////////////////////////*/

sim_state_t sim_init(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		state++;

		log_printf("Sim Init\n");

		sim_func = FUNC_OFF;
		break;
	case 1:
		res = reset_and_wait_ready();
		break;
	case 2:
		res = config_saved_params();
		break;
	case 3:
		res = reset_and_wait_ready();
		break;
	case 4:
		res = SIM_BUSY;
		state = 'S';
		break;
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	case 'X':
	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	// Go to next state
	if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_end(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		state++;

		log_printf("Sim End\n");

		break;
	case 1:
		res = set_function(FUNC_MIN);
		break;
	case 2:
		res = set_param("+CSCLK", "1", 5000);
		break;
	case 3:
		res = SIM_BUSY;
		state = 'S';

		usart_disable(SIM_USART);
		rcc_periph_clock_disable(SIM_USART_RCC);
		
		sim_func = FUNC_SLEEP;
		reg_status = REG_NONE;
		http_state = HTTP_TERM;
		break;
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	case 'X':
	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	// Go to next state
	if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;

}

sim_state_t sim_register_to_network(void)
{
	static uint8_t state = 0;
	static uint8_t num_tries = 0;
	static uint32_t timer = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	// Init state machine
	case 0:
		res = SIM_BUSY;
		state++;

		log_printf("SIM: Register\n");

		reg_status = REG_NONE;
		num_tries = 0;
		break;
	// Tried too many times with no end result
	case 1:
		res = SIM_BUSY;
		state++;

		num_tries++;
		if (num_tries >= 30)
		{
			state = 'X';
		}
		break;
	// Query registration status
	case 2:
		res = read_command("+CREG", 1000);
		break;
	// Parse reply
	case 3:
		res = SIM_BUSY;

		// enum uses same values as sim800 response
		reg_status = param_buf[9] - '0';

		serial_printf("Register Attempt %i : %u %s\n", num_tries, reg_status, param_buf);

		switch (reg_status)
		{
		// Continue searching
		case REG_NONE:
		case REG_SEARCHING:
			state++;
			break;
		case REG_HOME:
		case REG_ROAMING:
			state = 'S';
			break;
		case REG_DENIED:
		case REG_UNKNOWN:
			state = 'X';
			break;
		default:
			state++;
			reg_status = REG_NONE;
			break;
		}
		break;
	// Wait 2 seconds between CREG queries
	case 4:
		res = SIM_BUSY;
		state++;

		timer = timers_millis();
		break;
	case 5:
		res = SIM_BUSY;
		if ((timers_millis() - timer) > 2000)
		{
			state = 1;
		}
		break;
	// Finished, reset
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	// Error, reset
	case 'X':
	default:
		log_printf("SIM ERR: %u %u\n", reg_status);
		state = 0;
		return SIM_ERROR;
		break;
	}

	// Go to next state
	if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static sim_state_t reset_and_wait_ready(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_BUSY;
		state++;

		reset();
		break;
	case 1:
		res = try_autobaud();
		break;
	case 2:
		res = disable_echo();
		break;
	case 3:
		res = SIM_BUSY;
		state = 250;
		break;
	case 250:
		res = SIM_SUCCESS;
		state = 0;
		break;
	case 255:
	default:
		res = SIM_ERROR;
		state = 0;
		break;
	}

	// Go to next state if ok
	if ((state != 0) && (res == SIM_SUCCESS))
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static sim_state_t try_autobaud(void)
{
	static uint8_t num_tries = 0;

	sim_state_t res = exec_command("", 100);

	if (res == SIM_ERROR)
	{
		num_tries++;
		if (num_tries < 100)
		{
			res = SIM_BUSY;
		}
	}
	else if (res == SIM_SUCCESS)
	{
		num_tries = 0;
	}

	return res;
}

static sim_state_t disable_echo(void)
{
	return exec_command("E0", 1000);
}

static sim_state_t config_saved_params(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = toggle_local_timestamp(true);
		break;
	case 1:
		res = set_function(FUNC_FULL);
		break;
	case 2:
		res = SIM_BUSY;
		state = 'S';
		break;
	case 'S':
		state = 0;
		return SIM_SUCCESS;
		break;
	case 'X':
	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	// Go to next state if not finished & ok
	if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static sim_state_t toggle_local_timestamp(bool on)
{
	static char *buf = "0";
	buf[0] = on ? '1' : '0';
	
	return set_param("+CLTS", buf, 1000);
}

static sim_state_t set_function(sim_function_t func)
{
	static char *buf = "0";
	buf[0] = func + '0';
	return set_param("+CFUN", buf, 1000);
}

static sim_state_t open_bearer(void)
{
	return write_command("+SAPBR", '1,1', 90000);
}

bool sim_set_full_function(void)
{
	log_printf("Sim Set FF\n");

	bool result = false;

	if (sim_func == FUNC_FULL)
	{
		result = true;
	}
	else
	{
		// Reset sim if off or in sleep mode
		// Currently no connection to DTR so only way to get sim out of sleep is to reset
		if (sim_func == FUNC_OFF || sim_func == FUNC_SLEEP)
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
			sim_func = FUNC_FULL;
			result = true;
		}
	}

	return result;
}

void sim_print_res(sim_state_t res)
{
	switch (res)
	{
	case SIM_READY:
		serial_printf("SIM: Ready\n");
		break;
	case SIM_BUSY:
		serial_printf("SIM: Busy\n");
		break;
	case SIM_SUCCESS:
		serial_printf("SIM: Success\n");
		break;
	case SIM_TIMEOUT:
		serial_printf("SIM: Timeout\n");
		break;
	case SIM_ERROR:
		serial_printf("SIM: Error\n");
		break;
	case SIM_FAIL:
		serial_printf("SIM: Fail\n");
		break;
	default:
		break;
	}
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

uint32_t sim_get_timestamp(void)
{
	if (!sim_printf_and_check_response(1000, "CCLK", "AT+CCLK?\r"))
	{
	}
	else
	{
		memcpy(timestamp, &reply_buf[8], sizeof(timestamp) - 1);
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
	else if (!sim_printf_and_check_response(10000, "OK", "AT+SAPBR=1,1\r"))
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
		char *ptr = &reply_buf[15];
		uint16_t status_code = _atoi((const char **)&ptr);

		if (status_code == 200)
		{
			// Response length
			if (_is_digit(reply_buf[19]))
			{
				ptr = &reply_buf[19];
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
	else if (!!sim_printf_and_check_response(10000, "OK", "AT+SAPBR=1,1\r"))
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
		char *ptr = &reply_buf[15];
		uint16_t status_code = _atoi((const char **)&ptr);

		if (status_code == 200)
		{
			// Response length
			if (_is_digit(reply_buf[19]))
			{
				ptr = &reply_buf[19];
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
		if (_is_digit(reply_buf[11]))
		{
			char *ptr = &reply_buf[11];
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

	if (!sim_printf_and_check_response(10000, "OK", "AT+SAPBR=1,1\r"))
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
				char *ptr = &reply_buf[15];
				uint16_t status_code = _atoi((const char **)&ptr);

				if (status_code == 200)
				{
					// Response length
					if (_is_digit(reply_buf[19]))
					{
						ptr = &reply_buf[19];
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
	// else if (!sim_printf_and_check_response(1000, ">", "AT+CMGS=\"%s\"\r%s%c\r", phone_number, str, 0x1A))
	// {
	// }
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

static void reset(void)
{
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
	memset(reply_buf, 0, sizeof(reply_buf));

	sim_func = FUNC_RESET;
	reg_status = REG_NONE;
	http_state = HTTP_TERM;
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

static void clear_rx_buf(void)
{
	sim_rx_tail = sim_rx_head;
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
