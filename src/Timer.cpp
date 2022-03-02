//
// Created by Wanxi on 2022/2/24.
//

#include "Timer.h"

Timer::Timer(WindowBase* wb, int ID)
{
    hwnd    = wb->getHwnd();
    timerId = ID;
}

Timer::Timer()
{

}

Timer::~Timer()
{
    KillTimer(hwnd, timerId);
}

bool Timer::startTimer(int ms)
{
    if (SetTimer(hwnd, timerId, ms, NULL))
        return true;
    errorBox("Timer Init Error");
    return  false;
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