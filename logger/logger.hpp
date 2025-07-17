#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <memory>

// Уровни важности логов
enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

// Абстрактный интерфейс вывода логов
class LoggerOutput {
public:
    virtual ~LoggerOutput() = default;
    virtual void write(const std::string& message) = 0;
};

// Основной класс логгера
class Logger {
public:
    Logger(std::shared_ptr<LoggerOutput> output, LogLevel defaultLevel);
    void log(const std::string& message, LogLevel level);
    void setLogLevel(LogLevel newLevel);

private:
    LogLevel currentLevel;
    std::shared_ptr<LoggerOutput> output;

    std::string getTimeStamp();
    std::string levelToString(LogLevel level);
};

#endif // LOGGER_HPP
