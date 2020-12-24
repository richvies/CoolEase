#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

#include "coolease/battery.h"
#include "coolease/serial_printf.h"

uint8_t batt_get_voltage(void)
{
    rcc_periph_clock_enable(RCC_PWR);

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V9);
    if(pwr_voltage_high())
        return 9;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V8);
    if(pwr_voltage_high())
        return 8;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V7);
    if(pwr_voltage_high())
        return 7;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V6);
    if(pwr_voltage_high())
        return 6;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V5);
    if(pwr_voltage_high())
        return 5;
    
    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V4);
    if(pwr_voltage_high())
        return 4;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V3);
    if(pwr_voltage_high())
        return 3;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V2);
    if(pwr_voltage_high())
        return 2;

    return 255;
}

void batt_set_voltage_scale(uint8_t scale)
{
    rcc_periph_clock_enable(RCC_PWR);

    // Poll VOSF bit of in PWR_CSR. Wait until it is reset to 0
    while(PWR_CSR & PWR_CSR_VOSF);

    // Configure the voltage scaling range by setting the VOS[1:0] bits in the PWR_CR register
    pwr_set_vos_scale(scale);

    // Poll VOSF bit of in PWR_CSR register. Wait until it is reset to 0
    while(PWR_CSR & PWR_CSR_VOSF);
}

void batt_set_low_power_run(void)
{
    rcc_periph_clock_enable(RCC_PWR);

	// Set LPRUN & LPSDSR bits in PWR_CR register
	PWR_CR |= PWR_CR_LPSDSR;
	PWR_CR |= PWR_CR_LPRUN;

	// Enable MSI Osc 2.097Mhz
	rcc_osc_on(RCC_MSI);
	rcc_wait_for_osc_ready(RCC_MSI);

	// Set MSI to 65.536kHz
	rcc_set_msi_range(0);

	// Set prescalers for AHB, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);				// AHB -> 65.536kHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);			// APB1 -> 65.536kHz
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);			// APB2 -> 65.536kHz

	// Set flash, 65.536kHz -> 0 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 65536;
	rcc_apb1_frequency = 65536;
	rcc_apb2_frequency = 65536;

    rcc_periph_clock_disable(RCC_PWR);
}