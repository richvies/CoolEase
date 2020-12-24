#ifndef TMP112_H
#define TMP112_H

#include <stdint.h>

#define TMP112_I2C_ADDRESS          0x48

#define TMP112_SEL_TEMP_REG         0x00
#define TMP112_SEL_CONFIG_REG       0x01

#define TMP112_CONFIG_OS_MSB        0XE1
#define TMP112_CONFIG_OS_LSB        0XA0

#define TMP112_CONFIG_CM_MSB        0X60
#define TMP112_CONFIG_CM_LSB        0XA0

void tmp112_init(void);
void tmp112_end(void);
void tmp112_read_temperature(int16_t* readings, uint8_t num_readings);

#endif