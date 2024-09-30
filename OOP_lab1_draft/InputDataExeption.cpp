
#include "InputDataExeption.h"

#include <utility>

InputDataExeption::InputDataExeption(std::string what) noexcept : _what(std::move(what)), _out(_what){}

const char *InputDataExeption::what() const noexcept {
    return _out.data();
}
