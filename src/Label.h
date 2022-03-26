//
// Created by Wanxi on 2022/3/25.
//

#ifndef WGUILIB_LABEL_H
#define WGUILIB_LABEL_H

#include <string>
#include "WindowBase.h"

class Label
{
public:
    // wstring构造和string构造
    Label(WindowBase* parent = nullptr,
          const std::string& text = NULL,
          int x = 0, int y = 0,
          int width = 100, int height = 100
          );
//    Label(WindowBase* parent = nullptr,
//          const std::wstring& text = NULL,
//          int x = 0, int y = 0,
//          int width = 100, int height = 100
//          );
    virtual ~Label() noexcept;

    void setGeometry(int x, int y, int width, int height);

    static int labelID;
private:
    HWND parentHwnd = NULL;
    HWND hwnd = NULL;
    int  posX;
    int  posY;
    int  width;
    int  height;
    int  ID = 0;
    char    szWindowClass[255] = "static";
};


#endif //WGUILIB_LABEL_H