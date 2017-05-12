cmake_minimum_required(VERSION 3.7)
project(aliencounter)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -ffast-math")

set(SOURCE_FILES main.c analysis.c analysis.h termite.c termite.h)
add_executable(aliencounter ${SOURCE_FILES})