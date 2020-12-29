# 1 "common/src/printf.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "common/src/printf.c"
# 33 "common/src/printf.c"
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
# 34 "common/src/printf.c" 2

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 36 "common/src/printf.c" 2
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
# 37 "common/src/printf.c" 2
# 114 "common/src/printf.c"
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/float.h" 1 3 4
# 115 "common/src/printf.c" 2





# 119 "common/src/printf.c"
typedef void (*out_fct_type)(char character, void* buffer, size_t idx, size_t maxlen);



typedef struct {
  void (*fct)(char character, void* arg);
  void* arg;
} out_fct_wrap_type;



static inline void _out_buffer(char character, void* buffer, size_t idx, size_t maxlen)
{
  if (idx < maxlen) {
    ((char*)buffer)[idx] = character;
  }
}



static inline void _out_null(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)character; (void)buffer; (void)idx; (void)maxlen;
}



static inline void _out_char_spf(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    _putchar_spf(character);
  }
}

static inline void _out_char_sim(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    _putchar_sim(character);
  }
}

static inline void _out_char_log(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    _putchar_log(character);
  }
}


static inline void _out_fct(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)idx; (void)maxlen;
  if (character) {

    ((out_fct_wrap_type*)buffer)->fct(character, ((out_fct_wrap_type*)buffer)->arg);
  }
}




static inline unsigned int _strnlen_s(const char* str, size_t maxsize)
{
  const char* s;
  for (s = str; *s && maxsize--; ++s);
  return (unsigned int)(s - str);
}




static inline 
# 193 "common/src/printf.c" 3 4
             _Bool 
# 193 "common/src/printf.c"
                  _is_digit(char ch)
{
  return (ch >= '0') && (ch <= '9');
}



static unsigned int _atoi(const char** str)
{
  unsigned int i = 0U;
  while (_is_digit(**str)) {
    i = i * 10U + (unsigned int)(*((*str)++) - '0');
  }
  return i;
}



static size_t _out_rev(out_fct_type out, char* buffer, size_t idx, size_t maxlen, const char* buf, size_t len, unsigned int width, unsigned int flags)
{
  const size_t start_idx = idx;


  if (!(flags & (1U << 1U)) && !(flags & (1U << 0U))) {
    for (size_t i = len; i < width; i++) {
      out(' ', buffer, idx++, maxlen);
    }
  }


  while (len) {
    out(buf[--len], buffer, idx++, maxlen);
  }


  if (flags & (1U << 1U)) {
    while (idx - start_idx < width) {
      out(' ', buffer, idx++, maxlen);
    }
  }

  return idx;
}



static size_t _ntoa_format(out_fct_type out, char* buffer, size_t idx, size_t maxlen, char* buf, size_t len, 
# 239 "common/src/printf.c" 3 4
                                                                                                            _Bool 
# 239 "common/src/printf.c"
                                                                                                                 negative, unsigned int base, unsigned int prec, unsigned int width, unsigned int flags)
{

  if (!(flags & (1U << 1U))) {
    if (width && (flags & (1U << 0U)) && (negative || (flags & ((1U << 2U) | (1U << 3U))))) {
      width--;
    }
    while ((len < prec) && (len < 32U)) {
      buf[len++] = '0';
    }
    while ((flags & (1U << 0U)) && (len < width) && (len < 32U)) {
      buf[len++] = '0';
    }
  }


  if (flags & (1U << 4U)) {
    if (!(flags & (1U << 10U)) && len && ((len == prec) || (len == width))) {
      len--;
      if (len && (base == 16U)) {
        len--;
      }
    }
    if ((base == 16U) && !(flags & (1U << 5U)) && (len < 32U)) {
      buf[len++] = 'x';
    }
    else if ((base == 16U) && (flags & (1U << 5U)) && (len < 32U)) {
      buf[len++] = 'X';
    }
    else if ((base == 2U) && (len < 32U)) {
      buf[len++] = 'b';
    }
    if (len < 32U) {
      buf[len++] = '0';
    }
  }

  if (len < 32U) {
    if (negative) {
      buf[len++] = '-';
    }
    else if (flags & (1U << 2U)) {
      buf[len++] = '+';
    }
    else if (flags & (1U << 3U)) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
}



static size_t _ntoa_long(out_fct_type out, char* buffer, size_t idx, size_t maxlen, unsigned long value, 
# 293 "common/src/printf.c" 3 4
                                                                                                        _Bool 
# 293 "common/src/printf.c"
                                                                                                             negative, unsigned long base, unsigned int prec, unsigned int width, unsigned int flags)
{
  char buf[32U];
  size_t len = 0U;


  if (!value) {
    flags &= ~(1U << 4U);
  }


  if (!(flags & (1U << 10U)) || value) {
    do {
      const char digit = (char)(value % base);
      buf[len++] = digit < 10 ? '0' + digit : (flags & (1U << 5U) ? 'A' : 'a') + digit - 10;
      value /= base;
    } while (value && (len < 32U));
  }

  return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}
# 351 "common/src/printf.c"
static size_t _ftoa(out_fct_type out, char* buffer, size_t idx, size_t maxlen, double value, unsigned int prec, unsigned int width, unsigned int flags)
{
  char buf[32U];
  size_t len = 0U;
  double diff = 0.0;


  static const double pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };


  if (value != value)
    return _out_rev(out, buffer, idx, maxlen, "nan", 3, width, flags);
  if (value < -((double)1.7976931348623157e+308L))
    return _out_rev(out, buffer, idx, maxlen, "fni-", 4, width, flags);
  if (value > ((double)1.7976931348623157e+308L))
    return _out_rev(out, buffer, idx, maxlen, (flags & (1U << 2U)) ? "fni+" : "fni", (flags & (1U << 2U)) ? 4U : 3U, width, flags);



  if ((value > 1e9) || (value < -1e9)) {



    return 0U;

  }


  
# 379 "common/src/printf.c" 3 4
 _Bool 
# 379 "common/src/printf.c"
      negative = 
# 379 "common/src/printf.c" 3 4
                 0
# 379 "common/src/printf.c"
                      ;
  if (value < 0) {
    negative = 
# 381 "common/src/printf.c" 3 4
              1
# 381 "common/src/printf.c"
                  ;
    value = 0 - value;
  }


  if (!(flags & (1U << 10U))) {
    prec = 6U;
  }

  while ((len < 32U) && (prec > 9U)) {
    buf[len++] = '0';
    prec--;
  }

  int whole = (int)value;
  double tmp = (value - whole) * pow10[prec];
  unsigned long frac = (unsigned long)tmp;
  diff = tmp - frac;

  if (diff > 0.5) {
    ++frac;

    if (frac >= pow10[prec]) {
      frac = 0;
      ++whole;
    }
  }
  else if (diff < 0.5) {
  }
  else if ((frac == 0U) || (frac & 1U)) {

    ++frac;
  }

  if (prec == 0U) {
    diff = value - (double)whole;
    if ((!(diff < 0.5) || (diff > 0.5)) && (whole & 1)) {


      ++whole;
    }
  }
  else {
    unsigned int count = prec;

    while (len < 32U) {
      --count;
      buf[len++] = (char)(48U + (frac % 10U));
      if (!(frac /= 10U)) {
        break;
      }
    }

    while ((len < 32U) && (count-- > 0U)) {
      buf[len++] = '0';
    }
    if (len < 32U) {

      buf[len++] = '.';
    }
  }


  while (len < 32U) {
    buf[len++] = (char)(48 + (whole % 10));
    if (!(whole /= 10)) {
      break;
    }
  }


  if (!(flags & (1U << 1U)) && (flags & (1U << 0U))) {
    if (width && (negative || (flags & ((1U << 2U) | (1U << 3U))))) {
      width--;
    }
    while ((len < width) && (len < 32U)) {
      buf[len++] = '0';
    }
  }

  if (len < 32U) {
    if (negative) {
      buf[len++] = '-';
    }
    else if (flags & (1U << 2U)) {
      buf[len++] = '+';
    }
    else if (flags & (1U << 3U)) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
}
# 589 "common/src/printf.c"
static int _vsnprintf(out_fct_type out, char* buffer, const size_t maxlen, const char* format, va_list va)
{
  unsigned int flags, width, precision, n;
  size_t idx = 0U;

  if (!buffer) {

    out = _out_null;
  }

  while (*format)
  {

    if (*format != '%') {

      out(*format, buffer, idx++, maxlen);
      format++;
      continue;
    }
    else {

      format++;
    }


    flags = 0U;
    do {
      switch (*format) {
        case '0': flags |= (1U << 0U); format++; n = 1U; break;
        case '-': flags |= (1U << 1U); format++; n = 1U; break;
        case '+': flags |= (1U << 2U); format++; n = 1U; break;
        case ' ': flags |= (1U << 3U); format++; n = 1U; break;
        case '#': flags |= (1U << 4U); format++; n = 1U; break;
        default : n = 0U; break;
      }
    } while (n);


    width = 0U;
    if (_is_digit(*format)) {
      width = _atoi(&format);
    }
    else if (*format == '*') {
      const int w = 
# 632 "common/src/printf.c" 3 4
                   __builtin_va_arg(
# 632 "common/src/printf.c"
                   va
# 632 "common/src/printf.c" 3 4
                   ,
# 632 "common/src/printf.c"
                   int
# 632 "common/src/printf.c" 3 4
                   )
# 632 "common/src/printf.c"
                                  ;
      if (w < 0) {
        flags |= (1U << 1U);
        width = (unsigned int)-w;
      }
      else {
        width = (unsigned int)w;
      }
      format++;
    }


    precision = 0U;
    if (*format == '.') {
      flags |= (1U << 10U);
      format++;
      if (_is_digit(*format)) {
        precision = _atoi(&format);
      }
      else if (*format == '*') {
        const int prec = (int)
# 652 "common/src/printf.c" 3 4
                             __builtin_va_arg(
# 652 "common/src/printf.c"
                             va
# 652 "common/src/printf.c" 3 4
                             ,
# 652 "common/src/printf.c"
                             int
# 652 "common/src/printf.c" 3 4
                             )
# 652 "common/src/printf.c"
                                            ;
        precision = prec > 0 ? (unsigned int)prec : 0U;
        format++;
      }
    }


    switch (*format) {
      case 'l' :
        flags |= (1U << 8U);
        format++;
        if (*format == 'l') {
          flags |= (1U << 9U);
          format++;
        }
        break;
      case 'h' :
        flags |= (1U << 7U);
        format++;
        if (*format == 'h') {
          flags |= (1U << 6U);
          format++;
        }
        break;






      case 'j' :
        flags |= (sizeof(intmax_t) == sizeof(long) ? (1U << 8U) : (1U << 9U));
        format++;
        break;
      case 'z' :
        flags |= (sizeof(size_t) == sizeof(long) ? (1U << 8U) : (1U << 9U));
        format++;
        break;
      default :
        break;
    }


    switch (*format) {
      case 'd' :
      case 'i' :
      case 'u' :
      case 'x' :
      case 'X' :
      case 'o' :
      case 'b' : {

        unsigned int base;
        if (*format == 'x' || *format == 'X') {
          base = 16U;
        }
        else if (*format == 'o') {
          base = 8U;
        }
        else if (*format == 'b') {
          base = 2U;
        }
        else {
          base = 10U;
          flags &= ~(1U << 4U);
        }

        if (*format == 'X') {
          flags |= (1U << 5U);
        }


        if ((*format != 'i') && (*format != 'd')) {
          flags &= ~((1U << 2U) | (1U << 3U));
        }


        if (flags & (1U << 10U)) {
          flags &= ~(1U << 0U);
        }


        if ((*format == 'i') || (*format == 'd')) {

          if (flags & (1U << 9U)) {




          }
          else if (flags & (1U << 8U)) {
            const long value = 
# 743 "common/src/printf.c" 3 4
                              __builtin_va_arg(
# 743 "common/src/printf.c"
                              va
# 743 "common/src/printf.c" 3 4
                              ,
# 743 "common/src/printf.c"
                              long
# 743 "common/src/printf.c" 3 4
                              )
# 743 "common/src/printf.c"
                                              ;
            idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned long)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
          }
          else {
            const int value = (flags & (1U << 6U)) ? (char)
# 747 "common/src/printf.c" 3 4
                                                          __builtin_va_arg(
# 747 "common/src/printf.c"
                                                          va
# 747 "common/src/printf.c" 3 4
                                                          ,
# 747 "common/src/printf.c"
                                                          int
# 747 "common/src/printf.c" 3 4
                                                          ) 
# 747 "common/src/printf.c"
                                                                          : (flags & (1U << 7U)) ? (short int)
# 747 "common/src/printf.c" 3 4
                                                                                                               __builtin_va_arg(
# 747 "common/src/printf.c"
                                                                                                               va
# 747 "common/src/printf.c" 3 4
                                                                                                               ,
# 747 "common/src/printf.c"
                                                                                                               int
# 747 "common/src/printf.c" 3 4
                                                                                                               ) 
# 747 "common/src/printf.c"
                                                                                                                               : 
# 747 "common/src/printf.c" 3 4
                                                                                                                                 __builtin_va_arg(
# 747 "common/src/printf.c"
                                                                                                                                 va
# 747 "common/src/printf.c" 3 4
                                                                                                                                 ,
# 747 "common/src/printf.c"
                                                                                                                                 int
# 747 "common/src/printf.c" 3 4
                                                                                                                                 )
# 747 "common/src/printf.c"
                                                                                                                                                ;
            idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned int)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
          }
        }
        else {

          if (flags & (1U << 9U)) {



          }
          else if (flags & (1U << 8U)) {
            idx = _ntoa_long(out, buffer, idx, maxlen, 
# 759 "common/src/printf.c" 3 4
                                                      __builtin_va_arg(
# 759 "common/src/printf.c"
                                                      va
# 759 "common/src/printf.c" 3 4
                                                      ,
# 759 "common/src/printf.c"
                                                      unsigned long
# 759 "common/src/printf.c" 3 4
                                                      )
# 759 "common/src/printf.c"
                                                                               , 
# 759 "common/src/printf.c" 3 4
                                                                                 0
# 759 "common/src/printf.c"
                                                                                      , base, precision, width, flags);
          }
          else {
            const unsigned int value = (flags & (1U << 6U)) ? (unsigned char)
# 762 "common/src/printf.c" 3 4
                                                                            __builtin_va_arg(
# 762 "common/src/printf.c"
                                                                            va
# 762 "common/src/printf.c" 3 4
                                                                            ,
# 762 "common/src/printf.c"
                                                                            unsigned int
# 762 "common/src/printf.c" 3 4
                                                                            ) 
# 762 "common/src/printf.c"
                                                                                                     : (flags & (1U << 7U)) ? (unsigned short int)
# 762 "common/src/printf.c" 3 4
                                                                                                                                                   __builtin_va_arg(
# 762 "common/src/printf.c"
                                                                                                                                                   va
# 762 "common/src/printf.c" 3 4
                                                                                                                                                   ,
# 762 "common/src/printf.c"
                                                                                                                                                   unsigned int
# 762 "common/src/printf.c" 3 4
                                                                                                                                                   ) 
# 762 "common/src/printf.c"
                                                                                                                                                                            : 
# 762 "common/src/printf.c" 3 4
                                                                                                                                                                              __builtin_va_arg(
# 762 "common/src/printf.c"
                                                                                                                                                                              va
# 762 "common/src/printf.c" 3 4
                                                                                                                                                                              ,
# 762 "common/src/printf.c"
                                                                                                                                                                              unsigned int
# 762 "common/src/printf.c" 3 4
                                                                                                                                                                              )
# 762 "common/src/printf.c"
                                                                                                                                                                                                      ;
            idx = _ntoa_long(out, buffer, idx, maxlen, value, 
# 763 "common/src/printf.c" 3 4
                                                             0
# 763 "common/src/printf.c"
                                                                  , base, precision, width, flags);
          }
        }
        format++;
        break;
      }

      case 'f' :
      case 'F' :
        if (*format == 'F') flags |= (1U << 5U);
        idx = _ftoa(out, buffer, idx, maxlen, 
# 773 "common/src/printf.c" 3 4
                                             __builtin_va_arg(
# 773 "common/src/printf.c"
                                             va
# 773 "common/src/printf.c" 3 4
                                             ,
# 773 "common/src/printf.c"
                                             double
# 773 "common/src/printf.c" 3 4
                                             )
# 773 "common/src/printf.c"
                                                               , precision, width, flags);
        format++;
        break;
# 788 "common/src/printf.c"
      case 'c' : {
        unsigned int l = 1U;

        if (!(flags & (1U << 1U))) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }

        out((char)
# 797 "common/src/printf.c" 3 4
                 __builtin_va_arg(
# 797 "common/src/printf.c"
                 va
# 797 "common/src/printf.c" 3 4
                 ,
# 797 "common/src/printf.c"
                 int
# 797 "common/src/printf.c" 3 4
                 )
# 797 "common/src/printf.c"
                                , buffer, idx++, maxlen);

        if (flags & (1U << 1U)) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        format++;
        break;
      }

      case 's' : {
        const char* p = 
# 809 "common/src/printf.c" 3 4
                       __builtin_va_arg(
# 809 "common/src/printf.c"
                       va
# 809 "common/src/printf.c" 3 4
                       ,
# 809 "common/src/printf.c"
                       char*
# 809 "common/src/printf.c" 3 4
                       )
# 809 "common/src/printf.c"
                                        ;
        unsigned int l = _strnlen_s(p, precision ? precision : (size_t)-1);

        if (flags & (1U << 10U)) {
          l = (l < precision ? l : precision);
        }
        if (!(flags & (1U << 1U))) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }

        while ((*p != 0) && (!(flags & (1U << 10U)) || precision--)) {
          out(*(p++), buffer, idx++, maxlen);
        }

        if (flags & (1U << 1U)) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        format++;
        break;
      }

      case 'p' : {
        width = sizeof(void*) * 2U;
        flags |= (1U << 0U) | (1U << 5U);







          idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned long)((uintptr_t)
# 844 "common/src/printf.c" 3 4
                                                                               __builtin_va_arg(
# 844 "common/src/printf.c"
                                                                               va
# 844 "common/src/printf.c" 3 4
                                                                               ,
# 844 "common/src/printf.c"
                                                                               void*
# 844 "common/src/printf.c" 3 4
                                                                               )
# 844 "common/src/printf.c"
                                                                                                ), 
# 844 "common/src/printf.c" 3 4
                                                                                                   0
# 844 "common/src/printf.c"
                                                                                                        , 16U, precision, width, flags);



        format++;
        break;
      }

      case '%' :
        out('%', buffer, idx++, maxlen);
        format++;
        break;

      default :
        out(*format, buffer, idx++, maxlen);
        format++;
        break;
    }
  }


  out((char)0, buffer, idx < maxlen ? idx : maxlen - 1U, maxlen);


  return (int)idx;
}



int vprintf_spf(const char* format, va_list va)
{
  char buffer[1];
  return _vsnprintf(_out_char_spf, buffer, (size_t)-1, format, va);
}

int vprintf_sim(const char* format, va_list va)
{
  char buffer[1];
  return _vsnprintf(_out_char_sim, buffer, (size_t)-1, format, va);
}

int vprintf_log(const char* format, va_list va)
{
  char buffer[1];
  return _vsnprintf(_out_char_log, buffer, (size_t)-1, format, va);
}
