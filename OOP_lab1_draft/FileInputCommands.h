
#ifndef OOP_LAB1_FILEINPUTCOMMANDS_H
#define OOP_LAB1_FILEINPUTCOMMANDS_H

#include <fstream>
#include <vector>
#include "InputCommands.h"
#include "Log/Observers/FileInputObserver.h"
#include "Direction.h"
#include "FileInputExeption.h"

class FileInputCommands : public InputCommands{
private:
    std::ifstream file;
    std::map<char, Direction> commands;
    IFileInputObserver *file_input_observer;
public:
    FileInputCommands();
    void setObserver(Log &log) final;
    void setCommands() final;
    IFileInputObserver *&getObserver() final;
    std::vector<std::string> split(const std::string& s,char delim);
    std::map<char, Direction> &getCommands() final;
    void errorCommands() final;
    bool isValidOptions(std::vector<std::string> opt) final;
    bool isValidKeys(std::vector<char> keys) final;
    Direction getDirectionValue(const std::string& command);
    ~FileInputCommands() final;
};


#endif //OOP_LAB1_FILEINPUTCOMMANDS_H
