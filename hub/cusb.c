/**
 ******************************************************************************
 * @file    cusb.c
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Cusb Source File
 *
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "hub/cusb.h"

#include <stdbool.h>
#include <stddef.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/crc.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>

#include "../../libopencm3/lib/stm32/common/st_usbfs_core.h"
#include "../../libopencm3/lib/usb/usb_private.h"
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/usb/usbd.h>

#include <libopencm3/usb/hid.h>

#include "common/bootloader_utils.h"
#include "common/log.h"
#include "common/memory.h"
#include "config/board_defs.h"

/** @addtogroup CUSB_FILE
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// USB Configuration & Descriptors
/*////////////////////////////////////////////////////////////////////////////*/

/** @addtogroup CUSB_CFG
 *
 * - Device
 * - Configuration
 * - Interface
 * - Endpoints
 * - Strings
 * - HID Function
 * - Report
 *
 * @{
 */

/** @brief Interfaces used */
enum dev_interfaces {
    INTERFACE_HID = 0,

    // The next two must be consecutive since they are used in an Interface
    // Assication below. If the order is changed then the IAD must be changed as
    // well
    // INTERFACE_CDC_COMM = 1,
    // INTERFACE_CDC_DATA = 2,
    // INTERFACE_KEYBOARD_HID = 3,
    INTERFACE_COUNT = 1,
};

/** @brief Required endpoint addresses for interfaces */
enum dev_endpoints {
    ENDPOINT_HID_IN = 0x81,
    ENDPOINT_HID_OUT = 0x01,
    // ENDPOINT_CDC_COMM_IN = 0x83,
    // ENDPOINT_CDC_DATA_IN = 0x82,
    // ENDPOINT_CDC_DATA_OUT = 0x02,
    // ENDPOINT_KEYBOARD_HID_IN = 0x84,
};

#define USB_VID 0x0483 ///< Vendor ID
#define USB_PID 0x5750 ///< Product ID

// #define USB_VID 0x16c0 ///< Vendor ID
// #define USB_PID 0x05dc ///< Product ID

/** @brief Location of specific strings within string descriptors stuct */
enum usb_strings_index {
    USB_LANGID_IDX = 0,
    USB_MANUFACTURER_IDX,
    USB_PRODUCT_IDX,
    USB_SERIAL_IDX,
    USB_CONFIGURATION_IDX,
    USB_INTERFACE_IDX,
};

/** @brief Structure containing all string descriptors, indexed by @ref
 * usb_strings_index */
static const char* const usb_strings[] = {
    "CoolEase",
    "CoolEase Hub",
    "12345",
    "Custom HID Config"
    "Custom HID Interface",
};

/** @brief USB Device Descriptor */
static const struct usb_device_descriptor dev_desc = {
    .bLength = USB_DT_DEVICE_SIZE,
    .bDescriptorType = USB_DT_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = 0x00,
    .bDeviceSubClass = 0x00,
    .bDeviceProtocol = 0x00,
    .bMaxPacketSize0 = 64,
    .idVendor = USB_VID,
    .idProduct = USB_PID,
    .bcdDevice = 0x0200,
    .iManufacturer = USB_MANUFACTURER_IDX,
    .iProduct = USB_PRODUCT_IDX,
    .iSerialNumber = USB_SERIAL_IDX,
    .bNumConfigurations = 1};

/** @brief USB Device HID Endpoint Descriptors */
static const struct usb_endpoint_descriptor hid_interface_endpoints[] = {
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
    }};

/** @brief HID Report Descriptor
 *
 * The data below is an HID report descriptor. The first byte in each item
 * indicates the number of bytes that follow in the lower two bits. The next two
 * bits indicate the type of the item. The remaining four bits indicate the tag.
 * Words are stored in little endian.
 */
static const uint8_t hid_report_descriptor[] = {
    0x06, 0x00, 0xff, // USAGE_PAGE (Vendor Defined Page 1)
    0x09, 0x01,       // USAGE (Vendor Usage 1)
    0xa1, 0x01,       // COLLECTION (Application)
    0x09, 0x01,       //   USAGE (Vendor Usage 1)
    0x15, 0x00,       //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00, //   LOGICAL_MAXIMUM (255)
    0x75, 0x08,       //   REPORT_SIZE (8)
    0x95, 0x40,       //   REPORT_COUNT (64)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x09, 0x01,       //   USAGE (Vendor Usage 1)
    0x91, 0x02,       //   OUTPUT (Data,Var,Abs)
    0xc0              // END_COLLECTION
};

/** @brief HID Function Descriptor*/
static const struct hid_function_descriptor {
    struct usb_hid_descriptor hid_descriptor;
    struct {
        uint8_t  bReportDescriptorType;
        uint16_t wDescriptorLength;
    } __attribute__((packed)) hid_report;
} __attribute__((packed)) hid_function =
    /** @brief HID Function Definition */
    {
        .hid_descriptor =
            {
                // The size of this header in bytes: 9.
                .bLength = sizeof(hid_function),
                // The type of this descriptor. HID is indicated by the
                // value 33.
                .bDescriptorType = USB_DT_HID,
                // The version of the HID spec used in binary coded  decimal. We
                // are using version 1.11.
                .bcdHID = 0x0111,
                // Some HID devices, like keyboards, can specify different
                // country codes. A value of zero means not localized.
                .bCountryCode = 0,
                // The number of descriptors that follow. This must be at least
                // one since there should be at least a report descriptor.
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
static const struct usb_interface_descriptor hid_interface = {
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
static const struct usb_interface interfaces[] = {{
    .num_altsetting = 1,
    .altsetting = &hid_interface,
}};

/** @brief USB Device Config Descriptor */
static const struct usb_config_descriptor cfg_desc = {
    .bLength = USB_DT_CONFIGURATION_SIZE,
    .bDescriptorType = USB_DT_CONFIGURATION,
    .wTotalLength = 0, /**< Total size of descriptor + all interfaces. Auto
                          filled by usb stack in libopencm3 */
    .bNumInterfaces = INTERFACE_COUNT,
    .bConfigurationValue = 1,
    .iConfiguration = USB_CONFIGURATION_IDX,
    .bmAttributes =
        (1 << 7),     /**< Bit flags. 7: Must be set to 1. 6: Self Powered. 5:
                 Supports remote wakeup. 4-0: Must be set to 0.*/
    .bMaxPower = 200, /**< mA / 2 */
    .interface = interfaces,
};

/** @} */

/** @addtogroup CUSB_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief USB device handle */
static usbd_device* usbd_dev;

typedef enum {
    USB_OFF = 0,
    USB_INIT,
    USB_RESET,
    USB_CONNECTED,
    USB_GET_LOG,
    USB_PROG_PAGE,
    USB_PRINT,
    USB_TEST_CRC,
} usb_state_t;

typedef enum {
    CMD_RESET = 0xFF,
    CMD_GET_LOG = 1,
    CMD_PROG_START,
    CMD_PROG_PAGE,
    CMD_PROG_END,
    CMD_PRINT_START,
    CMD_PRINT_END,
    CMD_TEST_CRC,
    CMD_END,
} commands_t;

static usb_state_t usb_state = USB_OFF;
static bool        usb_plugged_in = false;

/** @brief Buffer to be used for control requests. */
static uint8_t usbd_control_buffer[128];

#define HID_REPORT_SIZE_BYTES 64U
#define HID_REPORT_SIZE_WORDS 16U
/** @brief HID Report buffers
 *
 * Buffer used for all HID in & out transactions
 */
union {
    uint32_t buf[HID_REPORT_SIZE_WORDS];
    struct {
        uint32_t command;
        uint32_t page_num;
        uint32_t crc_lower;
        uint32_t crc_upper;
    };

} hid_out_report;

union {
    uint32_t buf[HID_REPORT_SIZE_WORDS];
    struct {
        uint32_t last_command;
        uint32_t page_num;
    };

} hid_in_report;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @brief Setup CPU and peripheral clocks for usb */
static void cusb_clock_init(void);

/*////////////////////////////////////////////////////////////////////////////*/
// USB Callback Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

static void cusb_reset_callback(void);

/** @brief HID configuration init callback
 *
 * Called by libopencm3 - usb_standard_set_configuration() to initialize HID
 * configuration
 * - Initializes endpoints, IN (0x01) & OUT (0x81), and
 * sets the IN & OUT transaction callbacks @ref hid_report_callback()
 * - Sets control request callback @ref hid_control_request()
 * which is called by libopencm3 usb_control.c functions
 */
static void hid_set_config(usbd_device* dev, uint16_t wValue);

/** @brief HID Control Callback
 *
 * Links hid report descriptor to usbd
 */
static enum usbd_request_return_codes
hid_control_request(usbd_device* dev, struct usb_setup_data* req, uint8_t** buf,
                    uint16_t* len,
                    void (**complete)(usbd_device*, struct usb_setup_data*));

/** @brief HID Out Resport Callback
 *
 * Called when out report received packet received
 * i.e. when usb CTR interrupt received and transaction type is OUT
 */
static void hid_out_report_callback(usbd_device* dev, uint8_t ea);

/** @brief HID In Resport Callback
 *
 * Called when in report received packet received
 * i.e. when usb CTR interrupt and transaction type is IN
 */
static void hid_in_report_callback(usbd_device* dev, uint8_t ea);

/** @} */

/** @addtogroup CUSB_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void cusb_init(void) {
    if (usb_state == USB_OFF) {
        // Initialize clocks
        cusb_clock_init();

        // Reset USB peripheral
        SET_REG(USB_CNTR_REG, USB_CNTR_FRES);
        SET_REG(USB_CNTR_REG, 0);
        SET_REG(USB_ISTR_REG, 0);

        // Initialize USB Hardware and activate pullup on DP line
        usbd_dev =
            usbd_init(&st_usbfs_v2_usb_driver, &dev_desc, &cfg_desc,
                      usb_strings, sizeof(usb_strings) / sizeof(const char*),
                      usbd_control_buffer, sizeof(usbd_control_buffer));

        // Register Reset Callback
        usbd_register_reset_callback(usbd_dev, cusb_reset_callback);

        // Register Configuration Callback for HID
        usbd_register_set_config_callback(usbd_dev, hid_set_config);

        usb_state = USB_INIT;

        // Enable NVIC interrupt (through EXTI18 which is enabled on reset)
        nvic_enable_irq(NVIC_USB_IRQ);
        nvic_set_priority(NVIC_USB_IRQ, IRQ_PRIORITY_USB);

        usb_plugged_in = false;
    }
}

void cusb_end(void) {
    nvic_disable_irq(NVIC_USB_IRQ);

    rcc_periph_reset_pulse(RST_USB);

    rcc_osc_off(RCC_HSI48);

    rcc_periph_clock_disable(RCC_USB);
    rcc_periph_clock_disable(RCC_CRS);

    usb_state = USB_OFF;
}

bool cusb_connected(void) {
    return ((usb_state >= USB_CONNECTED) ? true : false);
}

bool cusb_reset(void) {
    return ((usb_state == USB_RESET) ? true : false);
}

bool cusb_plugged_in(void) {
    return usb_plugged_in;
}

void cusb_poll(void) {
    usbd_poll(usbd_dev);
}

void cusb_send(char character) {
    if (usb_state == USB_PRINT) {
        usbd_ep_write_packet(usbd_dev, ENDPOINT_HID_IN, &character, 1);
    }
}

/** @} */

/** @addtogroup CUSB_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/* HSI16 must be sys_clk */
static void cusb_clock_init(void) {
    //  Enable the VREF for HSI48
    rcc_periph_clock_enable(RCC_SYSCFG);
    SYSCFG_CFGR3 |= 0x01;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_VREFINT_RDYF)) {
    }
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENREF_HSI48;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_REF_HSI48_RDYF)) {
    }

    //  Enable HSI48
    rcc_osc_on(RCC_HSI48);
    rcc_wait_for_osc_ready(RCC_HSI48);

    rcc_periph_clock_enable(RCC_USB);
    rcc_periph_clock_enable(RCC_CRS);

    //  Select RC HSI48 as usb clock
    rcc_set_hsi48_source_rc48();
}

/*////////////////////////////////////////////////////////////////////////////*/
// USB Callback Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

static void cusb_reset_callback(void) {
    usb_state = USB_RESET;

    usb_plugged_in = true;

    cusb_hook_reset();
}

static void hid_set_config(usbd_device* dev, uint16_t wValue) {
    (void)wValue;
    (void)dev;

    usbd_ep_setup(dev, ENDPOINT_HID_IN, USB_ENDPOINT_ATTR_INTERRUPT, 64,
                  hid_in_report_callback);
    usbd_ep_setup(dev, ENDPOINT_HID_OUT, USB_ENDPOINT_ATTR_INTERRUPT, 64,
                  hid_out_report_callback);

    usbd_register_control_callback(
        dev, USB_REQ_TYPE_STANDARD | USB_REQ_TYPE_INTERFACE,
        USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT, hid_control_request);
}

static enum usbd_request_return_codes
hid_control_request(usbd_device* dev, struct usb_setup_data* req, uint8_t** buf,
                    uint16_t* len,
                    void (**complete)(usbd_device*, struct usb_setup_data*)) {
    (void)complete;
    (void)dev;

    if ((req->bmRequestType != 0x81) ||
        (req->bRequest != USB_REQ_GET_DESCRIPTOR) || (req->wValue != 0x2200))
        return USBD_REQ_NOTSUPP;

    //  Handle the HID report descriptor.
    *buf = (uint8_t*)hid_report_descriptor;
    *len = sizeof(hid_report_descriptor);

    return USBD_REQ_HANDLED;
}

static void hid_in_report_callback(usbd_device* dev, uint8_t ea) {
    // serial_printf("i\n");

    if (usb_state == USB_GET_LOG) {
        static uint16_t bytes_sent = 0;

        // Get next 64 bytes of log
        for (uint16_t i = 0; i < HID_REPORT_SIZE_BYTES; i++) {
            *(((uint8_t*)hid_in_report.buf) + i) = log_read();
        }
        bytes_sent += HID_REPORT_SIZE_BYTES;

        usbd_ep_write_packet(dev, ea, hid_in_report.buf, HID_REPORT_SIZE_BYTES);

        if (bytes_sent >= log_size()) {
            usb_state = USB_CONNECTED;
            bytes_sent = 0;
        }
    }
}

static void hid_out_report_callback(usbd_device* dev, uint8_t ea) {
    // serial_printf("o\n");

    // Bit field indicating which pages have been succesfully written
    static uint32_t page_written[16];
    static uint32_t page_num;
    static uint32_t crc_lower;
    static uint32_t crc_upper;
    static bool     lower;
    static bool     prog_error;

    static uint32_t crc_test_len;

    usbd_ep_read_packet(dev, ea, hid_out_report.buf, HID_REPORT_SIZE_BYTES);

    // Report is a half page of data
    if (usb_state == USB_PROG_PAGE) {
        if (!prog_error) {
            if (boot_program_half_page(lower, lower ? crc_lower : crc_upper,
                                       page_num, hid_out_report.buf)) {
                page_written[page_num / 32] |= (1 << (page_num % 32));
            }
        }

        lower = !lower;

        // 2 half pages done
        if (lower) {
            usb_state = USB_CONNECTED;
        }
    } else if (usb_state == USB_TEST_CRC) {
        serial_printf("page %u\n", crc_test_len);
        if (crc_test_len) {
            crc_lower = ~crc_calculate_block(hid_out_report.buf, 16);
            --crc_test_len;
        }

        if (crc_test_len == 0) {
            usb_state = USB_CONNECTED;
            serial_printf("Test End %8x\n", crc_lower);

            // Deinit
            crc_reset();
            rcc_periph_clock_disable(RCC_CRC);
        }
    } else {
        uint32_t command = hid_out_report.command;

        switch (command) {
        // Reset
        case CMD_RESET:
            usb_state = USB_CONNECTED;

            serial_printf("Reset\n");
            break;

        // Get Log
        case CMD_GET_LOG:
            usb_state = USB_GET_LOG;
            log_read_reset();

            // Have to write a packet back here to begin IN transfer
            uint8_t buf[HID_REPORT_SIZE_BYTES] = "Start IN\n";
            usbd_ep_write_packet(dev, ea, buf, HID_REPORT_SIZE_BYTES);

            serial_printf("Get Log\n");
            break;

        // Setup for programming
        case CMD_PROG_START:
            page_num = 0;
            for (uint8_t i = 0; i < 16; i++) {
                // Default all pages to fail, any lost in transit automatically
                // counted
                page_written[i] = 0;
            }

            serial_printf("Prog Start\n");
            break;

        // Two half pages will be sent next, lower half page first
        case CMD_PROG_PAGE:
            usb_state = USB_PROG_PAGE;
            crc_lower = hid_out_report.crc_lower;
            crc_upper = hid_out_report.crc_upper;
            lower = true;
            prog_error = false;

            page_num = hid_out_report.page_num;

            // Erase page first
            if (!mem_flash_erase_page(FLASH_APP_ADDRESS +
                                      (page_num * FLASH_PAGE_SIZE))) {
                log_error(ERR_USB_PAGE_ERASE_FAIL);
                prog_error = true;
            }

            serial_printf(".page %u\n", page_num);
            break;

        // Programming end, send back succesful pages
        // Fails will be resent
        case CMD_PROG_END:
            usb_state = USB_CONNECTED;

            usbd_ep_write_packet(dev, ea, page_written, HID_REPORT_SIZE_BYTES);

            serial_printf("Prog End\n");
            break;

        case CMD_PRINT_START:
            usb_state = USB_PRINT;

            serial_printf("Print Start\n");
            break;

        case CMD_PRINT_END:
            usb_state = USB_CONNECTED;

            serial_printf("Print End\n");
            break;

        case CMD_TEST_CRC:
            serial_printf("Test CRC\n%u half pages\ncrc %8x\n",
                          hid_out_report.page_num, hid_out_report.crc_lower);

            usb_state = USB_TEST_CRC;

            crc_test_len = hid_out_report.page_num;

            // Initialize CRC Peripheral
            rcc_periph_clock_enable(RCC_CRC);
            crc_reset();
            crc_set_reverse_input(CRC_CR_REV_IN_BYTE);
            crc_reverse_output_enable();
            CRC_INIT = 0xFFFFFFFF;

            break;

        case CMD_END:
            cusb_end();

            serial_printf("End\n");
            break;

        default:
            break;
        }
    }

    uint32_t command = hid_out_report.command;
    serial_printf("command: %d", command);
}

/*////////////////////////////////////////////////////////////////////////////*/
// Hook Function Weak Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void __attribute__((weak)) cusb_hook_reset(void) {
}
void __attribute__((weak)) cusb_hook_hid_out_report(void) {
}
void __attribute__((weak)) cusb_hook_hid_in_report(void) {
}

/*////////////////////////////////////////////////////////////////////////////*/
// USB Interrupt
/*////////////////////////////////////////////////////////////////////////////*/

void usb_isr(void) {
    // This print is definitley not the problem with hidapi write failing
    // serial_printf("I");

    uint16_t istr = *USB_ISTR_REG;

    if (istr & USB_ISTR_RESET) {
        USB_CLR_ISTR_RESET();
        usbd_dev->pm_top = USBD_PM_TOP;
        _usbd_reset(usbd_dev);
        return;
    }

    if (istr & USB_ISTR_CTR) {
        uint8_t ep = istr & USB_ISTR_EP_ID;
        uint8_t type;

        if (istr & USB_ISTR_DIR) {
            /* OUT or SETUP? */
            if (*USB_EP_REG(ep) & USB_EP_SETUP) {
                type = USB_TRANSACTION_SETUP;
                st_usbfs_ep_read_packet(usbd_dev, ep,
                                        &usbd_dev->control_state.req, 8);
            } else {
                type = USB_TRANSACTION_OUT;
            }
        } else {
            type = USB_TRANSACTION_IN;
            USB_CLR_EP_TX_CTR(ep);
        }

        if (usbd_dev->user_callback_ctr[ep][type]) {
            usbd_dev->user_callback_ctr[ep][type](usbd_dev, ep);
        } else {
            USB_CLR_EP_RX_CTR(ep);
        }
    }

    if (istr & USB_ISTR_SUSP) {
        USB_CLR_ISTR_SUSP();
        if (usbd_dev->user_callback_suspend) {
            usbd_dev->user_callback_suspend();
        }
    }

    if (istr & USB_ISTR_WKUP) {
        USB_CLR_ISTR_WKUP();
        if (usbd_dev->user_callback_resume) {
            usbd_dev->user_callback_resume();
        }
    }

    if (istr & USB_ISTR_SOF) {
        USB_CLR_ISTR_SOF();
        if (usbd_dev->user_callback_sof) {
            usbd_dev->user_callback_sof();
        }
    }

    if (usbd_dev->user_callback_sof) {
        *USB_CNTR_REG |= USB_CNTR_SOFM;
    } else {
        *USB_CNTR_REG &= ~USB_CNTR_SOFM;
    }
}

/** @} */
/** @} */