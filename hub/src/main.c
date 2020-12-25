/**
******************************************************************************
* @file    main.c
* @author  Richard Davies
* @brief   CoolEase Hub Main Function
*/

#include <stddef.h>

#include <hub/cusb.h>

#include <hub/test_hub.h>
#include <common/testing.h>

int main(void)
{

  cusb_init();

  return 0;
}
