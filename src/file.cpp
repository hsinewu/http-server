#include "include/file.hpp"
#include <cstdio>
#include <cstring>

File::File() : fd() {};

File::~File() { close(); };

void File::open(const char* path) {
    close();
    fd = fopen(path, "r");
    if(fd == NULL) perror("Fail to read file");
}

const char* File::c_str() {
    fseek(fd, 0, SEEK_END);
    long size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    char* str = new char[ size + 1];
    fread(str, size, 1, fd);
    str[size] = 0;
    return str;
}

void File::close() {
    if(fd != NULL) fclose(fd);
}
