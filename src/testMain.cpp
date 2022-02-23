//
// Created by Wanxi on 2022/2/23.
//

#include "WindowBase.h"
#include "Painter.h"
#include "func.h"
#include <gdiplus.h>
#include <cstdio>

extern HINSTANCE g_hInstance;

class TestWindow : public WindowBase
{
public:
    TestWindow();
    ~TestWindow() noexcept;
protected:
    virtual void paintEvent() override;
};

TestWindow::TestWindow() : WindowBase()
{

}

TestWindow::~TestWindow() noexcept
{

}

void TestWindow::paintEvent()
{
    Painter p(this);
    p.drawLine(0, 0, 100, 100);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preInstance, LPSTR lpCmdLine, int ncmd)
{
    g_hInstance = hInstance;

    TestWindow w;
    w.init();
    w.show(ncmd);

    return programExe();
}
