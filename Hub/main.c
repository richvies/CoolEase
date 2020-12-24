/**
  ******************************************************************************
  * @file    main.c
  * @author  Richard Davies
  * @brief   CoolEase Hub Main Function
  */


#include <stddef.h>

#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/cm3/nvic.h>

#include <libopencm3/usb/usbd.h>
#include "../libopencm3/lib/usb/usb_private.h"
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/usb/hid.h>

int main(void)
{   
    /** Initialize clocks */
    usb_clock_init();

    /** Reset USB */
    SET_REG(USB_CNTR_REG, USB_CNTR_FRES);
    SET_REG(USB_CNTR_REG, 0);
    SET_REG(USB_ISTR_REG, 0);

    /** Initialize USB */
    usbd_device *usbd_dev = usbd_init(&st_usbfs_v2_usb_driver, &dev_desc, &cfg_desc, string_desc, sizeof(string_desc) / sizeof(const char*), usbd_control_buffer, sizeof(usbd_control_buffer));
    
    /** Register Configuration Callback for HID */
    usbd_register_set_config_callback(usbd_dev, hid_set_config);

    while (1)
    {
      usbd_poll(usbd_dev);
    }
    

    return 0;
}
