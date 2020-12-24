/* -----------------------------------------------------------------------------
 * Copyright (c) 2017-2019 Arm Limited
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software. Permission is granted to anyone to use this
 * software for any purpose, including commercial applications, and to alter
 * it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software in
 *    a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *
 * $Date:        5. June 2019
 * $Revision:    V1.3
 *
 * Driver:       Driver_USBD0
 *
 * Configured:   via STM32CubeMx configuration tool
 * Project:      USB Full/Low-Speed Device Driver for
 *               STMicroelectronics STM32L0xx
 * --------------------------------------------------------------------------
 * Use the following configuration settings in the middleware component
 * to connect to this driver.
 *
 *   Configuration Setting                  Value
 *   ---------------------                  -----
 *   Connect to hardware via Driver_USBD# = 0
 * --------------------------------------------------------------------------
 * Defines used for driver configuration (at compile time):
 *   USBD_MAX_ENDPOINT_NUM: defines maximum number of IN/OUT Endpoint pairs
 *                          that driver will support with Control Endpoint 0
 *                          not included, this value impacts driver memory
 *                          requirements
 *     - default value:     2
 *     - maximum value:     7
 *
 *   USBD_EP0_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 0 reception
 *     - default value:     0
 *   USBD_EP0_RX_RAM_SIZE:  RAM size for reception for          endpoint 0
 *     - default value:     64
 *   USBD_EP0_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 0 reception
 *     - default value:     0
 *   USBD_EP0_TX_RAM_SIZE:  RAM size for transmission for       endpoint 0
 *     - default value:     64
 *
 *   USBD_EP1_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 1 reception
 *     - default value:     0
 *   USBD_EP1_RX_RAM_SIZE:  RAM size for reception for          endpoint 1
 *     - default value:     64
 *   USBD_EP1_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 1 reception
 *     - default value:     0
 *   USBD_EP1_TX_RAM_SIZE:  RAM size for transmission for       endpoint 1
 *     - default value:     64
 *
 *   USBD_EP2_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 2 reception
 *     - default value:     0
 *   USBD_EP2_RX_RAM_SIZE:  RAM size for reception for          endpoint 2
 *     - default value:     64
 *   USBD_EP2_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 2 reception
 *     - default value:     0
 *   USBD_EP2_TX_RAM_SIZE:  RAM size for transmission for       endpoint 2
 *     - default value:     64
 *
 *   USBD_EP3_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 3 reception
 *     - default value:     0
 *   USBD_EP3_RX_RAM_SIZE:  RAM size for reception for          endpoint 3
 *     - default value:     0
 *   USBD_EP3_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 3 reception
 *     - default value:     0
 *   USBD_EP3_TX_RAM_SIZE:  RAM size for transmission for       endpoint 3
 *     - default value:     0
 *
 *   USBD_EP4_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 4 reception
 *     - default value:     0
 *   USBD_EP4_RX_RAM_SIZE:  RAM size for reception for          endpoint 4
 *     - default value:     0
 *   USBD_EP4_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 4 reception
 *     - default value:     0
 *   USBD_EP4_TX_RAM_SIZE:  RAM size for transmission for       endpoint 4
 *     - default value:     0
 *
 *   USBD_EP5_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 5 reception
 *     - default value:     0
 *   USBD_EP5_RX_RAM_SIZE:  RAM size for reception for          endpoint 5
 *     - default value:     0
 *   USBD_EP5_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 5 reception
 *     - default value:     0
 *   USBD_EP5_TX_RAM_SIZE:  RAM size for transmission for       endpoint 5
 *     - default value:     0
 *
 *   USBD_EP6_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 6 reception
 *     - default value:     0
 *   USBD_EP6_RX_RAM_SIZE:  RAM size for reception for          endpoint 6
 *     - default value:     0
 *   USBD_EP6_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 6 reception
 *     - default value:     0
 *   USBD_EP6_TX_RAM_SIZE:  RAM size for transmission for       endpoint 6
 *     - default value:     0
 *
 *   USBD_EP7_RX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 7 reception
 *     - default value:     0
 *   USBD_EP7_RX_RAM_SIZE:  RAM size for reception for          endpoint 7
 *     - default value:     0
 *   USBD_EP7_TX_BUF_KIND:  Single (=0) or double (=1) buffered endpoint 7 reception
 *     - default value:     0
 *   USBD_EP7_TX_RAM_SIZE:  RAM size for transmission for       endpoint 7
 *     - default value:     0
 *
 * Notes:
 *   - HAL does not support double buffering
 * -------------------------------------------------------------------------- */

/* History:
 *  Version 1.3
 *    Corrected USBD_EndpointConfigure function (check that maximum packet 
 *    size requested fits into configured FIFO)
 *  Version 1.2
 *    Updated USBD_EndpointConfigure function to check that maximum packet 
 *    size requested fits into configured FIFO (compile time configured)
 *  Version 1.1
 *    Corrected transmitted count for non-control IN endpoints
 *  Version 1.0
 *    Initial release
 */

/*! \page stm32l0_usbd CMSIS-Driver USBD Setup

The CMSIS-Driver USBD requires:
  - Setup of USB clock to 48MHz
  - Configuration of USB as Device (FS)

Valid settings for various evaluation boards are listed in the table below:

Peripheral Resource | STM32L073Z-EVAL |
:-------------------|:----------------|
USB Peripheral      | USB             |
D- Pin              | PA11            |
D+ Pin              | PA12            |

For different boards, refer to the hardware schematics to reflect correct setup values.

The STM32CubeMX configuration for STMicroelectronics STM32L073Z-EVAL Board with steps for Pinout, Clock, and System Configuration are 
listed below. Enter the values that are marked \b bold.

Pinout tab
----------
  1. Configure peripheral
     - Peripherals \b USB: enable <b>Device (FS)</b>

Clock Configuration tab
-----------------------
  1. Configure USB Clock: "USBCLK (MHz)": \b 48

Configuration tab
-----------------
  1. Under Connectivity open \b USB Configuration:
     - Parameter Settings: not used
     - User Constants: not used
     - <b>NVIC Settings</b>: enable interrupts
          Interrupt Table                           | Enabled | Preemption Priority
          :-----------------------------------------|:--------|:-------------------
          USB event interrupt / USB wake-up inter.. | \b ON   | 0

     - <b>GPIO Settings</b>: review settings, no changes required
          Pin Name | Signal on Pin | GPIO output..|  GPIO mode  | GPIO Pull-up/Pull..| Maximum out |  Fast Mode  | User Label
          :--------|:--------------|:-------------|:------------|:-------------------|:------------|:------------|:----------
          PA11     | USB_DM        | n/a          | n/a         | n/a                | n/a         | n/a         |.
          PA12     | USB_DP        | n/a          | n/a         | n/a                | n/a         | n/a         |.

     Click \b OK to close the USB Configuration dialog
*/

/*! \cond */

#include <string.h>

#include "stm32l0xx_hal_pcd.h"
#include "stm32l0xx.h"

#include "USBD_STM32L0xx.h"


#ifndef USBD_MAX_ENDPOINT_NUM
#define USBD_MAX_ENDPOINT_NUM          (2U)
#endif
#if    (USBD_MAX_ENDPOINT_NUM > 7U)
#error  Too many Endpoints, maximum IN/OUT Endpoint pairs that this driver supports is 7 !!!
#endif

// FIFO sizes in bytes (total available memory for FIFOs is 1.25 kB)
#ifndef USBD_EP0_RX_BUF_KIND
#define USBD_EP0_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP0_RX_RAM_SIZE
#define USBD_EP0_RX_RAM_SIZE           (64U)
#endif
#ifndef USBD_EP0_TX_BUF_KIND
#define USBD_EP0_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP0_TX_RAM_SIZE
#define USBD_EP0_TX_RAM_SIZE           (64U)
#endif

#ifndef USBD_EP1_RX_BUF_KIND
#define USBD_EP1_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP1_RX_RAM_SIZE
#define USBD_EP1_RX_RAM_SIZE           (64U)
#endif
#ifndef USBD_EP1_TX_BUF_KIND
#define USBD_EP1_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP1_TX_RAM_SIZE
#define USBD_EP1_TX_RAM_SIZE           (64U)
#endif

#ifndef USBD_EP2_RX_BUF_KIND
#define USBD_EP2_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP2_RX_RAM_SIZE
#define USBD_EP2_RX_RAM_SIZE           (64U)
#endif
#ifndef USBD_EP2_TX_BUF_KIND
#define USBD_EP2_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP2_TX_RAM_SIZE
#define USBD_EP2_TX_RAM_SIZE           (64U)
#endif

#ifndef USBD_EP3_RX_BUF_KIND
#define USBD_EP3_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP3_RX_RAM_SIZE
#define USBD_EP3_RX_RAM_SIZE           (0U)
#endif
#ifndef USBD_EP3_TX_BUF_KIND
#define USBD_EP3_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP3_TX_RAM_SIZE
#define USBD_EP3_TX_RAM_SIZE           (0U)
#endif

#ifndef USBD_EP4_RX_BUF_KIND
#define USBD_EP4_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP4_RX_RAM_SIZE
#define USBD_EP4_RX_RAM_SIZE           (0U)
#endif
#ifndef USBD_EP4_TX_BUF_KIND
#define USBD_EP4_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP4_TX_RAM_SIZE
#define USBD_EP4_TX_RAM_SIZE           (0U)
#endif

#ifndef USBD_EP5_RX_BUF_KIND
#define USBD_EP5_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP5_RX_RAM_SIZE
#define USBD_EP5_RX_RAM_SIZE           (0U)
#endif
#ifndef USBD_EP5_TX_BUF_KIND
#define USBD_EP5_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP5_TX_RAM_SIZE
#define USBD_EP5_TX_RAM_SIZE           (0U)
#endif

#ifndef USBD_EP6_RX_BUF_KIND
#define USBD_EP6_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP6_RX_RAM_SIZE
#define USBD_EP6_RX_RAM_SIZE           (0U)
#endif
#ifndef USBD_EP6_TX_BUF_KIND
#define USBD_EP6_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP6_TX_RAM_SIZE
#define USBD_EP6_TX_RAM_SIZE           (0U)
#endif

#ifndef USBD_EP7_RX_BUF_KIND
#define USBD_EP7_RX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP7_RX_RAM_SIZE
#define USBD_EP7_RX_RAM_SIZE           (0U)
#endif
#ifndef USBD_EP7_TX_BUF_KIND
#define USBD_EP7_TX_BUF_KIND           (0U)
#endif
#ifndef USBD_EP7_TX_RAM_SIZE
#define USBD_EP7_TX_RAM_SIZE           (0U)
#endif

extern PCD_HandleTypeDef hpcd_USB_FS;


// USBD Driver *****************************************************************

#define ARM_USBD_DRV_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1,3)

// Driver Version
static const ARM_DRIVER_VERSION usbd_driver_version = { ARM_USBD_API_VERSION, ARM_USBD_DRV_VERSION };

// Driver Capabilities
static const ARM_USBD_CAPABILITIES usbd_driver_capabilities = {
  0U,   // VBUS Detection
  0U,   // Event VBUS On
  0U    // Event VBUS Off
#if (defined(ARM_USBD_API_VERSION) && (ARM_USBD_API_VERSION >= 0x202U))
, 0U    // Reserved
#endif
};

#define EP_NUM(ep_addr)         ((ep_addr) & ARM_USB_ENDPOINT_NUMBER_MASK)
#define EP_ID(ep_addr)          ((EP_NUM(ep_addr) * 2U) + (((ep_addr) >> 7) & 1U))

typedef struct {
           uint16_t  rx_buf_kind;
           uint16_t  rx_ram_size;
           uint16_t  tx_buf_kind;
           uint16_t  tx_ram_size;
} USBD_EP_CONFIG_t;

typedef struct {                        // Endpoint structure definition
           uint8_t  *data;
           uint32_t  num;
  volatile uint32_t  num_transferred_total;
  volatile uint32_t  num_transferring;
           uint16_t  max_packet_size;
  volatile uint16_t  active;
  volatile uint8_t   xfer_flag;
  volatile uint8_t   int_flag;
           uint16_t  reserved;
} ENDPOINT_t;


static PCD_HandleTypeDef  *p_hpcd = &hpcd_USB_FS;

static ARM_USBD_SignalDeviceEvent_t   SignalDeviceEvent;
static ARM_USBD_SignalEndpointEvent_t SignalEndpointEvent;

static bool                hw_powered     = false;
static bool                hw_initialized = false;
static ARM_USBD_STATE      usbd_state;

static uint32_t            setup_packet[2];
static volatile uint8_t    setup_received = 0U;     // Setup packet received

// Endpoints configuration information
static const    USBD_EP_CONFIG_t ep_cfg[USBD_MAX_ENDPOINT_NUM + 1U] = {
    { USBD_EP0_RX_BUF_KIND, USBD_EP0_RX_RAM_SIZE, USBD_EP0_TX_BUF_KIND, USBD_EP0_TX_RAM_SIZE }
#if (USBD_MAX_ENDPOINT_NUM > 0U)
  , { USBD_EP1_RX_BUF_KIND, USBD_EP1_RX_RAM_SIZE, USBD_EP1_TX_BUF_KIND, USBD_EP1_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 1U)
  , { USBD_EP2_RX_BUF_KIND, USBD_EP2_RX_RAM_SIZE, USBD_EP2_TX_BUF_KIND, USBD_EP2_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 2U)
  , { USBD_EP3_RX_BUF_KIND, USBD_EP3_RX_RAM_SIZE, USBD_EP3_TX_BUF_KIND, USBD_EP3_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 3U)
  , { USBD_EP4_RX_BUF_KIND, USBD_EP4_RX_RAM_SIZE, USBD_EP4_TX_BUF_KIND, USBD_EP4_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 4U)
  , { USBD_EP5_RX_BUF_KIND, USBD_EP5_RX_RAM_SIZE, USBD_EP5_TX_BUF_KIND, USBD_EP5_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 5U)
  , { USBD_EP6_RX_BUF_KIND, USBD_EP6_RX_RAM_SIZE, USBD_EP6_TX_BUF_KIND, USBD_EP6_TX_RAM_SIZE }
#endif
#if (USBD_MAX_ENDPOINT_NUM > 6U)
  , { USBD_EP7_RX_BUF_KIND, USBD_EP7_RX_RAM_SIZE, USBD_EP7_TX_BUF_KIND, USBD_EP7_TX_RAM_SIZE }
#endif
};

// Endpoints runtime information
static volatile ENDPOINT_t ep[(USBD_MAX_ENDPOINT_NUM + 1U) * 2U];


// USBD Driver functions

/**
  \fn          ARM_DRIVER_VERSION USBD_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRIVER_VERSION
*/
static ARM_DRIVER_VERSION USBD_GetVersion (void) { return usbd_driver_version; }

/**
  \fn          ARM_USBD_CAPABILITIES USBD_GetCapabilities (void)
  \brief       Get driver capabilities.
  \return      \ref ARM_USBD_CAPABILITIES
*/
static ARM_USBD_CAPABILITIES USBD_GetCapabilities (void) { return usbd_driver_capabilities; }

/**
  \fn          int32_t USBD_Initialize (ARM_USBD_SignalDeviceEvent_t   cb_device_event,
                                        ARM_USBD_SignalEndpointEvent_t cb_endpoint_event)
  \brief       Initialize USB Device Interface.
  \param[in]   cb_device_event    Pointer to \ref ARM_USBD_SignalDeviceEvent
  \param[in]   cb_endpoint_event  Pointer to \ref ARM_USBD_SignalEndpointEvent
  \return      \ref execution_status
*/
static int32_t USBD_Initialize (ARM_USBD_SignalDeviceEvent_t   cb_device_event,
                                ARM_USBD_SignalEndpointEvent_t cb_endpoint_event) {

  if (hw_initialized == true) {
    return ARM_DRIVER_OK;
  }

  SignalDeviceEvent   = cb_device_event;
  SignalEndpointEvent = cb_endpoint_event;

  hpcd_USB_FS.Instance = USB;

  hw_initialized = true;

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_Uninitialize (void)
  \brief       De-initialize USB Device Interface.
  \return      \ref execution_status
*/
static int32_t USBD_Uninitialize (void) {

  hpcd_USB_FS.Instance = NULL;
  
  hw_initialized = false;

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_PowerControl (ARM_POWER_STATE state)
  \brief       Control USB Device Interface Power.
  \param[in]   state  Power state
  \return      \ref execution_status
*/
static int32_t USBD_PowerControl (ARM_POWER_STATE state) {

  if ((state != ARM_POWER_OFF)  &&
      (state != ARM_POWER_FULL) &&
      (state != ARM_POWER_LOW)) {
    return ARM_DRIVER_ERROR_PARAMETER;
  }

  switch (state) {
    case ARM_POWER_OFF:
      // Deinitialize
      HAL_PCD_DeInit(p_hpcd);

      // Clear powered flag
      hw_powered =  false;
      break;

    case ARM_POWER_FULL:
      if (hw_initialized == false) {
        return ARM_DRIVER_ERROR;
      }
      if (hw_powered == true) {
        return ARM_DRIVER_OK;
      }

      // Set powered flag
      hw_powered     = true;

      // Initialize
      HAL_PCD_Init (p_hpcd);
      break;

    case ARM_POWER_LOW:
      return ARM_DRIVER_ERROR_UNSUPPORTED;
  }

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_DeviceConnect (void)
  \brief       Connect USB Device.
  \return      \ref execution_status
*/
static int32_t USBD_DeviceConnect (void) {

  if (hw_powered == false) { return ARM_DRIVER_ERROR; }

  HAL_PCD_Start(p_hpcd);

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_DeviceDisconnect (void)
  \brief       Disconnect USB Device.
  \return      \ref execution_status
*/
static int32_t USBD_DeviceDisconnect (void) {

  if (hw_powered == false) { return ARM_DRIVER_ERROR; }

  HAL_PCD_DevDisconnect(p_hpcd);

  return ARM_DRIVER_OK;
}

/**
  \fn          ARM_USBD_STATE USBD_DeviceGetState (void)
  \brief       Get current USB Device State.
  \return      Device State \ref ARM_USBD_STATE
*/
static ARM_USBD_STATE USBD_DeviceGetState (void) {
  return usbd_state;
}

/**
  \fn          int32_t USBD_DeviceRemoteWakeup (void)
  \brief       Trigger USB Remote Wakeup.
  \return      \ref execution_status
*/
static int32_t USBD_DeviceRemoteWakeup (void) {

  if (hw_powered == false) { return ARM_DRIVER_ERROR; }

  HAL_PCD_ActivateRemoteWakeup(p_hpcd);

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_DeviceSetAddress (uint8_t dev_addr)
  \brief       Set USB Device Address.
  \param[in]   dev_addr  Device Address
  \return      \ref execution_status
*/
static int32_t USBD_DeviceSetAddress (uint8_t dev_addr) {

  if (hw_powered == false) { return ARM_DRIVER_ERROR; }

  HAL_PCD_SetAddress(p_hpcd, dev_addr);

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_ReadSetupPacket (uint8_t *setup)
  \brief       Read setup packet received over Control Endpoint.
  \param[out]  setup  Pointer to buffer for setup packet
  \return      \ref execution_status
*/
static int32_t USBD_ReadSetupPacket (uint8_t *setup) {

  if (hw_powered == false)  { return ARM_DRIVER_ERROR; }
  if (setup_received == 0U) { return ARM_DRIVER_ERROR; }

  setup_received = 0U;
  memcpy(setup, setup_packet, 8);

  if (setup_received != 0U) {           // If new setup packet was received while this was being read
    return ARM_DRIVER_ERROR;
  }

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_EndpointConfigure (uint8_t  ep_addr,
                                               uint8_t  ep_type,
                                               uint16_t ep_max_packet_size)
  \brief       Configure USB Endpoint.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \param[in]   ep_type  Endpoint Type (ARM_USB_ENDPOINT_xxx)
  \param[in]   ep_max_packet_size Endpoint Maximum Packet Size
  \return      \ref execution_status
*/
static int32_t USBD_EndpointConfigure (uint8_t  ep_addr,
                                       uint8_t  ep_type,
                                       uint16_t ep_max_packet_size) {
  uint8_t              ep_num;
  uint16_t             ep_mps;
  volatile ENDPOINT_t *ptr_ep;

  ep_num = EP_NUM(ep_addr);
  ep_mps = ep_max_packet_size & ARM_USB_ENDPOINT_MAX_PACKET_SIZE_MASK;

  if (ep_num > USBD_MAX_ENDPOINT_NUM) { return ARM_DRIVER_ERROR_PARAMETER; }
  if ((ep_addr & ARM_USB_ENDPOINT_DIRECTION_MASK) == ARM_USB_ENDPOINT_DIRECTION_MASK) { // IN endpoint
    if (ep_mps > ep_cfg[ep_num].tx_ram_size)    { return ARM_DRIVER_ERROR_PARAMETER; }
  } else {                                                                              // OUT endpoint
    if (ep_mps > ep_cfg[ep_num].rx_ram_size)    { return ARM_DRIVER_ERROR_PARAMETER; }
  }
  if (hw_powered == false)            { return ARM_DRIVER_ERROR; }

  ptr_ep = &ep[EP_ID(ep_addr)];
  if (ptr_ep->active != 0U)           { return ARM_DRIVER_ERROR_BUSY; }

  // Clear Endpoint transfer and configuration information
  memset((void *)((uint32_t)ptr_ep), 0, sizeof (ENDPOINT_t));

  // Set maximum packet size to requested
  ptr_ep->max_packet_size = ep_mps;

  HAL_PCD_EP_Open(p_hpcd, ep_addr, ep_mps, ep_type);

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_EndpointUnconfigure (uint8_t ep_addr)
  \brief       Unconfigure USB Endpoint.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \return      \ref execution_status
*/
static int32_t USBD_EndpointUnconfigure (uint8_t ep_addr) {
  uint8_t              ep_num;
  volatile ENDPOINT_t *ptr_ep;

  ep_num = EP_NUM(ep_addr);
  if (ep_num > USBD_MAX_ENDPOINT_NUM) { return ARM_DRIVER_ERROR_PARAMETER; }
  if (hw_powered == false)            { return ARM_DRIVER_ERROR; }

  ptr_ep = &ep[EP_ID(ep_addr)];
  if (ptr_ep->active != 0U)           { return ARM_DRIVER_ERROR_BUSY; }

  // Clear Endpoint transfer and configuration information
  memset((void *)((uint32_t)ptr_ep), 0, sizeof (ENDPOINT_t));

  HAL_PCD_EP_Close(p_hpcd, ep_addr);

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_EndpointStall (uint8_t ep_addr, bool stall)
  \brief       Set/Clear Stall for USB Endpoint.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \param[in]   stall  Operation
                - \b false Clear
                - \b true Set
  \return      \ref execution_status
*/
static int32_t USBD_EndpointStall (uint8_t ep_addr, bool stall) {
  uint8_t ep_num;

  ep_num = EP_NUM(ep_addr);
  if (ep_num > USBD_MAX_ENDPOINT_NUM) { return ARM_DRIVER_ERROR_PARAMETER; }
  if (hw_powered == false)            { return ARM_DRIVER_ERROR; }

  if (stall != 0U) {
    // Set STALL
    HAL_PCD_EP_SetStall(p_hpcd, ep_addr);
  } else {
    // Clear STALL
    HAL_PCD_EP_ClrStall(p_hpcd, ep_addr);
  }

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t USBD_EndpointTransfer (uint8_t ep_addr, uint8_t *data, uint32_t num)
  \brief       Read data from or Write data to USB Endpoint.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \param[out]  data Pointer to buffer for data to read or with data to write
  \param[in]   num  Number of data bytes to transfer
  \return      \ref execution_status
*/
static int32_t USBD_EndpointTransfer (uint8_t ep_addr, uint8_t *data, uint32_t num) {
  uint8_t              ep_num;
  bool                 ep_dir;
  volatile ENDPOINT_t *ptr_ep;

  ep_num = EP_NUM(ep_addr);
  if (ep_num > USBD_MAX_ENDPOINT_NUM) { return ARM_DRIVER_ERROR_PARAMETER; }
  if (hw_powered == false)            { return ARM_DRIVER_ERROR; }


  ptr_ep = &ep[EP_ID(ep_addr)];
  if (ptr_ep->active != 0U)           { return ARM_DRIVER_ERROR_BUSY; }

  ep_dir = (ep_addr & ARM_USB_ENDPOINT_DIRECTION_MASK) == ARM_USB_ENDPOINT_DIRECTION_MASK;

  ptr_ep->active = 1U;

  ptr_ep->data                  = data;
  ptr_ep->num                   = num;
  ptr_ep->num_transferred_total = 0U;
  ptr_ep->num_transferring      = num;

  if ((ep_addr & 0x7F) == 0) {
    // Only for EP0
    if (ptr_ep->max_packet_size < num) {
      ptr_ep->num_transferring = ptr_ep->max_packet_size;
    }
  }

  if (ep_dir != 0U) {
    // IN Endpoint
    HAL_PCD_EP_Transmit(p_hpcd, ep_addr, (uint8_t *)data, ptr_ep->num_transferring);
  } else {
    // OUT Endpoint
    HAL_PCD_EP_Receive(p_hpcd, ep_addr, (uint8_t *)data, ptr_ep->num_transferring);
  }
  

  return ARM_DRIVER_OK;
}

/**
  \fn          uint32_t USBD_EndpointTransferGetResult (uint8_t ep_addr)
  \brief       Get result of USB Endpoint transfer.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \return      number of successfully transferred data bytes
*/
static uint32_t USBD_EndpointTransferGetResult (uint8_t ep_addr) {
  volatile ENDPOINT_t *ptr_ep;

  ptr_ep = &ep[EP_ID(ep_addr)];
  return (ptr_ep->num_transferred_total);
}

/**
  \fn          int32_t USBD_EndpointTransferAbort (uint8_t ep_addr)
  \brief       Abort current USB Endpoint transfer.
  \param[in]   ep_addr  Endpoint Address
                - ep_addr.0..3: Address
                - ep_addr.7:    Direction
  \return      \ref execution_status
*/
static int32_t USBD_EndpointTransferAbort (uint8_t ep_addr) {
           uint8_t       ep_num;
  volatile ENDPOINT_t   *ptr_ep;

  ep_num = EP_NUM(ep_addr);
  if (ep_num > USBD_MAX_ENDPOINT_NUM) { return ARM_DRIVER_ERROR_PARAMETER; }
  if (hw_powered == false)            { return ARM_DRIVER_ERROR; }

  if (ep_addr &  0x80U) {
    PCD_SET_EP_TX_STATUS(USB, ep_num, USB_EP_TX_NAK);
    HAL_PCD_EP_Flush(p_hpcd, ep_addr);
  } else {
    PCD_SET_EP_RX_STATUS(USB, ep_num, USB_EP_RX_NAK);
  }

  ptr_ep = &ep[EP_ID(ep_addr)];
  ptr_ep->active = 0U;

  return ARM_DRIVER_OK;
}

/**
  \fn          uint16_t USBD_GetFrameNumber (void)
  \brief       Get current USB Frame Number.
  \return      Frame Number
*/
static uint16_t USBD_GetFrameNumber (void) {

  if (hw_powered == false) { return 0U; }

  return ((uint16_t)(USB_FNR & USB_FNR_FN));
}

// Callbacks from HAL
/**
  * @brief  Data OUT stage callback.
  * @param  hpcd: PCD handle
  * @param  epnum: endpoint number
  * @retval None
  */
void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum) {
  uint16_t             cnt;
  volatile ENDPOINT_t *ptr_ep;

  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  ptr_ep = &ep[EP_ID(epnum)];

  if (epnum != 0) {
    if (SignalEndpointEvent != NULL) {
      ptr_ep->active = 0U;
      ptr_ep->num_transferred_total = HAL_PCD_EP_GetRxCount(hpcd, epnum);
      SignalEndpointEvent(epnum, ARM_USBD_EVENT_OUT);
    }
  } else {
    cnt = HAL_PCD_EP_GetRxCount(hpcd, epnum);
    ptr_ep->num_transferred_total += cnt;
    if ((cnt < ptr_ep->max_packet_size) || (ptr_ep->num_transferred_total == ptr_ep->num)) {
      if (SignalEndpointEvent != NULL) {
        ptr_ep->active = 0U;
        SignalEndpointEvent(epnum, ARM_USBD_EVENT_OUT);
      }
    } else {
      ptr_ep->num_transferring = ptr_ep->num - ptr_ep->num_transferred_total;
      if (ptr_ep->num_transferring > ptr_ep->max_packet_size) {
        ptr_ep->num_transferring = ptr_ep->max_packet_size;
      }
      HAL_PCD_EP_Receive(p_hpcd, epnum, (uint8_t *)(ptr_ep->data + ptr_ep->num_transferred_total), ptr_ep->num_transferring);
    }
  }
}

/**
  * @brief  Data IN stage callback.
  * @param  hpcd: PCD handle
  * @param  epnum: endpoint number
  * @retval None
  */
void HAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum) {
  volatile ENDPOINT_t *ptr_ep;
  
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  ptr_ep = &ep[EP_ID(epnum | 0x80)];

  ptr_ep->num_transferred_total += ptr_ep->num_transferring;
  if (epnum != 0) {
    if (SignalEndpointEvent != NULL) {
      ptr_ep->active = 0U;
      SignalEndpointEvent(epnum | ARM_USB_ENDPOINT_DIRECTION_MASK, ARM_USBD_EVENT_IN);
    }
  } else {
    // EP0
    if(ptr_ep->num_transferred_total == ptr_ep->num) {
      if (SignalEndpointEvent != NULL) {
        ptr_ep->active = 0U;
        SignalEndpointEvent(epnum | ARM_USB_ENDPOINT_DIRECTION_MASK, ARM_USBD_EVENT_IN);
      }
    } else {
      ptr_ep->num_transferring = ptr_ep->num - ptr_ep->num_transferred_total;
      if (ptr_ep->num_transferring > ptr_ep->max_packet_size) {
        ptr_ep->num_transferring = ptr_ep->max_packet_size;
      }
        HAL_PCD_EP_Transmit(p_hpcd, epnum | 0x80, (uint8_t *)(ptr_ep->data + ptr_ep->num_transferred_total), ptr_ep->num_transferring);
    }
  }
}
/**
  * @brief  Setup stage callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd) {
  memcpy(setup_packet, hpcd->Setup, 8);
  setup_received = 1;

  // Analyze Setup packet for SetAddress
  if ((setup_packet[0] & 0xFFFFU) == 0x0500U) {
    USBD_DeviceSetAddress((setup_packet[0] >> 16) & 0xFFU);
  }

  if (SignalEndpointEvent != NULL) {
    SignalEndpointEvent(0, ARM_USBD_EVENT_SETUP);
  }
}

/**
  * @brief  USB Reset callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ResetCallback(PCD_HandleTypeDef *hpcd) {
  uint32_t pcd_addr;
  uint16_t n, kind, addr;

  memset((void *)((uint32_t)ep), 0, sizeof(ep));

  addr = (USBD_MAX_ENDPOINT_NUM + 1U) * 16U;
  for (n = 0U; n < (USBD_MAX_ENDPOINT_NUM + 1U); n++) {
    if (ep_cfg[n].tx_buf_kind == 0) {
      kind     = PCD_SNG_BUF;
      pcd_addr = addr;
    } else {
      kind     = PCD_DBL_BUF;
      pcd_addr = ((uint32_t)addr) | (((uint32_t)addr + (uint32_t)(ep_cfg[n].tx_ram_size/2U)) << 16);
    }
    HAL_PCDEx_PMAConfig(hpcd, 0x00U | n, kind, pcd_addr);
    addr += ep_cfg[n].tx_ram_size;

    if (ep_cfg[n].rx_buf_kind == 0) {
      kind     = PCD_SNG_BUF;
      pcd_addr = addr;
    } else {
      kind     = PCD_DBL_BUF;
      pcd_addr = ((uint32_t)addr) | (((uint32_t)addr + (uint32_t)(ep_cfg[n].rx_ram_size/2U)) << 16);
    }
    HAL_PCDEx_PMAConfig(hpcd, 0x80U | n, kind, pcd_addr);
    addr += ep_cfg[n].rx_ram_size;
  }

  if (SignalDeviceEvent != NULL) {
    SignalDeviceEvent(ARM_USBD_EVENT_RESET);
  }
}

/**
  * @brief  Suspend event callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_SuspendCallback(PCD_HandleTypeDef *hpcd) {
  UNUSED(hpcd);

  if (SignalDeviceEvent != NULL) {
    SignalDeviceEvent(ARM_USBD_EVENT_SUSPEND);
  }
}

/**
  * @brief  Resume event callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ResumeCallback(PCD_HandleTypeDef *hpcd) {
  UNUSED(hpcd);

  if (SignalDeviceEvent != NULL) {
    SignalDeviceEvent(ARM_USBD_EVENT_RESUME);
  }
}

/**
  * @brief  Incomplete ISO OUT callback.
  * @param  hpcd: PCD handle
  * @param  epnum: endpoint number
  * @retval None
  */
void HAL_PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum) {
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PCD_ISOOUTIncompleteCallback could be implemented in the user file
   */ 
}

/**
  * @brief  Incomplete ISO IN callback.
  * @param  hpcd: PCD handle
  * @param  epnum: endpoint number
  * @retval None
  */
void HAL_PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum) {
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PCD_ISOINIncompleteCallback could be implemented in the user file
   */ 
}

/**
  * @brief  Connection event callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_ConnectCallback(PCD_HandleTypeDef *hpcd) {
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  if (SignalDeviceEvent != NULL) {
    SignalDeviceEvent(ARM_USBD_EVENT_VBUS_ON);
  } 
}

/**
  * @brief  Disconnection event callback.
  * @param  hpcd: PCD handle
  * @retval None
  */
void HAL_PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd) {
  UNUSED(hpcd);

  if (SignalDeviceEvent != NULL) {
    SignalDeviceEvent(ARM_USBD_EVENT_VBUS_OFF);
  }
}


// Exported driver structure
ARM_DRIVER_USBD Driver_USBD0 = {
  USBD_GetVersion,
  USBD_GetCapabilities,
  USBD_Initialize,
  USBD_Uninitialize,
  USBD_PowerControl,
  USBD_DeviceConnect,
  USBD_DeviceDisconnect,
  USBD_DeviceGetState,
  USBD_DeviceRemoteWakeup,
  USBD_DeviceSetAddress,
  USBD_ReadSetupPacket,
  USBD_EndpointConfigure,
  USBD_EndpointUnconfigure,
  USBD_EndpointStall,
  USBD_EndpointTransfer,
  USBD_EndpointTransferGetResult,
  USBD_EndpointTransferAbort,
  USBD_GetFrameNumber
};

/*! \endcond */
