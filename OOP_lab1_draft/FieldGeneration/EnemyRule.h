
#ifndef OOP_LAB1_ENEMYRULE_H
#define OOP_LAB1_ENEMYRULE_H

#include "../Objects/Field.h"
#include "GameDifficulty.h"


template <GameDifficulty difficulty>
class EnemyRule {
public:
    void setOnField(Field *field, Log &log);
};

template<GameDifficulty difficulty>
void EnemyRule<difficulty>::setOnField(Field *field, Log &log) {
    if (difficulty == GameDifficulty::EASY) {
        int count = 0;
        while (count < 2) {
            int y = rand() % (field->getHeight() - 1);
            int x = rand() % (field->getWidth() - 1);
            if (!field->getCell(x, y).getBarrier() and !field->getCell(x, y).getEvent() and !(x == 0 and y == 0)) {
                Enemy* enemy = new Enemy(log);
                field->getCell(x, y).changeEvent(enemy);
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
                Enemy* enemy = new Enemy(log);
                field->getCell(x, y).changeEvent(enemy);
                count++;
            }
        }

    }
}


#endif //OOP_LAB1_ENEMYRULE_H
