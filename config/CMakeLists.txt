set(CONFIG_LIB "config_${COOLEASE_DEVICE}_${CMAKE_BUILD_TYPE}")
set(CONFIG_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(${CONFIG_LIB} STATIC board_defs.c)
target_include_directories(${CONFIG_LIB} PUBLIC ${CONFIG_INCLUDE})

################################################################################
# Export
################################################################################

set(CONFIG_LIB ${CONFIG_LIB} PARENT_SCOPE)
set(CONFIG_INCLUDE ${CONFIG_INCLUDE} PARENT_SCOPE)
