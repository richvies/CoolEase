#ifndef SIM800_H
#define SIM800_H

/**
 * Global Function Decls
 */ 

void sim800_init(void);
void sim800_serial_pass_through(void);

void sim800_reset_hold(void);
void sim800_reset_release(void);

#endif