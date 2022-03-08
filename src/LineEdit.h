//
// Created by Wanxi on 2022/3/8.
//

#ifndef WGUILIB_H_LINEEDIT_H
#define WGUILIB_H_LINEEDIT_H

#include <windows.h>
#include "WindowBase.h"

class LineEdit
{
public:
    LineEdit(WindowBase* parent,
             const char* text = "",
             int x = 0, int y = 0,
             int width = 0, int height = 0);
    ~LineEdit();

    const char* getTextLine();

    // ID静态成员变量
    static int LineEditID;

private:
    HWND     hwnd;
    HWND     parentHwnd = NULL;
    WNDCLASS wcs;

    // 窗口属性
    int     posX = 0;
    int     posY = 0;
    int     width = 300;
    int     height = 30;
    int     ID;
    char    szWindowClass[255] = "EDIT";
    char    szTextInLine[255];
};

#endif //WGUILIB_H_LINEEDIT_H