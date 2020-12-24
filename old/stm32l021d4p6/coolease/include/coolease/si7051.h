#ifndef SI7051_H
#define SI7051_H

#include <stdint.h>

#define SI7051_I2C_ADDRESS          0x40

#define SI7051_CMD_MEASURE_HOLD     0xE3
#define SI7051_CMD_MEASURE_NO_HOLD  0xF3
#define SI7051_CMD_RESET            0xFE
#define SI7051_CMD_WRITE_REG        0xE6
#define SI7051_CMD_READ_REG         0xE7

#define SI7051_USER_REG_VAL         0X00

void si7051_setup_and_read_temperature(float* readings, uint8_t num_readings);
void si7051_setup_and_read_temperature2(float* readings, uint8_t num_readings);
void si7051_reset(void);

#endif