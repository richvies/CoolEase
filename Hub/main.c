/**
  ******************************************************************************
  * @file    main.c
  * @author  Richard Davies
  * @brief   CoolEase Hub Main Function
  */

#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/cm3/nvic.h>

#include <libopencm3/usb/usbd.h>
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/usb/hid.h>

/** 
 * USB Device -> st_usbfs_dev           -> st_usbfs_core.c
 * USB Driver -> st_usbfs_v2_usb_driver -> usbd.h / st_usbfs_v2.c 
 */

enum {
    INTERFACE_RAW_HID = 0,
    // The next two must be consecutive since they are used in an Interface
    // Assication below. If the order is changed then the IAD must be changed as
    // well
    INTERFACE_CDC_COMM = 1,
    INTERFACE_CDC_DATA = 2,
    INTERFACE_KEYBOARD_HID = 3,
    INTERFACE_COUNT = 1,
};

enum {
    ENDPOINT_RAW_HID_IN = 0x81,
    ENDPOINT_RAW_HID_OUT = 0x01,
    ENDPOINT_CDC_COMM_IN = 0x83,
    ENDPOINT_CDC_DATA_IN = 0x82,
    ENDPOINT_CDC_DATA_OUT = 0x02,
    ENDPOINT_KEYBOARD_HID_IN = 0x84,
};

enum {
    HID_GET_REPORT = 1,
    HID_GET_IDLE = 2,
    HID_GET_PROTOCOL = 3,
    HID_SET_REPORT = 9,
    HID_SET_IDLE = 10,
    HID_SET_PROTOCOL = 11,
};

typedef enum { USB_TOK_ANY, USB_TOK_SETUP, USB_TOK_IN, USB_TOK_OUT, USB_TOK_RESET } USBToken;

typedef enum { USB_RX_WORKING, USB_RX_DONE = 1 << 0, USB_RX_SETUP = 1 << 1 } USBRXStatus;

#define USB_ENDPOINT_REGISTER(ENDP) (*((&USB_EP0R) + ((ENDP) << 1)))
#define USB_EPREG_MASK     (USB_EP_RX_CTR|USB_EP_SETUP|USB_EP_TYPE|USB_EP_KIND|USB_EP_TX_CTR|USB_EP_ADDR)


static const struct usb_device_descriptor dev_desc = {
  18, //bLength
  1, //bDescriptorType
  0x0200, //bcdUSB
  0x00, //bDeviceClass (defined by interfaces)
  0x00, //bDeviceSubClass
  0x00, //bDeviceProtocl
  64, //bMaxPacketSize0
  0x16c0, //idVendor
  0x05dc, //idProduct
  0x0011, //bcdDevice
  1, //iManufacturer
  2, //iProduct
  0, //iSerialNumber,
  1, //bNumConfigurations
};


static const struct usb_endpoint_descriptor raw_hid_interface_endpoints[] = {
    {
        // The size of the endpoint descriptor in bytes: 7.
        .bLength = USB_DT_ENDPOINT_SIZE,
        // A value of 5 indicates that this describes an endpoint.
        .bDescriptorType = USB_DT_ENDPOINT,
        // Bit 7 indicates direction: 0 for OUT (to device) 1 for IN (to host).
        // Bits 6-4 must be set to 0.
        // Bits 3-0 indicate the endpoint number (zero is not allowed).
        // Here we define the IN side of endpoint 1.
        .bEndpointAddress = ENDPOINT_RAW_HID_IN,
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
        .bInterval = 10,
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
        .bEndpointAddress = ENDPOINT_RAW_HID_OUT,
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
        .bInterval = 10,
    }
};

// The data below is an HID report descriptor. The first byte in each item
// indicates the number of bytes that follow in the lower two bits. The next two
// bits indicate the type of the item. The remaining four bits indicate the tag.
// Words are stored in little endian.
static const uint8_t raw_hid_report_descriptor[] = {
    // Usage Page = 0xFF00 (Vendor Defined Page 1)
    0x06, 0x00, 0xFF,
    // Usage (Vendor Usage 1)
    0x09, 0x01,
    // Collection (Application)
    0xA1, 0x01,
    //   Usage Minimum
    0x19, 0x01,
    //   Usage Maximum. 64 input usages total (0x01 to 0x40).
    0x29, 0x40,
    //   Logical Minimum (data bytes in the report may have minimum value =
    //   0x00).
    0x15, 0x00,
    //   Logical Maximum (data bytes in the report may have
    //     maximum value = 0x00FF = unsigned 255).
    // TODO: Can this be one byte?
    0x26, 0xFF, 0x00,
    //   Report Size: 8-bit field size
    0x75, 0x08,
    //   Report Count: Make sixty-four 8-bit fields (the next time the parser
    //     hits an "Input", "Output", or "Feature" item).
    0x95, 0x40,
    //   Input (Data, Array, Abs): Instantiates input packet fields based on the
    //     above report size, count, logical min/max, and usage.
    0x81, 0x00,
    //   Usage Minimum
    0x19, 0x01,
    //   Usage Maximum. 64 output usages total (0x01 to 0x40)
    0x29, 0x40,
    //   Output (Data, Array, Abs): Instantiates output packet fields. Uses same
    //     report size and count as "Input" fields, since nothing new/different
    //     was specified to the parser since the "Input" item.
    0x91, 0x00,
    // End Collection
    0xC0,
};

static const struct {
    struct usb_hid_descriptor hid_descriptor;
    struct {
        uint8_t bReportDescriptorType;
        uint16_t wDescriptorLength;
    } __attribute__((packed)) hid_report;
} __attribute__((packed)) raw_hid_function = {
    .hid_descriptor = {
        // The size of this header in bytes: 9.
        .bLength = sizeof(raw_hid_function),
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
    .hid_report = {
        // The type of descriptor. A value of 34 indicates a report.
        .bReportDescriptorType = USB_DT_REPORT,
        // The size of the descriptor defined above.
        .wDescriptorLength = sizeof(raw_hid_report_descriptor),
    },
};

const struct usb_interface_descriptor raw_hid_interface = {
    // The size of an interface descriptor: 9
    .bLength = USB_DT_INTERFACE_SIZE,
    // A value of 4 specifies that this describes and interface.
    .bDescriptorType = USB_DT_INTERFACE,
    // The number for this interface. Starts counting from 0.
    .bInterfaceNumber = INTERFACE_RAW_HID,
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
    .iInterface = 0,
    // The header ends here.

    // A pointer to the beginning of the array of endpoints.
    .endpoint = raw_hid_interface_endpoints,

    // Some class types require extra data in the interface descriptor.
    // The libopencm3 usb library requires that we stuff that here.
    // Pointer to the buffer holding the extra data.
    .extra = &raw_hid_function,
    // The length of the data at the above address.
    .extralen = sizeof(raw_hid_function),
};

const struct usb_interface interfaces[] = {
    {
        .num_altsetting = 1,
        .altsetting = &raw_hid_interface,
    }
};

// static const struct usb_config_descriptor cfg_desc = {
//   9, //bLength
//   2, //bDescriptorType
//   9 + 9 + 9 + 7 + 7, //wTotalLength
//   1, //bNumInterfaces
//   1, //bConfigurationValue
//   0, //iConfiguration
//   0x80, //bmAttributes
//   250, //bMaxPower
//   // /* INTERFACE 0 BEGIN */
//   // 9, //bLength
//   // 4, //bDescriptorType
//   // 0, //bInterfaceNumber
//   // 0, //bAlternateSetting
//   // 2, //bNumEndpoints
//   // 0x03, //bInterfaceClass (HID)
//   // 0x00, //bInterfaceSubClass (0: no boot)
//   // 0x00, //bInterfaceProtocol (0: none)
//   // 0, //iInterface
//   // /* HID Descriptor */
//   // 9, //bLength
//   // 0x21, //bDescriptorType (HID)
//   // 0x0111, //bcdHID
//   // 0x00, //bCountryCode
//   // 1, //bNumDescriptors
//   // 0x22, //bDescriptorType (Report)
//   // 25,
//   // /* INTERFACE 0, ENDPOINT 1 BEGIN */
//   // 7, //bLength
//   // 5, //bDescriptorType
//   // 0x81, //bEndpointAddress (endpoint 1 IN)
//   // 0x03, //bmAttributes, interrupt endpoint
//   // 64, //wMaxPacketSize,
//   // 1, //bInterval (10 frames)
//   // /* INTERFACE 0, ENDPOINT 1 END */
//   // /* INTERFACE 0, ENDPOINT 2 BEGIN */
//   // 7, //bLength
//   // 5, //bDescriptorType
//   // 0x02, //bEndpointAddress (endpoint 2 OUT)
//   // 0x03, //bmAttributes, interrupt endpoint
//   // 64, //wMaxPacketSize
//   // 1, //bInterval (10 frames)
//   // /* INTERFACE 0, ENDPOINT 2 END */
//   // /* INTERFACE 0 END */
// };


static const struct usb_config_descriptor cfg_desc = {
    // The length of this header in bytes, 9.
    .bLength = USB_DT_CONFIGURATION_SIZE,
    // A value of 2 indicates that this is a configuration descriptor.
    .bDescriptorType = USB_DT_CONFIGURATION,
    // This should hold the total size of the configuration descriptor including
    // all sub interfaces. This is automatically filled in by the usb stack in
    // libopencm3.
    .wTotalLength = 0,
    // The number of interfaces in this configuration.
    .bNumInterfaces = INTERFACE_COUNT,
    // The index of this configuration. Starts counting from 1.
    .bConfigurationValue = 1,
    // A string index describing this configration. Zero means not provided.
    .iConfiguration = 0,
    // Bit flags:
    // 7: Must be set to 1.
    // 6: This device is self powered.
    // 5: This device supports remote wakeup.
    // 4-0: Must be set to 0.
    // TODO: Add remote wakeup.
    .bmAttributes = 0b10000000,
    // The maximum amount of current that this device will draw in 2mA units.
    // This indicates 400mA.
    .bMaxPower = 200,
    // The header ends here.

    // A pointer to an array of interfaces.
    .interface = interfaces,
};


static const char lang_desc[] = {
    4, //bLength
    3, //bDescriptorType
    0x09, 0x04 //wLANGID[0]
};

static const char manuf_desc[] = {
    2 + 15 * 2, //bLength
    3, //bDescriptorType
    'k', 0x00, //wString
    'e', 0x00,
    'v', 0x00,
    'i', 0x00,
    'n', 0x00,
    'c', 0x00,
    'u', 0x00,
    'z', 0x00,
    'n', 0x00,
    'e', 0x00,
    'r', 0x00,
    '.', 0x00,
    'c', 0x00,
    'o', 0x00,
    'm', 0x00
};

static const char product_desc[] = {
    2 + 25 * 2, //bLength
    3, //bDescriptorType
    'L', 0x00,
    'E', 0x00,
    'D', 0x00,
    ' ', 0x00,
    'W', 0x00,
    'r', 0x00,
    'i', 0x00,
    's', 0x00,
    't', 0x00,
    'w', 0x00,
    'a', 0x00,
    't', 0x00,
    'c', 0x00,
    'h', 0x00,
    ' ', 0x00,
    'B', 0x00,
    'o', 0x00,
    'o', 0x00,
    't', 0x00,
    'l', 0x00,
    'o', 0x00,
    'a', 0x00,
    'd', 0x00,
    'e', 0x00,
    'r', 0x00
};

static const char * string_desc[] = {
  lang_desc,
  manuf_desc,
  product_desc
};

static void usb_clock_init(void);

void usb_enable(void);
void usb_disable(void);
static void usb_reset(void);

int main(void)
{
  uint8_t control_buf[256];

  /** Initialize clocks */
  usb_clock_init();

  /** Initialize USB */
  usbd_device *dev = usbd_init(&st_usbfs_v2_usb_driver, &dev_desc, &cfg_desc, string_desc, 3, control_buf, 256);

  usb_enable();

  return 0;
}

static void usb_clock_init(void)
{
  // Set flash, 16Mhz -> 1 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_1WS);

  //turn on HSI16 and switch the processor clock
  rcc_osc_on(RCC_HSI16);
  rcc_wait_for_osc_ready(RCC_HSI16);
  rcc_set_sysclk_source(RCC_HSI16);

  //HSI is now the wakeup clock
  RCC_CFGR |= RCC_CFGR_STOPWUCK_HSI16;
  
  //turn off MSI
  rcc_osc_on(RCC_MSI);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 16Mhz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 ->16Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 ->16Mhz

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 16000000;
	rcc_apb1_frequency = 16000000;
	rcc_apb2_frequency = 16000000;

    // Enable USB Clock
	rcc_osc_on(RCC_HSI48);
	rcc_wait_for_osc_ready(RCC_HSI48);
  rcc_set_hsi48_source_rc48();

  rcc_periph_clock_enable(RCC_APB2ENR_SYSCFGEN);
  rcc_periph_clock_enable(RCC_APB1ENR_USBEN);
  rcc_periph_clock_enable(RCC_APB1ENR_CRSEN);
}

void usb_enable(void)
{
    //Enable the VREF for HSI48
    SYSCFG_CFGR3 |= 0x01;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_VREFINT_RDYF)) { }
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENREF_HSI48;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_REF_HSI48_RDYF)) { }

    //Enable HSI48
    RCC_CRRCR |= RCC_CRRCR_HSI48ON;
    while (!(RCC_CRRCR & RCC_CRRCR_HSI48RDY)) { }

    //reset the peripheral
    SET_REG(USB_CNTR_REG, USB_CNTR_FRES);

    //enable pullup to signal to the host that we are here
    SET_REG(USB_BCDR_REG, (GET_REG(USB_BCDR_REG) | USB_BCDR_DPPU) );

    //clear interrupts
    SET_REG(USB_ISTR_REG, 0);

    //Enable the USB interrupt
    NVIC_EnableIRQ(NVIC_USB_IRQ);

    SET_REG(USB_CNTR_REG, USB_CNTR_RESETM); //enable the USB reset interrupt
}

void usb_disable(void)
{
    //reset the peripheral
    SET_REG(USB_CNTR_REG, USB_CNTR_FRES);

    //clear interrupts
    SET_REG(USB_ISTR_REG, 0);
    SET_REG(USB_CNTR_REG, (USB_CNTR_FRES | USB_CNTR_LP_MODE | USB_CNTR_PWDN)); //power down usb peripheral

    //disable pullup
    SET_REG(USB_BCDR_REG, (GET_REG(USB_BCDR_REG) & (~USB_BCDR_DPPU)) );

    //disable clock recovery system
    CRS_CR &= ~CRS_CR_CEN;

    //Power down the HSI48 clock
    RCC_CRRCR &= ~RCC_CRRCR_HSI48ON;

    //Disable the VREF for HSI48
    SYSCFG_CFGR3 &= ~SYSCFG_CFGR3_ENREF_HSI48;
}

/**
 * Called during interrupt for a usb reset
 */
static void usb_reset(void)
{
    //clear all interrupts
    SET_REG(USB_ISTR_REG, 0);

    //enable clock recovery system
    CRS_CR |= CRS_CR_AUTOTRIMEN | CRS_CR_CEN;

    //BDT lives at the beginning of packet memory (see linker script)
    SET_REG(USB_BTABLE_REG, 0);

    // //All packet buffers are now deallocated and considered invalid. All endpoints statuses are reset.
    // memset(APPLICATION_ADDR(bt), 0, APPLICATION_SIZEOF(bt));
    // memset(endpoint_status, 0, sizeof(endpoint_status));
    // pma_break = &_pma_end;
    // if (!pma_break)
    //     pma_break++; //we use the assumption that 0 = none = invalid all over

    // //Reset endpoint 0
    // usb_handle_endp0(USB_TOK_RESET);

    //enable correct transfer and reset interrupts
    SET_REG(USB_CNTR_REG, USB_CNTR_CTRM | USB_CNTR_RESETM | USB_CNTR_SOFM | USB_CNTR_ERRM | USB_CNTR_PMAOVRM);

    //Reset USB address to 0 with the device enabled
    SET_REG(USB_DADDR_REG, USB_DADDR_EF);
}


void USB_IRQHandler(void)
{
    volatile uint16_t stat = USB_ISTR_REG;
    if (stat & USB_ISTR_RESET)
    {
        usb_reset();
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_RESET)));
    }
    if (stat & USB_ISTR_SUSP)
    {
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_SUSP)));
    }
    if (stat & USB_ISTR_WKUP)
    {
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_WKUP)));
    }
    if (stat & USB_ISTR_ERR)
    {
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_ERR)));
    }
    if (stat & USB_ISTR_SOF)
    {
        // hook_usb_sof();
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_SOF)));
    }
    if (stat & USB_ISTR_ESOF)
    {
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_ESOF)));
    }
    if (stat & USB_ISTR_PMAOVR)
    {
        SET_REG(USB_ISTR_REG, (GET_REG(USB_ISTR_REG) & (~USB_ISTR_PMAOVR)));
    }

    while ((stat = USB_ISTR_REG) & USB_ISTR_CTR)
    {
        uint8_t endpoint = stat & USB_ISTR_EP_ID;
        uint16_t val = USB_EP_REG(endpoint);

        if (val & USB_EP_RX_CTR)
        {
            uint16_t result = dev (endpoint);
            USB_EP_REG(endpoint) = val & USB_EPREG_MASK & ~USB_EP_RX_CTR;
            if (result & USB_RX_SETUP)
            {
                if (endpoint)
                {
                    // hook_usb_endpoint_setup(endpoint, &endpoint_status[endpoint].last_setup);
                }
                else
                {
                    //endpoint 0 SETUP complete
                    // usb_handle_endp0(USB_TOK_SETUP);
                }
            }
            if (result & USB_RX_DONE)
            {
                if (endpoint)
                {
                    // hook_usb_endpoint_received(endpoint, endpoint_status[endpoint].rx_buf, endpoint_status[endpoint].rx_len);
                }
                else
                {
                    //endpoint 0 OUT complete
                    // usb_handle_endp0(USB_TOK_OUT);
                }
            }
        }

        if (val & USB_EP_TX_CTR)
        {
            usb_endpoint_send_next_packet(endpoint);
            USB_ENDPOINT_REGISTER(endpoint) = val & USB_EPREG_MASK & ~USB_EP_TX_CTR;
            if (!endpoint_status[endpoint].tx_pos)
            {
                if (endpoint)
                {
                    // hook_usb_endpoint_sent(endpoint, endpoint_status[endpoint].tx_buf, endpoint_status[endpoint].tx_len);
                }
                else
                {
                    //endpoint 0 IN complete
                    // usb_handle_endp0(USB_TOK_IN);
                }
            }
        }
    }
}
