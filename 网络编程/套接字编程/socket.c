/*
socket 常见 API

int socket(int domain, int type, int protocol);  //创建文件描述符
domain 地址类型
type 协议类型
protocol 一般为0

int bind(int socket, const struct sockaddr* address, socklen_t address_len); //绑定端口号
{
    struct sockaddr_in addr;    //定义ip地址
    addr.sin_family = AF_INET;  //AF_INET表示ipv4版本协议
    addr.sin_addr.s_addr = inet_addr(argv[1]);  //赋值
    addr.sin_port = htons(atoi(argv[2]));

    int ret = bind(sock, (struct sockaddr*)&addr, sizeof(addr));    //绑定
}

int listen(int socket, int backlog); //开始监听套接字

int accept(int socket, struct sockaddr* address, socklen_T* address_len);   //接受请求

int connect(int sockfd, const struct sockaddr* address, socklen_ address_len);  //建立连接

struct sockaddr
{
    __SOCKADDR_COMMON (sa_); //common data: address family and length
    char sa_data[14];   //address data
};

struct sockaddr_in
{
    __SOCKADDR_COMMON (sin_);   //地址类型
    in_port_t sin_port; //port number
    struct in_addr sin_addr;    //internet address

    unsigned char sin_zero[sizeof(struct sockaddr) - \ 
        __SOCKADDR_COMMON_SIZE - sizeof(in_port_t) - \ 
        sizeof(struct in_addr)];
};

typedef uint32_t in_addr_t;
struct in_addr  //in_addr表示一个ipv4的地址
{
    in_addr_t s_addr;
}；

UDP服务端：

void _main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);  //其中socket参数使用SOCK_DGRAM表示UDP

    if(sock < 0)
    {
        perror("socket");
        return 2;
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET; //地址类型
    local.sin_port = htons(atoi(argv[2]));  //端口号
    local.sin_addr.s_addr = inet_addr(argv[1]); //ip地址

    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0);
    {
        perror("bind");
        return 3;
    }

    char buffer[1024];
    struct sockaddr_in client;

    while(1)
    {
        socklen_t len = sizeof(client);
        ssize_t s = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, \ 
                             (struct sockaddr*)&client, &len);

        if(s > 0)
        {
            buffer[s] = 0;
            printf("[%s:%d]: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buffer);

            sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&client, sizeof(client));
        }
    }
}

UDP客户端

void __main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
        return 2;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    char buf[1024];
    struct sockaddr_in peer;

    while(1)
    {
        socklen_tt len = sizeof(peer);
        printf("please enter# ");
        fflush(stdout);

        ssize_t s = read(0, buf, sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s-1] = 0;
            sendto(sock, buf, strlen(buf), 0, \
                   (struct sockaddr*)&server, sizeof(server));
            ssize_t _s = recvfrom(sock, buf, sizeof(buf) - 1, 0, \
                                 (struct sockaddr*)&peer, &len);

            if(s > 0)
            {
                buf[_s] = 0;

                printf("server echo# %s\n", buf);
            }
        }
    }
}



*/


//多线程调用inet_ntoa会出现以下情况



#include <stdio.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void* Func1(void* p)
{
    struct sockaddr_in* addr = (struct sockaddr_in*)p;
    while(1)
    {
        char* ptr = inet_ntoa(addr->sin_addr);
        printf("addr1: %s\n", ptr);
    }
    return NULL;
}


void* Func2(void* p)
{
    struct sockaddr_in* addr = (struct sockaddr_in*)p;
    while(1)
    {
        char* ptr = inet_ntoa(addr->sin_addr);
        printf("addr2: %s\n", ptr);
    }
    return NULL;
}

int main()
{
    pthread_t tid1 = 0;
    struct sockaddr_in addr1;
    struct sockaddr_in addr2;
    addr1.sin_addr.s_addr = 0;
    addr2.sin_addr.s_addr = 0xffffffff;
    pthread_create(&tid1, NULL, Func1, &addr1);

    pthread_t tid2 = 0;
    pthread_create(&tid2, NULL, Func2, &addr2);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
