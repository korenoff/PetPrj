
#ifndef OOP_LAB1_FILEINPUTEXEPTION_H
#define OOP_LAB1_FILEINPUTEXEPTION_H

#include <iostream>
#include <exception>


class FileInputException : public std::exception {
public:
    explicit FileInputException(std::string filename, std::string what) noexcept;
    [[nodiscard]] const char* what() const noexcept override;

private:
    std::string _filename;
    std::string _what;
    std::string _out;
};


#endif //OOP_LAB1_FILEINPUTEXEPTION_H
