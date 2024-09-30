
#ifndef OOP_LAB1_PRINTFIELD_H
#define OOP_LAB1_PRINTFIELD_H
#include "../Objects/Field.h"
#include "PrintCell.h"
#include <windows.h>

class PrintField{
public:
    void print(Field& field);

    PrintField();
    void printLine(int width);
};

#endif //OOP_LAB1_PRINTFIELD_H
