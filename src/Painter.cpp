//
// Created by Wanxin on 2022/2/20/
//

#include "Painter.h"

Painter::Painter(WindowBase *wBase) :
    hwnd(wBase->getHwnd()),
    hdc(BeginPaint(hwnd, &ps)),
    pen(WBLACK),
    graphics(hdc)
{

}

Painter::~Painter()
{
    EndPaint(hwnd, &ps);
}

void Painter::drawLine(int x1, int y1, int x2, int y2)
{
    graphics.DrawLine(&pen, x1, y1, x2, y2);
}

void Painter::drawEllipse(int x, int y, int width, int height)
{
    graphics.DrawEllipse(&pen, x, y, width, height);
}

void Painter::drawRect(int x, int y, int height, int width)
{
    graphics.DrawRectangle(&pen, x, y, height, width);
}

void Painter::drawPicture(int x, int y, const std::wstring &str)
{
    Image image(str.c_str());
    graphics.DrawImage(&image, x, y);
}