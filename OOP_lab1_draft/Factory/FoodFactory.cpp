
#include "FoodFactory.h"

Event *FoodFactory::createEvent(Log &log_) {
    return new Food(log_);
}
