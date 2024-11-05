cmake_minimum_required(VERSION 3.29)
project(vol_last)

set(CMAKE_CXX_STANDARD 20)

add_executable(vol_last main.cpp
        Memory.cpp
        Machine.h
        Machine.cpp
        ALU.cpp
        CU.cpp
        CPU.cpp
        Register.cpp
        Menu.cpp
        )
