//
// Created by Wanxin on 2022/2/24.
//

#ifndef WGUILIB_MOUSEEVENTC_H
#define WGUILIB_MOUSEEVENTC_H

#include <windows.h>
#include <windowsx.h>
#include "func.h"

class MouseEventC final
{
public:
    MouseEventC(mouseButtonEnum me, WPARAM wparam, LPARAM lparam);
    ~MouseEventC() noexcept;

    // 数据接口
    int getX();
    int getY();
    mouseButtonEnum getButton();

private:
    int x;
    int y;
    mouseButtonEnum me;
};

#endif //WGUILIB_MOUSEEVENTC_H