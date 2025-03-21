set(COOLEASE_DEVICE "sensor")
set(APP "sensor_${CMAKE_BUILD_TYPE}")
set(BOOTLOADER "${APP}_bootloader")
set(DEVICE "stm32l051c8t6")
set(LINKER_SCRIPT "freestanding.ld")
set(APP_LINKER_SCRIPT "app.ld")
set(BOOTLOADER_LINKER_SCRIPT "bootloader.ld")
set(SENSOR_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

################################################################################
# Sensor common
################################################################################

add_subdirectory(../common ${CMAKE_CURRENT_BINARY_DIR}/common)

set(C_SOURCES "si7051.c" "tmp112.c")

################################################################################
# Sensor app
################################################################################

set(C_SOURCES_APP "sensor.c" ${C_SOURCES})
add_executable(${APP} ${C_SOURCES_APP})

target_include_directories(${APP} PRIVATE ${SENSOR_INCLUDE})
target_link_libraries(${APP} PRIVATE ${COMMON_LIB})
target_link_options(${APP} PRIVATE -T${APP_LINKER_SCRIPT})

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
# Sensor bootloader
################################################################################

set(C_SOURCES_BOOTLOADER "sensor_bootloader.c" ${C_SOURCES})
add_executable(${BOOTLOADER} ${C_SOURCES_BOOTLOADER})

target_include_directories(${BOOTLOADER} PRIVATE ${SENSOR_INCLUDE})
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
