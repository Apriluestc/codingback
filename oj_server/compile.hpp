#pragma once
#include <iostream>
#include "json.h"

class Compiler
{
public:
    //源代码文件
    static std::string SrcPath(const std::string& name)
    {
        return "./tmp_files/" + name + ".cpp";
    }
    //编译错误文件
    static std::string CompileErrorPath(const std::string& name)
    {
        return "./tmp_files/" + name + ".compile_error";
    }
    //可执行程序文件
    static std::string ExePath(const std::string& name)
    {
        return "./tmp_files/" + name + ".exe";
    }
    //标准输入文件
    static std::string stdinPath(const std::string& name)
    {
        return "./tmp_files/" + name + ".stdin";
    }
    //标准输出文件
    static std::string stdoutPath(const std::string& name)
    {
        return "./tmp_files/" + name + ".stdout";
    }
    //标准错误文件
    static std::string stderrPath(const std::string& name)
    {
        return "./tmp_files/" + name + ".stderr";
    }

    static bool CompileAndRun(const Json::Value& req_json, Json::Value& reso_json)
    {
        if(req["code"].empty())
        {
            (*resp)["error"] = 3;
            (*resp)["reason"] = "code empty!";
            LOG(ERROR) << "code empty!" << std::endl;
            return false;
        }
        std::string code = req["code"].asString();
        std::string file_name = WriteTmpFile(code);
        Compile(file_name);
        bool ret = Compile(file_name);

        if(!ret)
        {
            (*resp)["error"] = 1;
            std::string reason;
            FileUtil::Read(CompileErrorPath(file_name), &reason);
            (*resp)["reason"] = reason;

            LOG() << << std::endl;
            return false;
        }

        int sig = Run(file_name);
        {
            (*resp)["error"] = 2;
            (*resp)["error"] = "Pragma exit!" + std::to_string(sig);
            LOG(INFO) << "Pragma exit by ···" << std::to_string(sig) << std::endl;
        }

        (*resp)["error"] = 0;
        (*resp)["reason"] = "";
        
        std::string str_stdin;
        FileUtil::Read(stdinPath(file_name), &str_stdin);
        (*resp)["stdin"] = str_stdin;
        
        std::string str_stdout;
        FileUtil::Read(stdoutPath(file_name), &str_stdout);
        (*resp)["stdout"] = str_stdout;
    }
private:
    static std::string WriteTmpFile(const std::string& code)
    {
        static std::atomic_int id(0);
        ++id;
        std::string file_name = "tmp_" + std::TimeStamp() + "." + std::to_string(id);

        FileUtil::Write(file_name);
        return file_name;
    }

    static bool Compile(const std::string& file_name)
    {
        //构造编译指令
        //g++ file_name.cpp -o file_name.exe -std=C++11
        char* command[20] = {0};
        char buf[20][20] = {0};
        for(int i = 0; i < sizeof(command)/sizeof(command[0]); ++i)
        {
            command[i] = buf[i];
        }
        sprintf(command[0], "%s", "g++");
        sprintf(command[1], "%s", SrcPath(file_name));   //源文件名
        sprintf(command[2], "%s", "-o");
        sprintf(command[3], "%s", ExePath(file_name));   //编译文件
        sprintf(command[4], "%s", "-std=C++11");
        command[5] = NULL;

        //创建进程
        //
        int ret = fork();
        if(ret > 0)
        {
            waitpid(ret, NULL, 0);
        }
        else
        {
            int fd = open(CompileErrorPath(file_name), O_WRONLY | O_CREAT, 0666);
            if(fd < 0)
            {
                LOG(ERROR) << "file open fill!" << std::endl;
                exit(1);
            }
        }
        dup2(fd, 2);
        execlp(command[0], command);
        exit(0);


        return true;
    }

    static int Run(const std::string& file_name)
    {

    }
};

