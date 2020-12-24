#include <stdint.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/flash.h>

#include "stm_temp.h"
#include "serial_printf.h"

#define V25         1430
#define AVG_SLOPE   4.3f

float v_sense = 0;

static void clock_setup(void);

static void adc_setup(void);

void stm_temp_read(float *readings, uint8_t num_readings)
{
    clock_setup();
    adc_setup();

    uint8_t channels[1] = {16};

    adc_set_regular_sequence(ADC1, 1, channels);

    for(int i = 0; i < num_readings; i++)
    {
        uint16_t tmp = 0;
        for(int j = 0; j < 10; j++)
        {
            adc_start_conversion_regular(ADC1);
            while (!adc_eoc(ADC1));

            tmp += adc_read_regular(ADC1);
        }
        tmp /= 10;
        
        spf_serial_printf("Reading: %04x\n", tmp);
        tmp = tmp << 4;
        tmp = tmp >> 4;
        spf_serial_printf("Signed: %04x\n", tmp);

        v_sense = (float)tmp * 3300 / 4096;
        spf_serial_printf("Voltage: %f\n", v_sense);
        
        v_sense = (( V25 - v_sense ) / AVG_SLOPE ) + 25;
        readings[i] = v_sense;
        spf_serial_printf("Temperature: %f\n\n", readings[0]);
    }

}

static void clock_setup(void)
{
	// Enable HSI Osc 8Mhz
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	// spi_chip_select HSI as SYSCLK Source
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	// Set prescalers for AHB, ADC, APB1, APB2
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);		// AHB -> 8MHz
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);	    // ADC -> 4MHz
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);		// APB1 -> 8Mhz
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);		// APB2 -> 8MHz

	// Set flash, 52MHz -> 2 waitstates
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	// spi_chip_select PLL as SYSCLK
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	// Set Peripheral Clock Frequencies used
	rcc_ahb_frequency = 8000000;
	rcc_apb1_frequency = 8000000;
	rcc_apb2_frequency = 8000000;
}

static void adc_setup(void)
{
    rcc_periph_clock_enable(RCC_ADC1);
    adc_power_off(ADC1);
    rcc_periph_reset_pulse(RST_ADC1);
    adc_disable_scan_mode(ADC1);
    adc_set_single_conversion_mode(ADC1);
    adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_41DOT5CYC);
    adc_enable_external_trigger_regular(ADC1, ADC_CR2_EXTSEL_SWSTART);
    adc_power_on(ADC1);
    adc_reset_calibration(ADC1);
    adc_calibrate(ADC1);
    adc_enable_temperature_sensor();

    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_ANALOG, GPIO0 | GPIO1);
    gpio_set_mode(GPIOB, GPIO_MODE_INPUT, GPIO_CNF_INPUT_ANALOG, GPIO0 | GPIO1);

    for(int i = 0; i < 8000; i++) __asm__("nop");
}
