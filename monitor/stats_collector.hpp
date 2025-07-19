#ifndef STATS_COLLECTOR_HPP
#define STATS_COLLECTOR_HPP

#include <string>
#include <map>
#include <vector>
#include <chrono>
#include "logger.hpp"

class StatsCollector {
public:
    void processMessage(const std::string& message);
    void printStats();

private:
    int totalMessages = 0;
    std::map<LogLevel, int> levelCount;
    std::vector<int> messageLengths;
    std::vector<std::chrono::steady_clock::time_point> timestamps;
};

#endif // STATS_COLLECTOR_HPP
