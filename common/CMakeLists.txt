set(COMMON_LIB "common_${APP}_${CMAKE_BUILD_TYPE}")
set(COMMON_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

file(GLOB C_SOURCES "*.c")
add_library(${COMMON_LIB} STATIC ${C_SOURCES})
target_include_directories(${COMMON_LIB} PUBLIC "${COMMON_INCLUDE}")

################################################################################
# Export
################################################################################

set(COMMON_LIB ${COMMON_LIB} PARENT_SCOPE)
set(COMMON_INCLUDE ${COMMON_INCLUDE} PARENT_SCOPE)
