
#ifndef OOP_LAB1_EXIT_H
#define OOP_LAB1_EXIT_H

#include "GoodEvents.h"
#include "../Log/Observers/EventObserver.h"

class Exit : public GoodEvents{
private:
    IEventObserver *event_observer;
public:
    explicit Exit(Log &log_);
    void changeObserver(Log *log_) final;
    void addGood(Player& player) final;
    void playerReact(Player &player) final;
    ~Exit() final;
};


#endif //OOP_LAB1_EXIT_H
