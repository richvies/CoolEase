#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* Ensure definitions are only used by the compiler, and not by the assembler.
 */
#if defined(__GNUC__) || defined(__ICCARM__)

#include <stdint.h>

/* POSIX-specific configurations */
#define configUSE_POSIX_ERRNO                   1
#define configUSE_16_BIT_TICKS                  0
#define configTICK_RATE_HZ                      1000
#define configMAX_PRIORITIES                    (7)
#define configMINIMAL_STACK_SIZE                ((unsigned short)128)
#define configMAX_TASK_NAME_LEN                 (16)
#define configUSE_TRACE_FACILITY                1
#define configUSE_STATS_FORMATTING_FUNCTIONS    1
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_ALTERNATIVE_API               0
#define configQUEUE_REGISTRY_SIZE               8
#define configUSE_QUEUE_SETS                    1
#define configUSE_TIME_SLICING                  1
#define configUSE_NEWLIB_REENTRANT              0
#define configENABLE_BACKWARD_COMPATIBILITY     0
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5

/* Memory allocation related definitions */
#define configSUPPORT_STATIC_ALLOCATION  0
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configTOTAL_HEAP_SIZE            ((size_t)(65536))
#define configAPPLICATION_ALLOCATED_HEAP 0

/* Hook function related definitions */
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
// #define configCHECK_FOR_STACK_OVERFLOW     2
// #define configUSE_MALLOC_FAILED_HOOK       1
#define configUSE_DAEMON_TASK_STARTUP_HOOK 0

/* Run time and task stats gathering related definitions */
#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_TRACE_FACILITY      1

/* Co-routine related definitions */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES 2

/* Software timer related definitions */
#define configUSE_TIMERS             1
#define configTIMER_TASK_PRIORITY    (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH     10
#define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE * 2)

/* Define to trap errors during development */
#define configASSERT(x)                                                        \
    if ((x) == 0) {                                                            \
        taskDISABLE_INTERRUPTS();                                              \
        for (;;)                                                               \
            ;                                                                  \
    }

/* Optional functions - most linkers will remove unused functions anyway */
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_xResumeFromISR              1
#define INCLUDE_vTaskDelayUntil             1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_xTaskGetCurrentTaskHandle   1
#define INCLUDE_uxTaskGetStackHighWaterMark 1
#define INCLUDE_xTaskGetIdleTaskHandle      1
#define INCLUDE_eTaskGetState               1
#define INCLUDE_xEventGroupSetBitFromISR    1
#define INCLUDE_xTimerPendFunctionCall      1
#define INCLUDE_xTaskAbortDelay             1
#define INCLUDE_xTaskGetHandle              1
#define INCLUDE_xTaskResumeFromISR          1

/* POSIX port specific definitions */
#define configPOSIX_STACK_SIZE  ((unsigned short)4096)
#define configUSE_PREEMPTION    1
#define configIDLE_SHOULD_YIELD 1

/* A header file that defines trace macro can be included here. */

/* Definitions needed for the POSIX simulator */
#define projCOVERAGE_TEST                     0
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 3

/* For simulation testing */
#define configSTART_TASK_SCHEDULER_ON_CREATION 1

/* For compatibility with the POSIX port */
#endif /* __GNUC__ || __ICCARM__ */

#endif /* FREERTOS_CONFIG_H */
