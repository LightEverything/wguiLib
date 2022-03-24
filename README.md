# wguiLib
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
    * g++命令行编译：
      ```bash
       g++ -lgdiplus 
      ```
    * cmake 编译工具编译
      ```cmake
      link_libraries(gdiplus) // 在cmakelist.txt 中加入这一句即可
      ```
    * clion 编译  
      直接将clone文件放clion里面打开就可以了  
   
    * devc++ 编译
       1. 将dev-Cpp的 include 文件移动至devc++的 MinGW64/include 内
       2. 将dev-Cpp的 lib 文件移动至devc++的 MinGW64/lib 内   
         (操作完前面两步，以后就可以直接从第三步开始)
       4. 用dev-Cpp创建新项目
       ![新建项目](https://github.com/LightEverything/wguiLib/blob/main/resource/dev_cpp_get1.png)
       6. 右键点开项目属性\参数\链接器，添加  
         ```g++
       -lwgui -lgdiplus
         ```   
          
          
          
          
          
       ![项目属性](https://github.com/LightEverything/wguiLib/blob/main/resource/dev_cpp_get2.png)  
       
       ![添加引用](https://github.com/LightEverything/wguiLib/blob/main/resource/dev_cpp_get3.png)

    * vscode 编译  
   
      
   
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
   http://120.27.213.171/2022/03/14/wguiLib-%E4%BD%BF%E7%94%A8%E6%96%87%E6%A1%A3/
