//
// Created by Wanxi on 2022/3/3.
//

#include "PushButton.h"
#include "func.h"


PushButton::PushButton(WindowBase *parent, int x, int y, int width, int height, const std::string& buttonText):
        WidgetBase("BUTTON",
                   parent,
                   x, y,
                   width, height,
                   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                   buttonText)
{
    // 创建窗口
    this->init();
}

PushButton::~PushButton()
{

}