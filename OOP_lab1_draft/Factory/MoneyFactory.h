
#ifndef OOP_LAB1_MONEYFACTORY_H
#define OOP_LAB1_MONEYFACTORY_H

#include "Factory.h"

class MoneyFactory : public Factory{
public:
    Event* createEvent(Log &log_) final;
};


#endif //OOP_LAB1_MONEYFACTORY_H
