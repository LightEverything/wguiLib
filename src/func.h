//
// Created by Wanxin on 2022/2/20/
//

#ifndef WGUILIB_FUNC_H
#define WGUILIB_FUNC_H

#include <windows.h>

void errorBox(const char* textContent);
void debugConsole();
// 启动消息循环
WPARAM programExe();

#endif //WGUILIB_FUNC_H
