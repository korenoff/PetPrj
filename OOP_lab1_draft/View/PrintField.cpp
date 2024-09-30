#include "PrintField.h"

#include <iostream>

void PrintField::printLine(int width) {
    std::cout << "+";
    while (width > 0) {
        for (int i = 0; i < 3; i++)
            std::cout << "-";
        std::cout << "+";
        width--;
    }
    std::cout << '\n';
}

void PrintField::print(Field &field) {
    system("cls");
    PrintCell print_cell;
    for (int i = 0; i < field.getHeight(); i++) {
        printLine(field.getWidth());
        for (int j = 0; j < field.getWidth(); j++) {
            print_cell.printCell(field.getCell(i, j));
        }
        std::cout << "|\n";
    }
    printLine(field.getWidth());
}

PrintField::PrintField() = default;


