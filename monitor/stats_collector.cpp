#include "stats_collector.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

void StatsCollector::processMessage(const std::string& message) {
    totalMessages++;
    messageLengths.push_back(message.length());
    timestamps.push_back(std::chrono::steady_clock::now());

    if (message.find("[INFO]") != std::string::npos) levelCount[LogLevel::INFO]++;
    else if (message.find("[WARNING]") != std::string::npos) levelCount[LogLevel::WARNING]++;
    else if (message.find("[ERROR]") != std::string::npos) levelCount[LogLevel::ERROR]++;
}

void StatsCollector::printStats() {
    std::cout << "Total messages: " << totalMessages << std::endl;
    std::cout << "INFO: " << levelCount[LogLevel::INFO] << std::endl;
    std::cout << "WARNING: " << levelCount[LogLevel::WARNING] << std::endl;
    std::cout << "ERROR: " << levelCount[LogLevel::ERROR] << std::endl;

    if (!messageLengths.empty()) {
        int minLen = *std::min_element(messageLengths.begin(), messageLengths.end());
        int maxLen = *std::max_element(messageLengths.begin(), messageLengths.end());
        double avg = std::accumulate(messageLengths.begin(), messageLengths.end(), 0.0) / messageLengths.size();
        std::cout << "Length (min/max/avg): " << minLen << "/" << maxLen << "/" << avg << std::endl;
    }
}
