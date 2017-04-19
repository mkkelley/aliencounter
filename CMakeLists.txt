cmake_minimum_required(VERSION 3.7)
project(aliencounter)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c analysis.c analysis.h termite.c termite.h)
add_executable(aliencounter ${SOURCE_FILES})