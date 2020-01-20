#pragma once
#include "network.hpp"

class Client {
    private:
    int socket_fd;
    socklen_t addrlen;
    struct sockaddr_in info;
    public:
    Client();
    ~Client();
    void accept(int);
    int read(char*, int);
    int write(const char*, int);
};
