//
// Created by Wanxi on 2022/3/26.
//

#include "../include/WidgetBase.h"

int WidgetBase::widgetID = 0;

WidgetBase::WidgetBase(const std::string &widgetName, WindowBase* parent,
                       int x, int y,
                       int width, int height,
                       DWORD style,
                       const std::string &text) :
                       strWindowClass(widgetName),
                       parentHwnd(parent->getHwnd()),
                       posX(x),
                       posY(y),
                       width(width),
                       height(height),
                       style(style),
                       // 显示文本
                       strText(text)
{

}

WidgetBase::~WidgetBase()
{

}

void WidgetBase::init()
{
    if (!(hwnd = CreateWindowA(strWindowClass.c_str(), strText.c_str(), style,
                               posX, posY, this->width, this->height, parentHwnd, (HMENU)widgetID,
                               (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL)))
    {
        errorBox("this is error to create widget");
    }
    else
    {
        thisID = widgetID;
        widgetID++;
    }
}

void WidgetBase::hide() const
{
    ShowWindow(hwnd, SW_HIDE);
}

void WidgetBase::setGeometry(int x, int y, int width, int height)
{
    posX = x;
    posY = y;
    this->width = width;
    this->height = height;
    MoveWindow(hwnd, x, y, width, height, true);
}