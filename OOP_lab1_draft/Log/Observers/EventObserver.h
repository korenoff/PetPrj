
#ifndef OOP_LAB1_EVENTOBSERVER_H
#define OOP_LAB1_EVENTOBSERVER_H

#include "IEventObserver.h"

class EventObserver : public IEventObserver{
private:
    Log &log;
public:
    explicit EventObserver(Log &log_);
    void enemyAction() final;
    void trapAction() final;
    void foodAction() final;
    void moneyAction() final;
    void exitAction() final;
};


#endif //OOP_LAB1_EVENTOBSERVER_H
