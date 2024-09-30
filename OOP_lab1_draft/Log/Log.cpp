
#include "Log.h"
#include <algorithm>
#include <typeinfo>


Log::Log(bool level_trace, bool level_info, bool level_error, bool file_logger, bool console_logger) : is_trace_level(level_trace), is_info_level(level_info), is_error_level(level_error), is_file_logger(file_logger), is_console_logger(console_logger) {
    if (level_trace)
        this->addLevel(Level::TRACE);
    if (level_info)
        this->addLevel(Level::INFO);
    if (level_error)
        this->addLevel(Level::ERROR_INFO);
    if (file_logger) {
        ILogger *file_log = new FileLogger;
        this->addLogger(file_log);
    }
    if (console_logger) {
        ILogger *console_log = new ConsoleLogger;
        this->addLogger(console_log);
    }
}

void Log::viewMessage(const Message &message) {
    for (auto &logger: loggers) {
        for (auto &level: levels) {
            if (message.getLevel() == level) {
                if (dynamic_cast<ConsoleLogger*>(logger)){
                    *logger << message;
                    system("pause");
                }
                else
                    *logger << message;
            }
        }
    }
}

Log::~Log() {
    for (auto & logger : loggers){
        delete logger;
    }
}

void Log::addLevel(Level level) {
    levels.push_back(level);
}

void Log::addLogger(ILogger *logger) {
    loggers.push_back(logger);
}

Log::Log(const Log &log) {
    loggers = log.loggers;
    levels = log.levels;
}

Log::Log(Log &&log) noexcept {
    std::swap(loggers, log.loggers);
    std::swap(levels, log.levels);
}

bool Log::getIsInfoLevel() {
    return is_info_level;
}

bool Log::getIsErrorLevel() {
    return is_error_level;
}

bool Log::getIsTraceLevel() {
    return is_trace_level;
}

bool Log::getIsConsoleLogger() {
    return is_console_logger;
}

bool Log::getIsFileLogger() {
    return is_file_logger;
}


Log &Log::operator=(const Log &log) = default;


