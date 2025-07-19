#include "socket_listener.hpp"
#include "stats_collector.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <port> <N> <T>" << std::endl;
        return 1;
    }

    int port = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);
    int T = std::stoi(argv[3]);

    StatsCollector collector;
    int messageCounter = 0;
    auto lastOutput = std::chrono::steady_clock::now();

    SocketListener listener(port, [&](const std::string& msg) {
        std::cout << "Received: " << msg << std::endl;
        collector.processMessage(msg);
        messageCounter++;

        auto now = std::chrono::steady_clock::now();
        bool shouldPrint = messageCounter >= N ||
            std::chrono::duration_cast<std::chrono::seconds>(now - lastOutput).count() >= T;

        if (shouldPrint) {
            collector.printStats();
            messageCounter = 0;
            lastOutput = now;
        }
    });

    listener.run();

    return 0;
}
