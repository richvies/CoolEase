/**
 ******************************************************************************
 * @file    timers.h
 * @author  Richard Davies
 * @date    20/Jan/2021
 * @brief   Timing and Power Management Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup timers_api Timing and Power Management
 *   @brief    System timing, delays, and power management functionality
 *
 *   This module provides functions for:
 *   - Precise timing and delays
 *   - RTC configuration and access
 *   - Low-power mode management
 *   - Watchdog timer control
 *   - Timeout handling
 * @}
 ******************************************************************************
 */

#ifndef TIMERS_H
#define TIMERS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup timers_api
 * @{
 */

/**
 * @name Timing Helper Macros
 * @{
 */

/**
 * @brief Wait for a condition with microsecond timeout
 *
 * @param cond Condition to wait for
 * @param timeout Timeout in microseconds
 */
#define WAIT_US(cond, timeout)                                                 \
    {                                                                          \
        uint16_t start_time = timers_micros();                                 \
        while (cond) {                                                         \
            if ((uint16_t)(timers_micros() - start_time) > timeout) {          \
                return false;                                                  \
            }                                                                  \
        }                                                                      \
    }

/**
 * @brief Wait for a condition with millisecond timeout
 *
 * @param cond Condition to wait for
 * @param timeout Timeout in milliseconds
 */
#define WAIT_MS(cond, timeout)                                                 \
    {                                                                          \
        uint32_t time = 0;                                                     \
        uint16_t curr_time = timers_micros();                                  \
        while (cond) {                                                         \
            time += (uint16_t)(timers_micros() - curr_time);                   \
            curr_time = timers_micros();                                       \
            if (time > timeout * 1000) {                                       \
                return false;                                                  \
            }                                                                  \
        }                                                                      \
    }

/**
 * @brief General timeout handling with break condition
 *
 * @param time Timeout in microseconds
 * @param print_str String to print on timeout
 * @param print_data Data to print on timeout
 * @param break_condition Condition to break the loop
 * @param if_code Code to execute if break condition is true
 * @param else_code Code to execute if break condition is false
 */
#define TIMEOUT(time, print_str, print_data, break_condition, if_code,         \
                else_code)                                                     \
    {                                                                          \
        timers_timeout_init();                                                 \
        while (!timers_timeout(time, print_str, print_data)) {                 \
            if (break_condition) {                                             \
                if_code break;                                                 \
            } else {                                                           \
                else_code                                                      \
            }                                                                  \
        }                                                                      \
    }
/** @} */

/**
 * @name RTC Functions
 * @{
 */

/**
 * @brief Initialize the real-time clock
 * @return None
 */
void timers_rtc_init(void);

/**
 * @brief Set the RTC time
 * @param year Year (0-99)
 * @param month Month (1-12)
 * @param day Day (1-31)
 * @param hours Hours (0-23)
 * @param mins Minutes (0-59)
 * @param secs Seconds (0-59)
 * @return None
 */
void timers_rtc_set_time(uint8_t year, uint8_t month, uint8_t day,
                         uint8_t hours, uint8_t mins, uint8_t secs);

/**
 * @brief Set the RTC wakeup time
 * @param wakeup_time Wakeup time in seconds
 * @return None
 */
void timers_set_wakeup_time(uint32_t wakeup_time);

/**
 * @brief Clear the RTC wakeup flag
 * @return None
 */
void timers_clear_wakeup_flag(void);

/**
 * @brief Enable the RTC wakeup timer interrupt
 * @return None
 */
void timers_enable_wut_interrupt(void);

/**
 * @brief Disable the RTC wakeup timer interrupt
 * @return None
 */
void timers_disable_wut_interrupt(void);

/**
 * @brief Unlock RTC registers for modification
 * @return None
 */
void timers_rtc_unlock(void);

/**
 * @brief Lock RTC registers to prevent modification
 * @return None
 */
void timers_rtc_lock(void);
/** @} */

/**
 * @name Microsecond Timer Functions
 * @{
 */

/**
 * @brief Initialize the low-power timer for microsecond counting
 *
 * Sets up LPTIM as an approximate microsecond counter.
 * Increments millisecond counter every 1,000 ticks.
 * @return None
 */
void timers_lptim_init(void);

/**
 * @brief Terminate low-power timer operations
 * @return None
 */
void timers_lptim_end(void);

/**
 * @brief Get the current microsecond counter value
 *
 * Returns value of millis_counter * 1000 + micros_counter
 * @return Current microsecond count
 */
uint32_t timers_micros(void);

/**
 * @brief Get the current millisecond counter value
 * @return Current millisecond count
 */
uint32_t timers_millis(void);

/**
 * @brief Delay for a specified number of microseconds
 *
 * Puts CPU into a NOP loop timed by LPTIM1
 * @param delay_microseconds Delay duration in microseconds
 * @return None
 */
void timers_delay_microseconds(uint32_t delay_microseconds);

/**
 * @brief Delay for a specified number of milliseconds
 *
 * Puts CPU into a NOP loop timed by LPTIM1
 * @param delay_milliseconds Delay duration in milliseconds
 * @return None
 */
void timers_delay_milliseconds(uint32_t delay_milliseconds);
/** @} */

/**
 * @name Additional Timer Functions
 * @{
 */

/**
 * @brief Initialize TIM6 as a microsecond counter
 *
 * Sets up TIM6 as an approximate microsecond counter.
 * Clocked by APB1. Not currently used.
 * @return None
 */
void timers_tim6_init(void);
/** @} */

/**
 * @name Watchdog Functions
 * @{
 */

/**
 * @brief Initialize the independent watchdog timer
 * @param period Watchdog period in milliseconds
 * @return None
 */
void timers_iwdg_init(uint32_t period);

/**
 * @brief Reset (feed) the watchdog timers
 *
 * Resets both independent and window watchdog timers
 * @return None
 */
void timers_pet_dogs(void);
/** @} */

/**
 * @name Power Management Functions
 * @{
 */

/**
 * @brief Enter standby (deep sleep) mode
 *
 * Configures the system for standby mode and enters it
 * @return None
 */
void timers_enter_standby(void);
/** @} */

/**
 * @name Timeout Functions
 * @{
 */

/**
 * @brief Initialize the timeout system
 * @return None
 */
void timers_timeout_init(void);

/**
 * @brief Check if a timeout has occurred
 * @param time_microseconds Timeout duration in microseconds
 * @param msg Message to display on timeout
 * @param data Data value to display on timeout
 * @return true if timeout occurred, false otherwise
 */
bool timers_timeout(uint32_t time_microseconds, char* msg, uint32_t data);
/** @} */

/** @} */ /* End of timers_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // TIMERS_H
