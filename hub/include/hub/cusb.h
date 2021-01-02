/**
 ******************************************************************************
 * @file    cusb.h
 * @author  Richard Davies
 * @date    25/Dec/2020
 * @brief   Hub USB driver header file
 *  
 * @defgroup    CUSB_FILE  Cusb
 * @brief       Hub USB HID driver
 * 
 * Manages the USB Device
 * 
 * @note     
 * 
 * @{
 * @defgroup   CUSB_API  Cusb API
 * @brief      Programming interface and key macros
 * 
 * @defgroup   CUSB_INT  Cusb Internal
 * @brief      Static Vars, Functions & Internal Macros
 * 
 * @defgroup   CUSB_CFG  Cusb Configuration
 * @brief      USB HID descriptors
 * @}
 ******************************************************************************
 */

#ifndef CUSB_H
#define CUSB_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CUSB_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/


/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Initialize clock and interrupts */
void cusb_init(void);

void cusb_test_poll(void);
void cusb_send(char character);

/** @brief True if usb state is CONNECTED
 * 
 * Set by hid config callback after 
 * host has requested HID configuration
 * 
 * @ref usb_state \n
 * @ref hid_set_config()
 */
bool cusb_connected(void);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // CUSB_H 