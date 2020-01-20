#include "include/response.h"
#include <cstring>
#include <cstdio>

Response::Response(const char* b) {
    body = new char[256];
    strcpy(body, b);
}

Response::~Response() {
    delete[] body;
}

const char* Response::c_str() {
    const char* fmt = 
    "HTTP/1.1 200 OK\n"
    "Content-Type: text/html\n"
    "Content-Length: %d\n"
    "\n%s";

    char* buf = new char[256]; // unmanaged
    sprintf(buf, fmt, strlen(body), body);
    return buf;
}