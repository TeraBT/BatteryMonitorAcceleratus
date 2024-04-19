cmake_minimum_required(VERSION 3.28)
project(praetor_systematis)

set(CMAKE_CXX_STANDARD 20)

add_executable(praetor_systematis
        main.cpp
        batterystat.cpp)
