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
    virtual void setTimer() override;
    virtual void timerEvent(int ID) override;
private:
    Timer timer1;
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

void TestWindow::setTimer()
{
    timer1.setId(10);
    timer1.setParent(this);
    timer1.startTimer(100);
}

void TestWindow::timerEvent(int ID)
{
    printf("&*&");
}
int main(int argc, char** argv)
{
    TestWindow w;
    w.init();
    w.show(argc);

    return programExe();
}
