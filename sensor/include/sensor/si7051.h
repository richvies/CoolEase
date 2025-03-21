/**
 ******************************************************************************
 * @file    si7051.h
 * @author  Richard Davies
 * @brief   SI7051 Temperature Sensor Driver Header File
 *
 * @defgroup sensor Sensor
 * @{
 *   @defgroup temperature_api Temperature Sensors
 *   @brief    Temperature sensor drivers and interfaces
 *   @{
 *     @defgroup si7051_api SI7051 Temperature Sensor
 *     @brief    SI7051 digital temperature sensor driver
 *   @}
 * @}
 ******************************************************************************
 */

#ifndef SI7051_H
#define SI7051_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sensor
 * @{
 */

/** @addtogroup temperature_api
 * @{
 */

/** @addtogroup si7051_api
 * @{
 */

/**
 * @brief SI7051 I2C device address
 */
#define SI7051_I2C_ADDRESS 0x40

/**
 * @brief SI7051 command: Measure temperature and hold master (SCL line is
 * blocked)
 */
#define SI7051_CMD_MEASURE_HOLD 0xE3

/**
 * @brief SI7051 command: Measure temperature without holding master
 */
#define SI7051_CMD_MEASURE_NO_HOLD 0xF3

/**
 * @brief SI7051 command: Reset device
 */
#define SI7051_CMD_RESET 0xFE

/**
 * @brief SI7051 command: Write to user register
 */
#define SI7051_CMD_WRITE_REG 0xE6

/**
 * @brief SI7051 command: Read from user register
 */
#define SI7051_CMD_READ_REG 0xE7

/**
 * @brief SI7051 default user register value
 */
#define SI7051_USER_REG_VAL 0X00

/**
 * @brief Initialize the SI7051 temperature sensor
 * @return None
 */
void si7051_init(void);

/**
 * @brief Terminate SI7051 operations
 * @return None
 */
void si7051_end(void);

/**
 * @brief Reset the SI7051 sensor to default state
 * @return None
 */
void si7051_reset(void);

/**
 * @brief Read temperature measurements from the SI7051 sensor
 * @param readings Buffer to store temperature readings (in 1/100 degrees C)
 * @param num_readings Number of readings to take
 * @return None
 */
void si7051_read_temperature(int16_t* readings, uint8_t num_readings);

/** @} */ /* End of si7051_api group */
/** @} */ /* End of temperature_api group */
/** @} */ /* End of sensor group */

#ifdef __cplusplus
}
#endif

#endif /* SI7051_H */
