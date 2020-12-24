#ifndef TMP112_H
#define TMP112_H

#include <stdint.h>

#define TMP112_I2C_ADDRESS          0x48

#define TMP112_SEL_TEMP_REG         0x00
#define TMP112_SEL_CONFIG_REG       0x01

#define TMP112_CONFIG_OS_MSB        0XE1
#define TMP112_CONFIG_OS_LSB        0XA0

void tmp112_setup_and_read_temperature(float* readings, uint8_t num_readings);

#endif