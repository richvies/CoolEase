# 1 "common/src/aes.c"
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
#define DEBUG 1
#define STM32L0 1
#define STM32L051C8T6 1
# 1 "common/src/aes.c"
# 38 "common/src/aes.c"
# 1 "common/include/common/aes.h" 1

#define AES_H 

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
# 5 "common/include/common/aes.h" 2

#define AES_BLOCKLEN 16

#define AES_KEY_LEN 16
#define AES_KEY_EXP_SIZE 176


# 11 "common/include/common/aes.h"
void aes_init(void);
void aes_expand_key(void);
void aes_ecb_encrypt(uint8_t* buf);
void aes_ecb_decrypt(uint8_t* buf);
void aes_generate_random(uint8_t *buf, uint8_t len);
# 39 "common/src/aes.c" 2

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


# 41 "common/src/aes.c" 2


# 1 "common/include/common/log.h" 1
# 26 "common/include/common/log.h"
#define LOG_H 






# 1 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 1 3 4
# 29 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/usr/local/Cellar/arm-gcc-bin/9-2020-q2-update/lib/gcc/arm-none-eabi/9.3.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 34 "common/include/common/log.h" 2
# 43 "common/include/common/log.h"

# 43 "common/include/common/log.h"
enum log_type
{
    MAIN=0,
    SPF,
    MEM,
    BOOT,
    RFM,
    TMP
};
# 62 "common/include/common/log.h"
void log_init(void);
void log_printf(enum log_type type, const char *format, ...);
# 44 "common/src/aes.c" 2
# 1 "common/include/common/memory.h" 1
# 26 "common/include/common/memory.h"
#define MEMORY_H 






# 1 "libopencm3/include/libopencm3/stm32/flash.h" 1
# 20 "libopencm3/include/libopencm3/stm32/flash.h"
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
# 21 "libopencm3/include/libopencm3/stm32/flash.h" 2
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
# 22 "libopencm3/include/libopencm3/stm32/flash.h" 2
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
# 34 "common/include/common/memory.h" 2
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
# 35 "common/include/common/memory.h" 2
# 49 "common/include/common/memory.h"
#define FLASH_PAGE_SIZE 128
#define FLASH_NUM_PAGES 512
#define FLASH_START 0x08000000
#define FLASH_START_APP 0x08004000
#define FLASH_END 0x08010000

#define EEPROM_PAGE_SIZE 4
#define EEPROM_NUM_PAGES 512
#define EEPROM_START 0x08080000
#define EEPROM_END 0x08080800

#define LOG_SIZE 1024
# 73 "common/include/common/memory.h"
void mem_init(void);


# 75 "common/include/common/memory.h" 3 4
_Bool 
# 75 "common/include/common/memory.h"
    mem_eeprom_write_word(uint32_t address, uint32_t data);

# 76 "common/include/common/memory.h" 3 4
_Bool 
# 76 "common/include/common/memory.h"
    mem_eeprom_write_half_word(uint32_t address, uint16_t data);

# 77 "common/include/common/memory.h" 3 4
_Bool 
# 77 "common/include/common/memory.h"
    mem_eeprom_write_byte(uint32_t address, uint8_t data);


# 79 "common/include/common/memory.h" 3 4
_Bool 
# 79 "common/include/common/memory.h"
    mem_flash_erase_page(uint32_t address);

# 80 "common/include/common/memory.h" 3 4
_Bool 
# 80 "common/include/common/memory.h"
    mem_flash_write_word(uint32_t address, uint32_t data);

# 81 "common/include/common/memory.h" 3 4
_Bool 
# 81 "common/include/common/memory.h"
    mem_flash_write_half_page(uint32_t address, uint32_t *data);

void mem_save_reading(int16_t reading);

uint32_t mem_get_dev_state(void);
uint32_t mem_get_dev_num(void);
uint32_t mem_get_msg_num(void);
void mem_update_msg_num(uint32_t new);
uint32_t mem_get_num_readings(void);
int16_t mem_get_reading(uint32_t reading_num);

void mem_get_log(char log[1024]);
void mem_wipe_log(void);
void mem_print_log(void);

void mem_get_aes_key(uint8_t *aes_key);
void mem_set_aes_key(uint8_t *aes_key);
void mem_get_aes_key_exp(uint8_t *aes_key_exp);
void mem_set_aes_key_exp(uint8_t *aes_key_exp);

void mem_wipe_readings(void);
# 45 "common/src/aes.c" 2





#define Nb 4

#define Nk 4
#define Nr 10






#define MULTIPLY_AS_A_FUNCTION 0







typedef uint8_t state_t[4][4];
static uint8_t adc_channels[4] = {0, 1, 8, 9};
static uint8_t round_key[176];





static const uint8_t sbox[256] = {

  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

static const uint8_t rsbox[256] = {
  0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
  0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
  0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
  0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
  0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
  0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
  0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
  0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
  0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
  0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
  0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
  0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
  0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
  0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
  0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };



static const uint8_t Rcon[11] = {
  0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };
# 133 "common/src/aes.c"
#define getSBoxValue(num) (sbox[(num)])

#define getSBoxInvert(num) (rsbox[(num)])


static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)
{
  unsigned i, j, k;
  uint8_t tempa[4];


  for (i = 0; i < 4; ++i)
  {
    RoundKey[(i * 4) + 0] = Key[(i * 4) + 0];
    RoundKey[(i * 4) + 1] = Key[(i * 4) + 1];
    RoundKey[(i * 4) + 2] = Key[(i * 4) + 2];
    RoundKey[(i * 4) + 3] = Key[(i * 4) + 3];
  }


  for (i = 4; i < 4 * (10 + 1); ++i)
  {
    {
      k = (i - 1) * 4;
      tempa[0]=RoundKey[k + 0];
      tempa[1]=RoundKey[k + 1];
      tempa[2]=RoundKey[k + 2];
      tempa[3]=RoundKey[k + 3];

    }

    if (i % 4 == 0)
    {




      {
        const uint8_t u8tmp = tempa[0];
        tempa[0] = tempa[1];
        tempa[1] = tempa[2];
        tempa[2] = tempa[3];
        tempa[3] = u8tmp;
      }





      {
        tempa[0] = (sbox[(tempa[0])]);
        tempa[1] = (sbox[(tempa[1])]);
        tempa[2] = (sbox[(tempa[2])]);
        tempa[3] = (sbox[(tempa[3])]);
      }

      tempa[0] = tempa[0] ^ Rcon[i/4];
    }

    j = i * 4; k=(i - 4) * 4;
    RoundKey[j + 0] = RoundKey[k + 0] ^ tempa[0];
    RoundKey[j + 1] = RoundKey[k + 1] ^ tempa[1];
    RoundKey[j + 2] = RoundKey[k + 2] ^ tempa[2];
    RoundKey[j + 3] = RoundKey[k + 3] ^ tempa[3];
  }
}



static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)
{
  uint8_t i,j;
  for (i = 0; i < 4; ++i)
  {
    for (j = 0; j < 4; ++j)
    {
      (*state)[i][j] ^= RoundKey[(round * 4 * 4) + (i * 4) + j];
    }
  }
}



static void SubBytes(state_t* state)
{
  uint8_t i, j;
  for (i = 0; i < 4; ++i)
  {
    for (j = 0; j < 4; ++j)
    {
      (*state)[j][i] = (sbox[((*state)[j][i])]);
    }
  }
}




static void ShiftRows(state_t* state)
{
  uint8_t temp;


  temp = (*state)[0][1];
  (*state)[0][1] = (*state)[1][1];
  (*state)[1][1] = (*state)[2][1];
  (*state)[2][1] = (*state)[3][1];
  (*state)[3][1] = temp;


  temp = (*state)[0][2];
  (*state)[0][2] = (*state)[2][2];
  (*state)[2][2] = temp;

  temp = (*state)[1][2];
  (*state)[1][2] = (*state)[3][2];
  (*state)[3][2] = temp;


  temp = (*state)[0][3];
  (*state)[0][3] = (*state)[3][3];
  (*state)[3][3] = (*state)[2][3];
  (*state)[2][3] = (*state)[1][3];
  (*state)[1][3] = temp;
}

static uint8_t xtime(uint8_t x)
{
  return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
}


static void MixColumns(state_t* state)
{
  uint8_t i;
  uint8_t Tmp, Tm, t;
  for (i = 0; i < 4; ++i)
  {
    t = (*state)[i][0];
    Tmp = (*state)[i][0] ^ (*state)[i][1] ^ (*state)[i][2] ^ (*state)[i][3] ;
    Tm = (*state)[i][0] ^ (*state)[i][1] ; Tm = xtime(Tm); (*state)[i][0] ^= Tm ^ Tmp ;
    Tm = (*state)[i][1] ^ (*state)[i][2] ; Tm = xtime(Tm); (*state)[i][1] ^= Tm ^ Tmp ;
    Tm = (*state)[i][2] ^ (*state)[i][3] ; Tm = xtime(Tm); (*state)[i][2] ^= Tm ^ Tmp ;
    Tm = (*state)[i][3] ^ t ; Tm = xtime(Tm); (*state)[i][3] ^= Tm ^ Tmp ;
  }
}
# 294 "common/src/aes.c"
#define Multiply(x,y) ( ((y & 1) * x) ^ ((y>>1 & 1) * xtime(x)) ^ ((y>>2 & 1) * xtime(xtime(x))) ^ ((y>>3 & 1) * xtime(xtime(xtime(x)))) ^ ((y>>4 & 1) * xtime(xtime(xtime(xtime(x))))))
# 306 "common/src/aes.c"
static void InvMixColumns(state_t* state)
{
  int i;
  uint8_t a, b, c, d;
  for (i = 0; i < 4; ++i)
  {
    a = (*state)[i][0];
    b = (*state)[i][1];
    c = (*state)[i][2];
    d = (*state)[i][3];

    (*state)[i][0] = ( ((0x0e & 1) * a) ^ ((0x0e>>1 & 1) * xtime(a)) ^ ((0x0e>>2 & 1) * xtime(xtime(a))) ^ ((0x0e>>3 & 1) * xtime(xtime(xtime(a)))) ^ ((0x0e>>4 & 1) * xtime(xtime(xtime(xtime(a)))))) ^ ( ((0x0b & 1) * b) ^ ((0x0b>>1 & 1) * xtime(b)) ^ ((0x0b>>2 & 1) * xtime(xtime(b))) ^ ((0x0b>>3 & 1) * xtime(xtime(xtime(b)))) ^ ((0x0b>>4 & 1) * xtime(xtime(xtime(xtime(b)))))) ^ ( ((0x0d & 1) * c) ^ ((0x0d>>1 & 1) * xtime(c)) ^ ((0x0d>>2 & 1) * xtime(xtime(c))) ^ ((0x0d>>3 & 1) * xtime(xtime(xtime(c)))) ^ ((0x0d>>4 & 1) * xtime(xtime(xtime(xtime(c)))))) ^ ( ((0x09 & 1) * d) ^ ((0x09>>1 & 1) * xtime(d)) ^ ((0x09>>2 & 1) * xtime(xtime(d))) ^ ((0x09>>3 & 1) * xtime(xtime(xtime(d)))) ^ ((0x09>>4 & 1) * xtime(xtime(xtime(xtime(d))))));
    (*state)[i][1] = ( ((0x09 & 1) * a) ^ ((0x09>>1 & 1) * xtime(a)) ^ ((0x09>>2 & 1) * xtime(xtime(a))) ^ ((0x09>>3 & 1) * xtime(xtime(xtime(a)))) ^ ((0x09>>4 & 1) * xtime(xtime(xtime(xtime(a)))))) ^ ( ((0x0e & 1) * b) ^ ((0x0e>>1 & 1) * xtime(b)) ^ ((0x0e>>2 & 1) * xtime(xtime(b))) ^ ((0x0e>>3 & 1) * xtime(xtime(xtime(b)))) ^ ((0x0e>>4 & 1) * xtime(xtime(xtime(xtime(b)))))) ^ ( ((0x0b & 1) * c) ^ ((0x0b>>1 & 1) * xtime(c)) ^ ((0x0b>>2 & 1) * xtime(xtime(c))) ^ ((0x0b>>3 & 1) * xtime(xtime(xtime(c)))) ^ ((0x0b>>4 & 1) * xtime(xtime(xtime(xtime(c)))))) ^ ( ((0x0d & 1) * d) ^ ((0x0d>>1 & 1) * xtime(d)) ^ ((0x0d>>2 & 1) * xtime(xtime(d))) ^ ((0x0d>>3 & 1) * xtime(xtime(xtime(d)))) ^ ((0x0d>>4 & 1) * xtime(xtime(xtime(xtime(d))))));
    (*state)[i][2] = ( ((0x0d & 1) * a) ^ ((0x0d>>1 & 1) * xtime(a)) ^ ((0x0d>>2 & 1) * xtime(xtime(a))) ^ ((0x0d>>3 & 1) * xtime(xtime(xtime(a)))) ^ ((0x0d>>4 & 1) * xtime(xtime(xtime(xtime(a)))))) ^ ( ((0x09 & 1) * b) ^ ((0x09>>1 & 1) * xtime(b)) ^ ((0x09>>2 & 1) * xtime(xtime(b))) ^ ((0x09>>3 & 1) * xtime(xtime(xtime(b)))) ^ ((0x09>>4 & 1) * xtime(xtime(xtime(xtime(b)))))) ^ ( ((0x0e & 1) * c) ^ ((0x0e>>1 & 1) * xtime(c)) ^ ((0x0e>>2 & 1) * xtime(xtime(c))) ^ ((0x0e>>3 & 1) * xtime(xtime(xtime(c)))) ^ ((0x0e>>4 & 1) * xtime(xtime(xtime(xtime(c)))))) ^ ( ((0x0b & 1) * d) ^ ((0x0b>>1 & 1) * xtime(d)) ^ ((0x0b>>2 & 1) * xtime(xtime(d))) ^ ((0x0b>>3 & 1) * xtime(xtime(xtime(d)))) ^ ((0x0b>>4 & 1) * xtime(xtime(xtime(xtime(d))))));
    (*state)[i][3] = ( ((0x0b & 1) * a) ^ ((0x0b>>1 & 1) * xtime(a)) ^ ((0x0b>>2 & 1) * xtime(xtime(a))) ^ ((0x0b>>3 & 1) * xtime(xtime(xtime(a)))) ^ ((0x0b>>4 & 1) * xtime(xtime(xtime(xtime(a)))))) ^ ( ((0x0d & 1) * b) ^ ((0x0d>>1 & 1) * xtime(b)) ^ ((0x0d>>2 & 1) * xtime(xtime(b))) ^ ((0x0d>>3 & 1) * xtime(xtime(xtime(b)))) ^ ((0x0d>>4 & 1) * xtime(xtime(xtime(xtime(b)))))) ^ ( ((0x09 & 1) * c) ^ ((0x09>>1 & 1) * xtime(c)) ^ ((0x09>>2 & 1) * xtime(xtime(c))) ^ ((0x09>>3 & 1) * xtime(xtime(xtime(c)))) ^ ((0x09>>4 & 1) * xtime(xtime(xtime(xtime(c)))))) ^ ( ((0x0e & 1) * d) ^ ((0x0e>>1 & 1) * xtime(d)) ^ ((0x0e>>2 & 1) * xtime(xtime(d))) ^ ((0x0e>>3 & 1) * xtime(xtime(xtime(d)))) ^ ((0x0e>>4 & 1) * xtime(xtime(xtime(xtime(d))))));
  }
}




static void InvSubBytes(state_t* state)
{
  uint8_t i, j;
  for (i = 0; i < 4; ++i)
  {
    for (j = 0; j < 4; ++j)
    {
      (*state)[j][i] = (rsbox[((*state)[j][i])]);
    }
  }
}

static void InvShiftRows(state_t* state)
{
  uint8_t temp;


  temp = (*state)[3][1];
  (*state)[3][1] = (*state)[2][1];
  (*state)[2][1] = (*state)[1][1];
  (*state)[1][1] = (*state)[0][1];
  (*state)[0][1] = temp;


  temp = (*state)[0][2];
  (*state)[0][2] = (*state)[2][2];
  (*state)[2][2] = temp;

  temp = (*state)[1][2];
  (*state)[1][2] = (*state)[3][2];
  (*state)[3][2] = temp;


  temp = (*state)[0][3];
  (*state)[0][3] = (*state)[1][3];
  (*state)[1][3] = (*state)[2][3];
  (*state)[2][3] = (*state)[3][3];
  (*state)[3][3] = temp;
}



static void Cipher(state_t* state, const uint8_t* RoundKey)
{
  uint8_t round = 0;


  AddRoundKey(0, state, RoundKey);





  for (round = 1; ; ++round)
  {
    SubBytes(state);
    ShiftRows(state);
    if (round == 10) {
      break;
    }
    MixColumns(state);
    AddRoundKey(round, state, RoundKey);
  }

  AddRoundKey(10, state, RoundKey);
}

static void InvCipher(state_t* state, const uint8_t* RoundKey)
{
  uint8_t round = 0;


  AddRoundKey(10, state, RoundKey);





  for (round = (10 - 1); ; --round)
  {
    InvShiftRows(state);
    InvSubBytes(state);
    AddRoundKey(round, state, RoundKey);
    if (round == 0) {
      break;
    }
    InvMixColumns(state);
  }

}





void aes_init(void)
{
  uint8_t tmp[176];
  mem_get_aes_key_exp(tmp);

  for(int i = 0; i < 176; i++)
  {
    round_key[i] = tmp[i];
  }
}

void aes_expand_key(void)
{
  uint8_t key[16];
  mem_get_aes_key(key);

  KeyExpansion(round_key, key);

  uint8_t tmp[176];
  for(int i = 0; i < 176; i++)
  {
    tmp[i] = round_key[i];
  }

  mem_set_aes_key_exp(tmp);
}

void aes_ecb_encrypt(uint8_t* buf)
{

  Cipher((state_t*)buf, round_key);
}

void aes_ecb_decrypt(uint8_t* buf)
{

  InvCipher((state_t*)buf, round_key);
}

void aes_generate_random(uint8_t *buf, uint8_t len)
{
    for(int i = 0; i < len; i++)
        buf[i] = buf[i] << (8 * i);
# 535 "common/src/aes.c"
}
