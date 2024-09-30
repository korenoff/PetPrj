
#ifndef OOP_LAB1_LOG_H
#define OOP_LAB1_LOG_H

#include "Message.h"
#include "ILogger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include <map>
#include <vector>

class Log {
private:
    std::vector <ILogger*> loggers;
    std::vector <Level> levels;
    bool is_trace_level, is_info_level, is_error_level, is_file_logger, is_console_logger;
public:
    void addLevel(Level level);
    void addLogger(ILogger* logger);
    Log(bool level_trace, bool level_info, bool level_error, bool file_logger, bool console_logger);
    void viewMessage(const Message& message);
    ~Log();
    Log(const Log &log);
    Log(Log &&log) noexcept;
    Log &operator=(const Log &log);

    bool getIsInfoLevel();
    bool getIsErrorLevel();
    bool getIsTraceLevel();
    bool getIsConsoleLogger();
    bool getIsFileLogger();
};


#endif //OOP_LAB1_LOG_H
