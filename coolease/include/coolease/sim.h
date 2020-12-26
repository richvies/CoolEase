#ifndef SIM_H
#define SIM_H

#include <stdint.h>
#include <stdbool.h>

// Global Function Decls
void sim_init(void);
void sim_end(void);
void sim_connect(void);
// void sim_send_temp(rfm_packet_t *packet_start,  uint8_t len);
// void sim_send_temp_and_num(rfm_packet_t *packet_start,  uint8_t len);
void sim_send_data(uint8_t *data, uint8_t len);
bool check_response(char *str);

int sim_printf(const char* format, ...);
void sim_serial_pass_through(void);

#endif