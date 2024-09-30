
#include "Trap.h"

void Trap::remBad(Player &player) {
    player.remPlayerProtection(10);
}

void Trap::playerReact(Player &player) {
    event_observer->trapAction();
    this->remBad(player);
    this->remPoints(player);
    if (player.getHealth() < 1 or player.getPoints() < 1 or player.getProtection() < 1)
        player.setDead();
}

Trap::Trap(Log &log_) {
    event_observer = new EventObserver(log_);
}

Trap::~Trap() {
    delete event_observer;
}

void Trap::changeObserver(Log *log_) {
    delete event_observer;
    event_observer = new EventObserver(*log_);
}