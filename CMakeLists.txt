cmake_minimum_required(VERSION 3.21)
project(wguiLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
link_libraries(-lgdiplus)

add_executable(wguiLib
        ./src/WindowBase.cpp
        ./src/WindowBase.h
        ./src/func.h
        src/testMain.cpp
        src/func.cpp
        src/Painter.cpp
        src/Painter.h
        src/MouseEventC.cpp
        src/MouseEventC.h
        wguiLib.h)