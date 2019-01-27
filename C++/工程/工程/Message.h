#pragma once

/**
* 消息列表
* type = 1 // 请求连接,  msg = 连接者名字
* type = 2 // 放棋子
* type = 3 // 请求和其他人游戏
* type = 4 // 拒绝游戏请求
* type = 5 // 同意请求
* type = 6 // 发送胜利消息
* type = 7 // 断开连接请求
* type = 8 // 保存游戏，但是不放在磁盘上，在下一局开始时将会丢失
* type = 9 // 添加新的玩家到所有客户端的玩家列表
* type = 10// 响应信息 type ==1
* type = 11// 和玩家游戏,msg 保存玩家的名字 ,创建游戏的玩家设置游戏
* type = 12//信息设置
* type = 13// 设置玩家颜色
* type = 14// msg＝ 接受请求的一方设置
* type = 15// 服务端更新信息
* type = 16// 发送控制或错误信息
* type = 17// 游戏失败
* type = 18// 服务端套接字关闭
* type = 19// 玩家结束游戏及更新
* type = 20// 电脑获胜/ 玩家获胜
*/

class Message  //启用其序列化功能
{
public:
	Message()
	{
		setting = true;
		char* msg = new char[50];
	}
	~Message()
	{
		delete[] msg;
	}
public:
	int type;            //消息类型 ,eg.1=请求连接
	bool setting;      // 是否设置禁手
	int color;           // 棋子颜色 ,1 = black ,2 = white
	bool forYourTurn;  //判断是否轮到接收者下棋
	int coordinateX;     // 记录坐标（X,Y）
	int coordinateY;
	char msg[];           // 消息主体

};
