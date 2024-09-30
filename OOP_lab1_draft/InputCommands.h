
#ifndef OOP_LAB1_INPUTCOMMANDS_H
#define OOP_LAB1_INPUTCOMMANDS_H

#include <map>
#include "Log/Log.h"
#include "Direction.h"
#include "Log/Observers/IFileInputObserver.h"

class InputCommands {
public:
    virtual std::map<char, Direction> &getCommands() = 0;
    virtual void setCommands() = 0;
    virtual void setObserver(Log &log) = 0;
    virtual void errorCommands() = 0;
    virtual IFileInputObserver *&getObserver() = 0;
    virtual bool isValidOptions(std::vector<std::string> opt) = 0;
    virtual bool isValidKeys(std::vector<char> keys) = 0;
    virtual ~InputCommands() = default;
};


#endif //OOP_LAB1_INPUTCOMMANDS_H
