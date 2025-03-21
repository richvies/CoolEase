set(COMMON_LIB "common_${APP}")
set(COMMON_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(${COMMON_LIB} STATIC
  aes.c
  # battery.c
  fake_battery.c
  bootloader_utils.c
  log.c
  memory.c
  printf.c
  reset.c
  # rfm.c
  fake_rfm.c
  timers.c
  syscalls.c
  sysmem.c
  startup.c
)

target_include_directories(${COMMON_LIB} PUBLIC ${COMMON_INCLUDE})

################################################################################
# Link to config
################################################################################

add_subdirectory(../config ${CMAKE_CURRENT_BINARY_DIR}/config)

target_link_libraries(${COMMON_LIB} PUBLIC ${CONFIG_LIB})

# TODO: config requires common headers so must pass back
target_include_directories(${CONFIG_LIB} PRIVATE ${COMMON_INCLUDE})

################################################################################
# Export
################################################################################

set(COMMON_LIB ${COMMON_LIB} PARENT_SCOPE)
