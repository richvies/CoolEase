/* -----------------------------------------------------------------------------
 * Copyright (c) 2013-2017 ARM Ltd.
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
 * $Date:        10. November 2017
 * $Revision:    V1.0
 *
 * Driver:       Driver_USART1, Driver_USART2
 *
 * Configured:   via STM32CubeMx configuration tool
 * Project:      USART Driver for STMicroelectronics STM32L0xx
 * --------------------------------------------------------------------------
 * Use the following configuration settings in the middleware component
 * to connect to this driver.
 *
 *   Configuration Setting                   Value   SmartCard Interface
 *   ---------------------                   -----   --------------
 *   Connect to hardware via Driver_USART# = 1       use USART1
 *   Connect to hardware via Driver_USART# = 2       use USART2
 * -------------------------------------------------------------------------- */

/* History:
 *  Version 1.0
 *    Initial release
 */

/*! \page stm32l0_usart_smart CMSIS-Driver USART Setup in SmartCard mode

The CMSIS-Driver USART requires:
  - Setup of USART/UART peripheral in SmartCard mode

For different boards, refer to the hardware schematics to reflect correct setup values.

The STM32CubeMX configuration example with steps for Pinout, Clock, and System Configuration are 
listed below. Enter the values that are marked \b bold.

Pinout tab
----------
  1. Configure peripheral
     - Peripherals \b USART2: Mode=<b>SmartCard</b>

  2. Configure pins PA2 and PD7 as USART2 peripheral alternative pins
     - Click in chip diagram on pin \b PA2 and select \b USART2_TX
     - Click in chip diagram on pin \b PD7 and select \b USART2_CK

Clock Configuration tab
-----------------------
  1. Configure USART2 Clock

Configuration tab
-----------------
  1. Under Connectivity open \b USART2 Configuration:
     - Parameter Settings: not used
     - User Constants: not used
     - <b>NVIC Settings</b>: enable interrupts
          Interrupt Table                           | Enabled | Preemption Priority
          :-----------------------------------------|:--------|:-------------------
          DMA1 channel 4, channel 5, channel 6 and..|    ON   | 0
          USART2 global interrupt / USART2 wake-up..| \b ON   | 0

     - \e optional <b>DMA Settings</b>: setup DMA transfers for Rx and Tx (DMA is optional)\n
       \b Add - Select \b USART2_RX: Stream=DMA1 Channel 5, DMA Request Settings: not used, Priority=Low\n
       \b Add - Select \b USART2_TX: Stream=DMA1 Channel 4, DMA Request Settings: not used, Priority=Low

     - <b>GPIO Settings</b>: review settings, no changes required
          Pin Name | Signal on Pin | GPIO output..|  GPIO mode  | GPIO Pull-up/Pull..| Maximum out |  Fast Mode  | User Label
          :--------|:--------------|:-------------|:------------|:-------------------|:------------|:------------|:----------
          PA2      | USART2_TX     | n/a          | Alternate ..| Pull-up            | Very High   | n/a         |.
          PD7      | USART2_CK     | n/a          | Alternate ..| Pull-up            | Very High   | n/a         |.

     Click \b OK to close the USART2 Configuration dialog
*/

/*! \cond */

#include "SmartCard_STM32L0xx.h"

#ifndef HAL_SMARTCARD_MODULE_ENABLED
  #warning "::Device:STM32Cube Framework: SMARTCARD Not configured."
#else

#define ARM_USART_DRV_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1,0)

// Driver Version
static const ARM_DRIVER_VERSION usart_driver_version = { ARM_USART_API_VERSION, ARM_USART_DRV_VERSION };

static const ARM_USART_CAPABILITIES Capabilities = {
    0,      ///< supports UART (Asynchronous) mode 
    0,      ///< supports Synchronous Master mode
    0,      ///< supports Synchronous Slave mode
    0,      ///< supports UART Single-wire mode
    0,      ///< supports UART IrDA mode
    1,      ///< supports UART Smart Card mode
    0,      ///< Smart Card Clock generator available
    0,      ///< RTS Flow Control available
    0,      ///< CTS Flow Control available
    1,      ///< Transmit completed event: \ref ARM_USART_EVENT_TX_COMPLETE
    0,      ///< Signal receive character timeout event: \ref ARM_USART_EVENT_RX_TIMEOUT
    0,      ///< RTS Line: 0=not available, 1=available
    0,      ///< CTS Line: 0=not available, 1=available
    0,      ///< DTR Line: 0=not available, 1=available
    0,      ///< DSR Line: 0=not available, 1=available
    0,      ///< DCD Line: 0=not available, 1=available
    0,      ///< RI Line: 0=not available, 1=available
    0,      ///< Signal CTS change event: \ref ARM_USART_EVENT_CTS
    0,      ///< Signal DSR change event: \ref ARM_USART_EVENT_DSR
    0,      ///< Signal DCD change event: \ref ARM_USART_EVENT_DCD
    0       ///< Signal RI change event: \ref ARM_USART_EVENT_RI
#if (defined(ARM_USART_API_VERSION) && (ARM_USART_API_VERSION >= 0x203U))
  , 0U  // Reserved bits
#endif
  };

// USART1
#ifdef USART1_MODE_SMARTCARD
SMARTCARDx_RESOURCE_ALLOC(1);
#endif

// USART2
#ifdef USART2_MODE_SMARTCARD
SMARTCARDx_RESOURCE_ALLOC(2);
#endif

/**
  \fn          const SMARTCARD_RESOURCES SMARTCARD_Resources (SMARTCARD_HandleTypeDef *hsmartcard)
  \brief       Get UART_RESOURCES structure from SMARTCARD_HandleTypeDef
*/
static const SMARTCARD_RESOURCES * SMARTCARD_Resources (SMARTCARD_HandleTypeDef *hsmartcard) {
  const SMARTCARD_RESOURCES *smartcard = NULL;

#ifdef USART1_MODE_SMARTCARD
  if (hsmartcard->Instance == USART1) { smartcard = &SMARTCARD1_Resources; }
#endif
#ifdef USART2_MODE_SMARTCARD
  if (hsmartcard->Instance == USART2) { smartcard = &SMARTCARD2_Resources; }
#endif

  return smartcard;
}

/**
  \fn          void SMARTCARD_PeripheralReset (USART_TypeDef *usart)
  \brief       SMARTCARD Reset
*/
static void SMARTCARD_PeripheralReset (USART_TypeDef *usart) {

#ifdef USART1_MODE_SMARTCARD
  if (usart == USART1) { __HAL_RCC_USART1_FORCE_RESET(); }
#endif
#ifdef USART2_MODE_SMARTCARD
  if (usart == USART2) { __HAL_RCC_USART2_FORCE_RESET(); }
#endif

      __NOP(); __NOP(); __NOP(); __NOP(); 
#ifdef USART1_MODE_SMARTCARD
  if (usart == USART1) { __HAL_RCC_USART1_RELEASE_RESET(); }
#endif
#ifdef USART2_MODE_SMARTCARD
  if (usart == USART2) { __HAL_RCC_USART2_RELEASE_RESET(); }
#endif
}

// USART Driver functions

/**
  \fn          ARM_DRIVER_VERSION SMARTCARD_GetVersion (void)
  \brief       Get driver version.
  \return      \ref ARM_DRIVER_VERSION
*/
static ARM_DRIVER_VERSION SMARTCARD_GetVersion (void) {
  return usart_driver_version;
}

/**
  \fn          ARM_USART_CAPABILITIES SMARTCARD_GetCapabilities (void)
  \brief       Get driver capabilities
  \param[in]   usart     Pointer to USART resources
  \return      \ref ARM_USART_CAPABILITIES
*/
static ARM_USART_CAPABILITIES SMARTCARD_GetCapabilities (void) {
  return Capabilities;
}

/**
  \fn          int32_t SMARTCARD_Initialize (      ARM_USART_SignalEvent_t   cb_event
                                             const SMARTCARD_RESOURCES      *smartcard)
  \brief       Initialize USART Interface.
  \param[in]   cb_event  Pointer to \ref ARM_USART_SignalEvent
  \param[in]   smartcard      Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_Initialize (      ARM_USART_SignalEvent_t   cb_event,
                                     const SMARTCARD_RESOURCES      *smartcard) {

  if (smartcard->info->flags & SMARTCARD_FLAG_INITIALIZED) {
    // Driver is already initialized
    return ARM_DRIVER_OK;
  }

  smartcard->h->Init.Mode = 0;

  // Initialize SMARTCARD Run-time Resources
  smartcard->info->cb_event = cb_event;

  // Clear transfer information
  memset(smartcard->xfer, 0, sizeof(SMARTCARD_TRANSFER_INFO));
  
  smartcard->h->Instance = smartcard->reg;

  smartcard->info->flags = SMARTCARD_FLAG_INITIALIZED;

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t SMARTCARD_Uninitialize (const SMARTCARD_RESOURCES *smartcard)
  \brief       De-initialize SMARTCARD Interface.
  \param[in]   usart     Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_Uninitialize (const SMARTCARD_RESOURCES *smartcard) {

  // Reset SMARTCARD status flags
  smartcard->info->flags = 0U;

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t SMARTCARD_PowerControl (ARM_POWER_STATE state)
  \brief       Control SMARTCARD Interface Power.
  \param[in]   state  Power state
  \param[in]   usart  Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_PowerControl (      ARM_POWER_STATE       state,
                                       const SMARTCARD_RESOURCES  *smartcard) {

  switch (state) {
    case ARM_POWER_OFF:

      // SMARTCARD peripheral reset
      SMARTCARD_PeripheralReset (smartcard->reg);

      if (smartcard->h->Instance != NULL) {
        HAL_SMARTCARD_MspDeInit (smartcard->h);
      }

      smartcard->info->flags &= ~SMARTCARD_FLAG_POWERED;
      break;
    case ARM_POWER_LOW:
      return ARM_DRIVER_ERROR_UNSUPPORTED;

    case ARM_POWER_FULL:
      if ((smartcard->info->flags & SMARTCARD_FLAG_INITIALIZED) == 0U) {
        return ARM_DRIVER_ERROR;
      }
      if ((smartcard->info->flags & SMARTCARD_FLAG_POWERED)     != 0U) {
        return ARM_DRIVER_OK;
      }

      smartcard->xfer->def_val    = 0U;

      smartcard->info->flags = SMARTCARD_FLAG_POWERED | SMARTCARD_FLAG_INITIALIZED;

      HAL_SMARTCARD_MspInit (smartcard->h);

      // SMARTCARD peripheral reset
      SMARTCARD_PeripheralReset (smartcard->reg);

    break;
  }
  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t SMARTCARD_Send (const void                *data,
                                             uint32_t             num,
                                       const SMARTCARD_RESOURCES *smartcard)
  \brief       Start sending data to SMARTCARD transmitter.
  \param[in]   data  Pointer to buffer with data to send to SMARTCARD transmitter
  \param[in]   num   Number of data items to send
  \param[in]   usart Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_Send (const void                 *data,
                                     uint32_t              num,
                               const SMARTCARD_RESOURCES  *smartcard) {

  HAL_StatusTypeDef stat;

  if ((data == NULL) || (num == 0U)) {
    // Invalid parameters
    return ARM_DRIVER_ERROR_PARAMETER;
  }

  if ((smartcard->info->flags & SMARTCARD_FLAG_CONFIGURED) == 0U) {
    // SMARTCARD is not configured (mode not selected)
    return ARM_DRIVER_ERROR;
  }

  switch (HAL_SMARTCARD_GetState (smartcard->h)) {
    case HAL_SMARTCARD_STATE_RESET:
    case HAL_SMARTCARD_STATE_ERROR:
      return ARM_DRIVER_ERROR;

    case HAL_SMARTCARD_STATE_TIMEOUT:
      return ARM_DRIVER_ERROR_TIMEOUT;

    case HAL_SMARTCARD_STATE_BUSY:
    case HAL_SMARTCARD_STATE_BUSY_TX:
    case HAL_SMARTCARD_STATE_BUSY_RX:
    case HAL_SMARTCARD_STATE_BUSY_TX_RX:
      return ARM_DRIVER_ERROR_BUSY;

    case HAL_SMARTCARD_STATE_READY:
      break;
  }

  // Save buffer info
  smartcard->xfer->tx_num = num;
  smartcard->xfer->tx_cnt = 0U;

  if (smartcard->dma_use_tx != 0U) {
    // DMA mode
    stat = HAL_SMARTCARD_Transmit_DMA (smartcard->h, (uint8_t *)(uint32_t)data, (uint16_t)num);
  } else {
    // Interrupt mode
    stat = HAL_SMARTCARD_Transmit_IT (smartcard->h, (uint8_t *)(uint32_t)data, (uint16_t)num);
  }

  switch (stat) {
    case HAL_ERROR:
    case HAL_TIMEOUT:
      return ARM_DRIVER_ERROR;

    case HAL_BUSY:
      return ARM_DRIVER_ERROR_BUSY;

    case HAL_OK:
      break;
  }

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t SMARTCARD_Receive (       void                 *data,
                                                 uint32_t              num,
                                           const SMARTCARD_RESOURCES  *smartcard)
  \brief       Start receiving data from SMARTCARD receiver.
  \param[out]  data  Pointer to buffer for data to receive from SMARTCARD receiver
  \param[in]   num   Number of data items to receive
  \param[in]   usart Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_Receive (      void                *data,
                                        uint32_t             num,
                                  const SMARTCARD_RESOURCES *smartcard) {

  HAL_StatusTypeDef stat;

  if ((data == NULL) || (num == 0U)) {
    // Invalid parameters
    return ARM_DRIVER_ERROR_PARAMETER;
  }

  if ((smartcard->info->flags & SMARTCARD_FLAG_CONFIGURED) == 0U) {
    // SMARTCARD is not configured (mode not selected)
    return ARM_DRIVER_ERROR;
  }

  switch (HAL_SMARTCARD_GetState (smartcard->h)) {
    case HAL_SMARTCARD_STATE_RESET:
    case HAL_SMARTCARD_STATE_ERROR:
      return ARM_DRIVER_ERROR;

    case HAL_SMARTCARD_STATE_TIMEOUT:
      return ARM_DRIVER_ERROR_TIMEOUT;

    case HAL_SMARTCARD_STATE_BUSY:
    case HAL_SMARTCARD_STATE_BUSY_TX:
    case HAL_SMARTCARD_STATE_BUSY_RX:
    case HAL_SMARTCARD_STATE_BUSY_TX_RX:
      return ARM_DRIVER_ERROR_BUSY;

    case HAL_SMARTCARD_STATE_READY:
      break;
  }

  // Save buffer info
  smartcard->xfer->rx_num = num;
  smartcard->xfer->rx_cnt = 0U;

  if (smartcard->dma_use_rx != 0U) {
    // DMA mode
    stat = HAL_SMARTCARD_Receive_DMA (smartcard->h, (uint8_t *)(uint32_t)data, (uint16_t)num);
  } else {
    // Interrupt mode
    stat = HAL_SMARTCARD_Receive_IT (smartcard->h, (uint8_t *)(uint32_t)data, (uint16_t)num);
  }

  switch (stat) {
    case HAL_ERROR:
    case HAL_TIMEOUT:
      return ARM_DRIVER_ERROR;

    case HAL_BUSY:
      return ARM_DRIVER_ERROR_BUSY;

    case HAL_OK:
      break;
  }

  return ARM_DRIVER_OK;
}

/**
  \fn          int32_t SMARTCARD_Transfer (const void                 *data_out,
                                                 void                 *data_in,
                                                 uint32_t              num,
                                           const SMARTCARD_RESOURCES  *smartcard)
  \brief       Start sending/receiving data to/from SMARTCARD transmitter/receiver.
  \param[in]   data_out  Pointer to buffer with data to send to SMARTCARD transmitter
  \param[out]  data_in   Pointer to buffer for data to receive from SMARTCARD receiver
  \param[in]   num       Number of data items to transfer
  \param[in]   smartcard      Pointer to SMARTCARD resources
  \return      \ref execution_status
*/
static int32_t SMARTCARD_Transfer (const void                 *data_out,
                                         void                 *data_in,
                                         uint32_t              num,
                                   const SMARTCARD_RESOURCES  *smartcard) {

  UNUSED(data_out);
  UNUSED(data_in);
  UNUSED(num);
  UNUSED(smartcard);

  // Supported only in Synchronous mode
  return ARM_DRIVER_ERROR;
}

/**
  \fn          uint32_t SMARTCARD_GetTxCount (const SMARTCARD_RESOURCES *smartcard)
  \brief       Get transmitted data count.
  \param[in]   smartcard     Pointer to SMARTCARD resources
  \return      number of data items transmitted
*/
static uint32_t SMARTCARD_GetTxCount (const SMARTCARD_RESOURCES *smartcard) {
  return smartcard->xfer->tx_cnt;
}

/**
  \fn          uint32_t SMARTCARD_GetRxCount (const SMARTCARD_RESOURCES *smartcard)
  \brief       Get received data count.
  \param[in]   smartcard     Pointer to SMARTCARD resources
  \return      number of data items received
*/
static uint32_t SMARTCARD_GetRxCount (const SMARTCARD_RESOURCES *smartcard) {
  return smartcard->xfer->rx_cnt;
}

/**
  \fn          int32_t SMARTCARD_Control (      uint32_t              control,
                                                uint32_t              arg,
                                          const SMARTCARD_RESOURCES  *smartcard)
  \brief       Control SMARTCARD Interface.
  \param[in]   control  Operation
  \param[in]   arg      Argument of operation (optional)
  \param[in]   smartcard    Pointer to SMARTCARD resources
  \return      common \ref execution_status and driver specific \ref smartcard_execution_status
*/
static int32_t SMARTCARD_Control (     uint32_t              control,
                                       uint32_t              arg,
                                 const SMARTCARD_RESOURCES  *smartcard) {

  SMARTCARD_ClockSourceTypeDef clksrc = SMARTCARD_CLOCKSOURCE_UNDEFINED;
  HAL_StatusTypeDef            status;
  uint32_t                     val;
  uint8_t                      i;

  if ((smartcard->info->flags & SMARTCARD_FLAG_POWERED) == 0U) {
    // SmartCard not powered
    return ARM_DRIVER_ERROR;
  }

  switch (control & ARM_USART_CONTROL_Msk) {
     // Control break
    case ARM_USART_CONTROL_BREAK:
      return ARM_DRIVER_ERROR_UNSUPPORTED;

    // Abort
    case ARM_USART_ABORT_SEND:
      HAL_SMARTCARD_AbortTransmit(smartcard->h);
      return ARM_DRIVER_OK;
    case ARM_USART_ABORT_RECEIVE:
      HAL_SMARTCARD_AbortReceive(smartcard->h);
      return ARM_DRIVER_OK;
    case ARM_USART_ABORT_TRANSFER:
      HAL_SMARTCARD_Abort(smartcard->h);
      return ARM_DRIVER_OK;

    // Control TX
    case ARM_USART_CONTROL_TX:
      if (arg) {
        // Transmitter enable
        smartcard->h->Init.Mode |=  SMARTCARD_MODE_TX;
      } else {
        // Transmitter disable
        smartcard->h->Init.Mode &= ~SMARTCARD_MODE_TX;
      }
      status = HAL_SMARTCARD_Init(smartcard->h);
      return SMARTCARD_HAL_STATUS(status);

    // Control RX
    case ARM_USART_CONTROL_RX:
      if (arg) {
        smartcard->h->Init.Mode |= SMARTCARD_MODE_RX;
      } else {
        // Receiver disable
        smartcard->h->Init.Mode &= ~SMARTCARD_MODE_RX;
      }
      status = HAL_SMARTCARD_Init(smartcard->h);
      return SMARTCARD_HAL_STATUS(status);
    default: break;
  }

  switch (control & ARM_USART_CONTROL_Msk) {
    case ARM_USART_MODE_IRDA:
    case ARM_USART_MODE_ASYNCHRONOUS:
    case ARM_USART_MODE_SYNCHRONOUS_MASTER:
    case ARM_USART_MODE_SYNCHRONOUS_SLAVE:
    case ARM_USART_MODE_SINGLE_WIRE:
      return ARM_USART_ERROR_MODE;

    case ARM_USART_MODE_SMART_CARD:
      break;

    // Default TX value
    case ARM_USART_SET_DEFAULT_TX_VALUE:
      smartcard->xfer->def_val = (uint16_t)arg;
      return ARM_DRIVER_OK;

    // SmartCard guard time
    case ARM_USART_SET_SMART_CARD_GUARD_TIME:
      if (arg > 255U) return ARM_DRIVER_ERROR;
      smartcard->h->Init.GuardTime = arg & 0xFF;
      HAL_SMARTCARD_Init(smartcard->h);
      return ARM_DRIVER_OK;

    // SmartCard clock
    case ARM_USART_SET_SMART_CARD_CLOCK:
      SMARTCARD_GETCLOCKSOURCE(smartcard->h, clksrc);
      switch (clksrc)
      {
        case SMARTCARD_CLOCKSOURCE_PCLK1:
          val = HAL_RCC_GetPCLK1Freq();
          break;
        case SMARTCARD_CLOCKSOURCE_PCLK2:
          val = HAL_RCC_GetPCLK2Freq();
          break;
        case SMARTCARD_CLOCKSOURCE_HSI:
          val = HSI_VALUE;
          break;
        case SMARTCARD_CLOCKSOURCE_SYSCLK:
          val = HAL_RCC_GetSysClockFreq();
          break;
        case SMARTCARD_CLOCKSOURCE_LSE:
          val = LSE_VALUE;
          break;
        case SMARTCARD_CLOCKSOURCE_UNDEFINED:
          return ARM_DRIVER_ERROR;
      }

      // Calculate period in ns
      val = 1000000000U / val;
      for (i = 1U; i <64U; i++) {
        // if in +-2% tolerance
        if (((val * i * 2U * 100U) < (arg * 102U)) &&
            ((val * i * 2U * 100U) > (arg * 98U))    ) {
          break;
        }
      }
      if (i == 64U) { return ARM_DRIVER_ERROR; }
      smartcard->h->Init.Prescaler = i;
      HAL_SMARTCARD_Init(smartcard->h);
      return ARM_DRIVER_OK;

    // SmartCard NACK
    case ARM_USART_CONTROL_SMART_CARD_NACK:
      if (arg != 0U) {
        smartcard->h->Init.NACKEnable = SMARTCARD_NACK_ENABLE;
      } else {
        smartcard->h->Init.NACKEnable = SMARTCARD_NACK_DISABLE;
      }
      HAL_SMARTCARD_Init(smartcard->h);
      return ARM_DRIVER_OK;

    // Unsupported command
    default: { return ARM_DRIVER_ERROR_UNSUPPORTED; }
  }

  // SmartCard Data bits
  if ((control & ARM_USART_DATA_BITS_Msk) == ARM_USART_DATA_BITS_8) {
    smartcard->h->Init.WordLength = SMARTCARD_WORDLENGTH_9B;
  }
  else{
    return ARM_USART_ERROR_DATA_BITS;
  }

  // SmartCard Parity
  switch (control & ARM_USART_PARITY_Msk) {
    case ARM_USART_PARITY_EVEN:
      smartcard->h->Init.Parity = SMARTCARD_PARITY_EVEN;
      break;
    case ARM_USART_PARITY_ODD:
      smartcard->h->Init.Parity = SMARTCARD_PARITY_ODD;
      break;
    case ARM_USART_PARITY_NONE:
    default: return ARM_USART_ERROR_PARITY;
  }

  // SmartCard Stop bits
  switch (control & ARM_USART_STOP_BITS_Msk) {
    case ARM_USART_STOP_BITS_1:
      break;
    case ARM_USART_STOP_BITS_2:
    case ARM_USART_STOP_BITS_1_5:
    case ARM_USART_STOP_BITS_0_5:
    default: return ARM_USART_ERROR_STOP_BITS;
  }

  // SmartCard Flow control
  switch (control & ARM_USART_FLOW_CONTROL_Msk) {
    case ARM_USART_FLOW_CONTROL_NONE:
      break;
    case ARM_USART_FLOW_CONTROL_RTS:
    case ARM_USART_FLOW_CONTROL_CTS:
    case ARM_USART_FLOW_CONTROL_RTS_CTS:
    default: return ARM_USART_ERROR_FLOW_CONTROL;
  }

  // SmartCard Baudrate
  smartcard->h->Init.BaudRate = arg;

  // Set configured flag
  smartcard->info->flags |= SMARTCARD_FLAG_CONFIGURED;

  // Initialize SmartCard
  status = HAL_SMARTCARD_Init(smartcard->h);
  return SMARTCARD_HAL_STATUS(status);
}

/**
  \fn          ARM_USART_STATUS SMARTCARD_GetStatus (const SMARTCARD_RESOURCES *smartcard)
  \brief       Get SMARTCARD status.
  \param[in]   smartcard     Pointer to SMARTCARD resources
  \return      USART status \ref ARM_USART_STATUS
*/
static ARM_USART_STATUS SMARTCARD_GetStatus (const SMARTCARD_RESOURCES *smartcard) {
  ARM_USART_STATUS  status;
  uint32_t          error;

  status.rx_busy = 0;
  status.tx_busy = 0;
  switch (HAL_SMARTCARD_GetState (smartcard->h)) {
    case HAL_SMARTCARD_STATE_BUSY:
    case HAL_SMARTCARD_STATE_BUSY_TX_RX:
      status.rx_busy = 1;
      status.tx_busy = 1;
      break;
    case HAL_SMARTCARD_STATE_BUSY_TX:
      status.tx_busy = 1;
      break;
    case HAL_SMARTCARD_STATE_BUSY_RX:
      status.rx_busy = 1;
      break;

    case HAL_SMARTCARD_STATE_TIMEOUT:
    case HAL_SMARTCARD_STATE_READY:
    case HAL_SMARTCARD_STATE_RESET:
    case HAL_SMARTCARD_STATE_ERROR:
      break;
  }

  error = HAL_SMARTCARD_GetError (smartcard->h);

  if (error & HAL_SMARTCARD_ERROR_PE) {
    status.rx_parity_error = 1;
  } else {
    status.rx_parity_error = 0;
  }

  if (error & HAL_SMARTCARD_ERROR_FE) {
    status.rx_framing_error = 1;
  } else {
    status.rx_framing_error = 0;
  }

  if (error & HAL_SMARTCARD_ERROR_ORE) {
    status.rx_overflow = 1;
  } else {
    status.rx_overflow = 0;
  }

  status.tx_underflow     = 0;

  return status;
}

/**
  \fn          int32_t SMARTCARD_SetModemControl (ARM_USART_MODEM_CONTROL  control
  \brief       Set USART Modem Control line state.
  \param[in]   control   \ref ARM_USART_MODEM_CONTROL
  \return      \ref execution_status
*/
static int32_t SMARTCARD_SetModemControl (ARM_USART_MODEM_CONTROL  control) {

  (void) control;

  // No modem control in synchronous mode
  return ARM_DRIVER_ERROR;
}

/**
  \fn          ARM_USART_MODEM_STATUS SMARTCARD_GetModemStatus (void)
  \brief       Get UART Modem Status lines state.
  \return      modem status \ref ARM_UART_MODEM_STATUS
*/
static ARM_USART_MODEM_STATUS SMARTCARD_GetModemStatus (void) {
  ARM_USART_MODEM_STATUS modem_status;

  modem_status.cts = 0U;
  modem_status.dsr = 0U;
  modem_status.ri  = 0U;
  modem_status.dcd = 0U;

  return modem_status;
}

/**
  * @brief Tx Transfer completed callback.
  * @param husart: SMARTCARD handle.
  * @retval None
  */
void HAL_SMARTCARD_TxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard) {
  const SMARTCARD_RESOURCES * smartcard;

  smartcard = SMARTCARD_Resources (hsmartcard);
  smartcard->xfer->tx_cnt = smartcard->xfer->tx_num;

  if (smartcard->info->cb_event != NULL) {
    smartcard->info->cb_event(ARM_USART_EVENT_TX_COMPLETE | ARM_USART_EVENT_SEND_COMPLETE);
  }
}

/**
  * @brief  Rx Transfer completed callback.
  * @param husart: SMARTCARD handle.
  * @retval None
  */
void HAL_SMARTCARD_RxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard) {
  const SMARTCARD_RESOURCES * smartcard;

  smartcard = SMARTCARD_Resources (hsmartcard);
  smartcard->xfer->rx_cnt = smartcard->xfer->rx_num;

  if (smartcard->info->cb_event != NULL) {
    smartcard->info->cb_event(ARM_USART_EVENT_RECEIVE_COMPLETE);
  }
}

/**
  * @brief SMARTCARD error callback.
  * @param hsmartcard: SMARTCARD handle.
  * @retval None
  */
void HAL_SMARTCARD_ErrorCallback(SMARTCARD_HandleTypeDef *hsmartcard) {
  const SMARTCARD_RESOURCES * smartcard;
        uint32_t         error;
        uint32_t         event;

  smartcard = SMARTCARD_Resources (hsmartcard);

  error = HAL_SMARTCARD_GetError (smartcard->h);
  event = 0;

  if (error & HAL_SMARTCARD_ERROR_PE) {
    event |= ARM_USART_EVENT_RX_PARITY_ERROR;
  }
  if (error & HAL_SMARTCARD_ERROR_FE) {
    event |= ARM_USART_EVENT_RX_FRAMING_ERROR;
  }
  if (error & HAL_SMARTCARD_ERROR_ORE) {
    event |= ARM_USART_EVENT_RX_OVERFLOW;
  }

  if ((event != 0) && (smartcard->info->cb_event != NULL)) {
    smartcard->info->cb_event(event);
  }
}

#ifdef USART1_MODE_SMARTCARD
SMARTCARDx_EXPORT_DRIVER(1);
#endif

#ifdef USART2_MODE_SMARTCARD
SMARTCARDx_EXPORT_DRIVER(2);
#endif

#endif /* HAL_SMARTCARD_MODULE_ENABLED */

/*! \endcond */
