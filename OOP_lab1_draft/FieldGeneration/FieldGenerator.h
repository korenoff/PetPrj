
#ifndef OOP_LAB1_FIELDGENERATOR_H
#define OOP_LAB1_FIELDGENERATOR_H

#include "../Objects/Field.h"
#include "GameDifficulty.h"
#include "BarrierRule.h"
#include "EnemyRule.h"
#include "TrapRule.h"
#include "FoodRule.h"
#include "MoneyRule.h"
#include "ExitPositionRule.h"

template<typename ... Rules>
class FieldGenerator {
public:
    Field *createField(int field_height, int field_width, Log &log);

    FieldGenerator() = default;

private:
    template<typename Rule>
    void applyRule(Field *field, Log &log);
};

template<typename... Rules>
Field *FieldGenerator<Rules...>::createField(int field_height, int field_width, Log &log) {
    auto *field = new Field(field_height, field_width);
    (applyRule<Rules>(field, log), ...);
    return field;
}

template<typename... Rules>
template<typename Rule>
void FieldGenerator<Rules...>::applyRule(Field *field, Log &log) {
    Rule rule;
    rule.setOnField(field, log);
}


#endif //OOP_LAB1_FIELDGENERATOR_H
