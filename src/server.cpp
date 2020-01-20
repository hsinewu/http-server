#include "include/network.hpp"
#include "include/client.hpp"
#include "include/server.hpp"
#include <cstdio>

Server::Server() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) perror("Fail to create server socket");
}

Server::~Server() {
    close( socket_fd);
}

int Server::listen(int port) {
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons( port);
    bind(socket_fd, (struct sockaddr*) &info, sizeof(info));
    int err = ::listen(socket_fd, 5);
    if(err < 0) perror("Fail to listen server port");
    return err;
}

Client* Server::accept() {
    Client *c = new Client();
    c->accept(socket_fd);
    return c;
}
