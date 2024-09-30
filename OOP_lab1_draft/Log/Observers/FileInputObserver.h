
#ifndef OOP_LAB1_FILEINPUTOBSERVER_H
#define OOP_LAB1_FILEINPUTOBSERVER_H

#include "IFileInputObserver.h"
#include "../Log.h"

class FileInputObserver : public IFileInputObserver{
private:
    Log &log;
public:
    explicit FileInputObserver(Log &log_);
    void wrongData(std::basic_string<char> mes) final;
};


#endif //OOP_LAB1_FILEINPUTOBSERVER_H
