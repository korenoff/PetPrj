
#include "FieldObserver.h"

void FieldObserver::openExit() {
    Message message = Message("[TRACE] Exit is open now.", Level::TRACE);
    log.viewMessage(message);
}

void FieldObserver::changedPlayerPosition(int x_position, int y_position) {
    std::string str;
    str = "[TRACE] Player position changed. Player position: (" + std::to_string(x_position) + ", " + std::to_string(y_position) + ")";
    Message message = Message(str, Level::TRACE);
    log.viewMessage(message);
}

void FieldObserver::stepOnBarrier(std::basic_string<char> mes) {
    std::string str_message = "[ERROR]" + mes;
    Message message = Message(str_message, Level::ERROR_INFO);
    log.viewMessage(message);
}

FieldObserver::FieldObserver(Log &log_) : log(log_){
}

Log &FieldObserver::getLog() {
    return log;
}
