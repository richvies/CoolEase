#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef _HUB
#define NUM_VOLTAGES    2
#define PWR_VOLTAGE     0
#define BATT_VOLTAGE    1
#else
#define NUM_VOLTAGES    1
#define BATT_VOLTAGE    0
#endif

extern uint16_t batt_voltages[NUM_VOLTAGES];

extern bool batt_rst_seq;

void batt_init(void);
void batt_set_voltage_scale(uint8_t scale);
void batt_set_low_power_run(void);
void batt_update_voltages(void);
void batt_enable_interrupt(void);
void batt_enable_comp(void);

#endif