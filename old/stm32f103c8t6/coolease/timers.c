
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/iwdg.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/f1/bkp.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/cortex.h>

#include <libopencmsis/core_cm3.h>

#include "coolease/timers.h"
#include "coolease/cc1101.h"
#include "coolease/serial_printf.h"

static void timers_enter_standby(uint32_t standby_time_seconds);


// Start Low Speed Oscillator and Configure RTC, IWDG & WWDG Registers
void timers_rtc_init(void)
{
    // Start low speed internal oscillator ≈ 40kHz. And wait until it is ready
    rcc_osc_on(RCC_LSI);
    rcc_wait_for_osc_ready(RCC_LSI);

    // Turn on rtc and configure to use low speed interal oscillator
    rtc_awake_from_off(RCC_LSI); 

    // Set prescale to 40,000 -> tick about once per second
    rtc_enter_config_mode();
    RTC_PRLL = 0x9C40;
    rtc_exit_config_mode();

    spf_serial_printf("RTC Set\n");
}

void timers_iwdg_init(void)
{
    // Turn on independant watchdog. 5 second time out. 
    iwdg_reset();
    iwdg_set_period_ms(5000);
    iwdg_start();
    spf_serial_printf("Watchdog Set\n");
}

// Reset independant and window watchdog timers
void timers_pet_dogs(void)
{
    iwdg_reset();
}

// Sets up RTC to wake device after number of seconds
// Standby initiated by timers_standby_check() after intentional watchdog reset
// This prevents watchdog from waking device while in standby
void timers_prepare_and_enter_standby(uint32_t standby_time_seconds)
{
    rcc_periph_clock_enable(RCC_BKP);
    pwr_disable_backup_domain_write_protect();
    BKP_DR1 = 0x1;
    BKP_DR2 = standby_time_seconds;
    pwr_enable_backup_domain_write_protect();
    while(1);
}

// Run just after reset and possibly calls timers_enter_standby()
void timers_standby_check(void)
{
    rcc_periph_clock_enable(RCC_BKP);
    if(BKP_DR1)
    {
        spf_serial_printf("Standby Check %i\n", BKP_DR2);
        timers_enter_standby(BKP_DR2); 
    } 
    spf_serial_printf("Standby Check Fail\n"); 
}

// Enter standby mode for number of seconds
// Called by timers_standby_check() after device reset by timers_prepare_and_enter_standby()
static void timers_enter_standby(uint32_t standby_time_seconds)
{
    cc1101_init();
    cc1101_end();

    rcc_periph_clock_enable(RCC_PWR);
    rcc_periph_clock_enable(RCC_BKP);

    // Start low speed internal oscillator ≈ 40kHz. And wait until it is ready
    rcc_osc_on(RCC_LSI);
    rcc_wait_for_osc_ready(RCC_LSI);

    // Turn on rtc and configure to use low speed interal oscillator
    rtc_awake_from_off(RCC_LSI); 

    // Set prescale to 40,000 -> tick about once per second
    rtc_enter_config_mode();
    RTC_PRLL = 0x9C40;
    RTC_ALRH = (uint16_t)(standby_time_seconds >> 16);
    RTC_ALRL = (uint16_t)(standby_time_seconds);
    rtc_exit_config_mode();

    // Set sleepdeep bit in cortex system control register
    SCB_SCR |= SCB_SCR_SLEEPDEEP;

    // Set to standby mode 
    pwr_set_standby_mode();

    // Clear Wakeup flag
    pwr_clear_wakeup_flag();

    pwr_clear_standby_flag();

    // Enable rtc alarm
    rtc_enable_alarm();

    // Enter standby
    while(1)
    {
        cm_disable_interrupts();
        pwr_disable_backup_domain_write_protect();
        BKP_DR1 = 0x0;
        __WFI();
        cm_enable_interrupts();
    }
}

// Simple delay function. Puts cpu into nop loop timed by rtc 
void timers_delay(uint32_t delay_seconds)
{
    uint32_t curr_time = rtc_get_counter_val();
	while (rtc_get_counter_val() - curr_time < delay_seconds)
		__asm__("nop");
}


void timers_tim2_init(void)
{
    rcc_periph_clock_enable(RCC_TIM2);
    timer_disable_counter(TIM2);
    timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
    timer_set_prescaler(TIM2, 100);
    timer_enable_update_event(TIM2);
    timer_enable_counter(TIM2);
}

// Override default rtc interrupt handler
void rtc_isr (void)
{
    // Check which flag caused interrupt
    if(rtc_check_flag(RTC_SEC))
    {
        rtc_clear_flag(RTC_SEC);
    }
}
