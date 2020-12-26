/**
******************************************************************************
* @file    hub.c
* @author  Richard Davies
* @brief   CoolEase Hub Main Function
*/

#include "hub/test_hub.h"
#include "common/testing.h"

#define APP_ADDRESS 0x08002000

int main(void)
{

  // test_cusb_poll();
  test_boot(APP_ADDRESS);

  return 0;
}
