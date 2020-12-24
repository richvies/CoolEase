# 1 "lib//battery.c"
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/coolease//"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 199901L
#define __STDC_HOSTED__ 1
#define __GNUC__ 9
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __VERSION__ "9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
#define __ATOMIC_RELAXED 0
#define __ATOMIC_SEQ_CST 5
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __OPTIMIZE_SIZE__ 1
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
#define STM32L0 1
#define STM32L051C8T6 1
# 1 "lib//battery.c"
# 1 "../coolease/include/coolease/battery.h" 1

#define BATTERY_H 

# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 1 3 4
# 9 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 3 4
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 

# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 1 3 4





#define _MACHINE__DEFAULT_TYPES_H 

# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 1 3 4
# 22 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 3 4
#define _SYS_FEATURES_H 





# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/_newlib_version.h" 1 3 4



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.1.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 1
#define __NEWLIB_PATCHLEVEL__ 0
# 29 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 2 3 4




#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 3 4
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 3 4
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 3 4
#define __XSI_VISIBLE 0
# 330 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/features.h" 3 4
#define __SSP_FORTIFY_LEVEL 0
# 9 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 2 3 4






#define __EXP(x) __ ##x ##__
# 26 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
#define __have_longlong64 1






#define __have_long32 1








# 41 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/machine/_default_types.h" 3 4
#undef __EXP
# 13 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 10 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _SYS__INTSUP_H 





#define __STDINT_EXP(x) __ ##x ##__
# 35 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef __int20
#undef long
#define signed +0
#define unsigned +0
#define char +0
#define short +1
#define __int20 +2
#define int +2
#define long +4
# 64 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _INTPTR_EQ_INT 






#define _INT32_EQ_LONG 







#define __INT8 "hh"
# 90 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT16 "h"
# 101 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT32 "l"
# 110 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT64 "ll"






#define __FAST8 
# 126 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST16 






#define __FAST32 
# 144 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST64 "ll"



#define __LEAST8 "hh"
# 159 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST16 "h"
# 170 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST32 "l"
# 179 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST64 "ll"

#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef long
       
       
       
       
       
# 191 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20
       
       
# 14 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 10 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_stdint.h" 3 4
#define _SYS__STDINT_H 
# 20 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/sys/_stdint.h" 3 4
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
# 15 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 2 3 4






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
# 51 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
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
# 128 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INTPTR_MIN (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX (__INTPTR_MAX__)
#define UINTPTR_MAX (__UINTPTR_MAX__)
# 152 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT8_MIN (-__INT8_MAX__ - 1)
#define INT8_MAX (__INT8_MAX__)
#define UINT8_MAX (__UINT8_MAX__)







#define INT_LEAST8_MIN (-__INT_LEAST8_MAX__ - 1)
#define INT_LEAST8_MAX (__INT_LEAST8_MAX__)
#define UINT_LEAST8_MAX (__UINT_LEAST8_MAX__)
# 174 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT16_MIN (-__INT16_MAX__ - 1)
#define INT16_MAX (__INT16_MAX__)
#define UINT16_MAX (__UINT16_MAX__)







#define INT_LEAST16_MIN (-__INT_LEAST16_MAX__ - 1)
#define INT_LEAST16_MAX (__INT_LEAST16_MAX__)
#define UINT_LEAST16_MAX (__UINT_LEAST16_MAX__)
# 196 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT32_MIN (-__INT32_MAX__ - 1)
#define INT32_MAX (__INT32_MAX__)
#define UINT32_MAX (__UINT32_MAX__)
# 212 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST32_MIN (-__INT_LEAST32_MAX__ - 1)
#define INT_LEAST32_MAX (__INT_LEAST32_MAX__)
#define UINT_LEAST32_MAX (__UINT_LEAST32_MAX__)
# 230 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT64_MIN (-__INT64_MAX__ - 1)
#define INT64_MAX (__INT64_MAX__)
#define UINT64_MAX (__UINT64_MAX__)
# 246 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST64_MIN (-__INT_LEAST64_MAX__ - 1)
#define INT_LEAST64_MAX (__INT_LEAST64_MAX__)
#define UINT_LEAST64_MAX (__UINT_LEAST64_MAX__)
# 262 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST8_MIN (-__INT_FAST8_MAX__ - 1)
#define INT_FAST8_MAX (__INT_FAST8_MAX__)
#define UINT_FAST8_MAX (__UINT_FAST8_MAX__)
# 278 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST16_MIN (-__INT_FAST16_MAX__ - 1)
#define INT_FAST16_MAX (__INT_FAST16_MAX__)
#define UINT_FAST16_MAX (__UINT_FAST16_MAX__)
# 294 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST32_MIN (-__INT_FAST32_MAX__ - 1)
#define INT_FAST32_MAX (__INT_FAST32_MAX__)
#define UINT_FAST32_MAX (__UINT_FAST32_MAX__)
# 310 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST64_MIN (-__INT_FAST64_MAX__ - 1)
#define INT_FAST64_MAX (__INT_FAST64_MAX__)
#define UINT_FAST64_MAX (__UINT_FAST64_MAX__)
# 326 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_MAX (__INTMAX_MAX__)
#define INTMAX_MIN (-INTMAX_MAX - 1)







#define UINTMAX_MAX (__UINTMAX_MAX__)







#define SIZE_MAX (__SIZE_MAX__)





#define SIG_ATOMIC_MIN (-__STDINT_EXP(INT_MAX) - 1)
#define SIG_ATOMIC_MAX (__STDINT_EXP(INT_MAX))



#define PTRDIFF_MAX (__PTRDIFF_MAX__)



#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)




#define WCHAR_MIN (__WCHAR_MIN__)
# 374 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define WCHAR_MAX (__WCHAR_MAX__)
# 384 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define WINT_MAX (__WINT_MAX__)




#define WINT_MIN (__WINT_MIN__)






#define INT8_C(x) __INT8_C(x)
#define UINT8_C(x) __UINT8_C(x)
# 408 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT16_C(x) __INT16_C(x)
#define UINT16_C(x) __UINT16_C(x)
# 420 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT32_C(x) __INT32_C(x)
#define UINT32_C(x) __UINT32_C(x)
# 433 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INT64_C(x) __INT64_C(x)
#define UINT64_C(x) __UINT64_C(x)
# 449 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_C(x) __INTMAX_C(x)
#define UINTMAX_C(x) __UINTMAX_C(x)
# 10 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 5 "../coolease/include/coolease/battery.h" 2
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdbool.h" 1 3 4
# 29 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 6 "../coolease/include/coolease/battery.h" 2






#define NUM_VOLTAGES 1
#define BATT_VOLTAGE 0



# 16 "../coolease/include/coolease/battery.h"
extern uint16_t batt_voltages[1];

extern 
# 18 "../coolease/include/coolease/battery.h" 3 4
      _Bool 
# 18 "../coolease/include/coolease/battery.h"
           batt_rst_seq;

void batt_init(void);
void batt_set_voltage_scale(uint8_t scale);
void batt_set_low_power_run(void);
void batt_update_voltages(void);
void batt_enable_interrupt(void);
void batt_enable_comp(void);
# 2 "lib//battery.c" 2

# 1 "../libopencm3/include/libopencm3/stm32/adc.h" 1
# 20 "../libopencm3/include/libopencm3/stm32/adc.h"
# 1 "../libopencm3/include/libopencm3/cm3/common.h" 1
# 21 "../libopencm3/include/libopencm3/cm3/common.h"
#define LIBOPENCM3_CM3_COMMON_H 
# 33 "../libopencm3/include/libopencm3/cm3/common.h"
#define BEGIN_DECLS 
#define END_DECLS 






#define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))
# 67 "../libopencm3/include/libopencm3/cm3/common.h"
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
# 21 "../libopencm3/include/libopencm3/stm32/adc.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/memorymap.h" 1
# 21 "../libopencm3/include/libopencm3/stm32/memorymap.h"
#define LIBOPENCM3_MEMORYMAP_COMMON_H 
# 36 "../libopencm3/include/libopencm3/stm32/memorymap.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/memorymap.h" 1
# 19 "../libopencm3/include/libopencm3/stm32/l0/memorymap.h"
#define LIBOPENCM3_MEMORYMAP_H 

# 1 "../libopencm3/include/libopencm3/cm3/memorymap.h" 1
# 21 "../libopencm3/include/libopencm3/cm3/memorymap.h"
#define LIBOPENCM3_CM3_MEMORYMAP_H 




#define PPBI_BASE (0xE0000000U)
# 42 "../libopencm3/include/libopencm3/cm3/memorymap.h"
#define SCS_BASE (PPBI_BASE + 0xE000)
# 60 "../libopencm3/include/libopencm3/cm3/memorymap.h"
#define SYS_TICK_BASE (SCS_BASE + 0x0010)


#define NVIC_BASE (SCS_BASE + 0x0100)


#define SCB_BASE (SCS_BASE + 0x0D00)


#define MPU_BASE (SCS_BASE + 0x0D90)




#define DEBUG_BASE (SCS_BASE + 0x0DF0)
# 91 "../libopencm3/include/libopencm3/cm3/memorymap.h"
#define CORESIGHT_LSR_OFFSET 0xfb4
#define CORESIGHT_LAR_OFFSET 0xfb0


#define CORESIGHT_LSR_SLK (1<<1)

#define CORESIGHT_LSR_SLI (1<<0)

#define CORESIGHT_LAR_KEY 0xC5ACCE55
# 22 "../libopencm3/include/libopencm3/stm32/l0/memorymap.h" 2




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
# 37 "../libopencm3/include/libopencm3/stm32/memorymap.h" 2
# 22 "../libopencm3/include/libopencm3/stm32/adc.h" 2
# 34 "../libopencm3/include/libopencm3/stm32/adc.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/adc.h" 1
# 34 "../libopencm3/include/libopencm3/stm32/l0/adc.h"
#define LIBOPENCM3_ADC_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define LIBOPENCM3_ADC_COMMON_V2_H 





#define ADC_ISR(adc) MMIO32((adc) + 0x00)

#define ADC_IER(adc) MMIO32((adc) + 0x04)

#define ADC_CR(adc) MMIO32((adc) + 0x08)

#define ADC_CFGR1(adc) MMIO32((adc) + 0x0C)

#define ADC_CFGR2(adc) MMIO32((adc) + 0x10)

#define ADC_SMPR1(adc) MMIO32((adc) + 0x14)

#define ADC_TR1(adc) MMIO32((adc) + 0x20)

#define ADC_DR(adc) MMIO32((adc) + 0x40)



#define ADC_CCR(adc) MMIO32((adc) + 0x300 + 0x8)
# 70 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define ADC_ISR_AWD1 (1 << 7)

#define ADC_ISR_OVR (1 << 4)

#define ADC_ISR_EOS (1 << 3)
#define ADC_ISR_EOSEQ ADC_ISR_EOS

#define ADC_ISR_EOC (1 << 2)

#define ADC_ISR_EOSMP (1 << 1)

#define ADC_ISR_ADRDY (1 << 0)
# 90 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define ADC_IER_AWD1IE (1 << 7)

#define ADC_IER_OVRIE (1 << 4)

#define ADC_IER_EOSIE (1 << 3)
#define ADC_IER_EOSEQIE ADC_IER_EOSIE

#define ADC_IER_EOCIE (1 << 2)

#define ADC_IER_EOSMPIE (1 << 1)

#define ADC_IER_ADRDYIE (1 << 0)
# 110 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define ADC_CR_ADCAL (1 << 31)

#define ADC_CR_ADSTP (1 << 4)

#define ADC_CR_ADSTART (1 << 2)

#define ADC_CR_ADDIS (1 << 1)

#define ADC_CR_ADEN (1 << 0)







#define ADC_CFGR1_AWD1CH_SHIFT 26
#define ADC_CFGR1_AWD1CH (0x1F << ADC_CFGR1_AWD1CH_SHIFT)

#define ADC_CFGR1_AWD1CH_VAL(x) ((x) << ADC_CFGR1_AWD1CH_SHIFT)


#define ADC_CFGR1_AWD1EN (1 << 23)

#define ADC_CFGR1_AWD1SGL (1 << 22)

#define ADC_CFGR1_DISCEN (1 << 16)

#define ADC_CFGR1_AUTDLY (1 << 14)

#define ADC_CFGR1_CONT (1 << 13)

#define ADC_CFGR1_OVRMOD (1 << 12)

#define ADC_CFGR1_EXTEN_MASK (0x3 << 10)


#define ADC_CFGR1_EXTEN_DISABLED (0x0 << 10)
#define ADC_CFGR1_EXTEN_RISING_EDGE (0x1 << 10)
#define ADC_CFGR1_EXTEN_FALLING_EDGE (0x2 << 10)
#define ADC_CFGR1_EXTEN_BOTH_EDGES (0x3 << 10)



#define ADC_CFGR1_ALIGN (1 << 5)

#define ADC_CFGR1_RES_MASK (0x3 << 3)


#define ADC_CFGR1_RES_12_BIT (0x0 << 3)
#define ADC_CFGR1_RES_10_BIT (0x1 << 3)
#define ADC_CFGR1_RES_8_BIT (0x2 << 3)
#define ADC_CFGR1_RES_6_BIT (0x3 << 3)



#define ADC_CFGR1_DMACFG (1 << 1)


#define ADC_CFGR1_DMAEN (1 << 0)
# 189 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define ADC_TR1_LT_SHIFT 0
#define ADC_TR1_LT_MASK 0xFFF
#define ADC_TR1_LT (0xFFF << ADC_TR1_LT_SHIFT)

#define ADC_TR1_LT_VAL(x) (((x) & ADC_TR1_LT_MASK) << ADC_TR1_LT_SHIFT)

#define ADC_TR1_HT_SHIFT 16
#define ADC_TR1_HT_MASK 0xFFF
#define ADC_TR1_HT (0xFFF << ADC_TR1_HT_SHIFT)

#define ADC_TR1_HT_VAL(x) (((x) & ADC_TR1_HT_MASK) << ADC_TR1_HT_SHIFT)
# 208 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
#define ADC_CCR_VBATEN (1 << 24)


#define ADC_CCR_TSEN (1 << 23)


#define ADC_CCR_VREFEN (1 << 22)







void adc_power_on_async(uint32_t adc);
void adc_power_on(uint32_t adc);

# 224 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 224 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_is_power_on(uint32_t adc);
void adc_power_off_async(uint32_t adc);
void adc_power_off(uint32_t adc);

# 227 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 227 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_is_power_off(uint32_t adc);
void adc_calibrate_async(uint32_t adc);

# 229 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 229 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_is_calibrating(uint32_t adc);
void adc_calibrate(uint32_t adc);
void adc_set_continuous_conversion_mode(uint32_t adc);
void adc_set_single_conversion_mode(uint32_t adc);
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[]);
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time);
void adc_enable_temperature_sensor(void);
void adc_disable_temperature_sensor(void);
void adc_enable_vrefint(void);
void adc_disable_vrefint(void);
void adc_set_resolution(uint32_t adc, uint16_t resolution);
void adc_set_left_aligned(uint32_t adc);
void adc_set_right_aligned(uint32_t adc);
void adc_enable_dma(uint32_t adc);
void adc_disable_dma(uint32_t adc);

# 244 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 244 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_eoc(uint32_t adc);

# 245 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 245 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_eos(uint32_t adc);
void adc_enable_eoc_interrupt(uint32_t adc);
void adc_disable_eoc_interrupt(uint32_t adc);
void adc_enable_overrun_interrupt(uint32_t adc);
void adc_disable_overrun_interrupt(uint32_t adc);

# 250 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h" 3 4
_Bool 
# 250 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2.h"
    adc_get_overrun_flag(uint32_t adc);
void adc_clear_overrun_flag(uint32_t adc);
uint32_t adc_read_regular(uint32_t adc);
void adc_start_conversion_regular(uint32_t adc);
void adc_enable_dma_circular_mode(uint32_t adc);
void adc_disable_dma_circular_mode(uint32_t adc);
void adc_enable_delayed_conversion_mode(uint32_t adc);
void adc_disable_delayed_conversion_mode(uint32_t adc);

# 37 "../libopencm3/include/libopencm3/stm32/l0/adc.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2_single.h" 1
# 43 "../libopencm3/include/libopencm3/stm32/common/adc_common_v2_single.h"
#define LIBOPENCM3_ADC_COMMON_V2_SINGLE_H 





#define ADC_CHSELR(adc) MMIO32((adc) + 0x28)







#define ADC_CFGR1_WAIT (1<<14)

#define ADC_CFGR1_AUTOFF (1 << 15)

#define ADC_CFGR1_EXTSEL_SHIFT 6
#define ADC_CFGR1_EXTSEL (0x7 << ADC_CFGR1_EXTSEL_SHIFT)

#define ADC_CFGR1_EXTSEL_VAL(x) ((x) << ADC_CFGR1_EXTSEL_SHIFT)


#define ADC_CFGR1_SCANDIR (1 << 2)





#define ADC_CHSELR_CHSEL(x) (1 << (x))







# 38 "../libopencm3/include/libopencm3/stm32/l0/adc.h" 2





#define ADC1 ADC1_BASE







#define ADC_CHANNEL_VLCD 16
#define ADC_CHANNEL_VREF 17
#define ADC_CHANNEL_TEMP 18



#define ADC_CALFACT(adc) MMIO32((adc) + 0xB4)




#define ADC_CFGR2_CKMODE_SHIFT 30
#define ADC_CFGR2_CKMODE (3 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_CK_ADC (0 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV2 (1 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK_DIV4 (2 << ADC_CFGR2_CKMODE_SHIFT)
#define ADC_CFGR2_CKMODE_PCLK (3 << ADC_CFGR2_CKMODE_SHIFT)





#define ADC_SMPR_SMP_1DOT5CYC 0x0
#define ADC_SMPR_SMP_3DOT5CYC 0x1
#define ADC_SMPR_SMP_7DOT5CYC 0x2
#define ADC_SMPR_SMP_12DOT5CYC 0x3
#define ADC_SMPR_SMP_19DOT5CYC 0x4
#define ADC_SMPR_SMP_39DOT5CYC 0x5
#define ADC_SMPR_SMP_79DOT5CYC 0x6
#define ADC_SMPR_SMP_160DOT5CYC 0x7






# 35 "../libopencm3/include/libopencm3/stm32/adc.h" 2
# 4 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/gpio.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/gpio.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/gpio.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define LIBOPENCM3_GPIO_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 1
# 37 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h"
#define LIBOPENCM3_GPIO_COMMON_F24_H 



# 1 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 1
# 37 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
#define LIBOPENCM3_GPIO_COMMON_F234_H 



# 1 "../libopencm3/include/libopencm3/stm32/common/gpio_common_all.h" 1
# 37 "../libopencm3/include/libopencm3/stm32/common/gpio_common_all.h"
#define LIBOPENCM3_GPIO_COMMON_ALL_H 







#define GPIO_LCKK (1 << 16)







#define GPIO0 (1 << 0)
#define GPIO1 (1 << 1)
#define GPIO2 (1 << 2)
#define GPIO3 (1 << 3)
#define GPIO4 (1 << 4)
#define GPIO5 (1 << 5)
#define GPIO6 (1 << 6)
#define GPIO7 (1 << 7)
#define GPIO8 (1 << 8)
#define GPIO9 (1 << 9)
#define GPIO10 (1 << 10)
#define GPIO11 (1 << 11)
#define GPIO12 (1 << 12)
#define GPIO13 (1 << 13)
#define GPIO14 (1 << 14)
#define GPIO15 (1 << 15)
#define GPIO_ALL 0xffff




void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint16_t data);
void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios);


# 42 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 2






#define GPIOA GPIO_PORT_A_BASE
#define GPIOB GPIO_PORT_B_BASE
#define GPIOC GPIO_PORT_C_BASE
#define GPIOD GPIO_PORT_D_BASE
#define GPIOE GPIO_PORT_E_BASE
#define GPIOF GPIO_PORT_F_BASE






#define GPIO_MODER(port) MMIO32((port) + 0x00)
#define GPIOA_MODER GPIO_MODER(GPIOA)
#define GPIOB_MODER GPIO_MODER(GPIOB)
#define GPIOC_MODER GPIO_MODER(GPIOC)
#define GPIOD_MODER GPIO_MODER(GPIOD)
#define GPIOE_MODER GPIO_MODER(GPIOE)
#define GPIOF_MODER GPIO_MODER(GPIOF)


#define GPIO_OTYPER(port) MMIO32((port) + 0x04)
#define GPIOA_OTYPER GPIO_OTYPER(GPIOA)
#define GPIOB_OTYPER GPIO_OTYPER(GPIOB)
#define GPIOC_OTYPER GPIO_OTYPER(GPIOC)
#define GPIOD_OTYPER GPIO_OTYPER(GPIOD)
#define GPIOE_OTYPER GPIO_OTYPER(GPIOE)
#define GPIOF_OTYPER GPIO_OTYPER(GPIOF)


#define GPIO_OSPEEDR(port) MMIO32((port) + 0x08)
#define GPIOA_OSPEEDR GPIO_OSPEEDR(GPIOA)
#define GPIOB_OSPEEDR GPIO_OSPEEDR(GPIOB)
#define GPIOC_OSPEEDR GPIO_OSPEEDR(GPIOC)
#define GPIOD_OSPEEDR GPIO_OSPEEDR(GPIOD)
#define GPIOE_OSPEEDR GPIO_OSPEEDR(GPIOE)
#define GPIOF_OSPEEDR GPIO_OSPEEDR(GPIOF)


#define GPIO_PUPDR(port) MMIO32((port) + 0x0c)
#define GPIOA_PUPDR GPIO_PUPDR(GPIOA)
#define GPIOB_PUPDR GPIO_PUPDR(GPIOB)
#define GPIOC_PUPDR GPIO_PUPDR(GPIOC)
#define GPIOD_PUPDR GPIO_PUPDR(GPIOD)
#define GPIOE_PUPDR GPIO_PUPDR(GPIOE)
#define GPIOF_PUPDR GPIO_PUPDR(GPIOF)


#define GPIO_IDR(port) MMIO32((port) + 0x10)
#define GPIOA_IDR GPIO_IDR(GPIOA)
#define GPIOB_IDR GPIO_IDR(GPIOB)
#define GPIOC_IDR GPIO_IDR(GPIOC)
#define GPIOD_IDR GPIO_IDR(GPIOD)
#define GPIOE_IDR GPIO_IDR(GPIOE)
#define GPIOF_IDR GPIO_IDR(GPIOF)


#define GPIO_ODR(port) MMIO32((port) + 0x14)
#define GPIOA_ODR GPIO_ODR(GPIOA)
#define GPIOB_ODR GPIO_ODR(GPIOB)
#define GPIOC_ODR GPIO_ODR(GPIOC)
#define GPIOD_ODR GPIO_ODR(GPIOD)
#define GPIOE_ODR GPIO_ODR(GPIOE)
#define GPIOF_ODR GPIO_ODR(GPIOF)


#define GPIO_BSRR(port) MMIO32((port) + 0x18)
#define GPIOA_BSRR GPIO_BSRR(GPIOA)
#define GPIOB_BSRR GPIO_BSRR(GPIOB)
#define GPIOC_BSRR GPIO_BSRR(GPIOC)
#define GPIOD_BSRR GPIO_BSRR(GPIOD)
#define GPIOE_BSRR GPIO_BSRR(GPIOE)
#define GPIOF_BSRR GPIO_BSRR(GPIOF)


#define GPIO_LCKR(port) MMIO32((port) + 0x1c)
#define GPIOA_LCKR GPIO_LCKR(GPIOA)
#define GPIOB_LCKR GPIO_LCKR(GPIOB)
#define GPIOC_LCKR GPIO_LCKR(GPIOC)
#define GPIOD_LCKR GPIO_LCKR(GPIOD)
#define GPIOE_LCKR GPIO_LCKR(GPIOE)
#define GPIOF_LCKR GPIO_LCKR(GPIOF)


#define GPIO_AFRL(port) MMIO32((port) + 0x20)
#define GPIOA_AFRL GPIO_AFRL(GPIOA)
#define GPIOB_AFRL GPIO_AFRL(GPIOB)
#define GPIOC_AFRL GPIO_AFRL(GPIOC)
#define GPIOD_AFRL GPIO_AFRL(GPIOD)
#define GPIOE_AFRL GPIO_AFRL(GPIOE)
#define GPIOF_AFRL GPIO_AFRL(GPIOF)


#define GPIO_AFRH(port) MMIO32((port) + 0x24)
#define GPIOA_AFRH GPIO_AFRH(GPIOA)
#define GPIOB_AFRH GPIO_AFRH(GPIOB)
#define GPIOC_AFRH GPIO_AFRH(GPIOC)
#define GPIOD_AFRH GPIO_AFRH(GPIOD)
#define GPIOE_AFRH GPIO_AFRH(GPIOE)
#define GPIOF_AFRH GPIO_AFRH(GPIOF)



#define GPIO_MODE(n,mode) ((mode) << (2 * (n)))
#define GPIO_MODE_MASK(n) (0x3 << (2 * (n)))



#define GPIO_MODE_INPUT 0x0
#define GPIO_MODE_OUTPUT 0x1
#define GPIO_MODE_AF 0x2
#define GPIO_MODE_ANALOG 0x3
# 168 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
#define GPIO_OTYPE_PP 0x0

#define GPIO_OTYPE_OD 0x1




#define GPIO_OSPEED(n,speed) ((speed) << (2 * (n)))
#define GPIO_OSPEED_MASK(n) (0x3 << (2 * (n)))



#define GPIO_OSPEED_2MHZ 0x0
#define GPIO_OSPEED_25MHZ 0x1
#define GPIO_OSPEED_50MHZ 0x2
#define GPIO_OSPEED_100MHZ 0x3




#define GPIO_PUPD(n,pupd) ((pupd) << (2 * (n)))
#define GPIO_PUPD_MASK(n) (0x3 << (2 * (n)))



#define GPIO_PUPD_NONE 0x0
#define GPIO_PUPD_PULLUP 0x1
#define GPIO_PUPD_PULLDOWN 0x2
# 213 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
#define GPIO_LCKK (1 << 16)







#define GPIO_AFR(n,af) ((af) << ((n) * 4))
#define GPIO_AFR_MASK(n) (0xf << ((n) * 4))



#define GPIO_AF0 0x0
#define GPIO_AF1 0x1
#define GPIO_AF2 0x2
#define GPIO_AF3 0x3
#define GPIO_AF4 0x4
#define GPIO_AF5 0x5
#define GPIO_AF6 0x6
#define GPIO_AF7 0x7
#define GPIO_AF8 0x8
#define GPIO_AF9 0x9
#define GPIO_AF10 0xa
#define GPIO_AF11 0xb
#define GPIO_AF12 0xc
#define GPIO_AF13 0xd
#define GPIO_AF14 0xe
#define GPIO_AF15 0xf







# 258 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);


# 42 "../libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 2






#define GPIOG GPIO_PORT_G_BASE
#define GPIOH GPIO_PORT_H_BASE
#define GPIOI GPIO_PORT_I_BASE
#define GPIOJ GPIO_PORT_J_BASE
#define GPIOK GPIO_PORT_K_BASE





#define GPIOG_MODER GPIO_MODER(GPIOG)
#define GPIOH_MODER GPIO_MODER(GPIOH)
#define GPIOI_MODER GPIO_MODER(GPIOI)
#define GPIOJ_MODER GPIO_MODER(GPIOJ)
#define GPIOK_MODER GPIO_MODER(GPIOK)


#define GPIOG_OTYPER GPIO_OTYPER(GPIOG)
#define GPIOH_OTYPER GPIO_OTYPER(GPIOH)
#define GPIOI_OTYPER GPIO_OTYPER(GPIOI)
#define GPIOJ_OTYPER GPIO_OTYPER(GPIOJ)
#define GPIOK_OTYPER GPIO_OTYPER(GPIOK)


#define GPIOG_OSPEEDR GPIO_OSPEEDR(GPIOG)
#define GPIOH_OSPEEDR GPIO_OSPEEDR(GPIOH)
#define GPIOI_OSPEEDR GPIO_OSPEEDR(GPIOI)
#define GPIOJ_OSPEEDR GPIO_OSPEEDR(GPIOJ)
#define GPIOK_OSPEEDR GPIO_OSPEEDR(GPIOK)


#define GPIOG_PUPDR GPIO_PUPDR(GPIOG)
#define GPIOH_PUPDR GPIO_PUPDR(GPIOH)
#define GPIOI_PUPDR GPIO_PUPDR(GPIOI)
#define GPIOJ_PUPDR GPIO_PUPDR(GPIOJ)
#define GPIOK_PUPDR GPIO_PUPDR(GPIOK)


#define GPIOG_IDR GPIO_IDR(GPIOG)
#define GPIOH_IDR GPIO_IDR(GPIOH)
#define GPIOI_IDR GPIO_IDR(GPIOI)
#define GPIOJ_IDR GPIO_IDR(GPIOJ)
#define GPIOK_IDR GPIO_IDR(GPIOK)


#define GPIOG_ODR GPIO_ODR(GPIOG)
#define GPIOH_ODR GPIO_ODR(GPIOH)
#define GPIOI_ODR GPIO_ODR(GPIOI)
#define GPIOJ_ODR GPIO_ODR(GPIOJ)
#define GPIOK_ODR GPIO_ODR(GPIOK)


#define GPIOG_BSRR GPIO_BSRR(GPIOG)
#define GPIOH_BSRR GPIO_BSRR(GPIOH)
#define GPIOI_BSRR GPIO_BSRR(GPIOI)
#define GPIOJ_BSRR GPIO_BSRR(GPIOJ)
#define GPIOK_BSRR GPIO_BSRR(GPIOK)


#define GPIOG_LCKR GPIO_LCKR(GPIOG)
#define GPIOH_LCKR GPIO_LCKR(GPIOH)
#define GPIOI_LCKR GPIO_LCKR(GPIOI)
#define GPIOJ_LCKR GPIO_LCKR(GPIOJ)
#define GPIOK_LCKR GPIO_LCKR(GPIOK)


#define GPIOG_AFRL GPIO_AFRL(GPIOG)
#define GPIOH_AFRL GPIO_AFRL(GPIOH)
#define GPIOI_AFRL GPIO_AFRL(GPIOI)
#define GPIOJ_AFRL GPIO_AFRL(GPIOJ)
#define GPIOK_AFRL GPIO_AFRL(GPIOK)


#define GPIOG_AFRH GPIO_AFRH(GPIOG)
#define GPIOH_AFRH GPIO_AFRH(GPIOH)
#define GPIOI_AFRH GPIO_AFRH(GPIOI)
#define GPIOJ_AFRH GPIO_AFRH(GPIOJ)
#define GPIOK_AFRH GPIO_AFRH(GPIOK)
# 35 "../libopencm3/include/libopencm3/stm32/l0/gpio.h" 2
# 44 "../libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define GPIO_BRR(port) MMIO32((port) + 0x28)
#define GPIOA_BRR GPIO_BRR(GPIOA)
#define GPIOB_BRR GPIO_BRR(GPIOB)
#define GPIOC_BRR GPIO_BRR(GPIOC)
#define GPIOD_BRR GPIO_BRR(GPIOD)
#define GPIOH_BRR GPIO_BRR(GPIOH)
# 58 "../libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define GPIO_OSPEED_LOW 0x0
#define GPIO_OSPEED_MED 0x1
#define GPIO_OSPEED_HIGH 0x2
#define GPIO_OSPEED_VERYHIGH 0x3
# 72 "../libopencm3/include/libopencm3/stm32/l0/gpio.h"



# 37 "../libopencm3/include/libopencm3/stm32/gpio.h" 2
# 5 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/rcc.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/rcc.h" 1
# 41 "../libopencm3/include/libopencm3/stm32/l0/rcc.h"
#define LIBOPENCM3_RCC_H 



# 1 "../libopencm3/include/libopencm3/stm32/pwr.h" 1
# 38 "../libopencm3/include/libopencm3/stm32/pwr.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/pwr.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/l0/pwr.h"
#define LIBOPENCM3_PWR_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h" 1
# 27 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h"
#define LIBOPENCM3_PWR_COMMON_V2_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 1
# 34 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
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

# 119 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 119 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_voltage_high(void);

# 120 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 120 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_get_standby_flag(void);

# 121 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h" 3 4
_Bool 
# 121 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v1.h"
    pwr_get_wakeup_flag(void);


# 30 "../libopencm3/include/libopencm3/stm32/common/pwr_common_v2.h" 2






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


# 35 "../libopencm3/include/libopencm3/stm32/l0/pwr.h" 2
# 39 "../libopencm3/include/libopencm3/stm32/pwr.h" 2
# 46 "../libopencm3/include/libopencm3/stm32/l0/rcc.h" 2



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
# 1 "../libopencm3/include/libopencm3/stm32/common/rcc_common_all.h" 1
# 35 "../libopencm3/include/libopencm3/stm32/common/rcc_common_all.h"
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







# 61 "../libopencm3/include/libopencm3/stm32/common/rcc_common_all.h" 3 4
_Bool 
# 61 "../libopencm3/include/libopencm3/stm32/common/rcc_common_all.h"
    rcc_is_osc_ready(enum rcc_osc osc);






void rcc_wait_for_osc_ready(enum rcc_osc osc);


# 680 "../libopencm3/include/libopencm3/stm32/l0/rcc.h" 2



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


# 37 "../libopencm3/include/libopencm3/stm32/rcc.h" 2
# 6 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/pwr.h" 1
# 7 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/flash.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/flash.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/flash.h" 1
# 31 "../libopencm3/include/libopencm3/stm32/l0/flash.h"
#define LIBOPENCM3_FLASH_H 


# 1 "../libopencm3/include/libopencm3/stm32/common/flash_common_all.h" 1
# 21 "../libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
       




# 37 "../libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
void flash_prefetch_enable(void);





void flash_prefetch_disable(void);
# 55 "../libopencm3/include/libopencm3/stm32/common/flash_common_all.h"
void flash_set_ws(uint32_t ws);




void flash_lock(void);





void flash_unlock(void);





void flash_unlock_option_bytes(void);


# 35 "../libopencm3/include/libopencm3/stm32/l0/flash.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/common/flash_common_l01.h" 1
# 29 "../libopencm3/include/libopencm3/stm32/common/flash_common_l01.h"
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


# 36 "../libopencm3/include/libopencm3/stm32/l0/flash.h" 2



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




# 37 "../libopencm3/include/libopencm3/stm32/flash.h" 2
# 8 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/syscfg.h" 1
# 34 "../libopencm3/include/libopencm3/stm32/syscfg.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/syscfg.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/l0/syscfg.h"
#define LIBOPENCM3_SYSCFG_H 
# 47 "../libopencm3/include/libopencm3/stm32/l0/syscfg.h"
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
# 130 "../libopencm3/include/libopencm3/stm32/l0/syscfg.h"



# 35 "../libopencm3/include/libopencm3/stm32/syscfg.h" 2
# 9 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/dma.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/dma.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/dma.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/l0/dma.h"
#define LIBOPENCM3_DMA_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h" 1
# 40 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h"
#define LIBOPENCM3_DMA_COMMON_F13_H 




#define DMA1 DMA1_BASE
#define DMA2 DMA2_BASE




#define DMA_ISR(dma_base) MMIO32((dma_base) + 0x00)
#define DMA1_ISR DMA_ISR(DMA1)
#define DMA2_ISR DMA_ISR(DMA2)


#define DMA_IFCR(dma_base) MMIO32((dma_base) + 0x04)
#define DMA1_IFCR DMA_IFCR(DMA1)
#define DMA2_IFCR DMA_IFCR(DMA2)


#define DMA_CCR(dma_base,channel) MMIO32((dma_base) + 0x08 + (0x14 * ((channel) - 1)))


#define DMA1_CCR(channel) DMA_CCR(DMA1, channel)
#define DMA1_CCR1 DMA1_CCR(DMA_CHANNEL1)
#define DMA1_CCR2 DMA1_CCR(DMA_CHANNEL2)
#define DMA1_CCR3 DMA1_CCR(DMA_CHANNEL3)
#define DMA1_CCR4 DMA1_CCR(DMA_CHANNEL4)
#define DMA1_CCR5 DMA1_CCR(DMA_CHANNEL5)
#define DMA1_CCR6 DMA1_CCR(DMA_CHANNEL6)
#define DMA1_CCR7 DMA1_CCR(DMA_CHANNEL7)

#define DMA2_CCR(channel) DMA_CCR(DMA2, channel)
#define DMA2_CCR1 DMA2_CCR(DMA_CHANNEL1)
#define DMA2_CCR2 DMA2_CCR(DMA_CHANNEL2)
#define DMA2_CCR3 DMA2_CCR(DMA_CHANNEL3)
#define DMA2_CCR4 DMA2_CCR(DMA_CHANNEL4)
#define DMA2_CCR5 DMA2_CCR(DMA_CHANNEL5)


#define DMA_CNDTR(dma_base,channel) MMIO32((dma_base) + 0x0C + (0x14 * ((channel) - 1)))


#define DMA1_CNDTR(channel) DMA_CNDTR(DMA1, channel)
#define DMA1_CNDTR1 DMA1_CNDTR(DMA_CHANNEL1)
#define DMA1_CNDTR2 DMA1_CNDTR(DMA_CHANNEL2)
#define DMA1_CNDTR3 DMA1_CNDTR(DMA_CHANNEL3)
#define DMA1_CNDTR4 DMA1_CNDTR(DMA_CHANNEL4)
#define DMA1_CNDTR5 DMA1_CNDTR(DMA_CHANNEL5)
#define DMA1_CNDTR6 DMA1_CNDTR(DMA_CHANNEL6)
#define DMA1_CNDTR7 DMA1_CNDTR(DMA_CHANNEL7)

#define DMA2_CNDTR(channel) DMA_CNDTR(DMA2, channel)
#define DMA2_CNDTR1 DMA2_CNDTR(DMA_CHANNEL1)
#define DMA2_CNDTR2 DMA2_CNDTR(DMA_CHANNEL2)
#define DMA2_CNDTR3 DMA2_CNDTR(DMA_CHANNEL3)
#define DMA2_CNDTR4 DMA2_CNDTR(DMA_CHANNEL4)
#define DMA2_CNDTR5 DMA2_CNDTR(DMA_CHANNEL5)


#define DMA_CPAR(dma_base,channel) MMIO32((dma_base) + 0x10 + (0x14 * ((channel) - 1)))


#define DMA1_CPAR(channel) DMA_CPAR(DMA1, channel)
#define DMA1_CPAR1 DMA1_CPAR(DMA_CHANNEL1)
#define DMA1_CPAR2 DMA1_CPAR(DMA_CHANNEL2)
#define DMA1_CPAR3 DMA1_CPAR(DMA_CHANNEL3)
#define DMA1_CPAR4 DMA1_CPAR(DMA_CHANNEL4)
#define DMA1_CPAR5 DMA1_CPAR(DMA_CHANNEL5)
#define DMA1_CPAR6 DMA1_CPAR(DMA_CHANNEL6)
#define DMA1_CPAR7 DMA1_CPAR(DMA_CHANNEL7)

#define DMA2_CPAR(channel) DMA_CPAR(DMA2, channel)
#define DMA2_CPAR1 DMA2_CPAR(DMA_CHANNEL1)
#define DMA2_CPAR2 DMA2_CPAR(DMA_CHANNEL2)
#define DMA2_CPAR3 DMA2_CPAR(DMA_CHANNEL3)
#define DMA2_CPAR4 DMA2_CPAR(DMA_CHANNEL4)
#define DMA2_CPAR5 DMA2_CPAR(DMA_CHANNEL5)



#define DMA_CMAR(dma_base,channel) MMIO32((dma_base) + 0x14 + (0x14 * ((channel) - 1)))


#define DMA1_CMAR(channel) DMA_CMAR(DMA1, channel)
#define DMA1_CMAR1 DMA1_CMAR(DMA_CHANNEL1)
#define DMA1_CMAR2 DMA1_CMAR(DMA_CHANNEL2)
#define DMA1_CMAR3 DMA1_CMAR(DMA_CHANNEL3)
#define DMA1_CMAR4 DMA1_CMAR(DMA_CHANNEL4)
#define DMA1_CMAR5 DMA1_CMAR(DMA_CHANNEL5)
#define DMA1_CMAR6 DMA1_CMAR(DMA_CHANNEL6)
#define DMA1_CMAR7 DMA1_CMAR(DMA_CHANNEL7)

#define DMA2_CMAR(channel) DMA_CMAR(DMA2, channel)
#define DMA2_CMAR1 DMA2_CMAR(DMA_CHANNEL1)
#define DMA2_CMAR2 DMA2_CMAR(DMA_CHANNEL2)
#define DMA2_CMAR3 DMA2_CMAR(DMA_CHANNEL3)
#define DMA2_CMAR4 DMA2_CMAR(DMA_CHANNEL4)
#define DMA2_CMAR5 DMA2_CMAR(DMA_CHANNEL5)
# 153 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h"
#define DMA_TEIF (1 << 3)

#define DMA_HTIF (1 << 2)

#define DMA_TCIF (1 << 1)

#define DMA_GIF (1 << 0)





#define DMA_FLAG_OFFSET(channel) (4*((channel) - 1))
#define DMA_FLAGS (DMA_TEIF | DMA_TCIF | DMA_HTIF | DMA_GIF)

#define DMA_ISR_MASK(channel) (DMA_FLAGS << DMA_FLAG_OFFSET(channel))


#define DMA_ISR_TEIF_BIT DMA_TEIF
#define DMA_ISR_TEIF(channel) (DMA_ISR_TEIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_ISR_TEIF1 DMA_ISR_TEIF(DMA_CHANNEL1)
#define DMA_ISR_TEIF2 DMA_ISR_TEIF(DMA_CHANNEL2)
#define DMA_ISR_TEIF3 DMA_ISR_TEIF(DMA_CHANNEL3)
#define DMA_ISR_TEIF4 DMA_ISR_TEIF(DMA_CHANNEL4)
#define DMA_ISR_TEIF5 DMA_ISR_TEIF(DMA_CHANNEL5)
#define DMA_ISR_TEIF6 DMA_ISR_TEIF(DMA_CHANNEL6)
#define DMA_ISR_TEIF7 DMA_ISR_TEIF(DMA_CHANNEL7)


#define DMA_ISR_HTIF_BIT DMA_HTIF
#define DMA_ISR_HTIF(channel) (DMA_ISR_HTIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_ISR_HTIF1 DMA_ISR_HTIF(DMA_CHANNEL1)
#define DMA_ISR_HTIF2 DMA_ISR_HTIF(DMA_CHANNEL2)
#define DMA_ISR_HTIF3 DMA_ISR_HTIF(DMA_CHANNEL3)
#define DMA_ISR_HTIF4 DMA_ISR_HTIF(DMA_CHANNEL4)
#define DMA_ISR_HTIF5 DMA_ISR_HTIF(DMA_CHANNEL5)
#define DMA_ISR_HTIF6 DMA_ISR_HTIF(DMA_CHANNEL6)
#define DMA_ISR_HTIF7 DMA_ISR_HTIF(DMA_CHANNEL7)


#define DMA_ISR_TCIF_BIT DMA_TCIF
#define DMA_ISR_TCIF(channel) (DMA_ISR_TCIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_ISR_TCIF1 DMA_ISR_TCIF(DMA_CHANNEL1)
#define DMA_ISR_TCIF2 DMA_ISR_TCIF(DMA_CHANNEL2)
#define DMA_ISR_TCIF3 DMA_ISR_TCIF(DMA_CHANNEL3)
#define DMA_ISR_TCIF4 DMA_ISR_TCIF(DMA_CHANNEL4)
#define DMA_ISR_TCIF5 DMA_ISR_TCIF(DMA_CHANNEL5)
#define DMA_ISR_TCIF6 DMA_ISR_TCIF(DMA_CHANNEL6)
#define DMA_ISR_TCIF7 DMA_ISR_TCIF(DMA_CHANNEL7)


#define DMA_ISR_GIF_BIT DMA_GIF
#define DMA_ISR_GIF(channel) (DMA_ISR_GIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_ISR_GIF1 DMA_ISR_GIF(DMA_CHANNEL1)
#define DMA_ISR_GIF2 DMA_ISR_GIF(DMA_CHANNEL2)
#define DMA_ISR_GIF3 DMA_ISR_GIF(DMA_CHANNEL3)
#define DMA_ISR_GIF4 DMA_ISR_GIF(DMA_CHANNEL4)
#define DMA_ISR_GIF5 DMA_ISR_GIF(DMA_CHANNEL5)
#define DMA_ISR_GIF6 DMA_ISR_GIF(DMA_CHANNEL6)
#define DMA_ISR_GIF7 DMA_ISR_GIF(DMA_CHANNEL7)




#define DMA_IFCR_CTEIF_BIT DMA_TEIF
#define DMA_IFCR_CTEIF(channel) (DMA_IFCR_CTEIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_IFCR_CTEIF1 DMA_IFCR_CTEIF(DMA_CHANNEL1)
#define DMA_IFCR_CTEIF2 DMA_IFCR_CTEIF(DMA_CHANNEL2)
#define DMA_IFCR_CTEIF3 DMA_IFCR_CTEIF(DMA_CHANNEL3)
#define DMA_IFCR_CTEIF4 DMA_IFCR_CTEIF(DMA_CHANNEL4)
#define DMA_IFCR_CTEIF5 DMA_IFCR_CTEIF(DMA_CHANNEL5)
#define DMA_IFCR_CTEIF6 DMA_IFCR_CTEIF(DMA_CHANNEL6)
#define DMA_IFCR_CTEIF7 DMA_IFCR_CTEIF(DMA_CHANNEL7)


#define DMA_IFCR_CHTIF_BIT DMA_HTIF
#define DMA_IFCR_CHTIF(channel) (DMA_IFCR_CHTIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_IFCR_CHTIF1 DMA_IFCR_CHTIF(DMA_CHANNEL1)
#define DMA_IFCR_CHTIF2 DMA_IFCR_CHTIF(DMA_CHANNEL2)
#define DMA_IFCR_CHTIF3 DMA_IFCR_CHTIF(DMA_CHANNEL3)
#define DMA_IFCR_CHTIF4 DMA_IFCR_CHTIF(DMA_CHANNEL4)
#define DMA_IFCR_CHTIF5 DMA_IFCR_CHTIF(DMA_CHANNEL5)
#define DMA_IFCR_CHTIF6 DMA_IFCR_CHTIF(DMA_CHANNEL6)
#define DMA_IFCR_CHTIF7 DMA_IFCR_CHTIF(DMA_CHANNEL7)


#define DMA_IFCR_CTCIF_BIT DMA_TCIF
#define DMA_IFCR_CTCIF(channel) (DMA_IFCR_CTCIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_IFCR_CTCIF1 DMA_IFCR_CTCIF(DMA_CHANNEL1)
#define DMA_IFCR_CTCIF2 DMA_IFCR_CTCIF(DMA_CHANNEL2)
#define DMA_IFCR_CTCIF3 DMA_IFCR_CTCIF(DMA_CHANNEL3)
#define DMA_IFCR_CTCIF4 DMA_IFCR_CTCIF(DMA_CHANNEL4)
#define DMA_IFCR_CTCIF5 DMA_IFCR_CTCIF(DMA_CHANNEL5)
#define DMA_IFCR_CTCIF6 DMA_IFCR_CTCIF(DMA_CHANNEL6)
#define DMA_IFCR_CTCIF7 DMA_IFCR_CTCIF(DMA_CHANNEL7)


#define DMA_IFCR_CGIF_BIT DMA_GIF
#define DMA_IFCR_CGIF(channel) (DMA_IFCR_CGIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_IFCR_CGIF1 DMA_IFCR_CGIF(DMA_CHANNEL1)
#define DMA_IFCR_CGIF2 DMA_IFCR_CGIF(DMA_CHANNEL2)
#define DMA_IFCR_CGIF3 DMA_IFCR_CGIF(DMA_CHANNEL3)
#define DMA_IFCR_CGIF4 DMA_IFCR_CGIF(DMA_CHANNEL4)
#define DMA_IFCR_CGIF5 DMA_IFCR_CGIF(DMA_CHANNEL5)
#define DMA_IFCR_CGIF6 DMA_IFCR_CGIF(DMA_CHANNEL6)
#define DMA_IFCR_CGIF7 DMA_IFCR_CGIF(DMA_CHANNEL7)


#define DMA_IFCR_CIF_BIT 0xF
#define DMA_IFCR_CIF(channel) (DMA_IFCR_CIF_BIT << (DMA_FLAG_OFFSET(channel)))


#define DMA_IFCR_CIF1 DMA_IFCR_CIF(DMA_CHANNEL1)
#define DMA_IFCR_CIF2 DMA_IFCR_CIF(DMA_CHANNEL2)
#define DMA_IFCR_CIF3 DMA_IFCR_CIF(DMA_CHANNEL3)
#define DMA_IFCR_CIF4 DMA_IFCR_CIF(DMA_CHANNEL4)
#define DMA_IFCR_CIF5 DMA_IFCR_CIF(DMA_CHANNEL5)
#define DMA_IFCR_CIF6 DMA_IFCR_CIF(DMA_CHANNEL6)
#define DMA_IFCR_CIF7 DMA_IFCR_CIF(DMA_CHANNEL7)




#define DMA_CCR_MEM2MEM (1 << 14)






#define DMA_CCR_PL_LOW (0x0 << 12)
#define DMA_CCR_PL_MEDIUM (0x1 << 12)
#define DMA_CCR_PL_HIGH (0x2 << 12)
#define DMA_CCR_PL_VERY_HIGH (0x3 << 12)

#define DMA_CCR_PL_MASK (0x3 << 12)
#define DMA_CCR_PL_SHIFT 12






#define DMA_CCR_MSIZE_8BIT (0x0 << 10)
#define DMA_CCR_MSIZE_16BIT (0x1 << 10)
#define DMA_CCR_MSIZE_32BIT (0x2 << 10)

#define DMA_CCR_MSIZE_MASK (0x3 << 10)
#define DMA_CCR_MSIZE_SHIFT 10






#define DMA_CCR_PSIZE_8BIT (0x0 << 8)
#define DMA_CCR_PSIZE_16BIT (0x1 << 8)
#define DMA_CCR_PSIZE_32BIT (0x2 << 8)

#define DMA_CCR_PSIZE_MASK (0x3 << 8)
#define DMA_CCR_PSIZE_SHIFT 8


#define DMA_CCR_MINC (1 << 7)


#define DMA_CCR_PINC (1 << 6)


#define DMA_CCR_CIRC (1 << 5)


#define DMA_CCR_DIR (1 << 4)


#define DMA_CCR_TEIE (1 << 3)


#define DMA_CCR_HTIE (1 << 2)


#define DMA_CCR_TCIE (1 << 1)


#define DMA_CCR_EN (1 << 0)
# 373 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h"
#define DMA_CHANNEL1 1
#define DMA_CHANNEL2 2
#define DMA_CHANNEL3 3
#define DMA_CHANNEL4 4
#define DMA_CHANNEL5 5
#define DMA_CHANNEL6 6
#define DMA_CHANNEL7 7






void dma_channel_reset(uint32_t dma, uint8_t channel);
void dma_clear_interrupt_flags(uint32_t dma, uint8_t channel,
          uint32_t interrupts);

# 389 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h" 3 4
_Bool 
# 389 "../libopencm3/include/libopencm3/stm32/common/dma_common_l1f013.h"
    dma_get_interrupt_flag(uint32_t dma, uint8_t channel, uint32_t interrupts);
void dma_enable_mem2mem_mode(uint32_t dma, uint8_t channel);
void dma_set_priority(uint32_t dma, uint8_t channel, uint32_t prio);
void dma_set_memory_size(uint32_t dma, uint8_t channel, uint32_t mem_size);
void dma_set_peripheral_size(uint32_t dma, uint8_t channel,
        uint32_t peripheral_size);
void dma_enable_memory_increment_mode(uint32_t dma, uint8_t channel);
void dma_disable_memory_increment_mode(uint32_t dma, uint8_t channel);
void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t channel);
void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t channel);
void dma_enable_circular_mode(uint32_t dma, uint8_t channel);
void dma_set_read_from_peripheral(uint32_t dma, uint8_t channel);
void dma_set_read_from_memory(uint32_t dma, uint8_t channel);
void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_channel(uint32_t dma, uint8_t channel);
void dma_disable_channel(uint32_t dma, uint8_t channel);
void dma_set_peripheral_address(uint32_t dma, uint8_t channel,
    uint32_t address);
void dma_set_memory_address(uint32_t dma, uint8_t channel, uint32_t address);
uint16_t dma_get_number_of_data(uint32_t dma, uint8_t channel);
void dma_set_number_of_data(uint32_t dma, uint8_t channel, uint16_t number);


# 35 "../libopencm3/include/libopencm3/stm32/l0/dma.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/common/dma_common_csel.h" 1
# 29 "../libopencm3/include/libopencm3/stm32/common/dma_common_csel.h"
       



#define DMA_CSELR(dma_base) MMIO32((dma_base) + 0xA8)
#define DMA1_CSELR DMA_CSELR(DMA1)
#define DMA2_CSELR DMA_CSELR(DMA2)



#define DMA_CSELR_CxS_SHIFT(channel) (4 * ((channel) - 1))
#define DMA_CSELR_CxS_MASK (0x0f)





void dma_set_channel_request(uint32_t dma, uint8_t channel, uint8_t request);


# 36 "../libopencm3/include/libopencm3/stm32/l0/dma.h" 2
# 37 "../libopencm3/include/libopencm3/stm32/dma.h" 2
# 10 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/stm32/exti.h" 1
# 38 "../libopencm3/include/libopencm3/stm32/exti.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/exti.h" 1
# 37 "../libopencm3/include/libopencm3/stm32/l0/exti.h"
#define LIBOPENCM3_EXTI_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/exti_common_all.h" 1
# 29 "../libopencm3/include/libopencm3/stm32/common/exti_common_all.h"
#define LIBOPENCM3_EXTI_COMMON_ALL_H 



#define EXTI0 (1 << 0)
#define EXTI1 (1 << 1)
#define EXTI2 (1 << 2)
#define EXTI3 (1 << 3)
#define EXTI4 (1 << 4)
#define EXTI5 (1 << 5)
#define EXTI6 (1 << 6)
#define EXTI7 (1 << 7)
#define EXTI8 (1 << 8)
#define EXTI9 (1 << 9)
#define EXTI10 (1 << 10)
#define EXTI11 (1 << 11)
#define EXTI12 (1 << 12)
#define EXTI13 (1 << 13)
#define EXTI14 (1 << 14)
#define EXTI15 (1 << 15)
#define EXTI16 (1 << 16)
#define EXTI17 (1 << 17)
#define EXTI18 (1 << 18)
#define EXTI19 (1 << 19)
#define EXTI20 (1 << 20)
#define EXTI21 (1 << 21)
#define EXTI22 (1 << 22)
#define EXTI23 (1 << 23)
#define EXTI24 (1 << 24)
#define EXTI25 (1 << 25)
#define EXTI26 (1 << 26)
#define EXTI27 (1 << 27)
#define EXTI28 (1 << 28)
#define EXTI29 (1 << 29)
#define EXTI30 (1 << 30)
#define EXTI31 (1 << 31)

#define EXTI32 (1 << 0)
#define EXTI33 (1 << 1)
#define EXTI34 (1 << 2)
#define EXTI35 (1 << 3)
#define EXTI36 (1 << 4)
#define EXTI37 (1 << 5)


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


# 40 "../libopencm3/include/libopencm3/stm32/l0/exti.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/common/exti_common_v1.h" 1

       
# 32 "../libopencm3/include/libopencm3/stm32/common/exti_common_v1.h"
#define EXTI_IMR MMIO32(EXTI_BASE + 0x00)

#define EXTI_EMR MMIO32(EXTI_BASE + 0x04)

#define EXTI_RTSR MMIO32(EXTI_BASE + 0x08)

#define EXTI_FTSR MMIO32(EXTI_BASE + 0x0c)

#define EXTI_SWIER MMIO32(EXTI_BASE + 0x10)

#define EXTI_PR MMIO32(EXTI_BASE + 0x14)





# 41 "../libopencm3/include/libopencm3/stm32/l0/exti.h" 2
# 39 "../libopencm3/include/libopencm3/stm32/exti.h" 2
# 11 "lib//battery.c" 2
# 1 "../libopencm3/include/libopencm3/cm3/nvic.h" 1
# 38 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define LIBOPENCM3_NVIC_H 
# 51 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ISER(iser_id) MMIO32(NVIC_BASE + 0x00 + ((iser_id) * 4))
# 60 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ICER(icer_id) MMIO32(NVIC_BASE + 0x80 + ((icer_id) * 4))
# 69 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ISPR(ispr_id) MMIO32(NVIC_BASE + 0x100 + ((ispr_id) * 4))
# 78 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_ICPR(icpr_id) MMIO32(NVIC_BASE + 0x180 + ((icpr_id) * 4))
# 98 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_IPR32(ipr_id) MMIO32(NVIC_BASE + 0x300 + ((ipr_id) * 4))
# 120 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_NMI_IRQ -14
#define NVIC_HARD_FAULT_IRQ -13
# 131 "../libopencm3/include/libopencm3/cm3/nvic.h"
#define NVIC_SV_CALL_IRQ -5







#define NVIC_PENDSV_IRQ -2
#define NVIC_SYSTICK_IRQ -1






# 1 "../libopencm3/include/libopencm3/dispatch/nvic.h" 1
# 18 "../libopencm3/include/libopencm3/dispatch/nvic.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/nvic.h" 1






#define LIBOPENCM3_STM32_L0_NVIC_H 

# 1 "../libopencm3/include/libopencm3/cm3/nvic.h" 1
# 10 "../libopencm3/include/libopencm3/stm32/l0/nvic.h" 2






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
# 58 "../libopencm3/include/libopencm3/stm32/l0/nvic.h"


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


# 19 "../libopencm3/include/libopencm3/dispatch/nvic.h" 2
# 148 "../libopencm3/include/libopencm3/cm3/nvic.h" 2





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
# 182 "../libopencm3/include/libopencm3/cm3/nvic.h"

# 12 "lib//battery.c" 2

# 1 "../coolease/include/coolease/serial_printf.h" 1

#define SERIAL_PRINTF_H 

# 1 "../coolease/include/coolease/printf.h" 1
# 33 "../coolease/include/coolease/printf.h"
#define _PRINTF_H_ 

# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 1 3 4
# 31 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4
#define _STDARG_H 
#define _ANSI_STDARG_H_ 

#undef __need___va_list




#define __GNUC_VA_LIST 

# 40 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;






#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)


#define va_copy(d,s) __builtin_va_copy(d,s)

#define __va_copy(d,s) __builtin_va_copy(d,s)
# 99 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;





#define _VA_LIST_ 


#define _VA_LIST 


#define _VA_LIST_DEFINED 


#define _VA_LIST_T_H 


#define __va_list__ 
# 36 "../coolease/include/coolease/printf.h" 2
# 1 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 1 3 4
# 39 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 
# 131 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 
#define _PTRDIFF_T_DECLARED 



typedef int ptrdiff_t;
# 155 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 181 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
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
# 231 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 260 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
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
# 287 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#undef _BSD_WCHAR_T_
# 321 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 340 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/Users/richarddavies/Desktop/Projects/CoolEase/Old Code/stm32l051c8t6_rfm/util/gcc-arm/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 37 "../coolease/include/coolease/printf.h" 2
# 49 "../coolease/include/coolease/printf.h"

# 49 "../coolease/include/coolease/printf.h"
void _putchar_spf(char character);
void _putchar_sim(char character);
void _putchar_log(char character);

int vprintf_spf(const char* format, va_list va);
int vprintf_sim(const char* format, va_list va);
int vprintf_log(const char* format, va_list va);
# 5 "../coolease/include/coolease/serial_printf.h" 2

void spf_init(void);
int spf_serial_printf(const char* format, ...);
# 14 "lib//battery.c" 2
# 1 "../coolease/include/coolease/board_defs.h" 1

#define BOARD_DEFS_H 

# 1 "../libopencm3/include/libopencm3/stm32/gpio.h" 1
# 5 "../coolease/include/coolease/board_defs.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/rcc.h" 1
# 6 "../coolease/include/coolease/board_defs.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/spi.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/spi.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/spi.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/l0/spi.h"
#define LIBOPENCM3_SPI_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h"
       



# 1 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 1
# 32 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"
       



# 1 "../libopencm3/include/libopencm3/stm32/common/spi_common_all.h" 1
# 33 "../libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
#define LIBOPENCM3_SPI_COMMON_ALL_H 
# 46 "../libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
#define SPI1 SPI1_BASE
#define SPI2 SPI2_BASE
#define SPI3 SPI3_BASE
#define SPI4 SPI4_BASE
#define SPI5 SPI5_BASE
#define SPI6 SPI6_BASE






#define SPI_CR1(spi_base) MMIO32((spi_base) + 0x00)
#define SPI1_CR1 SPI_CR1(SPI1_BASE)
#define SPI2_CR1 SPI_CR1(SPI2_BASE)
#define SPI3_CR1 SPI_CR1(SPI3_BASE)


#define SPI_CR2(spi_base) MMIO32((spi_base) + 0x04)
#define SPI1_CR2 SPI_CR2(SPI1_BASE)
#define SPI2_CR2 SPI_CR2(SPI2_BASE)
#define SPI3_CR2 SPI_CR2(SPI3_BASE)


#define SPI_SR(spi_base) MMIO32((spi_base) + 0x08)
#define SPI1_SR SPI_SR(SPI1_BASE)
#define SPI2_SR SPI_SR(SPI2_BASE)
#define SPI3_SR SPI_SR(SPI3_BASE)


#define SPI_DR(spi_base) MMIO32((spi_base) + 0x0c)
#define SPI1_DR SPI_DR(SPI1_BASE)
#define SPI2_DR SPI_DR(SPI2_BASE)
#define SPI3_DR SPI_DR(SPI3_BASE)



#define SPI_CRCPR(spi_base) MMIO32((spi_base) + 0x10)
#define SPI1_CRCPR SPI_CRCPR(SPI1_BASE)
#define SPI2_CRCPR SPI_CRCPR(SPI2_BASE)
#define SPI3_CRCPR SPI_CRCPR(SPI3_BASE)



#define SPI_RXCRCR(spi_base) MMIO32((spi_base) + 0x14)
#define SPI1_RXCRCR SPI_RXCRCR(SPI1_BASE)
#define SPI2_RXCRCR SPI_RXCRCR(SPI2_BASE)
#define SPI3_RXCRCR SPI_RXCRCR(SPI3_BASE)



#define SPI_TXCRCR(spi_base) MMIO32((spi_base) + 0x18)
#define SPI1_TXCRCR SPI_TXCRCR(SPI1_BASE)
#define SPI2_TXCRCR SPI_TXCRCR(SPI2_BASE)
#define SPI3_TXCRCR SPI_TXCRCR(SPI3_BASE)


#define SPI_I2SCFGR(spi_base) MMIO32((spi_base) + 0x1c)
#define SPI1_I2SCFGR SPI_I2SCFGR(SPI1_BASE)
#define SPI2_I2SCFGR SPI_I2SCFGR(SPI2_BASE)
#define SPI3_I2SCFGR SPI_I2SCFGR(SPI3_BASE)


#define SPI_I2SPR(spi_base) MMIO32((spi_base) + 0x20)
#define SPI1_I2SPR SPI_I2SPR(SPI1_BASE)
#define SPI2_I2SPR SPI_I2SPR(SPI2_BASE)
#define SPI3_I2SPR SPI_I2SPR(SPI3_BASE)






#define SPI_CR1_BIDIMODE_2LINE_UNIDIR (0 << 15)
#define SPI_CR1_BIDIMODE_1LINE_BIDIR (1 << 15)
#define SPI_CR1_BIDIMODE (1 << 15)


#define SPI_CR1_BIDIOE (1 << 14)


#define SPI_CR1_CRCEN (1 << 13)


#define SPI_CR1_CRCNEXT (1 << 12)


#define SPI_CR1_RXONLY (1 << 10)


#define SPI_CR1_SSM (1 << 9)


#define SPI_CR1_SSI (1 << 8)







#define SPI_CR1_MSBFIRST (0 << 7)
#define SPI_CR1_LSBFIRST (1 << 7)



#define SPI_CR1_SPE (1 << 6)







#define SPI_CR1_BAUDRATE_FPCLK_DIV_2 (0x00 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_4 (0x01 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_8 (0x02 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_16 (0x03 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_32 (0x04 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_64 (0x05 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_128 (0x06 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_256 (0x07 << 3)






#define SPI_CR1_BR_FPCLK_DIV_2 0x0
#define SPI_CR1_BR_FPCLK_DIV_4 0x1
#define SPI_CR1_BR_FPCLK_DIV_8 0x2
#define SPI_CR1_BR_FPCLK_DIV_16 0x3
#define SPI_CR1_BR_FPCLK_DIV_32 0x4
#define SPI_CR1_BR_FPCLK_DIV_64 0x5
#define SPI_CR1_BR_FPCLK_DIV_128 0x6
#define SPI_CR1_BR_FPCLK_DIV_256 0x7



#define SPI_CR1_MSTR (1 << 2)







#define SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE (0 << 1)
#define SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE (1 << 1)

#define SPI_CR1_CPOL (1 << 1)







#define SPI_CR1_CPHA_CLK_TRANSITION_1 (0 << 0)
#define SPI_CR1_CPHA_CLK_TRANSITION_2 (1 << 0)

#define SPI_CR1_CPHA (1 << 0)






#define SPI_CR2_TXEIE (1 << 7)


#define SPI_CR2_RXNEIE (1 << 6)


#define SPI_CR2_ERRIE (1 << 5)





#define SPI_CR2_SSOE (1 << 2)


#define SPI_CR2_TXDMAEN (1 << 1)


#define SPI_CR2_RXDMAEN (1 << 0)






#define SPI_SR_BSY (1 << 7)


#define SPI_SR_OVR (1 << 6)



#define SPI_SR_MODF (1 << 5)



#define SPI_SR_CRCERR (1 << 4)



#define SPI_SR_UDR (1 << 3)



#define SPI_SR_CHSIDE (1 << 2)


#define SPI_SR_TXE (1 << 1)


#define SPI_SR_RXNE (1 << 0)
# 292 "../libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
#define SPI_I2SCFGR_I2SMOD (1 << 11)


#define SPI_I2SCFGR_I2SE (1 << 10)


#define SPI_I2SCFGR_I2SCFG_LSB 8
#define SPI_I2SCFGR_I2SCFG_SLAVE_TRANSMIT 0x0
#define SPI_I2SCFGR_I2SCFG_SLAVE_RECEIVE 0x1
#define SPI_I2SCFGR_I2SCFG_MASTER_TRANSMIT 0x2
#define SPI_I2SCFGR_I2SCFG_MASTER_RECEIVE 0x3


#define SPI_I2SCFGR_PCMSYNC (1 << 7)




#define SPI_I2SCFGR_I2SSTD_LSB 4
#define SPI_I2SCFGR_I2SSTD_I2S_PHILIPS 0x0
#define SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED 0x1
#define SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED 0x2
#define SPI_I2SCFGR_I2SSTD_PCM 0x3


#define SPI_I2SCFGR_CKPOL (1 << 3)


#define SPI_I2SCFGR_DATLEN_LSB 1
#define SPI_I2SCFGR_DATLEN_16BIT 0x0
#define SPI_I2SCFGR_DATLEN_24BIT 0x1
#define SPI_I2SCFGR_DATLEN_32BIT 0x2


#define SPI_I2SCFGR_CHLEN (1 << 0)
# 335 "../libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
#define SPI_I2SPR_MCKOE (1 << 9)


#define SPI_I2SPR_ODD (1 << 8)








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


# 37 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 2
# 45 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"
#define SPI_CR1_DFF_8BIT (0 << 11)
#define SPI_CR1_DFF_16BIT (1 << 11)



#define SPI_CR1_DFF (1 << 11)





int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
  uint32_t dff, uint32_t lsbfirst);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);


# 37 "../libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 2





#define SPI_CR2_FRF (1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE (0 << 4)
#define SPI_CR2_FRF_TI_MODE (1 << 4)




#define SPI_SR_TIFRFE (1 << 8)
#define SPI_SR_FRE (1 << 8)





void spi_set_frf_ti(uint32_t spi);
void spi_set_frf_motorola(uint32_t spi);


# 35 "../libopencm3/include/libopencm3/stm32/l0/spi.h" 2
# 37 "../libopencm3/include/libopencm3/stm32/spi.h" 2
# 7 "../coolease/include/coolease/board_defs.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/usart.h" 1
# 36 "../libopencm3/include/libopencm3/stm32/usart.h"
# 1 "../libopencm3/include/libopencm3/stm32/l0/usart.h" 1
# 28 "../libopencm3/include/libopencm3/stm32/l0/usart.h"
#define LIBOPENCM3_USART_H 

# 1 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 1
# 35 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
#define LIBOPENCM3_USART_COMMON_ALL_H 
# 46 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
#define USART_PARITY_NONE 0x00
#define USART_PARITY_EVEN USART_CR1_PCE
#define USART_PARITY_ODD (USART_CR1_PS | USART_CR1_PCE)

#define USART_PARITY_MASK (USART_CR1_PS | USART_CR1_PCE)







#define USART_MODE_RX USART_CR1_RE
#define USART_MODE_TX USART_CR1_TE
#define USART_MODE_TX_RX (USART_CR1_RE | USART_CR1_TE)

#define USART_MODE_MASK (USART_CR1_RE | USART_CR1_TE)






#define USART_STOPBITS_1 USART_CR2_STOPBITS_1
#define USART_STOPBITS_0_5 USART_CR2_STOPBITS_0_5
#define USART_STOPBITS_2 USART_CR2_STOPBITS_2
#define USART_STOPBITS_1_5 USART_CR2_STOPBITS_1_5



#define USART_CR2_STOPBITS_1 (0x00 << 12)
#define USART_CR2_STOPBITS_0_5 (0x01 << 12)
#define USART_CR2_STOPBITS_2 (0x02 << 12)
#define USART_CR2_STOPBITS_1_5 (0x03 << 12)
#define USART_CR2_STOPBITS_MASK (0x03 << 12)
#define USART_CR2_STOPBITS_SHIFT 12
# 90 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
#define USART_FLOWCONTROL_NONE 0x00
#define USART_FLOWCONTROL_RTS USART_CR3_RTSE
#define USART_FLOWCONTROL_CTS USART_CR3_CTSE
#define USART_FLOWCONTROL_RTS_CTS (USART_CR3_RTSE | USART_CR3_CTSE)

#define USART_FLOWCONTROL_MASK (USART_CR3_RTSE | USART_CR3_CTSE)





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

# 125 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 3 4
_Bool 
# 125 "../libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
    usart_get_flag(uint32_t usart, uint32_t flag);


# 31 "../libopencm3/include/libopencm3/stm32/l0/usart.h" 2
# 1 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h" 1
# 26 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
       






#define USART_CR1(usart_base) MMIO32((usart_base) + 0x00)
#define USART1_CR1 USART_CR1(USART1_BASE)
#define USART2_CR1 USART_CR1(USART2_BASE)
#define USART3_CR1 USART_CR1(USART3_BASE)
# 48 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR2(usart_base) MMIO32((usart_base) + 0x04)
#define USART1_CR2 USART_CR2(USART1_BASE)
#define USART2_CR2 USART_CR2(USART2_BASE)
#define USART3_CR2 USART_CR2(USART3_BASE)
# 63 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR3(usart_base) MMIO32((usart_base) + 0x08)
#define USART1_CR3 USART_CR3(USART1_BASE)
#define USART2_CR3 USART_CR3(USART2_BASE)
#define USART3_CR3 USART_CR3(USART3_BASE)
# 78 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_BRR(usart_base) MMIO32((usart_base) + 0x0C)
#define USART1_BRR USART_BRR(USART1_BASE)
#define USART2_BRR USART_BRR(USART2_BASE)
#define USART3_BRR USART_BRR(USART3_BASE)
# 93 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_GTPR(usart_base) MMIO32((usart_base) + 0x10)
#define USART1_GTPR USART_GTPR(USART1_BASE)
#define USART2_GTPR USART_GTPR(USART2_BASE)
#define USART3_GTPR USART_GTPR(USART3_BASE)
# 108 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RTOR(usart_base) MMIO32((usart_base) + 0x14)
#define USART1_RTOR USART_RTOR(USART1_BASE)
#define USART2_RTOR USART_RTOR(USART2_BASE)
#define USART3_RTOR USART_RTOR(USART3_BASE)
# 123 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RQR(usart_base) MMIO32((usart_base) + 0x18)
#define USART1_RQR USART_RQR(USART1_BASE)
#define USART2_RQR USART_RQR(USART2_BASE)
#define USART3_RQR USART_RQR(USART3_BASE)
# 138 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ISR(usart_base) MMIO32((usart_base) + 0x1C)
#define USART1_ISR USART_ISR(USART1_BASE)
#define USART2_ISR USART_ISR(USART2_BASE)
#define USART3_ISR USART_ISR(USART3_BASE)
# 153 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ICR(usart_base) MMIO32((usart_base) + 0x20)
#define USART1_ICR USART_ICR(USART1_BASE)
#define USART2_ICR USART_ICR(USART2_BASE)
#define USART3_ICR USART_ICR(USART3_BASE)
# 168 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RDR(usart_base) MMIO32((usart_base) + 0x24)
#define USART1_RDR USART_RDR(USART1_BASE)
#define USART2_RDR USART_RDR(USART2_BASE)
#define USART3_RDR USART_RDR(USART3_BASE)
# 183 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_TDR(usart_base) MMIO32((usart_base) + 0x28)
#define USART1_TDR USART_TDR(USART1_BASE)
#define USART2_TDR USART_TDR(USART2_BASE)
#define USART3_TDR USART_TDR(USART3_BASE)
# 206 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_FLAG_PE USART_ISR_PE
#define USART_FLAG_FE USART_ISR_FE
#define USART_FLAG_NF USART_ISR_NF
#define USART_FLAG_ORE USART_ISR_ORE
#define USART_FLAG_IDLE USART_ISR_IDLE
#define USART_FLAG_RXNE USART_ISR_RXNE
#define USART_FLAG_TC USART_ISR_TC
#define USART_FLAG_TXE USART_ISR_TXE
# 226 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR1_M1 (1 << 28)


#define USART_CR1_EOBIE (1 << 27)


#define USART_CR1_RTOIE (1 << 26)

#define USART_CR1_DEAT_SHIFT 21
#define USART_CR1_DEAT (0x1F << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEAT_VAL(x) ((x) << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEDT_SHIFT 16
#define USART_CR1_DEDT (0x1F << USART_CR1_DEDT_SHIFT)

#define USART_CR1_DEDT_VAL(x) ((x) << USART_CR1_DEDT_SHIFT)


#define USART_CR1_OVER8 (1 << 15)


#define USART_CR1_CMIE (1 << 14)


#define USART_CR1_MME (1 << 13)


#define USART_CR1_M0 (1 << 12)

#define USART_CR1_M USART_CR1_M0


#define USART_CR1_WAKE (1 << 11)


#define USART_CR1_PCE (1 << 10)


#define USART_CR1_PS (1 << 9)


#define USART_CR1_PEIE (1 << 8)


#define USART_CR1_TXEIE (1 << 7)


#define USART_CR1_TCIE (1 << 6)


#define USART_CR1_RXNEIE (1 << 5)


#define USART_CR1_IDLEIE (1 << 4)


#define USART_CR1_TE (1 << 3)


#define USART_CR1_RE (1 << 2)


#define USART_CR1_UESM (1 << 1)


#define USART_CR1_UE (1 << 0)
# 301 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR2_ADD_SHIFT 24
#define USART_CR2_ADD (0xFF << USART_CR2_ADD_SHIFT)
#define USART_CR2_ADD_VAL(x) ((x) << USART_CR2_ADD_SHIFT)

#define USART_CR2_ABRMOD_MASK 3
#define USART_CR2_ABRMOD_SHIFT 21





#define USART_CR2_ABRMOD_STARTBIT (0x0 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FALL_EDGE (0x1 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x7F (0x2 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x55 (0x3 << USART_CR2_ABRMOD_SHIFT)



#define USART_CR2_RTOEN (1 << 23)


#define USART_CR2_ABREN (1 << 20)


#define USART_CR2_MSBFIRST (1 << 19)


#define USART_CR2_DATAINV (1 << 18)


#define USART_CR2_TXINV (1 << 17)


#define USART_CR2_RXINV (1 << 16)


#define USART_CR2_SWAP (1 << 15)


#define USART_CR2_LINEN (1 << 14)


#define USART_CR2_CLKEN (1 << 11)


#define USART_CR2_CPOL (1 << 10)


#define USART_CR2_CPHA (1 << 9)


#define USART_CR2_LBCL (1 << 8)


#define USART_CR2_LBDIE (1 << 6)


#define USART_CR2_LBDL (1 << 5)


#define USART_CR2_ADDM7 (1 << 4)
# 370 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR3_WUFIE (1 << 22)


#define USART_CR3_WUS_ADDRMATCH (0x0 << 20)
#define USART_CR3_WUS_START_BIT (0x2 << 20)
#define USART_CR3_WUS_RXNE (0x3 << 20)

#define USART_CR3_SCARCNT_SHIFT 17
#define USART_CR3_SCARCNT_MASK 0x7

#define USART_CR3_SCARCNT_DISABLE (0 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_VAL(x) ((x) << USART_CR3_SCARCNT_SHIFT)


#define USART_CR3_DEP (1 << 15)


#define USART_CR3_DEM (1 << 14)


#define USART_CR3_DDRE (1 << 13)


#define USART_CR3_OVRDIS (1 << 12)


#define USART_CR3_ONEBIT (1 << 11)


#define USART_CR3_CTSIE (1 << 10)


#define USART_CR3_CTSE (1 << 9)


#define USART_CR3_RTSE (1 << 8)


#define USART_CR3_DMAT (1 << 7)


#define USART_CR3_DMAR (1 << 6)


#define USART_CR3_SCEN (1 << 5)


#define USART_CR3_NACK (1 << 4)


#define USART_CR3_HDSEL (1 << 3)


#define USART_CR3_IRLP (1 << 2)


#define USART_CR3_IREN (1 << 1)


#define USART_CR3_EIE (1 << 0)







#define USART_GTPR_GT_SHIFT 8
#define USART_GTPR_GT (0xFF << USART_GTPR_GT_SHIFT)
#define USART_GTPR_GT_VAL(x) ((x) << USART_GTPR_GT_SHIFT)

#define USART_GTPR_PSC_SHIFT 0
#define USART_GTPR_PSC (0xFF << USART_GTPR_PSC_SHIFT)
#define USART_GTPR_PSC_VAL(x) ((x) << USART_GTPR_PSC_SHIFT)
# 452 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RTOR_BLEN_SHIFT 24
#define USART_RTOR_BLEN_MASK (0xFF << USART_RTOR_BLEN_SHIFT)
#define USART_RTOR_BLEN_VAL(x) ((x) << USART_RTOR_BLEN_SHIFT)


#define USART_RTOR_RTO_SHIFT 0
#define USART_RTOR_RTO_MASK (0xFFFFF << USART_RTOR_RTO_SHIFT)
#define USART_RTOR_RTO_VAL(x) ((x) << USART_RTOR_RTO_SHIFT)
# 469 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RQR_TXFRQ (1 << 4)


#define USART_RQR_RXFRQ (1 << 3)


#define USART_RQR_MMRQ (1 << 2)


#define USART_RQR_SBKRQ (1 << 1)


#define USART_RQR_ABKRQ (1 << 0)
# 492 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ISR_REACK (1 << 22)


#define USART_ISR_TEACK (1 << 21)


#define USART_ISR_WUF (1 << 20)


#define USART_ISR_RWU (1 << 19)


#define USART_ISR_SBKF (1 << 18)


#define USART_ISR_CMF (1 << 17)


#define USART_ISR_BUSY (1 << 16)


#define USART_ISR_ABRF (1 << 15)


#define USART_ISR_ABRE (1 << 14)


#define USART_ISR_EOBF (1 << 12)


#define USART_ISR_RTOF (1 << 11)


#define USART_ISR_CTS (1 << 10)


#define USART_ISR_CTSIF (1 << 9)


#define USART_ISR_LBDF (1 << 8)


#define USART_ISR_TXE (1 << 7)


#define USART_ISR_TC (1 << 6)


#define USART_ISR_RXNE (1 << 5)


#define USART_ISR_IDLE (1 << 4)


#define USART_ISR_ORE (1 << 3)


#define USART_ISR_NF (1 << 2)


#define USART_ISR_FE (1 << 1)


#define USART_ISR_PE (1 << 0)
# 566 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ICR_WUCF (1 << 20)


#define USART_ICR_CMCF (1 << 17)


#define USART_ICR_EOBCF (1 << 12)


#define USART_ICR_RTOCF (1 << 11)


#define USART_ICR_CTSCF (1 << 9)


#define USART_ICR_LBDCF (1 << 8)


#define USART_ICR_TCCF (1 << 6)


#define USART_ICR_IDLECF (1 << 4)


#define USART_ICR_ORECF (1 << 3)


#define USART_ICR_NCF (1 << 2)


#define USART_ICR_FECF (1 << 1)


#define USART_ICR_PECF (1 << 0)
# 608 "../libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RDR_MASK (0x1FF << 0)

#define USART_TDR_MASK (0x1FF << 0)







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


# 32 "../libopencm3/include/libopencm3/stm32/l0/usart.h" 2







#define USART1 USART1_BASE
#define USART2 USART2_BASE
#define USART4 USART4_BASE
#define USART5 USART5_BASE
#define LPUART1 LPUART1_BASE





# 37 "../libopencm3/include/libopencm3/stm32/usart.h" 2
# 8 "../coolease/include/coolease/board_defs.h" 2
# 147 "../coolease/include/coolease/board_defs.h"
#define MAX_SENSORS 50
typedef struct
{
 
# 150 "../coolease/include/coolease/board_defs.h" 3 4
_Bool 
# 150 "../coolease/include/coolease/board_defs.h"
       msg_pend;
 
# 151 "../coolease/include/coolease/board_defs.h" 3 4
_Bool 
# 151 "../coolease/include/coolease/board_defs.h"
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


#define FLASH_START 0x08000000
#define FLASH_END 0x08010000
#define FLASH_PAGE_SIZE 128
#define EEPROM_START 0x08080000
#define EEPROM_END 0x08080800


#define BATT_SENS_PORT GPIOA
#define BATT_SENS GPIO0



#define LED_PORT GPIOA
#define LED GPIO14


#define SPF_USART_BAUD 115200
#define SPF_USART USART2
#define SPF_USART_AF GPIO_AF4
#define SPF_USART_RCC RCC_USART2
#define SPF_USART_RCC_RST RST_USART2


#define SPF_USART_TX_PORT GPIOA
#define SPF_USART_TX GPIO2

#define SPF_USART_RX_PORT GPIOA
#define SPF_USART_RX GPIO3


#define RFM_SPI SPI1
#define RFM_SPI_AF GPIO_AF0
#define RFM_SPI_RCC RCC_SPI1
#define RFM_SPI_RST RST_SPI1



#define RFM_SPI SPI1
#define RFM_SPI_AF GPIO_AF0
#define RFM_SPI_RCC RCC_SPI1
#define RFM_SPI_RST RST_SPI1

#define RFM_SPI_NSS_PORT GPIOA
#define RFM_SPI_NSS GPIO4

#define RFM_SPI_SCK_PORT GPIOA
#define RFM_SPI_SCK GPIO5

#define RFM_SPI_MISO_PORT GPIOA
#define RFM_SPI_MISO GPIO6

#define RFM_SPI_MOSI_PORT GPIOA
#define RFM_SPI_MOSI GPIO7


#define RFM_RESET_PORT GPIOB
#define RFM_RESET GPIO0

#define RFM_IO_0_PORT GPIOB
#define RFM_IO_0 GPIO15
#define RFM_IO_0_EXTI EXTI15
#define RFM_IO_0_NVIC NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT GPIOB
#define RFM_IO_1 GPIO12

#define RFM_IO_2_PORT GPIOB
#define RFM_IO_2 GPIO11

#define RFM_IO_3_PORT GPIOB
#define RFM_IO_3 GPIO2

#define RFM_IO_4_PORT GPIOB
#define RFM_IO_4 GPIO10

#define RFM_IO_5_PORT GPIOB
#define RFM_IO_5 GPIO1




#define TEMP_I2C I2C2
#define TEMP_I2C_AF GPIO_AF5
#define TEMP_I2C_RCC RCC_I2C2
#define TEMP_I2C_RCC_RST RST_I2C2

#define TEMP_I2C_SCL_PORT GPIOB
#define TEMP_I2C_SCL GPIO13

#define TEMP_I2C_SDA_PORT GPIOB
#define TEMP_I2C_SDA GPIO14



void gpio_init(void);
# 15 "lib//battery.c" 2
# 1 "../coolease/include/coolease/timers.h" 1

#define TIMERS_H 





#define WAIT_US(cond,timeout) { uint16_t start_time = timers_micros(); while(cond){ if((uint16_t)( timers_micros() - start_time ) > timeout){ return false; }}}



#define WAIT_MS(cond,timeout) { uint32_t time = 0; uint16_t curr_time = timers_micros(); while(cond){ time += (uint16_t)(timers_micros() - curr_time); curr_time = timers_micros(); if(time > timeout * 1000){ return false;}}}







#define TIMEOUT(time,print_str,print_data,break_condition,if_code,else_code) timeout_init(); while(!timeout(time, print_str, print_data)) { if(break_condition){ if_code break; } else{ else_code }}





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

# 61 "../coolease/include/coolease/timers.h" 3 4
_Bool 
# 61 "../coolease/include/coolease/timers.h"
    timeout(uint32_t time_microseconds, char *msg, uint32_t data);

void set_gpio_for_standby(void);
# 16 "lib//battery.c" 2

uint16_t batt_voltages[1];

# 18 "lib//battery.c" 3 4
_Bool 
# 18 "lib//battery.c"
           batt_rst_seq = 
# 18 "lib//battery.c" 3 4
                          0
# 18 "lib//battery.c"
                               ;

static uint16_t adc_vals[3] = {0,0,0};
static 
# 21 "lib//battery.c" 3 4
      _Bool 
# 21 "lib//battery.c"
               plugged_in = 
# 21 "lib//battery.c" 3 4
                             1
# 21 "lib//battery.c"
                                 ;


void batt_init(void)
{
    rcc_periph_clock_enable(RCC_PWR);
    rcc_periph_clock_enable(RCC_SYSCFG);


    while(!( (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x7000) + 0x04)) & (1 << 3) ));



}

void batt_set_voltage_scale(uint8_t scale)
{
    rcc_periph_clock_enable(RCC_PWR);


    while((*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x7000) + 0x04)) & (1 << 4));


    pwr_set_vos_scale(scale);


    while((*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x7000) + 0x04)) & (1 << 4));
}

void batt_set_low_power_run(void)
{
    rcc_periph_clock_enable(RCC_PWR);


 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x7000) + 0x00)) |= (1 << 0);
 (*(volatile uint32_t *)((((0x40000000U) + 0x00000) + 0x7000) + 0x00)) |= (1 << 14);


 rcc_osc_on(RCC_MSI);
 rcc_wait_for_osc_ready(RCC_MSI);


 rcc_set_msi_range(0);


 rcc_set_hpre(0x0);
 rcc_set_ppre1(0x0);
 rcc_set_ppre2(0x0);


 flash_set_ws(0x00);


 rcc_ahb_frequency = 65536;
 rcc_apb1_frequency = 65536;
 rcc_apb2_frequency = 65536;

    rcc_periph_clock_disable(RCC_PWR);
}

void batt_update_voltages(void)
{

    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x10)) |= (3 << 30);

    adc_power_off((((0x40000000U) + 0x10000) + 0x2400));
    adc_calibrate((((0x40000000U) + 0x10000) + 0x2400));


    adc_set_single_conversion_mode((((0x40000000U) + 0x10000) + 0x2400));
    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x14)) &= ~7; (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x14)) |= 0x7;


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x0C)) |= (1 << 2);


    adc_enable_vrefint();


    adc_power_on((((0x40000000U) + 0x10000) + 0x2400));
    timers_delay_microseconds(1000);


    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(((0x50000000U) + 0x00000), 0x3, 0x0, (1 << 0));


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x28)) |= (1 << 17);
    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x28)) |= (1 << 0);







    nvic_enable_irq(12);
    nvic_set_priority(12, 0);


    adc_start_conversion_regular((((0x40000000U) + 0x10000) + 0x2400));
    for(uint8_t i = 0; i < 1 + 1; i++)
    {
        while ( !adc_eoc((((0x40000000U) + 0x10000) + 0x2400)) );
        adc_vals[i] = adc_read_regular((((0x40000000U) + 0x10000) + 0x2400));
    }


    for(uint8_t i = 0; i < 1; i++)
    {
        batt_voltages[i] = ( (uint32_t)300 * (*(volatile uint16_t *)(((0x1ff80000U) + 0x78))) * adc_vals[i + 1] ) / ( adc_vals[0] * 4095 );
    }
# 148 "lib//battery.c"
    adc_disable_vrefint();
    adc_power_off((((0x40000000U) + 0x10000) + 0x2400));
    rcc_periph_clock_disable(RCC_ADC1);
}

void batt_enable_interrupt(void)
{

    rcc_periph_clock_enable(RCC_ADC1);
    rcc_periph_reset_pulse(RST_ADC1);


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x10)) |= (2 << 30);


    adc_power_off((((0x40000000U) + 0x10000) + 0x2400));
    adc_calibrate((((0x40000000U) + 0x10000) + 0x2400));


    adc_set_single_conversion_mode((((0x40000000U) + 0x10000) + 0x2400));
    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x14)) &= ~7; (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x14)) |= 0x7;
    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x04)) = (1 << 3);
    adc_enable_dma((((0x40000000U) + 0x10000) + 0x2400));


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x0C)) |= (1 << 2);


    adc_enable_vrefint();
# 190 "lib//battery.c"
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(((0x50000000U) + 0x00000), 0x3, 0x0, (1 << 0));


    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x28)) |= (1 << 17);
    (*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x28)) |= (1 << 0);
# 204 "lib//battery.c"
    rcc_periph_clock_enable(RCC_DMA);
    dma_channel_reset((((0x40000000U) + 0x20000) + 0x00000), 1);

    dma_enable_circular_mode((((0x40000000U) + 0x20000) + 0x00000), 1);
    dma_set_read_from_peripheral((((0x40000000U) + 0x20000) + 0x00000), 1);
    dma_set_number_of_data((((0x40000000U) + 0x20000) + 0x00000), 1, 3);
    dma_set_priority((((0x40000000U) + 0x20000) + 0x00000), 1, (0x3 << 12));

    dma_set_peripheral_address((((0x40000000U) + 0x20000) + 0x00000), 1, (uint32_t)&(*(volatile uint32_t *)(((((0x40000000U) + 0x10000) + 0x2400)) + 0x40)));
    dma_set_peripheral_size((((0x40000000U) + 0x20000) + 0x00000), 1, (0x2 << 8));
    dma_disable_peripheral_increment_mode((((0x40000000U) + 0x20000) + 0x00000), 1);

    dma_set_memory_address((((0x40000000U) + 0x20000) + 0x00000), 1, (uint32_t)adc_vals);
    dma_set_memory_size((((0x40000000U) + 0x20000) + 0x00000), 1, (0x1 << 10));
    dma_enable_memory_increment_mode((((0x40000000U) + 0x20000) + 0x00000), 1);

    dma_enable_channel((((0x40000000U) + 0x20000) + 0x00000), 1);


    adc_power_on((((0x40000000U) + 0x10000) + 0x2400));
    timers_delay_microseconds(1000);


    nvic_enable_irq(12);
    nvic_set_priority(12, 0xFF);


    adc_start_conversion_regular((((0x40000000U) + 0x10000) + 0x2400));
}

void batt_enable_comp(void)
{





    rcc_periph_clock_enable(RCC_SYSCFG);




    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(((0x50000000U) + 0x00000), 0x3, 0x0, (1 << 0));






    (*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x18)) = 0x00000000;
    (*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x18)) = 0x00000010;
    (*(volatile uint32_t *)((((0x40000000U) + 0x10000) + 0x0000) + 0x18)) = 0x00000011;


    exti_reset_request((1 << 21));
 exti_set_trigger((1 << 21), EXTI_TRIGGER_BOTH);
 exti_enable_request((1 << 21));

    nvic_enable_irq(12);
    nvic_set_priority(12, 0);
}
