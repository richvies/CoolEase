#ifndef BOARD_DEFS_H
#define BOARD_DEFS_H

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>

#include "common/log.h"

extern enum rcc_osc sys_clk;

#define PRINT_REG(reg) serial_printf("%s : %8x\n",#reg, reg);

#define INIT_KEY 0xABC3F982

#define PRINT_OK() serial_printf("OK\n")

typedef struct
{
	uint8_t aes_key[16];
	uint32_t dev_num;
	uint32_t init_key;
	uint32_t app_version;
	uint32_t boot_version;
	char 	 pwd[33];
} dev_info_t;


#ifdef _HUB
#include "hub/board_defs.h"
#else
#include "sensor/board_defs.h"
#endif

void clock_setup_msi_2mhz(void);
void clock_setup_hsi_16mhz(void);
void set_gpio_for_standby(void);

#endif