#ifndef TIMERS_H
#define TIMERS_H

#include <stdint.h>

// Start Low Speed Oscillator and Configure RTC, IWDG & WWDG Registers
void timers_rtc_init(uint32_t standby_time_seconds);

// Setup timer6 as approx. microsecond counter
void timers_lptim_init(void);

void timers_iwdg_init(uint32_t period);

// Reset independant and window watchdog timers
void timers_pet_dogs(void);

// Enter standby mode
void timers_enter_standby(void);

// Simple delay function. Puts cpu into nop loop timed by timer6
// delay_microseconds limited to 16 bit maximum. Otherwise delay might never end
void timers_delay_microseconds(uint32_t delay_microseconds);

void timers_delay_milliseconds(uint32_t delay_milliseconds);

#endif