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
        return true;
    }

    return false;
}

void WindowBase::setGeometry(int x, int y, int width, int height)
{
    posX = x;
    posY = y;
    this->width = width;
    this->height = height;
    return ;
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
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT:
            g_windowBase->paintEvent();
            break;
        case WM_COMMAND:
            break;
        case WM_CHAR:
            break;
        case WM_KEYUP:
            g_windowBase->keyUpEvent();
            break;
        case WM_KEYDOWN:
            g_windowBase->keyDownEvent();
            break;
        case WM_MOUSEMOVE:
            g_windowBase->mouseMoveEvent();
            break;
        case WM_LBUTTONDOWN:
            g_windowBase->mouseButtonEvent();
            break;
        case WM_RBUTTONDOWN:
            g_windowBase->mouseButtonEvent();
            break;
        case WM_LBUTTONUP:
            g_windowBase->mouseButtonEvent();
            break;
        case WM_RBUTTONUP:
            g_windowBase->mouseButtonEvent();
            break;
        case WM_LBUTTONDBLCLK:
            g_windowBase->mouseDButtonEvent();
            break;
        case WM_RBUTTONDBLCLK:
            g_windowBase->mouseDButtonEvent();
            break;
        default:
            return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}