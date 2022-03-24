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
    PushButton(WindowBase* parent = nullptr,
               const char* buttonText = "",
               int x = 0,
               int y = 0,
               int width = 50,
               int height = 50);

    virtual ~PushButton();

    int getID() const;
    void hide() const;

    // 静态成员变量
    // PushButton不支持自定义ID, 此处使用一个静态成员变量解决ID问题
    static int PushButtonID;
private:
    HWND     hwnd;
    HWND     parentHwnd = NULL;
    WNDCLASS wcs;

    // 窗口属性
    int     posX = 0;
    int     posY = 0;
    int     width = 100;
    int     height = 200;
    char    szWindowClass[255] = "BUTTON";
    // 按钮文字最多255
    char    szButtonText[255] = {};
    // 自身ID
    int     ID = 0;
};

#endif //WGUILIB_H_PUSHBUTTON_H