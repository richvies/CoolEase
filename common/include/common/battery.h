/**
 ******************************************************************************
 * @file    battery.h
 * @author  Richard Davies
 * @date    20/Jan/2021
 * @brief   Battery Management Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup battery_api Battery Management
 *   @brief    Battery monitoring and power management functionality
 *
 *   This module provides functions for monitoring battery voltage,
 *   detecting power source changes, and managing power consumption.
 * @}
 ******************************************************************************
 */

#ifndef BATTERY_H
#define BATTERY_H

// Includes
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

/** @addtogroup battery_api
 * @{
 */

/**
 * @brief Initialize the battery monitoring system
 * @return None
 */
void batt_init(void);

/**
 * @brief Terminate battery monitoring operations
 * @return None
 */
void batt_end(void);

/**
 * @brief Set the voltage scale for power management
 * @param scale Voltage scale value (1-3)
 * @return None
 */
void batt_set_voltage_scale(uint8_t scale);

/**
 * @brief Enter low power run mode
 * @return None
 */
void batt_set_low_power_run(void);

/**
 * @brief Calculate battery and power supply voltages
 * @return None
 */
void batt_calculate_voltages(void);

/**
 * @brief Update voltage readings from ADC
 * @return None
 */
void batt_update_voltages(void);

/**
 * @brief Enable battery monitoring interrupt
 * @return None
 */
void batt_enable_interrupt(void);

/**
 * @brief Disable battery monitoring interrupt
 * @return None
 */
void batt_disable_interrupt(void);

/**
 * @brief Check if external power is connected
 * @return true if external power is connected, false otherwise
 */
bool batt_is_plugged_in(void);

/**
 * @brief Check if battery monitoring system is ready
 * @return true if ready, false otherwise
 */
bool batt_is_ready(void);

/**
 * @brief Get the current battery voltage
 * @return Battery voltage in millivolts
 */
uint16_t batt_get_batt_voltage(void);

/**
 * @brief Get the current power supply voltage
 * @return Power supply voltage in millivolts
 */
uint16_t batt_get_pwr_voltage(void);

/** @} */ /* End of battery_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // BATTERY_H
