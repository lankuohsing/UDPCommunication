//Client2��Ӧ�������������
#include<iostream>
#include<winsock2.h>
#include<stdio.h>

#pragma comment(lib,"WS2_32.lib")//��ʾ�����׽��ֿ�
struct Input2        //��Ҫ���͵Ľṹ��
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
		///////////socket��ʼ����һЩ����///////////
		WSADATA data;//����WSADATA�ṹ��
		WORD w = MAKEWORD(2, 0);//����汾��
		::WSAStartup(w, &data);//��ʼ���׽��ֿ�
		SOCKET s;
		s = ::socket(AF_INET, SOCK_DGRAM, 0);//����TCP�׽��֣���
		sockaddr_in addr, addr2;//�����׽��ֵ�ַ�ṹ
		int n = sizeof(addr2);		
		addr.sin_family = AF_INET;//��ʼ����ַ�ṹ
		addr.sin_port = htons(75);//���ö˿ں�
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		::sendto(s, (char*)&rcvInput2, sizeof(rcvInput2)+1, 0, (sockaddr*)&addr, n);//��ͻ��˷����ַ�����
		::closesocket(s);//�ر��׽��־��
		::WSACleanup();//�ͷ��׽��ֿ�
		printf_s("%d,%d,%d,%d,%d\n", rcvInput2.j,rcvInput2.CTRFlag, rcvInput2.SELFlag, rcvInput2.NDMode, rcvInput2.NDRange);
		system("pause");
	}
	
	system("pause");
	return 0;
}