# wguiLib

1.	将Win32窗口的绘制分成注册窗口，渲染窗口，消息循环三个部分进行处理
2.	对注册窗口的各种属性用宏进行替代，实现对系统级Win32 API的隔离。将窗口和消息使用OOP思想封装成窗口类和事件类，渲染窗口和消息传递均在类中处理，对用户透明且便于修改。在消息循环中遍历所有构造的基类的虚函数，如果用户重载了虚函数即可实现对应功能。
3.	库风格类Qt，对用户来说隐藏了系统级Win32 API的调用，便于用户的编写和使用。

这是一个由win32编写的gui库，会逐渐更新滴

此库已经使用c++14重新编写，正在测试之中 

注：wguiLib整合头更新通常比src要慢一些

***********

1. 介绍：
   
   * 简单，方便，易用是本库的目的。你可以仅仅只写几行代码，就可以构建出一个完整窗口
   * 零额外依赖。使用为win api，只需要满足winxp之上就可以正常使用。
   * 文件结构简单，将头文件和源文件放入文件夹就可以使用。
   * 支持多窗口显示和控制台Debug
   * 此库只封装了win32 api, 不具备跨平台能力。  

2. 环境搭建  
   
   * g++命令行编译(在根目录中)：
     
     ```bash
      g++ -L .\lib -lgdiplus -lwgui <你的源文件>
     ```
   
   * cmake 编译工具编译:
     
     ```cmake
     link_libraries(gdiplus) // 在cmakelist.txt 中加入这一句即可
     ```
   
   * clion 编译  
     直接将clone文件放clion里面打开就可以了  
   
   * devc++ 编译 
     
     1. 将 include 文件移动至devc++的 MinGW64/include 内
     
     2. 将 lib 文件移动至devc++的 MinGW64/lib 内  
        (操作完前面两步，以后就可以直接从第三步开始)
     
     3. 用dev-Cpp创建新项目
     
     4. 右键点开项目属性\参数\链接器，添加
     
     ```g++
     -lwgui -lgdiplus
     ```
   
   * vscode编译
     
     方法一：
     
     - 在vscode中打开项目文件夹
     
     - 新建终端，执行g++编译命令
       
       ```bash
       g++ -o out.exe .\sample\testMain.cpp -L.\lib\ -lwgui -lgdiplus
       ```
     
     方法二：CMake
     
     - 在vscode中安装CMake及CMake Tools这两个扩展，按要求重启vscode以激活扩展
     - 打开项目文件夹，此时会自动识别CMakeLists.txt文件
     - 按要求选择编译器
     - 在下方状态栏中点击build按钮即可构建项目
       
       

3. 使用方法 
   
   * 可以使用main作为入口（下面使用wguiLib整合头作为示例）  
     
     ```c++
     #include "wguiLib.h"
     
     int main(int argc, char** argv)
     {
      WindowBase w;   // 注册窗口基类
      w.show(argc);   // 展示窗口
      return programExe(); // 开始消息循环
     }
     ```
     
     * 建议使用WinMain作为入口(下面使用wguiLib整合头作为示例)

4. 具体文档请看   
   http://120.27.213.171/2022/03/14/wguiLib%E6%95%99%E7%A8%8B/
