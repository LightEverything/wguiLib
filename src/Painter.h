//
// Created by Wanxi on 2022/2/23.
//

#ifndef WGUILIB_PAINTER_H
#define WGUILIB_PAINTER_H

#include "WindowBase.h"

class Painter final
{
public:
    Painter(const WindowBase* wb);
    ~Painter();

    //绘制函数
    bool drawLine(int x1, int y1, int x2, int y2);
    bool drawRect(int leftRect, int rightRect, int topRect, int bottomRect);
    // 根据矩形画圆形
    bool drawEllipse(int leftRect, int rightRect, int topRect, int bottomRect);
    bool drawText(int x, int y, const char* textContent);
    // 绘制图形
    bool drawPicture(const char* picturePath);
private:
    PAINTSTRUCT ps;
    HWND        hwnd;
    HDC         hdc;
};

#endif //WGUILIB_PAINTER_H
