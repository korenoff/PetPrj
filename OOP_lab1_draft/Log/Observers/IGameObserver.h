
#ifndef OOP_LAB1_IGAMEOBSERVER_H
#define OOP_LAB1_IGAMEOBSERVER_H

#include "../Log.h"

class IGameObserver {
public:
    virtual void gameStarted(Log &log) = 0;
    virtual void gameEnded(Log &log) = 0;
    virtual void gameSaved(Log &log) = 0;
    virtual void gameLoaded(Log &log) = 0;
    virtual void invalidFileForLoad(Log &log) = 0;
    virtual void invalidInputData(Log &log, std::basic_string<char> mes) = 0;
    virtual ~IGameObserver() = default;
};


#endif //OOP_LAB1_IGAMEOBSERVER_H
