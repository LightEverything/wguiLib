//
// Created by Wanxin on 2022/2/20
//

#include "WindowBase.h"

#pragma comment(lib, "Gdiplus.lib")

HINSTANCE     g_hInstance = NULL;

// 初始化静态成员函数
bool WindowBase::registers = false;

// 基类窗口的实现
WindowBase::WindowBase()
{
    // 初始化windowClass
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

    // 如果未注册就注册
    if (!registers)
    {
        init();
        registers = true;
    }

    // 获取窗口句柄
    if (!(hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, szWindowClass,
                             szTitle,
                             WS_OVERLAPPEDWINDOW,  // 样式
                             posX, posY, width, height,  NULL, NULL, g_hInstance, this)))
    {
        errorBox("Get windowsHandle error");
    }

}

WindowBase::~WindowBase()
{
    Gdiplus::GdiplusShutdown(gdiplusToken);
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
    ShowWindow(hwnd, ncmd);
    UpdateWindow(hwnd);
    return true;
}

//
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
    // 定义一个WindowsBase基类
    WindowBase *pThis = nullptr;

    // 初始化pthis;
    if (message == WM_NCCREATE)
    {
        pThis = static_cast<WindowBase*>(reinterpret_cast<CREATESTRUCT*>(lparam)->lpCreateParams);

        SetLastError(0);
        if (!SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis)))
        {
            if (GetLastError() != 0)
                return FALSE;
        }
    }
    else
    {
        // 获取WindowBase指针
        pThis = reinterpret_cast<WindowBase*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (pThis)
    {
        // 匹配message
        switch (message)
        {
            case WM_TIMER:
            {
                int timerId = (int)wparam;
                pThis->timerEvent(timerId);
            }
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            case WM_PAINT:
                pThis->paintEvent();
                break;
            case WM_COMMAND:
            {
                switch (HIWORD(wparam))
                {
                    case BN_CLICKED:
                    {
                        int ID = LOWORD(wparam);
                        PushButtonEvent pe(ID);
                        pThis->buttonClickEvent(pe);
                    }
                }
            }
                break;
                // 同时处理KEYDOWN事件
            case WM_CHAR:
            {
                KeyEventC ke(wparam, keyDown);
                pThis->keyEvent(ke);
            }
                break;
            case WM_KEYUP:
            {
                KeyEventC ke(wparam, keyUp);
                pThis->keyEvent(ke);
            }
                break;
                // 不进行事件重载,功能与WM_CHAR类似
            case WM_KEYDOWN:
                break;
            case WM_MOUSEMOVE:
            {
                MouseEventC me(mouseNoClk, wparam, lparam);
                pThis->mouseMoveEvent(me);
            }
                break;
            case WM_LBUTTONDOWN:
            {
                MouseEventC me(mouseLeftDown, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            case WM_RBUTTONDOWN:
            {
                MouseEventC me(mouseRightDown, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            case WM_LBUTTONUP:
            {
                MouseEventC me(mouseLeftUp, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            case WM_RBUTTONUP:
            {
                MouseEventC me(mouseRightUp, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            case WM_LBUTTONDBLCLK:
            {
                MouseEventC me(mouseLeftDoubleClk, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            case WM_RBUTTONDBLCLK:
            {
                MouseEventC me(mouseRightDoubleClk, wparam, lparam);
                pThis->mouseButtonEvent(me);
            }
                break;
            default:
                return DefWindowProc(hwnd, message, wparam, lparam);
        }
    }
    return DefWindowProc(hwnd, message, wparam, lparam);
}