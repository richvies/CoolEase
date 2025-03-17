/**
 ******************************************************************************
 * @file    battery.h
 * @author  Richard Davies
 * @date    20/Jan/2021
 * @brief   Battery Header File
 *
 * @defgroup   BATTERY_FILE  Battery
 * @brief
 *
 * Description
 *
 * @note
 *
 * @{
 * @defgroup   BATTERY_API  Battery API
 * @brief
 *
 * @defgroup   BATTERY_INT  Battery Internal
 * @brief
 * @}
 ******************************************************************************
 */

#ifndef BATTERY_H
#define BATTERY_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup BATTERY_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void batt_init(void);
void batt_end(void);

void batt_set_voltage_scale(uint8_t scale);
void batt_set_low_power_run(void);
void batt_calculate_voltages(void);
void batt_update_voltages(void);
void batt_enable_interrupt(void);
void batt_disable_interrupt(void);

bool batt_is_plugged_in(void);
bool batt_is_ready(void);

uint16_t batt_get_batt_voltage(void);
uint16_t batt_get_pwr_voltage(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // BATTERY_H