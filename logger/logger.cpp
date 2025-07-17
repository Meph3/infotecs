#include "logger.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

// Конструктор
Logger::Logger(std::shared_ptr<LoggerOutput> output, LogLevel defaultLevel)
    : output(output), currentLevel(defaultLevel) {}

// Установка уровня логирования
void Logger::setLogLevel(LogLevel newLevel) {
    currentLevel = newLevel;
}

// Логирование сообщения
void Logger::log(const std::string& message, LogLevel level) {
    if (level < currentLevel || !output) {
        return;
    }

    std::ostringstream formatted;
    formatted << "[" << getTimeStamp() << "]"
              << " [" << levelToString(level) << "] "
              << message;

    output->write(formatted.str());
}

// Получение текущего времени
std::string Logger::getTimeStamp() {
    std::time_t now = std::time(nullptr);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buffer;
}

// Преобразование уровня важности в строку
std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
