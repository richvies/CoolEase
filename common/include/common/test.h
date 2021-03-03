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
#include <stdlib.h>

#include "common/board_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup TEST_API
 * @{
 */

#define DEV_NUM_CHIP		(uint32_t)0x0000001B
#define DEV_NUM_PCB		    (uint32_t)~DEV_NUM_CHIP

void test_init(const char *test_name);
void flash_led(uint16_t milliseconds, uint8_t num_flashes);
void print_aes_key(app_info_t *app_info);

/*////////////////////////////////////////////////////////////////////////////*/
// Memory tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_mem_write_read(void);
void test_eeprom(void);
void test_eeprom_read(void);
void test_eeprom_keys(void);
void test_eeprom_wipe(void);
void test_reset_eeprom(void);

void test_log(void);
void test_bkp_reg(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Bootloader utils tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_boot_jump_to_application(uint32_t address);
void test_boot_verify_checksum(void);
void test_crc(void);


/*////////////////////////////////////////////////////////////////////////////*/
// RFM tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_rf(void);
void test_rf_listen(void);
void test_rfm(void);


/*////////////////////////////////////////////////////////////////////////////*/
// Timer tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_rtc(void);
void test_rtc_wakeup(void);

void test_tim6(void);

void test_micros(void);
void test_millis(void);


void test_lptim(void);
void test_wakeup(void);
bool test_timers_timeout(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Low Power tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_standby(uint32_t standby_time);
void test_voltage_scale(uint8_t scale);
void test_low_power_run(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Battery
/*////////////////////////////////////////////////////////////////////////////*/

void test_batt_update_voltages(void);
void test_batt_interrupt(void);

/*////////////////////////////////////////////////////////////////////////////*/
// Other tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_encryption(uint8_t *key);
void test_analog_watchdog(void);


/** @} */

#endif // TEST_H 