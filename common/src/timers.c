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
#include "common/board_defs.h"
#include "common/aes.h"
#include "common/reset.h"
#include "common/rf_scan.h"
#include "common/rfm.h"
#include "common/log.h"
#include "common/test.h"
#include "common/timers.h"

static uint16_t timeout_timer = 0;
static uint32_t timeout_counter  = 0;


// Start Low Speed Oscillator and Configure RTC to wakeup device
void timers_rtc_init(uint32_t standby_time_seconds)
{
    rcc_periph_clock_enable(RCC_SYSCFG);

    // Enable PWR clock and disable write protection
    rcc_periph_clock_enable(RCC_PWR);
    pwr_disable_backup_domain_write_protect();

    // // Start low speed external oscillator = 32.768kHz. And wait until it is ready
    // rcc_osc_on(RCC_LSE);
    // rcc_wait_for_osc_ready(RCC_LSE);

    // // Enable RTC clock and select LSE
    // RCC_CSR &= ~(RCC_CSR_RTCSEL_MASK << RCC_CSR_RTCSEL_SHIFT);
	// RCC_CSR |= (RCC_CSR_RTCSEL_LSE << RCC_CSR_RTCSEL_SHIFT);
    // RCC_CSR |= RCC_CSR_RTCEN;

    // Start low speed internal oscillator ≈ 40kHz. And wait until it is ready
    rcc_osc_on(RCC_LSI);
    rcc_wait_for_osc_ready(RCC_LSI);

    // Enable RTC clock and select LSI
    RCC_CSR &= ~(RCC_CSR_RTCSEL_MASK << RCC_CSR_RTCSEL_SHIFT);
	RCC_CSR |= (RCC_CSR_RTCSEL_LSI << RCC_CSR_RTCSEL_SHIFT);
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
    exti_reset_request(EXTI20);
    exti_set_trigger(EXTI20, EXTI_TRIGGER_RISING);
    exti_enable_request(EXTI20);
    // exti_disable_request(EXTI20);

    nvic_clear_pending_irq(NVIC_RTC_IRQ);
    nvic_enable_irq(NVIC_RTC_IRQ);
    // nvic_disable_irq(NVIC_RTC_IRQ);
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

// Simple delay function. Puts cpu into nop loop timed by lptim1
void timers_delay_microseconds(uint32_t delay_microseconds)
{
    uint32_t curr_time = lptimer_get_counter(LPTIM1);

    // Limit delay to 16 bit max. Otherwise delay might never end
    if(delay_microseconds > 65000)
        delay_microseconds = 65000;

    while (lptimer_get_counter(LPTIM1) - curr_time < delay_microseconds);
}

/*
void timers_delay_milliseconds(uint32_t delay_milliseconds)
{
    uint32_t curr_time = lptimer_get_counter(LPTIM1);

    while(delay_milliseconds-- > 0)
    {
        while (lptimer_get_counter(LPTIM1) - curr_time < 1000);
        curr_time = lptimer_get_counter(LPTIM1);
    }
}
*/

// Returns value of microsecond counter
uint16_t timers_micros(void)
{
    return (uint16_t)lptimer_get_counter(LPTIM1);
}


// Setup TIM6 as millisecond counter. Clocked by APB1
void timers_tim6_init(void)
{
    rcc_periph_clock_enable(RCC_TIM6);
    timer_disable_counter(TIM6);
    timer_set_prescaler(TIM6, (2097 - 1));
    timer_enable_counter(TIM6);
}

// Simple delay function. Puts cpu into nop loop timed by lptim1
void timers_delay_milliseconds(uint32_t delay_milliseconds)
{
    uint32_t curr_time = timer_get_counter(TIM6);

    // Limit delay to 16 bit max. Otherwise delay might never end
    if(delay_milliseconds > 65000)
        delay_milliseconds = 65000;

    while (timer_get_counter(TIM6) - curr_time < delay_milliseconds);
}

// Returns value of millisecond counter
uint16_t timers_millis(void)
{
    return timer_get_counter(TIM6);
}


// Start independant watchdog timer
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

    // pwr_set_standby_mode();
    pwr_set_stop_mode();

    PWR_CR |= PWR_CR_LPDS | PWR_CR_ULP;

    pwr_clear_wakeup_flag();
    pwr_clear_standby_flag();

    // Enter standby
    while(1)
    {
        log_printf(MAIN, "WFI/E\n");
        set_gpio_for_standby();
        cm_disable_interrupts();
        __asm__("wfi");
        cm_enable_interrupts();
    }
}


// Timout functions
void timeout_init(void)
{
    timeout_counter     = 0; 
    // timeout_counter     = 2140483648; 
    timeout_timer       = timers_micros(); 
}

bool timeout(uint32_t time_microseconds, char *msg, uint32_t data)
{
    timeout_counter    += (uint16_t)(timers_micros() - timeout_timer);
    timeout_timer       = timers_micros();

    // log_printf(MAIN, "%u\n", timeout_counter);

    if(timeout_counter > time_microseconds)
    {
        log_printf(MAIN, "Timeout %s %08X\n", msg, data);
        return true;
    }
    else    
        return false;
}

void set_gpio_for_standby(void)
{   
    // Common
    // LED
    gpio_mode_setup(LED_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, LED);
    gpio_set(LED_PORT, LED);

    // Serial Print
    gpio_mode_setup(SPF_USART_TX_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, SPF_USART_TX);
	gpio_mode_setup(SPF_USART_RX_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  SPF_USART_RX);
	gpio_set(SPF_USART_RX_PORT, SPF_USART_RX);

    // Batt Sense
    gpio_mode_setup(BATT_SENS_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, BATT_SENS);
    
    // RFM
    // SPI
    gpio_mode_setup(RFM_SPI_MISO_PORT,  GPIO_MODE_ANALOG,   GPIO_PUPD_NONE,       RFM_SPI_MISO);

    gpio_mode_setup(RFM_SPI_SCK_PORT,   GPIO_MODE_INPUT,    GPIO_PUPD_PULLDOWN,   RFM_SPI_SCK);
    gpio_mode_setup(RFM_SPI_MOSI_PORT,  GPIO_MODE_INPUT,    GPIO_PUPD_PULLDOWN,   RFM_SPI_MOSI);

    gpio_mode_setup(RFM_SPI_NSS_PORT,   GPIO_MODE_INPUT,    GPIO_PUPD_PULLUP,     RFM_SPI_NSS);
    gpio_mode_setup(RFM_RESET_PORT,     GPIO_MODE_INPUT,    GPIO_PUPD_PULLUP,     RFM_RESET);

    // DIO
    gpio_mode_setup(RFM_IO_0_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_0);
    gpio_mode_setup(RFM_IO_1_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_1);
    gpio_mode_setup(RFM_IO_2_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_2);
    gpio_mode_setup(RFM_IO_3_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_3);
    gpio_mode_setup(RFM_IO_4_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_4);
    gpio_mode_setup(RFM_IO_5_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, RFM_IO_5);

    #ifdef _HUB
    #else

    // TMP
    gpio_mode_setup(TEMP_I2C_SCL_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, TEMP_I2C_SCL);
	gpio_mode_setup(TEMP_I2C_SDA_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, TEMP_I2C_SDA);

    #endif

}

// Override default rtc interrupt handler
void rtc_isr(void)
{ 
    exti_reset_request(EXTI20);

    // scb_reset_system();

    log_init();
    log_printf(MAIN, "RTC ISR\n");

    if(RTC_ISR & RTC_ISR_WUTF)
    { 
        pwr_disable_backup_domain_write_protect();
        rtc_unlock();
	    rtc_clear_wakeup_flag();
        pwr_clear_wakeup_flag();
        pwr_clear_standby_flag();
        rtc_lock();
	    pwr_enable_backup_domain_write_protect();
        set_gpio_for_standby();
    }
}