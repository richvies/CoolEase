#ifndef BATTERY_H
#define BATTERY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "common/log.h"
#include "common/memory.h"

#ifdef __cplusplus
extern "C" {
#endif

void batt_init(void) {
}
void batt_end(void) {
}

void batt_set_voltage_scale(uint8_t scale) {
    (void)scale;
}
void batt_set_low_power_run(void) {
}
void batt_calculate_voltages(void) {
}
void batt_update_voltages(void) {
}
void batt_enable_interrupt(void) {
}
void batt_disable_interrupt(void) {
}

bool batt_is_plugged_in(void) {
    return true;
}
bool batt_is_ready(void) {
    return true;
}

uint16_t batt_get_batt_voltage(void) {
    return 3000;
}
uint16_t batt_get_pwr_voltage(void) {
    return 3000;
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif // BATTERY_H