#include <cstdio>

class File {
    FILE *fd;
    public:
    File();
    ~File();
    void open(const char*);
    const char* c_str();
    void close();
};
