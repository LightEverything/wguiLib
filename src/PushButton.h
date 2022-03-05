//
// Created by Wanxi on 2022/3/3.
//

#ifndef WGUILIB_H_PUSHBUTTON_H
#define WGUILIB_H_PUSHBUTTON_H

#include <windows.h>
#include "WindowBase.h"

class PushButton
{
public:
    PushButton(WindowBase* parent,
               const char* buttonText = "",
               int x = 0,
               int y = 0,
               int width = 50,
               int height = 50);

    ~PushButton();
private:
    HWND     hwnd;
    HWND     parentHwnd = NULL;
    WNDCLASS wcs;

    // 窗口属性
    int     posX = 0;
    int     posY = 0;
    int     width = 300;
    int     height = 300;
    char    szWindowClass[255] = "BUTTON";
    // 按钮文字最多255
    char    szButtonText[255] = {};
};

#endif //WGUILIB_H_PUSHBUTTON_H
