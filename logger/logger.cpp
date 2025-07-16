#include "logger.hpp"
#include <iostream>

// Конструктор: открывает файл и устанавливает уровень логирования
Logger::Logger(const std::string& filename, LogLevel defaultLevel)
    : currentLevel(defaultLevel)
{
    logFile.open(filename, std::ios::app);  // открытие файла в режиме добавления
    if (!logFile.is_open()) {
        std::cerr << "Ошибка открытия файла журнала: " << filename << "\n";
    }
}

// Деструктор: закрывает файл
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Изменение уровня логирования
void Logger::setLogLevel(LogLevel newLevel) {
    currentLevel = newLevel;
}

// Запись сообщения в лог
void Logger::log(const std::string& message, LogLevel level) {
    if (level < currentLevel || !logFile.is_open()) {
        return;  
    }

    logFile << "[" << getTimeStamp() << "]"
            << " [" << levelToString(level) << "] "
            << message << std::endl;
}

// Получение текущей временной метки
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

