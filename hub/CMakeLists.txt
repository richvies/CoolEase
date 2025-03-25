set(C_SOURCES
  "${CMAKE_CURRENT_LIST_DIR}/cusb.c"
  "${CMAKE_CURRENT_LIST_DIR}/sim.c"
  "${CMAKE_CURRENT_LIST_DIR}/w25qxx.c"
)

if(${EXE_TYPE} STREQUAL freestanding OR ${EXE_TYPE} STREQUAL app)
  set(C_SOURCES "${CMAKE_CURRENT_LIST_DIR}/hub.c" ${C_SOURCES})
elseif(${EXE_TYPE} STREQUAL bootloader)
  set(C_SOURCES "${CMAKE_CURRENT_LIST_DIR}/hub_bootloader.c" ${C_SOURCES})
else()
  message(FATAL_ERROR "Dont recognize exe type ${EXE_TYPE}")
endif()

################################################################################
# Export
################################################################################

set(C_SOURCES ${C_SOURCES} PARENT_SCOPE)
set(C_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/include PARENT_SCOPE)
set(LINKER_INCLUDE -L${CMAKE_CURRENT_LIST_DIR}/ld PARENT_SCOPE)

add_executable(${EXE_NAME} ${C_SOURCES})

