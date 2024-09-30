
#include "EnemyFactory.h"

Event *EnemyFactory::createEvent(Log &log_) {
    return new Enemy(log_);
}
