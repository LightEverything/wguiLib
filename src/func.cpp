//
// Created by Wanxin on 2022/2/20
//

#include "func.h"

// 启动消息循环
WPARAM programExe()
{
    MSG msg = {0};

    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

void errorBox(const char* textContent)
{
    MessageBox(NULL, textContent, "ERROR", MB_ICONERROR);
}

// 启用控制台调试
void debugConsole()
{
    AllocConsole();
}
