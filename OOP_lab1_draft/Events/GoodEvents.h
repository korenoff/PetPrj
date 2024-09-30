
#ifndef OOP_LAB1_GOODEVENTS_H
#define OOP_LAB1_GOODEVENTS_H

#include "Event.h"
#include "../Objects/Player.h"

class GoodEvents : public Event {
public:
    virtual void addGood(Player &player) = 0;
    void addPoints(Player &player);
};


#endif //OOP_LAB1_GOODEVENTS_H
