#include "../logger/logger.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

// Проверка записи сообщения в лог-файл
void test_log_to_file() {
    const std::string logFile = "test_log.txt";

    // Создаем логгер с уровнем INFO и выводом в файл
    Logger logger(logFile, LogLevel::INFO, LoggerOutputType::FILE);
    logger.log("Test message", LogLevel::INFO);

    std::ifstream file(logFile);
    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        if (line.find("Test message") != std::string::npos) {
            found = true;
            break;
        }
    }

    assert(found && "Message should be written to log file.");
    std::cout << "test_log_to_file passed." << std::endl;
}

// Проверка фильтрации по уровню логирования
void test_log_level_filtering() {
    const std::string logFile = "test_filter_log.txt";

    Logger logger(logFile, LogLevel::WARNING, LoggerOutputType::FILE);
    logger.log("Info message", LogLevel::INFO);     // Не должен записаться
    logger.log("Error message", LogLevel::ERROR);   // Должен записаться

    std::ifstream file(logFile);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    assert(content.find("Info message") == std::string::npos && "INFO should be filtered");
    assert(content.find("Error message") != std::string::npos && "ERROR should be logged");

    std::cout << "test_log_level_filtering passed." << std::endl;
}

int main() {
    test_log_to_file();
    test_log_level_filtering();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
