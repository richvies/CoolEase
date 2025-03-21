/**
 ******************************************************************************
 * @file    cusb.h
 * @author  Richard Davies
 * @date    04/Jan/2021
 * @brief   Hub USB driver header file
 *
 * @defgroup hub Hub
 * @{
 *   @defgroup cusb_api USB HID Driver
 *   @brief    Hub USB HID driver interface for device management
 * @}
 ******************************************************************************
 */

#ifndef CUSB_H
#define CUSB_H

#include <stdbool.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup hub
 * @{
 */

/** @addtogroup cusb_api
 * @{
 */

// Exported Variables

// Exported Function Declarations

/**
 * @brief Initialize USB clock and interrupts
 * @return None
 */
void cusb_init(void);

/**
 * @brief Terminate USB operations
 * @return None
 */
void cusb_end(void);

/**
 * @brief Check if USB is in connected state
 *
 * Set by HID config callback after host has requested HID configuration
 *
 * @return true if connected, false otherwise
 */
bool cusb_connected(void);

/**
 * @brief Check if USB is in reset state
 * @return true if reset, false otherwise
 */
bool cusb_reset(void);

/**
 * @brief Check if USB device is physically connected
 * @return true if plugged in, false otherwise
 */
bool cusb_plugged_in(void);

/**
 * @brief Poll USB for events
 * @return None
 */
void cusb_poll(void);

/**
 * @brief Send a character over USB
 * @param character Character to send
 * @return None
 */
void cusb_send(char character);

/**
 * @brief Hook function for USB reset events
 * @return None
 */
void cusb_hook_reset(void);

/**
 * @brief Hook function for HID OUT report events
 *
 * This is called when data is received from host.
 *
 * @return None
 */
void cusb_hook_hid_out_report(void);

/**
 * @brief Hook function for HID IN report events
 *
 * This is called when data is requested by host.
 *
 * @return None
 */
void cusb_hook_hid_in_report(void);

/** @} */ /* End of cusb_api group */
/** @} */ /* End of hub group */

#ifdef __cplusplus
}
#endif

#endif // CUSB_H
