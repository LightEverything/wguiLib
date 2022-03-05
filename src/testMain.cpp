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
    virtual void timerEvent(int ID) override;
    virtual void buttonClickEvent(PushButtonEvent& pe) override;
private:
    Timer timer1;
    PushButton pushButton;
    PushButton pushButton1;
};

TestWindow::TestWindow() : WindowBase(), pushButton(this), timer1(this, 1), pushButton1(this, "123", 20, 20, 100, 100)
{
    timer1.startTimer(1000);
    SetTimer(this->getHwnd(), 10, 1000, NULL);
}

TestWindow::~TestWindow() noexcept
{

}

void TestWindow::keyEvent(KeyEventC &ke)
{
    if (ke.status() == keyDown)
        printf("%c\n", ke.getKey());
}

void TestWindow::timerEvent(int ID)
{
    printf("123");
}

void TestWindow::buttonClickEvent(PushButtonEvent &pe)
{
    if (pe.which() == pushButton.getID())
    {
        printf("123");
    }
    else if (pe.which() == pushButton1.getID())
    {
        printf("456");
    }
}

int main(int argc, char** argv)
{
    TestWindow w;
    w.show(argc);

    return programExe();
}
