#ifndef LOGGER_TYPES_HPP
#define LOGGER_TYPES_HPP

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

enum class LoggerOutputType {
    FILE,
    SOCKET
};

#endif // LOGGER_TYPES_HPP
