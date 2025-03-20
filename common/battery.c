/**
 ******************************************************************************
 * @file    battery.c
 * @author  Richard Davies
 * @date    20/Jan/2021
 * @brief   Battery Source File
 *
 ******************************************************************************
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Includes
/*////////////////////////////////////////////////////////////////////////////*/

#include "common/battery.h"

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>

#include "common/log.h"
#include "common/timers.h"
#include "config/board_defs.h"

#ifdef COOLEASE_DEVICE_HUB
#define NUM_VOLTAGES 2
#define PWR_VOLTAGE  0
#define BATT_VOLTAGE 1
#else
#define NUM_VOLTAGES 1
#define BATT_VOLTAGE 0
#endif

#define ADC_CCR_LFMEN (1 << 25)

#define ADC_CCR_PRESC_SHIFT  18
#define ADC_CCR_PRESC        (0xF << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_NODIV  (0 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV2   (1 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV4   (2 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV6   (3 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV8   (4 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV10  (5 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV12  (6 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV16  (7 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV32  (8 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV64  (9 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV128 (10 << ADC_CCR_PRESC_SHIFT)
#define ADC_CCR_PRESC_DIV256 (11 << ADC_CCR_PRESC_SHIFT)

#define ADC_CR_ADVREGEN (1 << 28)

#define BATT_LAG_MS 10000

typedef enum {
    BATT_INIT = 0,
    BATT_PLUGGED_IN,
    BATT_PLUGGED_OUT,
} batt_state_t;

/** @addtogroup BATTERY_FILE
 * @{
 */

/** @addtogroup BATTERY_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static uint16_t     adc_vals[3] = {0, 0, 0};
static uint16_t     batt_voltages[NUM_VOLTAGES];
static batt_state_t state = BATT_INIT;

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Declarations
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */

/** @addtogroup BATTERY_API
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Exported Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

void batt_init(void) {
    // Disable Interrupt
    nvic_disable_irq(NVIC_DMA1_CHANNEL1_IRQ);

    // Config Vrefint
    rcc_periph_clock_enable(RCC_SYSCFG);

    // Start/ wait for voltage reference, enable buffer to adc
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_EN_VREFINT;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_VREFINT_RDYF)) {
    }
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENBUF_VREFINT_ADC;

    // Enable adc clock and calibrate
    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);

    // Clock config
    uint32_t adc_freq;
    if (sys_clk == RCC_HSI16) {
        // Set clock to HSI clk
        ADC_CFGR2(ADC1) &= ~ADC_CFGR2_CKMODE;

        // Set prescaler 32
        ADC_CCR(ADC1) &= ~ADC_CCR_PRESC;
        ADC_CCR(ADC1) |= ADC_CCR_PRESC_DIV32;

        adc_freq = 16000000 / 32;
    } else {
        // Set clock to APB clk / 4
        ADC_CFGR2(ADC1) &= ~ADC_CFGR2_CKMODE;
        ADC_CFGR2(ADC1) |= ADC_CFGR2_CKMODE_PCLK_DIV4;
        adc_freq = rcc_apb2_frequency / 4;
    }

    // Enable low frequency below 2.8MHz, pg.297 of ref
    if (adc_freq < 2800000) {
        ADC_CCR(ADC1) |= ADC_CCR_LFMEN;
    } else {
        ADC_CCR(ADC1) &= ~ADC_CCR_LFMEN;
    }

    // Power off & calibrate
    adc_power_off(ADC1);
    adc_calibrate(ADC1);

    // Highest sampling time. 160.5 for l051 (239.5 for l052)
    ADC_SMPR1(ADC1) |= ADC_SMPR_SMP_160DOT5CYC;

    // Reverse scan direction so that VREF is always first conversion
    ADC_CFGR1(ADC1) |= ADC_CFGR1_SCANDIR;

    // Enable voltage reference
    adc_enable_vrefint();

    // Turn on ADC
    adc_power_on(ADC1);
    timers_delay_microseconds(1000);

    // Enable analog pins
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,
                    BATT_SENS);

    // Set channels to convert
    ADC_CHSELR(ADC1) |= (1 << ADC_CHANNEL_VREF);
    ADC_CHSELR(ADC1) |= (1 << 0);

#ifdef COOLEASE_DEVICE_HUB
    gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);
    ADC_CHSELR(ADC1) |= (1 << 1);
#endif

    log_printf("Batt Init\n");
}

void batt_end(void) {
    // Disable Interrupts
    nvic_disable_irq(NVIC_DMA1_CHANNEL1_IRQ);

    adc_power_off(ADC1);
    adc_disable_vrefint();

    // Turn off ADC Regulator
    ADC_CR(ADC1) &= ~ADC_CR_ADVREGEN;

    rcc_periph_reset_pulse(RST_ADC1);
    rcc_periph_clock_disable(RCC_ADC1);

    // Disable VRef Buffer
    SYSCFG_CFGR3 &= ~SYSCFG_CFGR3_ENBUF_VREFINT_ADC;
}

void batt_set_voltage_scale(uint8_t scale) {
    rcc_periph_clock_enable(RCC_PWR);

    // Poll VOSF bit of in PWR_CSR
    while (PWR_CSR & PWR_CSR_VOSF) {
    }

    // Configure the voltage scaling range by setting the VOS[1:0] bits in the
    // PWR_CR register
    pwr_set_vos_scale(scale);

    // Poll VOSF bit of in PWR_CSR register
    while (PWR_CSR & PWR_CSR_VOSF) {
    }
}

void batt_set_low_power_run(void) {
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
    rcc_set_hpre(RCC_CFGR_HPRE_NODIV);   // AHB -> 65.536kHz
    rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV); // APB1 -> 65.536kHz
    rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV); // APB2 -> 65.536kHz

    // Set flash, 65.536kHz -> 0 waitstates
    flash_set_ws(FLASH_ACR_LATENCY_0WS);

    // Set Peripheral Clock Frequencies used
    rcc_ahb_frequency = 65536;
    rcc_apb1_frequency = 65536;
    rcc_apb2_frequency = 65536;

    rcc_periph_clock_disable(RCC_PWR);
}

void batt_calculate_voltages(void) {
    // Calculate batt_voltages
    for (uint8_t i = 0; i < NUM_VOLTAGES; i++) {
        batt_voltages[i] = ((uint32_t)300 * ST_VREFINT_CAL * adc_vals[i + 1]) /
                           (adc_vals[0] * 4095);
    }

// For Hub : Measured voltage is half of actual
#ifdef COOLEASE_DEVICE_HUB
    for (uint8_t i = 0; i < NUM_VOLTAGES; i++) {
        batt_voltages[i] = batt_voltages[i] * 2;
    }
#endif
}

void batt_update_voltages(void) {
    static uint32_t timer;
    timer = timers_millis();

    ADC_CR(ADC1) |= ADC_CR_ADSTP;
    while (!(ADC_CR(ADC1) & ADC_CR_ADSTP)) {
        if (timers_millis() - timer > 2000) {
            log_printf("ERR: ADC Stop Timeout\n");
            return;
        }
    }
    adc_set_single_conversion_mode(ADC1);

    // Start conversions
    adc_start_conversion_regular(ADC1);
    for (uint8_t i = 0; i < NUM_VOLTAGES + 1; i++) {
        while (!adc_eoc(ADC1)) {
            if (timers_millis() - timer > 5000) {
                log_printf("ERR: ADC Conv Timeout\n");
                return;
            }
        }
        adc_vals[i] = adc_read_regular(ADC1);
    }

    batt_calculate_voltages();
}

void batt_enable_interrupt(void) {
    ADC_CR(ADC1) |= ADC_CR_ADSTP;
    while (!(ADC_CR(ADC1) & ADC_CR_ADSTP)) {
    }
    adc_set_continuous_conversion_mode(ADC1);

    adc_enable_dma(ADC1);
    adc_enable_dma_circular_mode(ADC1);

    // Setup DMA
    rcc_periph_clock_enable(RCC_DMA);
    dma_channel_reset(DMA1, 1);

    dma_enable_circular_mode(DMA1, 1);

    dma_set_read_from_peripheral(DMA1, 1);
    dma_set_number_of_data(DMA1, 1, NUM_VOLTAGES + 1);
    dma_set_priority(DMA1, 1, DMA_CCR_PL_VERY_HIGH);

    dma_set_peripheral_address(DMA1, 1, (uint32_t)&ADC_DR(ADC1));
    dma_set_peripheral_size(DMA1, 1, DMA_CCR_PSIZE_32BIT);
    dma_disable_peripheral_increment_mode(DMA1, 1);

    dma_set_memory_address(DMA1, 1, (uint32_t)adc_vals);
    dma_set_memory_size(DMA1, 1, DMA_CCR_MSIZE_16BIT);
    dma_enable_memory_increment_mode(DMA1, 1);

    dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL1);

    dma_enable_channel(DMA1, 1);

    // Enable interrupt. Low priority
    nvic_enable_irq(NVIC_DMA1_CHANNEL1_IRQ);
    nvic_set_priority(NVIC_DMA1_CHANNEL1_IRQ, IRQ_PRIORITY_BATT);

    // Start conversions
    adc_start_conversion_regular(ADC1);
}

void batt_disable_interrupt(void) {
    adc_disable_dma(ADC1);
    adc_disable_dma_circular_mode(ADC1);

    dma_channel_reset(DMA1, DMA_CHANNEL1);

    nvic_disable_irq(NVIC_DMA1_CHANNEL1_IRQ);
}

uint16_t batt_get_batt_voltage(void) {
    return batt_voltages[BATT_VOLTAGE];
}

uint16_t batt_get_pwr_voltage(void) {
#ifdef COOLEASE_DEVICE_HUB
    return batt_voltages[PWR_VOLTAGE];
#else
    return 0;
#endif
}

/*
uint8_t batt_get_voltage(void)
{
    uint8_t voltage = 137;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V2);
    if(pwr_voltage_high())
        voltage = 2;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V3);
    if(pwr_voltage_high())
        voltage = 3;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V4);
    if(pwr_voltage_high())
        voltage = 4;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V5);
    if(pwr_voltage_high())
        voltage = 5;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V6);
    if(pwr_voltage_high())
        voltage = 6;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V7);
    if(pwr_voltage_high())
        voltage = 7;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V8);
    if(pwr_voltage_high())
        voltage = 8;

    pwr_enable_power_voltage_detect(PWR_CR_PLS_2V9);
    if(pwr_voltage_high())
        voltage = 9;



    pwr_disable_power_voltage_detect();

    return voltage;
}
*/

bool batt_is_plugged_in(void) {
    // return (state == BATT_PLUGGED_IN);
    return true;
}

bool batt_is_ready(void) {
    // return (state != BATT_INIT);
    return true;
}
/** @} */

/** @addtogroup BATTERY_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/

/** @} */

void dma1_channel1_isr(void) {
    static uint32_t     timer = 0;
    static batt_state_t last_state = BATT_INIT;
    static batt_state_t curr_state = BATT_INIT;

    dma_clear_interrupt_flags(DMA1, DMA_CHANNEL1,
                              DMA_TEIF | DMA_TCIF | DMA_HTIF | DMA_GIF);

    batt_calculate_voltages();

    curr_state = (batt_get_pwr_voltage() >= batt_get_batt_voltage())
                     ? BATT_PLUGGED_IN
                     : BATT_PLUGGED_OUT;

    // if state changed since last check
    if (curr_state != last_state) {
        timer = timers_millis();
    } else {
        // update state after lag
        if ((state != curr_state) && (timers_millis() - timer > BATT_LAG_MS)) {
            state = curr_state;
        }
    }

    last_state = curr_state;
}

/** @} */
