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

#include <stdint.h>

#ifndef TESTING_H
#define TESTING_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include"common/bootloader_utils.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup TESTING_API
 * @{
 */

////////////////////////////////////////////////////////////////////////////////
// Exported Variables
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// Exported Function Declarations
////////////////////////////////////////////////////////////////////////////////

void test_boot(uint32_t address);


/** @} */

#ifdef __cplusplus
}
#endif

#endif /* TESTING_H */