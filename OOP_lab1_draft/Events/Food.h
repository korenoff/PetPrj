
#ifndef OOP_LAB1_FOOD_H
#define OOP_LAB1_FOOD_H

#include "GoodEvents.h"
#include "../Log/Observers/EventObserver.h"

class Food : public GoodEvents{
private:
    IEventObserver *event_observer;
public:
    Food(Log &log_);
    void playerReact(Player &player) final;
    void addGood(Player& player) final;
    void changeObserver(Log *log_) final;
    ~Food() final;
};


#endif //OOP_LAB1_FOOD_H
