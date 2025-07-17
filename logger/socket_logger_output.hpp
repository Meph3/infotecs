#ifndef SOCKET_LOGGER_OUTPUT_HPP
#define SOCKET_LOGGER_OUTPUT_HPP

#include "logger.hpp"
#include <string>

class SocketLoggerOutput : public LoggerOutput {
public:
    SocketLoggerOutput(const std::string& ip, int port);
    ~SocketLoggerOutput();

    void write(const std::string& message) override;

private:
    int sockfd;
    bool connected;
};

#endif // SOCKET_LOGGER_OUTPUT_HPP
