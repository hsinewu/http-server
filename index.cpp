#include <cstdio>
#include <cstdlib>
#include "include/network.h"
#include "server.cpp"

#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }


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

    const char message[] =
      "HTTP/1.1 200 OK\n"
      "Content-Type: text/plain\n"
      "Content-Length: 12\n"
      "\nHello world!";
    err = c->write( message, sizeof(message));
    if( err < 0) on_error("Fail to send\n");
    delete c;
  }

  return 0;
}
