
#ifndef OOP_LAB1_INPUTDATAEXEPTION_H
#define OOP_LAB1_INPUTDATAEXEPTION_H

#include <iostream>

class InputDataExeption : public std::exception {
public:
    explicit InputDataExeption(std::string what) noexcept;
    [[nodiscard]] const char *what() const noexcept override;

private:
    std::string _what;
    std::string _out;
};


#endif //OOP_LAB1_INPUTDATAEXEPTION_H
