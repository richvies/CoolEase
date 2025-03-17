set(APP "sensor_${CMAKE_BUILD_TYPE}")
set(BOOTLOADER "${APP}_bootloader")
set(DEVICE "stm32l051c8t6")
set(LINKER_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/ld/sensor.ld")
set(BOOTLOADER_LINKER_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/ld/sensor_bootloader.ld")

################################################################################
# sensor sources and linking
################################################################################

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common ${CMAKE_CURRENT_BINARY_DIR}/common)

set(C_SOURCES "si7051.c" "tmp112.c")
set(C_SOURCES_BOOTLOADER "sensor_bootloader.c" ${C_SOURCES})
list(APPEND C_SOURCES "sensor.c")

add_executable(${APP} ${C_SOURCES})
target_include_directories(${APP} PRIVATE "include")
target_include_directories(${APP} PRIVATE ${COMMON_INCLUDE})
target_include_directories(${APP} PRIVATE ${LIBOPENCM3_INCLUDE})
target_link_libraries(${APP} PRIVATE ${COMMON_LIB} libopencm3)
target_link_options(${APP} PRIVATE -T${LINKER_SCRIPT})

add_executable(${BOOTLOADER} ${C_SOURCES_BOOTLOADER})
target_include_directories(${BOOTLOADER} PRIVATE "include")
target_include_directories(${BOOTLOADER} PRIVATE ${COMMON_INCLUDE})
target_include_directories(${BOOTLOADER} PRIVATE ${LIBOPENCM3_INCLUDE})
target_link_libraries(${BOOTLOADER} PRIVATE ${COMMON_LIB} libopencm3)
target_link_options(${BOOTLOADER} PRIVATE -T${BOOTLOADER_LINKER_SCRIPT})

target_include_directories(${COMMON_LIB} PRIVATE "include")
target_include_directories(${COMMON_LIB} PRIVATE ${LIBOPENCM3_INCLUDE})

add_custom_target(${APP}.lss ALL
  DEPENDS $<TARGET_FILE:${APP}>
  COMMAND arm-none-eabi-objdump -S $<TARGET_FILE:${APP}>.elf > $<TARGET_FILE:${APP}>.lss
  COMMENT "Generating ${APP}.lss from ${APP}.elf"
)

add_custom_target(${BOOTLOADER}.lss ALL
  DEPENDS $<TARGET_FILE:${BOOTLOADER}>
  COMMAND arm-none-eabi-objdump -S $<TARGET_FILE:${BOOTLOADER}>.elf > $<TARGET_FILE:${BOOTLOADER}>.lss
  COMMENT "Generating ${BOOTLOADER}.lss from ${BOOTLOADER}.elf"
)
