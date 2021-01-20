/**
 ******************************************************************************
 * @file    timers.h
 * @author  Richard Davies
 * @date    20/Jan/2021
 * @brief   Timers Header File
 *  
 * @defgroup   TIMERS_FILE  Timers
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   TIMERS_API  Timers API
 * @brief      
 * 
 * @defgroup   TIMERS_INT  Timers Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef TIMERS_H
#define TIMERS_H

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

/** @addtogroup TIMERS_API
 * @{
 */

// Helper functions
#define WAIT_US(cond, timeout)  {   uint16_t start_time = timers_micros(); \
                                    while(cond){ \
                                    if((uint16_t)( timers_micros() - start_time ) > timeout){ \
                                    return false; }}}
#define WAIT_MS(cond, timeout)  {   uint32_t time = 0; \
                                    uint16_t curr_time = timers_micros(); \
                                    while(cond){ \
                                    time += (uint16_t)(timers_micros() - curr_time); \
                                    curr_time = timers_micros(); \
                                    if(time > timeout * 1000){ \
                                    return false;}}}

#define TIMEOUT(time, print_str, print_data, break_condition, if_code, else_code)    timeout_init(); \
  	                                                                        while(!timeout(time, print_str, print_data)) { \
  	  	                                                                        if(break_condition){ if_code break; } \
		                                                                        else{ else_code }}

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/* Start Low Speed Oscillator and Configure RTC, IWDG & WWDG Registers */
void timers_rtc_init(uint32_t standby_time_seconds);

/* Measure LSI frequency with TIM21 */
uint32_t timers_lsi_freq(void);


/* Setup lptim approx. us counter. Clocked by APB1 
    Inrements millis counter every 1,000 ticks */
void timers_lptim_init(void);

/* Returns value of lptimer */
uint32_t timers_micros(void);

/* Returns value of millis_counter */
uint32_t timers_millis(void);

/* Simple delay function. Puts cpu into nop loop timed by lptim1 */
void timers_delay_microseconds(uint32_t delay_microseconds);

/* Simple delay function. Puts cpu into nop loop timed by lptim1 */
void timers_delay_milliseconds(uint32_t delay_milliseconds);


/* Setup TIM6 as approx. microsecond counter. Clocked by APB1. Not currently used */
void timers_tim6_init(void);

/* Setup independant watchdog timer */
void timers_iwdg_init(uint32_t period);

/* Reset independant and window watchdog timers */
void timers_pet_dogs(void);


/* Enter standby mode */
void timers_enter_standby(void);

/* Timout functions */
void timeout_init(void);
bool timeout(uint32_t time_microseconds, char *msg, uint32_t data);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // TIMERS_H
