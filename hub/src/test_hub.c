/**
******************************************************************************
* @file    test_hub.c
* @author  Richard Davies
* @brief   CoolEase Hub testing source file
*/

/** @addtogroup TEST_HUB_FILE 
 * @{
 */

#include <hub/testing.h>
#include <hub/cusb.h>

void test_cusb_poll(void)
{
    cusb_init();
  cusb_test_poll();
}

/** @} */