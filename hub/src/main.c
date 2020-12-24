/**
******************************************************************************
* @file    main.c
* @author  Richard Davies
* @brief   CoolEase Hub Main Function
*/


#include <stddef.h>

#include <hub/cusb.h>

int main(void)
{
  cusb_init();
  cusb_test_poll();

  return 0;
}
