//
// Created by Wanxin on 2022/2/20/
//

#ifndef WGUILIB_FUNC_H
#define WGUILIB_FUNC_H

#include <windows.h>
#include <cstdio>

// define定义常用颜色
#define WBLACK          Gdiplus::Color(255, 0, 0, 0)
#define WRED            Gdiplus::Color(255, 255, 0, 0)
#define WGREEN			Gdiplus::Color(255, 0, 255, 0)
#define WBLUE			Gdiplus::Color(255, 0, 0, 255)
#define WCYAN			Gdiplus::Color(255, 0, 255, 255)
#define WMAGENTA		Gdiplus::Color(255, 255, 0, 255)
#define WYELLOW			Gdiplus::Color(255, 0, 0, 255)
#define WWHITE			Gdiplus::Color(255, 255, 255, 255)

// 鼠标枚举值
enum    mouseButtonEnum
{
    mouseLeftDown,
    mouseRightDown,
    mouseLeftUp,
    mouseRightUp,
    mouseLeftDoubleClk,
    mouseRightDoubleClk,
    mouseNoClk
};

// 按键枚举值
enum    keyEnum
{
    keyUp,
    keyDown
};

// 错误弹窗
void errorBox(const char* textContent);
// 启动调试窗口
void debugConsole();
// 启动消息循环
WPARAM programExe();

#endif //WGUILIB_FUNC_H
