#ifndef WGUILIB_H
#define WGUILIB_H

#include <windows.h>

typedef LRESULT CALLBACK (*WINPROCFUN)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

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
protected:
    // 事件函数
    virtual void mouseMoveEvent(){}
    virtual void keyUpEvent(){}
    virtual void keyDownEvent(){}
    virtual void paintEvent(){}
    virtual void mouseButtonEvent(){}
    virtual void mouseDButtonEvent(){}
private:
    HWND hwnd;
    WNDCLASS wcs;

    // 窗口属性
    int posX = 0;
    int posY = 0;
    int width = 300;
    int height = 300;
    char szWindowClass[255] = "WINDOWBASECLASS";
    char szTitle[255] = "New window";
};

#endif