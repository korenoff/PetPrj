
#ifndef OOP_LAB1_IEVENTOBSERVER_H
#define OOP_LAB1_IEVENTOBSERVER_H

#include "../Log.h"

class IEventObserver {
public:
    virtual void enemyAction() = 0;
    virtual void trapAction() = 0;
    virtual void foodAction() = 0;
    virtual void moneyAction() = 0;
    virtual void exitAction() = 0;
    virtual ~IEventObserver() = default;
};


#endif //OOP_LAB1_IEVENTOBSERVER_H
