
#ifndef OOP_LAB1_GAMEOBSERVER_H
#define OOP_LAB1_GAMEOBSERVER_H

#include "IGameObserver.h"

class GameObserver : public IGameObserver{
public:
    void gameStarted(Log &log) final;
    void gameEnded(Log &log) final;
    void gameSaved(Log &log) final;
    void gameLoaded(Log &log) final;
    void invalidFileForLoad(Log &log) final;
    void invalidInputData(Log &log, std::basic_string<char> mes) final;
};


#endif //OOP_LAB1_GAMEOBSERVER_H
