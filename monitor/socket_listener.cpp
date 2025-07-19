#include "socket_listener.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

SocketListener::SocketListener(int port, std::function<void(const std::string&)> onMessage)
    : port_(port), onMessage_(onMessage) {}

void SocketListener::run() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(address);
    int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    while (true) {
        ssize_t valread = read(new_socket, buffer, sizeof(buffer));
        if (valread <= 0) break;
        std::string message(buffer, valread);
        onMessage_(message);
    }

    close(new_socket);
    close(server_fd);
}
