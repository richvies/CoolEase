# 1 "common/src/serial_printf.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "common/src/serial_printf.c"
# 1 "common/include/common/serial_printf.h" 1



# 1 "common/include/common/printf.h" 1
# 35 "common/include/common/printf.h"
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 1 3 4
# 40 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4

# 40 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 99 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 36 "common/include/common/printf.h" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 143 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 209 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 321 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 37 "common/include/common/printf.h" 2
# 49 "common/include/common/printf.h"

# 49 "common/include/common/printf.h"
void _putchar_spf(char character);
void _putchar_sim(char character);
void _putchar_log(char character);

int vprintf_spf(const char* format, va_list va);
int vprintf_sim(const char* format, va_list va);
int vprintf_log(const char* format, va_list va);
# 5 "common/include/common/serial_printf.h" 2

void spf_init(void);
int spf_serial_printf(const char* format, ...);
# 2 "common/src/serial_printf.c" 2

# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 20 "libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "libopencm3/include/libopencm3/cm3/common.h" 1
# 63 "libopencm3/include/libopencm3/cm3/common.h"
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 1 3 4
# 9 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 1 3 4
# 12 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 1 3 4







# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 1 3 4
# 28 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_newlib_version.h" 1 3 4
# 29 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 2 3 4
# 9 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 2 3 4
# 41 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4

# 41 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
# 55 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;

typedef long unsigned int __uint32_t;
# 103 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;
# 200 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;
# 214 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 35 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
# 190 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
# 14 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 20 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_stdint.h" 3 4
typedef __int8_t int8_t ;



typedef __uint8_t uint8_t ;







typedef __int16_t int16_t ;



typedef __uint16_t uint16_t ;







typedef __int32_t int32_t ;



typedef __uint32_t uint32_t ;







typedef __int64_t int64_t ;



typedef __uint64_t uint64_t ;






typedef __intmax_t intmax_t;




typedef __uintmax_t uintmax_t;




typedef __intptr_t intptr_t;




typedef __uintptr_t uintptr_t;
# 15 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4






typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;




typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;




typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;




typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
# 51 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
# 61 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
# 71 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
# 81 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 2 3 4
# 64 "libopencm3/include/libopencm3/cm3/common.h" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 65 "libopencm3/include/libopencm3/cm3/common.h" 2
# 21 "libopencm3/include/libopencm3/stm32/rcc.h" 2
# 1 "libopencm3/include/libopencm3/stm32/memorymap.h" 1
# 36 "libopencm3/include/libopencm3/stm32/memorymap.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/memorymap.h" 1
# 21 "libopencm3/include/libopencm3/stm32/l0/memorymap.h"
# 1 "libopencm3/include/libopencm3/cm3/memorymap.h" 1
# 22 "libopencm3/include/libopencm3/stm32/l0/memorymap.h" 2
# 37 "libopencm3/include/libopencm3/stm32/memorymap.h" 2
# 22 "libopencm3/include/libopencm3/stm32/rcc.h" 2
# 36 "libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/rcc.h" 1
# 45 "libopencm3/include/libopencm3/stm32/l0/rcc.h"
# 1 "libopencm3/include/libopencm3/stm32/pwr.h" 1
# 38 "libopencm3/include/libopencm3/stm32/pwr.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/pwr.h" 1
# 34 "libopencm3/include/libopencm3/stm32/l0/pwr.h"
# 1 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h" 1
# 29 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h"
# 1 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 1
# 105 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"



# 107 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
void pwr_disable_backup_domain_write_protect(void);
void pwr_enable_backup_domain_write_protect(void);
void pwr_enable_power_voltage_detect(uint32_t pvd_level);
void pwr_disable_power_voltage_detect(void);
void pwr_clear_standby_flag(void);
void pwr_clear_wakeup_flag(void);
void pwr_set_standby_mode(void);
void pwr_set_stop_mode(void);
void pwr_voltage_regulator_on_in_stop(void);
void pwr_voltage_regulator_low_power_in_stop(void);
void pwr_enable_wakeup_pin(void);
void pwr_disable_wakeup_pin(void);

# 119 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 119 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_voltage_high(void);

# 120 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 120 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_get_standby_flag(void);

# 121 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 121 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_get_wakeup_flag(void);


# 30 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h" 2
# 82 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h"
enum pwr_vos_scale {

 PWR_SCALE1,

 PWR_SCALE2,

 PWR_SCALE3,
};



void pwr_set_vos_scale(enum pwr_vos_scale scale);


# 35 "libopencm3/include/libopencm3/stm32/l0/pwr.h" 2
# 39 "libopencm3/include/libopencm3/stm32/pwr.h" 2
# 46 "libopencm3/include/libopencm3/stm32/l0/rcc.h" 2
# 506 "libopencm3/include/libopencm3/stm32/l0/rcc.h"
struct rcc_clock_scale {
 uint8_t pll_mul;
 uint16_t pll_div;
 uint8_t pll_source;
 uint8_t flash_waitstates;
 enum pwr_vos_scale voltage_scale;
 uint8_t hpre;
 uint8_t ppre1;
 uint8_t ppre2;

 uint32_t ahb_frequency;
 uint32_t apb1_frequency;
 uint32_t apb2_frequency;
 uint8_t msi_range;
};


extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;



enum rcc_osc {
 RCC_PLL, RCC_HSE, RCC_HSI48, RCC_HSI16, RCC_MSI, RCC_LSE, RCC_LSI
};




enum rcc_periph_clken {

 RCC_GPIOA = (((0x2c) << 5) + (0)),
 RCC_GPIOB = (((0x2c) << 5) + (1)),
 RCC_GPIOC = (((0x2c) << 5) + (2)),
 RCC_GPIOD = (((0x2c) << 5) + (3)),
 RCC_GPIOE = (((0x2c) << 5) + (4)),
 RCC_GPIOH = (((0x2c) << 5) + (7)),


 RCC_DMA = (((0x30) << 5) + (0)),
 RCC_MIF = (((0x30) << 5) + (8)),
 RCC_CRC = (((0x30) << 5) + (12)),
 RCC_TSC = (((0x30) << 5) + (16)),
 RCC_RNG = (((0x30) << 5) + (20)),
 RCC_CRYPT = (((0x30) << 5) + (24)),


 RCC_SYSCFG = (((0x34) << 5) + (0)),
 RCC_TIM21 = (((0x34) << 5) + (2)),
 RCC_TIM22 = (((0x34) << 5) + (5)),
 RCC_FW = (((0x34) << 5) + (7)),
 RCC_ADC1 = (((0x34) << 5) + (9)),
 RCC_SPI1 = (((0x34) << 5) + (12)),
 RCC_USART1 = (((0x34) << 5) + (14)),
 RCC_DBG = (((0x34) << 5) + (22)),


 RCC_TIM2 = (((0x38) << 5) + (0)),
 RCC_TIM3 = (((0x38) << 5) + (1)),
 RCC_TIM6 = (((0x38) << 5) + (4)),
 RCC_TIM7 = (((0x38) << 5) + (5)),
 RCC_LCD = (((0x38) << 5) + (9)),
 RCC_WWDG = (((0x38) << 5) + (11)),
 RCC_SPI2 = (((0x38) << 5) + (14)),
 RCC_USART2 = (((0x38) << 5) + (17)),
 RCC_LPUART1 = (((0x38) << 5) + (18)),
 RCC_USART4 = (((0x38) << 5) + (19)),
 RCC_USART5 = (((0x38) << 5) + (20)),
 RCC_I2C1 = (((0x38) << 5) + (21)),
 RCC_I2C2 = (((0x38) << 5) + (22)),
 RCC_USB = (((0x38) << 5) + (23)),
 RCC_CRS = (((0x38) << 5) + (27)),
 RCC_PWR = (((0x38) << 5) + (28)),
 RCC_DAC = (((0x38) << 5) + (29)),
 RCC_I2C3 = (((0x38) << 5) + (30)),
 RCC_LPTIM1 = (((0x38) << 5) + (31)),


 SCC_GPIOA = (((0x3c) << 5) + (0)),
 SCC_GPIOB = (((0x3c) << 5) + (1)),
 SCC_GPIOC = (((0x3c) << 5) + (2)),
 SCC_GPIOD = (((0x3c) << 5) + (3)),
 SCC_GPIOE = (((0x3c) << 5) + (4)),
 SCC_GPIOH = (((0x3c) << 5) + (7)),


 SCC_DMA = (((0x40) << 5) + (0)),
 SCC_MIF = (((0x40) << 5) + (8)),
 SCC_SRAM = (((0x40) << 5) + (12)),
 SCC_CRC = (((0x40) << 5) + (12)),
 SCC_TSC = (((0x40) << 5) + (16)),
 SCC_RNG = (((0x40) << 5) + (20)),
 SCC_CRYPT = (((0x40) << 5) + (24)),


 SCC_SYSCFG = (((0x44) << 5) + (0)),
 SCC_TIM21 = (((0x44) << 5) + (2)),
 SCC_TIM22 = (((0x44) << 5) + (5)),
 SCC_ADC1 = (((0x44) << 5) + (9)),
 SCC_SPI1 = (((0x44) << 5) + (12)),
 SCC_USART1 = (((0x44) << 5) + (14)),
 SCC_DBG = (((0x44) << 5) + (22)),


 SCC_TIM2 = (((0x48) << 5) + (0)),
 SCC_TIM3 = (((0x48) << 5) + (1)),
 SCC_TIM6 = (((0x48) << 5) + (4)),
 SCC_TIM7 = (((0x48) << 5) + (5)),
 SCC_LCD = (((0x48) << 5) + (9)),
 SCC_WWDG = (((0x48) << 5) + (11)),
 SCC_SPI2 = (((0x48) << 5) + (14)),
 SCC_USART2 = (((0x48) << 5) + (17)),
 SCC_LPUART1 = (((0x48) << 5) + (18)),
 SCC_USART4 = (((0x48) << 5) + (19)),
 SCC_USART5 = (((0x48) << 5) + (20)),
 SCC_I2C1 = (((0x48) << 5) + (21)),
 SCC_I2C2 = (((0x48) << 5) + (22)),
 SCC_USB = (((0x48) << 5) + (23)),
 SCC_CRS = (((0x48) << 5) + (27)),
 SCC_PWR = (((0x48) << 5) + (28)),
 SCC_DAC = (((0x48) << 5) + (29)),
 SCC_I2C3 = (((0x48) << 5) + (30)),
 SCC_LPTIM1 = (((0x48) << 5) + (31)),
};

enum rcc_periph_rst {

 RST_GPIOA = (((0x1c) << 5) + (0)),
 RST_GPIOB = (((0x1c) << 5) + (1)),
 RST_GPIOC = (((0x1c) << 5) + (2)),
 RST_GPIOD = (((0x1c) << 5) + (3)),
 RST_GPIOE = (((0x1c) << 5) + (4)),
 RST_GPIOH = (((0x1c) << 5) + (7)),


 RST_DMA = (((0x20) << 5) + (0)),
 RST_MIF = (((0x20) << 5) + (8)),
 RST_CRC = (((0x20) << 5) + (12)),
 RST_TSC = (((0x20) << 5) + (16)),
 RST_RNG = (((0x20) << 5) + (20)),
 RST_CRYPT = (((0x20) << 5) + (24)),


 RST_SYSCFG = (((0x24) << 5) + (0)),
 RST_TIM21 = (((0x24) << 5) + (2)),
 RST_TIM22 = (((0x24) << 5) + (5)),
 RST_ADC1 = (((0x24) << 5) + (9)),
 RST_SPI1 = (((0x24) << 5) + (12)),
 RST_USART1 = (((0x24) << 5) + (14)),
 RST_DBG = (((0x24) << 5) + (22)),


 RST_TIM2 = (((0x28) << 5) + (0)),
 RST_TIM3 = (((0x28) << 5) + (1)),
 RST_TIM6 = (((0x28) << 5) + (4)),
 RST_TIM7 = (((0x28) << 5) + (5)),
 RST_LCD = (((0x28) << 5) + (9)),
 RST_WWDG = (((0x28) << 5) + (11)),
 RST_SPI2 = (((0x28) << 5) + (14)),
 RST_USART2 = (((0x28) << 5) + (17)),
 RST_LPUART1 = (((0x28) << 5) + (18)),
 RST_USART4 = (((0x28) << 5) + (19)),
 RST_USART5 = (((0x28) << 5) + (20)),
 RST_I2C1 = (((0x28) << 5) + (21)),
 RST_I2C2 = (((0x28) << 5) + (22)),
 RST_USB = (((0x28) << 5) + (23)),
 RST_CRS = (((0x28) << 5) + (27)),
 RST_PWR = (((0x28) << 5) + (28)),
 RST_DAC = (((0x28) << 5) + (29)),
 RST_I2C3 = (((0x28) << 5) + (30)),
 RST_LPTIM1 = (((0x28) << 5) + (31)),
};
# 1 "libopencm3/include/libopencm3/stm32/common/rcc_common_all.h" 1
# 39 "libopencm3/include/libopencm3/stm32/common/rcc_common_all.h"


void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset);
void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset);

void rcc_periph_clock_enable(enum rcc_periph_clken clken);
void rcc_periph_clock_disable(enum rcc_periph_clken clken);
void rcc_periph_reset_pulse(enum rcc_periph_rst rst);
void rcc_periph_reset_hold(enum rcc_periph_rst rst);
void rcc_periph_reset_release(enum rcc_periph_rst rst);

void rcc_set_mco(uint32_t mcosrc);
void rcc_osc_bypass_enable(enum rcc_osc osc);
void rcc_osc_bypass_disable(enum rcc_osc osc);







# 61 "libopencm3/include/libopencm3/stm32/common/rcc_common_all.h" 3 4
_Bool 
# 61 "libopencm3/include/libopencm3/stm32/common/rcc_common_all.h"
    rcc_is_osc_ready(enum rcc_osc osc);






void rcc_wait_for_osc_ready(enum rcc_osc osc);


# 680 "libopencm3/include/libopencm3/stm32/l0/rcc.h" 2



void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_set_hsi48_source_rc48(void);
void rcc_set_hsi48_source_pll(void);
void rcc_set_sysclk_source(enum rcc_osc osc);
void rcc_set_pll_multiplier(uint32_t factor);
void rcc_set_pll_divider(uint32_t factor);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);

void rcc_set_msi_range(uint32_t msi_range);

void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel);

void rcc_set_lptim1_sel(uint32_t lptim1_sel);
void rcc_set_lpuart1_sel(uint32_t lpupart1_sel);
void rcc_set_usart1_sel(uint32_t usart1_sel);
void rcc_set_usart2_sel(uint32_t usart2_sel);


# 37 "libopencm3/include/libopencm3/stm32/rcc.h" 2
# 4 "common/src/serial_printf.c" 2
# 1 "libopencm3/include/libopencm3/stm32/gpio.h" 1
# 36 "libopencm3/include/libopencm3/stm32/gpio.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/gpio.h" 1
# 34 "libopencm3/include/libopencm3/stm32/l0/gpio.h"
# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 1
# 41 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h"
# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 1
# 41 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_all.h" 1
# 72 "libopencm3/include/libopencm3/stm32/common/gpio_common_all.h"


void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint16_t data);
void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios);


# 42 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 2
# 248 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"

# 258 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);


# 42 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 2
# 35 "libopencm3/include/libopencm3/stm32/l0/gpio.h" 2
# 72 "libopencm3/include/libopencm3/stm32/l0/gpio.h"



# 37 "libopencm3/include/libopencm3/stm32/gpio.h" 2
# 5 "common/src/serial_printf.c" 2
# 1 "libopencm3/include/libopencm3/stm32/usart.h" 1
# 36 "libopencm3/include/libopencm3/stm32/usart.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/usart.h" 1
# 30 "libopencm3/include/libopencm3/stm32/l0/usart.h"
# 1 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 1
# 99 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"


void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, uint32_t bits);
void usart_set_stopbits(uint32_t usart, uint32_t stopbits);
void usart_set_parity(uint32_t usart, uint32_t parity);
void usart_set_mode(uint32_t usart, uint32_t mode);
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);
void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_wait_send_ready(uint32_t usart);
void usart_wait_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_dma(uint32_t usart);
void usart_disable_rx_dma(uint32_t usart);
void usart_enable_tx_dma(uint32_t usart);
void usart_disable_tx_dma(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_enable_error_interrupt(uint32_t usart);
void usart_disable_error_interrupt(uint32_t usart);

# 125 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 3 4
_Bool 
# 125 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
    usart_get_flag(uint32_t usart, uint32_t flag);


# 31 "libopencm3/include/libopencm3/stm32/l0/usart.h" 2
# 1 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h" 1
# 26 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
       
# 616 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"


void usart_enable_data_inversion(uint32_t usart);
void usart_disable_data_inversion(uint32_t usart);
void usart_enable_tx_inversion(uint32_t usart);
void usart_disable_tx_inversion(uint32_t usart);
void usart_enable_rx_inversion(uint32_t usart);
void usart_disable_rx_inversion(uint32_t usart);
void usart_enable_halfduplex(uint32_t usart);
void usart_disable_halfduplex(uint32_t usart);

void usart_set_rx_timeout_value(uint32_t usart, uint32_t value);
void usart_enable_rx_timeout(uint32_t usart);
void usart_disable_rx_timeout(uint32_t usart);
void usart_enable_rx_timeout_interrupt(uint32_t usart);
void usart_disable_rx_timeout_interrupt(uint32_t usart);


# 32 "libopencm3/include/libopencm3/stm32/l0/usart.h" 2
# 46 "libopencm3/include/libopencm3/stm32/l0/usart.h"



# 37 "libopencm3/include/libopencm3/stm32/usart.h" 2
# 6 "common/src/serial_printf.c" 2
# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 36 "libopencm3/include/libopencm3/stm32/flash.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/flash.h" 1
# 34 "libopencm3/include/libopencm3/stm32/l0/flash.h"
# 1 "libopencm3/include/libopencm3/stm32/common/flash_common_all.h" 1
# 21 "libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
       




# 37 "libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
void flash_prefetch_enable(void);





void flash_prefetch_disable(void);
# 55 "libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
void flash_set_ws(uint32_t ws);




void flash_lock(void);





void flash_unlock(void);





void flash_unlock_option_bytes(void);


# 35 "libopencm3/include/libopencm3/stm32/l0/flash.h" 2
# 1 "libopencm3/include/libopencm3/stm32/common/flash_common_l01.h" 1
# 115 "libopencm3/include/libopencm3/stm32/common/flash_common_l01.h"


void flash_unlock_pecr(void);
void flash_lock_pecr(void);
void flash_unlock_progmem(void);
void flash_lock_progmem(void);
void flash_lock_option_bytes(void);
void flash_unlock_acr(void);

void eeprom_program_word(uint32_t address, uint32_t data);
void eeprom_program_words(uint32_t address, uint32_t *data, int length_in_words);


# 36 "libopencm3/include/libopencm3/stm32/l0/flash.h" 2
# 58 "libopencm3/include/libopencm3/stm32/l0/flash.h"



# 37 "libopencm3/include/libopencm3/stm32/flash.h" 2
# 7 "common/src/serial_printf.c" 2

# 1 "common/include/common/board_defs.h" 1



# 1 "libopencm3/include/libopencm3/stm32/gpio.h" 1
# 5 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 6 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/spi.h" 1
# 36 "libopencm3/include/libopencm3/stm32/spi.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/spi.h" 1
# 34 "libopencm3/include/libopencm3/stm32/l0/spi.h"
# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 1
# 32 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h"
       



# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 1
# 32 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"
       



# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h" 1
# 345 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h"


void spi_reset(uint32_t spi_peripheral);
void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);
uint16_t spi_clean_disable(uint32_t spi);
void spi_write(uint32_t spi, uint16_t data);
void spi_send(uint32_t spi, uint16_t data);
uint16_t spi_read(uint32_t spi);
uint16_t spi_xfer(uint32_t spi, uint16_t data);
void spi_set_bidirectional_mode(uint32_t spi);
void spi_set_unidirectional_mode(uint32_t spi);
void spi_set_bidirectional_receive_only_mode(uint32_t spi);
void spi_set_bidirectional_transmit_only_mode(uint32_t spi);
void spi_enable_crc(uint32_t spi);
void spi_disable_crc(uint32_t spi);
void spi_set_next_tx_from_buffer(uint32_t spi);
void spi_set_next_tx_from_crc(uint32_t spi);
void spi_set_full_duplex_mode(uint32_t spi);
void spi_set_receive_only_mode(uint32_t spi);
void spi_disable_software_slave_management(uint32_t spi);
void spi_enable_software_slave_management(uint32_t spi);
void spi_set_nss_high(uint32_t spi);
void spi_set_nss_low(uint32_t spi);
void spi_send_lsb_first(uint32_t spi);
void spi_send_msb_first(uint32_t spi);
void spi_set_baudrate_prescaler(uint32_t spi, uint8_t baudrate);
void spi_set_master_mode(uint32_t spi);
void spi_set_slave_mode(uint32_t spi);
void spi_set_clock_polarity_1(uint32_t spi);
void spi_set_clock_polarity_0(uint32_t spi);
void spi_set_clock_phase_1(uint32_t spi);
void spi_set_clock_phase_0(uint32_t spi);
void spi_enable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_disable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_enable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_disable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_enable_error_interrupt(uint32_t spi);
void spi_disable_error_interrupt(uint32_t spi);
void spi_enable_ss_output(uint32_t spi);
void spi_disable_ss_output(uint32_t spi);
void spi_enable_tx_dma(uint32_t spi);
void spi_disable_tx_dma(uint32_t spi);
void spi_enable_rx_dma(uint32_t spi);
void spi_disable_rx_dma(uint32_t spi);
void spi_set_standard_mode(uint32_t spi, uint8_t mode);


# 37 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 2
# 54 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"


int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
  uint32_t dff, uint32_t lsbfirst);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);


# 37 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 2
# 54 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h"


void spi_set_frf_ti(uint32_t spi);
void spi_set_frf_motorola(uint32_t spi);


# 35 "libopencm3/include/libopencm3/stm32/l0/spi.h" 2
# 37 "libopencm3/include/libopencm3/stm32/spi.h" 2
# 7 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/usart.h" 1
# 8 "common/include/common/board_defs.h" 2
# 148 "common/include/common/board_defs.h"
typedef struct
{
 
# 150 "common/include/common/board_defs.h" 3 4
_Bool 
# 150 "common/include/common/board_defs.h"
       msg_pend;
 
# 151 "common/include/common/board_defs.h" 3 4
_Bool 
# 151 "common/include/common/board_defs.h"
       active;
 uint32_t dev_num;
 uint32_t msg_num;
 uint32_t msg_num_start;
 uint32_t ok_packets;
 uint32_t total_packets;
}sensor_t;

extern sensor_t sensors[50];
extern uint8_t num_sensors;
sensor_t *get_sensor(uint32_t dev_num);
# 252 "common/include/common/board_defs.h"
void gpio_init(void);
# 9 "common/src/serial_printf.c" 2



static void clock_setup(void);
static void usart_setup(void);



void spf_init(void)
{
 rcc_periph_clock_enable(RCC_GPIOA);
 rcc_periph_clock_enable(RCC_GPIOB);

 clock_setup();
 usart_setup();
}

int spf_serial_printf(const char* format, ...)
{
   va_list va;
   
# 29 "common/src/serial_printf.c" 3 4
  __builtin_va_start(
# 29 "common/src/serial_printf.c"
  va
# 29 "common/src/serial_printf.c" 3 4
  ,
# 29 "common/src/serial_printf.c"
  format
# 29 "common/src/serial_printf.c" 3 4
  )
# 29 "common/src/serial_printf.c"
                      ;
   const int ret = vprintf_spf(format, va);
   
# 31 "common/src/serial_printf.c" 3 4
  __builtin_va_end(
# 31 "common/src/serial_printf.c"
  va
# 31 "common/src/serial_printf.c" 3 4
  )
# 31 "common/src/serial_printf.c"
            ;

 while(!usart_get_flag((((0x40000000U) + 0x00000) + 0x4400), (1 << 6))) {__asm__("nop");}

 return ret;
}


void _putchar_spf(char character)
{
 usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), character);
}



static void clock_setup(void)
{

 rcc_osc_on(RCC_MSI);
 rcc_wait_for_osc_ready(RCC_MSI);


 rcc_set_msi_range(5);


 rcc_set_hpre(0x0);
 rcc_set_ppre1(0x0);
 rcc_set_ppre2(0x0);


 flash_set_ws(0x00);


 rcc_ahb_frequency = 2097000;
 rcc_apb1_frequency = 2097000;
 rcc_apb2_frequency = 2097000;
}

static void usart_setup(void)
{
 rcc_periph_clock_enable(RCC_USART2);

 gpio_mode_setup(((0x50000000U) + 0x00000), 0x2, 0x0, (1 << 2));
 gpio_mode_setup(((0x50000000U) + 0x00000), 0x2, 0x0, (1 << 3));

    gpio_set_output_options(((0x50000000U) + 0x00000), 0x0, 0x0, (1 << 2));

    gpio_set_af(((0x50000000U) + 0x00000), 0x4, (1 << 2));
    gpio_set_af(((0x50000000U) + 0x00000), 0x4, (1 << 3));

    rcc_periph_reset_pulse(RST_USART2);
 usart_disable((((0x40000000U) + 0x00000) + 0x4400));
 usart_set_baudrate((((0x40000000U) + 0x00000) + 0x4400), 115200);
 usart_set_databits((((0x40000000U) + 0x00000) + 0x4400), 8);
 usart_set_stopbits((((0x40000000U) + 0x00000) + 0x4400),(0x00 << 12));
 usart_set_mode((((0x40000000U) + 0x00000) + 0x4400), ((1 << 2) | (1 << 3)));
 usart_set_parity((((0x40000000U) + 0x00000) + 0x4400), 0x00);
 usart_set_flow_control((((0x40000000U) + 0x00000) + 0x4400), 0x00);
 usart_enable((((0x40000000U) + 0x00000) + 0x4400));
}
