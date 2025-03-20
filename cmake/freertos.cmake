set(FREERTOS_DIR "${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS")
set(FREERTOS_INCLUDE "${FREERTOS_DIR}/include")

if(NOT TARGET FreeRTOS)
  add_library(FreeRTOS STATIC
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/croutine.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/event_groups.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/list.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/queue.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/stream_buffer.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/tasks.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/timers.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/MemMang/heap_4.c
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/port.c
  )
  target_include_directories(FreeRTOS PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/include
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable
    ${CMAKE_CURRENT_LIST_DIR}/../config/include/config
  )
endif()

