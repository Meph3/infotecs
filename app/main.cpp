#include "logger.hpp"

int main() {
    Logger logger("log.txt", LogLevel::WARNING);

    logger.log("Информационное сообщение", LogLevel::INFO);     // не запишется
    logger.log("Предупреждение", LogLevel::WARNING);            // запишется
    logger.log("Ошибка", LogLevel::ERROR);                      // запишется

    logger.setLogLevel(LogLevel::INFO);
    logger.log("Теперь INFO будет записано", LogLevel::INFO);   // запишется

    return 0;
}
