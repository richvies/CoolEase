/**
 ******************************************************************************
 * @file    log.h
 * @author  Richard Davies
 * @date    30/Dec/2020
 * @brief   Log Header File
 *  
 * @defgroup   LOG_FILE  Log
 * @brief      
 * 
 * Description
 * 
 * @note     
 * 
 * @{
 * @defgroup   LOG_API  Log API
 * @brief      
 * 
 * @defgroup   LOG_INT  Log Internal
 * @brief      
 * @}
 ******************************************************************************
 */

#ifndef LOG_H
#define LOG_H

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup LOG_API
 * @{
 */

enum log_type
{
    MAIN=0,
    BOOT,
    RFM,
    TMP
};

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Variables
/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/
void log_init(void);
void log_printf(enum log_type type, const char *format, ...);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* LOG_H */
