#pragma once
#include "socket.hpp"

class Server {
    private:
    Socket *master;
    public:
    Server();
    ~Server();
    void listen(int);
    Socket* accept();
};
