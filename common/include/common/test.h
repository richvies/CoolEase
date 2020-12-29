/**
 ******************************************************************************
 * @file    test.h
 * @author  Richard Davies
 * @date    26/Dec/2020
 * @brief   Testing Header File
 *  
 * @defgroup   TEST_FILE  Testing
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   TEST_API  Testing API
 * @brief      
 * 
 * @defgroup   TEST_INT  Testing Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef TEST_H
#define TEST_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#include"common/bootloader_utils.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup TEST_API
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
void test_wakeup(void);
void test_standby(uint32_t standby_time);
void test_rf(void);
void test_rf_listen(void);
void test_receiver(uint32_t dev_num);
void test_voltage_scale(uint8_t scale);
void test_low_power_run(void);
void test_eeprom(void);
void test_eeprom_keys(void);
void test_eeprom_wipe(void);
void test_lptim(void);
void test_rfm(void);
void test_reset_eeprom(void);
void test_encryption(void);
bool test_timeout(void);
void test_log(void);
void test_analog_watchdog(void);


/** @} */

#endif /* TEST_H */