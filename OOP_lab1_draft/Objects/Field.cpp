#include <fstream>
#include "Field.h"

Field::Field(int height, int width, int player_x, int player_y) : height(height), width(width) {
    srand(static_cast<unsigned int>(time(nullptr)));
    array = new Cell *[height];
    for (int i = 0; i < height; i++) {
        array[i] = new Cell[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = Cell(i, j, false, false);
        }
    }
    array[player_y][player_x].activeReaction();
    x_active = player_x;
    y_active = player_y;
    field_observer = nullptr;
    x_exit_position = width - 1;
    y_exit_position = height - 1;
}


Field::Field(int height, int width) : height(height), width(width) {
    srand(static_cast<unsigned int>(time(nullptr)));
    array = new Cell *[height];
    for (int i = 0; i < height; i++) {
        array[i] = new Cell[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = Cell(i, j, false, false);
        }
    }
    array[0][0].activeReaction();
    x_active = 0;
    y_active = 0;
    field_observer = nullptr;
    x_exit_position = width - 1;
    y_exit_position = height - 1;
}

Field::Field() : Field(10, 10) {}

void Field::setEventOnCell(Factory *factory, Log &log) {
    int count = 0;
    while (count < 2) {
        int y = rand() % (height - 1);
        int x = rand() % (width - 1);
        if (!array[y][x].getBarrier() and !array[y][x].getEvent() and !(x == 0 and y == 0)) {
            array[y][x].changeEvent(factory->createEvent(log));
            count++;
        }
    }
}

void Field::setFieldEvents(Log &log) {

    Factory *enemy_factory = new EnemyFactory();
    Field::setEventOnCell(enemy_factory, log);
    delete enemy_factory;

    Factory *trap_factory = new TrapFactory();
    Field::setEventOnCell(trap_factory, log);
    delete trap_factory;

    Factory *money_factory = new MoneyFactory();
    Field::setEventOnCell(money_factory, log);
    delete money_factory;

    Factory *food_factory = new FoodFactory();
    Field::setEventOnCell(food_factory, log);
    delete food_factory;
}

Field::Field(const Field &field) {
    height = field.height;
    width = field.width;
    x_active = field.x_active;
    y_active = field.y_active;
    field_observer = field.field_observer;
    array = new Cell *[height];
    for (int i = 0; i < field.height; i++) {
        array[i] = new Cell[width];
    }
    for (int i = 0; i < field.height; i++) {
        for (int j = 0; j < field.width; j++) {
            array[i][j] = field.array[i][j];
        }
    }
}

Field::Field(Field &&field) noexcept {
    std::swap(height, field.height);
    std::swap(width, field.width);
    std::swap(x_active, field.x_active);
    std::swap(y_active, field.y_active);
    std::swap(field_observer, field.field_observer);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::swap(array[i][j], field.array[i][j]);
        }
    }
}


Field &Field::operator=(const Field &field) {
    if (this != &field) {
        for (int i = 0; i < height; i++) {
            delete array[i];
        }
        delete[] array;
        height = field.height;
        width = field.width;
        x_active = field.x_active;
        y_active = field.y_active;
        field_observer = field.field_observer;
        array = new Cell *[height];
        for (int i = 0; i < field.height; i++) {
            array[i] = new Cell[width];
        }
        for (int i = 0; i < field.height; i++) {
            for (int j = 0; j < field.width; j++) {
                array[i][j] = field.array[i][j];
            }
        }
    }
    return *this;
}

Field::~Field() {
    for (int i = 0; i < height; i++) {
        delete[] array[i];
    }
    delete[] array;
    delete field_observer;
}

int Field::getHeight() const {
    return this->height;
}

int Field::getWidth() const {
    return this->width;
}

Cell &Field::getCell(int y, int x) {
    return array[y][x];
}

int Field::getActiveCellX() const {
    return x_active;
}

int Field::getActiveCellY() const {
    return y_active;
}

void Field::setExit() {
    Factory *exit_factory = new ExitFactory();
    if (array[y_exit_position][x_exit_position].getBarrier())
        array[y_exit_position][x_exit_position].deleteBarrier();
    array[y_exit_position][x_exit_position].changeEvent(exit_factory->createEvent(field_observer->getLog()));
    field_observer->openExit();
    delete exit_factory;
}

void Field::moveUp(int step, Player &player) {
    array[y_active][x_active].activeReaction();
    array[y_active][x_active].setGood();
    y_active = (height + y_active - step) % height;
    field_observer->changedPlayerPosition(x_active, y_active);
    array[y_active][x_active].activeReaction();
    if (array[y_active][x_active].getEvent())
        array[y_active][x_active].getEvent()->playerReact(player);
    if (player.getOpenExit() and !array[height - 1][width - 1].getEvent())
        Field::setExit();
}

void Field::moveDown(int step, Player &player) {
    array[y_active][x_active].activeReaction();
    array[y_active][x_active].setGood();
    y_active = (height + y_active + step) % height;
    field_observer->changedPlayerPosition(x_active, y_active);
    array[y_active][x_active].activeReaction();
    if (array[y_active][x_active].getEvent())
        array[y_active][x_active].getEvent()->playerReact(player);
    if (player.getOpenExit() and !array[height - 1][width - 1].getEvent())
        Field::setExit();
}

void Field::moveRight(int step, Player &player) {
    array[y_active][x_active].activeReaction();
    array[y_active][x_active].setGood();
    x_active = (width + x_active + step) % width;
    field_observer->changedPlayerPosition(x_active, y_active);
    array[y_active][x_active].activeReaction();
    if (array[y_active][x_active].getEvent())
        array[y_active][x_active].getEvent()->playerReact(player);
    if (player.getOpenExit() and !array[height - 1][width - 1].getEvent())
        Field::setExit();
}

void Field::moveLeft(int step, Player &player) {
    array[y_active][x_active].activeReaction();
    array[y_active][x_active].setGood();
    x_active = (width + x_active - step) % width;
    field_observer->changedPlayerPosition(x_active, y_active);
    array[y_active][x_active].activeReaction();
    if (array[y_active][x_active].getEvent())
        array[y_active][x_active].getEvent()->playerReact(player);
    if (player.getOpenExit() and !array[height - 1][width - 1].getEvent())
        Field::setExit();
}

IFieldObserver *&Field::getFieldObserver() {
    return field_observer;
}

void Field::setObserver(Log &log) {
    delete field_observer;
    field_observer = new FieldObserver(log);
}

void Field::changePlayerStartPosition(int x, int y) {
    x_active = x;
    y_active = y;
    array[x_active][y_active].activeReaction();
}

void Field::changeExitPosition(int x, int y) {
    x_exit_position = x;
    y_exit_position = y;
}

void Field::setActiveCellY(int y) {
//    array[0][0].activeReaction();
    y_active = y;
}

void Field::setActiveCellX(int x) {
    x_active = x;
}

int Field::getExitX() const {
    return x_exit_position;
}

int Field::getExitY() const {
    return y_exit_position;
}

