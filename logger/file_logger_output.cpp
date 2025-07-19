#include "file_logger_output.hpp"

FileLoggerOutput::FileLoggerOutput(const std::string& filename) {
    file.open(filename, std::ios::app);
}

void FileLoggerOutput::write(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);
    if (file.is_open()) {
        file << message << std::endl;
    }
}
