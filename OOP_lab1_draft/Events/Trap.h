
#ifndef OOP_LAB1_TRAP_H
#define OOP_LAB1_TRAP_H

#include "BadEvents.h"
#include "../Log/Observers/EventObserver.h"

class Trap : public BadEvents {
private:
    IEventObserver *event_observer;
public:
    Trap(Log &log_);
    void playerReact(Player& player) final;
    void remBad(Player& player) final;
    void changeObserver(Log *log_) final;
    ~Trap() final;
};


#endif //OOP_LAB1_TRAP_H
