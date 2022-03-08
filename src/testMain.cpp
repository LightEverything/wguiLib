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
    LineEdit lineEdit;
    PushButton pb;
    Timer timer1;
};

TestWindow::TestWindow() : WindowBase(), lineEdit(this), pb(this, "123", 50, 50)
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
    printf("%s", lineEdit.getTextLine());
}

int main(int argc, char** argv)
{
    TestWindow w, w1;
    w1.show(argc);

    return programExe();
}