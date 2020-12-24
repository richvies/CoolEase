/**
******************************************************************************
* @file    main.c
* @author  Richard Davies
* @brief   CoolEase Hub Main Function
*/


#include <stddef.h>

#include <hub/cusb.h>

#include <hub/testing.h>
#include <common/testing.h>

int main(void)
{
  cusb_init();
  cusb_test_poll();

  return 0;
}
