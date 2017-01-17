//Client2，应后运行这个程序
#include<iostream>
#include<winsock2.h>
#include<stdio.h>

#pragma comment(lib,"WS2_32.lib")//显示连接套接字库
struct Input2        //需要发送的结构体
{
	int j;
	int CTRFlag;
	int SELFlag;
	int NDMode;
	int NDRange;
};
int main()
{
	struct Input2 rcvInput2;
	int i = 0;
	while (true)
	{
		
		i = i + 1;
		rcvInput2 = { i, i + 1, i + 2, i + 3, i + 4 };
		//scanf_s("%d,%d,%d,%d", &rcvInput2.CTRFlag, &rcvInput2.SELFlag, &rcvInput2.NDMode, &rcvInput2.NDRange);
		///////////socket初始化的一些工作///////////
		WSADATA data;//定义WSADATA结构体
		WORD w = MAKEWORD(2, 0);//定义版本号
		::WSAStartup(w, &data);//初始化套接字库
		SOCKET s;
		s = ::socket(AF_INET, SOCK_DGRAM, 0);//创建TCP套接字？？
		sockaddr_in addr, addr2;//定义套接字地址结构
		int n = sizeof(addr2);		
		addr.sin_family = AF_INET;//初始化地址结构
		addr.sin_port = htons(75);//设置端口号
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		::sendto(s, (char*)&rcvInput2, sizeof(rcvInput2)+1, 0, (sockaddr*)&addr, n);//向客户端发送字符数组
		::closesocket(s);//关闭套接字句柄
		::WSACleanup();//释放套接字库
		printf_s("%d,%d,%d,%d,%d\n", rcvInput2.j,rcvInput2.CTRFlag, rcvInput2.SELFlag, rcvInput2.NDMode, rcvInput2.NDRange);
		system("pause");
	}
	
	system("pause");
	return 0;
}