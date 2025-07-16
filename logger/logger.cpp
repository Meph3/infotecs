#include "logger.hpp"
#include <iostream>

Logger::Logger(const std::string& filename, LogLevel defaultLevel)
    : currentLevel(defaultLevel)
{
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Ошибка открытия файла журнала: " << filename << "\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::setLogLevel(LogLevel newLevel) {
    currentLevel = newLevel;
}

void Logger::log(const std::string& message, LogLevel level) {
    if (level < currentLevel || !logFile.is_open()) {
        return;
    }

    logFile << "[" << getTimeStamp() << "]"
            << " [" << levelToString(level) << "] "
            << message << std::endl;
}

std::string Logger::getTimeStamp() {
    std::time_t now = std::time(nullptr);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buffer;
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
