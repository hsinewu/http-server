#pragma once
#include "client.hpp"
#include "network.hpp"

class Server {
    private:
    int socket_fd;
    struct sockaddr_in info;
    public:
    Server();
    ~Server();
    int listen(int);
    Client* accept();
};
