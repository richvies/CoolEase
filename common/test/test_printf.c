#include <stdarg.h>
#include <stdio.h>

#include "printf.h"
#include "support/test_helper.h"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void tmpout(char character) {
    printf("%c", character);
}

void tmpprintf(char* format, ...) {
    va_list va;
    va_start(va, format);
    fnprintf(tmpout, format, va);
}

void test_format() {
    tmpprintf("hello world %d", 5);
    printf("random num: %d", generate_random_uint32());
    TEST_ASSERT_FLOAT_WITHIN(0.01f, -19.96f, -19.96f);
}
