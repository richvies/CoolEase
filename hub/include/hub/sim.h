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



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Setup & Communication
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Enable MCU USART, reset SIM800 into minimum func mode & disable command echo */
bool sim_init(void);

bool sim_set_full_function(void);

/** @brief Enter sleep mode and disable MCU USART */
bool sim_end(void);

void sim_printf(const char *format, ...);

/** @brief Print to SIM800 then wait for expected response or timeout */
bool sim_printf_and_check_response(uint32_t timeout_ms, const char *expected_response, const char *format, ...);

void sim_serial_pass_through(void);

bool sim_available(void);

char sim_read(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Device information
/*////////////////////////////////////////////////////////////////////////////*/

void sim_print_capabilities(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Network Configuration
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_register_to_network(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Internet Access
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief HTTP get request. Must be null terminalted string for url 
 * 	Must call http term after using this function 
 * 
 * @ref sim_http_term()
 * 
 * @param url_str Null terminated string for url to get
 */
uint32_t sim_http_get(const char *url);

uint32_t sim_http_read_response(uint32_t address, uint32_t num_bytes);

bool sim_http_term(void);

bool sim_send_data(uint8_t *data, uint8_t len);

/*////////////////////////////////////////////////////////////////////////////*/
// SMS
/*////////////////////////////////////////////////////////////////////////////*/

bool sim_send_sms(const char *phone_number, const char *str);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // SIM_H