cmake_minimum_required(VERSION 3.20)
project(freertos-test)

option(SIMULATOR "Run on POSIX" ON)
include(${CMAKE_CURRENT_LIST_DIR}/../../cmake/freertos.cmake)

add_executable(test test_sim.c ../../unity/unity.c)
target_include_directories(test PRIVATE ../../unity ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(test PRIVATE FreeRTOS)

