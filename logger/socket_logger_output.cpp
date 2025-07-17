#include "socket_logger_output.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

SocketLoggerOutput::SocketLoggerOutput(const std::string& ip, int port)
    : sockfd(-1), connected(false)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Ошибка создания сокета\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Неверный IP адрес\n";
        close(sockfd);
        return;
    }

    if (connect(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Ошибка подключения к серверу\n";
        close(sockfd);
        return;
    }

    connected = true;
}

SocketLoggerOutput::~SocketLoggerOutput() {
    if (connected) {
        close(sockfd);
    }
}

void SocketLoggerOutput::write(const std::string& message) {
    if (!connected) return;
    send(sockfd, message.c_str(), message.size(), 0);
}
