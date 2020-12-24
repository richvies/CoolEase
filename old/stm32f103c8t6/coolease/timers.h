#ifndef TIMERS_H
#define TIMERS_H

#include <stdint.h>

// Start Low Speed Oscillator and Configure RTC, IWDG & WWDG Registers
void timers_rtc_init(void);

void timers_iwdg_init(void);

// Reset independant and window watchdog timers
void timers_pet_dogs(void);

// Sets up RTC to wake device after number of seconds
// Standby initiated by timers_standby_check() after intentional watchdog reset
// This prevents watchdog from waking device while in standby
void timers_prepare_and_enter_standby(uint32_t standby_time_seconds);

// Run just after reset and possibly calls timers_enter_standby()
void timers_standby_check(void);

// Simple delay function. Puts CPU into nop loop timed by RTC 
void timers_delay(uint32_t delay_seconds);

void timers_tim2_init(void);

#endif