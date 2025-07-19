#ifndef SOCKET_LOGGER_OUTPUT_HPP
#define SOCKET_LOGGER_OUTPUT_HPP

#include "ilogger_output.hpp"
#include <string>
#include <mutex>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketLoggerOutput : public ILoggerOutput {
public:
    explicit SocketLoggerOutput(const std::string& address);
    ~SocketLoggerOutput();
    void write(const std::string& message) override;

private:
    int sock;
    struct sockaddr_in serverAddr;
    std::mutex mutex;
};

#endif // SOCKET_LOGGER_OUTPUT_HPP
