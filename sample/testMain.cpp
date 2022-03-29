//
// Created by Wanxi on 2022/2/23.
//

#include "../include/wguiLib.h"

class TestWindow : public WindowBase
{
public:
    TestWindow();

    ~TestWindow() noexcept;

protected:
//    virtual void keyEvent(KeyEventC& ke) override;
//    virtual void timerEvent(int ID) override;
    virtual void buttonClickEvent(PushButtonEvent& pe) override;
    virtual void paintEvent() override;

private:
    LineEdit lineEdit;
    PushButton pb;
    PushButton pb2;
    Timer timer1;
};

TestWindow::TestWindow() : WindowBase(), lineEdit(this), pb(this, 50, 50, 100, 100, "123"), pb2(this, 100,100, 100, 100, "123123")
{
    lineEdit.setGeometry(20, 20, 200, 25);
}

TestWindow::~TestWindow() noexcept
{

}

//void TestWindow::keyEvent(KeyEventC &ke)
//{
//    if (ke.status() == keyDown)
//        printf("%c\n", ke.getKey());
//}
//
//void TestWindow::timerEvent(int ID)
//{
//    printf("123");
//}
//
void TestWindow::buttonClickEvent(PushButtonEvent &pe)
{
    if (pe.which() == pb.getID())
        pb.hide();
    else if (pe.which() == pb2.getID())
        printf("%s", lineEdit.getTextLine());
}

void TestWindow::paintEvent()
{
    Painter p(this);
    p.drawEllipse(0, 0, 100, 100);
}

int main(int argc, char** argv)
{
    TestWindow w;
    w.show();
    return programExe();
}