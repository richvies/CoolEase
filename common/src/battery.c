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

uint16_t    batt_voltages[NUM_VOLTAGES];
bool        batt_rst_seq = false;

static uint16_t adc_vals[3] = {0,0,0};
static bool     plugged_in  = true;


void batt_init(void)
{
    rcc_periph_clock_enable(RCC_PWR);
    rcc_periph_clock_enable(RCC_SYSCFG);

    // Wait for voltage reference to start
    while(!( PWR_CSR & PWR_CSR_VREFINTRDYF ));

    // Enable Ultra Low Power for VFREFINT
    // PWR_CR |= PWR_CR_ULP;
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

void batt_update_voltages(void)
{   
    // Enable clock and calibrate
    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);

    // Set clock to APB clk
    ADC_CFGR2(ADC1) |= (3 << 30);
    
    adc_power_off(ADC1);
    adc_calibrate(ADC1);
    
    // Set ADC Params
    adc_set_single_conversion_mode(ADC1);
    ADC_SMPR1(ADC1) &= ~7; ADC_SMPR1(ADC1) |= ADC_SMPR_SMP_160DOT5CYC;

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

    // Disable Interrupts
    nvic_enable_irq(NVIC_ADC_COMP_IRQ);
    nvic_set_priority(NVIC_ADC_COMP_IRQ, 0);

    // Start conversions
    adc_start_conversion_regular(ADC1);
    for(uint8_t i = 0; i < NUM_VOLTAGES + 1; i++)
    {
        while ( !adc_eoc(ADC1) );
        adc_vals[i] = adc_read_regular(ADC1);
    }
    
    // Calculate batt_voltages
    for(uint8_t i = 0; i < NUM_VOLTAGES; i++)
    {
        batt_voltages[i] = ( (uint32_t)300 * ST_VREFINT_CAL * adc_vals[i + 1] ) / ( adc_vals[0] * 4095 );
    }

    // For Hub : Measured voltage is half of actual
    #ifdef _HUB
    for(uint8_t i = 0; i < NUM_VOLTAGES; i++)
    {
        batt_voltages[i] = batt_voltages[i] * 2;
    }
    #endif
    

    // Power down
    adc_disable_vrefint();
    adc_power_off(ADC1);
    rcc_periph_clock_disable(RCC_ADC1);
}

void batt_enable_interrupt(void)
{
    // Enable clock and reset
    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);

    // Set clock to APB clk / 4
    ADC_CFGR2(ADC1) |= (2 << 30);
    
    // Power off and calibrate
    adc_power_off(ADC1);
    adc_calibrate(ADC1);

    // Config ADC
    adc_set_single_conversion_mode(ADC1);
    ADC_SMPR1(ADC1) &= ~7; ADC_SMPR1(ADC1) |= ADC_SMPR_SMP_160DOT5CYC;
    ADC_IER(ADC1) = ADC_IER_EOSIE;
    adc_enable_dma(ADC1);

    // Reverse scan direction so that VREF is always first conversion
    ADC_CFGR1(ADC1) |= ADC_CFGR1_SCANDIR;

    // Enable voltage reference
    adc_enable_vrefint();

    /*
    // Interrupt if voltage below 4.7V (2.35 on pin)
    uint16_t vrefint_low    = (300 * ST_VREFINT_CAL) / 600;
    uint16_t vrefint_high   = (300 * ST_VREFINT_CAL) / 235;
    log_printf(MAIN, "Thresh %i %i\n", vrefint_low, vrefint_high);
    ADC_TR1(ADC1)           = (vrefint_high << 16) + vrefint_low; 
    // Configure ADC
    ADC_CFGR1(ADC1)  |= (1<<26) | ADC_CFGR1_AWD1EN | ADC_CFGR1_AWD1SGL;
    ADC_IER(ADC1) |= ADC_IER_AWD1IE;
    */

    // Enable inputs
    rcc_periph_clock_enable(RCC_GPIOA); 
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);

    // Set channels to convert
    ADC_CHSELR(ADC1) |= (1 << ADC_CHANNEL_VREF);
    ADC_CHSELR(ADC1) |= (1 << 0);
    
    // Extra pwr channel for hub
    #ifdef _HUB
    gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);
    ADC_CHSELR(ADC1) |= (1 << 1);
    #endif

    // Setup DMA
    rcc_periph_clock_enable(RCC_DMA);
    dma_channel_reset(DMA1, 1);

    dma_enable_circular_mode(DMA1, 1);
    dma_set_read_from_peripheral(DMA1, 1);
    dma_set_number_of_data(DMA1, 1, 3);
    dma_set_priority(DMA1, 1, DMA_CCR_PL_VERY_HIGH);

    dma_set_peripheral_address(DMA1, 1, (uint32_t)&ADC_DR(ADC1));
    dma_set_peripheral_size(DMA1, 1, DMA_CCR_PSIZE_32BIT);
    dma_disable_peripheral_increment_mode(DMA1, 1);

    dma_set_memory_address(DMA1, 1, (uint32_t)adc_vals);
    dma_set_memory_size(DMA1, 1, DMA_CCR_MSIZE_16BIT);
    dma_enable_memory_increment_mode(DMA1, 1);

    dma_enable_channel(DMA1, 1);

    // Turn on ADC
    adc_power_on(ADC1);
    timers_delay_microseconds(1000);

    // Enable interrupt. Low priority
    nvic_enable_irq(NVIC_ADC_COMP_IRQ);
    nvic_set_priority(NVIC_ADC_COMP_IRQ, 0xFF);

    // Start conversions
    adc_start_conversion_regular(ADC1);
}

void batt_enable_comp(void)
{
    // Batt on PA0 -input, PWR on PA1 +input
    // Ok when PWR > BATT, Comp 1 positive

    // Enable clock and calibrate
    // rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_clock_enable(RCC_SYSCFG);

    // rcc_periph_reset_pulse(RST_ADC1);

    // Enable inputs
    rcc_periph_clock_enable(RCC_GPIOA); 
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);

    #ifdef _HUB
    gpio_mode_setup(PWR_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PWR_SENS);
    #endif

    // Config COMP1
    COMP1_CTRL = 0x00000000;
    COMP1_CTRL = 0x00000010;
    COMP1_CTRL = 0x00000011;

    // Enable interrupt
    exti_reset_request(EXTI21);
	exti_set_trigger(EXTI21, EXTI_TRIGGER_BOTH);
	exti_enable_request(EXTI21);

    nvic_enable_irq(NVIC_ADC_COMP_IRQ);
    nvic_set_priority(NVIC_ADC_COMP_IRQ, 0);
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

// ISRs
#ifdef _HUB
// For use with ADC1
void adc_comp_isr(void)
{
    // Takes about 150us to run

    // log_printf(MAIN, "ADC ISR %08X\n", ADC_ISR(ADC1));

    // Calculate batt_voltages
    for(uint8_t i = 0; i < NUM_VOLTAGES; i++){
        batt_voltages[i] = ( (uint32_t)300 * ST_VREFINT_CAL * adc_vals[i + 1] ) / ( adc_vals[0] * 4095 ); }

    // For Hub : Measured voltage is half of actual
    for(uint8_t i = 0; i < NUM_VOLTAGES; i++){
        batt_voltages[i] = batt_voltages[i] * 2; }

    static uint16_t timer = 0;
    static uint8_t state = 0;
    switch(state)
    {
        case 0:
            plugged_in = true;
            timer = timers_millis();
            if(batt_voltages[PWR_VOLTAGE] < batt_voltages[BATT_VOLTAGE])
                state = 1;
            break;

        case 1:
            if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE])
                state = 0;
            else if(timers_millis() - timer > 1000)
                state = 2;
            break;
        
        case 2:
            if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE]){
                timer = timers_millis(); 
                state = 4;}
            else if(timers_millis() - timer > 10000){
                state = 3;
                plugged_in = false;
                log_printf(MAIN, "Plugged Out\n");}
            break;
        
        case 3:
            if(batt_voltages[PWR_VOLTAGE] > batt_voltages[BATT_VOLTAGE]){
                timer = timers_millis();
                state = 0;
                log_printf(MAIN, "Plugged In\n");}
            break;

        case 4:
            if(batt_voltages[PWR_VOLTAGE] < batt_voltages[BATT_VOLTAGE]){
                state = 2; }
            else if(timers_millis() - timer > 1000){
                state = 0;
                batt_rst_seq = true; 
                log_printf(MAIN, "Reset Sequence\n"); }
            break;

        default:
            log_printf(MAIN, "Error ADC ISR Defaut Case\n");
            break;
    }

    // log_printf(MAIN, "ADC ISR %u %u %u V\n",state, batt_voltages[0], batt_voltages[1]);

    ADC_ISR(ADC1) = 0xFFFFFFFF;
    adc_start_conversion_regular(ADC1);
}

/*
// For use with comp1
void adc_comp_isr(void)
{
    // log_printf(MAIN, "ADC ISR %08X\n", ADC_ISR(ADC1));

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
                log_printf(MAIN, "Reset Sequence\n");}
            else if(timers_millis() - timer > 10000){
                plugged_in = false;
                log_printf(MAIN, "Plugged Out\n");}
            break;

        default:
            break;

    }

    log_printf(MAIN, "ADC ISR %u %u %u V\n",state, batt_voltages[0], batt_voltages[1]);

    ADC_ISR(ADC1) = 0xFFFFFFFF;
    adc_start_conversion_regular(ADC1);
}
*/

#endif