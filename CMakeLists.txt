cmake_minimum_required(VERSION 3.16)

project(bc-tools C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS YY_NO_UNISTD_H)
endif()

add_library(libbc STATIC
  lib/getopt.c
  lib/getopt1.c
  lib/vfprintf.c
  lib/number.c
)

target_include_directories(libbc
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/h
)

add_executable(bc
  bc/main.c
  bc/bc.c
  bc/scan.c
  bc/execute.c
  bc/load.c
  bc/storage.c
  bc/util.c
  bc/global.c
  bc/warranty.c
)

target_include_directories(bc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/bc
    ${CMAKE_CURRENT_SOURCE_DIR}/h
)

target_link_libraries(bc PRIVATE libbc)

add_executable(dc
  dc/dc.c
  dc/input.c
  dc/misc.c
  dc/eval.c
  dc/stack.c
  dc/array.c
  dc/numeric.c
  dc/string.c
)

target_include_directories(dc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/dc
    ${CMAKE_CURRENT_SOURCE_DIR}/h
)

target_link_libraries(dc PRIVATE libbc)

if(UNIX AND NOT APPLE)
  target_link_libraries(bc PRIVATE m)
  target_link_libraries(dc PRIVATE m)
endif()
