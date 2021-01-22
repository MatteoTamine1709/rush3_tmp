#include <iostream>
#include <ctime>
#include "Logger.h"

Logger::e_LogLevel Logger::_level = ERROR;
int Logger::_deep_level = 0;

void Logger::setLogColor(const e_LogLevel &level)
{
    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char white[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };

    if (level == ERROR)
        std::cout << red;
    if (level == WARNING)
        std::cout << yellow;
    if (level == NOTICE)
        std::cout << magenta;
    if (level == INFO)
        std::cout << blue;
    if (level == DEBUG)
        std::cout << white;
}

void Logger::resetLogColor(void)
{
    char normal[] = { 0x1b, '[', '0', 'm', 0 };
    std::cout << normal;
}

void Logger::LogHeader(const e_LogLevel &level)
{
    for (int i = 0; i < _deep_level; i++)
        std::cout << "\t|";
    std::string vals[] = { "NONE", "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG" };
    std::string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    time_t now = std::time(0);
    tm *ltm = std::localtime(&now);
    std::cout << "[" << months[ltm->tm_mon] << " " << ltm->tm_mday << " ";
    std::cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] ";
    std::cout << "[" << vals[level] << "]: ";
}

void Logger::LOG(const e_LogLevel &level, const std::string &message)
{
    if (level > _level)
        return;
    setLogColor(level);
    LogHeader(level);
    if (level == ERROR)
        std::cerr << message << std::endl;
    else
        std::cout << message << std::endl;
    resetLogColor();
}

void Logger::LOG(const e_LogLevel &level, const Loggable& loggable)
{
    if (level > _level)
        return;
    setLogColor(level);
    LogHeader(level);
    loggable.LOG();
    resetLogColor();
}

Logger::Trace Logger::TRACE(const e_LogLevel &level, const std::string &message)
{
    if (level > _level)
        return Trace(false);
    setLogColor(level);
    LogHeader(level);
    if (level == ERROR)
        std::cerr << message << std::endl;
    else
        std::cout << message << std::endl;
    resetLogColor();
    return Trace(true);
}

Logger::Trace Logger::TRACE(const e_LogLevel &level, const Loggable& loggable)
{
    if (level > _level)
        return Trace(false);
    setLogColor(level);
    LogHeader(level);
    loggable.LOG();
    resetLogColor();
    return Trace(true);
}