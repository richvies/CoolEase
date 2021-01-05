/**
 ******************************************************************************
 * @file    sensor_test.h
 * @author  Richard Davies
 * @date    27/Dec/2020
 * @brief   Sensor_test Header File
 *  
 * @defgroup   SENSOR_TEST_FILE  Sensor_test
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   SENSOR_TEST_API  Sensor_test API
 * @brief      
 * 
 * @defgroup   SENSOR_TEST_INT  Sensor_test Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef SENSOR_TEST_H
#define SENSOR_TEST_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup SENSOR_TEST_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

void test_sensor(uint32_t dev_num);
void test_si7051(uint8_t num_readings);
void test_tmp112(uint8_t num_readings);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_TEST_H */