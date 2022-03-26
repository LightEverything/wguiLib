//
// Created by Wanxi on 2022/3/3.
//

#ifndef WGUILIB_H_PUSHBUTTON_H
#define WGUILIB_H_PUSHBUTTON_H

#include <windows.h>
#include "WidgetBase.h"
#include "WindowBase.h"

class PushButton : public WidgetBase
{
public:
    PushButton(WindowBase* parent = nullptr,
               int x = 0,
               int y = 0,
               int width = 50,
               int height = 50,
               const std::string& buttonText = "");

    virtual ~PushButton();

protected:
    virtual void canUseThisClass() override{}
private:
};

#endif //WGUILIB_H_PUSHBUTTON_H