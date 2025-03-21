/**
 ******************************************************************************
 * @file    sensor_bootloader.h
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Sensor Bootloader Header File
 *
 * @defgroup sensor Sensor
 * @{
 *   @defgroup bootloader_api Bootloader Interface
 *   @brief    Sensor bootloader functionality and interfaces
 *
 *   The sensor bootloader provides firmware update capabilities for sensor
 *   devices. It handles the secure boot process and firmware verification.
 * @}
 ******************************************************************************
 */

#ifndef SENSOR_BOOTLOADER_H
#define SENSOR_BOOTLOADER_H

// Includes

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sensor
 * @{
 */

/** @addtogroup bootloader_api
 * @{
 */

/**
 * @brief Bootloader version number
 */
#define VERSION 100

// Add bootloader API functions here

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_BOOTLOADER_H */
