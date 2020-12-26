/**
******************************************************************************
* @file    test_hub.c
* @author  Richard Davies
* @brief   CoolEase Hub testing source file
*/

/** @addtogroup TEST_HUB_FILE 
 * @{
 */

#include "hub/test_hub.h"

#include "hub/cusb.h"
#include "hub/bootloader.h"

void test_cusb_poll(void)
{
  cusb_init();
  cusb_test_poll();
}

/** @} */