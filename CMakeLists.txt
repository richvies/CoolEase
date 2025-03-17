cmake_minimum_required(VERSION 3.16)
project(CoolEase)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET>.elf -Wl,--start-group <LINK_LIBRARIES> -lc -lgcc -lnosys -Wl,--end-group -Wl,-Map=<TARGET>.map")

set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(
  -std=c99
  $<$<CONFIG:Debug>:-ggdb3>
  $<$<CONFIG:Debug>:-Og>
  $<$<CONFIG:Release>:-Os>
  $<$<CONFIG:Debug>:-DDEBUG>
  -Wno-all
  -Wextra
  -Wimplicit-function-declaration
  -Wredundant-decls
  -Wmissing-prototypes
  -Wstrict-prototypes
  -Wundef
  -Wshadow
  -mcpu=cortex-m0plus
  -msoft-float
  -mthumb
  -Wstrict-prototypes
  -fno-common
  -ffunction-sections
  -fdata-sections
  -MD
  -DSTM32L0
)

add_link_options(
  -nostartfiles
  -specs=nano.specs
  -mcpu=cortex-m0plus
  -msoft-float
  -Wl,--gc-sections
  -Wl,--nmagic
)

################################################################################
# Include libopencm3
################################################################################

set(LIBOPENCM3_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/libopencm3/include")
set(LIBOPENCM3_LIB "${CMAKE_CURRENT_LIST_DIR}/libopencm3/lib/libopencm3_stm32l0.a")
add_custom_command(
  OUTPUT "${LIBOPENCM3_LIB}"
  COMMAND cd ${CMAKE_CURRENT_LIST_DIR}/libopencm3 && make TARGETS=stm32/l0
  COMMENT "Building libopencm3 for STM32L0"
)
add_custom_target(libopencm3-target DEPENDS "${LIBOPENCM3_LIB}")
add_library(libopencm3 STATIC IMPORTED)
set_target_properties(libopencm3 PROPERTIES
  IMPORTED_LOCATION "${LIBOPENCM3_LIB}"
)
add_dependencies(libopencm3 libopencm3-target)

################################################################################
# Include rest
################################################################################

add_subdirectory(sensor)
add_subdirectory(hub)

