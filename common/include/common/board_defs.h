#ifndef BOARD_DEFS_H
#define BOARD_DEFS_H

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>



#ifdef _HUB
#include "hub/board_defs.h"
#else
#include "sensor/board_defs.h"
#endif

void clock_setup_msi_2mhz(void);

#endif