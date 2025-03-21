/**
 ******************************************************************************
 * @file    printf.h
 * @author  Marco Paland (info@paland.com)
 * @date    2014-2019
 * @brief   Lightweight printf implementation
 *
 * @defgroup common Common
 * @{
 *   @defgroup printf_api Formatted Output
 *   @brief    Lightweight printf implementation for embedded systems
 *
 *   A lightweight, optimized printf implementation for resource-constrained
 *   embedded systems. This implementation is thread-safe, reentrant, and
 *   significantly smaller than standard library printf.
 * @}
 ******************************************************************************
 * @copyright The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup common
 * @{
 */

/** @addtogroup printf_api
 * @{
 */

/**
 * @brief Output function type definition
 *
 * Function pointer type for character output functions.
 * Custom implementations must be provided for different output devices.
 */
typedef void (*out_fct_type)(char character);

/**
 * @brief Format and output a string using a custom output function
 *
 * This function formats a string according to the format string and
 * outputs it using the provided output function.
 *
 * @param out Output function to use for character output
 * @param format Format string
 * @param va Variable argument list
 * @return Number of characters output
 */
uint32_t fnprintf(out_fct_type out, const char* format, va_list va);

/**
 * @brief Convert a string to an integer
 *
 * Parses a string and converts it to an integer value.
 * Advances the string pointer to the end of the parsed number.
 *
 * @param str Pointer to string pointer (will be updated)
 * @return Parsed integer value
 */
uint32_t _atoi(const char** str);

/**
 * @brief Check if a character is a digit
 *
 * @param ch Character to check
 * @return true if the character is a digit (0-9), false otherwise
 */
bool _is_digit(char ch);

/** @} */ /* End of printf_api group */
/** @} */ /* End of common group */

#ifdef __cplusplus
}
#endif

#endif // _PRINTF_H_
