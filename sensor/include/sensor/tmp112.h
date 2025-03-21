/**
 ******************************************************************************
 * @file    tmp112.h
 * @author  Richard Davies
 * @brief   TMP112 Temperature Sensor Driver Header File
 *
 * @defgroup sensor Sensor
 * @{
 *   @defgroup temperature_api Temperature Sensors
 *   @brief    Temperature sensor drivers and interfaces
 *   @{
 *     @defgroup tmp112_api TMP112 Temperature Sensor
 *     @brief    TMP112 digital temperature sensor driver
 *   @}
 * @}
 ******************************************************************************
 */

#ifndef TMP112_H
#define TMP112_H

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

/** @addtogroup tmp112_api
 * @{
 */

/**
 * @brief TMP112 I2C device address
 */
#define TMP112_I2C_ADDRESS 0x49

/**
 * @brief TMP112 register: Temperature register
 */
#define TMP112_SEL_TEMP_REG 0x00

/**
 * @brief TMP112 register: Configuration register
 */
#define TMP112_SEL_CONFIG_REG 0x01

/**
 * @brief TMP112 configuration: One-shot mode MSB
 */
#define TMP112_CONFIG_OS_MSB 0XE1

/**
 * @brief TMP112 configuration: One-shot mode LSB
 */
#define TMP112_CONFIG_OS_LSB 0XA0

/**
 * @brief TMP112 configuration: Continuous mode MSB
 */
#define TMP112_CONFIG_CM_MSB 0X60

/**
 * @brief TMP112 configuration: Continuous mode LSB
 */
#define TMP112_CONFIG_CM_LSB 0XA0

/**
 * @brief TMP112 general call address
 */
#define TMP112_GEN_CALL_ADDR 0X00

/**
 * @brief TMP112 reset command
 */
#define TMP112_RESET_CMD 0X06

/**
 * @brief Initialize the TMP112 temperature sensor
 * @return None
 */
void tmp112_init(void);

/**
 * @brief Terminate TMP112 operations
 * @return None
 */
void tmp112_end(void);

/**
 * @brief Reset the TMP112 sensor to default state
 * @return None
 */
void tmp112_reset(void);

/**
 * @brief Read temperature measurements from the TMP112 sensor
 * @param readings Buffer to store temperature readings (in 1/100 degrees C)
 * @param num_readings Number of readings to take
 * @return None
 */
void tmp112_read_temperature(int16_t* readings, uint8_t num_readings);

/** @} */ /* End of tmp112_api group */
/** @} */ /* End of temperature_api group */
/** @} */ /* End of sensor group */

#ifdef __cplusplus
}
#endif

#endif /* TMP112_H */
