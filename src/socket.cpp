#include "include/socket.hpp"
#include <unistd.h>

Socket::Socket() {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) perror("Fail to create socket");
}

Socket::Socket(int sf) {
    socket_fd = sf;
}

Socket::~Socket() {
    close(socket_fd);
}

void Socket::listen(int port) {
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons( port);
    bind(socket_fd, (struct sockaddr*) &info, sizeof(info));
    int err = ::listen(socket_fd, 5);
    if(err < 0) perror("Fail to listen port");
}

Socket* Socket::accept() {
    int new_socket_fd = ::accept(socket_fd, (struct sockaddr*) &info, &addrlen);
    return new Socket(new_socket_fd);
    // if(socket_fd < 0) ERROR
}

std::string Socket::read() {
    char buf[256];
    int err = ::read( socket_fd, buf, 256);

    return std::string(buf);
}

void Socket::write(std::string message) {
    const char* buf = message.c_str();
    ::write( socket_fd, buf, 256);
}
