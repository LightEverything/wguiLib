//
// Created by Wanxin on 2022/2/20/
//

#include "Painter.h"

// 画家类的实现
Painter::Painter(const WindowBase* wb)
{
    hwnd = wb->getHwnd();
    hdc = BeginPaint(wb->getHwnd(), &ps);
}

Painter::~Painter()
{
    EndPaint(hwnd, &ps);
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

bool Painter::drawPicture(const char *picturePath)
{

}