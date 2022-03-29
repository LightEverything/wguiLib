//
// Created by Wanxi on 2022/2/24.
//

#include "../include/MouseEventC.h"

MouseEventC::MouseEventC(mouseButtonEnum me, WPARAM wparam, LPARAM lparam)
{
    this->me = me;
    this->x = GET_X_LPARAM(lparam);
    this->y = GET_Y_LPARAM(lparam);
}

MouseEventC::~MouseEventC()
{

}

int MouseEventC::getX()
{
    return this->x;
}

int MouseEventC::getY()
{
    return this->y;
}

mouseButtonEnum MouseEventC::getButton()
{
    return this->me;
}