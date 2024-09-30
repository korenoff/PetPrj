
#include "ConsoleCommandReader.h"
#include <iostream>
#include <conio.h>

int ConsoleCommandReader::getFieldHeight() {
    int height;
    std::cout << "Enter field height:";
    std::cin >> height;
    if (height < 9 or height > 18) {
        height = 10;
        throw InputDataExeption("Invalid field height!");
    }
    return height;
}

int ConsoleCommandReader::getFieldWidth() {
    int width;
    std::cout << "Enter field width:";
    std::cin >> width;
    if (width < 9 or width > 18) {
        width = 10;
        throw InputDataExeption("Invalid field width!");
    }
    return width;
}

Direction ConsoleCommandReader::getDirection(InputCommands *file_input) {
    char op = 'l';
    op = getch();
    std::map<char, Direction> actions = file_input->getCommands();
    Direction command = Direction::NONE;
    if (actions.find(op) != actions.end()) {
        command = actions.at(op);
    }
    return command;

}

int ConsoleCommandReader::getLevel() {
    int level;
    std::cout << "Choose logging levels:\n";
    std::cout << "\t1. If you want to see all changes\n";
    std::cout << "\t2. If you want to see errors and game changes (is started/ended and etc.) \n";
    std::cout << "\t3. If you want to see only errors\n";
    std::cin >> level;
    return level;
}

bool ConsoleCommandReader::getIsFileLogger() {
    std::cout << "Do you want to write changes in file? (y/n)\n";
    char answer;
    std::cin >> answer;
    if (answer == 'y')
        return true;
    return false;
}

bool ConsoleCommandReader::getIsConsoleLogger() {
    std::cout << "Do you want to write changes in console? (y/n)\n";
    char answer;
    std::cin >> answer;
    if (answer == 'y')
        return true;
    return false;
}

bool ConsoleCommandReader::getIsTraceLevel() {
    std::cout << "Do you want to log field and player changes? (y/n)\n";
    char answer;
    std::cin >> answer;
    if (answer == 'y')
        return true;
    return false;
}

bool ConsoleCommandReader::getIsInfoLevel() {
    std::cout << "Do you want to log game changes? (y/n)\n";
    char answer;
    std::cin >> answer;
    if (answer == 'y')
        return true;
    return false;
}

bool ConsoleCommandReader::getIsErrorLevel() {
    std::cout << "Do you want to log errors? (y/n)\n";
    char answer;
    std::cin >> answer;
    if (answer == 'y')
        return true;
    return false;
}

int ConsoleCommandReader::getGameDifficulty() {
    std::cout << "Choose level of game difficulty (easy - 1, medium - 2):\n";
    int difficulty_level;
    std::cin >> difficulty_level;
    if (difficulty_level != 1 and difficulty_level != 2){
        difficulty_level = 1;
        throw InputDataExeption("Invalid level of difficulty!");
    }
    return difficulty_level;
}

int ConsoleCommandReader::getCommand() {
    int command;
    std::cout << "Enter command:\n";
    std::cout << "1. New game\n";
    std::cout << "2. Load old game\n";
    std::cout << "3. Exit\n";
    std::cin >> command;
    return command;
}



