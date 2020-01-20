#pragma once
#include <netinet/in.h>
#include <string>

class Socket {
    private:
    int socket_fd;
    socklen_t addrlen;
    struct sockaddr_in info;
    Socket(int);
    public:
    Socket();
    ~Socket();
    void listen(int);
    Socket* accept();
    std::string read();
    void write(std::string);
};
