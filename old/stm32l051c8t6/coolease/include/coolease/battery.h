#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

uint8_t batt_get_voltage(void);
void batt_set_voltage_scale(uint8_t scale);
void batt_set_low_power_run(void);

#endif