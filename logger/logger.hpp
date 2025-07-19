#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <memory>
#include "ilogger_output.hpp"
#include "file_logger_output.hpp"
#include "socket_logger_output.hpp"
#include "logger_types.hpp"

class Logger {
public:
    Logger(const std::string& destination, LogLevel defaultLevel, LoggerOutputType outputType);
    void log(const std::string& message, LogLevel level);
    void setLogLevel(LogLevel newLevel);

private:
    LogLevel currentLevel;
    std::unique_ptr<ILoggerOutput> output;
};

#endif // LOGGER_HPP
