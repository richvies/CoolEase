if(NOT DEFINED FREERTOS_SIMULATOR)
  option(FREERTOS_SIMULATOR "Run on POSIX" OFF)
endif()

if(NOT DEFINED FREERTOS_CONFIG_INCLUDE)
  message(FATAL_ERROR "Must set FREERTOS_CONFIG_INCLUDE before including ${CMAKE_CURRENT_LIST_FILE}")
endif()
message(STATUS "Using FreeRTOS config at: ${FREERTOS_CONFIG_INCLUDE}")

add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM INTERFACE ${FREERTOS_CONFIG_INCLUDE})

if(FREERTOS_SIMULATOR)
  message(NOTICE "Compiling freertos_kernel for POSIX")
  set(FREERTOS_PORT UNIX CACHE STRING "")
else()
  message(NOTICE "Compiling freertos_kernel for STM32")
  set(FREERTOS_PORT GCC_ARM_CM0 CACHE STRING "")
endif()

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS")
