#include <iostream>
#include "include/server.hpp"
#include "include/socket.hpp"
#include "include/response.hpp"
#include "include/file.hpp"
#include <string>
#include <ctime>

#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }

int main() {

    int err;

    int port = 8080;
    int buffer_size = 256;
    const char* index_file = "/root/work/http-server/static/index.html";

    Server *server = new Server();
    server->listen(8080);

    char buf[ buffer_size];
    int len;

    while(1) {

        Socket *c = server->accept();

        std::cout << c->read() << std::endl;

        // File *file = new File();
        // file->open( index_file);
        // Response *res = new Response( file->c_str());
        Response *res = new Response( std::to_string( time(0)).c_str());
        c->write( res->toString());
        if( err < 0) on_error("Fail to send\n");
        delete c;
    }

    return 0;
}
