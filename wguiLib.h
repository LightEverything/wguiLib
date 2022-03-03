/* 基于新手的使用方便， 将所有类和文件合并成一个头文件中
 * 但是为了阅读和编写方便同样有分开的， 见src文件夹*/

#ifndef WGUILIB_H
#define WGUILIB_H

// win32API头文件
#include <windows.h>
// 常用过程函数
#include "src/func.h"
// 绘制函数
#include "src/Painter.h"
// 鼠标事件函数
#include "src/MouseEventC.h"
// 窗口基类
#include "src/WindowBase.h"
// 键盘事件函数
#include "src/KeyEventC.h"
// 计时器类
#include "src/Timer.h"
// 按钮类
#include "src/PushButton.h"

#endif