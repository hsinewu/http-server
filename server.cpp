#include "include/network.h"
#include "include/client.h"
#include "include/server.h"

Server::Server() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    // if(socket_fd < 0) ERROR
}

Server::~Server() {
    close( socket_fd);
}

int Server::listen(int port) {
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons( port);
    bind(socket_fd, (struct sockaddr*) &info, sizeof(info));
    return ::listen(socket_fd, 5);
}

Client* Server::accept() {
    Client *c = new Client();
    c->accept(socket_fd);
    return c;
}
