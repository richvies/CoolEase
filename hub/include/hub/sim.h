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


bool sim_init(void);
bool sim_end(void);

// Communication

void sim_printf(const char *format, ...);

/** @brief Print to SIM800 then wait for expected response or timeout */
bool sim_printf_and_check_response(uint32_t timeout_ms, const char *expected_response, const char *format, ...);
void sim_serial_pass_through(void);
bool sim_available(void);
char sim_read(void);


void sim_print_capabilities(void);
bool sim_connect(void);
uint32_t sim_http_get(const char *url);
uint32_t sim_http_read_response(uint32_t address, uint32_t num_bytes);
bool sim_http_term(void);
bool sim_send_data(uint8_t *data, uint8_t len);

// void sim_send_temp(rfm_packet_t *packet_start,  uint8_t len);
// void sim_send_temp_and_num(rfm_packet_t *packet_start,  uint8_t len);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // SIM_H