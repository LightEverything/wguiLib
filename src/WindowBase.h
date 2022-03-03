//
// Created by Wanxin on 2022/2/20/
//
#include <windows.h>
#include <gdiplus.h>
#include "MouseEventC.h"
#include "KeyEventC.h"
#include "func.h"

#ifndef WGUILIB_WINDOWBASE_H
#define WGUILIB_WINDOWBASE_H

using namespace Gdiplus;

// 窗口基类
class WindowBase
{
public:
    // 事件处理函数
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    WindowBase();
    virtual ~WindowBase();

    HWND getHwnd() const;
    bool init();
    bool show(int ncmd);
    void setGeometry(int x, int y, int width, int height);
protected:
    // 事件函数
    virtual void mouseMoveEvent(MouseEventC& me){}
    virtual void keyEvent(KeyEventC& ke){}
    virtual void paintEvent(){}
    virtual void mouseButtonEvent(MouseEventC& me){}
    // 计时器还没调好....
    virtual void timerEvent(int timerId){}
    virtual void setTimer(){}

private:
    HWND     hwnd;
    WNDCLASS wcs;

    // 窗口属性
    int     posX = 0;
    int     posY = 0;
    int     width = 300;
    int     height = 300;
    char    szWindowClass[255] = "WINDOWBASECLASS";
    char    szTitle[255] = "New window";

    // GDI
    GdiplusStartupInput gdiplusInput;
    ULONG_PTR           gdiplusToken;
};

#endif //WGUILIB_WINDOWBASE_H