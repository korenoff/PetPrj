
#ifndef OOP_LAB1_IFIELDOBSERVER_H
#define OOP_LAB1_IFIELDOBSERVER_H

#include "../Log.h"

class IFieldObserver {
public:
    virtual void openExit() = 0;
    virtual void changedPlayerPosition(int x_position, int y_position) = 0;
    virtual void stepOnBarrier(std::basic_string<char> mes) = 0;
    virtual ~IFieldObserver() = default;
    virtual Log &getLog() = 0;
};


#endif //OOP_LAB1_IFIELDOBSERVER_H
