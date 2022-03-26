//
// Created by Wanxi on 2022/3/5.
//

#ifndef WGUILIB_PUSHBUTTONEVENT_H
#define WGUILIB_PUSHBUTTONEVENT_H


class PushButtonEvent
{
public:
    PushButtonEvent(int pushButtonID);
    ~PushButtonEvent();

    // 那个按钮
    int which();
private:
    int ID = 0;
};


#endif //WGUILIB_PUSHBUTTONEVENT_H
