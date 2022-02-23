//
// Created by Wanxin on 2022/2/20/
//
#include <windows.h>
#include "func.h"

#ifndef WGUILIB_WINDOWBASE_H
#define WGUILIB_WINDOWBASE_H

// 窗口基类
class WindowBase
{
public:
    // 事件处理函数
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    WindowBase();
    virtual ~WindowBase();

    bool init();
    bool show(int ncmd);
    void setGeometry(int x, int y, int width, int height);
    HWND getHwnd() const;
protected:
    // 事件函数
    virtual void mouseMoveEvent(){}
    virtual void keyUpEvent(){}
    virtual void keyDownEvent(){}
    virtual void paintEvent(){}
    virtual void mouseButtonEvent(){}
    virtual void mouseDButtonEvent(){}
private:
    HWND     hwnd;
    WNDCLASS wcs;

    // 窗口属性
    int posX = 0;
    int posY = 0;
    int width = 300;
    int height = 300;
    char szWindowClass[255] = "WINDOWBASECLASS";
    char szTitle[255] = "New window";
};

#endif //WGUILIB_WINDOWBASE_H
