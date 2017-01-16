#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"WS2_32.lib")//显示连接套接字库
int main ( )
{
	WSADATA data;//定义WSADATA结构体
	WORD w = MAKEWORD ( 2, 0 );//定义版本号
	char sztext [ ] = "Welcome you\r\n";//定义并初始化发送到客户端的字符数组
	::WSAStartup ( w, &data );//初始化套接字库
	SOCKET s;
	s = ::socket ( AF_INET, SOCK_DGRAM, 0 );
	sockaddr_in addr, addr2;//定义套接字地址结构
	int n = sizeof( addr2 );
	char buff [ 16 ] = { 0 };//接收数据缓冲区
	addr.sin_family = AF_INET;//初始化地质结构
	addr.sin_port = htons ( 75 );
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	::bind ( s, (sockaddr*)&addr, sizeof( addr ) );//绑定套接字
	printf ( "UDP Server already start!\r\n" );
	if ( ::recvfrom ( s, buff, 16, 0, (sockaddr*)&addr2, &n ) != -1 )//接收客户端信息
	{
		printf ( "%s already connect\r\n", inet_ntoa ( addr2.sin_addr ) );
		::sendto ( s, sztext, sizeof( sztext ), 0, (sockaddr*)&addr2, n );//向客户端发送字符数组
		::closesocket ( s );//关闭套接字句柄
		::WSACleanup ( );//释放套接字库
	}
	if ( getchar ( ) )
	{
		return 0;
	}
	else
	{
		::Sleep ( 100 );
	}
}