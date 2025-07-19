#ifndef SOCKET_LISTENER_HPP
#define SOCKET_LISTENER_HPP

#include <functional>
#include <string>

class SocketListener {
public:
    SocketListener(int port, std::function<void(const std::string&)> onMessage);
    void run();

private:
    int port_;
    std::function<void(const std::string&)> onMessage_;
};

#endif // SOCKET_LISTENER_HPP
