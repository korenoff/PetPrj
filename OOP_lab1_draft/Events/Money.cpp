
#include "Money.h"

void Money::addGood(Player &player) {
    player.addPlayerPoints(15);

}

void Money::playerReact(Player &player) {
    event_observer->moneyAction();
    this->addGood(player);
    this->addPoints(player);
    if (player.getPoints() > player.getPointsToWin() and !player.getOpenExit())
        player.setOpenExit();
}

Money::Money(Log &log_) {
    event_observer = new EventObserver(log_);
}

Money::~Money() {
    delete event_observer;
}

void Money::changeObserver(Log *log_) {
    delete event_observer;
    event_observer = new EventObserver(*log_);

}
