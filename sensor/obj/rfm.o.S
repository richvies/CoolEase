# 1 "common/src/rfm.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "common/src/rfm.c"
# 15 "common/src/rfm.c"
# 1 "common/include/common/rfm.h" 1
# 37 "common/include/common/rfm.h"
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
# 38 "common/include/common/rfm.h" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 39 "common/include/common/rfm.h" 2
# 303 "common/include/common/rfm.h"

# 303 "common/include/common/rfm.h"
typedef struct rfm_packet_s
{



    union {
        uint8_t buffer[16];

        struct{
                uint32_t device_number;
                uint32_t msg_number;
                int8_t power;
                uint16_t battery;
                int16_t temperature;
        };
    }data;


    uint8_t flags;
    
# 322 "common/include/common/rfm.h" 3 4
   _Bool 
# 322 "common/include/common/rfm.h"
               crc_ok;
    int8_t snr;
    int16_t rssi;


    enum
    {
        RFM_PACKET_DEV_NUM_0 = 0, RFM_PACKET_DEV_NUM_1, RFM_PACKET_DEV_NUM_2, RFM_PACKET_DEV_NUM_3,
        RFM_PACKET_MSG_NUM_0, RFM_PACKET_MSG_NUM_1, RFM_PACKET_MSG_NUM_2, RFM_PACKET_MSG_NUM_3,
        RFM_PACKET_POWER,
        RFM_PACKET_BATTERY_0, RFM_PACKET_BATTERY_1,
        RFM_PACKET_TEMP_0, RFM_PACKET_TEMP_1
    }packet_data_e;

}rfm_packet_t;
# 352 "common/include/common/rfm.h"
void rfm_init(void);
void rfm_reset(void);
void rfm_end(void);
void rfm_calibrate_crystal(void);
void rfm_config_for_lora(uint8_t BW, uint8_t CR, uint8_t SF, 
# 356 "common/include/common/rfm.h" 3 4
                                                            _Bool 
# 356 "common/include/common/rfm.h"
                                                                 crc_turn_on, int8_t power);
void rfm_config_for_gfsk(void);
void rfm_set_power(int8_t power, uint8_t ramp_time);
void rfm_get_stats(void);
void rfm_reset_stats(void);
uint8_t rfm_get_version(void);

void rfm_start_listening(void);
void rfm_get_packets(void);
rfm_packet_t* rfm_get_next_packet(void);
uint8_t rfm_get_num_packets(void);
void rfm_organize_packet(rfm_packet_t *packet);


# 369 "common/include/common/rfm.h" 3 4
_Bool 
# 369 "common/include/common/rfm.h"
    rfm_transmit_packet(rfm_packet_t packet);
void rfm_set_tx_continuous(void);
void rfm_clear_tx_continuous(void);
# 16 "common/src/rfm.c" 2




# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 20 "libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "libopencm3/include/libopencm3/cm3/common.h" 1
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
# 21 "common/src/rfm.c" 2
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
# 22 "common/src/rfm.c" 2
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
# 23 "common/src/rfm.c" 2
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
# 24 "common/src/rfm.c" 2
# 1 "libopencm3/include/libopencm3/stm32/exti.h" 1
# 38 "libopencm3/include/libopencm3/stm32/exti.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/exti.h" 1
# 39 "libopencm3/include/libopencm3/stm32/l0/exti.h"
# 1 "libopencm3/include/libopencm3/stm32/common/exti_common_all.h" 1
# 74 "libopencm3/include/libopencm3/stm32/common/exti_common_all.h"
enum exti_trigger_type {
 EXTI_TRIGGER_RISING,
 EXTI_TRIGGER_FALLING,
 EXTI_TRIGGER_BOTH,
};



void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig);
void exti_enable_request(uint32_t extis);
void exti_disable_request(uint32_t extis);
void exti_reset_request(uint32_t extis);
void exti_select_source(uint32_t exti, uint32_t gpioport);
uint32_t exti_get_flag_status(uint32_t exti);


# 40 "libopencm3/include/libopencm3/stm32/l0/exti.h" 2
# 1 "libopencm3/include/libopencm3/stm32/common/exti_common_v1.h" 1

       
# 45 "libopencm3/include/libopencm3/stm32/common/exti_common_v1.h"



# 41 "libopencm3/include/libopencm3/stm32/l0/exti.h" 2
# 39 "libopencm3/include/libopencm3/stm32/exti.h" 2
# 25 "common/src/rfm.c" 2
# 1 "libopencm3/include/libopencm3/stm32/syscfg.h" 1
# 34 "libopencm3/include/libopencm3/stm32/syscfg.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/syscfg.h" 1
# 130 "libopencm3/include/libopencm3/stm32/l0/syscfg.h"



# 35 "libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 26 "common/src/rfm.c" 2
# 1 "libopencm3/include/libopencm3/cm3/nvic.h" 1
# 147 "libopencm3/include/libopencm3/cm3/nvic.h"
# 1 "libopencm3/include/libopencm3/dispatch/nvic.h" 1
# 18 "libopencm3/include/libopencm3/dispatch/nvic.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/nvic.h" 1
# 9 "libopencm3/include/libopencm3/stm32/l0/nvic.h"
# 1 "libopencm3/include/libopencm3/cm3/nvic.h" 1
# 10 "libopencm3/include/libopencm3/stm32/l0/nvic.h" 2
# 58 "libopencm3/include/libopencm3/stm32/l0/nvic.h"


void wwdg_isr(void);
void pvd_isr(void);
void rtc_isr(void);
void flash_isr(void);
void rcc_isr(void);
void exti0_1_isr(void);
void exti2_3_isr(void);
void exti4_15_isr(void);
void tsc_isr(void);
void dma1_channel1_isr(void);
void dma1_channel2_3_isr(void);
void dma1_channel4_5_isr(void);
void adc_comp_isr(void);
void lptim1_isr(void);
void usart4_5_isr(void);
void tim2_isr(void);
void tim3_isr(void);
void tim6_dac_isr(void);
void tim7_isr(void);
void reserved4_isr(void);
void tim21_isr(void);
void i2c3_isr(void);
void tim22_isr(void);
void i2c1_isr(void);
void i2c2_isr(void);
void spi1_isr(void);
void spi2_isr(void);
void usart1_isr(void);
void usart2_isr(void);
void lpuart1_aes_rng_isr(void);
void lcd_isr(void);
void usb_isr(void);


# 19 "libopencm3/include/libopencm3/dispatch/nvic.h" 2
# 148 "libopencm3/include/libopencm3/cm3/nvic.h" 2





void nvic_enable_irq(uint8_t irqn);
void nvic_disable_irq(uint8_t irqn);
uint8_t nvic_get_pending_irq(uint8_t irqn);
void nvic_set_pending_irq(uint8_t irqn);
void nvic_clear_pending_irq(uint8_t irqn);
uint8_t nvic_get_irq_enabled(uint8_t irqn);
void nvic_set_priority(uint8_t irqn, uint8_t priority);







void reset_handler(void);
void nmi_handler(void);
void hard_fault_handler(void);
void sv_call_handler(void);
void pend_sv_handler(void);
void sys_tick_handler(void);
# 182 "libopencm3/include/libopencm3/cm3/nvic.h"

# 27 "common/src/rfm.c" 2

# 1 "common/include/common/board_defs.h" 1



# 1 "libopencm3/include/libopencm3/stm32/gpio.h" 1
# 5 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 6 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/spi.h" 1
# 7 "common/include/common/board_defs.h" 2
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
# 29 "common/src/rfm.c" 2
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
# 30 "common/src/rfm.c" 2
# 1 "common/include/common/timers.h" 1
# 26 "common/include/common/timers.h"
void timers_rtc_init(uint32_t standby_time_seconds);



void timers_lptim_init(void);


void timers_delay_microseconds(uint32_t delay_microseconds);


uint16_t timers_micros(void);



void timers_tim6_init(void);


void timers_delay_milliseconds(uint32_t delay_milliseconds);


uint16_t timers_millis(void);



void timers_iwdg_init(uint32_t period);


void timers_pet_dogs(void);



void timers_enter_standby(void);


void timeout_init(void);

# 61 "common/include/common/timers.h" 3 4
_Bool 
# 61 "common/include/common/timers.h"
    timeout(uint32_t time_microseconds, char *msg, uint32_t data);

void set_gpio_for_standby(void);
# 31 "common/src/rfm.c" 2
# 67 "common/src/rfm.c"
static 
# 67 "common/src/rfm.c" 3 4
      _Bool 
# 67 "common/src/rfm.c"
           crc_on = 
# 67 "common/src/rfm.c" 3 4
                                 0
# 67 "common/src/rfm.c"
                                      ;
static uint8_t random_data[16] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};



static uint8_t packets_head = 0;
static uint8_t packets_tail = 0;
static uint8_t packets_read = 0;
static rfm_packet_t packets_buf[16];
# 87 "common/src/rfm.c"
static void clock_setup(void);
static void spi_setup(void);
static uint8_t spi_read_single(uint8_t reg);
static void spi_read_burst(uint8_t reg, uint8_t *buf, uint8_t len);
static void spi_write_single(uint8_t reg, uint8_t data);
static void spi_write_burst(uint8_t reg, uint8_t *buf, uint8_t len);
static void set_frequency(uint32_t frequency_hz);
static void set_dio_irq(uint8_t io0_3, uint8_t io4_5);
static void set_preamble_length(uint16_t num_sym);
static void print_registers(void);
static void clear_buffer(void);
static inline void mask_irq(uint8_t irq);
static inline void unmask_irq(uint8_t irq);
static inline uint8_t get_irq(void);
static inline void clear_irq(uint8_t irq);
static inline void set_standby_mode(void);
static inline void set_tx_mode(void);
static inline void set_rx_mode(void);
static inline void set_sleep_mode(void);
# 123 "common/src/rfm.c"
void rfm_init(void)
{
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_SYSCFG);


  clock_setup();
  spi_setup();


  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 15));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 12));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 11));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 2));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 10));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 1));


  gpio_mode_setup(((0x50000000U) + 0x00400), 0x1, 0x0, (1 << 0));
  gpio_set_output_options(((0x50000000U) + 0x00400), 0x0, 0x0, (1 << 0));
  gpio_set(((0x50000000U) + 0x00400), (1 << 0));

  gpio_set(((0x50000000U) + 0x00000), (1 << 4));

  set_sleep_mode();

  rfm_reset();

  spf_serial_printf("RFM Init Done\n");
}

void rfm_reset(void)
{

  gpio_clear(((0x50000000U) + 0x00400), (1 << 0));
  timers_delay_milliseconds(1);

  gpio_set(((0x50000000U) + 0x00400), (1 << 0));
  timers_delay_milliseconds(1);

  timers_delay_milliseconds(10);

  print_registers();

  set_sleep_mode();

  spf_serial_printf("RFM Reset Done\n");
}

void rfm_end(void)
{
  set_standby_mode();
  set_sleep_mode();

  spi_disable((((0x40000000U) + 0x10000) + 0x3000));
  rcc_periph_clock_disable(RCC_SPI1);

  spf_serial_printf("RFM End Done\n");
}

void rfm_calibrate_crystal(void)
{

}

void rfm_config_for_lora(uint8_t BW, uint8_t CR, uint8_t SF, 
# 189 "common/src/rfm.c" 3 4
                                                            _Bool 
# 189 "common/src/rfm.c"
                                                                 crc_turn_on, int8_t power)
{

  set_sleep_mode();


  spi_write_single(0x01, 0x00 | 0x80);


  set_standby_mode();




  set_frequency(868000000);


  rfm_set_power(power, 0x09);


  spi_write_single(0x1f, 0x64);


  set_preamble_length(6);


  spi_write_single(0x1d, BW | CR | 1);
# 235 "common/src/rfm.c"
  spi_write_single(0x1e, SF | (crc_turn_on << 2));
  crc_on = crc_turn_on;


  if(SF == 0x60)
  {
    spi_write_single(0x31, (spi_read_single(0x31) & ~0xF8) | 0x05);
    spi_write_single(0x37, 0x0C);
  }


  spi_write_single(0x22, 16);







  set_sleep_mode();
}

void rfm_config_for_gfsk(void)
{
# 280 "common/src/rfm.c"
}

void rfm_set_power(int8_t power, uint8_t ramp_time)
{
  if( power > 20 )
      power = 20;



  if(ramp_time > 0x0F)
    ramp_time = 0x0F;


  spi_write_single(0x4d, (spi_read_single(0x4d) & ~0x07) | 0x04);



 spi_write_single(0x09, 0x80 | 0x70 | (power-2));


  spi_write_single(0x0a, (spi_read_single(0x0a) & ~0x0f) | ramp_time);
}

void rfm_get_stats(void)
{

}

void rfm_reset_stats(void)
{

}

uint8_t rfm_get_version(void)
{
  return spi_read_single(0x42);
}


void rfm_start_listening(void)
{

  set_standby_mode();


  clear_buffer();


  set_dio_irq((0 << 6) | (0 << 4) | (0 << 2) | (2 << 0), (0 << 6) | (0 << 4));


  mask_irq(0xFF);
  unmask_irq(0x80 | 0x40 | 0x10 | 0x20);
  clear_irq(0xFF);


  exti_reset_request((1 << 15));
  exti_select_source((1 << 15), ((0x50000000U) + 0x00400));
 exti_set_trigger((1 << 15), EXTI_TRIGGER_RISING);
 exti_enable_request((1 << 15));

 nvic_enable_irq(7);
  nvic_set_priority(7, 0);


  set_rx_mode();
}

void rfm_organize_packet(rfm_packet_t *packet)
{

      packet->data.device_number = packet->data.buffer[RFM_PACKET_DEV_NUM_3] << 24 | packet->data.buffer[RFM_PACKET_DEV_NUM_2] << 16 | packet->data.buffer[RFM_PACKET_DEV_NUM_1] << 8 | packet->data.buffer[RFM_PACKET_DEV_NUM_0];
      packet->data.msg_number = packet->data.buffer[RFM_PACKET_MSG_NUM_3] << 24 | packet->data.buffer[RFM_PACKET_MSG_NUM_2] << 16 | packet->data.buffer[RFM_PACKET_MSG_NUM_1] << 8 | packet->data.buffer[RFM_PACKET_MSG_NUM_0];
      packet->data.power = packet->data.buffer[RFM_PACKET_POWER];
      packet->data.battery = packet->data.buffer[RFM_PACKET_BATTERY_1] << 8 | packet->data.buffer[RFM_PACKET_BATTERY_0];
      packet->data.temperature = packet->data.buffer[RFM_PACKET_TEMP_1] << 8 | packet->data.buffer[RFM_PACKET_TEMP_0];
}

void rfm_get_packets(void)
{
  if(packets_tail != packets_head)
  {

    set_standby_mode();


    clear_buffer();

    while(packets_tail != packets_head)
    {
      spf_serial_printf("Get %u %u\n", packets_head, packets_tail);


      spi_read_burst(0x00, packets_buf[packets_tail].data.buffer, 16);


      packets_tail = (packets_tail + 1) % 16;
    }


    clear_buffer();


    set_rx_mode();
  }
}

rfm_packet_t* rfm_get_next_packet(void)
{
  rfm_get_packets();

  spf_serial_printf("Read %u\n", packets_read);
  rfm_packet_t *packet = &packets_buf[packets_read];

  packets_read = (packets_read + 1) % 16;

  return packet;
}

uint8_t rfm_get_num_packets(void)
{
  return ((uint16_t)(16 + packets_head - packets_read)) % 16;
}
# 413 "common/src/rfm.c"

# 413 "common/src/rfm.c" 3 4
_Bool 
# 413 "common/src/rfm.c"
    rfm_transmit_packet(rfm_packet_t packet)
{

  set_standby_mode();
  clear_buffer();


  exti_disable_request((1 << 15));
 nvic_disable_irq(7);


  set_dio_irq((1 << 6) | (0 << 4) | (0 << 2) | (2 << 0), (0 << 6) | (0 << 4));
  mask_irq(0xFF);
  unmask_irq(0x08);
  clear_irq(0xFF);







  spi_write_burst(0x00, packet.data.buffer, 16);
# 445 "common/src/rfm.c"
  set_tx_mode();






  
# 452 "common/src/rfm.c" 3 4
 _Bool 
# 452 "common/src/rfm.c"
      sent = 
# 452 "common/src/rfm.c" 3 4
             0
# 452 "common/src/rfm.c"
                  ;
  timeout_init(); while(!timeout(100000, "RFM TX", 0)) { if(gpio_get(((0x50000000U) + 0x00400), (1 << 15))){ sent = 
# 453 "common/src/rfm.c" 3 4
 1
# 453 "common/src/rfm.c"
 ; break; } else{ ; }};


  mask_irq(0xFF);
  clear_irq(0xFF);


  clear_buffer();


  set_sleep_mode();

  return sent;
}

void rfm_set_tx_continuous(void)
{
  spi_write_burst(0x00, random_data, 16);

  clear_buffer();

  uint8_t current = spi_read_single(0x1e);
  spi_write_single(0x1e, current | 0x08);
  set_tx_mode();
}

void rfm_clear_tx_continuous(void)
{
  set_standby_mode();
  spi_write(0x1e, spi_read_single(0x1e) & ~0x08);
}
# 499 "common/src/rfm.c"
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

static void spi_setup(void)
{

  gpio_mode_setup(((0x50000000U) + 0x00000), 0x2, 0x0, (1 << 6));

  gpio_mode_setup(((0x50000000U) + 0x00000), 0x2, 0x0, (1 << 5));
  gpio_mode_setup(((0x50000000U) + 0x00000), 0x2, 0x0, (1 << 7));
  gpio_mode_setup(((0x50000000U) + 0x00000), 0x1, 0x0, (1 << 4));


  gpio_set_output_options(((0x50000000U) + 0x00000), 0x0, 0x1, (1 << 5));
  gpio_set_output_options(((0x50000000U) + 0x00000), 0x0, 0x1, (1 << 7));
  gpio_set_output_options(((0x50000000U) + 0x00000), 0x0, 0x1, (1 << 4));


  gpio_set(((0x50000000U) + 0x00000), (1 << 4));


  gpio_set_af(((0x50000000U) + 0x00000), 0x0, (1 << 6));

  gpio_set_af(((0x50000000U) + 0x00000), 0x0, (1 << 5));
  gpio_set_af(((0x50000000U) + 0x00000), 0x0, (1 << 7));


  rcc_periph_clock_enable(RCC_SPI1);
  rcc_periph_reset_pulse(RST_SPI1);
  spi_disable((((0x40000000U) + 0x10000) + 0x3000));
  spi_init_master((((0x40000000U) + 0x10000) + 0x3000), (0x02 << 3),
                    (0 << 1), (0 << 0),
                    (0 << 11), (0 << 7));
  spi_enable((((0x40000000U) + 0x10000) + 0x3000));
}
# 562 "common/src/rfm.c"
static uint8_t spi_read_single(uint8_t reg)
{
  gpio_clear(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);

  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), reg);
  uint8_t in = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x00);

  gpio_set(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);

  return in;
}

static void spi_read_burst(uint8_t reg, uint8_t *buf, uint8_t len)
{
  gpio_clear(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);

  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), reg);

  for(int i = 0; i < len; i++)
  {
    buf[i] = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x00);
  }

  gpio_set(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);
}

static void spi_write_single(uint8_t reg, uint8_t data)
{

  uint8_t cmd = 0x80 | reg;

  gpio_clear(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);

  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), cmd);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), data);

  gpio_set(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);

  uint8_t curr_data = spi_read_single(reg);



  if(reg == 0x12)
    return;

  timeout_init(); while(!timeout(10000, "RFM SPI Write", ((reg << 16) | data))) { if((curr_data == data)){ ; break; } else{ timers_delay_microseconds(100); curr_data = spi_read_single(reg); }};


}

static void spi_write_burst(uint8_t reg, uint8_t *buf, uint8_t len)
{
  gpio_clear(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);


  uint8_t cmd = 0x80 | reg;

  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), cmd);

  for(int i = 0; i < len; i++)
  {
    spi_xfer((((0x40000000U) + 0x10000) + 0x3000), buf[i]);
  }

  gpio_set(((0x50000000U) + 0x00000), (1 << 4));
  timers_delay_microseconds(1);
}

static void set_frequency(uint32_t frequency_hz)
{

    uint32_t frf = frequency_hz / (32000000.0 / 524288);
    spi_write_single(0x06, (frf >> 16) & 0xff);
    spi_write_single(0x07, (frf >> 8) & 0xff);
    spi_write_single(0x08, frf & 0xff);


}

static void set_dio_irq(uint8_t io0_3, uint8_t io4_5)
{
  spi_write_single(0x40, io0_3);
  spi_write_single(0x41, io4_5);
}

static void set_preamble_length(uint16_t num_sym)
{
    spi_write_single(0x20, num_sym >> 8);
    spi_write_single(0x21, num_sym & 0xff);
}

static void print_registers(void)
{
  uint8_t registers[] = { 0x01, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x014, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x4b, 0x4d};

  uint8_t i;
  for (i = 0; i < sizeof(registers); i++)
  {
   spf_serial_printf("%02x : %02x\n", registers[i], spi_read_single(registers[i]));
  }
}

static void clear_buffer(void)
{
    spi_write_single(0x0d, 0);
    spi_write_single(0x0e, 0);
    spi_write_single(0x0f, 0);
}
# 712 "common/src/rfm.c"
static inline void mask_irq(uint8_t irq)
{
  spi_write_single(0x11, spi_read_single(0x11) | irq);
}

static inline void unmask_irq(uint8_t irq)
{
  spi_write_single(0x11, spi_read_single(0x11) & ~irq);
}

static inline uint8_t get_irq(void)
{
  return spi_read_single(0x12);
}

static inline void clear_irq(uint8_t irq)
{




  spi_write_single(0x12, irq);
}

static inline void set_tx_mode(void)
{
  spi_write_single(0x01, (spi_read_single(0x01) & ~0x07) | 0x03);
}

static inline void set_rx_mode(void)
{
  spi_write_single(0x01, (spi_read_single(0x01) & ~0x07) | 0x05);
}

static inline void set_standby_mode(void)
{
  spi_write_single(0x01, (spi_read_single(0x01) & ~0x07) | 0x01);
}

static inline void set_sleep_mode(void)
{
  spi_write_single(0x01, (spi_read_single(0x01) & ~0x07) | 0x00);
}
# 766 "common/src/rfm.c"
void exti4_15_isr(void)
{
  uint16_t timer = timers_micros();

  exti_reset_request((1 << 15));
  exti_reset_request((1 << 15));


  packets_buf[packets_head].flags = get_irq();
  clear_irq(0xFF);
  clear_irq(0xFF);


  packets_buf[packets_head].rssi = spi_read_single(0x1a);
  packets_buf[packets_head].rssi -= 137;
  packets_buf[packets_head].snr = spi_read_single(0x19) / 4;


  packets_buf[packets_head].crc_ok = !(packets_buf[packets_head].flags & 0x20);

  packets_head = (packets_head + 1) % 16;

  uint16_t time = timers_micros() - timer;

}
