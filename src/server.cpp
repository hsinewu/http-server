#include "include/server.hpp"
#include "include/socket.hpp"

Server::Server() {
    master = new Socket();
}

Server::~Server() {
    delete master;
}

void Server::listen(int port) {
    master->listen(port);
}

Socket* Server::accept() {
    return master->accept();
}
