//
// Created by Wanxi on 2022/2/24.
//

#include "../include/Timer.h"

Timer::Timer(WindowBase* wb, int ID)
{
    hwnd    = wb->getHwnd();
    timerId = ID;
}

Timer::Timer()
{
    hwnd = NULL;
}

Timer::~Timer()
{
    if (timerId != -1)
        KillTimer(hwnd, timerId);
}

bool Timer::startTimer(int ms, TimerProc tp)
{
    if (SetTimer(hwnd, timerId, ms, tp))
        return true;
    errorBox("Timer Init Error");
    return  false;
}

void Timer::setId(int ID)
{
    timerId = ID;
}

void Timer::setParent(WindowBase *wb)
{
    hwnd = wb->getHwnd();
}