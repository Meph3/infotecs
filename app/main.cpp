#include "../logger/logger.hpp"
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<std::pair<std::string, LogLevel>> logQueue;
std::mutex queueMutex;
std::condition_variable condVar;
bool done = false;

void loggingThread(Logger& logger) {
    while (!done) {
        std::unique_lock<std::mutex> lock(queueMutex);
        condVar.wait(lock, [] { return !logQueue.empty() || done; });

        while (!logQueue.empty()) {
            auto [msg, lvl] = logQueue.front();
            logQueue.pop();
            logger.log(msg, lvl);
        }
    }
}

LogLevel parseLogLevel(const std::string& levelStr) {
    if (levelStr == "INFO") return LogLevel::INFO;
    if (levelStr == "WARNING") return LogLevel::WARNING;
    if (levelStr == "ERROR") return LogLevel::ERROR;
    return LogLevel::INFO;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: logger_app <destination> <default_level> [output_type]\n";
        return 1;
    }

    std::string destination = argv[1];
    LogLevel defaultLevel = parseLogLevel(argv[2]);
    LoggerOutputType outputType = LoggerOutputType::FILE;

    if (argc >= 4 && std::string(argv[3]) == "SOCKET")
        outputType = LoggerOutputType::SOCKET;

    Logger logger(destination, defaultLevel, outputType);
    std::thread t(loggingThread, std::ref(logger));

    std::string input;
    while (true) {
        std::cout << "Enter message (or 'exit'): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::cout << "Enter level (INFO/WARNING/ERROR or empty): ";
        std::string levelStr;
        std::getline(std::cin, levelStr);

        LogLevel level = levelStr.empty() ? defaultLevel : parseLogLevel(levelStr);

        {
            std::lock_guard<std::mutex> lock(queueMutex);
            logQueue.push({input, level});
        }
        condVar.notify_one();
    }

    done = true;
    condVar.notify_one();
    t.join();

    return 0;
}
