
#ifndef OOP_LAB1_ENEMY_H
#define OOP_LAB1_ENEMY_H

#include "BadEvents.h"
#include "../Log/Observers/EventObserver.h"


class Enemy : public BadEvents {
private:
    IEventObserver *event_observer;
public:
    explicit Enemy(Log &log_);
    void playerReact(Player& player) final;
    void remBad(Player& player) final;
    void changeObserver(Log *log_) final;
    ~Enemy() final;
};


#endif //OOP_LAB1_ENEMY_H
