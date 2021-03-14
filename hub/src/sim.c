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

#define PRINT_CMD(type, cmd, val) serial_printf("%s: %s %s\n", ((type == CMD_TEST) ? "TEST" : (type == CMD_READ) ? "READ"  \
																						  : (type == CMD_WRITE)	 ? "WRITE" \
																						  : (type == CMD_WAIT)	 ? "WAIT"  \
																												 : "EXEC"),  \
												cmd, val)

#undef PRINT_CMD
// #define PRINT_RESPONSE
// #define FORWARD_TO_SPF

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

#define RX_TIMEOUT_MS 100
#define QUICK_RESPONSE_MS 100

sim800_t sim800;

enum cmd_type
{
	CMD_TEST = 0,
	CMD_READ,
	CMD_WRITE,
	CMD_EXEC,
	CMD_WAIT
};

#define SIM_BUFFER_SIZE 64U

static char sim_rx_buf[SIM_BUFFER_SIZE];
static char sim_tx_buf[SIM_BUFFER_SIZE];
static uint8_t sim_tx_head = 0;
static uint8_t sim_tx_tail = 0;
static uint8_t sim_rx_head = 0;
static uint8_t sim_rx_tail = 0;
static bool sim_rx_overflow = false;

static char _sprintf_buf[SIM_BUFFER_SIZE];
static uint8_t _sprintf_buf_idx = 0;

static char param_buf[SIM_BUFFER_SIZE];
static char reply_buf[SIM_BUFFER_SIZE];

// year, month, day, hours, mins, secs
static uint8_t timestamp[6] = {0, 0, 0, 0, 0, 0};

static const char base_url_str[] = "http://cooleasetest.000webhostapp.com/";

static uint32_t _timer = 0;
static uint32_t _timeout_ms = 0;

/*////////////////////////////////////////////////////////////////////////////*/
// Comms
/*////////////////////////////////////////////////////////////////////////////*/

static void _putchar_buffer(char character);
static uint32_t _sprintf(const char *format, ...);
static void _sprintf_clear_buf(void);

static sim_state_t command(enum cmd_type type, const char *cmd_str, const char *val_str, uint32_t timeout_ms);
static sim_state_t test_command(const char *cmd_str, uint32_t timeout_ms);
static sim_state_t read_command(const char *cmd_str, uint32_t timeout_ms);
static sim_state_t write_command(const char *cmd_str, const char *val_str, uint32_t timeout_ms);
static sim_state_t exec_command(const char *cmd_str, uint32_t timeout_ms);
static sim_state_t set_param(const char *cmd_str, const char *val_str, uint32_t timeout_ms);
static sim_state_t wait_command(const char *wait_str, uint32_t timeout_ms);

/** @brief Wait until correct response received or timeout 
 * 
 * Check response + timeout
 */
static bool wait_and_check_response(uint32_t timeout_ms, const char *expected_response);
/** @brief Read all unread characters until terminated or no rx in 100ms */
static bool response_done(const char terminating_char);
/** @brief Search for string in reply_buf */
static bool check_response(const char *expected_response);
/** @brief Search for parameter value in param_buf */
static bool check_param_response(const char *cmd_str, const char *exp_val_str);
static void timeout_init(uint32_t new_timeout_ms);
static bool timeout(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Setup & Config
/*////////////////////////////////////////////////////////////////////////////*/

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
static sim_state_t config_bearer(char *apn_str, char *user_str, char *pwd_str);
static sim_state_t toggle_bearer(bool open);

/*////////////////////////////////////////////////////////////////////////////*/
// HTTP
/*////////////////////////////////////////////////////////////////////////////*/

static sim_state_t http_toggle_ssl(bool on);
static sim_state_t http_action(uint8_t action);

static void reset(void);
static void usart_setup(void);
static void clear_rx_buf(void);
static void _putchar(char character);
static void print_timestamp(void);

/** @} */

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Comms
/*////////////////////////////////////////////////////////////////////////////*/

void sim_serial_pass_through(void)
{
	serial_printf("SIM: Serial Passthrough Ready\n");

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

		timers_pet_dogs();
	}
}

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

	clear_rx_buf();

	return wait_and_check_response(timeout_ms, expected_response);
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

static uint32_t _sprintf(const char *format, ...)
{
	(void)test_command;
	_sprintf_clear_buf();

	va_list va;
	va_start(va, format);
	uint32_t res = fnprintf(_putchar_buffer, format, va);
	va_end(va);

	return res;
}

static void _sprintf_clear_buf(void)
{
	for (uint8_t i = 0; i < _sprintf_buf_idx; i++)
	{
		_sprintf_buf[i] = '\0';
	}
	_sprintf_buf_idx = 0;
}

static sim_state_t command(enum cmd_type type, const char *cmd_str, const char *val_str, uint32_t timeout_ms)
{
	static uint8_t state = 0;

	sim_state_t res = SIM_ERROR;

	bool quick_response = (timeout_ms <= QUICK_RESPONSE_MS) ? true : false;

	switch (state)
	{
	// Send command
	case 0:
#ifdef PRINT_CMD
		PRINT_CMD(type, cmd_str, val_str);
#endif

		res = SIM_BUSY;
		state++;

		timers_delay_milliseconds(1);

		timeout_init(timeout_ms);

		if (type != CMD_WAIT)
		{
			clear_rx_buf();
		}

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
		case CMD_WAIT:
			break;
		default:
			break;
		}

		if (!quick_response)
		{
			break;
		}
		/* fall through */

	// Parse response, waits until finished if timeout is small
	case 1:
		res = SIM_BUSY;
		do
		{
			if (timeout())
			{
				res = SIM_TIMEOUT;
				state = 0;

				log_printf("SIM ERR: CMD TO %u %s %s\n", type, cmd_str, val_str);
				break;
			}
			else if (response_done('\n'))
			{
				if (check_response("OK"))
				{
					res = SIM_SUCCESS;
					state = 0;

					break;
				}
				else if (check_response("ERROR"))
				{
					res = SIM_ERROR;
					state = 0;

					log_printf("SIM ERR: CMD FA %u %s %s\n", type, cmd_str, val_str);
					break;
				}
				// Save parameter value e.g. +CLTS: 1
				else if (check_response(cmd_str))
				{
					strcpy(param_buf, reply_buf);

					if (type == CMD_WAIT)
					{
						res = SIM_SUCCESS;
						state = 0;
					}
				}
			}
		} while (quick_response);
		break;

	default:
		state = 0;
		return SIM_ERROR;
		break;
	}

	return res;
}

static sim_state_t test_command(const char *cmd_str, uint32_t timeout_ms)
{
	(void)_sprintf;
	return command(CMD_TEST, cmd_str, "", timeout_ms);
}

// All end with OK. Only returns success if cmd_str found in response e,g, +clts
static sim_state_t read_command(const char *cmd_str, uint32_t timeout_ms)
{
	return command(CMD_READ, cmd_str, "", timeout_ms);
}

// All end with OK or error
static sim_state_t write_command(const char *cmd_str, const char *val_str, uint32_t timeout_ms)
{
	return command(CMD_WRITE, cmd_str, val_str, timeout_ms);
}

static sim_state_t exec_command(const char *cmd_str, uint32_t timeout_ms)
{
	return command(CMD_EXEC, cmd_str, "", timeout_ms);
}

static sim_state_t wait_command(const char *wait_str, uint32_t timeout_ms)
{
	return command(CMD_WAIT, wait_str, "", timeout_ms);
}

static sim_state_t set_param(const char *cmd_str, const char *val_str, uint32_t timeout_ms)
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
		if (check_param_response(cmd_str, val_str))
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_ERROR;
		}
		break;
	case 5:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
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
static bool check_param_response(const char *cmd_str, const char *exp_val_str)
{
	// E.g. Sim response from read commnad: "AT+CLTS?" -> "+CLTS: 1"

	// Look for command e.g. "+CLTS"
	char *tmp = strstr(param_buf, cmd_str);

	if (tmp != NULL)
	{
		// Check for expected value
		if (strstr(tmp, exp_val_str) != NULL)
		{
			return true;
		}
	}
	return false;
}

static bool response_done(const char terminating_char)
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

	// Copy message to buffer if terminated or no rx
	bool timeout = (timers_millis() - rx_timeout) > RX_TIMEOUT_MS;
	if (terminated || timeout)
	{
		// Null Terminate String
		check_buf[check_idx] = '\0';

		// Copy into last reply buffer
		strcpy(reply_buf, check_buf);

#ifdef DEBUG
#ifdef PRINT_RESPONSE
		if (check_idx > 2)
		{
			serial_printf("Response Done %s: %s\n", timeout ? "TO" : "TE", reply_buf);
		}
#endif
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

void sim_print_state(sim_state_t res)
{
	switch (res)
	{
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
		break;
	default:
		break;
	}
}

/*////////////////////////////////////////////////////////////////////////////*/
// Setup & Config
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

		log_printf("SIM: Init\n");

		sim800.func = FUNC_OFF;
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
		res = set_function(FUNC_FULL);
		break;
	case 5:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
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
		res = SIM_SUCCESS;

		log_printf("SIM: End\n");

		break;
	case 1:
		res = set_function(FUNC_MIN);
		break;
	case 2:
		res = set_param("+CSCLK", "1", 5000);
		break;
	case 3:
		res = SIM_SUCCESS;

		usart_disable(SIM_USART);
		rcc_periph_clock_disable(SIM_USART_RCC);

		sim800.func = FUNC_SLEEP;
		sim800.reg_status = REG_NONE;
		sim800.http.state = HTTP_TERM;
		break;
	case 4:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_sleep(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		log_printf("SIM: End\n");

		break;
	case 1:
		res = set_function(FUNC_MIN);
		break;
	case 2:
		res = set_param("+CSCLK", "1", 5000);
		break;
	case 3:
		res = SIM_SUCCESS;

		sim800.func = FUNC_SLEEP;
		sim800.reg_status = REG_NONE;
		sim800.http.state = HTTP_TERM;
		break;
	case 4:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
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
		res = SIM_SUCCESS;

		log_printf("SIM: Register\n");

		sim800.reg_status = REG_NONE;
		num_tries = 0;
		break;
	// Tried too many times with no end result
	case 1:
		res = SIM_SUCCESS;

		if (num_tries++ < 30)
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_ERROR;
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
		sim800.reg_status = param_buf[9] - '0';

		serial_printf("Register Attempt %i : %u %s\n", num_tries, sim800.reg_status, param_buf);

		switch (sim800.reg_status)
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
			sim800.reg_status = REG_NONE;
			break;
		}
		break;
	// Wait 2 seconds between CREG queries
	case 4:
		res = SIM_SUCCESS;

		timer = timers_millis();
		break;
	case 5:
		res = SIM_BUSY;

		if ((timers_millis() - timer) > 2000)
		{
			state = 1;
		}
		break;
	case 6:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

uint8_t *sim_get_timestamp(void)
{
	// E.g. +CCLK: "21/02/03,13:37:12+00"

	sim_state_t res = read_command("+CCLK", QUICK_RESPONSE_MS);

	if (res == SIM_SUCCESS)
	{
		// Basic error check of reponse format
		if ((param_buf[7] == '\"') && (param_buf[28] == '\"'))
		{
			// Parse reply and update timestamp buffer
			char *ptr;
			for (uint8_t i = 0; i < 6; i++)
			{
				ptr = &param_buf[8 + (3 * i)];
				timestamp[i] = (uint8_t)_atoi((const char **)&ptr);
			}
		}
		else
		{
			res = SIM_ERROR;
		}

		serial_printf("Timestamp: %s", param_buf);
		print_timestamp();
	}

	if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		memset(timestamp, 0, sizeof(timestamp));
	}

	return timestamp;
}

sim_state_t sim_open_bearer(char *apn_str, char *user_str, char *pwd_str)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = write_command("+SAPBR", "2,1", 1000);
		break;

	case 1:
		res = SIM_BUSY;

		if (check_param_response("+SAPBR", "1,1"))
		{
			state = 'S';
		}
		else
		{
			state++;
		}
		break;

	case 2:
		res = config_bearer(apn_str, user_str, pwd_str);
		break;

	case 3:
		// sim_serial_pass_through();
		res = toggle_bearer(true);

		if (res == SIM_SUCCESS)
		{
			state = 'S';
		}
		break;

	default:
		state = 0;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_close_bearer(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = write_command("+SAPBR", "2,1", QUICK_RESPONSE_MS);
		break;
	case 1:
		res = SIM_BUSY;

		if (check_param_response("+SAPBR", "1,3"))
		{
			state = 'S';
		}
		else
		{
			state++;
		}
		break;
	case 2:
		res = toggle_bearer(false);
		break;
	default:
		state = 0;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_is_connected(void)
{
	bool res = sim_printf_and_check_response(1000, "+SAPBR: 1,1", "AT+SAPBR=2,1\r");
	res = sim_printf_and_check_response(1000, "OK", "");
	return res ? SIM_SUCCESS : SIM_ERROR;
}

static sim_state_t reset_and_wait_ready(void)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		reset();
		break;
	case 1:
		res = try_autobaud();
		break;
	case 2:
		res = disable_echo();
		break;
	case 3:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static sim_state_t try_autobaud(void)
{
	static uint8_t num_tries = 0;

	if (num_tries == 0)
	{
		log_printf("SIM: AB\n");
	}

// Done with printf directly to avoid logging errors when no response
#ifdef DEBUG
	sim_state_t res = sim_printf_and_check_response(1000, "OK", "AT\r") ? SIM_SUCCESS : SIM_ERROR;
#else
	sim_state_t res = sim_printf_and_check_response(100, "OK", "AT\r") ? SIM_SUCCESS : SIM_ERROR;
#endif

	if (res == SIM_ERROR)
	{
		if (num_tries++ < 100)
		{
			res = SIM_BUSY;
		}
		else
		{
			log_printf("SIM: ERR AB\n");
			num_tries = 0;
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
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

static sim_state_t toggle_local_timestamp(bool on)
{
	return set_param("+CLTS", on ? "1" : "0", 1000);
}

static sim_state_t set_function(sim_function_t func)
{
	char buf[2] = {'1', '\0'};
	buf[0] = func + '0';
	return set_param("+CFUN", buf, 1000);
}

static sim_state_t config_bearer(char *apn_str, char *user_str, char *pwd_str)
{
	bool res = true;

	if (strlen(apn_str))
	{
		res &= sim_printf_and_check_response(100, "OK", "AT+SAPBR=3,1,\"APN\",\"%s\"\r", apn_str);
	}

	if (strlen(user_str))
	{
		res &= sim_printf_and_check_response(100, "OK", "AT+SAPBR=3,1,\"USER\",\"%s\"\r", user_str);
	}

	if (strlen(pwd_str))
	{
		res &= sim_printf_and_check_response(100, "OK", "AT+SAPBR=3,1,\"PWD\",\"%s\"\r", pwd_str);
	}

	if (res)
	{
		return SIM_SUCCESS;
	}

	return SIM_ERROR;
}

static sim_state_t toggle_bearer(bool open)
{
	return write_command("+SAPBR", open ? "1,1" : "0,1", 120000);
}

/*////////////////////////////////////////////////////////////////////////////*/
// Device information
/*////////////////////////////////////////////////////////////////////////////*/

void sim_print_capabilities(void)
{
	sim_printf("at+gcap");
}

/*////////////////////////////////////////////////////////////////////////////*/
// HTTP
/*////////////////////////////////////////////////////////////////////////////*/

sim_state_t sim_http_init(const char *url_str, bool ssl)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		log_printf("SIM: HTTP Init\n");

		sim800.http.response_size = 0;
		sim800.http.status_code = 0;

		break;
	case 1:
		res = sim_http_term();
		break;
	case 2:
		if (sim800.http.state == HTTP_INIT)
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = exec_command("+HTTPINIT", 1000);

			if (res == SIM_SUCCESS)
			{
				sim800.http.state = HTTP_INIT;
			}
		}
		break;
	case 3:
		res = write_command("+HTTPPARA", "\"CID\",\"1\"", 100);
		break;
	case 4:
		res = write_command("+HTTPPARA", "\"REDIR\",\"1\"", 100);
		break;
	case 5:
		if (sim_printf_and_check_response(100, "OK", "AT+HTTPPARA=\"URL\",\"%s\"\r", url_str))
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_ERROR;
		}
		break;
	case 6:
		res = http_toggle_ssl(ssl ? true : false);
		break;
	case 7:
		res = write_command("+SSLOPT", "0,1", 100);
		break;
	case 8:
		res = write_command("+SSLOPT", "1,0", 100);
		break;
	case 9:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		sim800.http.state = HTTP_INIT;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		sim800.http.state = HTTP_ERROR;
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_http_term(void)
{
	sim_state_t res = SIM_ERROR;
	sim_printf_and_check_response(1000, "OK", "AT+HTTPTERM\r");

	res = SIM_SUCCESS;
	sim800.http.state = HTTP_TERM;

	return res;
}

sim_state_t sim_http_get(const char *url_str, bool ssl, uint8_t num_tries)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	static uint8_t tries = 0;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		log_printf("SIM: HTTP Get\n");

		tries = 0;

		break;
	case 1:
		res = sim_http_init(url_str, ssl);
		break;
	case 2:
		if (tries++ < num_tries)
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_ERROR;
		}
		break;
	case 3:
		res = http_action(0);
		break;
	case 4:
		if ((sim800.http.status_code == 200))
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_BUSY;
			state = 2;
		}
		break;
	case 5:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		sim800.http.state = HTTP_DONE;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		sim800.http.state = HTTP_ERROR;
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_http_post_str(const char *url_str, const char *msg_str, bool ssl, uint8_t num_tries)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	static uint8_t tries = 0;
	static uint32_t size = 0;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		log_printf("SIM: HTTP Post Str\n");

		tries = 0;
		size = strlen(msg_str);

		break;
	case 1:
		// sim_serial_pass_through();
		res = sim_http_post_init(url_str, ssl);
		break;
	case 2:
		if (tries++ < num_tries)
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_ERROR;
		}
		break;
	case 3:
		res = sim_http_post_enter_data(size, 2000);
		break;
	case 4:
		res = SIM_SUCCESS;
		sim_printf("%s\r\n", msg_str);
		break;
	case 5:
		res = wait_command("OK", 2000);
		break;
	case 6:
		res = sim_http_post();
		break;
	case 7:
		if ((sim800.http.status_code == 200))
		{
			res = SIM_SUCCESS;
		}
		else
		{
			res = SIM_BUSY;
			state = 2;
		}
		break;
	case 8:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		sim800.http.state = HTTP_ERROR;
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_http_post_init(const char *url_str, bool ssl)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		log_printf("SIM: HTTP Post Init\n");

		break;
	case 1:
		res = sim_http_init(url_str, ssl);
		break;
	case 2:
		res = write_command("+HTTPPARA", "\"CONTENT\",\"application/x-www-form-urlencoded\"", 1000);
		break;
	case 3:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		sim800.http.state = HTTP_ERROR;
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

sim_state_t sim_http_post_enter_data(uint32_t size, uint32_t time)
{
	sim_state_t res = sim_printf_and_check_response(100, "DOWNLOAD", "AT+HTTPDATA=%u,%u\r", size, time) ? SIM_SUCCESS : SIM_ERROR;
	return res;
}

sim_state_t sim_http_post(void)
{
	return http_action(1);
}

uint32_t sim_http_read_response(uint32_t address, uint32_t buf_size, uint8_t *buf)
{
	uint32_t num_ret = 0;
	uint8_t i = 0;

	clear_rx_buf();

	// Request data
	if (!sim_printf_and_check_response(2000, "+HTTPREAD", "AT+HTTPREAD=%u,%u\r", address, buf_size))
	{
		log_error(ERR_SIM_HTTP_READ_TIMEOUT);
	}
	else
	{
		// Get actual number of bytes returned
		char *ptr = &reply_buf[11];

		if (_is_digit(*ptr))
		{
			num_ret = _atoi((const char **)&ptr);
		}

		// Only read up to buf_size
		for (i = 0; i < num_ret; i++)
		{
			while (!sim_available())
			{
			}
			buf[i] = (uint8_t)sim_read();
		}

		// Wait for final ok reply
		sim_printf_and_check_response(1000, "OK", "");
	}

	return num_ret;
}

static sim_state_t http_toggle_ssl(bool on)
{
	return set_param("+HTTPSSL", on ? "1" : "0", 100);
}

static sim_state_t http_action(uint8_t action)
{
	static uint8_t state = 0;
	sim_state_t res = SIM_ERROR;

	switch (state)
	{
	case 0:
		res = SIM_SUCCESS;

		sim800.http.state = HTTP_ACTION;
		break;
	case 1:
		res = write_command("+HTTPACTION", (action == 1) ? "1" : "0", 1000);
		break;
	case 2:
		res = wait_command("+HTTPACTION", 120000);
		break;
	case 3:
		res = SIM_SUCCESS;

		char *ptr;

		// Status code
		ptr = &param_buf[15];
		if (_is_digit(*ptr))
		{
			sim800.http.status_code = _atoi((const char **)&ptr);
		}

		// Response length
		ptr = &param_buf[19];
		if (_is_digit(*ptr))
		{
			sim800.http.response_size = _atoi((const char **)&ptr);
		}

		break;
	case 4:
		state = 'S';
		break;
	default:
		res = SIM_ERROR;
		break;
	}

	// Stop or go to next state
	if (state == 'S')
	{
		res = SIM_SUCCESS;
		state = 0;
	}
	else if (res == SIM_ERROR || res == SIM_TIMEOUT)
	{
		state = 0;
	}
	else if (res == SIM_SUCCESS)
	{
		res = SIM_BUSY;
		state++;
	}

	return res;
}

/*////////////////////////////////////////////////////////////////////////////*/
// TCP
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

/*////////////////////////////////////////////////////////////////////////////*/
// SMS
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_send_sms(const char *phone_number, const char *msg_str)
{
	(void)phone_number;
	(void)msg_str;
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

	_sprintf_clear_buf();

	sim800.func = FUNC_RESET;
	sim800.reg_status = REG_NONE;
	sim800.http.state = HTTP_TERM;
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

	if ((sim_tx_head == sim_tx_tail) && usart_get_flag(SIM_USART, USART_ISR_TXE))
	{
		usart_send(SIM_USART, character);
		done = true;
	}
	else
	{
		while (!done)
		{
			cm_disable_interrupts();

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

			cm_enable_interrupts();
			__asm__("nop");
		}
	}

#ifdef DEBUG
#ifdef FORWARD_TO_SPF
	serial_printf("%c", character);
#endif
#endif
}

static void _putchar_buffer(char character)
{
	_sprintf_buf[_sprintf_buf_idx++] = character;
}

static void print_timestamp(void)
{
	serial_printf("Timestamp: %u", timestamp[0]);
	for (uint8_t i = 1; i < sizeof(timestamp); i++)
	{
		serial_printf("/%u", timestamp[i]);
	}
	serial_printf("\n");
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
