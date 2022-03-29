//
// Created by Wanxi on 2022/2/24.
//

#include "../include/KeyEventC.h"
KeyEventC::KeyEventC(WPARAM wparam, keyEnum km)
{
    key = char(wparam);
    upOrDown = km;
}

char KeyEventC::getKey()
{
    return key;
}

keyEnum KeyEventC::status()
{
    return upOrDown;
}

KeyEventC::~KeyEventC()
{

}