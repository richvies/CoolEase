#ifndef SERIAL_PRINTF_H
#define SERIAL_PRINTF_H

#include "coolease/printf.h"

void spf_init(void);
int spf_serial_printf(const char* format, ...);

#endif