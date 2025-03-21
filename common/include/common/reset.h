/**
 ******************************************************************************
 * @file    reset.h
 * @author  Richard Davies
 * @brief   System Reset Management Header File
 *
 * @defgroup common Common
 * @{
 *   @defgroup reset_api Reset Management
 *   @brief    System reset and reboot functionality
 * @}
 ******************************************************************************
 */

#ifndef RESET_H
#define RESET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup reset_api Reset
 * @{
 */

/**
 * @brief Print the cause of the last system reset
 * @return None
 */
void reset_print_cause(void);

/**
 * @brief Save current reset flags to persistent storage
 * @return None
 */
void reset_save_flags(void);

/**
 * @brief Get the current reset flags
 * @return Reset flags as a 32-bit value
 */
uint32_t reset_get_flags(void);

/** @} */ /* End of reset_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // RESET_H
