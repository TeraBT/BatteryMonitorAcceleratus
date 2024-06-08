#cmake_minimum_required(VERSION 3.28)
#project(BatteryMonitorAcceleratus)
#set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
#set(CMAKE_CXX_STANDARD 20)
#
#include_directories("/home/chris/Qt/6.7.0/gcc_64/include")
#
#
#add_executable(BatteryMonitorAcceleratus
#        main.cpp
#        batterystat.cpp
#)
#


cmake_minimum_required(VERSION 3.28)
project(BatteryMonitorAcceleratus)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64")
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_PREFIX_PATH "/home/chris/Qt/6.7.0/gcc_64")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++-12")
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
set(CMAKE_EXE_LINKER_FLAGS "--static")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
    add_executable(BatteryMonitorAcceleratus WIN32
            Main.cpp
            BatteryStatus.cpp
            NotificationWindow.cpp
            NotificationWindow.h
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    add_executable(BatteryMonitorAcceleratus
            Main.cpp
            BatteryStatus.cpp
            NotificationWindow.cpp
            NotificationWindow.h
    )
endif ()


target_link_libraries(BatteryMonitorAcceleratus PRIVATE Qt6::Core Qt6::Widgets)
