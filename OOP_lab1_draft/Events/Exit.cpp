
#include "Exit.h"

void Exit::playerReact(Player &player) {
    event_observer->exitAction();
    player.setWin();
}

void Exit::addGood(Player &player) {}

Exit::Exit(Log &log_) {
    event_observer = new EventObserver(log_);
}

Exit::~Exit() {
    delete event_observer;
}

void Exit::changeObserver(Log *log_) {
    delete event_observer;
    event_observer = new EventObserver(*log_);
}

