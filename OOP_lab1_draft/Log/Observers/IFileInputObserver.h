
#ifndef OOP_LAB1_IFILEINPUTOBSERVER_H
#define OOP_LAB1_IFILEINPUTOBSERVER_H
#include <string>


class IFileInputObserver {
public:
    virtual void wrongData(std::basic_string<char> mes) = 0;
    virtual ~IFileInputObserver() = default;
};


#endif //OOP_LAB1_IFILEINPUTOBSERVER_H
