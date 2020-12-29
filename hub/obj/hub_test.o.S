# 1 "hub/src/hub_test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hub/src/hub_test.c"
# 15 "hub/src/hub_test.c"
# 1 "hub/include/hub/hub_test.h" 1
# 52 "hub/include/hub/hub_test.h"
void test_cusb_poll(void);
void test_hub(void);
void test_sim(void);
void test_sim_serial_pass_through(void);
# 16 "hub/src/hub_test.c" 2

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 1 3
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 1 3
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 1 3
# 14 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_newlib_version.h" 1 3
# 15 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 2 3
# 11 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 1 3



# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 5 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 1 3
# 6 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 2 3
# 12 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 2 3
# 11 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 1 3
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 1 3
# 14 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 143 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4

# 143 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 209 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 321 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 15 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 1 3
# 24 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 350 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 25 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 2 3


# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_types.h" 1 3






# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 1 3
# 41 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
# 55 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int32_t;

typedef long unsigned int __uint32_t;
# 103 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;
# 200 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;
# 214 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 8 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_types.h" 2 3
# 28 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 2 3


typedef long __blkcnt_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;



typedef long _off_t;





typedef int __pid_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



typedef __uint32_t __id_t;







typedef unsigned short __ino_t;
# 90 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;
# 131 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
typedef unsigned int __size_t;
# 147 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
typedef signed int _ssize_t;
# 158 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;




typedef void *_iconv_t;






typedef unsigned long __clock_t;






typedef __int_least64_t __time_t;





typedef unsigned long __clockid_t;


typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3






typedef unsigned long __ULong;
# 34 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/lock.h" 1 3
# 33 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/lock.h" 3
struct __lock;
typedef struct __lock * _LOCK_T;






extern void __retarget_lock_init(_LOCK_T *lock);

extern void __retarget_lock_init_recursive(_LOCK_T *lock);

extern void __retarget_lock_close(_LOCK_T lock);

extern void __retarget_lock_close_recursive(_LOCK_T lock);

extern void __retarget_lock_acquire(_LOCK_T lock);

extern void __retarget_lock_acquire_recursive(_LOCK_T lock);

extern int __retarget_lock_try_acquire(_LOCK_T lock);

extern int __retarget_lock_try_acquire_recursive(_LOCK_T lock);


extern void __retarget_lock_release(_LOCK_T lock);

extern void __retarget_lock_release_recursive(_LOCK_T lock);
# 35 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3
typedef _LOCK_T _flock_t;







struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};
# 98 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
# 122 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 186 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 292 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 324 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 613 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};
# 819 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 12 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 1 3
# 47 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 48 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 2 3
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3




# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 18 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3
# 27 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *restrict, const void *restrict, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *restrict, const char *restrict);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *restrict, const char *restrict);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *restrict, const char *restrict, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);

char *strtok (char *restrict, const char *restrict);

size_t strxfrm (char *restrict, const char *restrict, size_t);
# 86 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3
char *_strdup_r (struct _reent *, const char *);



char *_strndup_r (struct _reent *, const char *, size_t);
# 112 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3
char * _strerror_r (struct _reent *, int, int, int *);
# 134 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3
char *strsignal (int __signo);
# 175 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/string.h" 1 3
# 176 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3


# 18 "hub/src/hub_test.c" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 19 "hub/src/hub_test.c" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 1 3 4
# 9 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 1 3 4
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
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
# 20 "hub/src/hub_test.c" 2

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
# 22 "hub/src/hub_test.c" 2
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
# 23 "hub/src/hub_test.c" 2
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
# 24 "hub/src/hub_test.c" 2
# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 25 "hub/src/hub_test.c" 2
# 1 "libopencm3/include/libopencm3/stm32/timer.h" 1
# 38 "libopencm3/include/libopencm3/stm32/timer.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/timer.h" 1
# 38 "libopencm3/include/libopencm3/stm32/l0/timer.h"
# 1 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h" 1
# 1066 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h"
enum tim_oc_id {
 TIM_OC1 = 0,
 TIM_OC1N,
 TIM_OC2,
 TIM_OC2N,
 TIM_OC3,
 TIM_OC3N,
 TIM_OC4,
};


enum tim_oc_mode {
 TIM_OCM_FROZEN,
 TIM_OCM_ACTIVE,
 TIM_OCM_INACTIVE,
 TIM_OCM_TOGGLE,
 TIM_OCM_FORCE_LOW,
 TIM_OCM_FORCE_HIGH,
 TIM_OCM_PWM1,
 TIM_OCM_PWM2,
};


enum tim_ic_id {
 TIM_IC1,
 TIM_IC2,
 TIM_IC3,
 TIM_IC4,
};
# 1103 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h"
enum tim_ic_filter {
 TIM_IC_OFF,
 TIM_IC_CK_INT_N_2,
 TIM_IC_CK_INT_N_4,
 TIM_IC_CK_INT_N_8,
 TIM_IC_DTF_DIV_2_N_6,
 TIM_IC_DTF_DIV_2_N_8,
 TIM_IC_DTF_DIV_4_N_6,
 TIM_IC_DTF_DIV_4_N_8,
 TIM_IC_DTF_DIV_8_N_6,
 TIM_IC_DTF_DIV_8_N_8,
 TIM_IC_DTF_DIV_16_N_5,
 TIM_IC_DTF_DIV_16_N_6,
 TIM_IC_DTF_DIV_16_N_8,
 TIM_IC_DTF_DIV_32_N_5,
 TIM_IC_DTF_DIV_32_N_6,
 TIM_IC_DTF_DIV_32_N_8,
};




enum tim_ic_psc {
 TIM_IC_PSC_OFF,
 TIM_IC_PSC_2,
 TIM_IC_PSC_4,
 TIM_IC_PSC_8,
};





enum tim_ic_input {
 TIM_IC_OUT = 0,
 TIM_IC_IN_TI1 = 1,
 TIM_IC_IN_TI2 = 2,
 TIM_IC_IN_TRC = 3,
 TIM_IC_IN_TI3 = 5,
 TIM_IC_IN_TI4 = 6,
};


enum tim_et_pol {
 TIM_ET_RISING,
 TIM_ET_FALLING,
};





void timer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void timer_disable_irq(uint32_t timer_peripheral, uint32_t irq);

# 1157 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h" 3 4
_Bool 
# 1157 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h"
    timer_interrupt_source(uint32_t timer_peripheral, uint32_t flag);

# 1158 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h" 3 4
_Bool 
# 1158 "libopencm3/include/libopencm3/stm32/common/timer_common_all.h"
    timer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_clear_flag(uint32_t timer_peripheral, uint32_t flag);
void timer_set_mode(uint32_t timer_peripheral, uint32_t clock_div,
      uint32_t alignment, uint32_t direction);
void timer_set_clock_division(uint32_t timer_peripheral, uint32_t clock_div);
void timer_enable_preload(uint32_t timer_peripheral);
void timer_disable_preload(uint32_t timer_peripheral);
void timer_set_alignment(uint32_t timer_peripheral, uint32_t alignment);
void timer_direction_up(uint32_t timer_peripheral);
void timer_direction_down(uint32_t timer_peripheral);
void timer_one_shot_mode(uint32_t timer_peripheral);
void timer_continuous_mode(uint32_t timer_peripheral);
void timer_update_on_any(uint32_t timer_peripheral);
void timer_update_on_overflow(uint32_t timer_peripheral);
void timer_enable_update_event(uint32_t timer_peripheral);
void timer_disable_update_event(uint32_t timer_peripheral);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
void timer_set_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_reset_output_idle_state(uint32_t timer_peripheral, uint32_t outputs);
void timer_set_ti1_ch123_xor(uint32_t timer_peripheral);
void timer_set_ti1_ch1(uint32_t timer_peripheral);
void timer_set_master_mode(uint32_t timer_peripheral, uint32_t mode);
void timer_set_dma_on_compare_event(uint32_t timer_peripheral);
void timer_set_dma_on_update_event(uint32_t timer_peripheral);
void timer_enable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_disable_compare_control_update_on_trigger(uint32_t timer_peripheral);
void timer_enable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_disable_preload_complementry_enable_bits(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t value);
void timer_set_repetition_counter(uint32_t timer_peripheral, uint32_t value);
void timer_set_period(uint32_t timer_peripheral, uint32_t period);
void timer_enable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_clear(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_fast_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_slow_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_mode(uint32_t timer_peripheral, enum tim_oc_id oc_id,
         enum tim_oc_mode oc_mode);
void timer_enable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_preload(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_polarity_high(uint32_t timer_peripheral,
    enum tim_oc_id oc_id);
void timer_set_oc_polarity_low(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_enable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_disable_oc_output(uint32_t timer_peripheral, enum tim_oc_id oc_id);
void timer_set_oc_idle_state_set(uint32_t timer_peripheral,
     enum tim_oc_id oc_id);
void timer_set_oc_idle_state_unset(uint32_t timer_peripheral,
       enum tim_oc_id oc_id);
void timer_set_oc_value(uint32_t timer_peripheral, enum tim_oc_id oc_id,
   uint32_t value);
void timer_enable_break_main_output(uint32_t timer_peripheral);
void timer_disable_break_main_output(uint32_t timer_peripheral);
void timer_enable_break_automatic_output(uint32_t timer_peripheral);
void timer_disable_break_automatic_output(uint32_t timer_peripheral);
void timer_set_break_polarity_high(uint32_t timer_peripheral);
void timer_set_break_polarity_low(uint32_t timer_peripheral);
void timer_enable_break(uint32_t timer_peripheral);
void timer_disable_break(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_run_mode(uint32_t timer_peripheral);
void timer_set_enabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_disabled_off_state_in_idle_mode(uint32_t timer_peripheral);
void timer_set_break_lock(uint32_t timer_peripheral, uint32_t lock);
void timer_set_deadtime(uint32_t timer_peripheral, uint32_t deadtime);
void timer_generate_event(uint32_t timer_peripheral, uint32_t event);
uint32_t timer_get_counter(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);

void timer_ic_set_filter(uint32_t timer, enum tim_ic_id ic,
    enum tim_ic_filter flt);
void timer_ic_set_prescaler(uint32_t timer, enum tim_ic_id ic,
       enum tim_ic_psc psc);
void timer_ic_set_input(uint32_t timer, enum tim_ic_id ic,
   enum tim_ic_input in);
void timer_ic_enable(uint32_t timer, enum tim_ic_id ic);
void timer_ic_disable(uint32_t timer, enum tim_ic_id ic);

void timer_slave_set_filter(uint32_t timer, enum tim_ic_filter flt);
void timer_slave_set_prescaler(uint32_t timer, enum tim_ic_psc psc);
void timer_slave_set_polarity(uint32_t timer, enum tim_et_pol pol);
void timer_slave_set_mode(uint32_t timer, uint8_t mode);
void timer_slave_set_trigger(uint32_t timer, uint8_t trigger);


# 39 "libopencm3/include/libopencm3/stm32/l0/timer.h" 2
# 39 "libopencm3/include/libopencm3/stm32/timer.h" 2
# 26 "hub/src/hub_test.c" 2
# 1 "libopencm3/include/libopencm3/stm32/lptimer.h" 1
# 30 "libopencm3/include/libopencm3/stm32/lptimer.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/lptimer.h" 1
# 34 "libopencm3/include/libopencm3/stm32/l0/lptimer.h"
# 1 "libopencm3/include/libopencm3/stm32/common/lptimer_common_all.h" 1
# 260 "libopencm3/include/libopencm3/stm32/common/lptimer_common_all.h"


void lptimer_enable(uint32_t timer_peripheral);
void lptimer_disable(uint32_t timer_peripheral);

void lptimer_start_counter(uint32_t timer_peripheral, uint32_t mode);
void lptimer_set_counter(uint32_t timer_peripheral, uint16_t count);
uint16_t lptimer_get_counter(uint32_t timer_peripheral);
void lptimer_set_compare(uint32_t timer_peripheral, uint16_t compare_value);
void lptimer_set_period(uint32_t lptimer_peripheral, uint16_t period_value);
void lptimer_enable_preload(uint32_t lptimer_peripheral);
void lptimer_disable_preload(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_high(uint32_t lptimer_peripheral);
void lptimer_set_waveform_polarity_low(uint32_t lptimer_peripheral);

void lptimer_set_prescaler(uint32_t timer_peripheral, uint32_t prescaler);
void lptimer_enable_trigger(uint32_t lptimer_peripheral, uint32_t trigen);
void lptimer_select_trigger_source(uint32_t lptimer_peripheral, uint32_t trigger_source);
void lptimer_set_internal_clock_source(uint32_t timer_peripheral);
void lptimer_set_external_clock_source(uint32_t timer_peripheral);

void lptimer_clear_flag(uint32_t timer_peripheral, uint32_t flag);

# 282 "libopencm3/include/libopencm3/stm32/common/lptimer_common_all.h" 3 4
_Bool 
# 282 "libopencm3/include/libopencm3/stm32/common/lptimer_common_all.h"
    lptimer_get_flag(uint32_t timer_peripheral, uint32_t flag);
void lptimer_enable_irq(uint32_t timer_peripheral, uint32_t irq);
void lptimer_disable_irq(uint32_t timer_peripheral, uint32_t irq);



# 35 "libopencm3/include/libopencm3/stm32/l0/lptimer.h" 2









# 31 "libopencm3/include/libopencm3/stm32/lptimer.h" 2
# 27 "hub/src/hub_test.c" 2
# 1 "libopencm3/include/libopencm3/stm32/pwr.h" 1
# 28 "hub/src/hub_test.c" 2

# 1 "common/include/common/aes.h" 1
# 11 "common/include/common/aes.h"
void aes_init(void);
void aes_expand_key(void);
void aes_ecb_encrypt(uint8_t* buf);
void aes_ecb_decrypt(uint8_t* buf);
void aes_generate_random(uint8_t *buf, uint8_t len);
# 30 "hub/src/hub_test.c" 2
# 1 "common/include/common/battery.h" 1
# 16 "common/include/common/battery.h"
extern uint16_t batt_voltages[2];

extern 
# 18 "common/include/common/battery.h" 3 4
      _Bool 
# 18 "common/include/common/battery.h"
           batt_rst_seq;

void batt_init(void);
void batt_set_voltage_scale(uint8_t scale);
void batt_set_low_power_run(void);
void batt_update_voltages(void);
void batt_enable_interrupt(void);
void batt_enable_comp(void);
# 31 "hub/src/hub_test.c" 2
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
# 32 "hub/src/hub_test.c" 2

# 1 "common/include/common/reset.h" 1



void reset_print_cause(void);
# 34 "hub/src/hub_test.c" 2
# 1 "common/include/common/rfm.h" 1
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
# 35 "hub/src/hub_test.c" 2
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
# 36 "hub/src/hub_test.c" 2
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
# 37 "hub/src/hub_test.c" 2
# 1 "common/include/common/memory.h" 1
# 33 "common/include/common/memory.h"
# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 34 "common/include/common/memory.h" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 35 "common/include/common/memory.h" 2
# 72 "common/include/common/memory.h"
void mem_init(void);


# 74 "common/include/common/memory.h" 3 4
_Bool 
# 74 "common/include/common/memory.h"
    mem_eeprom_write_word(uint32_t address, uint32_t data);

# 75 "common/include/common/memory.h" 3 4
_Bool 
# 75 "common/include/common/memory.h"
    mem_eeprom_write_half_word(uint32_t address, uint16_t data);

# 76 "common/include/common/memory.h" 3 4
_Bool 
# 76 "common/include/common/memory.h"
    mem_eeprom_write_byte(uint32_t address, uint8_t data);


# 78 "common/include/common/memory.h" 3 4
_Bool 
# 78 "common/include/common/memory.h"
    mem_flash_erase_page(uint32_t address);

# 79 "common/include/common/memory.h" 3 4
_Bool 
# 79 "common/include/common/memory.h"
    mem_flash_write_word(uint32_t address, uint32_t data);

# 80 "common/include/common/memory.h" 3 4
_Bool 
# 80 "common/include/common/memory.h"
    mem_flash_write_half_page(uint32_t address, uint32_t *data);

void mem_save_reading(int16_t reading);

uint32_t mem_get_dev_state(void);
uint32_t mem_get_dev_num(void);
uint32_t mem_get_msg_num(void);
void mem_update_msg_num(uint32_t new);
uint32_t mem_get_num_readings(void);
int16_t mem_get_reading(uint32_t reading_num);

int mem_log_printf(const char* format, ...);
void mem_get_log(char log[1024]);
void mem_wipe_log(void);
void mem_print_log(void);

void mem_get_aes_key(uint8_t *aes_key);
void mem_set_aes_key(uint8_t *aes_key);
void mem_get_aes_key_exp(uint8_t *aes_key_exp);
void mem_set_aes_key_exp(uint8_t *aes_key_exp);

void mem_wipe_readings(void);
# 38 "hub/src/hub_test.c" 2

# 1 "hub/include/hub/cusb.h" 1
# 52 "hub/include/hub/cusb.h"
void cusb_init(void);
void cusb_test_poll(void);
# 40 "hub/src/hub_test.c" 2
# 1 "hub/include/hub/hub_bootloader.h" 1
# 32 "hub/include/hub/hub_bootloader.h"
# 1 "common/include/common/bootloader_utils.h" 1
# 51 "common/include/common/bootloader_utils.h"
void boot_init(void);
void boot_deinit(void);
void boot_jump_to_application(uint32_t address);
# 33 "hub/include/hub/hub_bootloader.h" 2
# 41 "hub/src/hub_test.c" 2
# 1 "hub/include/hub/sim.h" 1







void sim_init(void);
void sim_end(void);
void sim_connect(void);


void sim_send_data(uint8_t *data, uint8_t len);

# 14 "hub/include/hub/sim.h" 3 4
_Bool 
# 14 "hub/include/hub/sim.h"
    check_response(char *str);

int sim_printf(const char* format, ...);
void sim_serial_pass_through(void);
# 42 "hub/src/hub_test.c" 2
# 73 "hub/src/hub_test.c"
void test_cusb_poll(void)
{
  cusb_init();
  cusb_test_poll();
}

void test_sim(void)
{
 spf_serial_printf("Testing Sim\n");


 uint32_t dev_num = mem_get_dev_num();


 rfm_init();
 rfm_config_for_lora(0x70, 0x02, 0x70, 
# 88 "hub/src/hub_test.c" 3 4
                                                                                     1
# 88 "hub/src/hub_test.c"
                                                                                         , 0);
 rfm_start_listening();

 uint8_t num_vals = 3;
 uint32_t ids[3] = {0x00000001, 0x00000010, 0x00000100};
 int16_t temps[3] = {-634, -312, 512};
 uint16_t battery[3] = {345, 301, 276};
 uint32_t total_packets[3] = {1, 1, 1};
 uint32_t ok_packets[3] = {1,1,1};
 int8_t rssi[3] = {1,1,1};

 for(;;)
 {

  uint8_t sim_buf[256];
  uint8_t sim_idx = 0;
  sim_buf[sim_idx++] = dev_num >> 24;
  sim_buf[sim_idx++] = dev_num >> 16;
  sim_buf[sim_idx++] = dev_num >> 8;
  sim_buf[sim_idx++] = dev_num;

  for(uint8_t i = 0; i < num_vals; i++)
  {
   sim_buf[sim_idx++] = ids[i] >> 24; sim_buf[sim_idx++] = ids[i] >> 16; sim_buf[sim_idx++] = ids[i] >> 8; sim_buf[sim_idx++] = ids[i];
   sim_buf[sim_idx++] = temps[i] >> 8; sim_buf[sim_idx++] = temps[i];
   sim_buf[sim_idx++] = battery[i] >> 8; sim_buf[sim_idx++] = battery[i];
   sim_buf[sim_idx++] = total_packets[i] >> 24; sim_buf[sim_idx++] = total_packets[i] >> 16; sim_buf[sim_idx++] = total_packets[i] >> 8; sim_buf[sim_idx++] = total_packets[i];
   sim_buf[sim_idx++] = ok_packets[i] >> 24; sim_buf[sim_idx++] = ok_packets[i] >> 16; sim_buf[sim_idx++] = ok_packets[i] >> 8; sim_buf[sim_idx++] = ok_packets[i];
   sim_buf[sim_idx++] = rssi[i] >> 8; sim_buf[sim_idx++] = rssi[i];
  }


  sim_init();
  sim_connect();

  sim_send_data(sim_buf, sim_idx);

  spf_serial_printf("Sent\n\n");

  sim_end();

  temps[2]++;

  timers_delay_milliseconds(5000);


  for(uint8_t i = 0; i < num_vals; i++)
  {
   total_packets[i]++;
   ok_packets[i]++;
  }
 }
}

void test_sim_serial_pass_through(void)
{
 spf_serial_printf("Testing sim serial pass through\n");
 sim_serial_pass_through();
}

void test_hub(void)
{
# 257 "hub/src/hub_test.c"
}
