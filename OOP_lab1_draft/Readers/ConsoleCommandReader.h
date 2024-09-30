
#ifndef OOP_LAB1_CONSOLECOMMANDREADER_H
#define OOP_LAB1_CONSOLECOMMANDREADER_H

#include "../Objects/Player.h"
#include "../Direction.h"
#include "../FileInputCommands.h"
#include "IReader.h"
#include "../InputDataExeption.h"

class ConsoleCommandReader : public IReader{
public:
    Direction getDirection(InputCommands *file_input) final;
    int getFieldHeight() final;
    int getFieldWidth() final;
    int getLevel() final;
    bool getIsFileLogger() final;
    bool getIsConsoleLogger() final;
    bool getIsTraceLevel() final;
    bool getIsInfoLevel() final;
    bool getIsErrorLevel() final;
    int getGameDifficulty() final;
    int getCommand() final;
};


#endif //OOP_LAB1_CONSOLECOMMANDREADER_H
