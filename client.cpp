#include "include/network.h"
#include "include/client.h"

Client::Client() {
}

Client::~Client() {
    close(socket_fd);
}

void Client::accept(int server_fd) {
    socket_fd = ::accept(server_fd, (struct sockaddr*) &info, &addrlen);
    // if(socket_fd < 0) ERROR
}

int Client::read(char* buf, int len) {
    return ::read( socket_fd, buf, len);
}

int Client::write(const char* buf, int len) {
    return ::write( socket_fd, buf, len);
}
