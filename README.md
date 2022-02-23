# wguiLib
这是一个由win32编写的gui库，会逐渐更新滴

此库已经使用c++14重新编写，正在测试之中

***********
1. 介绍：
  * 简单，方便，易用是本库的目的。你可以仅仅只写几行代码，就可以构建出一个完整窗口
  * 零额外依赖。使用为win api，只需要满足winxp之上就可以正常使用。
  * 文件结构简单，将头文件和源文件放入文件夹就可以使用。
  * 支持多窗口显示和控制台Debug
  * 此库只封装了win32 api, 不具备跨平台能力。
2. 使用方法
 * 可以使用main作为入口（下面使用wguiLib整合头作为示例）
  `````cpp
  #include "wguiLib.h"
  
  int main(int argc, char** argv)
  {
    WindowBase w; // 窗口基类
    w.init();    // 在显示之前必须初始化
    w.show(1);   // 显示窗口，1是ncmd，如果用main的话，可以选择argc
    
    return programExe();  // 开启消息循环
  }
  
  `````
  即可创建窗口
  * 建议使用WinMain作为入口(下面使用wguiLib整合头作为示例)
