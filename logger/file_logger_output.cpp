#include "file_logger_output.hpp"
#include <iostream>

FileLoggerOutput::FileLoggerOutput(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Ошибка открытия файла лога: " << filename << std::endl;
    }
}

FileLoggerOutput::~FileLoggerOutput() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void FileLoggerOutput::write(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}
