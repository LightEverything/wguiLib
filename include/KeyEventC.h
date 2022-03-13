//
// Created by Wanxi on 2022/2/24.
//

#ifndef WGUILIB_KEYEVENTC_H
#define WGUILIB_KEYEVENTC_H

#include "func.h"

class KeyEventC final
{
public:
    KeyEventC(WPARAM wparam, keyEnum km);
    ~KeyEventC();

    char getKey();
    keyEnum status();
private:
    char key;
    keyEnum upOrDown;
};

#endif //WGUILIB_KEYEVENTC_H