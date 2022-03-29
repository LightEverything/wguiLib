cmake_minimum_required(VERSION 3.21)
project(wguiLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
link_libraries(gdiplus)

add_executable(wguiLib
        ./src/WindowBase.cpp
        sample/testMain.cpp
        src/func.cpp
        src/Painter.cpp
        src/MouseEventC.cpp
        src/KeyEventC.cpp
        src/Timer.cpp
        src/PushButton.cpp
        src/PushButtonEvent.cpp
        src/RichEditor.cpp
        src/LineEdit.cpp
        src/WidgetBase.cpp )