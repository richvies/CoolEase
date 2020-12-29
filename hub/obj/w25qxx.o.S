# 1 "hub/src/w25qxx.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hub/src/w25qxx.c"
# 1 "hub/include/hub/w25qxx.h" 1



# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 5 "hub/include/hub/w25qxx.h" 2
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
# 6 "hub/include/hub/w25qxx.h" 2


# 7 "hub/include/hub/w25qxx.h"
typedef enum
{
 W25Q10 = 1,
 W25Q20,
 W25Q40,
 W25Q80,
 W25Q16,
 W25Q32,
 W25Q64,
 W25Q128,
 W25Q256,
 W25Q512,

} W25_ID_t;

typedef struct
{
 W25_ID_t ID;
 uint8_t UniqID[8];
 uint16_t PageSize;
 uint32_t PageCount;
 uint32_t SectorSize;
 uint32_t SectorCount;
 uint32_t BlockSize;
 uint32_t BlockCount;
 uint32_t CapacityInKiloByte;
 uint8_t StatusRegister1;
 uint8_t StatusRegister2;
 uint8_t StatusRegister3;
 uint8_t Lock;

} w25_t;

extern w25_t w25;




# 44 "hub/include/hub/w25qxx.h" 3 4
_Bool 
# 44 "hub/include/hub/w25qxx.h"
    w25_Init(void);



uint32_t w25_ReadID(void);
void w25_ReadUniqID(void);
void w25_WriteEnable(void);
void w25_WriteDisable(void);
void w25_WaitForWriteEnd(void);
uint8_t w25_ReadStatusRegister(uint8_t SelectStatusRegister_1_2_3);
void w25_WriteStatusRegister(uint8_t SelectStatusRegister_1_2_3, uint8_t Data);

void w25_EraseChip(void);
void w25_EraseSector(uint32_t SectorAddr);
void w25_EraseBlock(uint32_t BlockAddr);

uint32_t w25_PageToSector(uint32_t PageAddress);
uint32_t w25_PageToBlock(uint32_t PageAddress);
uint32_t w25_SectorToBlock(uint32_t SectorAddress);
uint32_t w25_SectorToPage(uint32_t SectorAddress);
uint32_t w25_BlockToPage(uint32_t BlockAddress);


# 66 "hub/include/hub/w25qxx.h" 3 4
_Bool 
# 66 "hub/include/hub/w25qxx.h"
    w25_IsEmptyPage(uint32_t Page_Address, uint32_t OffsetInByte, uint32_t NumByteToCheck_up_to_PageSize);

# 67 "hub/include/hub/w25qxx.h" 3 4
_Bool 
# 67 "hub/include/hub/w25qxx.h"
    w25_IsEmptySector(uint32_t Sector_Address, uint32_t OffsetInByte, uint32_t NumByteToCheck_up_to_SectorSize);

# 68 "hub/include/hub/w25qxx.h" 3 4
_Bool 
# 68 "hub/include/hub/w25qxx.h"
    w25_IsEmptyBlock(uint32_t Block_Address, uint32_t OffsetInByte, uint32_t NumByteToCheck_up_to_BlockSize);

void w25_WriteByte(uint8_t pBuffer, uint32_t Bytes_Address);
void w25_WritePage(uint8_t *pBuffer, uint32_t Page_Address, uint32_t OffsetInByte, uint32_t NumByteToWrite_up_to_PageSize);
void w25_WriteSector(uint8_t *pBuffer, uint32_t Sector_Address, uint32_t OffsetInByte, uint32_t NumByteToWrite_up_to_SectorSize);
void w25_WriteBlock(uint8_t *pBuffer, uint32_t Block_Address, uint32_t OffsetInByte, uint32_t NumByteToWrite_up_to_BlockSize);

void w25_ReadByte(uint8_t *pBuffer, uint32_t Bytes_Address);
void w25_ReadBytes(uint8_t *pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead);
void w25_ReadPage(uint8_t *pBuffer, uint32_t Page_Address, uint32_t OffsetInByte, uint32_t NumByteToRead_up_to_PageSize);
void w25_ReadSector(uint8_t *pBuffer, uint32_t Sector_Address, uint32_t OffsetInByte, uint32_t NumByteToRead_up_to_SectorSize);
void w25_ReadBlock(uint8_t *pBuffer, uint32_t Block_Address, uint32_t OffsetInByte, uint32_t NumByteToRead_up_to_BlockSize);
# 2 "hub/src/w25qxx.c" 2




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
# 7 "hub/src/w25qxx.c" 2
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
# 8 "hub/src/w25qxx.c" 2
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
# 9 "hub/src/w25qxx.c" 2
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
# 10 "hub/src/w25qxx.c" 2
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
# 11 "hub/src/w25qxx.c" 2
# 1 "libopencm3/include/libopencm3/stm32/syscfg.h" 1
# 34 "libopencm3/include/libopencm3/stm32/syscfg.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/syscfg.h" 1
# 130 "libopencm3/include/libopencm3/stm32/l0/syscfg.h"



# 35 "libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 12 "hub/src/w25qxx.c" 2
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

# 13 "hub/src/w25qxx.c" 2

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





typedef struct
{
 
# 15 "common/include/common/board_defs.h" 3 4
_Bool 
# 15 "common/include/common/board_defs.h"
       msg_pend;
 
# 16 "common/include/common/board_defs.h" 3 4
_Bool 
# 16 "common/include/common/board_defs.h"
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
# 15 "hub/src/w25qxx.c" 2
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
# 16 "hub/src/w25qxx.c" 2
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
# 17 "hub/src/w25qxx.c" 2







w25_t w25;

static void clock_setup(void);
static void spi_setup(void);


# 29 "hub/src/w25qxx.c" 3 4
_Bool 
# 29 "hub/src/w25qxx.c"
    w25_Init(void)
{
 clock_setup();
 spi_setup();

 w25.Lock=1;
 timers_delay_microseconds(100);
 gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(100);

 uint32_t id;
 spf_serial_printf("w25 Init Begin...\r\n");

 id=w25_ReadID();

 spf_serial_printf("w25 ID:0x%X\r\n",id);
 switch(id&0x0000FFFF)
 {
  case 0x401A:
   w25.ID=W25Q512;
   w25.BlockCount=1024;
   spf_serial_printf("w25 Chip: w25q512\r\n");
  break;
  case 0x4019:
   w25.ID=W25Q256;
   w25.BlockCount=512;
   spf_serial_printf("w25 Chip: w25q256\r\n");
  break;
  case 0x4018:
   w25.ID=W25Q128;
   w25.BlockCount=256;
   spf_serial_printf("w25 Chip: w25q128\r\n");
  break;
  case 0x4017:
   w25.ID=W25Q64;
   w25.BlockCount=128;
   spf_serial_printf("w25 Chip: w25q64\r\n");
  break;
  case 0x4016:
   w25.ID=W25Q32;
   w25.BlockCount=64;
   spf_serial_printf("w25 Chip: w25q32\r\n");
  break;
  case 0x4015:
   w25.ID=W25Q16;
   w25.BlockCount=32;
   spf_serial_printf("w25 Chip: w25q16\r\n");
  break;
  case 0x4014:
   w25.ID=W25Q80;
   w25.BlockCount=16;
   spf_serial_printf("w25 Chip: w25q80\r\n");
  break;
  case 0x4013:
   w25.ID=W25Q40;
   w25.BlockCount=8;
   spf_serial_printf("w25 Chip: w25q40\r\n");
  break;
  case 0x4012:
   w25.ID=W25Q20;
   w25.BlockCount=4;
   spf_serial_printf("w25 Chip: w25q20\r\n");
  break;
  case 0x4011:
   w25.ID=W25Q10;
   w25.BlockCount=2;
   spf_serial_printf("w25 Chip: w25q10\r\n");
  break;
  default:
    spf_serial_printf("w25 Unknown ID\r\n");
   w25.Lock=0;
   return 
# 100 "hub/src/w25qxx.c" 3 4
         0
# 100 "hub/src/w25qxx.c"
              ;

 }

 w25.PageSize=256;
 w25.SectorSize=0x1000;
 w25.SectorCount=w25.BlockCount*16;
 w25.PageCount=(w25.SectorCount*w25.SectorSize)/w25.PageSize;
 w25.BlockSize=w25.SectorSize*16;
 w25.CapacityInKiloByte=(w25.SectorCount*w25.SectorSize)/1024;

 w25_ReadUniqID();
 w25_ReadStatusRegister(1);
 w25_ReadStatusRegister(2);
 w25_ReadStatusRegister(3);
 spf_serial_printf("w25 Page Size: %d Bytes\r\n",w25.PageSize);
 spf_serial_printf("w25 Sector Size: %d Bytes\r\n",w25.SectorSize);
 spf_serial_printf("w25 Sector Count: %d\r\n",w25.SectorCount);
 spf_serial_printf("w25 Block Size: %d Bytes\r\n",w25.BlockSize);
 spf_serial_printf("w25 Block Count: %d\r\n",w25.BlockCount);
 spf_serial_printf("w25 Capacity: %d KiloBytes\r\n",w25.CapacityInKiloByte);
 spf_serial_printf("w25 Init Done\r\n");

 w25.Lock=0;

 return 
# 125 "hub/src/w25qxx.c" 3 4
       1
# 125 "hub/src/w25qxx.c"
           ;
}



uint32_t w25_ReadID(void)
{
 uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
 timers_delay_microseconds(1);

 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x9F);
 Temp0 = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
 Temp1 = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
 Temp2 = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);

 gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
   return Temp;
}
void w25_ReadUniqID(void)
{
 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
 timers_delay_microseconds(1);

 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x4B);

 for(uint8_t i=0;i<4;i++)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);

 for(uint8_t i=0;i<8;i++)
  w25.UniqID[i] = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
}



void w25_WriteEnable(void)
{
 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
 timers_delay_microseconds(1);

 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x06);

 gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
}
void w25_WriteDisable(void)
{
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x04);
     gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
 timers_delay_microseconds(1);
}
void w25_WaitForWriteEnd(void)
{
 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x05);

 do
 {
  w25.StatusRegister1 = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
  timers_delay_microseconds(10);
 }while ((w25.StatusRegister1 & 0x01) == 0x01);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
}



uint8_t w25_ReadStatusRegister(uint8_t SelectStatusRegister_1_2_3)
{
 uint8_t status=0;

 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 if(SelectStatusRegister_1_2_3==1)
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x05);
  status=spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
  w25.StatusRegister1 = status;
 }
 else if(SelectStatusRegister_1_2_3==2)
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x35);
  status=spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
  w25.StatusRegister2 = status;
 }
 else
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x15);
  status=spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
  w25.StatusRegister3 = status;
 }

 gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 return status;
}
void w25_WriteStatusRegister(uint8_t SelectStatusRegister_1_2_3, uint8_t Data)
{
 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 if(SelectStatusRegister_1_2_3==1)
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x01);
  w25.StatusRegister1 = Data;
 }
 else if(SelectStatusRegister_1_2_3==2)
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x31);
  w25.StatusRegister2 = Data;
 }
 else
 {
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x11);
  w25.StatusRegister3 = Data;
 }

 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), Data);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
}




void w25_EraseChip(void)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;


 spf_serial_printf("w25 EraseChip Begin...\r\n");

 w25_WriteEnable();

 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xC7);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 w25_WaitForWriteEnd();



 timers_delay_microseconds(10);

 w25.Lock=0;
}
void w25_EraseSector(uint32_t SectorAddr)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;

 spf_serial_printf("w25 EraseSector %d Begin...\r\n",SectorAddr);
 w25_WaitForWriteEnd();
 SectorAddr = SectorAddr * w25.SectorSize;
  w25_WriteEnable();
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x20);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (SectorAddr & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (SectorAddr & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (SectorAddr & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), SectorAddr & 0xFF);
    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  w25_WaitForWriteEnd();

 timers_delay_microseconds(1);
 w25.Lock=0;
}
void w25_EraseBlock(uint32_t BlockAddr)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;
 spf_serial_printf("w25 EraseBlock %d Begin...\r\n",BlockAddr);

 w25_WaitForWriteEnd();
 BlockAddr = BlockAddr * w25.SectorSize*16;
  w25_WriteEnable();
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xD8);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (BlockAddr & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (BlockAddr & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (BlockAddr & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), BlockAddr & 0xFF);
    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  w25_WaitForWriteEnd();

 timers_delay_microseconds(1);
 w25.Lock=0;
}



uint32_t w25_PageToSector(uint32_t PageAddress)
{
 return ((PageAddress*w25.PageSize)/w25.SectorSize);
}
uint32_t w25_PageToBlock(uint32_t PageAddress)
{
 return ((PageAddress*w25.PageSize)/w25.BlockSize);
}
uint32_t w25_SectorToBlock(uint32_t SectorAddress)
{
 return ((SectorAddress*w25.SectorSize)/w25.BlockSize);
}
uint32_t w25_SectorToPage(uint32_t SectorAddress)
{
 return (SectorAddress*w25.SectorSize)/w25.PageSize;
}
uint32_t w25_BlockToPage(uint32_t BlockAddress)
{
 return (BlockAddress*w25.BlockSize)/w25.PageSize;
}




# 369 "hub/src/w25qxx.c" 3 4
_Bool 
# 369 "hub/src/w25qxx.c"
     w25_IsEmptyPage(uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_PageSize)
{
 while(w25.Lock==1)
 timers_delay_microseconds(1);
 w25.Lock=1;
 if(((NumByteToCheck_up_to_PageSize+OffsetInByte)>w25.PageSize)||(NumByteToCheck_up_to_PageSize==0))
  NumByteToCheck_up_to_PageSize=w25.PageSize-OffsetInByte;
 spf_serial_printf("w25 CheckPage:%d, Offset:%d, Bytes:%d begin...\r\n",Page_Address,OffsetInByte,NumByteToCheck_up_to_PageSize);

 uint8_t pBuffer[32];
 uint32_t WorkAddress;
 uint32_t i;
 for(i=OffsetInByte; i<w25.PageSize; i+=sizeof(pBuffer))
 {
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  WorkAddress=(i+Page_Address*w25.PageSize);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
  if(w25.ID>=W25Q256)
  {
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
  }
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

     gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  for(uint8_t x=0;x<sizeof(pBuffer);x++)
  {
   if(pBuffer[x]!=0xFF)
   {

   }

  }
 }
 if((w25.PageSize+OffsetInByte)%sizeof(pBuffer)!=0)
 {
  i-=sizeof(pBuffer);
  for( ; i<w25.PageSize; i++)
  {
   gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   WorkAddress=(i+Page_Address*w25.PageSize);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
   if(w25.ID>=W25Q256)
    spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

      gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   if(pBuffer[0]!=0xFF)
   {

   }

  }
 }

 w25.Lock=0;
 return 
# 434 "hub/src/w25qxx.c" 3 4
       1
# 434 "hub/src/w25qxx.c"
           ;


 w25.Lock=0;
 return 
# 438 "hub/src/w25qxx.c" 3 4
       0
# 438 "hub/src/w25qxx.c"
            ;
}

# 440 "hub/src/w25qxx.c" 3 4
_Bool 
# 440 "hub/src/w25qxx.c"
     w25_IsEmptySector(uint32_t Sector_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_SectorSize)
{
 while(w25.Lock==1)
 timers_delay_microseconds(1);
 w25.Lock=1;
 if((NumByteToCheck_up_to_SectorSize>w25.SectorSize)||(NumByteToCheck_up_to_SectorSize==0))
  NumByteToCheck_up_to_SectorSize=w25.SectorSize;
 spf_serial_printf("w25 CheckSector:%d, Offset:%d, Bytes:%d begin...\r\n",Sector_Address,OffsetInByte,NumByteToCheck_up_to_SectorSize);

 uint8_t pBuffer[32];
 uint32_t WorkAddress;
 uint32_t i;
 for(i=OffsetInByte; i<w25.SectorSize; i+=sizeof(pBuffer))
 {
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  WorkAddress=(i+Sector_Address*w25.SectorSize);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
  if(w25.ID>=W25Q256)
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

     gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  for(uint8_t x=0;x<sizeof(pBuffer);x++)
  {
   if(pBuffer[x]!=0xFF)
   {

   }

  }
 }
 if((w25.SectorSize+OffsetInByte)%sizeof(pBuffer)!=0)
 {
  i-=sizeof(pBuffer);
  for( ; i<w25.SectorSize; i++)
  {
   gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   WorkAddress=(i+Sector_Address*w25.SectorSize);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
   if(w25.ID>=W25Q256)
    spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

      gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   if(pBuffer[0]!=0xFF)
   {

   }

  }
 }

 w25.Lock=0;
 return 
# 503 "hub/src/w25qxx.c" 3 4
       1
# 503 "hub/src/w25qxx.c"
           ;

 w25.Lock=0;
 return 
# 506 "hub/src/w25qxx.c" 3 4
       0
# 506 "hub/src/w25qxx.c"
            ;
}

# 508 "hub/src/w25qxx.c" 3 4
_Bool 
# 508 "hub/src/w25qxx.c"
     w25_IsEmptyBlock(uint32_t Block_Address,uint32_t OffsetInByte,uint32_t NumByteToCheck_up_to_BlockSize)
{
 while(w25.Lock==1)
 timers_delay_microseconds(1);
 w25.Lock=1;
 if((NumByteToCheck_up_to_BlockSize>w25.BlockSize)||(NumByteToCheck_up_to_BlockSize==0))
  NumByteToCheck_up_to_BlockSize=w25.BlockSize;
 spf_serial_printf("w25 CheckBlock:%d, Offset:%d, Bytes:%d begin...\r\n",Block_Address,OffsetInByte,NumByteToCheck_up_to_BlockSize);

 uint8_t pBuffer[32];
 uint32_t WorkAddress;
 uint32_t i;
 for(i=OffsetInByte; i<w25.BlockSize; i+=sizeof(pBuffer))
 {
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  WorkAddress=(i+Block_Address*w25.BlockSize);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
  if(w25.ID>=W25Q256)
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

     gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  for(uint8_t x=0;x<sizeof(pBuffer);x++)
  {
   if(pBuffer[x]!=0xFF){}

  }
 }
 if((w25.BlockSize+OffsetInByte)%sizeof(pBuffer)!=0)
 {
  i-=sizeof(pBuffer);
  for( ; i<w25.BlockSize; i++)
  {
   gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   WorkAddress=(i+Block_Address*w25.BlockSize);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
   if(w25.ID>=W25Q256)
    spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF000000) >> 24);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF0000) >> 16);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WorkAddress & 0xFF00) >> 8);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WorkAddress & 0xFF);
   spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

      gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
   if(pBuffer[0]!=0xFF){}

  }
 }


 w25.Lock=0;
 return 
# 566 "hub/src/w25qxx.c" 3 4
       1
# 566 "hub/src/w25qxx.c"
           ;



 w25.Lock=0;
 return 
# 571 "hub/src/w25qxx.c" 3 4
       0
# 571 "hub/src/w25qxx.c"
            ;
}



void w25_WriteByte(uint8_t pBuffer, uint32_t WriteAddr_inBytes)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;


 spf_serial_printf("w25 WriteByte 0x%02X at address %d begin...",pBuffer,WriteAddr_inBytes);

 w25_WaitForWriteEnd();
  w25_WriteEnable();
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x02);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WriteAddr_inBytes & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WriteAddr_inBytes & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (WriteAddr_inBytes & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), WriteAddr_inBytes & 0xFF);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), pBuffer);
    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  w25_WaitForWriteEnd();

 w25.Lock=0;
}
void w25_WritePage(uint8_t *pBuffer ,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToWrite_up_to_PageSize)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;
 if(((NumByteToWrite_up_to_PageSize+OffsetInByte)>w25.PageSize)||(NumByteToWrite_up_to_PageSize==0))
  NumByteToWrite_up_to_PageSize=w25.PageSize-OffsetInByte;
 if((OffsetInByte+NumByteToWrite_up_to_PageSize) > w25.PageSize)
  NumByteToWrite_up_to_PageSize = w25.PageSize-OffsetInByte;
 spf_serial_printf("w25 WritePage:%d, Offset:%d ,Writes %d Bytes, begin...\r\n",Page_Address,OffsetInByte,NumByteToWrite_up_to_PageSize);


 w25_WaitForWriteEnd();
  w25_WriteEnable();
  gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x02);
 Page_Address = (Page_Address*w25.PageSize)+OffsetInByte;
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address & 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), Page_Address&0xFF);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  w25_WaitForWriteEnd();


 for(uint32_t i=0;i<NumByteToWrite_up_to_PageSize ; i++)
 {
  if((i%8==0)&&(i>2))
  {
   spf_serial_printf("\r\n");
   timers_delay_microseconds(10);
  }
  spf_serial_printf("0x%02X,",pBuffer[i]);
 }
 spf_serial_printf("\r\n");

 timers_delay_microseconds(100);

 timers_delay_microseconds(1);
 w25.Lock=0;
}
void w25_WriteSector(uint8_t *pBuffer ,uint32_t Sector_Address,uint32_t OffsetInByte ,uint32_t NumByteToWrite_up_to_SectorSize)
{
 if((NumByteToWrite_up_to_SectorSize>w25.SectorSize)||(NumByteToWrite_up_to_SectorSize==0))
  NumByteToWrite_up_to_SectorSize=w25.SectorSize;
 spf_serial_printf("+++w25 WriteSector:%d, Offset:%d ,Write %d Bytes, begin...\r\n",Sector_Address,OffsetInByte,NumByteToWrite_up_to_SectorSize);

 if(OffsetInByte>=w25.SectorSize)
 {
  spf_serial_printf("---w25 WriteSector Faild!\r\n");

  return;
 }
 uint32_t StartPage;
 int32_t BytesToWrite;
 uint32_t LocalOffset;
 if((OffsetInByte+NumByteToWrite_up_to_SectorSize) > w25.SectorSize)
  BytesToWrite = w25.SectorSize-OffsetInByte;
 else
  BytesToWrite = NumByteToWrite_up_to_SectorSize;
 StartPage = w25_SectorToPage(Sector_Address)+(OffsetInByte/w25.PageSize);
 LocalOffset = OffsetInByte%w25.PageSize;
 do
 {
  w25_WritePage(pBuffer,StartPage,LocalOffset,BytesToWrite);
  StartPage++;
  BytesToWrite-=w25.PageSize-LocalOffset;
  pBuffer += w25.PageSize - LocalOffset;
  LocalOffset=0;
 }while(BytesToWrite>0);
 spf_serial_printf("---w25 WriteSector Done\r\n");

}
void w25_WriteBlock (uint8_t* pBuffer ,uint32_t Block_Address ,uint32_t OffsetInByte ,uint32_t NumByteToWrite_up_to_BlockSize)
{
 if((NumByteToWrite_up_to_BlockSize>w25.BlockSize)||(NumByteToWrite_up_to_BlockSize==0))
  NumByteToWrite_up_to_BlockSize=w25.BlockSize;
 spf_serial_printf("+++w25 WriteBlock:%d, Offset:%d ,Write %d Bytes, begin...\r\n",Block_Address,OffsetInByte,NumByteToWrite_up_to_BlockSize);

 if(OffsetInByte>=w25.BlockSize)
 {
  spf_serial_printf("---w25 WriteBlock Faild!\r\n");

  return;
 }
 uint32_t StartPage;
 int32_t BytesToWrite;
 uint32_t LocalOffset;
 if((OffsetInByte+NumByteToWrite_up_to_BlockSize) > w25.BlockSize)
  BytesToWrite = w25.BlockSize-OffsetInByte;
 else
  BytesToWrite = NumByteToWrite_up_to_BlockSize;
 StartPage = w25_BlockToPage(Block_Address)+(OffsetInByte/w25.PageSize);
 LocalOffset = OffsetInByte%w25.PageSize;
 do
 {
  w25_WritePage(pBuffer,StartPage,LocalOffset,BytesToWrite);
  StartPage++;
  BytesToWrite-=w25.PageSize-LocalOffset;
  pBuffer += w25.PageSize - LocalOffset;
  LocalOffset=0;
 }while(BytesToWrite>0);
 spf_serial_printf("---w25 WriteBlock Done\r\n");

}



void w25_ReadByte(uint8_t *pBuffer,uint32_t Bytes_Address)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;


 spf_serial_printf("w25 ReadByte at address %d begin...\r\n",Bytes_Address);

 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Bytes_Address & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Bytes_Address & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Bytes_Address& 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), Bytes_Address & 0xFF);
 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);
 *pBuffer = spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0xA5);
    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);

 w25.Lock=0;
}
void w25_ReadBytes(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumByteToRead)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;


 spf_serial_printf("w25 ReadBytes at Address:%d, %d Bytes  begin...\r\n",ReadAddr,NumByteToRead);

 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (ReadAddr & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (ReadAddr & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (ReadAddr& 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), ReadAddr & 0xFF);
 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);


 for(uint32_t i=0;i<NumByteToRead ; i++)
 {
  if((i%8==0)&&(i>2))
  {
   spf_serial_printf("\r\n");
   timers_delay_microseconds(10);
  }
  spf_serial_printf("0x%02X,",pBuffer[i]);
 }
 spf_serial_printf("\r\n");

 timers_delay_microseconds(100);

 timers_delay_microseconds(1);
 w25.Lock=0;
}
void w25_ReadPage(uint8_t *pBuffer,uint32_t Page_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_PageSize)
{
 while(w25.Lock==1)
  timers_delay_microseconds(1);
 w25.Lock=1;
 if((NumByteToRead_up_to_PageSize>w25.PageSize)||(NumByteToRead_up_to_PageSize==0))
  NumByteToRead_up_to_PageSize=w25.PageSize;
 if((OffsetInByte+NumByteToRead_up_to_PageSize) > w25.PageSize)
  NumByteToRead_up_to_PageSize = w25.PageSize-OffsetInByte;
 spf_serial_printf("w25 ReadPage:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Page_Address,OffsetInByte,NumByteToRead_up_to_PageSize);


 Page_Address = Page_Address*w25.PageSize+OffsetInByte;
 gpio_clear(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);
 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0x0B);
 if(w25.ID>=W25Q256)
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address & 0xFF000000) >> 24);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address & 0xFF0000) >> 16);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), (Page_Address& 0xFF00) >> 8);
  spi_xfer((((0x40000000U) + 0x10000) + 0x3000), Page_Address & 0xFF);
 spi_xfer((((0x40000000U) + 0x10000) + 0x3000), 0);

    gpio_set(((0x50000000U) + 0x00400), (1 << 6));
   timers_delay_microseconds(1);


 for(uint32_t i=0;i<NumByteToRead_up_to_PageSize ; i++)
 {
  if((i%8==0)&&(i>2))
  {
   spf_serial_printf("\r\n");
   timers_delay_microseconds(10);
  }
  spf_serial_printf("0x%02X,",pBuffer[i]);
 }
 spf_serial_printf("\r\n");

 timers_delay_microseconds(100);

 timers_delay_microseconds(1);
 w25.Lock=0;
}
void w25_ReadSector(uint8_t *pBuffer,uint32_t Sector_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_SectorSize)
{
 if((NumByteToRead_up_to_SectorSize>w25.SectorSize)||(NumByteToRead_up_to_SectorSize==0))
  NumByteToRead_up_to_SectorSize=w25.SectorSize;
 spf_serial_printf("+++w25 ReadSector:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Sector_Address,OffsetInByte,NumByteToRead_up_to_SectorSize);

 if(OffsetInByte>=w25.SectorSize)
 {
  spf_serial_printf("---w25 ReadSector Faild!\r\n");

  return;
 }
 uint32_t StartPage;
 int32_t BytesToRead;
 uint32_t LocalOffset;
 if((OffsetInByte+NumByteToRead_up_to_SectorSize) > w25.SectorSize)
  BytesToRead = w25.SectorSize-OffsetInByte;
 else
  BytesToRead = NumByteToRead_up_to_SectorSize;
 StartPage = w25_SectorToPage(Sector_Address)+(OffsetInByte/w25.PageSize);
 LocalOffset = OffsetInByte%w25.PageSize;
 do
 {
  w25_ReadPage(pBuffer,StartPage,LocalOffset,BytesToRead);
  StartPage++;
  BytesToRead-=w25.PageSize-LocalOffset;
  pBuffer += w25.PageSize - LocalOffset;
  LocalOffset=0;
 }while(BytesToRead>0);
 spf_serial_printf("---w25 ReadSector Done\r\n");

}
void w25_ReadBlock(uint8_t* pBuffer,uint32_t Block_Address,uint32_t OffsetInByte,uint32_t NumByteToRead_up_to_BlockSize)
{
 if((NumByteToRead_up_to_BlockSize>w25.BlockSize)||(NumByteToRead_up_to_BlockSize==0))
  NumByteToRead_up_to_BlockSize=w25.BlockSize;
 spf_serial_printf("+++w25 ReadBlock:%d, Offset:%d ,Read %d Bytes, begin...\r\n",Block_Address,OffsetInByte,NumByteToRead_up_to_BlockSize);

 if(OffsetInByte>=w25.BlockSize)
 {
  spf_serial_printf("w25 ReadBlock Faild!\r\n");

  return;
 }
 uint32_t StartPage;
 int32_t BytesToRead;
 uint32_t LocalOffset;
 if((OffsetInByte+NumByteToRead_up_to_BlockSize) > w25.BlockSize)
  BytesToRead = w25.BlockSize-OffsetInByte;
 else
  BytesToRead = NumByteToRead_up_to_BlockSize;
 StartPage = w25_BlockToPage(Block_Address)+(OffsetInByte/w25.PageSize);
 LocalOffset = OffsetInByte%w25.PageSize;
 do
 {
  w25_ReadPage(pBuffer,StartPage,LocalOffset,BytesToRead);
  StartPage++;
  BytesToRead-=w25.PageSize-LocalOffset;
  pBuffer += w25.PageSize - LocalOffset;
  LocalOffset=0;
 }while(BytesToRead>0);
 spf_serial_printf("---w25 ReadBlock Done\r\n");

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
static void spi_setup(void)
{

  gpio_mode_setup(((0x50000000U) + 0x00400), 0x2, 0x0, (1 << 4));

  gpio_mode_setup(((0x50000000U) + 0x00400), 0x2, 0x0, (1 << 3));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x2, 0x0, (1 << 5));
  gpio_mode_setup(((0x50000000U) + 0x00400), 0x1, 0x0, (1 << 6));


  gpio_set_output_options(((0x50000000U) + 0x00400), 0x0, 0x1, (1 << 3));
  gpio_set_output_options(((0x50000000U) + 0x00400), 0x0, 0x1, (1 << 5));
  gpio_set_output_options(((0x50000000U) + 0x00400), 0x0, 0x1, (1 << 6));


  gpio_set(((0x50000000U) + 0x00400), (1 << 6));


  gpio_set_af(((0x50000000U) + 0x00400), 0x0, (1 << 4));

  gpio_set_af(((0x50000000U) + 0x00400), 0x0, (1 << 3));
  gpio_set_af(((0x50000000U) + 0x00400), 0x0, (1 << 5));


  rcc_periph_clock_enable(RCC_SPI1);
  rcc_periph_reset_pulse(RST_SPI1);
  spi_disable((((0x40000000U) + 0x10000) + 0x3000));
  spi_init_master((((0x40000000U) + 0x10000) + 0x3000), (0x02 << 3),
                    (0 << 1), (0 << 0),
                    (0 << 11), (0 << 7));
  spi_enable((((0x40000000U) + 0x10000) + 0x3000));
}
