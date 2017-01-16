#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"WS2_32.lib")//显示连接套接字库
int main ( )
{
	WSADATA data;//定义WSADATA结构体
	WORD w = MAKEWORD ( 2, 0 );//定义版本号
	::WSAStartup ( w, &data );//初始化套接字库
	SOCKET s;
	s = ::socket ( AF_INET, SOCK_DGRAM, 0 );//创建TCP套接字
	sockaddr_in addr, addr2;
	int n = sizeof( addr2 );
	char buff [ 16 ] = "Wde";
	char sztext [ 16 ] = { 0 };
	addr.sin_family = AF_INET;//初始化地质结构
	addr.sin_port = htons ( 75 );
	addr.sin_addr.S_un.S_addr = inet_addr ( "127.0.0.1" );
	printf ( "UDP Clienct already start\r\n" );
	if ( ::sendto ( s, sztext, sizeof( sztext ), 0, (sockaddr*)&addr, n ) != 0 )
	{
		::recvfrom ( s, buff, 16, 0, (sockaddr*)&addr2, &n );
		printf ( "Server say:%s\r\n", buff );
		::closesocket ( s );
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