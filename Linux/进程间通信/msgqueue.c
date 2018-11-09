/*  这是一个以 System V 消息队列实现聊天室程序客户端
 *      1.创建消息队列
 *      2.从消息队列中获取数据,打印出来
 *      3.从标准输入获取数据,组织成消息队列节点发送
 *      4.删除消息队列
 *  消息队列的接口:
 *      msgget
 *      msgsnd
 *      msgrcv
 *      msgctl
 *      int msgget(key_t key, int msgflg);
 *          key:内核中消息队列的标识
 *          msgflg:
 *              IPC_CREAT   不存在则创建,存在则打开
 *              IPC_EXCL    与IPC_CREAT同用时,若存在则报错,
 *              mode    权限
 *              返回值: 代码操作的句柄; 失败:    -1
 *      ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
 *          msqid:  msgget返回的操作句柄
 *          msgp:   用于接收数据
 *          msgsz:  指定接收数据的大小
 *          msgtyp: 指定接收的数据类型
 *          msgflg: 标志选项, 0
 * */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define IPC_KEY 0x12345678
//int msgget(key_t key, int msgflg);
int main()
{
    int msgid = -1;
    //ftok()
    //key_t ftok(const char *pathname, int proj_id);
    //ftok通过文件的inode 节点号和一个proj_id计算出一个key 值
    //缺点:如果文件被删除,或替换,或交换那么打开的不是同一个msgqueue
    //创建消息队列
    msgid = msgget(IPC_KEY, IPC_CREAT | IPC_EXCL | 0664);
    if(msgid < 0){
        perror("msgget error");
        return -1;
    }

    //ftok
    
    //printf("Hello world\n");

}

