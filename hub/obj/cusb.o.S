# 1 "hub/src/cusb.c"
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase//"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 199901L
#define __STDC_HOSTED__ 1
#define __GNUC__ 9
#define __GNUC_MINOR__ 3
#define __GNUC_PATCHLEVEL__ 1
#define __VERSION__ "9.3.1 20200408 (release)"
#define __ATOMIC_RELAXED 0
#define __ATOMIC_SEQ_CST 5
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __OPTIMIZE__ 1
#define __FINITE_MATH_ONLY__ 0
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG_DOUBLE__ 8
#define __SIZEOF_SIZE_T__ 4
#define __CHAR_BIT__ 8
#define __BIGGEST_ALIGNMENT__ 8
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_PDP_ENDIAN__ 3412
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __SIZEOF_POINTER__ 4
#define __SIZE_TYPE__ unsigned int
#define __PTRDIFF_TYPE__ int
#define __WCHAR_TYPE__ unsigned int
#define __WINT_TYPE__ unsigned int
#define __INTMAX_TYPE__ long long int
#define __UINTMAX_TYPE__ long long unsigned int
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __SIG_ATOMIC_TYPE__ int
#define __INT8_TYPE__ signed char
#define __INT16_TYPE__ short int
#define __INT32_TYPE__ long int
#define __INT64_TYPE__ long long int
#define __UINT8_TYPE__ unsigned char
#define __UINT16_TYPE__ short unsigned int
#define __UINT32_TYPE__ long unsigned int
#define __UINT64_TYPE__ long long unsigned int
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST16_TYPE__ short int
#define __INT_LEAST32_TYPE__ long int
#define __INT_LEAST64_TYPE__ long long int
#define __UINT_LEAST8_TYPE__ unsigned char
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __UINT_LEAST32_TYPE__ long unsigned int
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __INT_FAST8_TYPE__ int
#define __INT_FAST16_TYPE__ int
#define __INT_FAST32_TYPE__ int
#define __INT_FAST64_TYPE__ long long int
#define __UINT_FAST8_TYPE__ unsigned int
#define __UINT_FAST16_TYPE__ unsigned int
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INTPTR_TYPE__ int
#define __UINTPTR_TYPE__ unsigned int
#define __has_include(STR) __has_include__(STR)
#define __has_include_next(STR) __has_include_next__(STR)
#define __GXX_ABI_VERSION 1013
#define __SCHAR_MAX__ 0x7f
#define __SHRT_MAX__ 0x7fff
#define __INT_MAX__ 0x7fffffff
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __WCHAR_MAX__ 0xffffffffU
#define __WCHAR_MIN__ 0U
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __PTRDIFF_MAX__ 0x7fffffff
#define __SIZE_MAX__ 0xffffffffU
#define __SCHAR_WIDTH__ 8
#define __SHRT_WIDTH__ 16
#define __INT_WIDTH__ 32
#define __LONG_WIDTH__ 32
#define __LONG_LONG_WIDTH__ 64
#define __WCHAR_WIDTH__ 32
#define __WINT_WIDTH__ 32
#define __PTRDIFF_WIDTH__ 32
#define __SIZE_WIDTH__ 32
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __INTMAX_C(c) c ## LL
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __UINTMAX_C(c) c ## ULL
#define __INTMAX_WIDTH__ 64
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __SIG_ATOMIC_WIDTH__ 32
#define __INT8_MAX__ 0x7f
#define __INT16_MAX__ 0x7fff
#define __INT32_MAX__ 0x7fffffffL
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT8_MAX__ 0xff
#define __UINT16_MAX__ 0xffff
#define __UINT32_MAX__ 0xffffffffUL
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __INT_LEAST8_MAX__ 0x7f
#define __INT8_C(c) c
#define __INT_LEAST8_WIDTH__ 8
#define __INT_LEAST16_MAX__ 0x7fff
#define __INT16_C(c) c
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_MAX__ 0x7fffffffL
#define __INT32_C(c) c ## L
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __INT64_C(c) c ## LL
#define __INT_LEAST64_WIDTH__ 64
#define __UINT_LEAST8_MAX__ 0xff
#define __UINT8_C(c) c
#define __UINT_LEAST16_MAX__ 0xffff
#define __UINT16_C(c) c
#define __UINT_LEAST32_MAX__ 0xffffffffUL
#define __UINT32_C(c) c ## UL
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __UINT64_C(c) c ## ULL
#define __INT_FAST8_MAX__ 0x7fffffff
#define __INT_FAST8_WIDTH__ 32
#define __INT_FAST16_MAX__ 0x7fffffff
#define __INT_FAST16_WIDTH__ 32
#define __INT_FAST32_MAX__ 0x7fffffff
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_FAST64_WIDTH__ 64
#define __UINT_FAST8_MAX__ 0xffffffffU
#define __UINT_FAST16_MAX__ 0xffffffffU
#define __UINT_FAST32_MAX__ 0xffffffffU
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __INTPTR_MAX__ 0x7fffffff
#define __INTPTR_WIDTH__ 32
#define __UINTPTR_MAX__ 0xffffffffU
#define __GCC_IEC_559 0
#define __GCC_IEC_559_COMPLEX 0
#define __FLT_EVAL_METHOD__ 0
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __DEC_EVAL_METHOD__ 2
#define __FLT_RADIX__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_DIG__ 6
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_10_EXP__ 38
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_MAX__ 3.4028234663852886e+38F
#define __FLT_MIN__ 1.1754943508222875e-38F
#define __FLT_EPSILON__ 1.1920928955078125e-7F
#define __FLT_DENORM_MIN__ 1.4012984643248171e-45F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_DIG__ 15
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_10_EXP__ 308
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_MAX__ ((double)1.7976931348623157e+308L)
#define __DBL_MIN__ ((double)2.2250738585072014e-308L)
#define __DBL_EPSILON__ ((double)2.2204460492503131e-16L)
#define __DBL_DENORM_MIN__ ((double)4.9406564584124654e-324L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 53
#define __LDBL_DIG__ 15
#define __LDBL_MIN_EXP__ (-1021)
#define __LDBL_MIN_10_EXP__ (-307)
#define __LDBL_MAX_EXP__ 1024
#define __LDBL_MAX_10_EXP__ 308
#define __DECIMAL_DIG__ 17
#define __LDBL_DECIMAL_DIG__ 17
#define __LDBL_MAX__ 1.7976931348623157e+308L
#define __LDBL_MIN__ 2.2250738585072014e-308L
#define __LDBL_EPSILON__ 2.2204460492503131e-16L
#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT32_DIG__ 6
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_MAX__ 3.4028234663852886e+38F32
#define __FLT32_MIN__ 1.1754943508222875e-38F32
#define __FLT32_EPSILON__ 1.1920928955078125e-7F32
#define __FLT32_DENORM_MIN__ 1.4012984643248171e-45F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT64_MANT_DIG__ 53
#define __FLT64_DIG__ 15
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_MAX__ 1.7976931348623157e+308F64
#define __FLT64_MIN__ 2.2250738585072014e-308F64
#define __FLT64_EPSILON__ 2.2204460492503131e-16F64
#define __FLT64_DENORM_MIN__ 4.9406564584124654e-324F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_DIG__ 15
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_MAX__ 1.7976931348623157e+308F32x
#define __FLT32X_MIN__ 2.2250738585072014e-308F32x
#define __FLT32X_EPSILON__ 2.2204460492503131e-16F32x
#define __FLT32X_DENORM_MIN__ 4.9406564584124654e-324F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __DEC32_MANT_DIG__ 7
#define __DEC32_MIN_EXP__ (-94)
#define __DEC32_MAX_EXP__ 97
#define __DEC32_MIN__ 1E-95DF
#define __DEC32_MAX__ 9.999999E96DF
#define __DEC32_EPSILON__ 1E-6DF
#define __DEC32_SUBNORMAL_MIN__ 0.000001E-95DF
#define __DEC64_MANT_DIG__ 16
#define __DEC64_MIN_EXP__ (-382)
#define __DEC64_MAX_EXP__ 385
#define __DEC64_MIN__ 1E-383DD
#define __DEC64_MAX__ 9.999999999999999E384DD
#define __DEC64_EPSILON__ 1E-15DD
#define __DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD
#define __DEC128_MANT_DIG__ 34
#define __DEC128_MIN_EXP__ (-6142)
#define __DEC128_MAX_EXP__ 6145
#define __DEC128_MIN__ 1E-6143DL
#define __DEC128_MAX__ 9.999999999999999999999999999999999E6144DL
#define __DEC128_EPSILON__ 1E-33DL
#define __DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL
#define __SFRACT_FBIT__ 7
#define __SFRACT_IBIT__ 0
#define __SFRACT_MIN__ (-0.5HR-0.5HR)
#define __SFRACT_MAX__ 0X7FP-7HR
#define __SFRACT_EPSILON__ 0x1P-7HR
#define __USFRACT_FBIT__ 8
#define __USFRACT_IBIT__ 0
#define __USFRACT_MIN__ 0.0UHR
#define __USFRACT_MAX__ 0XFFP-8UHR
#define __USFRACT_EPSILON__ 0x1P-8UHR
#define __FRACT_FBIT__ 15
#define __FRACT_IBIT__ 0
#define __FRACT_MIN__ (-0.5R-0.5R)
#define __FRACT_MAX__ 0X7FFFP-15R
#define __FRACT_EPSILON__ 0x1P-15R
#define __UFRACT_FBIT__ 16
#define __UFRACT_IBIT__ 0
#define __UFRACT_MIN__ 0.0UR
#define __UFRACT_MAX__ 0XFFFFP-16UR
#define __UFRACT_EPSILON__ 0x1P-16UR
#define __LFRACT_FBIT__ 31
#define __LFRACT_IBIT__ 0
#define __LFRACT_MIN__ (-0.5LR-0.5LR)
#define __LFRACT_MAX__ 0X7FFFFFFFP-31LR
#define __LFRACT_EPSILON__ 0x1P-31LR
#define __ULFRACT_FBIT__ 32
#define __ULFRACT_IBIT__ 0
#define __ULFRACT_MIN__ 0.0ULR
#define __ULFRACT_MAX__ 0XFFFFFFFFP-32ULR
#define __ULFRACT_EPSILON__ 0x1P-32ULR
#define __LLFRACT_FBIT__ 63
#define __LLFRACT_IBIT__ 0
#define __LLFRACT_MIN__ (-0.5LLR-0.5LLR)
#define __LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR
#define __LLFRACT_EPSILON__ 0x1P-63LLR
#define __ULLFRACT_FBIT__ 64
#define __ULLFRACT_IBIT__ 0
#define __ULLFRACT_MIN__ 0.0ULLR
#define __ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR
#define __ULLFRACT_EPSILON__ 0x1P-64ULLR
#define __SACCUM_FBIT__ 7
#define __SACCUM_IBIT__ 8
#define __SACCUM_MIN__ (-0X1P7HK-0X1P7HK)
#define __SACCUM_MAX__ 0X7FFFP-7HK
#define __SACCUM_EPSILON__ 0x1P-7HK
#define __USACCUM_FBIT__ 8
#define __USACCUM_IBIT__ 8
#define __USACCUM_MIN__ 0.0UHK
#define __USACCUM_MAX__ 0XFFFFP-8UHK
#define __USACCUM_EPSILON__ 0x1P-8UHK
#define __ACCUM_FBIT__ 15
#define __ACCUM_IBIT__ 16
#define __ACCUM_MIN__ (-0X1P15K-0X1P15K)
#define __ACCUM_MAX__ 0X7FFFFFFFP-15K
#define __ACCUM_EPSILON__ 0x1P-15K
#define __UACCUM_FBIT__ 16
#define __UACCUM_IBIT__ 16
#define __UACCUM_MIN__ 0.0UK
#define __UACCUM_MAX__ 0XFFFFFFFFP-16UK
#define __UACCUM_EPSILON__ 0x1P-16UK
#define __LACCUM_FBIT__ 31
#define __LACCUM_IBIT__ 32
#define __LACCUM_MIN__ (-0X1P31LK-0X1P31LK)
#define __LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK
#define __LACCUM_EPSILON__ 0x1P-31LK
#define __ULACCUM_FBIT__ 32
#define __ULACCUM_IBIT__ 32
#define __ULACCUM_MIN__ 0.0ULK
#define __ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK
#define __ULACCUM_EPSILON__ 0x1P-32ULK
#define __LLACCUM_FBIT__ 31
#define __LLACCUM_IBIT__ 32
#define __LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)
#define __LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK
#define __LLACCUM_EPSILON__ 0x1P-31LLK
#define __ULLACCUM_FBIT__ 32
#define __ULLACCUM_IBIT__ 32
#define __ULLACCUM_MIN__ 0.0ULLK
#define __ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK
#define __ULLACCUM_EPSILON__ 0x1P-32ULLK
#define __QQ_FBIT__ 7
#define __QQ_IBIT__ 0
#define __HQ_FBIT__ 15
#define __HQ_IBIT__ 0
#define __SQ_FBIT__ 31
#define __SQ_IBIT__ 0
#define __DQ_FBIT__ 63
#define __DQ_IBIT__ 0
#define __TQ_FBIT__ 127
#define __TQ_IBIT__ 0
#define __UQQ_FBIT__ 8
#define __UQQ_IBIT__ 0
#define __UHQ_FBIT__ 16
#define __UHQ_IBIT__ 0
#define __USQ_FBIT__ 32
#define __USQ_IBIT__ 0
#define __UDQ_FBIT__ 64
#define __UDQ_IBIT__ 0
#define __UTQ_FBIT__ 128
#define __UTQ_IBIT__ 0
#define __HA_FBIT__ 7
#define __HA_IBIT__ 8
#define __SA_FBIT__ 15
#define __SA_IBIT__ 16
#define __DA_FBIT__ 31
#define __DA_IBIT__ 32
#define __TA_FBIT__ 63
#define __TA_IBIT__ 64
#define __UHA_FBIT__ 8
#define __UHA_IBIT__ 8
#define __USA_FBIT__ 16
#define __USA_IBIT__ 16
#define __UDA_FBIT__ 32
#define __UDA_IBIT__ 32
#define __UTA_FBIT__ 64
#define __UTA_IBIT__ 64
#define __REGISTER_PREFIX__ 
#define __USER_LABEL_PREFIX__ 
#define __GNUC_STDC_INLINE__ 1
#define __STRICT_ANSI__ 1
#define __CHAR_UNSIGNED__ 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 1
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 1
#define __GCC_ATOMIC_SHORT_LOCK_FREE 1
#define __GCC_ATOMIC_INT_LOCK_FREE 1
#define __GCC_ATOMIC_LONG_LOCK_FREE 1
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 1
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#undef __ARM_FEATURE_DSP
# 1 "<built-in>"
#undef __ARM_FEATURE_QBIT
# 1 "<built-in>"
#undef __ARM_FEATURE_SAT
# 1 "<built-in>"
#undef __ARM_FEATURE_CRYPTO
# 1 "<built-in>"
#undef __ARM_FEATURE_UNALIGNED
# 1 "<built-in>"
#undef __ARM_FEATURE_QRDMX
# 1 "<built-in>"
#undef __ARM_FEATURE_CRC32
# 1 "<built-in>"
#undef __ARM_FEATURE_DOTPROD
# 1 "<built-in>"
#undef __ARM_FEATURE_COMPLEX
# 1 "<built-in>"
#undef __ARM_32BIT_STATE
# 1 "<built-in>"
#undef __ARM_FEATURE_CMSE
# 1 "<built-in>"
#undef __ARM_FEATURE_LDREX
# 1 "<built-in>"
#undef __ARM_FEATURE_CLZ
# 1 "<built-in>"
#undef __ARM_FEATURE_NUMERIC_MAXMIN
# 1 "<built-in>"
#undef __ARM_FEATURE_SIMD32
# 1 "<built-in>"
#define __ARM_SIZEOF_MINIMAL_ENUM 1
#define __ARM_SIZEOF_WCHAR_T 4
#undef __ARM_ARCH_PROFILE
# 1 "<built-in>"
#define __ARM_ARCH_PROFILE 77
#define __arm__ 1
#undef __ARM_ARCH
# 1 "<built-in>"
#define __ARM_ARCH 6
#define __APCS_32__ 1
#define __thumb__ 1
#undef __thumb2__
# 1 "<built-in>"
#define __THUMBEL__ 1
#undef __ARM_ARCH_ISA_THUMB
# 1 "<built-in>"
#define __ARM_ARCH_ISA_THUMB 1
#define __ARMEL__ 1
#define __SOFTFP__ 1
#define __VFP_FP__ 1
#undef __ARM_FP
# 1 "<built-in>"
#undef __ARM_FP16_FORMAT_IEEE
# 1 "<built-in>"
#undef __ARM_FP16_FORMAT_ALTERNATIVE
# 1 "<built-in>"
#undef __ARM_FP16_ARGS
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_FML
# 1 "<built-in>"
#undef __ARM_FEATURE_FMA
# 1 "<built-in>"
#undef __ARM_NEON__
# 1 "<built-in>"
#undef __ARM_NEON
# 1 "<built-in>"
#undef __ARM_NEON_FP
# 1 "<built-in>"
#define __THUMB_INTERWORK__ 1
#define __ARM_ARCH_6M__ 1
#define __ARM_PCS 1
#define __ARM_EABI__ 1
#undef __ARM_ARCH_EXT_IDIV__
# 1 "<built-in>"
#undef __ARM_FEATURE_IDIV
# 1 "<built-in>"
#undef __ARM_ASM_SYNTAX_UNIFIED__
# 1 "<built-in>"
#undef __ARM_FEATURE_COPROC
# 1 "<built-in>"
#define __GXX_TYPEINFO_EQUALITY_INLINE 0
#define __ELF__ 1
# 1 "<command-line>"
#define __USES_INITFINI__ 1
#define _HUB 1
#define DEBUG 1
#define STM32L0 1
#define STM32L052C8T6 1
# 1 "hub/src/cusb.c"
# 15 "hub/src/cusb.c"
# 1 "hub/include/hub/cusb.h" 1
# 29 "hub/include/hub/cusb.h"
#define CUSB_H 





# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 29 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 36 "hub/include/hub/cusb.h" 2
# 55 "hub/include/hub/cusb.h"
void cusb_init(void);

void cusb_test_poll(void);
void cusb_send(char character);
# 68 "hub/include/hub/cusb.h"

# 68 "hub/include/hub/cusb.h" 3 4
_Bool 
# 68 "hub/include/hub/cusb.h"
    cusb_connected(void);





void cusb_hook_reset(void);
void cusb_hook_hid_out_report(void);
void cusb_hook_hid_in_report(void);
# 16 "hub/src/cusb.c" 2

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 39 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 
# 131 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 
#define _PTRDIFF_T_DECLARED 




# 143 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 155 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 181 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#define __size_t__ 
#define __SIZE_T__ 
#define _SIZE_T 
#define _SYS_SIZE_T_H 
#define _T_SIZE_ 
#define _T_SIZE 
#define __SIZE_T 
#define _SIZE_T_ 
#define _BSD_SIZE_T_ 
#define _SIZE_T_DEFINED_ 
#define _SIZE_T_DEFINED 
#define _BSD_SIZE_T_DEFINED_ 
#define _SIZE_T_DECLARED 
#define ___int_size_t_h 
#define _GCC_SIZE_T 
#define _SIZET_ 






#define __size_t 





typedef unsigned int size_t;
# 231 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_size_t
# 260 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#define __wchar_t__ 
#define __WCHAR_T__ 
#define _WCHAR_T 
#define _T_WCHAR_ 
#define _T_WCHAR 
#define __WCHAR_T 
#define _WCHAR_T_ 
#define _BSD_WCHAR_T_ 
#define _WCHAR_T_DEFINED_ 
#define _WCHAR_T_DEFINED 
#define _WCHAR_T_H 
#define ___int_wchar_t_h 
#define __INT_WCHAR_T_H 
#define _GCC_WCHAR_T 
#define _WCHAR_T_DECLARED 
# 287 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef _BSD_WCHAR_T_
# 321 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 340 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 18 "hub/src/cusb.c" 2


# 1 "libopencm3/include/libopencm3/stm32/syscfg.h" 1
# 20 "libopencm3/include/libopencm3/stm32/syscfg.h"
# 1 "libopencm3/include/libopencm3/cm3/common.h" 1
# 21 "libopencm3/include/libopencm3/cm3/common.h"
#define LIBOPENCM3_CM3_COMMON_H 
# 33 "libopencm3/include/libopencm3/cm3/common.h"
#define BEGIN_DECLS 
#define END_DECLS 






#define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))
# 63 "libopencm3/include/libopencm3/cm3/common.h"
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 1 3 4
# 9 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 1 3 4





#define _MACHINE__DEFAULT_TYPES_H 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 1 3 4
# 22 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
#define _SYS_FEATURES_H 





# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_newlib_version.h" 1 3 4



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 29 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 2 3 4




#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
#define __XSI_VISIBLE 0
# 330 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/features.h" 3 4
#define __SSP_FORTIFY_LEVEL 0
# 9 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 2 3 4






#define __EXP(x) __ ##x ##__
# 26 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
#define __have_longlong64 1






#define __have_long32 1







typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
#undef __EXP
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _SYS__INTSUP_H 





#define __STDINT_EXP(x) __ ##x ##__
# 35 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef __int20
#undef __int20__
#undef long
#define signed +0
#define unsigned +0
#define char +0
#define short +1
#define __int20 +2
#define __int20__ +2
#define int +2
#define long +4
# 67 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _INTPTR_EQ_INT 






#define _INT32_EQ_LONG 







#define __INT8 "hh"
# 93 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT16 "h"
# 104 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT32 "l"
# 113 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT64 "ll"






#define __FAST8 
# 129 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST16 






#define __FAST32 
# 147 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST64 "ll"



#define __LEAST8 "hh"
# 162 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST16 "h"
# 173 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST32 "l"
# 182 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST64 "ll"

#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef long
       
       
       
       
       
# 194 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20
       
# 195 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20__
       
       
# 14 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_stdint.h" 3 4
#define _SYS__STDINT_H 
# 20 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_stdint.h" 3 4
typedef __int8_t int8_t ;
#define _INT8_T_DECLARED 


typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED 

#define __int8_t_defined 1




typedef __int16_t int16_t ;
#define _INT16_T_DECLARED 


typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED 

#define __int16_t_defined 1




typedef __int32_t int32_t ;
#define _INT32_T_DECLARED 


typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED 

#define __int32_t_defined 1




typedef __int64_t int64_t ;
#define _INT64_T_DECLARED 


typedef __uint64_t uint64_t ;
#define _UINT64_T_DECLARED 

#define __int64_t_defined 1



typedef __intmax_t intmax_t;
#define _INTMAX_T_DECLARED 



typedef __uintmax_t uintmax_t;
#define _UINTMAX_T_DECLARED 



typedef __intptr_t intptr_t;
#define _INTPTR_T_DECLARED 



typedef __uintptr_t uintptr_t;
#define _UINTPTR_T_DECLARED 
# 15 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 2 3 4






typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
#define __int_least8_t_defined 1



typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
#define __int_least16_t_defined 1



typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
#define __int_least32_t_defined 1



typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
#define __int_least64_t_defined 1
# 51 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
#define __int_fast8_t_defined 1







  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
#define __int_fast16_t_defined 1







  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
#define __int_fast32_t_defined 1







  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;
#define __int_fast64_t_defined 1
# 128 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INTPTR_MIN (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX (__INTPTR_MAX__)
#define UINTPTR_MAX (__UINTPTR_MAX__)
# 152 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT8_MIN (-__INT8_MAX__ - 1)
#define INT8_MAX (__INT8_MAX__)
#define UINT8_MAX (__UINT8_MAX__)







#define INT_LEAST8_MIN (-__INT_LEAST8_MAX__ - 1)
#define INT_LEAST8_MAX (__INT_LEAST8_MAX__)
#define UINT_LEAST8_MAX (__UINT_LEAST8_MAX__)
# 174 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT16_MIN (-__INT16_MAX__ - 1)
#define INT16_MAX (__INT16_MAX__)
#define UINT16_MAX (__UINT16_MAX__)







#define INT_LEAST16_MIN (-__INT_LEAST16_MAX__ - 1)
#define INT_LEAST16_MAX (__INT_LEAST16_MAX__)
#define UINT_LEAST16_MAX (__UINT_LEAST16_MAX__)
# 196 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT32_MIN (-__INT32_MAX__ - 1)
#define INT32_MAX (__INT32_MAX__)
#define UINT32_MAX (__UINT32_MAX__)
# 212 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST32_MIN (-__INT_LEAST32_MAX__ - 1)
#define INT_LEAST32_MAX (__INT_LEAST32_MAX__)
#define UINT_LEAST32_MAX (__UINT_LEAST32_MAX__)
# 230 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT64_MIN (-__INT64_MAX__ - 1)
#define INT64_MAX (__INT64_MAX__)
#define UINT64_MAX (__UINT64_MAX__)
# 246 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST64_MIN (-__INT_LEAST64_MAX__ - 1)
#define INT_LEAST64_MAX (__INT_LEAST64_MAX__)
#define UINT_LEAST64_MAX (__UINT_LEAST64_MAX__)
# 262 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST8_MIN (-__INT_FAST8_MAX__ - 1)
#define INT_FAST8_MAX (__INT_FAST8_MAX__)
#define UINT_FAST8_MAX (__UINT_FAST8_MAX__)
# 278 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST16_MIN (-__INT_FAST16_MAX__ - 1)
#define INT_FAST16_MAX (__INT_FAST16_MAX__)
#define UINT_FAST16_MAX (__UINT_FAST16_MAX__)
# 294 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST32_MIN (-__INT_FAST32_MAX__ - 1)
#define INT_FAST32_MAX (__INT_FAST32_MAX__)
#define UINT_FAST32_MAX (__UINT_FAST32_MAX__)
# 310 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST64_MIN (-__INT_FAST64_MAX__ - 1)
#define INT_FAST64_MAX (__INT_FAST64_MAX__)
#define UINT_FAST64_MAX (__UINT_FAST64_MAX__)
# 326 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_MAX (__INTMAX_MAX__)
#define INTMAX_MIN (-INTMAX_MAX - 1)







#define UINTMAX_MAX (__UINTMAX_MAX__)







#define SIZE_MAX (__SIZE_MAX__)





#define SIG_ATOMIC_MIN (-__STDINT_EXP(INT_MAX) - 1)
#define SIG_ATOMIC_MAX (__STDINT_EXP(INT_MAX))



#define PTRDIFF_MAX (__PTRDIFF_MAX__)



#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)




#define WCHAR_MIN (__WCHAR_MIN__)
# 374 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define WCHAR_MAX (__WCHAR_MAX__)
# 384 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define WINT_MAX (__WINT_MAX__)




#define WINT_MIN (__WINT_MIN__)






#define INT8_C(x) __INT8_C(x)
#define UINT8_C(x) __UINT8_C(x)
# 408 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT16_C(x) __INT16_C(x)
#define UINT16_C(x) __UINT16_C(x)
# 420 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT32_C(x) __INT32_C(x)
#define UINT32_C(x) __UINT32_C(x)
# 433 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INT64_C(x) __INT64_C(x)
#define UINT64_C(x) __UINT64_C(x)
# 449 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_C(x) __INTMAX_C(x)
#define UINTMAX_C(x) __UINTMAX_C(x)
# 10 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 64 "libopencm3/include/libopencm3/cm3/common.h" 2



#define MMIO8(addr) (*(volatile uint8_t *)(addr))
#define MMIO16(addr) (*(volatile uint16_t *)(addr))
#define MMIO32(addr) (*(volatile uint32_t *)(addr))
#define MMIO64(addr) (*(volatile uint64_t *)(addr))


#define BBIO_SRAM(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)


#define BBIO_PERIPH(addr,bit) MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)




#define BIT0 (1<<0)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)
#define BIT8 (1<<8)
#define BIT9 (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)
#define BIT16 (1<<16)
#define BIT17 (1<<17)
#define BIT18 (1<<18)
#define BIT19 (1<<19)
#define BIT20 (1<<20)
#define BIT21 (1<<21)
#define BIT22 (1<<22)
#define BIT23 (1<<23)
#define BIT24 (1<<24)
#define BIT25 (1<<25)
#define BIT26 (1<<26)
#define BIT27 (1<<27)
#define BIT28 (1<<28)
#define BIT29 (1<<29)
#define BIT30 (1<<30)
#define BIT31 (1<<31)
# 21 "libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 1 "libopencm3/include/libopencm3/stm32/memorymap.h" 1
# 21 "libopencm3/include/libopencm3/stm32/memorymap.h"
#define LIBOPENCM3_MEMORYMAP_COMMON_H 
# 36 "libopencm3/include/libopencm3/stm32/memorymap.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/memorymap.h" 1
# 19 "libopencm3/include/libopencm3/stm32/l0/memorymap.h"
#define LIBOPENCM3_MEMORYMAP_H 

# 1 "libopencm3/include/libopencm3/cm3/memorymap.h" 1
# 21 "libopencm3/include/libopencm3/cm3/memorymap.h"
#define LIBOPENCM3_CM3_MEMORYMAP_H 




#define PPBI_BASE (0xE0000000U)
# 42 "libopencm3/include/libopencm3/cm3/memorymap.h"
#define SCS_BASE (PPBI_BASE + 0xE000)
# 60 "libopencm3/include/libopencm3/cm3/memorymap.h"
#define SYS_TICK_BASE (SCS_BASE + 0x0010)


#define NVIC_BASE (SCS_BASE + 0x0100)


#define SCB_BASE (SCS_BASE + 0x0D00)


#define MPU_BASE (SCS_BASE + 0x0D90)




#define DEBUG_BASE (SCS_BASE + 0x0DF0)
# 91 "libopencm3/include/libopencm3/cm3/memorymap.h"
#define CORESIGHT_LSR_OFFSET 0xfb4
#define CORESIGHT_LAR_OFFSET 0xfb0


#define CORESIGHT_LSR_SLK (1<<1)

#define CORESIGHT_LSR_SLI (1<<0)

#define CORESIGHT_LAR_KEY 0xC5ACCE55
# 22 "libopencm3/include/libopencm3/stm32/l0/memorymap.h" 2




#define PERIPH_BASE (0x40000000U)
#define IOPORT_BASE (0x50000000U)
#define INFO_BASE (0x1ff80000U)
#define PERIPH_BASE_APB1 (PERIPH_BASE + 0x00000)
#define PERIPH_BASE_APB2 (PERIPH_BASE + 0x10000)
#define PERIPH_BASE_AHB (PERIPH_BASE + 0x20000)




#define TIM2_BASE (PERIPH_BASE_APB1 + 0x0000)
#define TIM3_BASE (PERIPH_BASE_APB1 + 0x0400)
#define TIM6_BASE (PERIPH_BASE_APB1 + 0x1000)
#define TIM7_BASE (PERIPH_BASE_APB1 + 0x1400)
#define LCD_BASE (PERIPH_BASE_APB1 + 0x2400)
#define RTC_BASE (PERIPH_BASE_APB1 + 0x2800)
#define WWDG_BASE (PERIPH_BASE_APB1 + 0x2c00)
#define IWDG_BASE (PERIPH_BASE_APB1 + 0x3000)
#define SPI2_BASE (PERIPH_BASE_APB1 + 0x3800)
#define USART2_BASE (PERIPH_BASE_APB1 + 0x4400)
#define LPUART1_BASE (PERIPH_BASE_APB1 + 0x4800)
#define I2C1_BASE (PERIPH_BASE_APB1 + 0x5400)
#define I2C2_BASE (PERIPH_BASE_APB1 + 0x5800)
#define USB_DEV_FS_BASE (PERIPH_BASE_APB1 + 0x5c00)
#define USB_PMA_BASE (PERIPH_BASE_APB1 + 0x6000)
#define CRS_BASE (PERIPH_BASE_APB1 + 0x6C00)
#define POWER_CONTROL_BASE (PERIPH_BASE_APB1 + 0x7000)
#define DAC_BASE (PERIPH_BASE_APB1 + 0x7400)
#define I2C3_BASE (PERIPH_BASE_APB1 + 0x7800)
#define LPTIM1_BASE (PERIPH_BASE_APB1 + 0x7c00)



#define SYSCFG_BASE (PERIPH_BASE_APB2 + 0x0000)
#define EXTI_BASE (PERIPH_BASE_APB2 + 0x0400)
#define TIM21_BASE (PERIPH_BASE_APB2 + 0x0800)
#define TIM22_BASE (PERIPH_BASE_APB2 + 0x1400)
#define FIREWALL_BASE (PERIPH_BASE_APB2 + 0x1C00)
#define ADC1_BASE (PERIPH_BASE_APB2 + 0x2400)
#define SPI1_BASE (PERIPH_BASE_APB2 + 0x3000)
#define USART1_BASE (PERIPH_BASE_APB2 + 0x3800)
#define DBGMCU_BASE (PERIPH_BASE_APB2 + 0x5800)


#define DMA1_BASE (PERIPH_BASE_AHB + 0x00000)
#define RCC_BASE (PERIPH_BASE_AHB + 0x01000)
#define FLASH_MEM_INTERFACE_BASE (PERIPH_BASE_AHB + 0x02000)
#define CRC_BASE (PERIPH_BASE_AHB + 0x03000)
#define TSC_BASE (PERIPH_BASE_AHB + 0x04000)
#define RNG_BASE (PERIPH_BASE_AHB + 0x05000)
#define AES_BASE (PERIPH_BASE_AHB + 0x06000)

#define GPIO_PORT_A_BASE (IOPORT_BASE + 0x00000)
#define GPIO_PORT_B_BASE (IOPORT_BASE + 0x00400)
#define GPIO_PORT_C_BASE (IOPORT_BASE + 0x00800)
#define GPIO_PORT_D_BASE (IOPORT_BASE + 0x00c00)
#define GPIO_PORT_H_BASE (IOPORT_BASE + 0x01C00)


#define DESIG_FLASH_SIZE_BASE (INFO_BASE + 0x7C)
#define DESIG_UNIQUE_ID_BASE (INFO_BASE + 0x50)
#define DESIG_UNIQUE_ID0 MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1 MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2 MMIO32(DESIG_UNIQUE_ID_BASE + 0x14)


#define ST_VREFINT_CAL MMIO16((INFO_BASE + 0x78))
#define ST_TSENSE_CAL1_30C MMIO16((INFO_BASE + 0x7A))
#define ST_TSENSE_CAL2_110C MMIO16((INFO_BASE + 0x7E))
# 37 "libopencm3/include/libopencm3/stm32/memorymap.h" 2
# 22 "libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 34 "libopencm3/include/libopencm3/stm32/syscfg.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/syscfg.h" 1
# 36 "libopencm3/include/libopencm3/stm32/l0/syscfg.h"
#define LIBOPENCM3_SYSCFG_H 
# 47 "libopencm3/include/libopencm3/stm32/l0/syscfg.h"
#define SYSCFG_CFGR1 MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_CFGR2 MMIO32(SYSCFG_BASE + 0x04)
#define SYSCFG_EXTICR(i) MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1 SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2 SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3 SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4 SYSCFG_EXTICR(3)
#define COMP1_CTRL MMIO32(SYSCFG_BASE + 0x18)
#define COMP2_CTRL MMIO32(SYSCFG_BASE + 0x1C)
#define SYSCFG_CFGR3 MMIO32(SYSCFG_BASE + 0x20)







#define SYSCFG_CFGR1_MEM_MODE_SHIFT 0
#define SYSCFG_CFGR1_MEM_MODE (3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_FLASH (0 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SYSTEM (1 << SYSCFG_CFGR1_MEM_MODE_SHIFT)
#define SYSCFG_CFGR1_MEM_MODE_SRAM (3 << SYSCFG_CFGR1_MEM_MODE_SHIFT)

#define SYSCFG_CFGR1_UFB (1<<3)

#define SYSCFG_CFGR1_BOOT_MODE_SHIFT 8
#define SYSCFG_CFGR1_BOOT_MODE (3 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_FLASH (0 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_SYSTEM (1 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)
#define SYSCFG_CFGR1_BOOT_MODE_SRAM (3 << SYSCFG_CFGR1_BOOT_MODE_SHIFT)



#define SYSCFG_CFGR2_FWDIS (1 << 0)

#define SYSCFG_CFGR2_I2C_PB6_FMP (1 << 8)
#define SYSCFG_CFGR2_I2C_PB7_FMP (1 << 9)
#define SYSCFG_CFGR2_I2C_PB8_FMP (1 << 10)
#define SYSCFG_CFGR2_I2C_PB9_FMP (1 << 11)

#define SYSCFG_CFGR2_I2C1_FMP (1 << 12)
#define SYSCFG_CFGR2_I2C2_FMP (1 << 13)
#define SYSCFG_CFGR2_I2C3_FMP (1 << 14)



#define SYSCFG_CFGR3_EN_VREFINT (1 << 0)

#define SYSCFG_CFGR3_SEL_VREF_OUT_SHIFT 4
#define SYSCFG_CFGR3_SEL_VREF_OUT (3 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)
#define SYSCFG_CFGR3_SEL_VREF_OUT_PB0 (1 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)
#define SYSCFG_CFGR3_SEL_VREF_OUT_PB1 (2 << SYSCFG_CFGR3_EN_VREFINT_SHIFT)

#define SYSCFG_CFGR3_ENBUF_VREFINT_ADC (1 << 8)
#define SYSCFG_CFGR3_ENBUF_SENSOR_ADC (1 << 9)
#define SYSCFG_CFGR3_ENBUF_VREFINT_COMP (1 << 12)
#define SYSCFG_CFGR3_ENREF_HSI48 (1 << 13)

#define SYSCFG_CFGR3_REF_HSI48_RDYF (1 << 26)
#define SYSCFG_CFGR3_SENSOR_ADC_RDYF (1 << 27)
#define SYSCFG_CFGR3_VREFINT_ADC_RDYF (1 << 28)
#define SYSCFG_CFGR3_VREFINT_COMP_RDYF (1 << 29)
#define SYSCFG_CFGR3_VREFINT_RDYF (1 << 30)
#define SYSCFG_CFGR3_REF_LOCK (1 << 31)



#define SYSCFG_EXTICR_FIELDSIZE 4
#define SYSCFG_EXTICR_GPIOA 0
#define SYSCFG_EXTICR_GPIOB 1
#define SYSCFG_EXTICR_GPIOC 2
#define SYSCFG_EXTICR_GPIOD 3
#define SYSCFG_EXTICR_GPIOE 4
#define SYSCFG_EXTICR_GPIOH 5
# 130 "libopencm3/include/libopencm3/stm32/l0/syscfg.h"



# 35 "libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 21 "hub/src/cusb.c" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 36 "libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/rcc.h" 1
# 41 "libopencm3/include/libopencm3/stm32/l0/rcc.h"
#define LIBOPENCM3_RCC_H 



# 1 "libopencm3/include/libopencm3/stm32/pwr.h" 1
# 38 "libopencm3/include/libopencm3/stm32/pwr.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/pwr.h" 1
# 32 "libopencm3/include/libopencm3/stm32/l0/pwr.h"
#define LIBOPENCM3_PWR_H 

# 1 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h" 1
# 27 "libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h"
#define LIBOPENCM3_PWR_COMMON_V2_H 

# 1 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 1
# 34 "libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
#define LIBOPENCM3_PWR_COMMON_V1_H 






#define PWR_CR MMIO32(POWER_CONTROL_BASE + 0x00)


#define PWR_CSR MMIO32(POWER_CONTROL_BASE + 0x04)






#define PWR_CR_DBP (1 << 8)


#define PWR_CR_PLS_LSB 5




#define PWR_CR_PLS_2V2 (0x0 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V3 (0x1 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V4 (0x2 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V5 (0x3 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V6 (0x4 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V7 (0x5 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V8 (0x6 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V9 (0x7 << PWR_CR_PLS_LSB)

#define PWR_CR_PLS_MASK (0x7 << PWR_CR_PLS_LSB)


#define PWR_CR_PVDE (1 << 4)


#define PWR_CR_CSBF (1 << 3)


#define PWR_CR_CWUF (1 << 2)


#define PWR_CR_PDDS (1 << 1)


#define PWR_CR_LPDS (1 << 0)






#define PWR_CSR_EWUP (1 << 8)




#define PWR_CSR_PVDO (1 << 2)


#define PWR_CSR_SBF (1 << 1)


#define PWR_CSR_WUF (1 << 0)






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






#define PWR_CR_LPRUN (1 << 14)


#define PWR_CR_VOS_LSB 11




#define PWR_CR_VOS_RANGE1 (0x1 << PWR_CR_VOS_LSB)
#define PWR_CR_VOS_RANGE2 (0x2 << PWR_CR_VOS_LSB)
#define PWR_CR_VOS_RANGE3 (0x3 << PWR_CR_VOS_LSB)

#define PWR_CR_VOS_MASK (0x3 << PWR_CR_VOS_LSB)


#define PWR_CR_FWU (1 << 10)


#define PWR_CR_ULP (1 << 9)


#define PWR_CR_LPSDSR (1 << 0)




#define PWR_CSR_EWUP2 (1 << 9)


#define PWR_CSR_EWUP1 PWR_CSR_EWUP


#define PWR_CSR_REGLPF (1 << 5)


#define PWR_CSR_VOSF (1 << 4)


#define PWR_CSR_VREFINTRDYF (1 << 3)







enum pwr_vos_scale {

 PWR_SCALE1,

 PWR_SCALE2,

 PWR_SCALE3,
};



void pwr_set_vos_scale(enum pwr_vos_scale scale);


# 35 "libopencm3/include/libopencm3/stm32/l0/pwr.h" 2
# 39 "libopencm3/include/libopencm3/stm32/pwr.h" 2
# 46 "libopencm3/include/libopencm3/stm32/l0/rcc.h" 2



#define RCC_CR MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR MMIO32(RCC_BASE + 0x04)
#define RCC_CRRCR MMIO32(RCC_BASE + 0x08)
#define RCC_CFGR MMIO32(RCC_BASE + 0x0c)
#define RCC_CIER MMIO32(RCC_BASE + 0x10)
#define RCC_CIFR MMIO32(RCC_BASE + 0x14)
#define RCC_CICR MMIO32(RCC_BASE + 0x18)
#define RCC_IOPRSTR MMIO32(RCC_BASE + 0x1c)
#define RCC_AHBRSTR MMIO32(RCC_BASE + 0x20)
#define RCC_APB2RSTR MMIO32(RCC_BASE + 0x24)
#define RCC_APB1RSTR MMIO32(RCC_BASE + 0x28)
#define RCC_IOPENR MMIO32(RCC_BASE + 0x2c)
#define RCC_AHBENR MMIO32(RCC_BASE + 0x30)
#define RCC_APB2ENR MMIO32(RCC_BASE + 0x34)
#define RCC_APB1ENR MMIO32(RCC_BASE + 0x38)
#define RCC_IOPSMEN MMIO32(RCC_BASE + 0x3c)
#define RCC_AHBSMENR MMIO32(RCC_BASE + 0x40)
#define RCC_APB2SMENR MMIO32(RCC_BASE + 0x44)
#define RCC_APB1SMENR MMIO32(RCC_BASE + 0x48)
#define RCC_CCIPR MMIO32(RCC_BASE + 0x4c)
#define RCC_CSR MMIO32(RCC_BASE + 0x50)



#define RCC_CR_PLLRDY (1 << 25)
#define RCC_CR_PLLON (1 << 24)
#define RCC_CR_RTCPRE_SHIFT 20
#define RCC_CR_RTCPRE_MASK 0x3
#define RCC_CR_RTCPRE_DIV2 0
#define RCC_CR_RTCPRE_DIV4 1
#define RCC_CR_RTCPRE_DIV8 2
#define RCC_CR_RTCPRE_DIV16 3
#define RCC_CR_CSSHSEON (1 << 19)
#define RCC_CR_HSEBYP (1 << 18)
#define RCC_CR_HSERDY (1 << 17)
#define RCC_CR_HSEON (1 << 16)
#define RCC_CR_MSIRDY (1 << 9)
#define RCC_CR_MSION (1 << 8)
#define RCC_CR_HSI16DIVF (1 << 4)
#define RCC_CR_HSI16DIVEN (1 << 3)
#define RCC_CR_HSI16RDY (1 << 2)
#define RCC_CR_HSI16KERON (1 << 1)
#define RCC_CR_HSI16ON (1 << 0)




#define RCC_ICSCR_MSITRIM_SHIFT 24
#define RCC_ICSCR_MSITRIM_MASK 0xff
#define RCC_ICSCR_MSICAL_SHIFT 16
#define RCC_ICSCR_MSICAL_MASK 0xff

#define RCC_ICSCR_MSIRANGE_SHIFT 13
#define RCC_ICSCR_MSIRANGE_MASK 0x7
#define RCC_ICSCR_MSIRANGE_65KHZ 0x0
#define RCC_ICSCR_MSIRANGE_131KHZ 0x1
#define RCC_ICSCR_MSIRANGE_262KHZ 0x2
#define RCC_ICSCR_MSIRANGE_524KHZ 0x3
#define RCC_ICSCR_MSIRANGE_1MHZ 0x4
#define RCC_ICSCR_MSIRANGE_2MHZ 0x5
#define RCC_ICSCR_MSIRANGE_4MHZ 0x6

#define RCC_ICSCR_HSI16TRIM_SHIFT 8
#define RCC_ICSCR_HSI16TRIM_MASK 0x1f
#define RCC_ICSCR_HSI16CAL_SHIFT 0
#define RCC_ICSCR_HSI16CAL_MASK 0xff



#define RCC_CRRCR_HSI48CAL_SHIFT 8
#define RCC_CRRCR_HSI48CAL_MASK 0xff
#define RCC_CRRCR_HSI48RDY (1<<1)
#define RCC_CRRCR_HSI48ON (1<<0)




#define RCC_CFGR_MCOPRE_DIV1 0
#define RCC_CFGR_MCOPRE_DIV2 1
#define RCC_CFGR_MCOPRE_DIV4 2
#define RCC_CFGR_MCOPRE_DIV8 3
#define RCC_CFGR_MCOPRE_DIV16 4


#define RCC_CFGR_MCO_NOCLK 0x0
#define RCC_CFGR_MCO_SYSCLK 0x1
#define RCC_CFGR_MCO_HSI16 0x2
#define RCC_CFGR_MCO_MSI 0x3
#define RCC_CFGR_MCO_HSE 0x4
#define RCC_CFGR_MCO_PLL 0x5
#define RCC_CFGR_MCO_LSI 0x6
#define RCC_CFGR_MCO_LSE 0x7
#define RCC_CFGR_MCO_HSI48 0x8
#define RCC_CFGR_MCO_SHIFT 24
#define RCC_CFGR_MCO_MASK 0xf



#define RCC_CFGR_PLLDIV_DIV2 0x1
#define RCC_CFGR_PLLDIV_DIV3 0x2
#define RCC_CFGR_PLLDIV_DIV4 0x3

#define RCC_CFGR_PLLDIV_SHIFT 22
#define RCC_CFGR_PLLDIV_MASK 0x3



#define RCC_CFGR_PLLMUL_MUL3 0x0
#define RCC_CFGR_PLLMUL_MUL4 0x1
#define RCC_CFGR_PLLMUL_MUL6 0x2
#define RCC_CFGR_PLLMUL_MUL8 0x3
#define RCC_CFGR_PLLMUL_MUL12 0x4
#define RCC_CFGR_PLLMUL_MUL16 0x5
#define RCC_CFGR_PLLMUL_MUL24 0x6
#define RCC_CFGR_PLLMUL_MUL32 0x7
#define RCC_CFGR_PLLMUL_MUL48 0x8

#define RCC_CFGR_PLLMUL_SHIFT 18
#define RCC_CFGR_PLLMUL_MASK 0xf


#define RCC_CFGR_PLLSRC_HSI16_CLK 0x0
#define RCC_CFGR_PLLSRC_HSE_CLK 0x1


#define RCC_CFGR_STOPWUCK_MSI (0<<15)
#define RCC_CFGR_STOPWUCK_HSI16 (1<<15)




#define RCC_CFGR_PPRE2_NODIV 0x0
#define RCC_CFGR_PPRE2_DIV2 0x4
#define RCC_CFGR_PPRE2_DIV4 0x5
#define RCC_CFGR_PPRE2_DIV8 0x6
#define RCC_CFGR_PPRE2_DIV16 0x7

#define RCC_CFGR_PPRE2_MASK 0x7
#define RCC_CFGR_PPRE2_SHIFT 11




#define RCC_CFGR_PPRE1_NODIV 0x0
#define RCC_CFGR_PPRE1_DIV2 0x4
#define RCC_CFGR_PPRE1_DIV4 0x5
#define RCC_CFGR_PPRE1_DIV8 0x6
#define RCC_CFGR_PPRE1_DIV16 0x7

#define RCC_CFGR_PPRE1_MASK 0x7
#define RCC_CFGR_PPRE1_SHIFT 8




#define RCC_CFGR_HPRE_NODIV 0x0
#define RCC_CFGR_HPRE_DIV2 0x8
#define RCC_CFGR_HPRE_DIV4 0x9
#define RCC_CFGR_HPRE_DIV8 0xa
#define RCC_CFGR_HPRE_DIV16 0xb
#define RCC_CFGR_HPRE_DIV64 0xc
#define RCC_CFGR_HPRE_DIV128 0xd
#define RCC_CFGR_HPRE_DIV256 0xe
#define RCC_CFGR_HPRE_DIV512 0xf

#define RCC_CFGR_HPRE_MASK 0xf
#define RCC_CFGR_HPRE_SHIFT 4


#define RCC_CFGR_SWS_MSI 0x0
#define RCC_CFGR_SWS_HSI16 0x1
#define RCC_CFGR_SWS_HSE 0x2
#define RCC_CFGR_SWS_PLL 0x3
#define RCC_CFGR_SWS_MASK 0x3
#define RCC_CFGR_SWS_SHIFT 2


#define RCC_CFGR_SW_MSI 0x0
#define RCC_CFGR_SW_HSI16 0x1
#define RCC_CFGR_SW_HSE 0x2
#define RCC_CFGR_SW_PLL 0x3
#define RCC_CFGR_SW_MASK 0x3
#define RCC_CFGR_SW_SHIFT 0



#define RCC_CIER_CSSLSE (1 << 7)

#define RCC_CIER_HSI48RDYIE (1 << 6)
#define RCC_CIER_MSIRDYIE (1 << 5)
#define RCC_CIER_PLLRDYIE (1 << 4)
#define RCC_CIER_HSERDYIE (1 << 3)
#define RCC_CIER_HSI16RDYIE (1 << 2)
#define RCC_CIER_LSERDYIE (1 << 1)
#define RCC_CIER_LSIRDYIE (1 << 0)



#define RCC_CIFR_CSSHSEF (1 << 8)
#define RCC_CIFR_CSSLSEF (1 << 7)
#define RCC_CIFR_HSI48RDYF (1 << 6)
#define RCC_CIFR_MSIRDYF (1 << 5)
#define RCC_CIFR_PLLRDYF (1 << 4)
#define RCC_CIFR_HSERDYF (1 << 3)
#define RCC_CIFR_HSI16RDYF (1 << 2)
#define RCC_CIFR_LSERDYF (1 << 1)
#define RCC_CIFR_LSIRDYF (1 << 0)



#define RCC_CICR_CSSHSEC (1 << 8)
#define RCC_CICR_CSSLSEC (1 << 7)
#define RCC_CICR_HSI48RDYC (1 << 6)
#define RCC_CICR_MSIRDYC (1 << 5)
#define RCC_CICR_PLLRDYC (1 << 4)
#define RCC_CICR_HSERDYC (1 << 3)
#define RCC_CICR_HSI16RDYC (1 << 2)
#define RCC_CICR_LSERDYC (1 << 1)
#define RCC_CICR_LSIRDYC (1 << 0)



#define RCC_IOPPRSTR_IOPHRST (1<<7)
#define RCC_IOPPRSTR_IOPERST (1<<4)
#define RCC_IOPPRSTR_IOPDRST (1<<3)
#define RCC_IOPPRSTR_IOPCRST (1<<2)
#define RCC_IOPPRSTR_IOPBRST (1<<1)
#define RCC_IOPPRSTR_IOPARST (1<<0)



#define RCC_AHBRSTR_CRYPRST (1 << 24)
#define RCC_AHBRSTR_RNGRST (1 << 20)
#define RCC_AHBRSTR_TSCRST (1 << 16)
#define RCC_AHBRSTR_CRCRST (1 << 12)
#define RCC_AHBRSTR_MIFRST (1 << 8)
#define RCC_AHBRSTR_DMARST (1 << 0)




#define RCC_APB2RSTR_DBGRST (1 << 22)
#define RCC_APB2RSTR_USART1RST (1 << 14)
#define RCC_APB2RSTR_SPI1RST (1 << 12)
#define RCC_APB2RSTR_ADC1RST (1 << 9)
#define RCC_APB2RSTR_TIM22RST (1 << 5)
#define RCC_APB2RSTR_TIM21RST (1 << 2)
#define RCC_APB2RSTR_SYSCFGRST (1 << 0)




#define RCC_APB1RSTR_LPTIM1RST (1 << 31)
#define RCC_APB1RSTR_I2C3RST (1 << 30)
#define RCC_APB1RSTR_DACRST (1 << 29)
#define RCC_APB1RSTR_PWRRST (1 << 28)
#define RCC_APB1RSTR_CRSRST (1 << 27)
#define RCC_APB1RSTR_USBRST (1 << 23)
#define RCC_APB1RSTR_I2C2RST (1 << 22)
#define RCC_APB1RSTR_I2C1RST (1 << 21)
#define RCC_APB1RSTR_USART5RST (1 << 20)
#define RCC_APB1RSTR_USART4RST (1 << 19)
#define RCC_APB1RSTR_LPUART1RST (1 << 18)
#define RCC_APB1RSTR_USART2RST (1 << 17)
#define RCC_APB1RSTR_SPI2RST (1 << 14)
#define RCC_APB1RSTR_WWDGRST (1 << 11)
#define RCC_APB1RSTR_LCDRST (1 << 9)
#define RCC_APB1RSTR_TIM7RST (1 << 5)
#define RCC_APB1RSTR_TIM6RST (1 << 4)
#define RCC_APB1RSTR_TIM3RST (1 << 1)
#define RCC_APB1RSTR_TIM2RST (1 << 0)




#define RCC_IOPENR_IOPHEN (1<<7)
#define RCC_IOPENR_IOPEEN (1<<4)
#define RCC_IOPENR_IOPDEN (1<<3)
#define RCC_IOPENR_IOPCEN (1<<2)
#define RCC_IOPENR_IOPBEN (1<<1)
#define RCC_IOPENR_IOPAEN (1<<0)



#define RCC_AHBENR_CRYPEN (1 << 24)
#define RCC_AHBENR_RNGEN (1 << 20)
#define RCC_AHBENR_TSCEN (1 << 16)
#define RCC_AHBENR_CRCEN (1 << 12)
#define RCC_AHBENR_MIFEN (1 << 8)
#define RCC_AHBENR_DMAEN (1 << 0)




#define RCC_APB2ENR_DBGEN (1 << 22)
#define RCC_APB2ENR_USART1EN (1 << 14)
#define RCC_APB2ENR_SPI1EN (1 << 12)
#define RCC_APB2ENR_ADC1EN (1 << 9)
#define RCC_APB2ENR_MIFEN (1 << 7)
#define RCC_APB2ENR_TIM22EN (1 << 5)
#define RCC_APB2ENR_TIM21EN (1 << 2)
#define RCC_APB2ENR_SYSCFGEN (1 << 0)




#define RCC_APB1ENR_LPTIM1EN (1 << 31)
#define RCC_APB1ENR_DACEN (1 << 29)
#define RCC_APB1ENR_PWREN (1 << 28)
#define RCC_APB1ENR_CRSEN (1 << 27)
#define RCC_APB1ENR_USBEN (1 << 23)
#define RCC_APB1ENR_I2C2EN (1 << 22)
#define RCC_APB1ENR_I2C1EN (1 << 21)
#define RCC_APB1ENR_USART5EN (1 << 20)
#define RCC_APB1ENR_USART4EN (1 << 19)
#define RCC_APB1ENR_LPUART1EN (1 << 18)
#define RCC_APB1ENR_USART2EN (1 << 17)
#define RCC_APB1ENR_SPI2EN (1 << 14)
#define RCC_APB1ENR_WWDGEN (1 << 11)
#define RCC_APB1ENR_LCDEN (1 << 9)
#define RCC_APB1ENR_TIM7EN (1 << 5)
#define RCC_APB1ENR_TIM6EN (1 << 4)
#define RCC_APB1ENR_TIM3EN (1 << 1)
#define RCC_APB1ENR_TIM2EN (1 << 0)




#define RCC_IOPSMENR_IOPHSMEN (1<<7)
#define RCC_IOPSMENR_IOPESMEN (1<<4)
#define RCC_IOPSMENR_IOPDSMEN (1<<3)
#define RCC_IOPSMENR_IOPCSMEN (1<<2)
#define RCC_IOPSMENR_IOPBSMEN (1<<1)
#define RCC_IOPSMENR_IOPASMEN (1<<0)



#define RCC_AHBSMENR_CRYPSMEN (1 << 24)
#define RCC_AHBSMENR_RNGSMEN (1 << 20)
#define RCC_AHBSMENR_TSCSMEN (1 << 16)
#define RCC_AHBSMENR_CRCSMEN (1 << 12)
#define RCC_AHBSMENR_MIFSMEN (1 << 8)
#define RCC_AHBSMENR_DMASMEN (1 << 0)



#define RCC_APB2SMENR_DBGSMEN (1 << 22)
#define RCC_APB2SMENR_USART1SMEN (1 << 14)
#define RCC_APB2SMENR_SPI1SMEN (1 << 12)
#define RCC_APB2SMENR_ADC1SMEN (1 << 9)
#define RCC_APB2SMENR_MIFSMEN (1 << 7)
#define RCC_APB2SMENR_TIM22SMEN (1 << 5)
#define RCC_APB2SMENR_TIM21SMEN (1 << 2)
#define RCC_APB2SMENR_SYSCFGSMEN (1 << 0)



#define RCC_APB1SMENR_LPTIM1SMEN (1 << 31)
#define RCC_APB1SMENR_I2C3SMEN (1 << 30)
#define RCC_APB1SMENR_DACSMEN (1 << 29)
#define RCC_APB1SMENR_PWRSMEN (1 << 28)
#define RCC_APB1SMENR_CRSSMEN (1 << 27)
#define RCC_APB1SMENR_USBSMEN (1 << 23)
#define RCC_APB1SMENR_I2C2SMEN (1 << 22)
#define RCC_APB1SMENR_I2C1SMEN (1 << 21)
#define RCC_APB1SMENR_USART5SMEN (1 << 20)
#define RCC_APB1SMENR_USART4SMEN (1 << 19)
#define RCC_APB1SMENR_LPUART1SMEN (1 << 18)
#define RCC_APB1SMENR_USART2SMEN (1 << 17)
#define RCC_APB1SMENR_SPI2SMEN (1 << 14)
#define RCC_APB1SMENR_WWDGSMEN (1 << 11)
#define RCC_APB1SMENR_LCDSMEN (1 << 9)
#define RCC_APB1SMENR_TIM7SMEN (1 << 5)
#define RCC_APB1SMENR_TIM6SMEN (1 << 4)
#define RCC_APB1SMENR_TIM3SMEN (1 << 1)
#define RCC_APB1SMENR_TIM2SMEN (1 << 0)



#define RCC_CCIPR_HSI48SEL (1<<26)

#define RCC_CCIPR_LPTIM1SEL_APB 0
#define RCC_CCIPR_LPTIM1SEL_LSI 1
#define RCC_CCIPR_LPTIM1SEL_HSI16 2
#define RCC_CCIPR_LPTIM1SEL_LSE 3
#define RCC_CCIPR_LPTIM1SEL_SHIFT 18
#define RCC_CCIPR_LPTIM1SEL_MASK 0x3

#define RCC_CCIPR_I2C3SEL_APB 0
#define RCC_CCIPR_I2C3SEL_SYS 1
#define RCC_CCIPR_I2C3SEL_HSI16 2
#define RCC_CCIPR_I2C3SEL_SHIFT 16
#define RCC_CCIPR_I2C3SEL_MASK 0x3

#define RCC_CCIPR_I2C1SEL_APB 0
#define RCC_CCIPR_I2C1SEL_SYS 1
#define RCC_CCIPR_I2C1SEL_HSI16 2
#define RCC_CCIPR_I2C1SEL_SHIFT 12
#define RCC_CCIPR_I2C1SEL_MASK 0x3

#define RCC_CCIPR_LPUART1SEL_APB 0
#define RCC_CCIPR_LPUART1SEL_SYS 1
#define RCC_CCIPR_LPUART1SEL_HSI16 2
#define RCC_CCIPR_LPUART1SEL_LSE 3
#define RCC_CCIPR_LPUART1SEL_SHIFT 10
#define RCC_CCIPR_LPUART1SEL_MASK 0x3

#define RCC_CCIPR_USART2SEL_APB 0
#define RCC_CCIPR_USART2SEL_SYS 1
#define RCC_CCIPR_USART2SEL_HSI16 2
#define RCC_CCIPR_USART2SEL_LSE 3
#define RCC_CCIPR_USART2SEL_SHIFT 2
#define RCC_CCIPR_USART2SEL_MASK 0x3

#define RCC_CCIPR_USART1SEL_APB 0
#define RCC_CCIPR_USART1SEL_SYS 1
#define RCC_CCIPR_USART1SEL_HSI16 2
#define RCC_CCIPR_USART1SEL_LSE 3
#define RCC_CCIPR_USART1SEL_SHIFT 0
#define RCC_CCIPR_USART1SEL_MASK 0x3



#define RCC_CSR_LPWRRSTF (1 << 31)
#define RCC_CSR_WWDGRSTF (1 << 30)
#define RCC_CSR_IWDGRSTF (1 << 29)
#define RCC_CSR_SFTRSTF (1 << 28)
#define RCC_CSR_PORRSTF (1 << 27)
#define RCC_CSR_PINRSTF (1 << 26)
#define RCC_CSR_OBLRSTF (1 << 25)
#define RCC_CSR_FWRSTF (1 << 24)
#define RCC_CSR_RMVF (1 << 23)
#define RCC_CSR_RESET_FLAGS (RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF | RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF | RCC_CSR_PINRSTF | RCC_CSR_OBLRSTF | RCC_CSR_FWRSTF)


#define RCC_CSR_RTCRST (1 << 19)
#define RCC_CSR_RTCEN (1 << 18)
#define RCC_CSR_RTCSEL_SHIFT (16)
#define RCC_CSR_RTCSEL_MASK (0x3)
#define RCC_CSR_RTCSEL_NONE (0x0)
#define RCC_CSR_RTCSEL_LSE (0x1)
#define RCC_CSR_RTCSEL_LSI (0x2)
#define RCC_CSR_RTCSEL_HSE (0x3)
#define RCC_CSR_CSSLSED (1 << 14)
#define RCC_CSR_CSSLSEON (1 << 13)
#define RCC_CSR_LSEDRV_SHIFT 11
#define RCC_CSR_LSEDRV_MASK 0x3
#define RCC_CSR_LSEDRV_LOWEST 0
#define RCC_CSR_LSEDRV_MLOW 1
#define RCC_CSR_LSEDRV_MHIGH 2
#define RCC_CSR_LSEDRV_HIGHEST 3
#define RCC_CSR_LSEBYP (1 << 10)
#define RCC_CSR_LSERDY (1 << 9)
#define RCC_CSR_LSEON (1 << 8)
#define RCC_CSR_LSIRDY (1 << 1)
#define RCC_CSR_LSION (1 << 0)

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


#define _REG_BIT(base,bit) (((base) << 5) + (bit))

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
# 35 "libopencm3/include/libopencm3/stm32/common/rcc_common_all.h"
#define LIBOPENCM3_RCC_COMMON_ALL_H 





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
# 22 "hub/src/cusb.c" 2
# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 36 "libopencm3/include/libopencm3/stm32/flash.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/flash.h" 1
# 31 "libopencm3/include/libopencm3/stm32/l0/flash.h"
#define LIBOPENCM3_FLASH_H 


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
# 29 "libopencm3/include/libopencm3/stm32/common/flash_common_l01.h"
#define LIBOPENCM3_FLASH_COMMON_L01_H 






#define FLASH_ACR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_PECR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_PDKEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_PEKEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_PRGKEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_OPTKEYR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_SR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)
#define FLASH_OBR MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1c)
#define FLASH_WRPR1 MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)
#define FLASH_WRPR2 MMIO32(FLASH_MEM_INTERFACE_BASE + 0x80)


#define FLASH_ACR_RUNPD (1 << 4)
#define FLASH_ACR_SLEEPPD (1 << 3)
#define FLASH_ACR_PRFTEN (1 << 1)
#define FLASH_ACR_LATENCY_SHIFT 0
#define FLASH_ACR_LATENCY_MASK 1



#define FLASH_ACR_LATENCY_0WS 0x00
#define FLASH_ACR_LATENCY_1WS 0x01



#define FLASH_PECR_OBL_LAUNCH (1 << 18)
#define FLASH_PECR_ERRIE (1 << 17)
#define FLASH_PECR_EOPIE (1 << 16)
#define FLASH_PECR_PARALLBANK (1 << 15)
#define FLASH_PECR_FPRG (1 << 10)
#define FLASH_PECR_ERASE (1 << 9)
#define FLASH_PECR_FTDW (1 << 8)
#define FLASH_PECR_DATA (1 << 4)
#define FLASH_PECR_PROG (1 << 3)
#define FLASH_PECR_OPTLOCK (1 << 2)
#define FLASH_PECR_PRGLOCK (1 << 1)
#define FLASH_PECR_PELOCK (1 << 0)


#define FLASH_PDKEYR_PDKEY1 ((uint32_t)0x04152637)
#define FLASH_PDKEYR_PDKEY2 ((uint32_t)0xFAFBFCFD)


#define FLASH_PEKEYR_PEKEY1 ((uint32_t)0x89ABCDEF)
#define FLASH_PEKEYR_PEKEY2 ((uint32_t)0x02030405)


#define FLASH_PRGKEYR_PRGKEY1 ((uint32_t)0x8C9DAEBF)
#define FLASH_PRGKEYR_PRGKEY2 ((uint32_t)0x13141516)


#define FLASH_OPTKEYR_KEY1 ((uint32_t)0xFBEAD9C8)
#define FLASH_OPTKEYR_KEY2 ((uint32_t)0x24252627)


#define FLASH_SR_OPTVERR (1 << 11)
#define FLASH_SR_SIZEERR (1 << 10)
#define FLASH_SR_PGAERR (1 << 9)
#define FLASH_SR_WRPERR (1 << 8)
#define FLASH_SR_READY (1 << 3)
#define FLASH_SR_ENDHV (1 << 2)
#define FLASH_SR_EOP (1 << 1)
#define FLASH_SR_BSY (1 << 0)


#define FLASH_OBR_BFB2 (1 << 23)
#define FLASH_OBR_NRST_STDBY (1 << 22)
#define FLASH_OBR_NRST_STOP (1 << 21)
#define FLASH_OBR_IWDG_SW (1 << 20)
#define FLASH_OBR_BOR_OFF (0x0 << 16)
#define FLASH_OBR_BOR_LEVEL_1 (0x8 << 16)
#define FLASH_OBR_BOR_LEVEL_2 (0x9 << 16)
#define FLASH_OBR_BOR_LEVEL_3 (0xa << 16)
#define FLASH_OBR_BOR_LEVEL_4 (0xb << 16)
#define FLASH_OBR_BOR_LEVEL_5 (0xc << 16)
#define FLASH_OBR_RDPRT_LEVEL_0 (0xaa)
#define FLASH_OBR_RDPRT_LEVEL_1 (0x00)
#define FLASH_OBR_RDPRT_LEVEL_2 (0xcc)



void flash_unlock_pecr(void);
void flash_lock_pecr(void);
void flash_unlock_progmem(void);
void flash_lock_progmem(void);
void flash_lock_option_bytes(void);
void flash_unlock_acr(void);

void eeprom_program_word(uint32_t address, uint32_t data);
void eeprom_program_words(uint32_t address, uint32_t *data, int length_in_words);


# 36 "libopencm3/include/libopencm3/stm32/l0/flash.h" 2



#define FLASH_OPTR FLASH_OBR
#define FLASH_WRPROT1 FLASH_WRPR1
#define FLASH_WRPROT2 FLASH_WRPR2


#define FLASH_ACR_PRE_READ (1 << 6)
#define FLASH_ACR_DISAB_BUF (1 << 5)


#define FLASH_PECR_NZDISABLE (1 << 23)


#define FLASH_SR_RDERR (1 << 13)
#define FLASH_SR_NOTZEROERR (1 << 16)
#define FLASH_SR_FWWERR (1 << 17)


#define FLASH_OPTR_NBOOT1 (1 << 31)




# 37 "libopencm3/include/libopencm3/stm32/flash.h" 2
# 23 "hub/src/cusb.c" 2
# 1 "libopencm3/include/libopencm3/stm32/crs.h" 1
# 26 "libopencm3/include/libopencm3/stm32/crs.h"
# 1 "libopencm3/include/libopencm3/stm32/common/crs_common_all.h" 1
# 33 "libopencm3/include/libopencm3/stm32/common/crs_common_all.h"
#define LIBOPENCM3_CRS_H 






#define CRS CRS_BASE





#define CRS_CR MMIO32(CRS_BASE + 0x00)
#define CRS_CFGR MMIO32(CRS_BASE + 0x04)
#define CRS_ISR MMIO32(CRS_BASE + 0x08)
#define CRS_ICR MMIO32(CRS_BASE + 0x0c)







#define CRS_CR_TRIM_SHIFT 8
#define CRS_CR_TRIM (0x3F << CRS_CR_TRIM_SHIFT)

#define CRS_CR_SWSYNC (1 << 7)
#define CRS_CR_AUTOTRIMEN (1 << 6)
#define CRS_CR_CEN (1 << 5)
#define CRS_CR_ESYNCIE (1 << 3)
#define CRS_CR_ERRIE (1 << 2)
#define CRS_CR_SYNCWARNIE (1 << 1)
#define CRS_CR_SYNCOKIE (1 << 0)



#define CRS_CFGR_SYNCPOL (1 << 31)

#define CRS_CFGR_SYNCSRC_SHIFT 28
#define CRS_CFGR_SYNCSRC (3 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_GPIO (0 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_LSE (1 << CRS_CFGR_SYNCSRC_SHIFT)
#define CRS_CFGR_SYNCSRC_USB_SOF (2 << CRS_CFGR_SYNCSRC_SHIFT)

#define CRS_CFGR_SYNCDIV_SHIFT 24
#define CRS_CFGR_SYNCDIV (7 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_NODIV (0 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV2 (1 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV4 (2 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV8 (3 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV16 (4 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV32 (5 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV64 (6 << CRS_CFGR_SYNCDIV_SHIFT)
#define CRS_CFGR_SYNCDIV_DIV128 (7 << CRS_CFGR_SYNCDIV_SHIFT)

#define CRS_CFGR_FELIM_SHIFT 16
#define CRS_CFGR_FELIM (0xFF << CRS_CFGR_FELIM_SHIFT)
#define CRS_CFGR_FELIM_VAL(x) ((x) << CRS_CFGR_FELIM_SHIFT)

#define CRS_CFGR_RELOAD_SHIFT 0
#define CRS_CFGR_RELOAD (0xFFFF << CRS_CFGR_RELOAD_SHIFT)
#define CRS_CFGR_RELOAD_VAL(x) ((x) << CRS_CFGR_RELOAD_SHIFT)



#define CRS_ISR_FECAP_SHIFT 16
#define CRS_ISR_FECAP (0xFFFF << CRS_ISR_FECAP_SHIFT)

#define CRS_ISR_FEDIR (1 << 15)
#define CRS_ISR_TRIMOVF (1 << 10)
#define CRS_ISR_SYNCMISS (1 << 9)
#define CRS_ISR_SYNCERR (1 << 8)
#define CRS_ISR_ESYNCF (1 << 3)
#define CRS_ISR_ERRF (1 << 2)
#define CRS_ISR_SYNCWARNF (1 << 1)
#define CRS_ISR_SYNCOOKF (1 << 0)



#define CRS_ICR_ESYNCC (1 << 3)
#define CRS_ICR_ERRC (1 << 2)
#define CRS_ICR_SYNCWARNC (1 << 1)
#define CRS_ICR_SYNCOKC (1 << 0)
# 126 "libopencm3/include/libopencm3/stm32/common/crs_common_all.h"


void crs_autotrim_usb_enable(void);


# 27 "libopencm3/include/libopencm3/stm32/crs.h" 2
# 24 "hub/src/cusb.c" 2
# 1 "libopencm3/include/libopencm3/cm3/nvic.h" 1
# 38 "libopencm3/include/libopencm3/cm3/nvic.h"
#define LIBOPENCM3_NVIC_H 
# 51 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ISER(iser_id) MMIO32(NVIC_BASE + 0x00 + ((iser_id) * 4))
# 60 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ICER(icer_id) MMIO32(NVIC_BASE + 0x80 + ((icer_id) * 4))
# 69 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ISPR(ispr_id) MMIO32(NVIC_BASE + 0x100 + ((ispr_id) * 4))
# 78 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ICPR(icpr_id) MMIO32(NVIC_BASE + 0x180 + ((icpr_id) * 4))
# 98 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_IPR32(ipr_id) MMIO32(NVIC_BASE + 0x300 + ((ipr_id) * 4))
# 120 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_NMI_IRQ -14
#define NVIC_HARD_FAULT_IRQ -13
# 131 "libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_SV_CALL_IRQ -5







#define NVIC_PENDSV_IRQ -2
#define NVIC_SYSTICK_IRQ -1






# 1 "libopencm3/include/libopencm3/dispatch/nvic.h" 1
# 18 "libopencm3/include/libopencm3/dispatch/nvic.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/nvic.h" 1






#define LIBOPENCM3_STM32_L0_NVIC_H 

# 1 "libopencm3/include/libopencm3/cm3/nvic.h" 1
# 10 "libopencm3/include/libopencm3/stm32/l0/nvic.h" 2






#define NVIC_WWDG_IRQ 0
#define NVIC_PVD_IRQ 1
#define NVIC_RTC_IRQ 2
#define NVIC_FLASH_IRQ 3
#define NVIC_RCC_IRQ 4
#define NVIC_EXTI0_1_IRQ 5
#define NVIC_EXTI2_3_IRQ 6
#define NVIC_EXTI4_15_IRQ 7
#define NVIC_TSC_IRQ 8
#define NVIC_DMA1_CHANNEL1_IRQ 9
#define NVIC_DMA1_CHANNEL2_3_IRQ 10
#define NVIC_DMA1_CHANNEL4_5_IRQ 11
#define NVIC_ADC_COMP_IRQ 12
#define NVIC_LPTIM1_IRQ 13
#define NVIC_USART4_5_IRQ 14
#define NVIC_TIM2_IRQ 15
#define NVIC_TIM3_IRQ 16
#define NVIC_TIM6_DAC_IRQ 17
#define NVIC_TIM7_IRQ 18
#define NVIC_RESERVED4_IRQ 19
#define NVIC_TIM21_IRQ 20
#define NVIC_I2C3_IRQ 21
#define NVIC_TIM22_IRQ 22
#define NVIC_I2C1_IRQ 23
#define NVIC_I2C2_IRQ 24
#define NVIC_SPI1_IRQ 25
#define NVIC_SPI2_IRQ 26
#define NVIC_USART1_IRQ 27
#define NVIC_USART2_IRQ 28
#define NVIC_LPUART1_AES_RNG_IRQ 29
#define NVIC_LCD_IRQ 30
#define NVIC_USB_IRQ 31

#define NVIC_IRQ_COUNT 32
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

# 25 "hub/src/cusb.c" 2

# 1 "libopencm3/include/libopencm3/usb/usbd.h" 1
# 39 "libopencm3/include/libopencm3/usb/usbd.h"
#define __USBD_H 

# 1 "libopencm3/include/libopencm3/usb/usbstd.h" 1
# 44 "libopencm3/include/libopencm3/usb/usbstd.h"
#define __USBSTD_H 
# 56 "libopencm3/include/libopencm3/usb/usbstd.h"
struct usb_setup_data {
 uint8_t bmRequestType;
 uint8_t bRequest;
 uint16_t wValue;
 uint16_t wIndex;
 uint16_t wLength;
} __attribute__((packed));


#define USB_CLASS_VENDOR 0xFF



#define USB_REQ_TYPE_DIRECTION 0x80
#define USB_REQ_TYPE_IN 0x80
#define USB_REQ_TYPE_OUT 0x0

#define USB_REQ_TYPE_TYPE 0x60
#define USB_REQ_TYPE_STANDARD 0x00
#define USB_REQ_TYPE_CLASS 0x20
#define USB_REQ_TYPE_VENDOR 0x40

#define USB_REQ_TYPE_RECIPIENT 0x1F
#define USB_REQ_TYPE_DEVICE 0x00
#define USB_REQ_TYPE_INTERFACE 0x01
#define USB_REQ_TYPE_ENDPOINT 0x02
#define USB_REQ_TYPE_OTHER 0x03


#define USB_REQ_GET_STATUS 0
#define USB_REQ_CLEAR_FEATURE 1

#define USB_REQ_SET_FEATURE 3

#define USB_REQ_SET_ADDRESS 5
#define USB_REQ_GET_DESCRIPTOR 6
#define USB_REQ_SET_DESCRIPTOR 7
#define USB_REQ_GET_CONFIGURATION 8
#define USB_REQ_SET_CONFIGURATION 9
#define USB_REQ_GET_INTERFACE 10
#define USB_REQ_SET_INTERFACE 11
#define USB_REQ_SET_SYNCH_FRAME 12


#define USB_DT_DEVICE 1
#define USB_DT_CONFIGURATION 2
#define USB_DT_STRING 3
#define USB_DT_INTERFACE 4
#define USB_DT_ENDPOINT 5
#define USB_DT_DEVICE_QUALIFIER 6
#define USB_DT_OTHER_SPEED_CONFIGURATION 7
#define USB_DT_INTERFACE_POWER 8

#define USB_DT_OTG 9
#define USB_DT_DEBUG 10
#define USB_DT_INTERFACE_ASSOCIATION 11


#define USB_FEAT_ENDPOINT_HALT 0
#define USB_FEAT_DEVICE_REMOTE_WAKEUP 1
#define USB_FEAT_TEST_MODE 2


#define USB_DEV_STATUS_SELF_POWERED 0x01
#define USB_DEV_STATUS_REMOTE_WAKEUP 0x02


struct usb_device_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint16_t idVendor;
 uint16_t idProduct;
 uint16_t bcdDevice;
 uint8_t iManufacturer;
 uint8_t iProduct;
 uint8_t iSerialNumber;
 uint8_t bNumConfigurations;
} __attribute__((packed));

#define USB_DT_DEVICE_SIZE sizeof(struct usb_device_descriptor)




struct usb_device_qualifier_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdUSB;
 uint8_t bDeviceClass;
 uint8_t bDeviceSubClass;
 uint8_t bDeviceProtocol;
 uint8_t bMaxPacketSize0;
 uint8_t bNumConfigurations;
 uint8_t bReserved;
} __attribute__((packed));




struct usb_interface {
 uint8_t *cur_altsetting;
 uint8_t num_altsetting;
 const struct usb_iface_assoc_descriptor *iface_assoc;
 const struct usb_interface_descriptor *altsetting;
};


struct usb_config_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wTotalLength;
 uint8_t bNumInterfaces;
 uint8_t bConfigurationValue;
 uint8_t iConfiguration;
 uint8_t bmAttributes;
 uint8_t bMaxPower;


 const struct usb_interface *interface;
} __attribute__((packed));
#define USB_DT_CONFIGURATION_SIZE 9


#define USB_CONFIG_ATTR_DEFAULT 0x80
#define USB_CONFIG_ATTR_SELF_POWERED 0x40
#define USB_CONFIG_ATTR_REMOTE_WAKEUP 0x20






struct usb_interface_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bInterfaceNumber;
 uint8_t bAlternateSetting;
 uint8_t bNumEndpoints;
 uint8_t bInterfaceClass;
 uint8_t bInterfaceSubClass;
 uint8_t bInterfaceProtocol;
 uint8_t iInterface;


 const struct usb_endpoint_descriptor *endpoint;
 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_INTERFACE_SIZE 9


struct usb_endpoint_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bEndpointAddress;
 uint8_t bmAttributes;
 uint16_t wMaxPacketSize;
 uint8_t bInterval;


 const void *extra;
 int extralen;
} __attribute__((packed));
#define USB_DT_ENDPOINT_SIZE 7


#define USB_ENDPOINT_ADDR_OUT(x) (x)
#define USB_ENDPOINT_ADDR_IN(x) (0x80 | (x))



#define USB_ENDPOINT_ATTR_CONTROL 0x00
#define USB_ENDPOINT_ATTR_ISOCHRONOUS 0x01
#define USB_ENDPOINT_ATTR_BULK 0x02
#define USB_ENDPOINT_ATTR_INTERRUPT 0x03
#define USB_ENDPOINT_ATTR_TYPE 0x03

#define USB_ENDPOINT_ATTR_NOSYNC 0x00
#define USB_ENDPOINT_ATTR_ASYNC 0x04
#define USB_ENDPOINT_ATTR_ADAPTIVE 0x08
#define USB_ENDPOINT_ATTR_SYNC 0x0C
#define USB_ENDPOINT_ATTR_SYNCTYPE 0x0C

#define USB_ENDPOINT_ATTR_DATA 0x00
#define USB_ENDPOINT_ATTR_FEEDBACK 0x10
#define USB_ENDPOINT_ATTR_IMPLICIT_FEEDBACK_DATA 0x20
#define USB_ENDPOINT_ATTR_USAGETYPE 0x30




struct usb_string_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t wData[];
} __attribute__((packed));


struct usb_iface_assoc_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint8_t bFirstInterface;
 uint8_t bInterfaceCount;
 uint8_t bFunctionClass;
 uint8_t bFunctionSubClass;
 uint8_t bFunctionProtocol;
 uint8_t iFunction;
} __attribute__((packed));
#define USB_DT_INTERFACE_ASSOCIATION_SIZE sizeof(struct usb_iface_assoc_descriptor)


enum usb_language_id {
 USB_LANGID_ENGLISH_US = 0x409,
};
# 42 "libopencm3/include/libopencm3/usb/usbd.h" 2




enum usbd_request_return_codes {
 USBD_REQ_NOTSUPP = 0,
 USBD_REQ_HANDLED = 1,
 USBD_REQ_NEXT_CALLBACK = 2,
};

typedef struct _usbd_driver usbd_driver;
typedef struct _usbd_device usbd_device;

extern const usbd_driver st_usbfs_v1_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
extern const usbd_driver stm32f207_usb_driver;
extern const usbd_driver st_usbfs_v2_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver
#define otghs_usb_driver stm32f207_usb_driver
extern const usbd_driver efm32lg_usb_driver;
extern const usbd_driver efm32hg_usb_driver;
extern const usbd_driver lm4f_usb_driver;
# 97 "libopencm3/include/libopencm3/usb/usbd.h"
extern usbd_device * usbd_init(const usbd_driver *driver,
          const struct usb_device_descriptor *dev,
          const struct usb_config_descriptor *conf,
          const char * const *strings, int num_strings,
          uint8_t *control_buffer,
          uint16_t control_buffer_size);


extern void usbd_register_reset_callback(usbd_device *usbd_dev,
      void (*callback)(void));

extern void usbd_register_suspend_callback(usbd_device *usbd_dev,
        void (*callback)(void));

extern void usbd_register_resume_callback(usbd_device *usbd_dev,
       void (*callback)(void));

extern void usbd_register_sof_callback(usbd_device *usbd_dev,
           void (*callback)(void));

typedef void (*usbd_control_complete_callback)(usbd_device *usbd_dev,
  struct usb_setup_data *req);

typedef enum usbd_request_return_codes (*usbd_control_callback)(
  usbd_device *usbd_dev,
  struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
  usbd_control_complete_callback *complete);

typedef void (*usbd_set_config_callback)(usbd_device *usbd_dev,
      uint16_t wValue);

typedef void (*usbd_set_altsetting_callback)(usbd_device *usbd_dev,
          uint16_t wIndex, uint16_t wValue);

typedef void (*usbd_endpoint_callback)(usbd_device *usbd_dev, uint8_t ep);
# 148 "libopencm3/include/libopencm3/usb/usbd.h"
extern int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
       uint8_t type_mask,
       usbd_control_callback callback);
# 159 "libopencm3/include/libopencm3/usb/usbd.h"
extern int usbd_register_set_config_callback(usbd_device *usbd_dev,
       usbd_set_config_callback callback);




extern void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
     usbd_set_altsetting_callback callback);


extern void usbd_poll(usbd_device *usbd_dev);
# 179 "libopencm3/include/libopencm3/usb/usbd.h"
extern void usbd_disconnect(usbd_device *usbd_dev, 
# 179 "libopencm3/include/libopencm3/usb/usbd.h" 3 4
                                                  _Bool 
# 179 "libopencm3/include/libopencm3/usb/usbd.h"
                                                       disconnected);
# 191 "libopencm3/include/libopencm3/usb/usbd.h"
extern void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
  uint16_t max_size, usbd_endpoint_callback callback);
# 201 "libopencm3/include/libopencm3/usb/usbd.h"
extern uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
    const void *buf, uint16_t len);
# 211 "libopencm3/include/libopencm3/usb/usbd.h"
extern uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
          void *buf, uint16_t len);





extern void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
         uint8_t stall);






extern uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);






extern void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);


# 27 "hub/src/cusb.c" 2
# 1 "hub/src/../../libopencm3/lib/usb/usb_private.h" 1
# 39 "hub/src/../../libopencm3/lib/usb/usb_private.h"
#define __USB_PRIVATE_H 

#define MAX_USER_CONTROL_CALLBACK 4
#define MAX_USER_SET_CONFIG_CALLBACK 4

#define MIN(a,b) ((a) < (b) ? (a) : (b))


struct _usbd_device {
 const struct usb_device_descriptor *desc;
 const struct usb_config_descriptor *config;
 const char * const *strings;
 int num_strings;

 uint8_t *ctrl_buf;
 uint16_t ctrl_buf_len;

 uint8_t current_address;
 uint8_t current_config;

 uint16_t pm_top;


 void (*user_callback_reset)(void);
 void (*user_callback_suspend)(void);
 void (*user_callback_resume)(void);
 void (*user_callback_sof)(void);

 struct usb_control_state {
  enum {
   IDLE, STALLED,
   DATA_IN, LAST_DATA_IN, STATUS_IN,
   DATA_OUT, LAST_DATA_OUT, STATUS_OUT,
  } state;
  struct usb_setup_data req __attribute__((aligned(4)));
  uint8_t *ctrl_buf;
  uint16_t ctrl_len;
  usbd_control_complete_callback complete;
  
# 77 "hub/src/../../libopencm3/lib/usb/usb_private.h" 3 4
 _Bool 
# 77 "hub/src/../../libopencm3/lib/usb/usb_private.h"
      needs_zlp;
 } control_state;

 struct user_control_callback {
  usbd_control_callback cb;
  uint8_t type;
  uint8_t type_mask;
 } user_control_callback[4];

 usbd_endpoint_callback user_callback_ctr[8][3];


 usbd_set_config_callback user_callback_set_config[4];

 usbd_set_altsetting_callback user_callback_set_altsetting;

 const struct _usbd_driver *driver;



 uint16_t fifo_mem_top;
 uint16_t fifo_mem_top_ep0;
 uint8_t force_nak[4];




 uint32_t doeptsiz[4];





 uint16_t rxbcnt;
};

enum _usbd_transaction {
 USB_TRANSACTION_IN,
 USB_TRANSACTION_OUT,
 USB_TRANSACTION_SETUP,
};




void _usbd_control_in(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_out(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_setup(usbd_device *usbd_dev, uint8_t ea);

enum usbd_request_return_codes _usbd_standard_request_device(usbd_device *usbd_dev,
      struct usb_setup_data *req, uint8_t **buf,
      uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_interface(usbd_device *usbd_dev,
         struct usb_setup_data *req, uint8_t **buf,
         uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_endpoint(usbd_device *usbd_dev,
        struct usb_setup_data *req, uint8_t **buf,
        uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
      uint8_t **buf, uint16_t *len);

void _usbd_reset(usbd_device *usbd_dev);


struct _usbd_driver {
 usbd_device *(*init)(void);
 void (*set_address)(usbd_device *usbd_dev, uint8_t addr);
 void (*ep_setup)(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
    uint16_t max_size, usbd_endpoint_callback cb);
 void (*ep_reset)(usbd_device *usbd_dev);
 void (*ep_stall_set)(usbd_device *usbd_dev, uint8_t addr,
        uint8_t stall);
 void (*ep_nak_set)(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
 uint8_t (*ep_stall_get)(usbd_device *usbd_dev, uint8_t addr);
 uint16_t (*ep_write_packet)(usbd_device *usbd_dev, uint8_t addr,
        const void *buf, uint16_t len);
 uint16_t (*ep_read_packet)(usbd_device *usbd_dev, uint8_t addr,
       void *buf, uint16_t len);
 void (*poll)(usbd_device *usbd_dev);
 void (*disconnect)(usbd_device *usbd_dev, 
# 156 "hub/src/../../libopencm3/lib/usb/usb_private.h" 3 4
                                          _Bool 
# 156 "hub/src/../../libopencm3/lib/usb/usb_private.h"
                                               disconnected);
 uint32_t base_address;
 
# 158 "hub/src/../../libopencm3/lib/usb/usb_private.h" 3 4
_Bool 
# 158 "hub/src/../../libopencm3/lib/usb/usb_private.h"
     set_address_before_status;
 uint16_t rx_fifo_size;
};
# 28 "hub/src/cusb.c" 2
# 1 "libopencm3/include/libopencm3/stm32/st_usbfs.h" 1
# 21 "libopencm3/include/libopencm3/stm32/st_usbfs.h"
#define LIBOPENCM3_ST_USBFS_H 
# 33 "libopencm3/include/libopencm3/stm32/st_usbfs.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/st_usbfs.h" 1
# 25 "libopencm3/include/libopencm3/stm32/l0/st_usbfs.h"
# 1 "libopencm3/include/libopencm3/stm32/common/st_usbfs_v2.h" 1
# 32 "libopencm3/include/libopencm3/stm32/common/st_usbfs_v2.h"
#define LIBOPENCM3_ST_USBFS_V2_H 

# 1 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h" 1
# 45 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h"
#define LIBOPENCM3_ST_USBFS_COMMON_H 

# 1 "libopencm3/include/libopencm3/stm32/tools.h" 1
# 21 "libopencm3/include/libopencm3/stm32/tools.h"
#define LIBOPENCM3_TOOLS_H 






#define GET_REG(REG) ((uint16_t) *(REG))


#define SET_REG(REG,VAL) (*(REG) = (uint16_t)(VAL))


#define CLR_REG_BIT(REG,BIT) SET_REG((REG), (~(BIT)))


#define CLR_REG_BIT_MSK_AND_SET(REG,MSK,BIT,EXTRA_BITS) SET_REG((REG), (GET_REG((REG)) & (MSK) & (~(BIT))) | (EXTRA_BITS))


#define CLR_REG_BIT_MSK(REG,MSK,BIT) CLR_REG_BIT_MSK_AND_SET((REG), (MSK), (BIT), 0)



#define GET_REG_BIT(REG,BIT) (GET_REG(REG) & (BIT))
# 56 "libopencm3/include/libopencm3/stm32/tools.h"
#define TOG_SET_REG_BIT_MSK_AND_SET(REG,MSK,BIT,EXTRA_BITS) do { register uint16_t toggle_mask = GET_REG(REG) & (MSK); toggle_mask ^= BIT; SET_REG((REG), toggle_mask | (EXTRA_BITS)); } while (0)






#define TOG_SET_REG_BIT_MSK(REG,MSK,BIT) TOG_SET_REG_BIT_MSK_AND_SET((REG), (MSK), (BIT), 0)
# 48 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h" 2
# 60 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h"
#define USB_CNTR_REG (&MMIO32(USB_DEV_FS_BASE + 0x40))

#define USB_ISTR_REG (&MMIO32(USB_DEV_FS_BASE + 0x44))

#define USB_FNR_REG (&MMIO32(USB_DEV_FS_BASE + 0x48))

#define USB_DADDR_REG (&MMIO32(USB_DEV_FS_BASE + 0x4C))

#define USB_BTABLE_REG (&MMIO32(USB_DEV_FS_BASE + 0x50))


#define USB_EP_REG(EP) (&MMIO32(USB_DEV_FS_BASE) + (EP))
# 81 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h"
#define USB_CNTR_CTRM 0x8000
#define USB_CNTR_PMAOVRM 0x4000
#define USB_CNTR_ERRM 0x2000
#define USB_CNTR_WKUPM 0x1000
#define USB_CNTR_SUSPM 0x0800
#define USB_CNTR_RESETM 0x0400
#define USB_CNTR_SOFM 0x0200
#define USB_CNTR_ESOFM 0x0100


#define USB_CNTR_RESUME 0x0010
#define USB_CNTR_FSUSP 0x0008
#define USB_CNTR_LP_MODE 0x0004
#define USB_CNTR_PWDN 0x0002
#define USB_CNTR_FRES 0x0001



#define USB_ISTR_CTR 0x8000
#define USB_ISTR_PMAOVR 0x4000
#define USB_ISTR_ERR 0x2000
#define USB_ISTR_WKUP 0x1000
#define USB_ISTR_SUSP 0x0800
#define USB_ISTR_RESET 0x0400
#define USB_ISTR_SOF 0x0200
#define USB_ISTR_ESOF 0x0100
#define USB_ISTR_DIR 0x0010
#define USB_ISTR_EP_ID 0x000F




#define USB_CLR_ISTR_PMAOVR() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_PMAOVR)
#define USB_CLR_ISTR_ERR() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_ERR)
#define USB_CLR_ISTR_WKUP() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_WKUP)
#define USB_CLR_ISTR_SUSP() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_SUSP)
#define USB_CLR_ISTR_RESET() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_RESET)
#define USB_CLR_ISTR_SOF() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_SOF)
#define USB_CLR_ISTR_ESOF() CLR_REG_BIT(USB_ISTR_REG, USB_ISTR_ESOF)



#define USB_FNR_RXDP (1 << 15)
#define USB_FNR_RXDM (1 << 14)
#define USB_FNR_LCK (1 << 13)

#define USB_FNR_LSOF_SHIFT 11
#define USB_FNR_LSOF (3 << USB_FNR_LSOF_SHIFT)

#define USB_FNR_FN (0x7FF << 0)



#define USB_DADDR_EF (1 << 7)
#define USB_DADDR_ADDR 0x007F



#define USB_BTABLE_BTABLE 0xFFF8





#define USB_EP0 0
#define USB_EP1 1
#define USB_EP2 2
#define USB_EP3 3
#define USB_EP4 4
#define USB_EP5 5
#define USB_EP6 6
#define USB_EP7 7




#define USB_EP_RX_CTR 0x8000
#define USB_EP_RX_DTOG 0x4000
#define USB_EP_RX_STAT 0x3000

#define USB_EP_SETUP 0x0800
#define USB_EP_TYPE 0x0600
#define USB_EP_KIND 0x0100




#define USB_EP_TX_CTR 0x0080
#define USB_EP_TX_DTOG 0x0040
#define USB_EP_TX_STAT 0x0030

#define USB_EP_ADDR 0x000F


#define USB_EP_NTOGGLE_MSK (USB_EP_RX_CTR | USB_EP_SETUP | USB_EP_TYPE | USB_EP_KIND | USB_EP_TX_CTR | USB_EP_ADDR)







#define USB_EP_RX_STAT_TOG_MSK (USB_EP_RX_STAT | USB_EP_NTOGGLE_MSK)

#define USB_EP_TX_STAT_TOG_MSK (USB_EP_TX_STAT | USB_EP_NTOGGLE_MSK)


#define USB_EP_RX_STAT_DISABLED 0x0000
#define USB_EP_RX_STAT_STALL 0x1000
#define USB_EP_RX_STAT_NAK 0x2000
#define USB_EP_RX_STAT_VALID 0x3000


#define USB_EP_TX_STAT_DISABLED 0x0000
#define USB_EP_TX_STAT_STALL 0x0010
#define USB_EP_TX_STAT_NAK 0x0020
#define USB_EP_TX_STAT_VALID 0x0030


#define USB_EP_TYPE_BULK 0x0000
#define USB_EP_TYPE_CONTROL 0x0200
#define USB_EP_TYPE_ISO 0x0400
#define USB_EP_TYPE_INTERRUPT 0x0600
# 213 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h"
#define USB_SET_EP_RX_STAT(EP,STAT) TOG_SET_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), USB_EP_RX_STAT_TOG_MSK, STAT, USB_EP_RX_CTR | USB_EP_TX_CTR)



#define USB_SET_EP_TX_STAT(EP,STAT) TOG_SET_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), USB_EP_TX_STAT_TOG_MSK, STAT, USB_EP_RX_CTR | USB_EP_TX_CTR)
# 228 "libopencm3/include/libopencm3/stm32/common/st_usbfs_common.h"
#define USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP,BIT,EXTRA_BITS) CLR_REG_BIT_MSK_AND_SET(USB_EP_REG(EP), USB_EP_NTOGGLE_MSK, BIT, EXTRA_BITS)



#define USB_CLR_EP_RX_CTR(EP) USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP, USB_EP_RX_CTR, USB_EP_TX_CTR)


#define USB_CLR_EP_TX_CTR(EP) USB_CLR_EP_NTOGGLE_BIT_AND_SET(EP, USB_EP_TX_CTR, USB_EP_RX_CTR)



#define USB_SET_EP_TYPE(EP,TYPE) SET_REG(USB_EP_REG(EP), (GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK & (~USB_EP_TYPE))) | TYPE)





#define USB_SET_EP_KIND(EP) SET_REG(USB_EP_REG(EP), (GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK & (~USB_EP_KIND))) | USB_EP_KIND)





#define USB_CLR_EP_KIND(EP) SET_REG(USB_EP_REG(EP), (GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK & (~USB_EP_KIND))))




#define USB_SET_EP_STAT_OUT(EP) USB_SET_EP_KIND(EP)
#define USB_CLR_EP_STAT_OUT(EP) USB_CLR_EP_KIND(EP)

#define USB_SET_EP_ADDR(EP,ADDR) SET_REG(USB_EP_REG(EP), ((GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK & (~USB_EP_ADDR))) | ADDR))






#define USB_CLR_EP_TX_DTOG(EP) SET_REG(USB_EP_REG(EP), GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK | USB_EP_TX_DTOG))




#define USB_CLR_EP_RX_DTOG(EP) SET_REG(USB_EP_REG(EP), GET_REG(USB_EP_REG(EP)) & (USB_EP_NTOGGLE_MSK | USB_EP_RX_DTOG))







#define USB_GET_BTABLE GET_REG(USB_BTABLE_REG)



#define USB_GET_EP_TX_ADDR(EP) GET_REG(USB_EP_TX_ADDR(EP))
#define USB_GET_EP_TX_COUNT(EP) GET_REG(USB_EP_TX_COUNT(EP))
#define USB_GET_EP_RX_ADDR(EP) GET_REG(USB_EP_RX_ADDR(EP))
#define USB_GET_EP_RX_COUNT(EP) GET_REG(USB_EP_RX_COUNT(EP))
#define USB_SET_EP_TX_ADDR(EP,ADDR) SET_REG(USB_EP_TX_ADDR(EP), ADDR)
#define USB_SET_EP_TX_COUNT(EP,COUNT) SET_REG(USB_EP_TX_COUNT(EP), COUNT)
#define USB_SET_EP_RX_ADDR(EP,ADDR) SET_REG(USB_EP_RX_ADDR(EP), ADDR)
#define USB_SET_EP_RX_COUNT(EP,COUNT) SET_REG(USB_EP_RX_COUNT(EP), COUNT)
# 35 "libopencm3/include/libopencm3/stm32/common/st_usbfs_v2.h" 2
# 44 "libopencm3/include/libopencm3/stm32/common/st_usbfs_v2.h"
#define USB_LPMCSR_REG (&MMIO32(USB_DEV_FS_BASE + 0x54))
#define USB_BCDR_REG (&MMIO32(USB_DEV_FS_BASE + 0x58))







#define USB_CNTR_L1REQM (1 << 7)
#define USB_CNTR_L1RESUME (1 << 5)



#define USB_ISTR_L1REQ (1 << 7)



#define USB_LPMCSR_BESL_SHIFT 4
#define USB_LPMCSR_BESL (15 << USB_LPMCSR_BESL_SHIFT)

#define USB_LPMCSR_REMWAKE (1 << 3)
#define USB_LPMCSR_LPMACK (1 << 1)
#define USB_LPMCSR_LPMEN (1 << 0)



#define USB_BCDR_DPPU (1 << 15)
#define USB_BCDR_PS2DET (1 << 7)
#define USB_BCDR_SDET (1 << 6)
#define USB_BCDR_PDET (1 << 5)
#define USB_BCDR_DCDET (1 << 4)
#define USB_BCDR_SDEN (1 << 3)
#define USB_BCDR_PDEN (1 << 2)
#define USB_BCDR_DCDEN (1 << 1)
#define USB_BCDR_BCDEN (1 << 0)



#define USB_EP_TX_ADDR(ep) ((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 0) * 1))


#define USB_EP_TX_COUNT(ep) ((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 2) * 1))


#define USB_EP_RX_ADDR(ep) ((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 4) * 1))


#define USB_EP_RX_COUNT(ep) ((uint16_t *)(USB_PMA_BASE + (USB_GET_BTABLE + (ep) * 8 + 6) * 1))




#define USB_GET_EP_TX_BUFF(ep) (USB_PMA_BASE + (uint8_t *)(USB_GET_EP_TX_ADDR(ep) * 1))


#define USB_GET_EP_RX_BUFF(ep) (USB_PMA_BASE + (uint8_t *)(USB_GET_EP_RX_ADDR(ep) * 1))
# 26 "libopencm3/include/libopencm3/stm32/l0/st_usbfs.h" 2
# 34 "libopencm3/include/libopencm3/stm32/st_usbfs.h" 2
# 29 "hub/src/cusb.c" 2
# 1 "hub/src/../../libopencm3/lib/stm32/common/st_usbfs_core.h" 1
# 28 "hub/src/../../libopencm3/lib/stm32/common/st_usbfs_core.h"
#define ST_USBFS_CORE 




#define USBD_PM_TOP 0x40

void st_usbfs_set_address(usbd_device *dev, uint8_t addr);
uint16_t st_usbfs_set_ep_rx_bufsize(usbd_device *dev, uint8_t ep, uint32_t size);

void st_usbfs_ep_setup(usbd_device *usbd_dev, uint8_t addr,
  uint8_t type, uint16_t max_size,
  void (*callback) (usbd_device *usbd_dev,
  uint8_t ep));

void st_usbfs_endpoints_reset(usbd_device *usbd_dev);
void st_usbfs_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall);
uint8_t st_usbfs_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);
void st_usbfs_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
uint16_t st_usbfs_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
      const void *buf, uint16_t len);
uint16_t st_usbfs_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
     void *buf, uint16_t len);
void st_usbfs_poll(usbd_device *usbd_dev);
# 62 "hub/src/../../libopencm3/lib/stm32/common/st_usbfs_core.h"
void st_usbfs_copy_from_pm(void *buf, const volatile void *vPM, uint16_t len);
# 71 "hub/src/../../libopencm3/lib/stm32/common/st_usbfs_core.h"
void st_usbfs_copy_to_pm(volatile void *vPM, const void *buf, uint16_t len);

extern uint8_t st_usbfs_force_nak[8];
extern struct _usbd_device st_usbfs_dev;
# 30 "hub/src/cusb.c" 2

# 1 "libopencm3/include/libopencm3/usb/hid.h" 1
# 39 "libopencm3/include/libopencm3/usb/hid.h"
#define __HID_H 



#define USB_CLASS_HID 3


#define USB_HID_SUBCLASS_NO 0
#define USB_HID_SUBCLASS_BOOT_INTERFACE 1


#define USB_HID_INTERFACE_PROTOCOL_NONE 0
#define USB_HID_INTERFACE_PROTOCOL_KEYBOARD 1
#define USB_HID_INTERFACE_PROTOCOL_MOUSE 2


#define USB_HID_DT_HID 0x21
#define USB_HID_DT_REPORT 0x22
#define USB_HID_DT_PHYSICAL 0x23

#define USB_DT_HID USB_HID_DT_HID

#define USB_DT_REPORT USB_HID_DT_REPORT


#define USB_HID_REQ_TYPE_GET_REPORT 0x01
#define USB_HID_REQ_TYPE_GET_IDLE 0x02
#define USB_HID_REQ_TYPE_GET_PROTOCOL 0x03
#define USB_HID_REQ_TYPE_SET_REPORT 0x09
#define USB_HID_REQ_TYPE_SET_IDLE 0x0A
#define USB_HID_REQ_TYPE_SET_PROTOCOL 0x0B


#define USB_HID_REPORT_TYPE_INPUT 1
#define USB_HID_REPORT_TYPE_OUTPUT 2
#define USB_HID_REPORT_TYPE_FEATURE 3


#define USB_HID_PROTOCOL_BOOT 0
#define USB_HID_PROTOCOL_REPORT 1

struct usb_hid_descriptor {
 uint8_t bLength;
 uint8_t bDescriptorType;
 uint16_t bcdHID;
 uint8_t bCountryCode;
 uint8_t bNumDescriptors;
} __attribute__((packed));
# 32 "hub/src/cusb.c" 2

# 1 "common/include/common/log.h" 1
# 26 "common/include/common/log.h"
#define LOG_H 
# 47 "common/include/common/log.h"
#define ERR_BOOT_PROG_START_ADDRESS_OUT_OF_BOUNDS 0
#define ERR_BOOT_PROG_TOO_BIG 1
#define ERR_BOOT_PROG_BAD_CHECKSUM 2
#define ERR_BOOT_PROG_FLASH_ERASE 3
#define ERR_BOOT_PROG_FLASH_WRITE_1 4
#define ERR_BOOT_PROG_FLASH_WRITE_2 5
# 65 "common/include/common/log.h"
void log_init(void);
void log_printf(const char *format, ...);
void log_error(uint16_t error);
uint8_t log_get_byte(uint16_t index);
void log_read_reset(void);
uint8_t log_read(void);
uint16_t log_size(void);
void log_erase(void);

void serial_printf(const char *format, ...);
# 34 "hub/src/cusb.c" 2
# 1 "common/include/common/memory.h" 1
# 26 "common/include/common/memory.h"
#define MEMORY_H 






# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 34 "common/include/common/memory.h" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 35 "common/include/common/memory.h" 2
# 54 "common/include/common/memory.h"
#define FLASH_PAGE_SIZE 128U
#define FLASH_NUM_PAGES 512U
#define FLASH_START 0x08000000U
#define FLASH_APP_START 0x08004000U
#define FLASH_APP_END 0x0800C000U
#define FLASH_END 0x08010000U





#define EEPROM_PAGE_SIZE 4U
#define EEPROM_NUM_PAGES 512U
#define EEPROM_START 0x08080000U
#define EEPROM_SIZE 2048U
#define EEPROM_END EEPROM_START + EEPROM_SIZE



#define EEPROM_BOOTLOADER_SIZE 256U
#define EEPROM_DEV_SIZE 256U
#define EEPROM_LOG_SIZE 1024U






#define EEPROM_BOOTLOADER_BASE EEPROM_START
#define EEPROM_BOOTLOADER_END EEPROM_BOOTLOADER_BASE + EEPROM_BOOTLOADER_SIZE


#define EEPROM_DEV_BASE EEPROM_BOOTLOADER_END
#define EEPROM_DEV_END EEPROM_START + EEPROM_BOOTLOADER_SIZE


#define EEPROM_LOG_BASE EEPROM_DEV_END
#define EEPROM_LOG_END EEPROM_LOG_BASE + EEPROM_LOG_SIZE
# 102 "common/include/common/memory.h"
void mem_init(void);


# 104 "common/include/common/memory.h" 3 4
_Bool 
# 104 "common/include/common/memory.h"
    mem_eeprom_write_word(uint32_t address, uint32_t data);

# 105 "common/include/common/memory.h" 3 4
_Bool 
# 105 "common/include/common/memory.h"
    mem_eeprom_write_half_word(uint32_t address, uint16_t data);

# 106 "common/include/common/memory.h" 3 4
_Bool 
# 106 "common/include/common/memory.h"
    mem_eeprom_write_byte(uint32_t address, uint8_t data);


# 108 "common/include/common/memory.h" 3 4
_Bool 
# 108 "common/include/common/memory.h"
    mem_flash_erase_page(uint32_t address);

# 109 "common/include/common/memory.h" 3 4
_Bool 
# 109 "common/include/common/memory.h"
    mem_flash_write_word(uint32_t address, uint32_t data);

# 110 "common/include/common/memory.h" 3 4
_Bool 
# 110 "common/include/common/memory.h"
    mem_flash_write_half_page(uint32_t address, uint32_t *data);

void mem_save_reading(int16_t reading);

uint32_t mem_get_dev_state(void);
uint32_t mem_get_dev_num(void);
uint32_t mem_get_msg_num(void);
void mem_update_msg_num(uint32_t new);
uint32_t mem_get_num_readings(void);
int16_t mem_get_reading(uint32_t reading_num);

void mem_get_log(char log[1024U]);
void mem_wipe_log(void);
void mem_print_log(void);

void mem_get_aes_key(uint8_t *aes_key);
void mem_set_aes_key(uint8_t *aes_key);
void mem_get_aes_key_exp(uint8_t *aes_key_exp);
void mem_set_aes_key_exp(uint8_t *aes_key_exp);

void mem_wipe_readings(void);
# 35 "hub/src/cusb.c" 2
# 58 "hub/src/cusb.c"
enum dev_interfaces
{
    INTERFACE_HID = 0,



    INTERFACE_CDC_COMM = 1,
    INTERFACE_CDC_DATA = 2,
    INTERFACE_KEYBOARD_HID = 3,
    INTERFACE_COUNT = 1,
};


enum dev_endpoints
{
    ENDPOINT_HID_IN = 0x81,
    ENDPOINT_HID_OUT = 0x01,
    ENDPOINT_CDC_COMM_IN = 0x83,
    ENDPOINT_CDC_DATA_IN = 0x82,
    ENDPOINT_CDC_DATA_OUT = 0x02,
    ENDPOINT_KEYBOARD_HID_IN = 0x84,
};

#define USB_VID 0x0483
#define USB_PID 0x5750





enum usb_strings_index
{
    USB_LANGID_IDX = 0,
    USB_MANUFACTURER_IDX,
    USB_PRODUCT_IDX,
    USB_SERIAL_IDX,
    USB_CONFIGURATION_IDX,
    USB_INTERFACE_IDX,
};


static const char *const usb_strings[] =
    {
        "CoolEase",
        "CoolEase Hub",
        "12345",
        "Custom HID Config"
        "Custom HID Interface",
};


static const struct usb_device_descriptor dev_desc =
    {
        .bLength = sizeof(struct usb_device_descriptor),
        .bDescriptorType = 1,
        .bcdUSB = 0x0200,
        .bDeviceClass = 0x00,
        .bDeviceSubClass = 0x00,
        .bDeviceProtocol = 0x00,
        .bMaxPacketSize0 = 64,
        .idVendor = 0x0483,
        .idProduct = 0x5750,
        .bcdDevice = 0x0200,
        .iManufacturer = USB_MANUFACTURER_IDX,
        .iProduct = USB_PRODUCT_IDX,
        .iSerialNumber = USB_SERIAL_IDX,
        .bNumConfigurations = 1};


static const struct usb_endpoint_descriptor hid_interface_endpoints[] =
    {
        {

            .bLength = 7,

            .bDescriptorType = 5,




            .bEndpointAddress = ENDPOINT_HID_IN,
# 147 "hub/src/cusb.c"
            .bmAttributes = 0x03,

            .wMaxPacketSize = 64,


            .bInterval = 1,
        },
        {

            .bLength = 7,

            .bDescriptorType = 5,




            .bEndpointAddress = ENDPOINT_HID_OUT,
# 172 "hub/src/cusb.c"
            .bmAttributes = 0x03,

            .wMaxPacketSize = 64,


            .bInterval = 1,
        }};
# 187 "hub/src/cusb.c"
static const uint8_t hid_report_descriptor[] =
    {
        0x06, 0x00, 0xff,
        0x09, 0x01,
        0xa1, 0x01,
        0x09, 0x01,
        0x15, 0x00,
        0x26, 0xff, 0x00,
        0x75, 0x08,
        0x95, 0x40,
        0x81, 0x02,
        0x09, 0x01,
        0x91, 0x02,
        0xc0
};


static const struct hid_function_descriptor
{
    struct usb_hid_descriptor hid_descriptor;
    struct
    {
        uint8_t bReportDescriptorType;
        uint16_t wDescriptorLength;
    } __attribute__((packed)) hid_report;
} __attribute__((packed)) hid_function =

    {
        .hid_descriptor =
            {

                .bLength = sizeof(hid_function),

                .bDescriptorType = 0x21,


                .bcdHID = 0x0111,


                .bCountryCode = 0,


                .bNumDescriptors = 1,
            },

        .hid_report =
            {

                .bReportDescriptorType = 0x22,

                .wDescriptorLength = sizeof(hid_report_descriptor),
            },
};


static const struct usb_interface_descriptor hid_interface =
    {

        .bLength = 9,

        .bDescriptorType = 4,

        .bInterfaceNumber = INTERFACE_HID,

        .bAlternateSetting = 0,

        .bNumEndpoints = 2,

        .bInterfaceClass = 3,


        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0,

        .iInterface = USB_INTERFACE_IDX,



        .endpoint = hid_interface_endpoints,




        .extra = &hid_function,

        .extralen = sizeof(hid_function),
};


static const struct usb_interface interfaces[] =
    {
        {
            .num_altsetting = 1,
            .altsetting = &hid_interface,
        }};


static const struct usb_config_descriptor cfg_desc =
    {
        .bLength = 9,
        .bDescriptorType = 2,
        .wTotalLength = 0,
        .bNumInterfaces = INTERFACE_COUNT,
        .bConfigurationValue = 1,
        .iConfiguration = USB_CONFIGURATION_IDX,
        .bmAttributes = 0b10000000,
        .bMaxPower = 200,
        .interface = interfaces,
};
# 308 "hub/src/cusb.c"
static usbd_device *usbd_dev;

typedef enum
{
    RESET = 0,
    CONNECTED,
    GET_LOG
} usb_state_t;

static usb_state_t usb_state;


static uint8_t usbd_control_buffer[128];

#define HID_REPORT_SIZE 64U




static uint8_t hid_report_buf[64U] = "Default Report Buffer";






static void cusb_clock_init(void);





static void cusb_reset_callback(void);
# 350 "hub/src/cusb.c"
static void hid_set_config(usbd_device *dev, uint16_t wValue);





static enum usbd_request_return_codes hid_control_request(usbd_device *dev, struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
                                                          void (**complete)(usbd_device *, struct usb_setup_data *));






static void hid_out_report_callback(usbd_device *dev, uint8_t ea);






static void hid_in_report_callback(usbd_device *dev, uint8_t ea);
# 383 "hub/src/cusb.c"
void cusb_init(void)
{

    cusb_clock_init();


    usb_state = RESET;
    (*((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x40)))) = (uint16_t)(0x0001));
    (*((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x40)))) = (uint16_t)(0));
    (*((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44)))) = (uint16_t)(0));


    usbd_dev = usbd_init(&st_usbfs_v2_usb_driver, &dev_desc, &cfg_desc, usb_strings, sizeof(usb_strings) / sizeof(const char *), usbd_control_buffer, sizeof(usbd_control_buffer));


    usbd_register_reset_callback(usbd_dev, cusb_reset_callback);


    usbd_register_set_config_callback(usbd_dev, hid_set_config);


    nvic_enable_irq(31);
    nvic_set_priority(31, 0);
}

void cusb_test_poll(void)
{
    while (1)
    {
        usbd_poll(usbd_dev);
    }
}

void cusb_send(char character)
{
    if(usb_state == CONNECTED)
    {
        usbd_ep_write_packet(usbd_dev, ENDPOINT_HID_IN, &character, 1);
    }
}


# 424 "hub/src/cusb.c" 3 4
_Bool 
# 424 "hub/src/cusb.c"
    cusb_connected(void)
{
    return ((usb_state == CONNECTED) ? 
# 426 "hub/src/cusb.c" 3 4
                                      1 
# 426 "hub/src/cusb.c"
                                           : 
# 426 "hub/src/cusb.c" 3 4
                                             0
# 426 "hub/src/cusb.c"
                                                  );
}
# 439 "hub/src/cusb.c"
static void cusb_clock_init(void)
{

    flash_set_ws(0x00);


    rcc_osc_on(RCC_HSI16);
    rcc_wait_for_osc_ready(RCC_HSI16);


    rcc_set_sysclk_source(RCC_HSI16);


    (*(volatile uint32_t *)((((0x40000000U) + 0x20000) + 0x01000) + 0x0c)) |= (1<<15);


    rcc_set_hpre(0x0);
    rcc_set_ppre1(0x0);
    rcc_set_ppre2(0x0);


    rcc_ahb_frequency = 16000000;
    rcc_apb1_frequency = 16000000;
    rcc_apb2_frequency = 16000000;


    rcc_periph_clock_enable(RCC_SYSCFG);
    (*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x20)) |= 0x01;
    while (!((*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x20)) & (1 << 30)))
    {
    }
    (*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x20)) |= (1 << 13);
    while (!((*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x20)) & (1 << 26)))
    {
    }


    rcc_osc_on(RCC_HSI48);
    rcc_wait_for_osc_ready(RCC_HSI48);

    rcc_periph_clock_enable(RCC_USB);
    rcc_periph_clock_enable(RCC_CRS);


    rcc_set_hsi48_source_rc48();


    rcc_osc_off(RCC_MSI);
}





static void cusb_reset_callback(void)
{
    usb_state = RESET;
    cusb_hook_reset();
}

static void hid_set_config(usbd_device *dev, uint16_t wValue)
{
    (void)wValue;
    (void)dev;

    usbd_ep_setup(dev, ENDPOINT_HID_IN, 0x03, 64, hid_in_report_callback);
    usbd_ep_setup(dev, ENDPOINT_HID_OUT, 0x03, 64, hid_out_report_callback);

    usbd_register_control_callback(
        dev,
        0x00 | 0x01,
        0x60 | 0x1F,
        hid_control_request);

    usb_state = CONNECTED;
}

static enum usbd_request_return_codes hid_control_request(usbd_device *dev, struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
                                                          void (**complete)(usbd_device *, struct usb_setup_data *))
{
    (void)complete;
    (void)dev;

    if ((req->bmRequestType != 0x81) ||
        (req->bRequest != 6) ||
        (req->wValue != 0x2200))
        return USBD_REQ_NOTSUPP;


    *buf = (uint8_t *)hid_report_descriptor;
    *len = sizeof(hid_report_descriptor);

    return USBD_REQ_HANDLED;
}

static void hid_in_report_callback(usbd_device *dev, uint8_t ea)
{


    if (usb_state == GET_LOG)
    {
        static uint16_t bytes_sent = 0;


        for (uint16_t i = 0; i < 64U; i++)
        {
            hid_report_buf[i] = log_read();
        }
        bytes_sent += 64U;

        usbd_ep_write_packet(dev, ea, hid_report_buf, 64U);

        if(bytes_sent >= log_size())
        {
            usb_state = RESET;
            bytes_sent = 0;
        }
    }
}

static void hid_out_report_callback(usbd_device *dev, uint8_t ea)
{



    uint8_t buf[] = "Out Report Callback\n";
    usbd_ep_write_packet(dev, ea, buf, 64U);

    usbd_ep_read_packet(dev, ea, hid_report_buf, 64U);
    uint8_t command = hid_report_buf[0];




    if (command == 1)
    {
        usb_state = GET_LOG;
        log_read_reset();
    }
}





void __attribute__ ((weak)) cusb_hook_reset(void) {}
void __attribute__ ((weak)) cusb_hook_hid_out_report(void) {}
void __attribute__ ((weak)) cusb_hook_hid_in_report(void) {}





void usb_isr(void)
{



    uint16_t istr = *(&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44)));

    if (istr & 0x0400)
    {
        (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44))))) = (uint16_t)((~(0x0400))));
        usbd_dev->pm_top = 0x40;
        _usbd_reset(usbd_dev);
        return;
    }

    if (istr & 0x8000)
    {
        uint8_t ep = istr & 0x000F;
        uint8_t type;

        if (istr & 0x0010)
        {

            if (*(&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00))) + (ep)) & 0x0800)
            {
                type = USB_TRANSACTION_SETUP;
                st_usbfs_ep_read_packet(usbd_dev, ep, &usbd_dev->control_state.req, 8);
            }
            else
            {
                type = USB_TRANSACTION_OUT;
            }
        }
        else
        {
            type = USB_TRANSACTION_IN;
            (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00))) + (ep)))) = (uint16_t)((((uint16_t) *(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00))) + (ep))))) & ((0x8000 | 0x0800 | 0x0600 | 0x0100 | 0x0080 | 0x000F)) & (~(0x0080))) | (0x8000)));
        }

        if (usbd_dev->user_callback_ctr[ep][type])
        {
            usbd_dev->user_callback_ctr[ep][type](usbd_dev, ep);
        }
        else
        {
            (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00))) + (ep)))) = (uint16_t)((((uint16_t) *(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00))) + (ep))))) & ((0x8000 | 0x0800 | 0x0600 | 0x0100 | 0x0080 | 0x000F)) & (~(0x8000))) | (0x0080)));
        }
    }

    if (istr & 0x0800)
    {
        (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44))))) = (uint16_t)((~(0x0800))));
        if (usbd_dev->user_callback_suspend)
        {
            usbd_dev->user_callback_suspend();
        }
    }

    if (istr & 0x1000)
    {
        (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44))))) = (uint16_t)((~(0x1000))));
        if (usbd_dev->user_callback_resume)
        {
            usbd_dev->user_callback_resume();
        }
    }

    if (istr & 0x0200)
    {
        (*(((&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x44))))) = (uint16_t)((~(0x0200))));
        if (usbd_dev->user_callback_sof)
        {
            usbd_dev->user_callback_sof();
        }
    }

    if (usbd_dev->user_callback_sof)
    {
        *(&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x40))) |= 0x0200;
    }
    else
    {
        *(&(*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x5c00) + 0x40))) &= ~0x0200;
    }
}
