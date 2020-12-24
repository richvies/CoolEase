#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include "coolease/battery.h"

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
