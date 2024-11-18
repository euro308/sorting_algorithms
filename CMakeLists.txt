cmake_minimum_required(VERSION 3.29)
project(calculator_header_files C)

set(CMAKE_C_STANDARD 23)

add_executable(calculator_header_files main.c
        sorting.h
        sorting.c
)
