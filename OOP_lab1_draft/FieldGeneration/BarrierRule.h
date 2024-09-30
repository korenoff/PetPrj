
#ifndef OOP_LAB1_BARRIERRULE_H
#define OOP_LAB1_BARRIERRULE_H

#include "../Objects/Field.h"
#include "GameDifficulty.h"

template <GameDifficulty difficulty>
class BarrierRule {
public:
    void setOnField(Field *field, Log &log);
};

template<GameDifficulty difficulty>
void BarrierRule<difficulty>::setOnField(Field *field, Log &log) {
    if (difficulty == GameDifficulty::EASY) {
        int count = 0;
        while (count < 8) {
            int y = 1 + rand() % (field->getHeight() - 2);
            int x = 1 + rand() % (field->getWidth() - 2);
            if (!field->getCell(x, y).getBarrier() and !field->getCell(x, y).getEvent() and !(x == 0 and y == 0)) {
                field->getCell(x, y).setBarrier();
                count++;
            }
        }

    }
    if (difficulty == GameDifficulty::MEDIUM) {
        int count = 0;
        while (count < 13) {
            int y = 1 + rand() % (field->getHeight() - 2);
            int x = 1 + rand() % (field->getWidth() - 2);
            if (!field->getCell(x, y).getBarrier() and !field->getCell(x, y).getEvent() and !(x == 0 and y == 0)) {
                field->getCell(x, y).setBarrier();
                count++;
            }
        }

    }
}


#endif //OOP_LAB1_BARRIERRULE_H
