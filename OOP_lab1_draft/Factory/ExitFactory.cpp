
#include "ExitFactory.h"

Event *ExitFactory::createEvent(Log &log_) {
    return new Exit(log_);
}

