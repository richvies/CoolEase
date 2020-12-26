#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>
#include <stdbool.h>

#define DEV_NUM_CHIP		(uint32_t)0x0000001B
#define DEV_NUM_PCB		    (uint32_t)~DEV_NUM_CHIP

void flash_led(uint16_t milliseconds, uint8_t num_flashes);
void testing_wakeup(void);
void testing_standby(uint32_t standby_time);
void testing_tmp112a(uint8_t num_readings);
void testing_rf(void);
void testing_rf_listen(void);
void testing_sensor(uint32_t dev_num);
void testing_receiver(uint32_t dev_num);
void testing_hub(void);
void testing_voltage_scale(uint8_t scale);
void testing_low_power_run(void);
void testing_eeprom(void);
void testing_eeprom_keys(void);
void testing_eeprom_wipe(void);
void testing_lptim(void);
void testing_si7051(uint8_t num_readings);
void testing_tmp112(uint8_t num_readings);
void testing_rfm(void);
void testing_reset_eeprom(void);
void testing_encryption(void);
void testing_sim(void);
void testing_sim_serial_pass_through(void);
bool testing_timeout(void);
void testing_log(void);
void testing_analog_watchdog(void);

#endif