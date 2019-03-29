#include <cstdio>
#include <cstdlib>
#include "include/server.h"
#include "include/client.h"
#include "include/response.h"
#include <string>

#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }

const char* response_from_file();

int main() {

    int err;

    Server *server = new Server();
    server->listen(8888);

    char buf[256];
    int len;

    while(1) {

        Client *c = server->accept();

        len = c->read( buf, sizeof(buf));
        if(len) printf("%s\n\n", buf);

        Response *res = new Response(response_from_file());
        const char *message = res->c_str();
        err = c->write( message, strlen(message));
        if( err < 0) on_error("Fail to send\n");
        delete c;
    }

    return 0;
}
