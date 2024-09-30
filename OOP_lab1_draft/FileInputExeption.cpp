
#include "FileInputExeption.h"

FileInputException::FileInputException(std::string filename, std::string what) noexcept
        : _filename(std::move(filename)),
          _what(std::move(what)),
          _out("(" + _filename + ") " + _what) {}

const char *FileInputException::what() const noexcept {
    return _out.data();
}
