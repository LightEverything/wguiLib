//
// Created by Wanxin on 2022/2/20/
//

#include "../include/Painter.h"

// 变量初始化
Painter::Painter(WindowBase *wBase) :
    hwnd(wBase->getHwnd()),
    hdc(BeginPaint(hwnd, &ps)),
    pen(new Gdiplus::Pen(WBLACK)),
    graphics(hdc),
    fontFamily(L"Arial"),
    fontSize(10),
    stringFormat(new Gdiplus::StringFormat()),
    solidBrush(new Gdiplus::SolidBrush(WBLACK))
{
}

Painter::~Painter()
{
    EndPaint(hwnd, &ps);
}

// 绘制图形
void Painter::drawLine(int x1, int y1, int x2, int y2 )
{
    graphics.DrawLine(pen.get(), x1, y1, x2, y2);
}

void Painter::drawEllipse(int x, int y, int width, int height)
{
    graphics.DrawEllipse(pen.get(), x, y, width, height);
}

void Painter::drawRect(int x, int y, int height, int width)
{
    graphics.DrawRectangle(pen.get(), x, y, height, width);
}

// 绘制图片
void Painter::drawPicture(int x, int y, const std::wstring &str)
{
    Gdiplus::Image image(str.c_str());
    graphics.DrawImage(&image, x, y);
}

void Painter::drawScalePicture(
        int x, int y,
        double widthScale, double heightScale,
        const std::wstring &str)
{
    Gdiplus::Image image(str.c_str());
    int owidth = image.GetWidth();
    int oheight = image.GetHeight();

    graphics.DrawImage(
            &image, x, y, 0, 0,
            widthScale * owidth, heightScale * owidth, Gdiplus::UnitPixel);
}

void Painter::drawCutPicture(int x, int y, int showX, int showY, const std::wstring &str)
{
    Gdiplus::Image image(str.c_str());
    int owidth = image.GetWidth();
    int oheight = image.GetHeight();

    graphics.DrawImage(&image, x, y, showX, showY, owidth, oheight, Gdiplus::UnitPixel);
}

// 绘制文本
void Painter::drawText(float x, float y, const std::wstring &str)
{
    Gdiplus::PointF pointF(x, y);
    Gdiplus::FontFamily fF(fontFamily.c_str());
    Gdiplus::Font font(&fF, fontSize);
    graphics.DrawString(str.c_str(), -1, &font, pointF, solidBrush.get());
}

void Painter::drawRectText(const Gdiplus::RectF &frect, const std::wstring &str)
{
    Gdiplus::FontFamily fF(fontFamily.c_str());
    Gdiplus::Font font(&fF, fontSize);
    graphics.DrawString(str.c_str(), -1, &font,
                        frect, stringFormat.get(), solidBrush.get());
}

void Painter::drawRectText(float x, float y, float width, float height, const std::wstring &str)
{
    Gdiplus::FontFamily fF(fontFamily.c_str());
    Gdiplus::RectF frect(x, y, width, height);
    Gdiplus::Font font(&fF, fontSize);
    graphics.DrawString(str.c_str(), -1, &font,
                        frect, stringFormat.get(), solidBrush.get());
}

// 设置画笔画刷, 封装常用设置
void Painter::setTextColor(const Gdiplus::Color &c)
{
    solidBrush->SetColor(c);
}

void Painter::setPenWidth(int width)
{
    pen->SetWidth(width);
}

void Painter::setPenColor(const Gdiplus::Color &c)
{
    pen->SetColor(c);
}

// 设置字体朝向，true是垂直，false是水平
void Painter::setTextVertial(bool flag)
{
    if (flag)
        stringFormat->SetFormatFlags(Gdiplus::StringFormatFlagsDirectionVertical);
    else
        stringFormat->SetFormatFlags(0x0);
}

void Painter::setTextWidth(int size)
{
    fontSize = size;
}

void Painter::setFontFamily(const std::wstring &str)
{
    fontFamily = str;
}

// 执行复制
void Painter::setSolidBrush(const Gdiplus::SolidBrush &sb)
{
    solidBrush.reset(sb.Clone());
}

void Painter::setStringFormat(const Gdiplus::StringFormat &sg)
{
    stringFormat.reset(sg.Clone());
}

void Painter::setPen(const Gdiplus::Pen &p)
{
    pen.reset(p.Clone());
}
