
#ifndef OOP_LAB1_FIELDOBSERVER_H
#define OOP_LAB1_FIELDOBSERVER_H

#include "IFieldObserver.h"

class FieldObserver : public IFieldObserver{
private:
    Log &log;
public:
    explicit FieldObserver(Log &log_);
    void openExit() final;
    void changedPlayerPosition(int x_position, int y_position) final;
    void stepOnBarrier(std::basic_string<char> mes) final;
    Log &getLog() final;
};


#endif //OOP_LAB1_FIELDOBSERVER_H
