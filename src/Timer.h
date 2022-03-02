//
// Created by Wanxi on 2022/2/24.
//

#ifndef WGUILIB_TIMER_H
#define WGUILIB_TIMER_H

#include <windows.h>
#include "WindowBase.h"

// 回调函数别名
using TimerProc = TIMERPROC;

class Timer
{
public:
    Timer();
    Timer(WindowBase* wb, int ID);
    ~Timer() noexcept;

    void setParent(WindowBase* wb);
    void setId(int ID);
    // 开始计时
    bool startTimer(int  ms);
    bool startTimer(int  ms, TimerProc tp);
private:
    int     timerId = -1;
    HWND    hwnd = NULL;
};

#endif //WGUILIB_TIMER_H