
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

#include "FileInputCommands.h"


std::map<char, Direction> &FileInputCommands::getCommands() {
    return commands;
}

FileInputCommands::FileInputCommands() : file(std::ifstream("Commands.txt")) {
    file_input_observer = nullptr;
}

FileInputCommands::~FileInputCommands() {
    delete file_input_observer;
    file.close();
}

std::vector<std::string> FileInputCommands::split(const std::string &s, char delim) {
    std::string temp;
    std::stringstream ss(s);
    std::vector<std::string> vec;
    if (s.find('-') != std::string::npos) {
        while (getline(ss, temp, delim)) {
            if (temp.length()) {
                vec.push_back(temp);
            }
        }
    }
    return vec;
}

void FileInputCommands::errorCommands() {
    commands.clear();
    commands.insert(std::make_pair('w', Direction::UP));
    commands.insert(std::make_pair('s', Direction::DOWN));
    commands.insert(std::make_pair('a', Direction::LEFT));
    commands.insert(std::make_pair('d', Direction::RIGHT));
    commands.insert(std::make_pair('e', Direction::EXIT));
    commands.insert(std::make_pair('q', Direction::SAVE));
    commands.insert(std::make_pair('l', Direction::LOAD));
    commands.insert(std::make_pair('t', Direction::DOUBLE_UP));
    commands.insert(std::make_pair('g', Direction::DOUBLE_DOWN));
    commands.insert(std::make_pair('f', Direction::DOUBLE_LEFT));
    commands.insert(std::make_pair('h', Direction::DOUBLE_RIGHT));
}

bool FileInputCommands::isValidOptions(std::vector<std::string> opt) {
    if (!std::count(opt.begin(), opt.end(), "up") or !std::count(opt.begin(), opt.end(), "down") or !std::count(opt.begin(), opt.end(), "left") or !std::count(opt.begin(), opt.end(), "right") or !std::count(opt.begin(), opt.end(), "exit") or !std::count(opt.begin(), opt.end(), "save") or !std::count(opt.begin(), opt.end(), "double up") or !std::count(opt.begin(), opt.end(), "double down") or !std::count(opt.begin(), opt.end(), "double left") or !std::count(opt.begin(), opt.end(), "double right") or !std::count(opt.begin(), opt.end(), "load")){
        throw FileInputException("Commands.txt", "Wrong options!");
        return false;
    }
    return true;
}

bool FileInputCommands::isValidKeys(std::vector<char> keys) {
    for (auto key : keys){
        if (std::count(keys.begin(), keys.end(), key) > 1){
            throw FileInputException("Commands.txt", "Wrong keys!");
            return false;
        }

    }
    return true;
}

void FileInputCommands::setCommands() {
    std::string line;
    int count_lines = 0;
    std::vector<std::string> temp;
    std::vector<std::string> options;
    std::vector<char> keys;
    while (std::getline(file, line)) {
        temp = this->split(line, '-');
        if (!temp.empty()) {
            if (temp[1].size() != 1){
                this->errorCommands();
                throw FileInputException("Commands.txt", "Wrong keys!");
                return;
            }
            commands.insert(std::make_pair(temp[1][0], this->getDirectionValue(temp[0])));
            options.push_back(temp[0]);
            keys.push_back(temp[1][0]);
            count_lines++;
        }
        else{
            count_lines++;
        }
    }
    if (count_lines != 11) {
        this->errorCommands();
        throw FileInputException("Commands.txt", "Too few or too much lines in file!");
    }
    try{
        isValidOptions(options);
    } catch(const FileInputCommands &e){
        this->errorCommands();
        throw FileInputException("Commands.txt", "Wrong options!");
    }
    try{
        isValidKeys(keys);
    } catch(const FileInputCommands &e){
        this->errorCommands();
        throw FileInputException("Commands.txt", "Wrong keys!");
    }
}

void FileInputCommands::setObserver(Log &log) {
    file_input_observer = new FileInputObserver(log);
}

Direction FileInputCommands::getDirectionValue(const std::string& command) {
    if (command == "up")
        return Direction::UP;
    if (command == "down")
        return Direction::DOWN;
    if (command == "left")
        return Direction::LEFT;
    if (command == "right")
        return Direction::RIGHT;
    if (command == "double up")
        return Direction::DOUBLE_UP;
    if (command == "double down")
        return Direction::DOUBLE_DOWN;
    if (command == "double right")
        return Direction::DOUBLE_RIGHT;
    if (command == "double left")
        return Direction::DOUBLE_LEFT;
    if (command == "exit")
        return Direction::EXIT;
    if (command == "save")
        return Direction::SAVE;
    if(command == "load")
        return Direction::LOAD;
    return Direction::NONE;
}

IFileInputObserver *&FileInputCommands::getObserver() {
    return file_input_observer;
}
