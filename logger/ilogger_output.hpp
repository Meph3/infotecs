#ifndef ILOGGER_OUTPUT_HPP
#define ILOGGER_OUTPUT_HPP

#include <string>

class ILoggerOutput {
public:
    virtual ~ILoggerOutput() = default;
    virtual void write(const std::string& message) = 0;
};

#endif // ILOGGER_OUTPUT_HPP
