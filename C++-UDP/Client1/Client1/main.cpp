#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"WS2_32.lib")//��ʾ�����׽��ֿ�
int main ( )
{
	WSADATA data;//����WSADATA�ṹ��
	WORD w = MAKEWORD ( 2, 0 );//����汾��
	::WSAStartup ( w, &data );//��ʼ���׽��ֿ�
	SOCKET s;
	s = ::socket ( AF_INET, SOCK_DGRAM, 0 );//����TCP�׽���
	sockaddr_in addr, addr2;
	int n = sizeof( addr2 );
	char buff [ 16 ] = "Wde";
	char sztext [ 16 ] = { 0 };
	addr.sin_family = AF_INET;//��ʼ�����ʽṹ
	addr.sin_port = htons ( 75 );
	addr.sin_addr.S_un.S_addr = inet_addr ( "127.0.0.1" );
	printf ( "UDP Clienct already start\r\n" );
	if ( ::sendto ( s, sztext, sizeof( sztext ), 0, (sockaddr*)&addr, n ) != 0 )
	{
		::recvfrom ( s, buff, 16, 0, (sockaddr*)&addr2, &n );
		printf ( "Server say:%s\r\n", buff );
		::closesocket ( s );
		::WSACleanup ( );//�ͷ��׽��ֿ�
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