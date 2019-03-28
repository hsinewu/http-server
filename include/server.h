#pragma once
#include "client.h"
#include "network.h"

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
