//
// Created by Wanxi on 2022/2/20
//

#ifndef WGUILIB_PAINTER_H
#define WGUILIB_PAINTER_H

#include <windows.h>
#include <gdiplus.h>
#include <string>
#include "WindowBase.h"
#include "func.h"

class Painter final
{
public:
    Painter(WindowBase* wBase);
    ~Painter();

    void drawLine(int x1, int y1, int x2, int y2);
    void drawEllipse(int x, int y, int height, int width);
    void drawRect(int x, int y, int height, int width);
    void drawPicture(int x, int y, const std::wstring& str);
private:
    HWND            hwnd;
    HDC             hdc;
    Pen             pen;
    PAINTSTRUCT     ps;
    Graphics        graphics;
};

#endif //WGUILIB_PAINTER_H
