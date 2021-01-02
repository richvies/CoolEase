# 1 "hub/src/sim.c"
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
# 1 "hub/src/sim.c"
# 1 "hub/include/hub/sim.h" 1

#define SIM_H 

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








# 41 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_default_types.h" 3 4
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
# 5 "hub/include/hub/sim.h" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 29 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 6 "hub/include/hub/sim.h" 2



# 8 "hub/include/hub/sim.h"
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
# 2 "hub/src/sim.c" 2

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 1 3







#define _STRING_H_ 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 1 3







#define __NEWLIB_H__ 1
# 18 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 3
#define _WANT_IO_C99_FORMATS 1


#define _WANT_IO_LONG_LONG 1


#define _WANT_REGISTER_FINI 1
# 37 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 3
#define _REENT_CHECK_VERIFY 1





#define _MB_LEN_MAX 1
# 53 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 3
#define HAVE_INITFINI_ARRAY 1



#define _ATEXIT_DYNAMIC_ALLOC 1


#define _HAVE_LONG_DOUBLE 1


#define _HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1


#define _LDBL_EQ_DBL 1


#define _FVWRITE_IN_STREAMIO 1


#define _FSEEK_OPTIMIZATION 1


#define _WIDE_ORIENT 1


#define _UNBUF_STREAM_OPT 1
# 95 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/newlib.h" 3
#define _RETARGETABLE_LOCKING 1
# 11 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 1 3

#define __SYS_CONFIG_H__ 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 77 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/ieeefp.h" 3
#define __IEEE_LITTLE_ENDIAN 
# 473 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/ieeefp.h" 3
#define __OBSOLETE_MATH_DEFAULT 1


#define __OBSOLETE_MATH __OBSOLETE_MATH_DEFAULT
# 5 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 2 3
# 224 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 3
#define _POINTER_INT long





#undef __RAND_MAX



#define __RAND_MAX 0x7fffffff
# 250 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/config.h" 3
#define __EXPORT 



#define __IMPORT 






#define _READ_WRITE_RETURN_TYPE int





#define _READ_WRITE_BUFSIZE_TYPE int
# 12 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 2 3
# 31 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 3
#define _BEGIN_STD_C 
#define _END_STD_C 
#define _NOTHROW 



#define _LONG_DOUBLE long double





#define _ATTRIBUTE(attrs) __attribute__ (attrs)
# 69 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 3
#define _ELIDABLE_INLINE static __inline__



#define _NOINLINE __attribute__ ((__noinline__))
#define _NOINLINE_STATIC _NOINLINE static
# 11 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 1 3
# 11 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _SYS_REENT_H_ 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/_ansi.h" 1 3
# 14 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3
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
# 15 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 1 3
# 20 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
#define _SYS__TYPES_H 

#define __need_size_t 
#define __need_wint_t 
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 155 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_wchar_t




#define _WINT_T 




typedef unsigned int wint_t;

#undef __need_wint_t
# 390 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 25 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 2 3


# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/machine/_types.h" 1 3





#define _MACHINE__TYPES_H 
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
# 127 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
#undef __size_t



typedef unsigned int __size_t;
# 146 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/_types.h" 3
#define unsigned signed
typedef signed int _ssize_t;
#undef unsigned
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



#define _CLOCK_T_ unsigned long


typedef unsigned long __clock_t;




#define _TIME_T_ __int_least64_t

typedef __int_least64_t __time_t;


#define _CLOCKID_T_ unsigned long


typedef unsigned long __clockid_t;

#define _TIMER_T_ unsigned long
typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 2 3

#define _NULL 0



#define __Long long
typedef unsigned long __ULong;
# 34 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/lock.h" 1 3

#define __SYS_LOCK_H__ 
# 33 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/lock.h" 3
struct __lock;
typedef struct __lock * _LOCK_T;
#define _LOCK_RECURSIVE_T _LOCK_T

#define __LOCK_INIT(class,lock) extern struct __lock __lock_ ## lock; class _LOCK_T lock = &__lock_ ## lock

#define __LOCK_INIT_RECURSIVE(class,lock) __LOCK_INIT(class,lock)

extern void __retarget_lock_init(_LOCK_T *lock);
#define __lock_init(lock) __retarget_lock_init(&lock)
extern void __retarget_lock_init_recursive(_LOCK_T *lock);
#define __lock_init_recursive(lock) __retarget_lock_init_recursive(&lock)
extern void __retarget_lock_close(_LOCK_T lock);
#define __lock_close(lock) __retarget_lock_close(lock)
extern void __retarget_lock_close_recursive(_LOCK_T lock);
#define __lock_close_recursive(lock) __retarget_lock_close_recursive(lock)
extern void __retarget_lock_acquire(_LOCK_T lock);
#define __lock_acquire(lock) __retarget_lock_acquire(lock)
extern void __retarget_lock_acquire_recursive(_LOCK_T lock);
#define __lock_acquire_recursive(lock) __retarget_lock_acquire_recursive(lock)
extern int __retarget_lock_try_acquire(_LOCK_T lock);
#define __lock_try_acquire(lock) __retarget_lock_try_acquire(lock)
extern int __retarget_lock_try_acquire_recursive(_LOCK_T lock);
#define __lock_try_acquire_recursive(lock) __retarget_lock_try_acquire_recursive(lock)

extern void __retarget_lock_release(_LOCK_T lock);
#define __lock_release(lock) __retarget_lock_release(lock)
extern void __retarget_lock_release_recursive(_LOCK_T lock);
#define __lock_release_recursive(lock) __retarget_lock_release_recursive(lock)
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





#define _ATEXIT_SIZE 32

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
#define _ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL}, 0, 0}}





#define _REENT_INIT_ATEXIT _NULL, _ATEXIT_INIT,
# 122 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 183 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_SMALL_CHECK_INIT(ptr) 


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
# 317 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _RAND48_SEED_0 (0x330e)
#define _RAND48_SEED_1 (0xabcd)
#define _RAND48_SEED_2 (0x1234)
#define _RAND48_MULT_0 (0xe66d)
#define _RAND48_MULT_1 (0xdeec)
#define _RAND48_MULT_2 (0x0005)
#define _RAND48_ADD (0x000b)
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};


#define _REENT_EMERGENCY_SIZE 25
#define _REENT_ASCTIME_SIZE 26
#define _REENT_SIGNAL_SIZE 24
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
#define _N_LISTS 30
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





#define _REENT_STDIO_STREAM(var,index) &(var)->__sf[index]


#define _REENT_INIT(var) { 0, _REENT_STDIO_STREAM(&(var), 0), _REENT_STDIO_STREAM(&(var), 1), _REENT_STDIO_STREAM(&(var), 2), 0, "", 0, _NULL, 0, _NULL, _NULL, 0, _NULL, _NULL, 0, _NULL, { { 0, _NULL, "", {0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 1, { {_RAND48_SEED_0, _RAND48_SEED_1, _RAND48_SEED_2}, {_RAND48_MULT_0, _RAND48_MULT_1, _RAND48_MULT_2}, _RAND48_ADD }, {0, {0}}, {0, {0}}, {0, {0}}, "", "", 0, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}} } }, _REENT_INIT_ATEXIT _NULL, {_NULL, 0, _NULL} }
# 751 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_INIT_PTR_ZEROED(var) { (var)->_stdin = _REENT_STDIO_STREAM(var, 0); (var)->_stdout = _REENT_STDIO_STREAM(var, 1); (var)->_stderr = _REENT_STDIO_STREAM(var, 2); (var)->_new._reent._rand_next = 1; (var)->_new._reent._r48._seed[0] = _RAND48_SEED_0; (var)->_new._reent._r48._seed[1] = _RAND48_SEED_1; (var)->_new._reent._r48._seed[2] = _RAND48_SEED_2; (var)->_new._reent._r48._mult[0] = _RAND48_MULT_0; (var)->_new._reent._r48._mult[1] = _RAND48_MULT_1; (var)->_new._reent._r48._mult[2] = _RAND48_MULT_2; (var)->_new._reent._r48._add = _RAND48_ADD; }
# 765 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_CHECK_RAND48(ptr) 
#define _REENT_CHECK_MP(ptr) 
#define _REENT_CHECK_TM(ptr) 
#define _REENT_CHECK_ASCTIME_BUF(ptr) 
#define _REENT_CHECK_EMERGENCY(ptr) 
#define _REENT_CHECK_MISC(ptr) 
#define _REENT_CHECK_SIGNAL_BUF(ptr) 

#define _REENT_SIGNGAM(ptr) ((ptr)->_new._reent._gamma_signgam)
#define _REENT_RAND_NEXT(ptr) ((ptr)->_new._reent._rand_next)
#define _REENT_RAND48_SEED(ptr) ((ptr)->_new._reent._r48._seed)
#define _REENT_RAND48_MULT(ptr) ((ptr)->_new._reent._r48._mult)
#define _REENT_RAND48_ADD(ptr) ((ptr)->_new._reent._r48._add)
#define _REENT_MP_RESULT(ptr) ((ptr)->_result)
#define _REENT_MP_RESULT_K(ptr) ((ptr)->_result_k)
#define _REENT_MP_P5S(ptr) ((ptr)->_p5s)
#define _REENT_MP_FREELIST(ptr) ((ptr)->_freelist)
#define _REENT_ASCTIME_BUF(ptr) ((ptr)->_new._reent._asctime_buf)
#define _REENT_TM(ptr) (&(ptr)->_new._reent._localtime_buf)
#define _REENT_EMERGENCY(ptr) ((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr) ((ptr)->_new._reent._strtok_last)
#define _REENT_MBLEN_STATE(ptr) ((ptr)->_new._reent._mblen_state)
#define _REENT_MBTOWC_STATE(ptr) ((ptr)->_new._reent._mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr) ((ptr)->_new._reent._wctomb_state)
#define _REENT_MBRLEN_STATE(ptr) ((ptr)->_new._reent._mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr) ((ptr)->_new._reent._mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_new._reent._mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr) ((ptr)->_new._reent._wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_new._reent._wcsrtombs_state)
#define _REENT_L64A_BUF(ptr) ((ptr)->_new._reent._l64a_buf)
#define _REENT_SIGNAL_BUF(ptr) ((ptr)->_new._reent._signal_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._getdate_err))



#define _REENT_INIT_PTR(var) { memset((var), 0, sizeof(*(var))); _REENT_INIT_PTR_ZEROED(var); }







#define _Kmax (sizeof (size_t) << 3)







#define __ATTRIBUTE_IMPURE_PTR__ 


extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 832 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/reent.h" 3
#define _REENT _impure_ptr


#define _GLOBAL_REENT _global_impure_ptr





#define _GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)
# 12 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 1 3
# 43 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define _SYS_CDEFS_H_ 



# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 48 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 2 3

#define __PMT(args) args
#define __DOTS , ...
#define __THROW 


#define __ASMNAME(cname) __XSTRING (__USER_LABEL_PREFIX__) cname


#define __ptr_t void *
#define __long_double_t long double

#define __attribute_malloc__ 
#define __attribute_pure__ 
#define __attribute_format_strfmon__(a,b) 
#define __flexarr [0]


#define __bounded 
#define __unbounded 
#define __ptrvalue 
# 78 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __has_extension __has_feature


#define __has_feature(x) 0





#define __has_builtin(x) 0






#define __BEGIN_DECLS 
#define __END_DECLS 
# 107 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __GNUCLIKE_ASM 3
#define __GNUCLIKE_MATH_BUILTIN_CONSTANTS 



#define __GNUCLIKE___TYPEOF 1
#define __GNUCLIKE___OFFSETOF 1
#define __GNUCLIKE___SECTION 1


#define __GNUCLIKE_CTOR_SECTION_HANDLING 1


#define __GNUCLIKE_BUILTIN_CONSTANT_P 1






#define __GNUCLIKE_BUILTIN_VARARGS 1
#define __GNUCLIKE_BUILTIN_STDARG 1
#define __GNUCLIKE_BUILTIN_VAALIST 1



#define __GNUC_VA_LIST_COMPATIBILITY 1






#define __compiler_membar() __asm __volatile(" " : : : "memory")



#define __GNUCLIKE_BUILTIN_NEXT_ARG 1
#define __GNUCLIKE_MATH_BUILTIN_RELOPS 


#define __GNUCLIKE_BUILTIN_MEMCPY 1


#define __CC_SUPPORTS_INLINE 1
#define __CC_SUPPORTS___INLINE 1
#define __CC_SUPPORTS___INLINE__ 1

#define __CC_SUPPORTS___FUNC__ 1
#define __CC_SUPPORTS_WARNING 1

#define __CC_SUPPORTS_VARADIC_XXX 1

#define __CC_SUPPORTS_DYNAMIC_ARRAY_INIT 1
# 177 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __P(protos) protos
#define __CONCAT1(x,y) x ## y
#define __CONCAT(x,y) __CONCAT1(x,y)
#define __STRING(x) #x
#define __XSTRING(x) __STRING(x)

#define __const const
#define __signed signed
#define __volatile volatile
# 230 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __weak_symbol __attribute__((__weak__))
# 243 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __dead2 __attribute__((__noreturn__))
#define __pure2 __attribute__((__const__))
#define __unused __attribute__((__unused__))
#define __used __attribute__((__used__))
#define __packed __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __section(x) __attribute__((__section__(x)))


#define __alloc_size(x) __attribute__((__alloc_size__(x)))
#define __alloc_size2(n,x) __attribute__((__alloc_size__(n, x)))





#define __alloc_align(x) __attribute__((__alloc_align__(x)))
# 280 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define _Alignas(x) __aligned(x)






#define _Alignof(x) __alignof(x)
# 296 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define _Atomic(T) struct { T volatile __val; }





#define _Noreturn __dead2
# 331 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define _Thread_local __thread
# 351 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __generic(expr,t,yes,no) __builtin_choose_expr( __builtin_types_compatible_p(__typeof(expr), t), yes, no)
# 366 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __min_size(x) static (x)





#define __malloc_like __attribute__((__malloc__))
#define __pure __attribute__((__pure__))






#define __always_inline __inline__ __attribute__((__always_inline__))





#define __noinline __attribute__ ((__noinline__))





#define __nonnull(x) __attribute__((__nonnull__ x))
#define __nonnull_all __attribute__((__nonnull__))






#define __fastcall __attribute__((__fastcall__))
#define __result_use_check __attribute__((__warn_unused_result__))






#define __returns_twice __attribute__((__returns_twice__))





#define __unreachable() __builtin_unreachable()
# 434 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __restrict restrict
# 467 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __predict_true(exp) __builtin_expect((exp), 1)
#define __predict_false(exp) __builtin_expect((exp), 0)






#define __null_sentinel __attribute__((__sentinel__))
#define __exported __attribute__((__visibility__("default")))


#define __hidden __attribute__((__visibility__("hidden")))
# 489 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __offsetof(type,field) offsetof(type, field)
#define __rangeof(type,start,end) (__offsetof(type, end) - __offsetof(type, start))
# 500 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __containerof(x,s,m) ({ const volatile __typeof(((s *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volatile char *)__x - __offsetof(s, m));})
# 522 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))

#define __format_arg(fmtarg) __attribute__((__format_arg__ (fmtarg)))
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))

#define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
# 539 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __printf0like(fmtarg,firstvararg) 




#define __strong_reference(sym,aliassym) extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))




#define __weak_reference(sym,alias) __asm__(".weak " #alias); __asm__(".equ " #alias ", " #sym)


#define __warn_references(sym,msg) __asm__(".section .gnu.warning." #sym); __asm__(".asciz \"" msg "\""); __asm__(".previous")



#define __sym_compat(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@" #verid)

#define __sym_default(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@@" #verid)
# 593 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __FBSDID(s) struct __hack



#define __RCSID(s) struct __hack



#define __RCSID_SOURCE(s) struct __hack



#define __SCCSID(s) struct __hack



#define __COPYRIGHT(s) struct __hack



#define __DECONST(type,var) ((type)(__uintptr_t)(const void *)(var))



#define __DEVOLATILE(type,var) ((type)(__uintptr_t)(volatile void *)(var))



#define __DEQUALIFY(type,var) ((type)(__uintptr_t)(const volatile void *)(var))






#define _Nonnull 
#define _Nullable 
#define _Null_unspecified 
#define __NULLABILITY_PRAGMA_PUSH 
#define __NULLABILITY_PRAGMA_POP 
# 653 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __arg_type_tag(arg_kind,arg_idx,type_tag_idx) 
#define __datatype_type_tag(kind,type) 
# 672 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/sys/cdefs.h" 3
#define __lock_annotate(x) 





#define __lockable __lock_annotate(lockable)


#define __locks_exclusive(...) __lock_annotate(exclusive_lock_function(__VA_ARGS__))

#define __locks_shared(...) __lock_annotate(shared_lock_function(__VA_ARGS__))



#define __trylocks_exclusive(...) __lock_annotate(exclusive_trylock_function(__VA_ARGS__))

#define __trylocks_shared(...) __lock_annotate(shared_trylock_function(__VA_ARGS__))



#define __unlocks(...) __lock_annotate(unlock_function(__VA_ARGS__))


#define __asserts_exclusive(...) __lock_annotate(assert_exclusive_lock(__VA_ARGS__))

#define __asserts_shared(...) __lock_annotate(assert_shared_lock(__VA_ARGS__))



#define __requires_exclusive(...) __lock_annotate(exclusive_locks_required(__VA_ARGS__))

#define __requires_shared(...) __lock_annotate(shared_locks_required(__VA_ARGS__))

#define __requires_unlocked(...) __lock_annotate(locks_excluded(__VA_ARGS__))



#define __no_lock_analysis __lock_annotate(no_thread_safety_analysis)


#define __guarded_by(x) __lock_annotate(guarded_by(x))
#define __pt_guarded_by(x) __lock_annotate(pt_guarded_by(x))
# 13 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/arm-none-eabi/include/string.h" 2 3


#define __need_size_t 
#define __need_NULL 
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 155 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
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


# 4 "hub/src/sim.c" 2


# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 20 "libopencm3/include/libopencm3/stm32/rcc.h"
# 1 "libopencm3/include/libopencm3/cm3/common.h" 1
# 21 "libopencm3/include/libopencm3/cm3/common.h"
#define LIBOPENCM3_CM3_COMMON_H 
# 33 "libopencm3/include/libopencm3/cm3/common.h"
#define BEGIN_DECLS 
#define END_DECLS 






#define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))
# 67 "libopencm3/include/libopencm3/cm3/common.h"
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
# 21 "libopencm3/include/libopencm3/stm32/rcc.h" 2
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
# 22 "libopencm3/include/libopencm3/stm32/rcc.h" 2
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
# 7 "hub/src/sim.c" 2
# 1 "libopencm3/include/libopencm3/stm32/gpio.h" 1
# 36 "libopencm3/include/libopencm3/stm32/gpio.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/gpio.h" 1
# 32 "libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define LIBOPENCM3_GPIO_H 

# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 1
# 37 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h"
#define LIBOPENCM3_GPIO_COMMON_F24_H 



# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 1
# 37 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
#define LIBOPENCM3_GPIO_COMMON_F234_H 



# 1 "libopencm3/include/libopencm3/stm32/common/gpio_common_all.h" 1
# 37 "libopencm3/include/libopencm3/stm32/common/gpio_common_all.h"
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


# 42 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h" 2






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
# 168 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
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
# 213 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
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







# 258 "libopencm3/include/libopencm3/stm32/common/gpio_common_f234.h"
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
       uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
        uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);


# 42 "libopencm3/include/libopencm3/stm32/common/gpio_common_f24.h" 2






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
# 35 "libopencm3/include/libopencm3/stm32/l0/gpio.h" 2
# 44 "libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define GPIO_BRR(port) MMIO32((port) + 0x28)
#define GPIOA_BRR GPIO_BRR(GPIOA)
#define GPIOB_BRR GPIO_BRR(GPIOB)
#define GPIOC_BRR GPIO_BRR(GPIOC)
#define GPIOD_BRR GPIO_BRR(GPIOD)
#define GPIOH_BRR GPIO_BRR(GPIOH)
# 58 "libopencm3/include/libopencm3/stm32/l0/gpio.h"
#define GPIO_OSPEED_LOW 0x0
#define GPIO_OSPEED_MED 0x1
#define GPIO_OSPEED_HIGH 0x2
#define GPIO_OSPEED_VERYHIGH 0x3
# 72 "libopencm3/include/libopencm3/stm32/l0/gpio.h"



# 37 "libopencm3/include/libopencm3/stm32/gpio.h" 2
# 8 "hub/src/sim.c" 2
# 1 "libopencm3/include/libopencm3/stm32/usart.h" 1
# 36 "libopencm3/include/libopencm3/stm32/usart.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/usart.h" 1
# 28 "libopencm3/include/libopencm3/stm32/l0/usart.h"
#define LIBOPENCM3_USART_H 

# 1 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 1
# 35 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
#define LIBOPENCM3_USART_COMMON_ALL_H 
# 46 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
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
# 90 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
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

# 125 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h" 3 4
_Bool 
# 125 "libopencm3/include/libopencm3/stm32/common/usart_common_all.h"
    usart_get_flag(uint32_t usart, uint32_t flag);


# 31 "libopencm3/include/libopencm3/stm32/l0/usart.h" 2
# 1 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h" 1
# 26 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
       






#define USART_CR1(usart_base) MMIO32((usart_base) + 0x00)
#define USART1_CR1 USART_CR1(USART1_BASE)
#define USART2_CR1 USART_CR1(USART2_BASE)
#define USART3_CR1 USART_CR1(USART3_BASE)
# 48 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR2(usart_base) MMIO32((usart_base) + 0x04)
#define USART1_CR2 USART_CR2(USART1_BASE)
#define USART2_CR2 USART_CR2(USART2_BASE)
#define USART3_CR2 USART_CR2(USART3_BASE)
# 63 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_CR3(usart_base) MMIO32((usart_base) + 0x08)
#define USART1_CR3 USART_CR3(USART1_BASE)
#define USART2_CR3 USART_CR3(USART2_BASE)
#define USART3_CR3 USART_CR3(USART3_BASE)
# 78 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_BRR(usart_base) MMIO32((usart_base) + 0x0C)
#define USART1_BRR USART_BRR(USART1_BASE)
#define USART2_BRR USART_BRR(USART2_BASE)
#define USART3_BRR USART_BRR(USART3_BASE)
# 93 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_GTPR(usart_base) MMIO32((usart_base) + 0x10)
#define USART1_GTPR USART_GTPR(USART1_BASE)
#define USART2_GTPR USART_GTPR(USART2_BASE)
#define USART3_GTPR USART_GTPR(USART3_BASE)
# 108 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RTOR(usart_base) MMIO32((usart_base) + 0x14)
#define USART1_RTOR USART_RTOR(USART1_BASE)
#define USART2_RTOR USART_RTOR(USART2_BASE)
#define USART3_RTOR USART_RTOR(USART3_BASE)
# 123 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RQR(usart_base) MMIO32((usart_base) + 0x18)
#define USART1_RQR USART_RQR(USART1_BASE)
#define USART2_RQR USART_RQR(USART2_BASE)
#define USART3_RQR USART_RQR(USART3_BASE)
# 138 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ISR(usart_base) MMIO32((usart_base) + 0x1C)
#define USART1_ISR USART_ISR(USART1_BASE)
#define USART2_ISR USART_ISR(USART2_BASE)
#define USART3_ISR USART_ISR(USART3_BASE)
# 153 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_ICR(usart_base) MMIO32((usart_base) + 0x20)
#define USART1_ICR USART_ICR(USART1_BASE)
#define USART2_ICR USART_ICR(USART2_BASE)
#define USART3_ICR USART_ICR(USART3_BASE)
# 168 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RDR(usart_base) MMIO32((usart_base) + 0x24)
#define USART1_RDR USART_RDR(USART1_BASE)
#define USART2_RDR USART_RDR(USART2_BASE)
#define USART3_RDR USART_RDR(USART3_BASE)
# 183 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_TDR(usart_base) MMIO32((usart_base) + 0x28)
#define USART1_TDR USART_TDR(USART1_BASE)
#define USART2_TDR USART_TDR(USART2_BASE)
#define USART3_TDR USART_TDR(USART3_BASE)
# 206 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_FLAG_PE USART_ISR_PE
#define USART_FLAG_FE USART_ISR_FE
#define USART_FLAG_NF USART_ISR_NF
#define USART_FLAG_ORE USART_ISR_ORE
#define USART_FLAG_IDLE USART_ISR_IDLE
#define USART_FLAG_RXNE USART_ISR_RXNE
#define USART_FLAG_TC USART_ISR_TC
#define USART_FLAG_TXE USART_ISR_TXE
# 226 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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
# 301 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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
# 370 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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
# 452 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RTOR_BLEN_SHIFT 24
#define USART_RTOR_BLEN_MASK (0xFF << USART_RTOR_BLEN_SHIFT)
#define USART_RTOR_BLEN_VAL(x) ((x) << USART_RTOR_BLEN_SHIFT)


#define USART_RTOR_RTO_SHIFT 0
#define USART_RTOR_RTO_MASK (0xFFFFF << USART_RTOR_RTO_SHIFT)
#define USART_RTOR_RTO_VAL(x) ((x) << USART_RTOR_RTO_SHIFT)
# 469 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
#define USART_RQR_TXFRQ (1 << 4)


#define USART_RQR_RXFRQ (1 << 3)


#define USART_RQR_MMRQ (1 << 2)


#define USART_RQR_SBKRQ (1 << 1)


#define USART_RQR_ABKRQ (1 << 0)
# 492 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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
# 566 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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
# 608 "libopencm3/include/libopencm3/stm32/common/usart_common_v2.h"
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


# 32 "libopencm3/include/libopencm3/stm32/l0/usart.h" 2







#define USART1 USART1_BASE
#define USART2 USART2_BASE
#define USART4 USART4_BASE
#define USART5 USART5_BASE
#define LPUART1 LPUART1_BASE





# 37 "libopencm3/include/libopencm3/stm32/usart.h" 2
# 9 "hub/src/sim.c" 2
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
# 10 "hub/src/sim.c" 2
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

# 11 "hub/src/sim.c" 2

# 1 "common/include/common/board_defs.h" 1

#define BOARD_DEFS_H 

# 1 "libopencm3/include/libopencm3/stm32/gpio.h" 1
# 5 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/rcc.h" 1
# 6 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/spi.h" 1
# 36 "libopencm3/include/libopencm3/stm32/spi.h"
# 1 "libopencm3/include/libopencm3/stm32/l0/spi.h" 1
# 32 "libopencm3/include/libopencm3/stm32/l0/spi.h"
#define LIBOPENCM3_SPI_H 

# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 1
# 32 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h"
       



# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 1
# 32 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"
       



# 1 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h" 1
# 33 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
#define LIBOPENCM3_SPI_COMMON_ALL_H 
# 46 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
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
# 292 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
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
# 335 "libopencm3/include/libopencm3/stm32/common/spi_common_all.h"
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


# 37 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h" 2
# 45 "libopencm3/include/libopencm3/stm32/common/spi_common_v1.h"
#define SPI_CR1_DFF_8BIT (0 << 11)
#define SPI_CR1_DFF_16BIT (1 << 11)



#define SPI_CR1_DFF (1 << 11)





int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
  uint32_t dff, uint32_t lsbfirst);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);


# 37 "libopencm3/include/libopencm3/stm32/common/spi_common_v1_frf.h" 2





#define SPI_CR2_FRF (1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE (0 << 4)
#define SPI_CR2_FRF_TI_MODE (1 << 4)




#define SPI_SR_TIFRFE (1 << 8)
#define SPI_SR_FRE (1 << 8)





void spi_set_frf_ti(uint32_t spi);
void spi_set_frf_motorola(uint32_t spi);


# 35 "libopencm3/include/libopencm3/stm32/l0/spi.h" 2
# 37 "libopencm3/include/libopencm3/stm32/spi.h" 2
# 7 "common/include/common/board_defs.h" 2
# 1 "libopencm3/include/libopencm3/stm32/usart.h" 1
# 8 "common/include/common/board_defs.h" 2

typedef struct
{
 
# 11 "common/include/common/board_defs.h" 3 4
_Bool 
# 11 "common/include/common/board_defs.h"
     msg_pend;
 
# 12 "common/include/common/board_defs.h" 3 4
_Bool 
# 12 "common/include/common/board_defs.h"
     active;
 uint32_t dev_num;
 uint32_t msg_num;
 uint32_t msg_num_start;
 uint32_t ok_packets;
 uint32_t total_packets;
} sensor_t;

typedef struct
{
 
# 22 "common/include/common/board_defs.h" 3 4
_Bool 
# 22 "common/include/common/board_defs.h"
     msg_pend;
 
# 23 "common/include/common/board_defs.h" 3 4
_Bool 
# 23 "common/include/common/board_defs.h"
     active;
 uint32_t dev_num;
 uint32_t msg_num;
 uint32_t msg_num_start;
 uint32_t ok_packets;
 uint32_t total_packets;
} hub_t;


void clock_setup_msi_2mhz(void);




#define MAX_SENSORS 50

extern sensor_t sensors[50];
extern uint8_t num_sensors;
sensor_t *get_sensor(uint32_t dev_num);


#define BATT_SENS_PORT GPIOA
#define BATT_SENS GPIO0

#define PWR_SENS_PORT GPIOA
#define PWR_SENS GPIO1


#define LED_PORT GPIOB
#define LED GPIO8


#define SPF_USART_BAUD 115200
#define SPF_USART USART1
#define SPF_USART_AF GPIO_AF4
#define SPF_USART_RCC RCC_USART1
#define SPF_USART_RCC_RST RST_USART1
#define SPF_USART_TX_PORT GPIOA
#define SPF_USART_TX GPIO9
#define SPF_USART_RX_PORT GPIOA
#define SPF_USART_RX GPIO10



#define RFM_SPI SPI2
#define RFM_SPI_AF GPIO_AF0
#define RFM_SPI_RCC RCC_SPI2
#define RFM_SPI_RST RST_SPI2

#define RFM_SPI_NSS_PORT GPIOA
#define RFM_SPI_NSS GPIO6

#define RFM_SPI_MISO_PORT GPIOB
#define RFM_SPI_MISO GPIO14

#define RFM_SPI_MOSI_PORT GPIOB
#define RFM_SPI_MOSI GPIO15

#define RFM_SPI_SCK_PORT GPIOB
#define RFM_SPI_SCK GPIO13


#define RFM_RESET_PORT GPIOA
#define RFM_RESET GPIO4

#define RFM_IO_0_PORT GPIOB
#define RFM_IO_0 GPIO10
#define RFM_IO_0_EXTI EXTI10
#define RFM_IO_0_NVIC NVIC_EXTI4_15_IRQ

#define RFM_IO_1_PORT GPIOB
#define RFM_IO_1 GPIO11

#define RFM_IO_2_PORT GPIOA
#define RFM_IO_2 GPIO8

#define RFM_IO_3_PORT GPIOB
#define RFM_IO_3 GPIO1

#define RFM_IO_4_PORT GPIOB
#define RFM_IO_4 GPIO2

#define RFM_IO_5_PORT GPIOB
#define RFM_IO_5 GPIO0


#define SIM_USART_BAUD 38400
#define SIM_USART_NVIC NVIC_USART2_IRQ
#define SIM_USART USART2
#define SIM_USART_AF GPIO_AF4
#define SIM_USART_RCC RCC_USART2
#define SIM_USART_RCC_RST RST_USART2

#define SIM_USART_TX_PORT GPIOA
#define SIM_USART_TX GPIO2

#define SIM_USART_RX_PORT GPIOA
#define SIM_USART_RX GPIO3

#define SIM_RESET_PORT GPIOA
#define SIM_RESET GPIO4



#define W25_SPI SPI1
#define W25_SPI_AF GPIO_AF0
#define W25_SPI_RCC RCC_SPI1
#define W25_SPI_RST RST_SPI1

#define W25_SPI_NSS_PORT GPIOB
#define W25_SPI_NSS GPIO6

#define W25_SPI_MISO_PORT GPIOB
#define W25_SPI_MISO GPIO4

#define W25_SPI_MOSI_PORT GPIOB
#define W25_SPI_MOSI GPIO5

#define W25_SPI_SCK_PORT GPIOB
#define W25_SPI_SCK GPIO3
# 233 "common/include/common/board_defs.h"
void gpio_init(void);
# 13 "hub/src/sim.c" 2
# 1 "common/include/common/printf.h" 1
# 33 "common/include/common/printf.h"
#define _PRINTF_H_ 

# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 1 3 4
# 31 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4
#define _STDARG_H 
#define _ANSI_STDARG_H_ 

#undef __need___va_list




#define __GNUC_VA_LIST 

# 40 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;






#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)


#define va_copy(d,s) __builtin_va_copy(d,s)

#define __va_copy(d,s) __builtin_va_copy(d,s)
# 99 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;





#define _VA_LIST_ 


#define _VA_LIST 


#define _VA_LIST_DEFINED 


#define _VA_LIST_T_H 


#define __va_list__ 
# 36 "common/include/common/printf.h" 2
# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h" 1 3 4
# 37 "common/include/common/printf.h" 2
# 52 "common/include/common/printf.h"

# 52 "common/include/common/printf.h"
typedef void (*out_fct_type)(char character);
uint32_t fnprintf(out_fct_type out, const char *format, va_list va);
# 14 "hub/src/sim.c" 2
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

void serial_printf(const char *format, ...);
# 15 "hub/src/sim.c" 2
# 1 "common/include/common/timers.h" 1

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

# 61 "common/include/common/timers.h" 3 4
_Bool 
# 61 "common/include/common/timers.h"
    timeout(uint32_t time_microseconds, char *msg, uint32_t data);

void set_gpio_for_standby(void);
# 16 "hub/src/sim.c" 2
# 1 "common/include/common/aes.h" 1

#define AES_H 



#define AES_BLOCKLEN 16

#define AES_KEY_LEN 16
#define AES_KEY_EXP_SIZE 176

void aes_init(void);
void aes_expand_key(void);
void aes_ecb_encrypt(uint8_t* buf);
void aes_ecb_decrypt(uint8_t* buf);
void aes_generate_random(uint8_t *buf, uint8_t len);
# 17 "hub/src/sim.c" 2

char sim_rx_buf[256];
uint8_t sim_rx_head, sim_rx_tail;

char msg[256];
uint8_t msg_idx;


static void clock_setup(void);
static void usart_setup(void);
static void _putchar(char character);



void sim_init(void)
{
 log_printf("Sim Init\n");

 rcc_periph_clock_enable(RCC_GPIOA);
 rcc_periph_clock_enable(RCC_GPIOB);

    clock_setup();
    usart_setup();

    gpio_mode_setup(((0x50000000U) + 0x00000), 0x1, 0x0, (1 << 4));
    gpio_set_output_options(((0x50000000U) + 0x00000), 0x0, 0x0, (1 << 4));
 gpio_clear(((0x50000000U) + 0x00000), (1 << 4));
 timers_delay_milliseconds(500);
 gpio_set(((0x50000000U) + 0x00000), (1 << 4));
 timers_delay_milliseconds(5000);

 sim_rx_head = 0;
 sim_rx_tail = 0;

 memset(msg, 0, 256);
 msg_idx = 0;

 sim_printf("ate0\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: ate0", 0)) { if(check_response("OK")){ ; break; } else{ ; }};

 log_printf("Sim Init Done\n");
}

void sim_end(void)
{



 sim_printf("at+cfun=4\r\n");
 timeout_init(); while(!timeout(10000000, "SIM: at+cfun=4", 0)) { if(check_response("OK")){ ; break; } else{ ; }};

 sim_printf("at+csclk=1\r\n");
 timeout_init(); while(!timeout(10000000, "SIM: at+csclk=1", 0)) { if(check_response("OK")){ ; break; } else{ ; }};

 usart_disable((((0x40000000U) + 0x00000) + 0x4400));
 rcc_periph_clock_disable(RCC_USART2);

 log_printf("Sim End Done\n");
}


void sim_connect(void)
{
 sim_printf("at\r\n");
 timeout_init(); while(!timeout(10000000, "SIM: at", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+cfun=1\r\n");
 timeout_init(); while(!timeout(10000000, "SIM: at+cfun=1", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timeout_init(); while(!timeout(20000000, "SIM: SMS Ready", 0)) { if(check_response("SMS Ready")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);




 sim_printf("at+creg=1\r\n");
 timeout_init(); while(!timeout(60000000, "SIM: at+creg=1", 0)) { if(check_response("+CREG: 5")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+creg=0\r\n");
 timeout_init(); while(!timeout(60000000, "SIM: at+creg=0", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);




}
# 182 "hub/src/sim.c"
void sim_send_data(uint8_t *data, uint8_t len)
{
 sim_printf("at+sapbr=3,1,APN,data.rewicom.net\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: at+sapbr=3,1,APN,data.rewicom.net", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httpinit\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: at+httpinit", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httppara=cid,1\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: at+httppara=cid,1", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=");
 for(uint8_t i = 0; i < len; i++){ sim_printf("%02X", data[i]); }
 sim_printf("N\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: at+httppara=url,www.circuitboardsamurai.com:8085/website/upload_save_all.php?s=", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);




 sim_printf("at+sapbr=1,1\r\n");
 timeout_init(); while(!timeout(60000000, "SIM: at+sapbr=1,1", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httpaction=0\r\n");
 timeout_init(); while(!timeout(20000000, "SIM: at+httpaction=0", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timeout_init(); while(!timeout(60000000, "SIM: at+httpaction=0", 0)) { if(check_response("+HTTPACTION")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httpread\r\n");
 timeout_init(); while(!timeout(2000000, "SIM: at+httpread", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+httpterm\r\n");
 timeout_init(); while(!timeout(1000000, "SIM: at+httpterm", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);

 sim_printf("at+sapbr=0,1\r\n");
 timeout_init(); while(!timeout(60000000, "SIM: at+sapbr=0,1", 0)) { if(check_response("OK")){ ; break; } else{ ; }};
 timers_delay_milliseconds(100);
}


# 227 "hub/src/sim.c" 3 4
_Bool 
# 227 "hub/src/sim.c"
    check_response(char *str)
{
 
# 229 "hub/src/sim.c" 3 4
_Bool 
# 229 "hub/src/sim.c"
     found = 
# 229 "hub/src/sim.c" 3 4
             0
# 229 "hub/src/sim.c"
                  ;


 while( sim_rx_tail != sim_rx_head )
 {

  char character = sim_rx_buf[sim_rx_tail++];
  msg[msg_idx++] = character;




  if(character == '\n')
  {

   msg[msg_idx++] = '\0';


   if( strstr(msg, str) )
    found = 
# 248 "hub/src/sim.c" 3 4
           1
# 248 "hub/src/sim.c"
               ;


   memset(msg, 0, 256);
   msg_idx = 0;
  }


  if(found)
   return 
# 257 "hub/src/sim.c" 3 4
         1
# 257 "hub/src/sim.c"
             ;
 }


 return 
# 261 "hub/src/sim.c" 3 4
       0
# 261 "hub/src/sim.c"
            ;

}


int sim_printf(const char* format, ...)
{
 char buffer[1];

 va_list va;
 
# 271 "hub/src/sim.c" 3 4
__builtin_va_start(
# 271 "hub/src/sim.c"
va
# 271 "hub/src/sim.c" 3 4
,
# 271 "hub/src/sim.c"
format
# 271 "hub/src/sim.c" 3 4
)
# 271 "hub/src/sim.c"
                    ;
   const int ret = fnprintf(_putchar, format, va);
   
# 273 "hub/src/sim.c" 3 4
  __builtin_va_end(
# 273 "hub/src/sim.c"
  va
# 273 "hub/src/sim.c" 3 4
  )
# 273 "hub/src/sim.c"
            ;

 while(!usart_get_flag((((0x40000000U) + 0x00000) + 0x4400), (1 << 6))) {__asm__("nop");}

 return ret;
}

static void _putchar(char character)
{
 usart_send_blocking((((0x40000000U) + 0x00000) + 0x4400), character);
 usart_send_blocking((((0x40000000U) + 0x10000) + 0x3800), character);
}


void sim_serial_pass_through(void)
{

 usart_disable_rx_interrupt((((0x40000000U) + 0x00000) + 0x4400));
 nvic_disable_irq(27);

    sim_init();

    log_printf("Ready\n");

    while(1)
    {
        if(usart_get_flag((((0x40000000U) + 0x00000) + 0x4400), (1 << 5)))
            usart_send((((0x40000000U) + 0x10000) + 0x3800), usart_recv((((0x40000000U) + 0x00000) + 0x4400)));

        if(usart_get_flag((((0x40000000U) + 0x10000) + 0x3800), (1 << 5)))
            usart_send((((0x40000000U) + 0x00000) + 0x4400), usart_recv((((0x40000000U) + 0x10000) + 0x3800)));
    }
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

    gpio_set_output_options(((0x50000000U) + 0x00000), 0x1, 0x0, (1 << 2));

    gpio_set_af(((0x50000000U) + 0x00000), 0x4, (1 << 2));
    gpio_set_af(((0x50000000U) + 0x00000), 0x4, (1 << 3));

    rcc_periph_reset_pulse(RST_USART2);
 usart_disable((((0x40000000U) + 0x00000) + 0x4400));
 usart_set_baudrate((((0x40000000U) + 0x00000) + 0x4400), 38400);
 usart_set_databits((((0x40000000U) + 0x00000) + 0x4400), 8);
 usart_set_stopbits((((0x40000000U) + 0x00000) + 0x4400),(0x00 << 12));
 usart_set_mode((((0x40000000U) + 0x00000) + 0x4400), ((1 << 2) | (1 << 3)));
 usart_set_parity((((0x40000000U) + 0x00000) + 0x4400), 0x00);
 usart_set_flow_control((((0x40000000U) + 0x00000) + 0x4400), 0x00);
 usart_enable((((0x40000000U) + 0x00000) + 0x4400));


 usart_enable_rx_interrupt((((0x40000000U) + 0x00000) + 0x4400));
 nvic_enable_irq(28);
   nvic_set_priority(28, 0);
}



void usart2_isr(void)
{
 usart_send((((0x40000000U) + 0x10000) + 0x3800), usart_recv((((0x40000000U) + 0x00000) + 0x4400)));

 sim_rx_buf[sim_rx_head++] = usart_recv((((0x40000000U) + 0x00000) + 0x4400));
}
