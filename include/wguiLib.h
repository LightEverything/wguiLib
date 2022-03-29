/* 基于新手的使用方便， 将所有类和文件合并成一个头文件中
 * 但是为了阅读和编写方便同样有分开的， 见src文件夹*/

#ifndef WGUILIB_H
#define WGUILIB_H

// win32API头文件
#include <windows.h>
// 常用过程函数
#include "../include/func.h"
// 绘制函数
#include "../include/Painter.h"
// 鼠标事件函数
#include "../include//MouseEventC.h"
// 窗口基类
#include "../include/WindowBase.h"
// 键盘事件函数
#include "../include/KeyEventC.h"
// 计时器类
#include "../include/Timer.h"
// 按钮类
#include "../include/PushButton.h"
// 行编辑类
#include "../include/LineEdit.h"
// 静态控件
#include "../include/Label.h"

#endif