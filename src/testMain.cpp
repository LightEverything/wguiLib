//
// Created by Wanxi on 2022/2/23.
//

#include "./wguiLib.h"

extern HINSTANCE g_hInstance;

class TestWindow : public WindowBase
{
public:
    TestWindow();
    ~TestWindow() noexcept;
protected:
    virtual void paintEvent() override;
    virtual void mouseButtonEvent(MouseEventC& me) override;
};

TestWindow::TestWindow() : WindowBase()
{

}

TestWindow::~TestWindow() noexcept
{

}

void TestWindow::mouseButtonEvent(MouseEventC &me)
{
    if (me.getButton() == mouseLeftUp)
        printf("this x = %d, this y = %d", me.getX(), me.getY());
    if (me.getButton() == mouseLeftDown)
        printf("this x = %d, this y = %d", me.getX(), me.getY());
}

void TestWindow::paintEvent()
{
    Painter p(this);
    p.drawText(10, 10, L"this is tet");
}

int main(int argc, char** argv)
{
    AllocConsole();
    TestWindow w;
    w.init();
    w.show(argc);

    return programExe();
}
