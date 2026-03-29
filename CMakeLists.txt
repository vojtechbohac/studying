cmake_minimum_required(VERSION 4.2)
project(studying)

set(CMAKE_CXX_STANDARD 20)
enable_language(ASM)

add_executable(studying
        cpp/moving-vs-copying/main.cpp
        cpp/moving-vs-copying/Operations.h)
