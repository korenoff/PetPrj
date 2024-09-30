
#include "TrapFactory.h"

Event *TrapFactory::createEvent(Log &log_) {
    return new Trap(log_);
}
