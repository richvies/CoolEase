set(FREERTOS_DIR "${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS")
set(FREERTOS_INCLUDE "${FREERTOS_DIR}/include")

if(NOT DEFINED SIMULATOR)
  option(SIMULATOR "Run on POSIX" OFF)
endif()

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
  )

  target_include_directories(FreeRTOS PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/include
  )


  if(DEFINED SIMULATOR)
    message(NOTICE "Compiling FreeRTOS for POSIX")

    target_include_directories(FreeRTOS PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/posix
    )
    target_sources(FreeRTOS PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/posix/port.c
      ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/posix/utils/wait_for_event.c
    )
  else()
    target_sources(FreeRTOS PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/cm3/port.c
    )
    target_include_directories(FreeRTOS PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS/portable/cm3
      ${CMAKE_CURRENT_LIST_DIR}/../config/include/config
    )
  endif()
endif()

