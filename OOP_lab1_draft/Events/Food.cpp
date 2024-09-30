
#include "Food.h"

void Food::addGood(Player &player) {
    player.addPlayerHealth(1);
    player.addPlayerPoints(10);
}

void Food::playerReact(Player &player) {
    event_observer->foodAction();
    this->addGood(player);
    this->addPoints(player);
    if (player.getPoints() > player.getPointsToWin() and !player.getOpenExit())
        player.setOpenExit();
}

Food::Food(Log &log_) {
    event_observer = new EventObserver(log_);
}

Food::~Food() {
    delete event_observer;
}

void Food::changeObserver(Log *log_) {
    delete event_observer;
    event_observer = new EventObserver(*log_);
}
