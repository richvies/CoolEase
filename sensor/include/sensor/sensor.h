/**
 ******************************************************************************
 * @file    sensor.h
 * @author  Richard Davies
 * @date    18/Jan/2021
 * @brief   Sensor Module Header File
 *
 * @defgroup sensor Sensor
 * @{
 *   @defgroup sensor_api Sensor Interface
 *   @brief    Core sensor functionality and interfaces
 *
 *   The sensor module provides the core functionality for sensor devices,
 *   including measurement, calibration, and communication capabilities.
 *   It serves as the main interface for interacting with sensor hardware.
 * @}
 ******************************************************************************
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sensor
 * @{
 */

/** @addtogroup sensor_api
 * @{
 */

/**
 * @brief Sensor firmware version number
 */
#define VERSION 100

// Add sensor API functions here

/** @} */ /* End of sensor_api group */
/** @} */ /* End of sensor group */

#ifdef __cplusplus
}
#endif

#endif // SENSOR_H
