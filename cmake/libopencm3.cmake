set(LIBOPENCM3_DIR "${CMAKE_CURRENT_LIST_DIR}/../libopencm3")
set(LIBOPENCM3_INCLUDE "${LIBOPENCM3_DIR}/include")
set(LIBOPENCM3_LIB_NAME "libopencm3_stm32l0.a")
set(LIBOPENCM3_LIB_PATH "${CMAKE_BINARY_DIR}/libopencm3/${LIBOPENCM3_LIB_NAME}")

################################################################################
# libopencm3 build command
################################################################################

add_custom_command(
  OUTPUT ${LIBOPENCM3_LIB_PATH}
  COMMAND ${CMAKE_COMMAND} -E echo "Building libopencm3 for STM32L0"
  COMMAND cd "${CMAKE_CURRENT_LIST_DIR}/../libopencm3" && make TARGETS=stm32/l0
  COMMAND mv "${LIBOPENCM3_DIR}/lib/${LIBOPENCM3_LIB_NAME}" ${LIBOPENCM3_LIB_PATH}
)
add_custom_target("libopencm3-target" DEPENDS ${LIBOPENCM3_LIB_PATH})

################################################################################
# import library and export as normal cmake target
################################################################################

add_library(libopencm3-import STATIC IMPORTED)
set_target_properties(libopencm3-import PROPERTIES
  IMPORTED_LOCATION ${LIBOPENCM3_LIB_PATH}
)
target_include_directories(libopencm3-import INTERFACE ${LIBOPENCM3_INCLUDE})
add_dependencies(libopencm3-import "libopencm3-target")

add_library(libopencm3 INTERFACE)
target_link_libraries(libopencm3 INTERFACE libopencm3-import)
