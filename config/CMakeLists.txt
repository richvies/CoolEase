set(CONFIG_LIB "config_${APP}")
set(CONFIG_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(${CONFIG_LIB} STATIC board_defs.c)
target_include_directories(${CONFIG_LIB} PUBLIC ${CONFIG_INCLUDE})

################################################################################
# Link with libopencm3
################################################################################

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/libopencm3.cmake)
target_link_libraries(${CONFIG_LIB} PUBLIC libopencm3)


################################################################################
# Link with FreeRTOS
################################################################################

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/freertos.cmake)
target_link_libraries(${CONFIG_LIB} PUBLIC FreeRTOS)

################################################################################
# Export config library target
################################################################################

target_compile_options(FreeRTOS PUBLIC
  $<$<CONFIG:Debug>:-O0 -g3>
  $<$<CONFIG:Release>:-Os -g0>
  $<$<CONFIG:Debug>:-DDEBUG>
  -mcpu=cortex-m0plus
  -Wall -Wextra -Wpedantic
  -fdata-sections -ffunction-sections
  -msoft-float
  -DSTM32L0
  -MD
  -MP
)

target_link_options(FreeRTOS PUBLIC
  -specs=nano.specs
  -nostartfiles
  -Wl,--gc-sections
  -Wl,--print-memory-usage
)

if(${COOLEASE_DEVICE} STREQUAL "hub")
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_HUB)
else()
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_SENSOR)
endif()

set(CONFIG_LIB ${CONFIG_LIB} PARENT_SCOPE)
