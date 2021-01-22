#ifndef LOGGER_H_
#define LOGGER_H_

#include "Loggable.h"

class Logger
{
public:
    Logger() = delete;
    ~Logger() = delete;
    
    enum e_LogLevel
    {
        NONE,
        ERROR,
        WARNING,
        NOTICE,
        INFO,
        DEBUG
    };

    class Trace
    {
        bool inc = true;
    public:
        Trace(bool d) {
            inc = d;
            if (inc == true)
                ++_deep_level;
        };
        ~Trace() {
            if (inc == true)
                --_deep_level;
        };
        
    };


public:
    static Logger::Trace TRACE(const e_LogLevel &level, const std::string &message);
    static Logger::Trace TRACE(const e_LogLevel &level, const Loggable &loggable);
    static void LOG(const e_LogLevel &level, const std::string &message);
    static void LOG(const e_LogLevel &level, const Loggable &loggable);
    static const enum e_LogLevel& getLogLevel() { return _level; }
    static void setLogLevel(enum e_LogLevel level) { _level = level; };

private:
    static int _deep_level;
    static e_LogLevel _level;

    static void LogHeader(const e_LogLevel &level);
    static void setLogColor(const e_LogLevel &level);
    static void resetLogColor(void);

};

#endif