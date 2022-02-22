#include "wguiLib.h"

HINSTANCE     g_hInstance = NULL;
WindowBase*   g_windowBase = NULL;

inline void errorBox(const char* textContent)
{
    MessageBox(NULL, textContent, "ERROR", MB_ICONERROR);
}

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

LRESULT CALLBACK WindowBase::WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
             g_windowBase->paintEvent();
            EndPaint(hwnd, &ps);
        }
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preInstance, LPSTR lpCmdLine, int ncmd)
{
    g_hInstance = hInstance;

    WindowBase w;
    w.init();
    w.show(ncmd);

    return programExe();
}