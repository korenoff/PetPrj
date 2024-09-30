
#ifndef OOP_LAB1_APPLICATION_H
#define OOP_LAB1_APPLICATION_H

#include "Readers/ConsoleCommandReader.h"
#include "Controller.h"
#include "Log/Observers/GameObserver.h"
#include "FileInputCommands.h"
#include "FieldGeneration/FieldGenerator.h"
#include "FileInputExeption.h"

class Application {
private:
    bool game;
    IGameObserver* game_observer;
public:
    void start();
    void load();
    void exit();
    Application();
    ~Application();
};


#endif //OOP_LAB1_APPLICATION_H
