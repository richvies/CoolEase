set(LIBOPENCM3 "libopencm3")
set(LIBOPENCM3_DIR "${CMAKE_CURRENT_LIST_DIR}/../libopencm3")
set(LIBOPENCM3_INCLUDE "${LIBOPENCM3_DIR}/include")
set(LIBOPENCM3_LIB_NAME "libopencm3_stm32l0.a")
set(LIBOPENCM3_LIB_PATH "${CMAKE_BINARY_DIR}/${LIBOPENCM3_LIB_NAME}")

################################################################################
# libopencm3 build command
################################################################################

# this file is included by both sensor and hub so prevent duplicate target def.
if(NOT TARGET libopencm3-target)
  add_custom_command(
    OUTPUT ${LIBOPENCM3_LIB_PATH}
    COMMAND ${CMAKE_COMMAND} -E echo "Building libopencm3 for STM32L0"
    COMMAND cd ${CMAKE_CURRENT_LIST_DIR}/../libopencm3 && make TARGETS=stm32/l0
    COMMAND mv "${LIBOPENCM3_DIR}/lib/${LIBOPENCM3_LIB_NAME}" ${LIBOPENCM3_LIB_PATH}
  )
  add_custom_target(libopencm3-target DEPENDS ${LIBOPENCM3_LIB_PATH})
endif()

################################################################################
# import library and export as normal cmake target
################################################################################

add_library(${LIBOPENCM3} STATIC IMPORTED)
set_target_properties(${LIBOPENCM3} PROPERTIES
  IMPORTED_LOCATION ${LIBOPENCM3_LIB_PATH}
)
target_include_directories(${LIBOPENCM3} INTERFACE ${LIBOPENCM3_INCLUDE})
add_dependencies(${LIBOPENCM3} libopencm3-target)

################################################################################
# Export 'libopencm3' library target
################################################################################

set(LIBOPENCM3 ${LIBOPENCM3} PARENT_SCOPE)
