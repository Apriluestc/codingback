#pragma once
#include <cstdlib>
#include <sys/time.h>
#include <stdint.h>

#include <iostream>

#include <fstream>


//获取时间戳
//
class TimeUtil
{
public:
    //获取秒
    static int64_t TimeStamp()
    {
        struct timeval tv;
        ::Gettimeofday(&tv, NULL);
        return tv.tv_sec;
    }
    //获取毫秒
    static int64_t TimeStampMS()
    {
        struct timeval tv;
        ::Gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000 + tv.tv_usec / 1000;
    }
};

enum Level
{
    INFO,   //提示
    WARING, //警告
    ERROR,  //错误
    FATAL,  //致命
};

//打印日志

inline std::ostream& Log(Level level, const std::string& msg, \ 
                         const std::string& file_name, int line_num)
{
    std::string prefix = "[";
    if(level == INFO)
        prefix += "I";
    else if(level == WARING)
        prefix += "W";
    else if(level == ERROR)
        prefix += "E";
    else(level == FATAL)
        prefix += "F";
    prefix += std::to_string(TimeUtil::TimeStamp());
    prefix += " ";
    prefix += file_name;
    prefix += ":";
    prefix += std::to_string(line_num);
    prefix += "]";
    std::cout << prefix;
    return std::cout;
}

#define LOG(level) Log(level, __FILE__, __LINE__)

//文件管理类

class fileUtil
{
public:
    //读取文件
    static bool Read(const std::string& file_name, std::string* content)
    {
        content->clear();
        std::ifstream file(file_path.c_str());
        if(!file.if_open())
        {
            return false;
        }
        while(std::getline(file, line))
        {
            *content += line + "\n";
        }
        file.close();
        return true;
    }

    //写文件
    static bool Write(const std::string& file_name, std::string* content)
    {
        content->clear();
        std::ifstream file(file_path.c_str());
        if(!file.if_open())
        {
            return false;
        }
        file.write(content.c_str(), content.size());

        file.close();
        return true;
    }
};
