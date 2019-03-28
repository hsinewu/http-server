#include "include/network.h"

class Client {
    int socket_fd;
    socklen_t addrlen;
    struct sockaddr_in info;
    public:
    Client() {
    }
    ~Client() {
        close(socket_fd);
    }
    void accept(int server_fd) {
        socket_fd = ::accept(server_fd, (struct sockaddr*) &info, &addrlen);
        // if(socket_fd < 0) ERROR
    }

    int read(char* buf, int len) {
        return ::read( socket_fd, buf, len);
    }

    int write(const char* buf, int len) {
        return ::write( socket_fd, buf, len);
    }
};

class Server {
    int socket_fd;
    int err;
    struct sockaddr_in info;
    public:
    Server() {
        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        // if(socket_fd < 0) ERROR
    }

    ~Server() {
        close( socket_fd);
    }

    int listen(int port) {
        info.sin_family = PF_INET;
        info.sin_addr.s_addr = INADDR_ANY;
        info.sin_port = htons( port);
        bind(socket_fd, (struct sockaddr*) &info, sizeof(info));
        return err = ::listen(socket_fd, 5);
    }

    Client* accept() {
        Client *c = new Client();
        c->accept(socket_fd);
        return c;
    }

    int getfd() { return socket_fd; }
};
