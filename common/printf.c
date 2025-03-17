///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2019, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// \brief Tiny printf, sprintf and (v)snprintf implementation, optimized for
// speed on
//        embedded systems with a very limited resources. These routines are
//        thread safe and reentrant! Use this instead of the bloated
//        standard/newlib printf cause these use malloc for printf (and may not
//        be thread safe).
//
///////////////////////////////////////////////////////////////////////////////

#include "common/printf.h"

#include <stdbool.h>
#include <stdint.h>

// 'ntoa' conversion buffer size, this must be big enough to hold one converted
// numeric number including padded zeros (dynamically created on stack)
// default: 32 byte
#define PRINTF_NTOA_BUFFER_SIZE 32

#define PRINTF_MAX_STR_LEN 1024

///////////////////////////////////////////////////////////////////////////////

// internal secure strlen
// \return The length of the string (excluding the terminating 0) limited by
// 'maxsize'
static inline uint32_t _strnlen_s(const char* str, uint32_t maxsize) {
    const char* s;
    uint32_t    len = 0;

    for (s = str; *s && maxsize--; ++s) {
        len++;
    };
    return len;
}

// internal itoa format
static uint32_t _ntoa_format(out_fct_type out, uint32_t value, uint32_t base,
                             uint32_t width, bool negative) {
    char     buf[PRINTF_NTOA_BUFFER_SIZE];
    uint32_t len = 0;

    // Digits to char
    do {
        const char digit = (char)(value % base);
        buf[len++] = digit < 10 ? '0' + digit : ('A') + digit - 10;
        value /= base;
    } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));

    // pad leading zeros
    while ((len < width) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
        buf[len++] = '0';
    }

    // Base specifier
    if ((base == 16U) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
        buf[len++] = 'X';
    } else if ((base == 2U) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
        buf[len++] = 'b';
    }
    if (((base == 16U) || (base == 2U)) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
        buf[len++] = '0';
    }

    if (negative && (len < PRINTF_NTOA_BUFFER_SIZE)) {
        buf[len++] = '-';
    }

    // reverse string and write out
    uint32_t i = len;
    while (i) {
        out(buf[--i]);
    }
    return len;
}

uint32_t fnprintf(out_fct_type out, const char* format, va_list va) {
    uint32_t width;
    uint32_t idx = 0U;

    while (*format) {
        // format specifier?  %[flags][width]
        if (*format == '%') {
            // Yes, evaluate it
            format++;
        } else {
            // Just print char
            out(*format);
            idx++;
            format++;
            continue;
        }

        // evaluate width field
        width = 0U;
        if (_is_digit(*format)) {
            width = _atoi(&format);
        }

        // evaluate specifier
        switch (*format) {
        case 'd':
        case 'i':
        case 'u':
        case 'x':
        case 'X':
        case 'o':
        case 'b': {
            // set the base
            uint32_t base;
            if (*format == 'x' || *format == 'X') {
                base = 16U;
            } else if (*format == 'o') {
                base = 8U;
            } else if (*format == 'b') {
                base = 2U;
            } else {
                base = 10U;
            }

            // convert integer
            if ((*format == 'i') || (*format == 'd')) {
                int32_t val = (int32_t)va_arg(va, int);
                idx += _ntoa_format(out, (val < 0) ? (0 - val) : val, base,
                                    width, (val < 0) ? true : false);
            } else {
                idx += _ntoa_format(out, (uint32_t)va_arg(va, int), base, width,
                                    false);
            }
            format++;
            break;
        }

        case 'c': {
            out((char)va_arg(va, int));
            idx++;
            format++;
            break;
        }

        case 's': {
            const char* p = va_arg(va, char*);
            uint32_t    l = _strnlen_s(p, PRINTF_MAX_STR_LEN);

            // string output
            while (*p != 0) {
                out(*(p++));
                idx++;
            }
            format++;
            break;
        }

        case 'p': {
            width = sizeof(void*) * 2U;
            idx += _ntoa_format(out, (uint32_t)((uintptr_t)va_arg(va, void*)),
                                16U, width, false);
            format++;
            break;
        }

        case '%': {
            out('%');
            idx++;
            format++;
            break;
        }

        default: {
            out(*format);
            idx++;
            format++;
            break;
        }
        }
    }
    // return written chars
    return idx;
}

bool _is_digit(char ch) { return (ch >= '0') && (ch <= '9'); }

uint32_t _atoi(const char** str) {
    uint32_t i = 0U;
    while (_is_digit(**str)) {
        i = i * 10U + (uint32_t)(*((*str)++) - '0');
    }
    return i;
}

///////////////////////////////////////////////////////////////////////////////
