/**
 ******************************************************************************
 * @file    hub.h
 * @author  Richard Davies
 * @date    18/Jan/2021
 * @brief   Hub Header File
 *
 * @defgroup   HUB_FILE  Hub
 * @brief
 *
 * Description
 *
 * @note
 *
 * @{
 * @defgroup   HUB_API  Hub API
 * @brief
 *
 * @defgroup   HUB_INT  Hub Internal
 * @brief
 * @}
 ******************************************************************************
 */

#ifndef HUB_H
#define HUB_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"
#include "config/board_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup HUB_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

sensor_t* get_sensor_by_id(uint32_t dev_id);
void      clean_sensors(void);
void      add_sensor(uint32_t dev_id);
void      rem_sensor(uint32_t dev_id);
void      print_sensors(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif // HUB_H