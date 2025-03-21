/**
 ******************************************************************************
 * @file    hub.h
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   Hub Header File
 *
 * @defgroup hub Hub
 * @brief    Hub module for sensor management
 *
 * @{
 *   @defgroup hub_apis Hub APIs
 *   @brief    Public interfaces for sensor management
 * @}
 ******************************************************************************
 */

#ifndef HUB_H
#define HUB_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"
#include "config/board_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup hub
 * @{
 */

/** @addtogroup hub_apis
 * @{
 */

/**
 * @brief  Retrieves a sensor by its device ID
 * @param  dev_id: Device identifier
 * @return Pointer to the sensor structure if found, NULL otherwise
 */
sensor_t* get_sensor_by_id(uint32_t dev_id);

/**
 * @brief  Cleans up all sensor resources
 * @return None
 */
void clean_sensors(void);

/**
 * @brief  Adds a new sensor to the system
 * @param  dev_id: Device identifier for the new sensor
 * @return None
 */
void add_sensor(uint32_t dev_id);

/**
 * @brief  Removes a sensor from the system
 * @param  dev_id: Device identifier of the sensor to remove
 * @return None
 */
void rem_sensor(uint32_t dev_id);

/**
 * @brief  Prints information about all registered sensors
 * @return None
 */
void print_sensors(void);

/** @} */ /* End of hub_apis group */
/** @} */ /* End of hub group */

#ifdef __cplusplus
}
#endif

#endif // HUB_H
