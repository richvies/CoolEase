################################################################################
# Common flags
################################################################################
if(NOT TARGET stm32_flags)
  add_library("stm32_flags" INTERFACE)

  target_compile_options("stm32_flags" INTERFACE
    -mcpu=cortex-m0plus
    -Wall -Wextra -Wpedantic
    -fdata-sections -ffunction-sections
    -msoft-float
    -DSTM32L0
    -MD
    -MP
  )

  target_link_options("stm32_flags" INTERFACE
    -specs=nano.specs
    # -nostartfiles
    -Wl,--gc-sections
    -Wl,--print-memory-usage
  )
endif()

################################################################################
# Device specific flags
################################################################################
add_library("stm32_flags_${COOLEASE_DEVICE}" INTERFACE)
if(${COOLEASE_DEVICE} STREQUAL "hub")
  target_compile_definitions("stm32_flags_${COOLEASE_DEVICE}" INTERFACE COOLEASE_DEVICE_HUB)
elseif(${COOLEASE_DEVICE} STREQUAL "sensor")
  target_compile_definitions("stm32_flags_${COOLEASE_DEVICE}" INTERFACE COOLEASE_DEVICE_SENSOR)
else()
  message(FATAL_ERROR "Dont recognize device type ${COOLEASE_DEVICE}")
endif()
target_link_libraries("stm32_flags_${COOLEASE_DEVICE}" INTERFACE "stm32_flags")
