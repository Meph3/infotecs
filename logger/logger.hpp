#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <ctime>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    Logger(const std::string& filename, LogLevel defaultLevel);
    ~Logger();

    void log(const std::string& message, LogLevel level);
    void setLogLevel(LogLevel newLevel);

private:
    std::ofstream logFile;
    LogLevel currentLevel;

    std::string getTimeStamp();
    std::string levelToString(LogLevel level);
};

#endif // LOGGER_HPP
