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


void sim_init(void);
void sim_end(void);
void sim_printf(const char* format, ...);
bool check_for_response(char *str);
void sim_serial_pass_through(void);
bool sim_available(void);
char sim_read(void);

void sim_print_capabilities(void);
void sim_connect(void);
void sim_send_data(uint8_t *data, uint8_t len);
bool sim_get_bin(void);

// void sim_send_temp(rfm_packet_t *packet_start,  uint8_t len);
// void sim_send_temp_and_num(rfm_packet_t *packet_start,  uint8_t len);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // SIM_H