
#ifndef OOP_LAB1_FOODFACTORY_H
#define OOP_LAB1_FOODFACTORY_H

#include "Factory.h"

class FoodFactory : public Factory{
public:
    Event* createEvent(Log &log_) final;
};


#endif //OOP_LAB1_FOODFACTORY_H
