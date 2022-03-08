//
// Created by Wanxi on 2022/3/8.
//

#include "LineEdit.h"

int LineEdit::LineEditID = 0;

LineEdit::LineEdit(WindowBase* parent,
                   const char* text,
                   int x, int y,int width, int height)
{
    // 初始化
    parentHwnd = parent->getHwnd();

    // 创建窗口
    if (!(hwnd = CreateWindowA(szWindowClass, text,
                               WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT,
                               posX, posY, this->width, this->height, parentHwnd,
                               (HMENU)LineEditID, (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE), NULL)))
    {
        errorBox("CreateWindow is Error");
    }
    else{
        ID = LineEditID;
        LineEditID++;
    }
}

LineEdit::~LineEdit()
{

}

const char *LineEdit::getTextLine()
{
    // 规定第一个大小
    szTextInLine[0] = 255;
    int nLine = SendMessageA(hwnd, EM_GETLINE, NULL, (LPARAM) szTextInLine);
    // 补齐最后一个
    this->szTextInLine[nLine] = '\0';

    return this->szTextInLine;
}