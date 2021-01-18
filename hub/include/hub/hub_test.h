/**
 ******************************************************************************
 * @file    hub_test.h
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Hub_test Header File
 *  
 * @defgroup   HUB_TEST_FILE  Hub_test
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   HUB_TEST_API  Hub_test API
 * @brief      
 * 
 * @defgroup   HUB_TEST_INT  Hub_test Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef HUB_TEST_H
#define HUB_TEST_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup HUB_TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void test_hub_init(const char* test_name);
void test_hub(void);
void test_hub_rf_vs_temp_cal(void);
void test_receiver(uint32_t dev_num);

/*////////////////////////////////////////////////////////////////////////////*/
// USB Tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_cusb_poll(void);
void test_cusb_get_log(void);

/*////////////////////////////////////////////////////////////////////////////*/
// SIM800 Tests
/*////////////////////////////////////////////////////////////////////////////*/

void test_sim_serial_passtrhough(void);
void test_sim(void);
void test_sim_get_request(void);


/** @} */

#ifdef __cplusplus
}
#endif

#endif // HUB_TEST_H 