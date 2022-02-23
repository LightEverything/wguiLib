/* 基于新手的使用方便， 将所有类和实现文件放在两个文件中
 * 但是为了阅读和编写方便同样有分开的， 见src文件夹*/

#ifndef WGUILIB_H
#define WGUILIB_H

#include <windows.h>

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

// 绘图类
class Painter final
{
public:
    Painter(const WindowBase& wb);
    ~Painter();

    //绘制函数
    bool drawLine(int x1, int y1, int x2, int y2);
    bool drawRect(int leftRect, int rightRect, int topRect, int bottomRect);
    // 根据矩形画圆形
    bool drawEllipse(int leftRect, int rightRect, int topRect, int bottomRect);
    bool drawText(int x, int y, const char* textContent);
    bool drawPicture(const char* picturePath);
private:
    PAINTSTRUCT ps;
    HWND        hwnd;
    HDC         hdc;
};

#endif