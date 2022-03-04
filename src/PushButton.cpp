//
// Created by Wanxi on 2022/3/3.
//

#include "PushButton.h"
#include "func.h"

PushButton::PushButton(WindowBase *parent, const char *buttonText, int x, int y, int width, int height):
            posX(x),
            posY(y),
            width(width),
            height(height)
{
    // 初始化按钮
    strncpy(szButtonText, buttonText, 255);
    parentHwnd = parent->getHwnd();
    // 创建窗口

    if (!(hwnd = CreateWindowA(szWindowClass, szButtonText, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         posX, posY, this->width, this->height, parentHwnd, NULL,
                         (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL)))
    {
        errorBox("CreateWindow is Error");
    }
}

PushButton::~PushButton()
{

}