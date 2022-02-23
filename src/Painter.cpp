//
// Created by Wanxin on 2022/2/20/
//

#include "Painter.h"

// 变量初始化
Painter::Painter(WindowBase *wBase) :
    hwnd(wBase->getHwnd()),
    hdc(BeginPaint(hwnd, &ps)),
    pen(new Pen(WBLACK)),
    graphics(hdc),
    fontFamily(new FontFamily(L"Arial")),
    font(new Font(fontFamily.get(), 15)),
    solidBrush(new SolidBrush(WBLACK))
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
    Image image(str.c_str());
    graphics.DrawImage(&image, x, y);
}

void Painter::drawScalePicture(
        int x, int y,
        double widthScale, double heightScale,
        const std::wstring &str)
{
    Image image(str.c_str());
    int owidth = image.GetWidth();
    int oheight = image.GetHeight();

    graphics.DrawImage(
            &image, x, y, 0, 0,
            widthScale * owidth, heightScale * owidth, Gdiplus::UnitPixel);
}

void Painter::drawCutPicture(int x, int y, int showX, int showY, const std::wstring &str)
{
    Image image(str.c_str());
    int owidth = image.GetWidth();
    int oheight = image.GetHeight();

    graphics.DrawImage(&image, x, y, showX, showY, owidth, oheight, Gdiplus::UnitPixel);
}

// 绘制文本
void Painter::drawText(float x, float y, const std::wstring &str)
{
    PointF pointF(x, y);
    graphics.DrawString(str.c_str(), -1, font.get(), pointF, solidBrush.get());
}

void Painter::drawRectText(const RectF &frect, const std::wstring &str)
{
    graphics.DrawString(str.c_str(), -1, font.get(),
                        frect, stringFormat.get(), solidBrush.get());
}

void Painter::drawRectText(float x, float y, float width, float height, const std::wstring &str)
{
    RectF frect(x, y, width, height);
    graphics.DrawString(str.c_str(), -1, font.get(),
                        frect, stringFormat.get(), solidBrush.get());
}

// 设置画笔画刷, 封装常用设置
void Painter::setTextColor(const Color &c)
{
    solidBrush->SetColor(c);
}

void Painter::setFontWidth(int width)
{
    pen->SetWidth(width);
}

void Painter::setPenColor(const Color &c)
{
    pen->SetColor(c);
}

void Painter::setTextVertial(bool flag)
{
    if (flag)
        stringFormat->SetFormatFlags(StringFormatFlagsDirectionVertical);
    else
        stringFormat->SetFormatFlags(StringFormatFlagsDisplayFormatControl);
}

// 执行复制
void Painter::setSolidBrush(const SolidBrush &sb)
{
    solidBrush.reset(sb.Clone());
}

void Painter::setStringFormat(const StringFormat &sg)
{
    stringFormat.reset(sg.Clone());
}

void Painter::setPen(const Pen &p)
{
    pen.reset(p.Clone());
}

void Painter::setFont(const Font &f)
{
    font.reset(f.Clone());
}

void Painter::setFontFamily(const std::wstring &str)
{
    fontFamily.reset(new FontFamily(str.c_str()));
}
