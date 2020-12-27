# 1 "common/src/bootloader_utils.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "common/src/bootloader_utils.c"
# 15 "common/src/bootloader_utils.c"
# 1 "common/include/common/bootloader_utils.h" 1
# 32 "common/include/common/bootloader_utils.h"
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
# 33 "common/include/common/bootloader_utils.h" 2
# 51 "common/include/common/bootloader_utils.h"

# 51 "common/include/common/bootloader_utils.h"
void boot_deinit(void);
void boot_jump_to_application(uint32_t address);
# 16 "common/src/bootloader_utils.c" 2

# 1 "libopencm3/include/libopencm3/cm3/cortex.h" 1
# 36 "libopencm3/include/libopencm3/cm3/cortex.h"
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 37 "libopencm3/include/libopencm3/cm3/cortex.h" 2







static inline void ccm_enable_interrupts(void)
{
 __asm__ volatile ("CPSIE I\n");
}






static inline void cm_disable_interrupts(void)
{
 __asm__ volatile ("CPSID I\n");
}






static inline void cm_enable_faults(void)
{
 __asm__ volatile ("CPSIE F\n");
}






static inline void cm_disable_faults(void)
{
 __asm__ volatile ("CPSID F\n");
}
# 86 "libopencm3/include/libopencm3/cm3/cortex.h"
__attribute__((always_inline))
static inline 
# 87 "libopencm3/include/libopencm3/cm3/cortex.h" 3 4
             _Bool 
# 87 "libopencm3/include/libopencm3/cm3/cortex.h"
                  cm_is_masked_interrupts(void)
{
 register uint32_t result;
 __asm__ volatile ("MRS %0, PRIMASK" : "=r" (result));
 return result;
}
# 121 "libopencm3/include/libopencm3/cm3/cortex.h"
__attribute__((always_inline))
static inline uint32_t cm_mask_interrupts(uint32_t mask)
{
 register uint32_t old;
 __asm__ __volatile__("MRS %0, PRIMASK" : "=r" (old));
 __asm__ __volatile__("" : : : "memory");
 __asm__ __volatile__("MSR PRIMASK, %0" : : "r" (mask));
 return old;
}
# 166 "libopencm3/include/libopencm3/cm3/cortex.h"
static inline uint32_t __cm_atomic_set(uint32_t *val)
{
 return cm_mask_interrupts(*val);
}
# 18 "common/src/bootloader_utils.c" 2
# 1 "libopencm3/include/libopencm3/cm3/scb.h" 1
# 34 "libopencm3/include/libopencm3/cm3/scb.h"
# 1 "libopencm3/include/libopencm3/cm3/memorymap.h" 1
# 35 "libopencm3/include/libopencm3/cm3/scb.h" 2
# 1 "libopencm3/include/libopencm3/cm3/common.h" 1
# 36 "libopencm3/include/libopencm3/cm3/scb.h" 2
# 461 "libopencm3/include/libopencm3/cm3/scb.h"


struct scb_exception_stack_frame {
 uint32_t r0;
 uint32_t r1;
 uint32_t r2;
 uint32_t r3;
 uint32_t r12;
 uint32_t lr;
 uint32_t pc;
 uint32_t xpsr;
} __attribute__((packed));







void scb_reset_system(void) __attribute__((noreturn));








# 19 "common/src/bootloader_utils.c" 2
# 46 "common/src/bootloader_utils.c"
void boot_deinit(void)
{

}

void boot_jump_to_application(uint32_t address)
{

  __asm__ volatile ("CPSID I\n");


  (*(volatile uint32_t *)((((0xE0000000U) + 0xE000) + 0x0D00) + 0x08)) = address;


  __asm__("msr msp, %0" : : "r" ((*(volatile uint32_t *)(address))));


  void (*start)(void) = (void*)(*(volatile uint32_t *)(address + 4));


  __asm__ volatile ("CPSIE I\n");

  start();

  while(1){ };
}
