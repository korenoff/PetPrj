
#include "PlayerObserver.h"

void PlayerObserver::changedPoints(int points) {
    std::string str;
    str = "[TRACE] Player's points changed. Now there are " + std::to_string(points) + " points.";
    Message message = Message(str, Level::TRACE);
    log.viewMessage(message);
}

void PlayerObserver::changedProtection(int protection) {
    std::string str;
    str = "[TRACE] Player's protection changed. Now there are " + std::to_string(protection) + " protection.";
    Message message = Message(str, Level::TRACE);
    log.viewMessage(message);
}

void PlayerObserver::changedHealth(int health) {
    std::string str;
    str = "[TRACE] Player's health changed. Now there are " + std::to_string(health) + " health.";
    Message message = Message(str, Level::TRACE);
    log.viewMessage(message);
}

void PlayerObserver::playerWon() {
    Message message = Message("[TRACE] Player won!", Level::TRACE);
    log.viewMessage(message);
}

void PlayerObserver::playerLost() {
    Message message = Message("[TRACE] Player lost!", Level::TRACE);
    log.viewMessage(message);
}

PlayerObserver::PlayerObserver(Log &log_) : log(log_){
}
