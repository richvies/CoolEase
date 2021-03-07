#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>

#include "common/board_defs.h"
#include "common/timers.h"

#include <stdint.h>
#include <stddef.h>

shared_info_t *shared_info = ((shared_info_t *)(EEPROM_SHARED_INFO_BASE));
boot_info_t *boot_info = ((boot_info_t *)(EEPROM_BOOT_INFO_BASE));
app_info_t *app_info = ((app_info_t *)(EEPROM_APP_INFO_BASE));
log_t *log_file = ((log_t *)(EEPROM_LOG_BASE));

enum rcc_osc sys_clk = RCC_MSI;

void clock_setup_msi_2mhz(void) 
{
	// Enable MSI Osc 2.097Mhz
	rcc_osc_on(RCC_MSI);
	rcc_wait_for_osc_ready(RCC_MSI);

	// Set MSI to 2.097Mhz
	rcc_set_msi_range(5);

	// Select as system clock
	rcc_set_sysclk_source(RCC_MSI);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 2.097Mhz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 2.097Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 2.097Mhz

	// Set flash, 2.097Mhz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 2097000;
	rcc_apb1_frequency = 2097000;
	rcc_apb2_frequency = 2097000;

	rcc_osc_off(RCC_HSI16);

	sys_clk = RCC_MSI;
}

void clock_setup_hsi_16mhz(void) 
{
	// Enable MSI Osc 16MHz
	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);

	// Select as system clock
	rcc_set_sysclk_source(RCC_HSI16);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 16MHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 16MHz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 16MHz

	// Set flash, 16MHz -> 0 waitstates, voltgae scale must be range 1 (1.8v)
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 16000000;
	rcc_apb1_frequency = 16000000;
	rcc_apb2_frequency = 16000000;

	rcc_osc_off(RCC_MSI);

	sys_clk = RCC_HSI16;
}

void flash_led(uint16_t milliseconds, uint8_t num_flashes)
{
	rcc_periph_clock_enable(RCC_GPIOA);

	gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED);
	gpio_clear(LED_PORT, LED);
	for (uint8_t i = 0; i < num_flashes; i++)
	{
		gpio_set(LED_PORT, LED);
		timers_delay_milliseconds(milliseconds / 4);
		gpio_clear(LED_PORT, LED);
		timers_delay_milliseconds(3 * milliseconds / 4);
	}
}

void __attribute__((weak)) serial_printf(const char *format, ...)
{
	(void)format;
}

bool __attribute__((weak)) serial_available(void)
{
	return false;
}

char __attribute__((weak)) serial_read(void)
{
	return 0;
}