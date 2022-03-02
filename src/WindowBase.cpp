//
// Created by Wanxin on 2022/2/20
//

#include "WindowBase.h"

#pragma comment(lib, "Gdiplus.lib")

HINSTANCE     g_hInstance = NULL;
WindowBase*   g_windowBase = NULL;

// 基类窗口的实现
WindowBase::WindowBase()
{
    // 初始化并且注册
    g_windowBase = this;
    wcs.style          = CS_HREDRAW | CS_VREDRAW;
    wcs.lpfnWndProc    = WinProc;
    wcs.cbClsExtra     = 0;
    wcs.cbWndExtra     = 0;
    wcs.hInstance      = g_hInstance;
    wcs.hIcon          = 0;
    wcs.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcs.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcs.lpszMenuName   = 0;
    wcs.lpszClassName  = this->szWindowClass;
    // 初始化GDI
    GdiplusStartup(&gdiplusToken, &gdiplusInput, NULL);
}

WindowBase::~WindowBase()
{
    GdiplusShutdown(gdiplusToken);
}

// 初始化函数
bool WindowBase::init()
{
    if (!RegisterClassA(&this->wcs))
    {
        errorBox("Register your Window hava problem");
        return false;
    }

    return true;
}

bool WindowBase::show(int ncmd)
{
    if (hwnd = CreateWindowA(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, posX, posY, width, height, NULL, NULL, 0, NULL))
    {
        ShowWindow(hwnd, ncmd);
        UpdateWindow(hwnd);
        setTimer();
        return true;
    }

    errorBox("Show Windows Error");
    return false;
}

void WindowBase::setGeometry(int x, int y, int width, int height)
{
    posX = x;
    posY = y;
    this->width = width;
    this->height = height;
    MoveWindow(hwnd, x, y, width, height, true);
}

// 获取窗口句柄
HWND WindowBase::getHwnd() const
{
    return this->hwnd;
}

// win的消息处理函数
LRESULT CALLBACK WindowBase::WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
        case WM_TIMER:
        {
            int timerId = wparam;
            g_windowBase->timerEvent(timerId);
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT:
            g_windowBase->paintEvent();
            break;
        case WM_COMMAND:
            break;
        // 同时处理KEYDOWN事件
        case WM_CHAR:
        {
            KeyEventC ke(wparam, keyDown);
            g_windowBase->keyEvent(ke);
        }
            break;
        case WM_KEYUP:
        {
            KeyEventC ke(wparam, keyUp);
            g_windowBase->keyEvent(ke);
        }
            break;
        // 不进行事件重载,功能与WM_CHAR类似
        case WM_KEYDOWN:
            break;
        case WM_MOUSEMOVE:
        {
            MouseEventC me(mouseNoClk, wparam, lparam);
            g_windowBase->mouseMoveEvent(me);
        }
            break;
        case WM_LBUTTONDOWN:
        {
            MouseEventC me(mouseLeftDown, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        case WM_RBUTTONDOWN:
        {
            MouseEventC me(mouseRightDown, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        case WM_LBUTTONUP:
        {
            MouseEventC me(mouseLeftUp, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        case WM_RBUTTONUP:
        {
            MouseEventC me(mouseRightUp, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        case WM_LBUTTONDBLCLK:
        {
            MouseEventC me(mouseLeftDoubleClk, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        case WM_RBUTTONDBLCLK:
        {
            MouseEventC me(mouseRightDoubleClk, wparam, lparam);
            g_windowBase->mouseButtonEvent(me);
        }
            break;
        default:
            return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}