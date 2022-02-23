#include "wguiLib.h"

// 全局变量
HINSTANCE     g_hInstance = NULL;
WindowBase*   g_windowBase = NULL;

inline void errorBox(const char* textContent)
{
    MessageBox(NULL, textContent, "ERROR", MB_ICONERROR);
}

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

WindowBase::~WindowBase()
{

}

// 画家类的实现
Painter::Painter(const WindowBase& wb)
{
    hwnd = wb.getHwnd();
    hdc = BeginPaint(wb.getHwnd(), &ps);
}

bool Painter::drawEllipse(int leftRect, int rightRect, int topRect, int bottomRect)
{
    return Ellipse(hdc, leftRect, topRect, rightRect, bottomRect);
}

bool Painter::drawLine(int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL);
    return LineTo(hdc, x2, y2);
}

bool Painter::drawRect(int leftRect, int rightRect, int topRect, int bottomRect)
{
    return Rectangle(hdc, leftRect, topRect, rightRect, bottomRect);
}

Painter::~Painter()
{
    EndPaint(hwnd, &ps);
}

// 启用控制台调试
inline void debugConsole()
{
    AllocConsole();
}

// 启动消息循环
WPARAM programExe()
{
    MSG msg = {0};

    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}