/**
 ******************************************************************************
 * @file    sensor.h
 * @author  Richard Davies
 * @date    18/Jan/2021
 * @brief   Sensor Header File
 *
 * @defgroup   SENSOR_FILE  Sensor
 * @brief
 *
 * Description
 *
 * @note
 *
 * @{
 * @defgroup   SENSOR_API  Sensor API
 * @brief
 *
 * @defgroup   SENSOR_INT  Sensor Internal
 * @brief
 * @}
 ******************************************************************************
 */

#ifndef SENSOR_H
#define SENSOR_H

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

/** @addtogroup SENSOR_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

#define VERSION 100

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */

#ifdef __cplusplus
}
#endif

#endif // SENSOR_H