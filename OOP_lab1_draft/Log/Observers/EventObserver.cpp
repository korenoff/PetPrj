
#include "EventObserver.h"

void EventObserver::enemyAction() {
    Message message = Message("[TRACE] Enemy event is active", Level::TRACE);
    log.viewMessage(message);
}

void EventObserver::trapAction() {
    Message message = Message("[TRACE] Trap event is active", Level::TRACE);
    log.viewMessage(message);
}

void EventObserver::foodAction() {
    Message message = Message("[TRACE] Food event is active", Level::TRACE);
    log.viewMessage(message);
}

void EventObserver::moneyAction() {
    Message message = Message("[TRACE] Money event is active", Level::TRACE);
    log.viewMessage(message);
}

void EventObserver::exitAction() {
    Message message = Message("[TRACE] Exit event is active", Level::TRACE);
    log.viewMessage(message);
}

EventObserver::EventObserver(Log &log_) : log(log_){
}
