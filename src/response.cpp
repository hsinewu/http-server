#include "include/response.hpp"
#include <cstring>
#include <cstdio>
#include <string>

Response::Response(const char* b) {
    body = new char[256];
    strcpy(body, b);
}

Response::~Response() {
    delete[] body;
}

std::string Response::toString() {
    const char* fmt = 
    "HTTP/1.1 200 OK\n"
    "Content-Type: text/html\n"
    "Content-Length: %d\n"
    "\n%s";

    char* buf = new char[256]; // unmanaged
    sprintf(buf, fmt, strlen(body), body);
    return std::string(buf);
}