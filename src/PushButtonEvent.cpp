//
// Created by Wanxi on 2022/3/5.
//

#include "../include/PushButtonEvent.h"

PushButtonEvent::PushButtonEvent(int pushButtonID)
{
    ID = pushButtonID;
}

PushButtonEvent::~PushButtonEvent()
{

}

int PushButtonEvent::which()
{
    return ID;
}
