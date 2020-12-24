#ifndef SIM800_H
#define SIM800_H

/**
 * Global Function Decls
 */ 

void sim800_init(void);
void sim800_end(void);
int sim800_printf(const char* format, ...);
void sim800_send_temp(int16_t temp);

void sim800_reset_hold(void);
void sim800_reset_release(void);

#endif