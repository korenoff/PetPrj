
#ifndef OOP_LAB1_EXITFACTORY_H
#define OOP_LAB1_EXITFACTORY_H

#include "Factory.h"

class ExitFactory : public Factory{
public:
    Event* createEvent(Log &log_) final;
};


#endif //OOP_LAB1_EXITFACTORY_H

