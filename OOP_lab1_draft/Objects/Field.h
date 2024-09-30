
#ifndef OOP_LAB1_FIELD_H
#define OOP_LAB1_FIELD_H

#include "Cell.h"
#include "../Factory/FoodFactory.h"
#include "../Factory/ExitFactory.h"
#include "Player.h"
#include "../Factory/Factory.h"
#include "../Factory/EnemyFactory.h"
#include "../Factory/TrapFactory.h"
#include "../Factory/MoneyFactory.h"
#include "../Log/Observers/FieldObserver.h"
#include <ctime>
#include <iostream>


class Field {
private:

    int height, width;
    Cell **array;
    int x_active, y_active;
    int x_exit_position, y_exit_position;
    IFieldObserver *field_observer;
public:
    Field(int height, int width, int player_x, int player_y);
    Field(int height, int width);
    Field();
    Field(const Field &field);
    Field(Field &&field) noexcept ;
    Field &operator=(const Field &field);
    ~Field();
    void changePlayerStartPosition(int x, int y);
    int getHeight() const;
    int getWidth() const;
    int getExitX() const;
    int getExitY() const;
    Cell &getCell(int y, int x);
    int getActiveCellX() const;
    int getActiveCellY() const;
    void setActiveCellX(int x);
    void setActiveCellY(int y);
    IFieldObserver *&getFieldObserver();
    void moveUp(int step, Player &player);
    void moveDown(int step, Player &player);
    void moveRight(int step, Player &player);
    void moveLeft(int step, Player &player);
    void setExit();
    void setFieldEvents(Log &log);
    void setEventOnCell(Factory *factory, Log &log);
    void setObserver(Log &log);
    void changeExitPosition(int x, int y);
};

#endif //OOP_LAB1_FIELD_H
