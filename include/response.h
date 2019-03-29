class Response {
    char* body;
    public:
    Response(const char*);
    ~Response();
    const char* c_str();
};
