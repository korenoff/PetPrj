
#ifndef OOP_LAB1_EXITPOSITIONRULE_H
#define OOP_LAB1_EXITPOSITIONRULE_H

#include "../Objects/Field.h"
#include "GameDifficulty.h"


template<GameDifficulty difficulty>
class ExitPositionRule {
public:
    void setOnField(Field *field, Log &log);
};

template<GameDifficulty difficulty>
void ExitPositionRule<difficulty>::setOnField(Field *field, Log &log) {
    if (difficulty == GameDifficulty::EASY) {
        field->changeExitPosition(field->getWidth() / 2, field->getHeight() / 2);
    }
    if (difficulty == GameDifficulty::MEDIUM) {
    }
}


#endif //OOP_LAB1_EXITPOSITIONRULE_H
