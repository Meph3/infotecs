#include "socket_logger_output.hpp"
#include <cstring>

SocketLoggerOutput::SocketLoggerOutput(const std::string& address) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr);
    connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

SocketLoggerOutput::~SocketLoggerOutput() {
    close(sock);
}

void SocketLoggerOutput::write(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);
    send(sock, message.c_str(), message.size(), 0);
}
