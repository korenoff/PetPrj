
#ifndef OOP_LAB1_BADEVENTS_H
#define OOP_LAB1_BADEVENTS_H

#include "Event.h"

class BadEvents : public Event {
public:
    virtual void remBad(Player &player) = 0;
    void remPoints(Player &player);
};


#endif //OOP_LAB1_BADEVENTS_H
