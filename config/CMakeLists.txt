set(CONFIG_LIB "config_${APP}")
set(CONFIG_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(${CONFIG_LIB} STATIC board_defs.c)
target_include_directories(${CONFIG_LIB} PUBLIC ${CONFIG_INCLUDE})


################################################################################
# Link with libopencm3
################################################################################

include(${CMAKE_CURRENT_LIST_DIR}/libopencm3.cmake)
target_link_libraries(${CONFIG_LIB} PUBLIC libopencm3)

################################################################################
# Global compile and linker options
################################################################################

# clear default cmake flags
# set(CMAKE_C_FLAGS "")
# set(CMAKE_CXX_FLAGS "")

target_compile_options(${CONFIG_LIB} PUBLIC
  -std=c99
  $<$<CONFIG:Debug>:-ggdb3>
  $<$<CONFIG:Debug>:-Og>
  $<$<CONFIG:Release>:-Os>
  $<$<CONFIG:Debug>:-DDEBUG>
  -Wall
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

if(${COOLEASE_DEVICE} STREQUAL "hub")
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_HUB)
else()
  target_compile_definitions(${CONFIG_LIB} PUBLIC COOLEASE_DEVICE_SENSOR)
endif()

target_link_options(${CONFIG_LIB} PUBLIC
  -nostartfiles
  -specs=nano.specs
  -mcpu=cortex-m0plus
  -msoft-float
  -Wl,--gc-sections
  -Wl,--nmagic
)

################################################################################
# Export config library target
################################################################################

set(CONFIG_LIB ${CONFIG_LIB} PARENT_SCOPE)
