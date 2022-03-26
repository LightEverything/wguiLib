cmake_minimum_required(VERSION 3.21)
project(wguiLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "D:/clion/CLion 2021.3/bin/mingw/bin/g++.exe")

include_directories(.)
link_libraries(gdiplus)

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
        src/wguiLib.h src/KeyEventC.cpp src/KeyEventC.h src/Timer.cpp src/Timer.h src/PushButton.cpp src/PushButton.h src/PushButtonEvent.cpp src/PushButtonEvent.h src/RichEditor.cpp src/RichEditor.h src/LineEdit.cpp src/LineEdit.h src/WidgetBase.cpp src/WidgetBase.h)