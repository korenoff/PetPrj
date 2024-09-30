
#include "MoneyFactory.h"

Event *MoneyFactory::createEvent(Log &log_) {
    return new Money(log_);
}
