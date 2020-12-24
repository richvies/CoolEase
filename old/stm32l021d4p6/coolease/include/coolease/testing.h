#ifndef TESTING_H
#define TESTING_H

void testing_wakeup(void);
void testing_standby(uint32_t standby_time);
void testing_tmp112a(uint8_t num_readings);
void testing_rf(void);
void testing_rf_listen(void);
void testing_sensor(void);
void testing_receiver(void);
void testing_hub(void);
void testing_voltage_scale(uint8_t scale);
void testing_low_power_run(void);
void testing_eeprom(void);
void testing_lptim(void);
void testing_sdr(void);
void testing_sim800(void);

#endif