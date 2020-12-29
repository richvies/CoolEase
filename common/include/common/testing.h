/**
 ******************************************************************************
 * @file    testing.h
 * @author  Richard Davies
 * @date    26/Dec/2020
 * @brief   Testing Header File
 *  
 * @defgroup   TESTING_FILE  Testing
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   TESTING_API  Testing API
 * @brief      
 * 
 * @defgroup   TESTING_INT  Testing Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef TESTING_H
#define TESTING_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#include"common/bootloader_utils.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup TESTING_API
 * @{
 */

#define DEV_NUM_CHIP		(uint32_t)0x0000001B
#define DEV_NUM_PCB		    (uint32_t)~DEV_NUM_CHIP

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void test_boot(uint32_t address);
void flash_led(uint16_t milliseconds, uint8_t num_flashes);
void testing_wakeup(void);
void testing_standby(uint32_t standby_time);
void testing_rf(void);
void testing_rf_listen(void);
void testing_receiver(uint32_t dev_num);
void testing_voltage_scale(uint8_t scale);
void testing_low_power_run(void);
void testing_eeprom(void);
void testing_eeprom_keys(void);
void testing_eeprom_wipe(void);
void testing_lptim(void);
void testing_rfm(void);
void testing_reset_eeprom(void);
void testing_encryption(void);
bool testing_timeout(void);
void testing_log(void);
void testing_analog_watchdog(void);


/** @} */

#endif /* TESTING_H */