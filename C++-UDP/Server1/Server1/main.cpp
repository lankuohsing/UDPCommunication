#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"WS2_32.lib")//��ʾ�����׽��ֿ�
int main ( )
{
	WSADATA data;//����WSADATA�ṹ��
	WORD w = MAKEWORD ( 2, 0 );//����汾��
	char sztext [ ] = "Welcome you\r\n";//���岢��ʼ�����͵��ͻ��˵��ַ�����
	::WSAStartup ( w, &data );//��ʼ���׽��ֿ�
	SOCKET s;
	s = ::socket ( AF_INET, SOCK_DGRAM, 0 );
	sockaddr_in addr, addr2;//�����׽��ֵ�ַ�ṹ
	int n = sizeof( addr2 );
	char buff [ 16 ] = { 0 };//�������ݻ�����
	addr.sin_family = AF_INET;//��ʼ�����ʽṹ
	addr.sin_port = htons ( 75 );
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	::bind ( s, (sockaddr*)&addr, sizeof( addr ) );//���׽���
	printf ( "UDP Server already start!\r\n" );
	if ( ::recvfrom ( s, buff, 16, 0, (sockaddr*)&addr2, &n ) != -1 )//���տͻ�����Ϣ
	{
		printf ( "%s already connect\r\n", inet_ntoa ( addr2.sin_addr ) );
		::sendto ( s, sztext, sizeof( sztext ), 0, (sockaddr*)&addr2, n );//��ͻ��˷����ַ�����
		::closesocket ( s );//�ر��׽��־��
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