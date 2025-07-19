#include "logger.hpp"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

Logger::Logger(const std::string& destination, LogLevel defaultLevel, LoggerOutputType outputType)
    : currentLevel(defaultLevel) {
    if (outputType == LoggerOutputType::FILE) {
        output = std::make_unique<FileLoggerOutput>(destination);
    } else {
        output = std::make_unique<SocketLoggerOutput>(destination);
    }
}

void Logger::setLogLevel(LogLevel newLevel) {
    currentLevel = newLevel;
}

void Logger::log(const std::string& message, LogLevel level) {
    if (level < currentLevel) return;

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << "[" << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] ";

    switch (level) {
        case LogLevel::INFO: ss << "[INFO] "; break;
        case LogLevel::WARNING: ss << "[WARNING] "; break;
        case LogLevel::ERROR: ss << "[ERROR] "; break;
    }

    ss << message;
    output->write(ss.str());
}
