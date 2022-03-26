//
// Created by Wanxi on 2022/3/26.
//

#ifndef WGUILIB_H_WIDGETBASE_H
#define WGUILIB_H_WIDGETBASE_H


#include <windows.h>
#include <string>
#include "WindowBase.h"

class WidgetBase
{
public:
    // 基类控件
    explicit WidgetBase(const std::string& widgetName,
                        WindowBase* parent,
                        int x, int y,
                        int width, int height,
                        DWORD style,
                        const std::string& text);
    virtual  ~WidgetBase() noexcept;

    void hide()  const;
    void setGeometry(int x, int y, int width, int height);

    int  getPosX()   { return posX;}
    int  getPosY()   { return posY;}
    int  getWidth()  { return width;}
    int  getHeight() { return height;}
    int  getID()     { return thisID;}
    HWND getHwnd()   { return hwnd;}
protected:
    // 防止用户使用WidgetBase
    virtual void canUseThisClass() = 0;
    void init();
    std::string getWidgetName();

    void setPosX(int x)       { posX = x;}
    void setPosY(int y)       { posY = y;}
    void setWidth(int width)  { this->width = width;}
    void setHeight(int height){ this->height = height;}
    void setStyle(DWORD style){ this->style  = style;}
    void setText(const std::string& text)  { this->strText = text;}
private:
    HWND        parentHwnd;
    HWND        hwnd;
    DWORD       style;
    // 类名
    std::string strWindowClass;
    std::string strText;
    int         posX;
    int         posY;
    int         width;
    int         height;
    int         thisID;

    // 控件ID
    static int  widgetID;
};


#endif //WGUILIB_H_WIDGETBASE_H
