#ifndef RESET_H
#define RESET_H

#include <stdint.h>

void     reset_print_cause(void);
void     reset_save_flags(void);
uint32_t reset_get_flags(void);

#endif