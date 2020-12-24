/**
  ******************************************************************************
  * @file    cusb.c
  * @author  Richard Davies
  * @brief   CoolEase Hub USB driver source file
  */


#include <stddef.h>

#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/cm3/nvic.h>

#include <libopencm3/usb/usbd.h>
#include "../../libopencm3/lib/usb/usb_private.h"
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/usb/hid.h>

/** @addtogroup CUSB_FILE 
 * @{
 */

/************************************************************ 
 * USB Descriptors:
 * Device
 * Configuration
 * Interface
 * Endpoints
 * Strings
 * 
 * HID Descriptor
 * Report
 ************************************************************/

/** @addtogroup CUSB_CFG
 * @{
 */

/** @brief Interfaces used */
enum 
{
  INTERFACE_HID = 0,
  // The next two must be consecutive since they are used in an Interface
    // Assication below. If the order is changed then the IAD must be changed as
    // well
  INTERFACE_CDC_COMM = 1,
  INTERFACE_CDC_DATA = 2,
  INTERFACE_KEYBOARD_HID = 3,
  INTERFACE_COUNT = 1,
};

/** @brief Required endpoint addresses for interfaces */
enum 
{
  ENDPOINT_HID_IN = 0x81,
  ENDPOINT_HID_OUT = 0x01,
  ENDPOINT_CDC_COMM_IN = 0x83,
  ENDPOINT_CDC_DATA_IN = 0x82,
  ENDPOINT_CDC_DATA_OUT = 0x02,
  ENDPOINT_KEYBOARD_HID_IN = 0x84,
};

enum 
{
  HID_GET_REPORT = 1,
  HID_GET_IDLE = 2,
  HID_GET_PROTOCOL = 3,
  HID_SET_REPORT = 9,
  HID_SET_IDLE = 10,
  HID_SET_PROTOCOL = 11,
};

/** @brief String Descriptors */
#define USB_VID                         0x0483
#define USB_PID                         0x5750

/** @brief Location of specific strings within string descriptors stuct */
enum usb_strings_index
{
  USB_LANGID_IDX = 0,
  USB_MANUFACTURER_IDX,
  USB_PRODUCT_IDX,
  USB_SERIAL_IDX,
  USB_CONFIGURATION_IDX,
  USB_INTERFACE_IDX,
};

/** @brief Structure containing all string descriptors, indexed by @ref usb_strings_index */
static const char * const string_desc[] = 
{
  "CoolEase",
  "CoolEase Hub",
  "12345",
  "Custom HID Config"
  "Custom HID Interface",
};


/** @brief USB Device Descriptor */
static const struct usb_device_descriptor dev_desc = 
{
  .bLength            = USB_DT_DEVICE_SIZE,
	.bDescriptorType    = USB_DT_DEVICE,
	.bcdUSB             = 0x0200,
	.bDeviceClass       = 0x00,
	.bDeviceSubClass    = 0x00,
	.bDeviceProtocol    = 0x00,
	.bMaxPacketSize0    = 64,
	.idVendor           = USB_VID,
	.idProduct          = USB_PID,
	.bcdDevice          = 0x0200,
	.iManufacturer      = USB_MANUFACTURER_IDX,
	.iProduct           = USB_PRODUCT_IDX,
	.iSerialNumber      = USB_SERIAL_IDX,
	.bNumConfigurations = 1
};


/** @brief USB Device HID Endpoint Descriptors */
static const struct usb_endpoint_descriptor hid_interface_endpoints[] = 
{
  {
    // The size of the endpoint descriptor in bytes: 7.
    .bLength = USB_DT_ENDPOINT_SIZE,
    // A value of 5 indicates that this describes an endpoint.
    .bDescriptorType = USB_DT_ENDPOINT,
    // Bit 7 indicates direction: 0 for OUT (to device) 1 for IN (to host).
        // Bits 6-4 must be set to 0.
        // Bits 3-0 indicate the endpoint number (zero is not allowed).
        // Here we define the IN side of endpoint 1.
    .bEndpointAddress = ENDPOINT_HID_IN,
    // Bit 7-2 are only used in Isochronous mode, otherwise they should be
        // 0.
        // Bit 1-0: Indicates the mode of this endpoint.
        // 00: Control
        // 01: Isochronous
        // 10: Bulk
        // 11: Interrupt
        // Here we're using interrupt.
    .bmAttributes = USB_ENDPOINT_ATTR_INTERRUPT,
    // Maximum packet size.
    .wMaxPacketSize = 64,
    // The frequency, in number of frames, that we're going to be sending
        // data. Here we're saying we're going to send data every millisecond.
    .bInterval = 1,
  },
  {
    // The size of the endpoint descriptor in bytes: 7.
    .bLength = USB_DT_ENDPOINT_SIZE,
    // A value of 5 indicates that this describes an endpoint.
    .bDescriptorType = USB_DT_ENDPOINT,
    // Bit 7 indicates direction: 0 for OUT (to device) 1 for IN (to host).
        // Bits 6-4 must be set to 0.
        // Bits 3-0 indicate the endpoint number (zero is not allowed).
        // Here we define the OUT side of endpoint 1.
    .bEndpointAddress = ENDPOINT_HID_OUT,
    // Bit 7-2 are only used in Isochronous mode, otherwise they should be
        // 0.
        // Bit 1-0: Indicates the mode of this endpoint.
        // 00: Control
        // 01: Isochronous
        // 10: Bulk
        // 11: Interrupt
        // Here we're using interrupt.
    .bmAttributes = USB_ENDPOINT_ATTR_INTERRUPT,
    // Maximum packet size.
    .wMaxPacketSize = 64,
    // The frequency, in number of frames, that we're going to be sending
        // data. Here we're saying we're going to send data every millisecond.
    .bInterval = 1,
  }
};


/** @brief HID Report Descriptor
 * 
 * The data below is an HID report descriptor. The first byte in each item
 * indicates the number of bytes that follow in the lower two bits. The next two
 * bits indicate the type of the item. The remaining four bits indicate the tag.
 * Words are stored in little endian.
 */
static const uint8_t hid_report_descriptor[] = 
{
  0x06, 0x00, 0xff,              // USAGE_PAGE (Vendor Defined Page 1)
  0x09, 0x01,                    // USAGE (Vendor Usage 1)
  0xa1, 0x01,                    // COLLECTION (Application)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
  0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
  0x75, 0x08,                    //   REPORT_SIZE (8)
  0x95, 0x40,                    //   REPORT_COUNT (64)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
  0xc0                           // END_COLLECTION
};

/** @brief HID Function Descriptor
 */
static const struct 
{
  struct usb_hid_descriptor hid_descriptor;
  struct 
  {
    uint8_t bReportDescriptorType;
    uint16_t wDescriptorLength;
  } __attribute__((packed)) hid_report;
} __attribute__((packed)) hid_function = 
{
  .hid_descriptor = 
  {
    // The size of this header in bytes: 9.
    .bLength = sizeof(hid_function),
    // The type of this descriptor. HID is indicated by the value 33.
    .bDescriptorType = USB_DT_HID,
    // The version of the HID spec used in binary coded  decimal. We are
    // using version 1.11.
    .bcdHID = 0x0111,
    // Some HID devices, like keyboards, can specify different country
    // codes. A value of zero means not localized.
    .bCountryCode = 0,
    // The number of descriptors that follow. This must be at least one
    // since there should be at least a report descriptor.
    .bNumDescriptors = 1,
  },
    // The report descriptor.
  .hid_report = 
  {
    // The type of descriptor. A value of 34 indicates a report.
    .bReportDescriptorType = USB_DT_REPORT,
    // The size of the descriptor defined above.
    .wDescriptorLength = sizeof(hid_report_descriptor),
  },
};

/** @brief HID Interface Descriptor */
const struct usb_interface_descriptor hid_interface = 
{
    // The size of an interface descriptor: 9
    .bLength = USB_DT_INTERFACE_SIZE,
    // A value of 4 specifies that this describes and interface.
    .bDescriptorType = USB_DT_INTERFACE,
    // The number for this interface. Starts counting from 0.
    .bInterfaceNumber = INTERFACE_HID,
    // The number for this alternate setting for this interface.
    .bAlternateSetting = 0,
    // The number of endpoints in this interface.
    .bNumEndpoints = 2,
    // The interface class for this interface is HID, defined by 3.
    .bInterfaceClass = USB_CLASS_HID,
    // The interface subclass for an HID device is used to indicate of this is a
    // mouse or keyboard that is boot mode capable (1) or not (0).
    .bInterfaceSubClass = 0, // Not a boot mode mouse or keyboard.
    .bInterfaceProtocol = 0, // Since subclass is zero then this must be too.
    // A string representing this interface. Zero means not provided.
    .iInterface = USB_INTERFACE_IDX,
    // The header ends here.

    // A pointer to the beginning of the array of endpoints.
    .endpoint = hid_interface_endpoints,

    // Some class types require extra data in the interface descriptor.
    // The libopencm3 usb library requires that we stuff that here.
    // Pointer to the buffer holding the extra data.
    .extra = &hid_function,
    // The length of the data at the above address.
    .extralen = sizeof(hid_function),
};

/** @brief Struct containing all used interfaces */
const struct usb_interface interfaces[] = 
{
  {
    .num_altsetting = 1,
    .altsetting = &hid_interface,
  }
};


/** @brief USB Device Config Descriptor */
static const struct usb_config_descriptor cfg_desc = 
{
  .bLength                = USB_DT_CONFIGURATION_SIZE,
  .bDescriptorType        = USB_DT_CONFIGURATION,
  .wTotalLength           = 0, /**< Total size of descriptor + all interfaces. Auto filled by usb stack in libopencm3 */
  .bNumInterfaces         = INTERFACE_COUNT,
  .bConfigurationValue    = 1,
  .iConfiguration         = USB_CONFIGURATION_IDX,
  .bmAttributes           = 0b10000000, /**< Bit flags. 7: Must be set to 1. 6: Self Powered. 5: Supports remote wakeup. 4-0: Must be set to 0.*/
  .bMaxPower              = 200, /**< mA / 2 */
  .interface              = interfaces,
};

/** @} */

/****************************************************************** 
 * HID Callback functions and buffer definitions
 ******************************************************************/
/** @addtogroup CUSB_INT
 * @{
 */

/** @brief Buffer to be used for control requests. */
uint8_t usbd_control_buffer[128];

/** @brief HID Control Callback 
 * 
 * Sends hid report descriptor to host
*/
static enum usbd_request_return_codes hid_control_request(usbd_device *dev, struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
			void (**complete)(usbd_device *, struct usb_setup_data *))
{
	(void)complete;
	(void)dev;

	if((req->bmRequestType != 0x81) ||
	   (req->bRequest != USB_REQ_GET_DESCRIPTOR) ||
	   (req->wValue != 0x2200))
		return USBD_REQ_NOTSUPP;

	/* Handle the HID report descriptor. */
	*buf = (uint8_t *)hid_report_descriptor;
	*len = sizeof(hid_report_descriptor);

	return USBD_REQ_HANDLED;
}

/** @brief HID Report buffer 
 * 
 * Buffer used for all HID in & out transactions
*/
uint8_t hid_report_buf[64];

/** @brief HID Resport Callback */
void hid_report_callback(usbd_device *usbd_dev, uint8_t ea);
void hid_report_callback(usbd_device *usbd_dev, uint8_t ea){
    usbd_ep_write_packet(usbd_dev, ea, hid_report_buf, sizeof(hid_report_buf) / sizeof(uint8_t));
}

/** @brief Configuration callback to setup device as HID 
 * 
 * Sets up HID endpoints &
 * registers the @ref hid_control_request callback which 
*/
static void hid_set_config(usbd_device *dev, uint16_t wValue)
{
	(void)wValue;
	(void)dev;

	usbd_ep_setup(dev, ENDPOINT_HID_IN, USB_ENDPOINT_ATTR_INTERRUPT, 64, hid_report_callback);
  usbd_ep_setup(dev, ENDPOINT_HID_OUT, USB_ENDPOINT_ATTR_INTERRUPT, 64, hid_report_callback);

	usbd_register_control_callback(
        dev,
		    USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
		    USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
		    hid_control_request);
}

/******************************************************************** 
 * Static Function Declarations
 *******************************************************************/

static void cusb_clock_init(void);

/** @} */

/******************************************************************** 
 * Exported Function Definitions
 *******************************************************************/
/** @addtogroup CUSB_API
 * @{
 */

void cusb_init(void)
{   
    
  /** Initialize clocks */
  cusb_clock_init();

  /** Reset USB */
  SET_REG(USB_CNTR_REG, USB_CNTR_FRES);
  SET_REG(USB_CNTR_REG, 0);
  SET_REG(USB_ISTR_REG, 0);

  /** Initialize USB */
  usbd_device *usbd_dev = usbd_init(&st_usbfs_v2_usb_driver, &dev_desc, &cfg_desc, string_desc, sizeof(string_desc) / sizeof(const char*), usbd_control_buffer, sizeof(usbd_control_buffer));
    
  /** Register Configuration Callback for HID */
  usbd_register_set_config_callback(usbd_dev, hid_set_config);
}

void cusb_test_poll(void)
{
  while (1)
  {
    usbd_poll(usbd_dev);
  }
}


/** @} */

/******************************************************************** 
 * Static Function Definitions
 *******************************************************************/
/** @addtogroup CUSB_INT
 * @{
 */

/** @brief Setup CPU and peripheral clocks for usb */
static void cusb_clock_init(void)
{
  /** Set flash, 16Mhz -> 0 waitstates */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

  /** Turn on HSI16 osc */ 
  rcc_osc_on(RCC_HSI16);
  rcc_wait_for_osc_ready(RCC_HSI16);
  
  /** Select CPU Clock */
  rcc_set_sysclk_source(RCC_HSI16);
  
  /** HSI is now the wakeup clock */
  RCC_CFGR |= RCC_CFGR_STOPWUCK_HSI16;
  
  /** Set prescalers for AHB, APB1, APB2 */
  rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				/**< AHB -> 16Mhz */
  rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			/**< APB1 ->16Mhz */
  rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			/**< APB2 ->16Mhz */

  /** Set Peripheral Clock Frequencies used */
	rcc_ahb_frequency = 16000000;
	rcc_apb1_frequency = 16000000;
	rcc_apb2_frequency = 16000000;
    

  /** Enable the VREF for HSI48 */
  rcc_periph_clock_enable(RCC_SYSCFG);
  SYSCFG_CFGR3 |= 0x01;
  while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_VREFINT_RDYF)) { }
  SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENREF_HSI48;
  while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_REF_HSI48_RDYF)) { }

    /** Enable HSI48 */
	rcc_osc_on(RCC_HSI48);
	rcc_wait_for_osc_ready(RCC_HSI48);

  rcc_periph_clock_enable(RCC_USB);
  rcc_periph_clock_enable(RCC_CRS);
  
  /** Select RC HSI48 as usb clock */
  rcc_set_hsi48_source_rc48();

  /** turn off MSI */
  rcc_osc_off(RCC_MSI);
}

/** @} */
/** @} */