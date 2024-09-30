
#include "FileInputObserver.h"

FileInputObserver::FileInputObserver(Log &log_) : log(log_) {}

void FileInputObserver::wrongData(std::basic_string<char> mes) {
    std::string str_message = "[ERROR]" + mes;
    Message message = Message(str_message, Level::ERROR_INFO);
    log.viewMessage(message);
}
