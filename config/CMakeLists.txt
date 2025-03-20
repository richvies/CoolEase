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

target_compile_options(FreeRTOS PUBLIC
  -mcpu=cortex-m0plus
  -Wall -Wextra -Wpedantic
  -fdata-sections -ffunction-sections
  $<$<CONFIG:Debug>:-O0>
  $<$<CONFIG:Debug>:-g3>
  $<$<CONFIG:Release>:-Os>
  $<$<CONFIG:Release>:-g0>
  $<$<CONFIG:Debug>:-DDEBUG>
  -msoft-float
  -mthumb
  -MD
  -DSTM32L0
)

set(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -x assembler-with-cpp -MMD -MP")

target_link_libraries(${CONFIG_LIB} PUBLIC FreeRTOS)

################################################################################
# Export config library target
################################################################################

if(${COOLEASE_DEVICE} STREQUAL "hub")
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_HUB)
else()
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_SENSOR)
endif()

target_link_options(${CONFIG_LIB} PUBLIC
  -specs=nano.specs
  -msoft-float
  -Wl,--gc-sections
  -Wl,--nmagic
  -Wl,--print-memory-usage
)

set(CONFIG_LIB ${CONFIG_LIB} PARENT_SCOPE)
