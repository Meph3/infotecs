#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <ctime>

// Уровни важности логов
enum class LogLevel {
    INFO,     // Информационное сообщение
    WARNING,  // Предупреждение
    ERROR     // Ошибка
};

// Класс Logger реализует запись сообщений в лог-файл с уровнями важности и временной меткой
class Logger {
public:

    Logger(const std::string& filename, LogLevel defaultLevel);

    ~Logger();

    void log(const std::string& message, LogLevel level);

    void setLogLevel(LogLevel newLevel);

private:
    std::ofstream logFile;  // Файловый поток для логирования
    LogLevel currentLevel;  // Текущий уровень логирования

    std::string getTimeStamp();

    std::string levelToString(LogLevel level);
};
#endif
