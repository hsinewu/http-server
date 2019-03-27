#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define on_error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }


int main() {

  int err;
  int sockfd = 0;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0) on_error("Fail to create socket\n");

  struct sockaddr_in serverInfo;
  serverInfo.sin_family = PF_INET;
  serverInfo.sin_addr.s_addr = INADDR_ANY;
  serverInfo.sin_port = htons( 8888);
  bind(sockfd, (struct sockaddr *)&serverInfo, sizeof(serverInfo) );
  err = listen( sockfd, 5);
  if( err < 0) on_error("Fail to listen\n");

  int clientfd;
  socklen_t addrlen;
  struct sockaddr_in clientInfo;

  char buf[256];
  int len;

  while(1) {
    clientfd = accept( sockfd, (struct sockaddr*) &clientInfo, &addrlen);
    if( clientfd < 0) on_error("Could not accept connection\n");

    len = read( clientfd, buf, sizeof(buf));
    if(len) printf("%s\n\n", buf);

    const char message[] =
      "HTTP/1.1 200 OK\n"
      "Content-Type: text/plain\n"
      "Content-Length: 12\n"
      "\nHello world!";
    write( clientfd, message, sizeof(message));
    if( err < 0) on_error("Fail to send\n");
    close( clientfd);
  }

  return 0;
}
