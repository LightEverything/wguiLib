//
// Created by Wanxi on 2022/3/8.
//

#include "LineEdit.h"

LineEdit::LineEdit(WindowBase* parent,
                   int x, int y,
                   int width, int height,
                   const std::string& text):
        WidgetBase("EDIT",
                   parent,
                   x, y,
                   width, height,
                   WS_BORDER | WS_CHILD | WS_VISIBLE  | ES_LEFT,
                   text)
{
    this->init();
}

LineEdit::~LineEdit()
{

}

const char *LineEdit::getTextLine()
{
    // 规定第一个大小
    szTextInLine[0] = 255;
    int nLine = SendMessageA(this->getHwnd(), EM_GETLINE, NULL, (LPARAM) szTextInLine);
    // 补齐最后一个
    this->szTextInLine[nLine] = '\0';

    return this->szTextInLine;
}