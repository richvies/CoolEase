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
 * @{
 * @defgroup   CUSB_CFG  Cusb Configuration
 * @brief      USB HID descriptors
 * @}
 ******************************************************************************
 */

#ifndef CUSB_H
#define CUSB_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CUSB_API
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Exported Variables
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Exported Function Declarations
////////////////////////////////////////////////////////////////////////////////

void cusb_init(void);
void cusb_test_poll(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* CUSB_H */