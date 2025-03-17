cmake_minimum_required(VERSION 3.16)
project(CoolEase)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET>.elf -Wl,--start-group <LINK_LIBRARIES> -lc -lgcc -lnosys -Wl,--end-group -Wl,-Map=<TARGET>.map")

add_subdirectory(sensor)
add_subdirectory(hub)
