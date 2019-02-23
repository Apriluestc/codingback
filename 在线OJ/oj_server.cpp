#include <iostream>
#include "util.hpp"

int main()
{
    Server server;
    server.Get("/", [](const Request& req, Response& resp));
    std::string req_josn;
    std::string resp_josn;
    complier::ComplierAndRun(&req_josn, &resp_josn);
    resp.set_content();

    server.listen("IP", 端口号);
    return 0;
}
