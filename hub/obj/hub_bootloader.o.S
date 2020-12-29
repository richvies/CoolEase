# 1 "hub/src/hub_bootloader.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hub/src/hub_bootloader.c"
# 15 "hub/src/hub_bootloader.c"
# 1 "hub/include/hub/hub_bootloader.h" 1
# 32 "hub/include/hub/hub_bootloader.h"
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
# 33 "hub/include/hub/hub_bootloader.h" 2
# 16 "hub/src/hub_bootloader.c" 2

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
# 18 "hub/src/hub_bootloader.c" 2
# 47 "hub/src/hub_bootloader.c"
int main(void)
{


    boot_jump_to_application(0x08004000);

    return 0;
}
