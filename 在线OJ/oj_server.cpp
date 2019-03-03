#include <iostream>
#include "util.hpp"
#include "httplib.h"
#include "json.h"

int main()
{
    using namespace httplib;
    Server server;
    server.Get("/compile", [](const Request& req, Response& resp));
    {
        
        (void)req;
        std::string req_json;
        std::string resp_json;
        Compiler::CompileAndRun(&req_json, &resp_json);
        resp.set_content(resp_json, "text/plain");
    }
    /*
    (void)req;
    std::string req_json;
    std::string resp_json;
    Compiler::CompileAndRun(&req_json, &resp_json);
    //resp.set_content();

    //server.listen("0.0.0.0", 9092);
    */
    return 0;
}
