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
    virtual void keyEvent(KeyEventC& ke) override;
};

TestWindow::TestWindow() : WindowBase()
{

}

TestWindow::~TestWindow() noexcept
{

}

void TestWindow::keyEvent(KeyEventC &ke)
{
    if (ke.status() == keyDown)
        printf("%c\n", ke.getKey());
}

int main(int argc, char** argv)
{
    TestWindow w;
    w.init();
    w.show(argc);

    return programExe();
}
