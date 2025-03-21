set(COOLEASE_DEVICE "hub")
set(APP "hub_${CMAKE_BUILD_TYPE}")
set(BOOTLOADER "${APP}_bootloader")
set(DEVICE "stm32l051c8t6")
set(LINKER_SCRIPT "freestanding.ld")
set(APP_LINKER_SCRIPT "app.ld")
set(BOOTLOADER_LINKER_SCRIPT "bootloader.ld")
set(HUB_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

################################################################################
# Hub common
################################################################################

add_subdirectory(../common ${CMAKE_CURRENT_BINARY_DIR}/common)

set(C_SOURCES "cusb.c" "sim.c" "w25qxx.c")

# TODO: common requires cusb headers so must pass back
target_include_directories(${COMMON_LIB} PRIVATE ${HUB_INCLUDE})

################################################################################
# Hub app
################################################################################

set(C_SOURCES_APP "hub.c" ${C_SOURCES})
add_executable(${APP} ${C_SOURCES_APP})

target_include_directories(${APP} PRIVATE ${HUB_INCLUDE})
target_link_libraries(${APP} PRIVATE ${COMMON_LIB})
target_link_options(${APP} PUBLIC
  -T${APP_LINKER_SCRIPT}
  -L${CMAKE_CURRENT_LIST_DIR}/ld
  -L${CMAKE_CURRENT_LIST_DIR}/../config/ld
)

add_custom_target(${APP}.lss ALL
  DEPENDS $<TARGET_FILE:${APP}>
  COMMAND ${CMAKE_COMMAND} -E echo "Generating ${APP}.lss from ${APP}.elf"
  COMMAND arm-none-eabi-objdump -S $<TARGET_FILE:${APP}>.elf >
  $<TARGET_FILE:${APP}>.lss
)

################################################################################
# Hub bootloader
################################################################################

set(C_SOURCES_BOOTLOADER "hub_bootloader.c" ${C_SOURCES})
add_executable(${BOOTLOADER} ${C_SOURCES_BOOTLOADER})

target_include_directories(${BOOTLOADER} PRIVATE ${HUB_INCLUDE})
target_link_libraries(${BOOTLOADER} PRIVATE ${COMMON_LIB})
target_link_options(${BOOTLOADER} PUBLIC
  -T${BOOTLOADER_LINKER_SCRIPT}
  -L${CMAKE_CURRENT_LIST_DIR}/ld
  -L${CMAKE_CURRENT_LIST_DIR}/../config/ld
)

add_custom_target(${BOOTLOADER}.lss ALL
  DEPENDS $<TARGET_FILE:${BOOTLOADER}>
  COMMAND ${CMAKE_COMMAND} -E echo "Generating ${BOOTLOADER}.lss from ${BOOTLOADER}.elf"
  COMMAND arm-none-eabi-objdump -S $<TARGET_FILE:${BOOTLOADER}>.elf >
  $<TARGET_FILE:${BOOTLOADER}>.lss
)
