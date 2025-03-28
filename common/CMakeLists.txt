set(COMMON_LIB "common_${COOLEASE_DEVICE}_${CMAKE_BUILD_TYPE}")
set(COMMON_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

add_library(${COMMON_LIB} STATIC
  aes.c
  battery.c
  bootloader_utils.c
  log.c
  memory.c
  printf.c
  reset.c
  rfm.c
  timers.c
  syscalls.c
  sysmem.c
  startup.c
)

target_include_directories(${COMMON_LIB} PUBLIC ${COMMON_INCLUDE})

################################################################################
# Export
################################################################################

set(COMMON_LIB ${COMMON_LIB} PARENT_SCOPE)
set(COMMON_INCLUDE ${COMMON_INCLUDE} PARENT_SCOPE)
