//
// Created by Wanxi on 2022/3/25.
//

#include "Label.h"

int Label::labelID = 1;

Label::Label(WindowBase *parent, const std::string &text, int x, int y, int width, int height):
                parentHwnd(parent->getHwnd()),
                posX(x),
                posY(y),
                width(width),
                height(height)
{
    if (!(hwnd = CreateWindow(TEXT("static"), text.c_str(), WS_CHILD | WS_VISIBLE | SS_LEFT,
                        x, y, width, height,
                        parentHwnd, (HMENU) labelID, (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL)
                                ))
    {
        errorBox("this is error to create box");
    }
    else
    {
        this->ID = labelID;
        labelID++;
    }

}

Label::~Label()
{

}

void Label::setGeometry(int x, int y, int width, int height)
{
    posX = x;
    posY = y;
    this->width = width;
    this->height = height;
    MoveWindow(hwnd, x, y, width, height, true);
}