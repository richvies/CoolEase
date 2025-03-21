/**
 ******************************************************************************
 * @file    test_printf.c
 * @author  Richard Davies
 * @date    26/Dec/2020
 * @brief   Printf Testing Source File
 *
 * @defgroup testing Testing
 * @{
 *   @defgroup printf_test Printf Tests
 *   @brief    Test functions for printf implementation
 *
 *   This file contains test functions for the lightweight printf
 *implementation.
 * @}
 ******************************************************************************
 */

#include <stdarg.h>
#include <stdio.h>

#include "printf.h"
#include "support/test_helper.h"
#include "unity.h"

/** @addtogroup testing
 * @{
 */

/** @addtogroup printf_test
 * @{
 */

/**
 * @brief Test setup function
 *
 * Called before each test case
 * @return None
 */
void setUp(void) {
}

/**
 * @brief Test teardown function
 *
 * Called after each test case
 * @return None
 */
void tearDown(void) {
}

/**
 * @brief Temporary output function for testing
 *
 * Redirects output to standard output
 * @param character Character to output
 * @return None
 */
void tmpout(char character) {
    printf("%c", character);
}

/**
 * @brief Temporary printf function for testing
 *
 * Uses the custom printf implementation with standard output
 * @param format Format string
 * @param ... Variable arguments
 * @return None
 */
void tmpprintf(char* format, ...) {
    va_list va;
    va_start(va, format);
    fnprintf(tmpout, format, va);
}

/**
 * @brief Test formatting functionality
 *
 * Tests various formatting options of the printf implementation
 * @return None
 */
void test_format() {
    tmpprintf("hello world %d", 5);
    printf("random num: %d", generate_random_uint32());
    TEST_ASSERT_FLOAT_WITHIN(0.01f, -19.96f, -19.96f);
}

/** @} */ /* End of printf_test group */
/** @} */ /* End of testing group */
