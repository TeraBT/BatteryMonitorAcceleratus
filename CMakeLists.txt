cmake_minimum_required(VERSION 3.28)
project(BatteryMonitor++)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "--static")

add_executable(BatteryMonitorAcceleratus
        main.cpp
        batterystat.cpp
)

