//
// Created by Wanxi on 2022/2/23.
//

#include "./wguiLib.h"

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
    PushButton pushButton;
    PushButton pushButton1;
};

TestWindow::TestWindow() : WindowBase(), pushButton(this),
    pushButton1(this, "123", 20, 20, 100, 1000)
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
    WindowBase w2;
    TestWindow w, w1;
    w.show(argc);
    w1.show(argc);

    return programExe();
}
