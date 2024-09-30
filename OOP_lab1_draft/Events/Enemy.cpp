
#include "Enemy.h"

void Enemy::remBad(Player &player) {
    player.remPlayerHealth(1);
}

void Enemy::playerReact(Player &player) {
    event_observer->enemyAction();
    this->remBad(player);
    this->remPoints(player);
    if (player.getHealth() < 1 or player.getPoints() < 1 or player.getProtection() < 1)
        player.setDead();
}

Enemy::Enemy(Log &log_) {
    event_observer = new EventObserver(log_);
}

Enemy::~Enemy() {
    delete event_observer;
}

void Enemy::changeObserver(Log *log_) {
    delete event_observer;
    event_observer = new EventObserver(*log_);
}