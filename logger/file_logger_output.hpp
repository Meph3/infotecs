#ifndef FILE_LOGGER_OUTPUT_HPP
#define FILE_LOGGER_OUTPUT_HPP

#include "ilogger_output.hpp"
#include <fstream>
#include <mutex>

class FileLoggerOutput : public ILoggerOutput {
public:
    explicit FileLoggerOutput(const std::string& filename);
    void write(const std::string& message) override;

private:
    std::ofstream file;
    std::mutex mutex;
};

#endif // FILE_LOGGER_OUTPUT_HPP
