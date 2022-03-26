//
// Created by Wanxi on 2022/3/8.
//

#ifndef WGUILIB_H_LINEEDIT_H
#define WGUILIB_H_LINEEDIT_H

#include <windows.h>
#include "WidgetBase.h"
#include "WindowBase.h"

class LineEdit: public WidgetBase
{
public:
    LineEdit(WindowBase* parent,
             int x = 0, int y = 0,
             int width = 200, int height = 25,
             const std::string& text = "");
    virtual ~LineEdit() noexcept;

    const char* getTextLine();

protected:
    virtual void canUseThisClass() override{}
private:
    // 获取行内字
    char    szTextInLine[255];
};

#endif //WGUILIB_H_LINEEDIT_H