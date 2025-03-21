set(COOLEASE_DEVICE "sensor")
set(FREE "sensor_${CMAKE_BUILD_TYPE}")
set(APP "sensor_app_${CMAKE_BUILD_TYPE}")
set(BOOTLOADER "sensor_bootloader_${CMAKE_BUILD_TYPE}")
set(FREE_LINKER_SCRIPT "freestanding.ld")
set(APP_LINKER_SCRIPT "app.ld")
set(BOOTLOADER_LINKER_SCRIPT "bootloader.ld")
set(SENSOR_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include")

################################################################################
# Sensor common
################################################################################

add_subdirectory(../common ${CMAKE_CURRENT_BINARY_DIR}/common)

set(C_SOURCES "si7051.c" "tmp112.c")

set(C_SOURCES_APP "sensor.c" ${C_SOURCES})
set(C_SOURCES_BOOTLOADER "sensor_bootloader.c" ${C_SOURCES})

################################################################################
# Sensor freestanding
################################################################################

add_executable(${FREE} ${C_SOURCES_APP})

target_include_directories(${FREE} PRIVATE ${SENSOR_INCLUDE})
target_link_libraries(${FREE} PRIVATE ${COMMON_LIB})

target_link_options(${FREE} PUBLIC
  -T${FREE_LINKER_SCRIPT}
  -L${CMAKE_CURRENT_LIST_DIR}/ld
  -L${CMAKE_CURRENT_LIST_DIR}/../config/ld
)

add_custom_target(${FREE}.lss ALL
  DEPENDS $<TARGET_FILE:${FREE}>
  COMMAND ${CMAKE_COMMAND} -E echo "Generating ${FREE}.lss from ${FREE}.elf"
  COMMAND arm-none-eabi-objdump -S $<TARGET_FILE:${FREE}>.elf >
  $<TARGET_FILE:${FREE}>.lss
)

################################################################################
# Sensor app
################################################################################

add_executable(${APP} ${C_SOURCES_APP})

target_include_directories(${APP} PRIVATE ${SENSOR_INCLUDE})
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
# Sensor bootloader
################################################################################

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
