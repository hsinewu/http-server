#include <cstdio>
#include <cstring>
#define BUFFER_SIZE 100

const char* response_from_file() {
    FILE *f;
    f = fopen("./static/index.html", "r");
    if(f == NULL) perror("Fail to read file");

    char* buf = new char[BUFFER_SIZE];
    fgets(buf, BUFFER_SIZE, f);
    fclose(f);

    return buf;
}
