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

#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/syscfg.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>

#include "common/log.h"
#include "common/board_defs.h"
#include "common/timers.h"

/** @addtogroup BATTERY_FILE 
 * @{
 */

uint16_t batt_voltages[NUM_VOLTAGES];
bool batt_rst_seq = false;

/** @addtogroup BATTERY_INT 
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Variables
/*////////////////////////////////////////////////////////////////////////////*/

static uint16_t adc_vals[3] = {0, 0, 0};
static bool plugged_in = true;

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

void batt_init(void)
{
    // Disable Interrupts
    nvic_disable_irq(NVIC_ADC_COMP_IRQ);

    // Config Vrefint
    rcc_periph_clock_enable(RCC_SYSCFG);

    // Start/ wait for voltage reference, enable buffer to adc
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_EN_VREFINT;
    while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_VREFINT_RDYF))
    {
    }
    SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENBUF_VREFINT_ADC;

    // Enable adc clock and calibrate
    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);

    // Enable low frequency below 2.8MHz, pg.297 of ref
    uint32_t adc_freq = rcc_apb2_frequency / 4;
    if (adc_freq < 2800000)
    {
        ADC_CCR(ADC1) |= (1 << 25);
    }

    // Set clock to APB clk
    ADC_CFGR2(ADC1) |= (3 << 30);

    // Power off & calibrate
    adc_power_off(ADC1);
    adc_calibrate(ADC1);

    // Highest sampling time (239.5 for l052)
    // ADC clk 1/4 PCLK, 3 channels = 2874 cpu clk per conversion
    ADC_SMPR1(ADC1) |= 7;

    // Reverse scan direction so that VREF is always first conversion
    ADC_CFGR1(ADC1) |= ADC_CFGR1_SCANDIR;

    // Enable voltage reference
    adc_enable_vrefint();

    // Turn on ADC
    adc_power_on(ADC1);
    timers_delay_microseconds(1000);

    // Enable input pins
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);

    // Set channels to convert
    ADC_CHSELR(ADC1) |= (1 << ADC_CHANNEL_VREF);
    ADC_CHSELR(ADC1) |= (1 << 0);

#ifdef _HUB
    gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);
    ADC_CHSELR(ADC1) |= (1 << 1);
#endif
}

void batt_end(void)
{
    // Disable Interrupts
    nvic_disable_irq(NVIC_ADC_COMP_IRQ);

    adc_power_off(ADC1);
    adc_disable_vrefint();
    rcc_periph_reset_pulse(RST_ADC1);
    rcc_periph_clock_disable(RCC_ADC1);
    SYSCFG_CFGR3 &= ~SYSCFG_CFGR3_ENBUF_VREFINT_ADC;
}

void batt_set_voltage_scale(uint8_t scale)
{
    rcc_periph_clock_enable(RCC_PWR);

    // Poll VOSF bit of in PWR_CSR. Wait until it is reset to 0
    while (PWR_CSR & PWR_CSR_VOSF)
    {
    }

    // Configure the voltage scaling range by setting the VOS[1:0] bits in the PWR_CR register
    pwr_set_vos_scale(scale);

    // Poll VOSF bit of in PWR_CSR register. Wait until it is reset to 0
    while (PWR_CSR & PWR_CSR_VOSF)
    {
    }
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

void batt_calculate_voltages(void)
{
    // Calculate batt_voltages
    for (uint8_t i = 0; i < NUM_VOLTAGES; i++)
    {
        batt_voltages[i] = ((uint32_t)300 * ST_VREFINT_CAL * adc_vals[i + 1]) / (adc_vals[0] * 4095);
    }

// For Hub : Measured voltage is half of actual
#ifdef _HUB
    for (uint8_t i = 0; i < NUM_VOLTAGES; i++)
    {
        batt_voltages[i] = batt_voltages[i] * 2;
    }
#endif
}

void batt_update_voltages(void)
{
    // Start conversions
    adc_set_single_conversion_mode(ADC1);
    adc_start_conversion_regular(ADC1);
    for (uint8_t i = 0; i < NUM_VOLTAGES + 1; i++)
    {
        while (!adc_eoc(ADC1))
        {
        }
        adc_vals[i] = adc_read_regular(ADC1);
    }

    batt_calculate_voltages();
}

void batt_enable_interrupt(void)
{
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
    nvic_set_priority(NVIC_DMA1_CHANNEL1_IRQ, 0x10);

    // Start conversions
    adc_start_conversion_regular(ADC1);
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

/** @} */

/** @addtogroup BATTERY_INT
 * @{
 */

/*////////////////////////////////////////////////////////////////////////////*/
// Static Function Definitions
/*////////////////////////////////////////////////////////////////////////////*/



/** @} */

void dma1_channel1_isr(void)
{
    dma_clear_interrupt_flags(DMA1, DMA_CHANNEL1, DMA_TEIF | DMA_TCIF | DMA_HTIF | DMA_GIF);

    batt_calculate_voltages();
}

/*
// ISRs
#ifdef _HUB
// For use with ADC1
void adc_comp_isr(void)
{
    serial_printf("ADC ISR\n");
    // // Takes about 150us to run

    // // log_printf("ADC ISR %08X\n", ADC_ISR(ADC1));

    // // Calculate batt_voltages
    // for(uint8_t i = 0; i < NUM_VOLTAGES; i++){
    //     batt_voltages[i] = ( (uint32_t)300 * ST_VREFINT_CAL * adc_vals[i + 1] ) / ( adc_vals[0] * 4095 ); }

    // // For Hub : Measured voltage is half of actual
    // for(uint8_t i = 0; i < NUM_VOLTAGES; i++){
    //     batt_voltages[i] = batt_voltages[i] * 2; }

    // static uint16_t timer = 0;
    // static uint8_t state = 0;
    // switch(state)
    // {
    //     case 0:
    //         plugged_in = true;
    //         timer = timers_millis();
    //         if(batt_voltages[PWR_VOLTAGE] < batt_voltages[BATT_VOLTAGE])
    //             state = 1;
    //         break;

    //     case 1:
    //         if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE])
    //             state = 0;
    //         else if(timers_millis() - timer > 1000)
    //             state = 2;
    //         break;

    //     case 2:
    //         if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE]){
    //             timer = timers_millis();
    //             state = 4;}
    //         else if(timers_millis() - timer > 10000){
    //             state = 3;
    //             plugged_in = false;
    //             log_printf("Plugged Out\n");}
    //         break;

    //     case 3:
    //         if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE]){
    //             timer = timers_millis();
    //             state = 0;
    //             log_printf("Plugged In\n");}
    //         break;

    //     case 4:
    //         if(batt_voltages[PWR_VOLTAGE] < batt_voltages[BATT_VOLTAGE]){
    //             state = 2; }
    //         else if(timers_millis() - timer > 1000){
    //             state = 0;
    //             batt_rst_seq = true;
    //             log_printf("Reset Sequence\n"); }
    //         break;

    //     default:
    //         log_printf("Error ADC ISR Defaut Case\n");
    //         break;
    // }

    // // log_printf("ADC ISR %u %u %u V\n",state, batt_voltages[0], batt_voltages[1]);

    // ADC_ISR(ADC1) = 0xFFFFFFFF;
    // adc_start_conversion_regular(ADC1);
}

// For use with comp1
void adc_comp_isr(void)
{
    // log_printf("ADC ISR %08X\n", ADC_ISR(ADC1));

    exti_reset_request(EXTI21);

    static uint16_t timer = 0;
    static uint8_t state = 0;
    bool comp_high = COMP1_CTRL & (1 << 30);

    switch(state)
    {
        case 0:
            plugged_in = true;
            timer = timers_millis();
            if(!comp_high)
                state = 1;
            break;

        case 1:
            if(comp_high)
                state = 0;
            else if(timers_millis() - timer > 1000)
                state = 2;
            break;
        
        case 2:
            if(comp_high){
                state = 0;
                batt_rst_seq = true; 
                log_printf("Reset Sequence\n");}
            else if(timers_millis() - timer > 10000){
                plugged_in = false;
                log_printf("Plugged Out\n");}
            break;

        default:
            break;

    }

    log_printf("ADC ISR %u %u %u V\n",state, batt_voltages[0], batt_voltages[1]);

    ADC_ISR(ADC1) = 0xFFFFFFFF;
    adc_start_conversion_regular(ADC1);
}
*/

/** @} */
