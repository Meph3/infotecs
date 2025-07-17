#ifndef FILE_LOGGER_OUTPUT_HPP
#define FILE_LOGGER_OUTPUT_HPP

#include "logger.hpp"
#include <fstream>

class FileLoggerOutput : public LoggerOutput {
public:
    explicit FileLoggerOutput(const std::string& filename);
    ~FileLoggerOutput();

    void write(const std::string& message) override;

private:
    std::ofstream logFile;
};

#endif // FILE_LOGGER_OUTPUT_HPP
