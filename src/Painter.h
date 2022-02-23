//
// Created by Wanxi on 2022/2/20
//

#ifndef WGUILIB_PAINTER_H
#define WGUILIB_PAINTER_H

#include <windows.h>
#include <gdiplus.h>
#include <string>
#include <memory>
#include "WindowBase.h"
#include "func.h"

class Painter final
{
public:
    explicit Painter(WindowBase* wBase);
    ~Painter() noexcept;

    // 绘制图形线条
    void drawLine(int x1, int y1, int x2, int y2) ;
    void drawEllipse(int x, int y, int height, int width) ;
    void drawRect(int x, int y, int height, int width) ;

    // 绘制图像
    void drawPicture(int x, int y, const std::wstring& str) ;
    void drawScalePicture(int x, int y, double widthScale, double heightScale, const std::wstring& str) ;
    void drawCutPicture(int x, int y, int showX, int showY, const std::wstring& str) ;

    // 绘制文字
    void drawText(float x, float y, const std::wstring& str);
    void drawRectText(const RectF& rect, const std::wstring& str);
    void drawRectText(float x, float y, float width, float height, const std::wstring& str);

    // 设置
    void setPenColor(const Color& c);
    void setPen(const Pen& p);
    void setFontFamily(const std::wstring& str);
    void setFont(const Font& f);
    void setFontWidth(int width);
    void setTextColor(const Color& c);
    void setTextVertial(bool flag);
    void setStringFormat(const StringFormat& sg);
    void setSolidBrush(const SolidBrush& sb);

private:
    HWND            hwnd;
    HDC             hdc;
    PAINTSTRUCT     ps;
    Graphics        graphics;

    // 由于需要进行拷贝，使用智能指针
    std::shared_ptr<Pen>            pen;
    std::shared_ptr<FontFamily>     fontFamily;
    std::shared_ptr<Font>           font;
    std::shared_ptr<StringFormat>   stringFormat;
    std::shared_ptr<SolidBrush>     solidBrush;
};

#endif //WGUILIB_PAINTER_H