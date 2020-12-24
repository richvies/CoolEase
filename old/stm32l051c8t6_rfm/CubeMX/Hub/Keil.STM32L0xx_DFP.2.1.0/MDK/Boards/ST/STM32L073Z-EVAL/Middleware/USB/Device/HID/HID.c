/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::USB:Device
 * Copyright (c) 2004-2017 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HID.c
 * Purpose: USB Device - Human Interface Device example
 *----------------------------------------------------------------------------*/

#include "main.h"
#include "rl_usb.h"                     /* RL-USB function prototypes         */

#include "Board_Buttons.h"
#include "Board_LED.h"

// Main stack size must be multiple of 8 Bytes
#define APP_MAIN_STK_SZ (1024U)
uint64_t app_main_stk[APP_MAIN_STK_SZ / 8];
const osThreadAttr_t app_main_attr = {
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk)
};


/*------------------------------------------------------------------------------
 *        Application
 *----------------------------------------------------------------------------*/
__NO_RETURN void app_main (void *arg) {
  uint8_t but, buf = 0;

  (void)arg;

  LED_Initialize    ();                 /* LED Initialization                 */
  Buttons_Initialize();                 /* Buttons Initialization             */

  USBD_Initialize(0U);                  /* USB Device 0 Initialization        */
  USBD_Connect   (0U);                  /* USB Device 0 Connect               */

  for (;;) {                            /* Loop forever                       */
    but = (uint8_t)(Buttons_GetState ());
    if (but ^ buf) {
      buf = but;
      USBD_HID_GetReportTrigger(0, 0, &buf, 1);
    }
    osDelay(100U);                      /* 100 ms delay for sampling buttons  */
  }
}
