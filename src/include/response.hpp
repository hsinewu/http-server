#include <string>

class Response {
    char* body;
    public:
    Response(const char*);
    ~Response();
    std::string toString();
};
