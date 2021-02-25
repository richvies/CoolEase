/**
 ******************************************************************************
 * @file    sim.h
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   Sim Header File
 *  
 * @defgroup   SIM_FILE  Sim
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   SIM_API  Sim API
 * @brief      
 * 
 * @defgroup   SIM_INT  Sim Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef SIM_H
#define SIM_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "common/log.h"
#include "common/memory.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup SIM_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

typedef enum sim_state
{
    SIM_BUSY = 0,
    SIM_SUCCESS,
    SIM_TIMEOUT,
    SIM_ERROR
} sim_state_t;

typedef enum sim_function
{
	FUNC_MIN = 0,
	FUNC_FULL = 1,
	FUNC_NO_RF = 4,
	FUNC_OFF,
	FUNC_RESET,
	FUNC_SLEEP
} sim_function_t;

typedef enum registration_status
{
	REG_NONE = 0,
	REG_HOME,
	REG_SEARCHING,
	REG_DENIED,
	REG_UNKNOWN,
	REG_ROAMING
} registration_status_t;

typedef enum http_state
{
	HTTP_TERM = 0,
	HTTP_INIT,
	HTTP_ACTION,
	HTTP_DONE,
	HTTP_ERROR
} http_state_t;

typedef struct sim800_s
{
    sim_state_t             state;
    sim_function_t          func;
    registration_status_t   reg_status;

    struct http_params
    {
        http_state_t    state;
        uint32_t        status_code;
        uint32_t        response_size;
    } http; 
} sim800_t;

extern sim800_t sim800;


/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Comms
/*////////////////////////////////////////////////////////////////////////////*/

void sim_printf(const char *format, ...);

/** @brief Print to SIM800 then wait for expected response or timeout */
bool sim_printf_and_check_response(uint32_t timeout_ms, const char *expected_response, const char *format, ...);

void sim_serial_pass_through(void);

void sim_print_state(sim_state_t res);

bool sim_available(void);

char sim_read(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Setup & Config
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Enable MCU USART, reset SIM800 into minimum func mode & disable command echo */
sim_state_t sim_init(void);

/** @brief Enter sleep mode and disable MCU USART */
sim_state_t sim_end(void);

sim_state_t sim_sleep(void);

sim_state_t sim_register_to_network(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Device information
/*////////////////////////////////////////////////////////////////////////////*/

void sim_print_capabilities(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Network Configuration
/*////////////////////////////////////////////////////////////////////////////*/

uint8_t *sim_get_timestamp(void);
sim_state_t sim_open_bearer(char *apn_str, char *user_str, char *pwd_str);
sim_state_t sim_close_bearer(void);
sim_state_t sim_is_connected(void);

/*////////////////////////////////////////////////////////////////////////////*/
// HTTP
/*////////////////////////////////////////////////////////////////////////////*/

sim_state_t sim_http_init(const char *url_str, bool ssl);
sim_state_t sim_http_term(void);
sim_state_t sim_http_get(const char *url_str, bool ssl, uint8_t num_tries);
sim_state_t sim_http_post_str(const char *url_str, const char *msg_str, bool ssl, uint8_t num_tries);
sim_state_t sim_http_post_init(const char *url_str, bool ssl);
sim_state_t sim_http_post_enter_data(uint32_t size, uint32_t time);
sim_state_t sim_http_post(void);
uint32_t sim_http_read_response(uint32_t address, uint32_t num_bytes);

/*////////////////////////////////////////////////////////////////////////////*/
// TCP
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_tcp_init(const char *url_str, uint16_t port, bool ssl);

/*////////////////////////////////////////////////////////////////////////////*/
// SMS
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_send_sms(const char *phone_number, const char *str);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // SIM_H