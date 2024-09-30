
#ifndef OOP_LAB1_IREADER_H
#define OOP_LAB1_IREADER_H


#include "../FieldGeneration/GameDifficulty.h"

class IReader {
public:
    virtual Direction getDirection(InputCommands *file_input) = 0;
    virtual int getFieldHeight() = 0;
    virtual int getFieldWidth() = 0;
    virtual int getLevel() = 0;
    virtual bool getIsFileLogger() = 0;
    virtual bool getIsConsoleLogger() = 0;
    virtual bool getIsTraceLevel() = 0;
    virtual bool getIsInfoLevel() = 0;
    virtual bool getIsErrorLevel() = 0;
    virtual int getGameDifficulty() = 0;
    virtual ~IReader() = default;
    virtual int getCommand() = 0;
};


#endif //OOP_LAB1_IREADER_H
