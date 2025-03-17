#include "common/timers.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/iwdg.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/lptimer.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/exti.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>

#include <libopencmsis/core_cm3.h>

#include "common/aes.h"
#include "common/battery.h"
#include "config/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/test.h"
#include "common/timers.h"

// Problems
// LPTIM counter update using lptim_irq means it must have higher priority than every other irq otherwise calls to delay_ inside an irq will hang

static uint16_t timeout_timer = 0;
static uint32_t timeout_counter = 0;
static uint32_t micros_counter = 0;
static uint32_t millis_counter = 0;

static uint32_t timers_measure_lsi_freq(void);

// Start Low Speed Oscillator and Configure RTC to wakeup device
void timers_rtc_init(void)
{
    // Check if rtc already initialized
    if (RTC_ISR & RTC_ISR_INITS)
    {
        serial_printf("RTC: Init\n");
    }
    else
    {
        log_printf("RTC: Not init\n");

        // Enable PWR clock and disable write protection
        // RCC_CSR Write protected. Must come before turning on LSI/ LSE clocks
        timers_rtc_unlock();

        // Start low speed internal oscillator ≈ 40kHz. And wait until it is ready
        rcc_osc_on(RCC_LSI);
        rcc_wait_for_osc_ready(RCC_LSI);

        // Get LSI frequency
        uint32_t lsi_freq = timers_measure_lsi_freq();
        // serial_printf("Freq: %u\n", lsi_freq);

        // Select LSI as RTC clk
        RCC_CSR &= ~(RCC_CSR_RTCSEL_MASK << RCC_CSR_RTCSEL_SHIFT);
        RCC_CSR |= (RCC_CSR_RTCSEL_LSI << RCC_CSR_RTCSEL_SHIFT);

        // Enable RTC
        RCC_CSR |= RCC_CSR_RTCEN;

        timers_delay_milliseconds(10);

        // Set RTC initialization mode
        RTC_ISR |= RTC_ISR_INIT;
        while (!((RTC_ISR) & (RTC_ISR_INITF)))
        {
        }

        // Set RTC prescaler
        rtc_set_prescaler(((lsi_freq / 4) - 1), 0x0003);
        // PRINT_REG(RTC_PRER);

        // Exit RTC initialization mode
        RTC_ISR &= ~RTC_ISR_INIT;

        // Reenable write protection
        timers_rtc_lock();

        timers_rtc_set_time(21, 6, 24, 16, 20, 00);

        log_printf(".done\n");
    }
}

void timers_rtc_set_time(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t mins, uint8_t secs)
{
    // Enable PWR clock and disable write protection
    timers_rtc_unlock();

    // Set shadow registers
    uint32_t tr = 0;
    uint32_t dr = 0;
    tr |= (((secs % 10) & RTC_TR_SU_MASK) << RTC_TR_SU_SHIFT);
    tr |= (((secs / 10) & RTC_TR_ST_MASK) << RTC_TR_ST_SHIFT);
    tr |= (((mins % 10) & RTC_TR_MNU_MASK) << RTC_TR_MNU_SHIFT);
    tr |= (((mins / 10) & RTC_TR_MNT_MASK) << RTC_TR_MNT_SHIFT);
    tr |= (((hours % 10) & RTC_TR_HU_MASK) << RTC_TR_HU_SHIFT);
    tr |= (((hours / 10) & RTC_TR_HT_MASK) << RTC_TR_HT_SHIFT);

    dr |= (((day % 10) & RTC_DR_DU_MASK) << RTC_DR_DU_SHIFT);
    dr |= (((day / 10) & RTC_DR_DT_MASK) << RTC_DR_DT_SHIFT);
    dr |= (((month % 10) & RTC_DR_MU_MASK) << RTC_DR_MU_SHIFT);
    dr |= (((month / 10) & RTC_DR_MT_MASK) << RTC_DR_MT_SHIFT);
    dr |= (((year % 10) & RTC_DR_YU_MASK) << RTC_DR_YU_SHIFT);
    dr |= (((year / 10) & RTC_DR_YT_MASK) << RTC_DR_YT_SHIFT);

    // Set RTC initialization mode
    RTC_ISR |= RTC_ISR_INIT;
    while (!((RTC_ISR) & (RTC_ISR_INITF)))
    {
    }

    RTC_TR = tr;
    RTC_DR = dr;

    // Exit RTC initialization mode
    RTC_ISR &= ~RTC_ISR_INIT;

    // PRINT_REG(RTC_TR);
    // PRINT_REG(RTC_DR);

    // Reenable write protection
    timers_rtc_lock();
}

void timers_set_wakeup_time(uint32_t wakeup_time)
{
    timers_rtc_unlock();

    // Configure & enable wakeup timer/ interrupt
    rtc_clear_wakeup_flag();
    rtc_set_wakeup_time((wakeup_time - 1), RTC_CR_WUCLKSEL_SPRE);

    timers_rtc_lock();
}

void timers_clear_wakeup_flag(void)
{
    timers_rtc_unlock();
    rtc_clear_wakeup_flag();
    timers_rtc_lock();
}

void timers_enable_wut_interrupt(void)
{
    timers_rtc_unlock();
    RTC_CR |= RTC_CR_WUTIE;
    timers_rtc_lock();

    // Enable RTC interrupt
    exti_reset_request(EXTI20);
    exti_set_trigger(EXTI20, EXTI_TRIGGER_RISING);
    exti_enable_request(EXTI20);

    nvic_clear_pending_irq(NVIC_RTC_IRQ);
    nvic_set_priority(NVIC_RTC_IRQ, IRQ_PRIORITY_RTC);
    nvic_enable_irq(NVIC_RTC_IRQ);
}

void timers_disable_wut_interrupt(void)
{
    timers_rtc_unlock();
    RTC_CR &= ~RTC_CR_WUTIE;
    timers_rtc_lock();

    // Enable RTC interrupt
    exti_reset_request(EXTI20);
    exti_disable_request(EXTI20);

    nvic_disable_irq(NVIC_RTC_IRQ);
}

void timers_rtc_unlock(void)
{
    rcc_periph_clock_enable(RCC_PWR);
    pwr_disable_backup_domain_write_protect();
    rtc_unlock();
}

void timers_rtc_lock(void)
{
    rcc_periph_clock_enable(RCC_PWR);
    pwr_enable_backup_domain_write_protect();
    rtc_lock();
}

static uint32_t timers_measure_lsi_freq(void)
{
    // TIM21 on APB2
    rcc_periph_clock_enable(RCC_TIM21);
    rcc_periph_reset_pulse(RST_TIM21);
    timer_disable_counter(TIM21);

    // Edge aligned, up counter
    TIM_CR1(TIM21) |= TIM_CR1_CMS_EDGE | TIM_CR1_DIR_UP;

    // Enable
    TIM_CR1(TIM21) |= TIM_CR1_CEN;

    // CC1 input capture mode, 8 prescale, 8 sample filter
    TIM_CCMR1(TIM21) |= TIM_CCMR1_CC1S_IN_TI1 | TIM_CCMR1_IC1PSC_8 | TIM_CCMR1_IC1F_CK_INT_N_8;

    // Select LSI capture
    TIM21_OR |= TIM21_OR_TI1_RMP_LSI;

    // Enable capture
    TIM_CCER(TIM21) |= TIM_CCER_CC1E;

    // Wait for captures
    uint32_t count = 0;
    while (!(TIM_SR(TIM21) & TIM_SR_CC1IF))
    {
    };
    uint16_t time = TIM_CCR1(TIM21);
    for (uint16_t i = 0; i < 10; i++)
    {
        while (!(TIM_SR(TIM21) & TIM_SR_CC1IF))
        {
        };
        count += (uint16_t)(TIM_CCR1(TIM21) - time);
        time = TIM_CCR1(TIM21);
    }

    // prescaler * number of samples
    count /= 80;

    uint32_t freq = rcc_apb2_frequency / count;

    // Disable TIM21
    TIM_CCER(TIM21) &= ~TIM_CCER_CC1E;
    TIM_CR1(TIM21) &= ~TIM_CR1_CEN;
    rcc_periph_reset_pulse(RST_TIM21);
    rcc_periph_clock_disable(RCC_TIM21);

    return freq;
}

void timers_lptim_init(void)
{
    // Internal clock = APB1
    rcc_set_peripheral_clk_sel(LPTIM1, RCC_CCIPR_LPTIM1SEL_APB);

    rcc_periph_clock_enable(RCC_LPTIM1);

    // Reset timer
    rcc_periph_reset_pulse(RST_LPTIM1);

    // Select internal clock as src
    lptimer_set_internal_clock_source(LPTIM1);

    // Find best prescaler for 1us clock
    uint8_t freq_mhz = rcc_apb1_frequency / 1000000;
    for (uint8_t i = 0; i < 8; i++)
    {
        if (freq_mhz <= (1 << i))
        {
            lptimer_set_prescaler(LPTIM1, (i << LPTIM_CFGR_PRESC_SHIFT));
            break;
        }
    }

    // Enable SW start triggering
    lptimer_enable_trigger(LPTIM1, LPTIM_CFGR_TRIGEN_SW);

    lptimer_enable(LPTIM1);

    // Must be done after timer enable
    lptimer_set_period(LPTIM1, 1000);
    lptimer_enable_irq(LPTIM1, LPTIM_IER_ARRMIE);

    micros_counter = 0;
    millis_counter = 0;

    // Enable lptim interrupt through exti29 - updates millis counter
    nvic_enable_irq(NVIC_LPTIM1_IRQ);
    nvic_set_priority(NVIC_LPTIM1_IRQ, IRQ_PRIORITY_LPTIM);
    exti_reset_request(EXTI29);
    exti_enable_request(EXTI29);
    exti_set_trigger(EXTI29, EXTI_TRIGGER_RISING);

    // Trigger SW start
    lptimer_start_counter(LPTIM1, LPTIM_CR_CNTSTRT);
}

void timers_lptim_end(void)
{
    exti_disable_request(EXTI29);
    nvic_disable_irq(NVIC_LPTIM1_IRQ);

    lptimer_disable(LPTIM1);

    rcc_periph_reset_pulse(RST_LPTIM1);
    rcc_periph_clock_disable(RCC_LPTIM1);
}

uint32_t timers_micros(void)
{
    return (micros_counter + LPTIM1_CNT);
}

uint32_t timers_millis(void)
{
    return millis_counter;
}

void timers_delay_microseconds(uint32_t delay_microseconds)
{
    uint32_t curr_time = timers_micros();

    while ((timers_micros() - curr_time) < delay_microseconds)
    {
    }
}

void timers_delay_milliseconds(uint32_t delay_milliseconds)
{
    uint32_t curr_time = timers_millis();

    while ((timers_millis() - curr_time) < delay_milliseconds)
    {
        // serial_printf("%u\n", timers_micros());
        // serial_printf("%u\n\n", timers_millis());
    }
}

void timers_tim6_init(void)
{
    rcc_periph_clock_enable(RCC_TIM6);
    rcc_periph_reset_pulse(RST_TIM6);
    timer_disable_counter(TIM6);

    timer_set_prescaler(TIM6, ((rcc_apb1_frequency / 1000000) - 1));
    timer_enable_counter(TIM6);
}

// Start independant watchdog timer
void timers_iwdg_init(uint32_t period)
{
    timers_rtc_unlock();

    // Start low speed internal oscillator ≈ 40kHz. And wait until it is ready
    rcc_osc_on(RCC_LSI);
    rcc_wait_for_osc_ready(RCC_LSI);

    // Turn on independant watchdog
    iwdg_reset();
    iwdg_set_period_ms(period);
    iwdg_start();
}

// Reset independant and window watchdog timers
void timers_pet_dogs(void)
{
    iwdg_reset();
}

// Enter standby mode. Vrefint disabled (ULP bit)
void timers_enter_standby(void)
{
    pwr_disable_backup_domain_write_protect();

    // Cortex deepsleep - stop & standy modes
    SCB_SCR |= SCB_SCR_SLEEPDEEP;

    // pwr_set_standby_mode();
    pwr_set_stop_mode();

    // Put regulator in low power mode & turn off Vreftint during deepsleep
    PWR_CR |= PWR_CR_LPDS | PWR_CR_ULP;

    pwr_clear_wakeup_flag();
    pwr_clear_standby_flag();

    __asm__("wfi");
}

// Timout functions
void timers_timeout_init(void)
{
    timeout_counter = 0;
    // timeout_counter     = 2140483648;
    timeout_timer = timers_micros();
}

bool timers_timeout(uint32_t time_microseconds, char *msg, uint32_t data)
{
    timeout_counter += (uint16_t)(timers_micros() - timeout_timer);
    timeout_timer = timers_micros();

    // log_printf("%u\n", timeout_counter);

    if (timeout_counter > time_microseconds)
    {
        log_printf("Timeout %s %08X\n", msg, data);
        return true;
    }
    else
        return false;
}

void lptim1_isr(void)
{
    // Clear all flags
    LPTIM1_ICR = 0xFFFFFFFF;
    micros_counter += 1000;
    millis_counter++;
}
