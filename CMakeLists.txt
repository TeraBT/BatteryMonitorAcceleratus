cmake_minimum_required(VERSION 3.28)
project(praetor_systematis)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "--static")

add_executable(praetor_systematis
        main.cpp
        batterystat.cpp)

