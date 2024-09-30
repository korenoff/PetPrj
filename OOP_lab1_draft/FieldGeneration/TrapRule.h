
#ifndef OOP_LAB1_TRAPRULE_H
#define OOP_LAB1_TRAPRULE_H

#include "../Objects/Field.h"
#include "GameDifficulty.h"

template <GameDifficulty difficulty>
class TrapRule {
public:
    void setOnField(Field *field, Log &log);
};

template<GameDifficulty difficulty>
void TrapRule<difficulty>::setOnField(Field *field, Log &log) {
    if (difficulty == GameDifficulty::EASY) {
        int count = 0;
        while (count < 2) {
            int y = rand() % (field->getHeight() - 1);
            int x = rand() % (field->getWidth() - 1);
            if (!field->getCell(x, y).getBarrier() and !field->getCell(x, y).getEvent() and !(x == 0 and y == 0)) {
                Trap* trap = new Trap(log);
                field->getCell(x, y).changeEvent(trap);
                count++;
            }
        }

    }
    if (difficulty == GameDifficulty::MEDIUM) {
        int count = 0;
        while (count < 4) {
            int y = rand() % (field->getHeight() - 1);
            int x = rand() % (field->getWidth() - 1);
            if (!field->getCell(x, y).getBarrier() and !field->getCell(x, y).getEvent() and !(x == 0 and y == 0)) {
                Trap* trap = new Trap(log);
                field->getCell(x, y).changeEvent(trap);
                count++;
            }
        }

    }
}


#endif //OOP_LAB1_TRAPRULE_H
