cmake_minimum_required(VERSION 3.16)
project(CoolEase)

################################################################################
# Add libopencm3
################################################################################
include(cmake/libopencm3.cmake)

################################################################################
# Add FreeRTOS
################################################################################
set(FREERTOS_CONFIG_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/config/include/config")
include(cmake/freertos.cmake)

################################################################################
# Loop through available targets
################################################################################
list(APPEND DEVICES hub sensor)
list(APPEND EXE_TYPES freestanding app bootloader)
set(COMMON_LINKER_SCRIPTS_INCLUDE -L${CMAKE_CURRENT_LIST_DIR}/common/ld)

foreach(DEVICE IN LISTS DEVICES)
  set(COOLEASE_DEVICE ${DEVICE})

  ################################################################################
  # Add flags and options
  ################################################################################
  include(cmake/stm32_flags.cmake)
  target_link_libraries(freertos_kernel PRIVATE "stm32_flags")
  target_link_libraries(freertos_kernel_port PRIVATE "stm32_flags")

  ################################################################################
  # Add config library
  ################################################################################
  add_subdirectory(config ${CMAKE_BINARY_DIR}/${COOLEASE_DEVICE}/config)

  ################################################################################
  # Add common library
  ################################################################################
  add_subdirectory(common ${CMAKE_BINARY_DIR}/${COOLEASE_DEVICE}/common)

  ################################################################################
  # Generate targets and link
  ################################################################################
  foreach(EXE_TYPE IN LISTS EXE_TYPES)
    set(EXE_NAME "${COOLEASE_DEVICE}_${EXE_TYPE}_${CMAKE_BUILD_TYPE}")
    set(LINKER_SCRIPT "${EXE_TYPE}.ld")

    add_subdirectory(${COOLEASE_DEVICE} ${CMAKE_BINARY_DIR}/${COOLEASE_DEVICE}/${EXE_TYPE})

    target_include_directories(${EXE_NAME} PRIVATE ${C_INCLUDE})

    target_link_options(${EXE_NAME} PRIVATE
      -T${LINKER_SCRIPT}
      ${COMMON_LINKER_SCRIPTS_INCLUDE}
      ${LINKER_INCLUDE})

    add_custom_target(${EXE_NAME}.lss ALL
      DEPENDS $<TARGET_FILE:${EXE_NAME}>
      COMMAND ${CMAKE_COMMAND} -E echo "Generating ${EXE_NAME}.lss from ${EXE_NAME}.elf"
      COMMAND ${CMAKE_OBJDUMP} -S $<TARGET_FILE:${EXE_NAME}>.elf >
      $<TARGET_FILE:${EXE_NAME}>.lss)

    ################################################################################
    # Link flags and options
    ################################################################################
    target_link_libraries(${EXE_NAME} PRIVATE "stm32_flags_${COOLEASE_DEVICE}")
    target_link_libraries(${COMMON_LIB} PRIVATE "stm32_flags_${COOLEASE_DEVICE}")
    target_link_libraries(${CONFIG_LIB} PRIVATE "stm32_flags_${COOLEASE_DEVICE}")

    ################################################################################
    # Link with libopencm3
    ################################################################################
    target_link_libraries(${CONFIG_LIB} PUBLIC libopencm3)

    ################################################################################
    # Link config library
    ################################################################################
    target_link_libraries(${COMMON_LIB} PUBLIC ${CONFIG_LIB})

    ################################################################################
    # Link common
    ################################################################################
    target_link_libraries(${EXE_NAME} PRIVATE ${COMMON_LIB})

    # TODO: config requires common headers
    target_include_directories(${CONFIG_LIB} PRIVATE ${COMMON_INCLUDE})

    # TODO: common requires cusb headers when building hub
    if(${COOLEASE_DEVICE} STREQUAL "hub")
      target_include_directories(${COMMON_LIB} PRIVATE ${C_INCLUDE})
    endif()

    ################################################################################
    # Link FreeRTOS
    ################################################################################
    target_link_libraries(${EXE_NAME} PRIVATE freertos_kernel)
  endforeach()
endforeach()
