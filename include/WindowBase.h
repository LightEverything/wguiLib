//
// Created by Wanxin on 2022/2/20/
//

#include <windows.h>
#include <winuser.h>
#include <gdiplus.h>
#include <string.h>
#include "MouseEventC.h"
#include "KeyEventC.h"
#include "func.h"
#include "PushButtonEvent.h"

#ifndef WGUILIB_WINDOWBASE_H
#define WGUILIB_WINDOWBASE_H

// 窗口基类
class WindowBase
{
public:
    // 事件处理函数
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    WindowBase(WindowBase* parent = nullptr);
    virtual ~WindowBase();

    // 注册计数
    static bool registers;

    HWND getHwnd() const;
    bool show(int ncmd  =SW_NORMAL);
    void hide() const;
    void setGeometry(int x, int y, int width, int height);
protected:
    // 事件函数
    virtual void mouseMoveEvent(MouseEventC& me){}
    virtual void keyEvent(KeyEventC& ke){}
    virtual void paintEvent(){}
    virtual void mouseButtonEvent(MouseEventC& me){}
    virtual void buttonClickEvent(PushButtonEvent& pe){}
    virtual void timerEvent(int timerId){}

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
    Gdiplus::GdiplusStartupInput gdiplusInput;
    ULONG_PTR                    gdiplusToken;

    // 初始化函数
    bool init();
};

#endif //WGUILIB_WINDOWBASE_H