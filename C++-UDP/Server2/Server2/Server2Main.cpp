//Server2，应先运行这个程序
#include<iostream>
#include<winsock2.h>
#include<stdio.h>

#pragma comment(lib,"WS2_32.lib")//显示连接套接字库
struct Input2        //需要接收的结构体
{
	int j;
	int CTRFlag;
	int SELFlag;
	int NDMode;
	int NDRange;
};
int main()
{
	while (true)
	{
		WSADATA data;//定义WSADATA结构体
		WORD w = MAKEWORD(2, 0);//定义版本号 
		char sztext[] = "Welcome you\r\n";//初始化套接字库
		::WSAStartup(w, &data);//初始化套接字库
		SOCKET s;
		s = ::socket(AF_INET, SOCK_DGRAM, 0);//创建TCP套接字？？
		sockaddr_in addr, addr2;//定义套接字地址结构
		int n = sizeof(addr2);
		addr.sin_family = AF_INET;//初始化地址结构
		addr.sin_port = htons(75);//设置端口号
		addr.sin_addr.S_un.S_addr = INADDR_ANY;
		::bind(s, (sockaddr*)&addr, sizeof(addr));
		
		char recvBuf[100] = { 0 };//用来存储接收的字符串

		::recvfrom(s, recvBuf, 100, 0, (sockaddr*)&addr, &n);
		::closesocket(s);//关闭套接字句柄
		::WSACleanup();//释放套接字库
		struct Input2 rec_udp;
		memcpy(&rec_udp, recvBuf, sizeof(rec_udp)+1);//将字符串转换为结构体
		printf_s("%d,%d,%d,%d,%d\n", rec_udp.j, rec_udp.CTRFlag, rec_udp.SELFlag, rec_udp.NDMode, rec_udp.NDRange);
		//system("pause");
	}
	

	system("pause");
	return 0;
}