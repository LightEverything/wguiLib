//
// Created by Wanxi on 2022/2/23.
//

#include "WindowBase.h"
#include "Painter.h"
#include "func.h"
#include <gdiplus.h>

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
    p.drawText(10, 10, L"this is Text");
}

int main(int argc, char** argv)
{
    TestWindow w;
    w.init();
    w.show(argc);

    return programExe();
}
