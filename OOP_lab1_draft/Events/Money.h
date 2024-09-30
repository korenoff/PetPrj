
#ifndef OOP_LAB1_MONEY_H
#define OOP_LAB1_MONEY_H

#include "GoodEvents.h"
#include "../Log/Observers/EventObserver.h"


class Money :public GoodEvents{
private:
    IEventObserver *event_observer;
public:
    explicit Money(Log &log_);
    void playerReact(Player &player) final;
    void addGood(Player &player) final;
    void changeObserver(Log *log_) final;
    ~Money() final;
};


#endif //OOP_LAB1_MONEY_H
