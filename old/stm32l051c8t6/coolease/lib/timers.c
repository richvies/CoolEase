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

#include "coolease/timers.h"
#include "coolease/serial_printf.h"


// Start Low Speed Oscillator and Configure RTC to wakeup device
void timers_rtc_init(uint32_t standby_time_seconds)
{
    // Enable PWR clock and disable write protection
    rcc_periph_clock_enable(RCC_PWR);
    pwr_disable_backup_domain_write_protect();

    // Start low speed external oscillator = 32.768kHz. And wait until it is ready
    rcc_osc_on(RCC_LSE);
    rcc_wait_for_osc_ready(RCC_LSE);

    // Enable RTC clock and select LSE
    RCC_CSR &= ~(RCC_CSR_RTCSEL_MASK << RCC_CSR_RTCSEL_SHIFT);
	RCC_CSR |= (RCC_CSR_RTCSEL_LSE << RCC_CSR_RTCSEL_SHIFT);
    RCC_CSR |= RCC_CSR_RTCEN;

    // Unlock RTC Registers
    rtc_unlock();
    
    // Set RTC initialization mode & configure prescaler
    RTC_ISR |= RTC_ISR_INIT;
    while (!((RTC_ISR) & (RTC_ISR_INITF)));

    // Set RTC prescaler
    rtc_set_prescaler(0x00FF, 0x007F);
    
    // Configure & enable wakeup timer/ interrupt
    rtc_clear_wakeup_flag();
    RTC_CR |= RTC_CR_WUTIE;
    rtc_set_wakeup_time( (standby_time_seconds - 1), RTC_CR_WUCLKSEL_SPRE);

    // Exit RTC initialization mode
    RTC_ISR &= ~RTC_ISR_INIT;

    // Reenable write protection
    pwr_enable_backup_domain_write_protect();
    rtc_lock();

    // Enable RTC interrupt
    exti_enable_request(EXTI20);
    exti_set_trigger(EXTI20, EXTI_TRIGGER_RISING);

    nvic_clear_pending_irq(NVIC_RTC_IRQ);
    nvic_enable_irq(NVIC_RTC_IRQ);
}

// Setup lptim1 as approx. microsecond counter
void timers_lptim_init(void)
{
    // Input clock is 2.097Mhz
    rcc_set_peripheral_clk_sel(LPTIM1, RCC_CCIPR_LPTIM1SEL_APB);
 
    rcc_periph_clock_enable(RCC_LPTIM1);
    
    lptimer_set_internal_clock_source(LPTIM1);
    lptimer_enable_trigger(LPTIM1, LPTIM_CFGR_TRIGEN_SW);
    lptimer_set_prescaler(LPTIM1, LPTIM_CFGR_PRESC_2);
    
    lptimer_enable(LPTIM1);
    
    lptimer_set_period(LPTIM1, 0xffff);
    
    lptimer_start_counter(LPTIM1, LPTIM_CR_CNTSTRT);
}

void timers_iwdg_init(uint32_t period)
{
    // Turn on independant watchdog. 5 second time out
    iwdg_reset();
    iwdg_set_period_ms(period);
    iwdg_start();
}

// Reset independant and window watchdog timers
void timers_pet_dogs(void)
{
    iwdg_reset();
}

// Enter standby mode
void timers_enter_standby(void)
{
    pwr_disable_backup_domain_write_protect();

    SCB_SCR |= SCB_SCR_SLEEPDEEP;

    pwr_set_standby_mode();
    // pwr_set_stop_mode();
    // PWR_CR &= PWR_CR_LPDS;

    pwr_clear_wakeup_flag();

    pwr_clear_standby_flag();

    // Enter standby
    while(1)
    {
        cm_disable_interrupts();
        __WFI();
        cm_enable_interrupts();
    }
}

// Simple delay function. Puts cpu into nop loop timed by lptim1
void timers_delay_microseconds(uint32_t delay_microseconds)
{
    uint32_t curr_time = lptimer_get_counter(LPTIM1);

    // Limit delay to 16 bit max. Otherwise delay might never end
    if(delay_microseconds > 65535)
        delay_microseconds = 65535;

    while (lptimer_get_counter(LPTIM1) - curr_time < delay_microseconds);
}

// Simple delay function. Puts cpu into nop loop timed by lptim1
void timers_delay_milliseconds(uint32_t delay_milliseconds)
{
    uint32_t curr_time = lptimer_get_counter(LPTIM1);

    while(delay_milliseconds > 0)
    {
        while (lptimer_get_counter(LPTIM1) - curr_time < 1000);

        curr_time = lptimer_get_counter(LPTIM1);

        delay_milliseconds--;
    }
}

// Override default rtc interrupt handler
void rtc_isr(void)
{  
    if(RTC_ISR & RTC_ISR_WUTF)
    { 
        pwr_disable_backup_domain_write_protect();
        rtc_unlock();
	    rtc_clear_wakeup_flag();
        rtc_lock();
	    pwr_enable_backup_domain_write_protect();
    }

    exti_reset_request(EXTI20);
}