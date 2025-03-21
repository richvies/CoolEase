/**
 ******************************************************************************
 * @file    test_sim.c
 * @author  Test Author
 * @date    Current Date
 * @brief   Basic test for FreeRTOS POSIX port
 *
 * @defgroup testing Testing
 * @{
 *   @defgroup freertos_test FreeRTOS Tests
 *   @brief    Test functions for FreeRTOS POSIX port
 *
 *   This file contains basic tests to verify that the POSIX port of FreeRTOS
 *   is working correctly.
 * @}
 ******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Unity framework */
#include "unity.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

/** @addtogroup testing
 * @{
 */

/** @addtogroup freertos_test
 * @{
 */

/* Test variables */
static TaskHandle_t      testTaskHandle = NULL;
static SemaphoreHandle_t testSemaphore = NULL;
static QueueHandle_t     testQueue = NULL;
static volatile int      taskExecutionCount = 0;
static volatile int      taskCompletionFlag = 0;

/**
 * @brief Test task function
 *
 * Simple task that increments a counter and signals completion
 * @param pvParameters Task parameters (unused)
 * @return None
 */
static void testTask(void* pvParameters) {
    (void)pvParameters; /* Unused parameter */

    /* Increment execution counter */
    taskExecutionCount++;

    /* Signal task has run */
    taskCompletionFlag = 1;

    /* Give semaphore if it exists */
    if (testSemaphore != NULL) {
        xSemaphoreGive(testSemaphore);
    }

    /* Delete self */
    vTaskDelete(NULL);
}

/**
 * @brief Setup function for each test
 *
 * Called before each test case
 * @return None
 */
void setUp(void) {
    /* Reset test variables */
    testTaskHandle = NULL;
    testSemaphore = NULL;
    testQueue = NULL;
    taskExecutionCount = 0;
    taskCompletionFlag = 0;
}

/**
 * @brief Teardown function for each test
 *
 * Called after each test case
 * @return None
 */
void tearDown(void) {
    /* Clean up any remaining resources */
    if (testTaskHandle != NULL) {
        vTaskDelete(testTaskHandle);
        testTaskHandle = NULL;
    }

    if (testSemaphore != NULL) {
        vSemaphoreDelete(testSemaphore);
        testSemaphore = NULL;
    }

    if (testQueue != NULL) {
        vQueueDelete(testQueue);
        testQueue = NULL;
    }
}

/**
 * @brief Test FreeRTOS task creation and execution
 *
 * Verifies that tasks can be created and executed
 * @return None
 */
void test_TaskCreationAndExecution(void) {
    /* Create a task */
    BaseType_t result = xTaskCreate(
        testTask,                 /* Function that implements the task */
        "TestTask",               /* Text name for the task */
        configMINIMAL_STACK_SIZE, /* Stack size in words, not bytes */
        NULL,                     /* Parameter passed into the task */
        tskIDLE_PRIORITY + 1,     /* Priority at which the task is created */
        &testTaskHandle); /* Used to pass out the created task's handle */

    /* Verify task creation succeeded */
    TEST_ASSERT_EQUAL_MESSAGE(pdPASS, result, "Task creation failed");
    TEST_ASSERT_NOT_NULL_MESSAGE(testTaskHandle, "Task handle is NULL");

    /* Let the scheduler run */
    vTaskDelay(pdMS_TO_TICKS(10));

    /* Verify the task executed */
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, taskExecutionCount,
                                  "Task did not execute");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, taskCompletionFlag,
                                  "Task did not complete");
}

/**
 * @brief Test FreeRTOS semaphore functionality
 *
 * Verifies that semaphores work correctly
 * @return None
 */
void test_SemaphoreOperation(void) {
    /* Create a binary semaphore */
    testSemaphore = xSemaphoreCreateBinary();
    TEST_ASSERT_NOT_NULL_MESSAGE(testSemaphore, "Semaphore creation failed");

    /* Create a task that will give the semaphore */
    BaseType_t result =
        xTaskCreate(testTask, "SemaphoreTask", configMINIMAL_STACK_SIZE, NULL,
                    tskIDLE_PRIORITY + 1, &testTaskHandle);

    TEST_ASSERT_EQUAL_MESSAGE(pdPASS, result, "Task creation failed");

    /* Wait for the semaphore with timeout */
    result = xSemaphoreTake(testSemaphore, pdMS_TO_TICKS(100));

    /* Verify semaphore was given */
    TEST_ASSERT_EQUAL_MESSAGE(pdTRUE, result, "Failed to take semaphore");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, taskExecutionCount,
                                  "Task did not execute");
}

/**
 * @brief Test FreeRTOS queue functionality
 *
 * Verifies that queues work correctly
 * @return None
 */
void test_QueueOperation(void) {
    const uint32_t testValue = 0xABCD1234;
    uint32_t       receivedValue = 0;

    /* Create a queue */
    testQueue = xQueueCreate(1, sizeof(uint32_t));
    TEST_ASSERT_NOT_NULL_MESSAGE(testQueue, "Queue creation failed");

    /* Send to queue */
    BaseType_t result = xQueueSend(testQueue, &testValue, 0);
    TEST_ASSERT_EQUAL_MESSAGE(pdTRUE, result, "Failed to send to queue");

    /* Receive from queue */
    result = xQueueReceive(testQueue, &receivedValue, 0);
    TEST_ASSERT_EQUAL_MESSAGE(pdTRUE, result, "Failed to receive from queue");

    /* Verify value */
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(testValue, receivedValue,
                                     "Queue data corruption");
}

/**
 * @brief Test FreeRTOS tick functionality
 *
 * Verifies that the tick count increments correctly
 * @return None
 */
void test_TickCount(void) {
    TickType_t startTick, endTick;

    /* Get starting tick count */
    startTick = xTaskGetTickCount();

    /* Delay for a known period */
    vTaskDelay(pdMS_TO_TICKS(10));

    /* Get ending tick count */
    endTick = xTaskGetTickCount();

    /* Verify ticks increased */
    TEST_ASSERT_MESSAGE(endTick > startTick, "Tick count did not increase");

    /* Verify ticks increased by approximately the expected amount */
    /* Allow for some scheduling variance */
    TEST_ASSERT_MESSAGE((endTick - startTick) >= pdMS_TO_TICKS(5),
                        "Tick count increased by less than expected");
}

/**
 * @brief Test FreeRTOS memory allocation
 *
 * Verifies that pvPortMalloc and vPortFree work correctly
 * @return None
 */
void test_MemoryAllocation(void) {
    const size_t allocSize = 128;
    void*        ptr;

    /* Allocate memory */
    ptr = pvPortMalloc(allocSize);
    TEST_ASSERT_NOT_NULL_MESSAGE(ptr, "Memory allocation failed");

    /* Write to memory to ensure it's usable */
    memset(ptr, 0xAA, allocSize);

    /* Free memory */
    vPortFree(ptr);

    /* Test passed if we got here without crashing */
}

static TaskHandle_t mainTaskHandle = NULL;

static void runTestsTask(void* pvParameters) {
    int result;

    // Initialize Unity test framework
    UNITY_BEGIN();

    // Run all tests
    RUN_TEST(test_TaskCreationAndExecution);
    RUN_TEST(test_SemaphoreOperation);
    RUN_TEST(test_QueueOperation);
    RUN_TEST(test_TickCount);
    RUN_TEST(test_MemoryAllocation);

    // End tests
    result = UNITY_END();

    // Signal main task that tests are complete
    if (mainTaskHandle != NULL) {
        xTaskNotifyGive(mainTaskHandle);
    }

    // Delete self
    vTaskDelete(NULL);
}
/**
 * @brief Main function to run the FreeRTOS tests
 *
 * This function initializes the Unity test framework and runs all the tests
 * defined in this file.
 *
 * @return int Exit code (0 for success, non-zero for failure)
 */
int main(void) {
    printf("Start");

    // Store the main task handle
    mainTaskHandle = xTaskGetCurrentTaskHandle();

    // Create test runner task
    xTaskCreate(runTestsTask, "TestRunner", configMINIMAL_STACK_SIZE * 2, NULL,
                tskIDLE_PRIORITY + 2, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    printf("Scheduler exited\n");

    return UNITY_END();
}

/** @} */ /* End of freertos_test group */
/** @} */ /* End of testing group */
