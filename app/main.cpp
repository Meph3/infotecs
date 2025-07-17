#include "logger.hpp"
#include "file_logger_output.hpp"
#include "socket_logger_output.hpp"
#include <memory>

int main() {
    // Пример логгера с выводом в файл
    auto fileOutput = std::make_shared<FileLoggerOutput>("log.txt");
    Logger fileLogger(fileOutput, LogLevel::INFO);
    fileLogger.log("Сообщение INFO", LogLevel::INFO);
    fileLogger.log("Сообщение WARNING", LogLevel::WARNING);

    // Пример логгера с выводом в сокет (лог сервер должен слушать на этом адресе)
    auto socketOutput = std::make_shared<SocketLoggerOutput>("127.0.0.1", 9090);
    Logger socketLogger(socketOutput, LogLevel::WARNING);
    socketLogger.log("Сообщение INFO — не должно быть видно", LogLevel::INFO);
    socketLogger.log("Сообщение ERROR через сокет", LogLevel::ERROR);

    return 0;
}
