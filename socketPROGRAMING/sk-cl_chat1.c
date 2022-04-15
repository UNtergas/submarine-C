#include<winsock2.h>
#include<stdio.h>
#include<WS2tcpip.h.>
#include<stringapiset.h>
#include<string.h>

#define PORT 9000

void connecting(int cnt, SOCKET a, struct sockaddr_in b) {
	if ((cnt = connect(a, (SOCKADDR*)&b, sizeof(b))) == SOCKET_ERROR) {
		printf("connect failed-code %d\n", WSAGetLastError());
	}
	printf("connect success\n");
}

void sending(SOCKET clsk, char* mesg, int size) {
	send(sAcpt, mesg, size, 0);
}

void receiving(SOCKET clsk, char* mesg, int size) {
	recv(sAcpt, mesg, size, 0);
}

int main() {
	const char i4[] = "192.168.1.7";
	wchar_t ipv4[40];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, i4, -1, ipv4, 40);

	WSADATA winsockdata;
	int iwsastart;
	//int iwsaclean;

	SOCKET ClientSK;
	//int icloseSK;
	struct sockaddr_in ServerAdr;


	int iConnect=0;

	//int iSend;
	char SendMsg[512];
	char stopchat[] = "done";
	//int iSendMsg = sizeof(SendMsg);

	//int iRecv;
	//char RecvMsg[512];
	//int iRecvMsg = sizeof(RecvMsg);
	// structure
	ServerAdr.sin_family = AF_INET;
	ServerAdr.sin_port = PORT;
	InetPton(AF_INET, (LPCWSTR)ipv4, &ServerAdr.sin_addr.s_addr);

	// wsa-startup
	if ((iwsastart = WSAStartup(MAKEWORD(2, 2), &winsockdata)) != 0) {
		printf("wsa start failed-code %d\n", WSAGetLastError());
	}
	printf("wsa started\n");

	//sk -initializing 
	if ((ClientSK = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
		printf("initalizing error %d\n", WSAGetLastError());
	}
	printf("intialized\n");

	connecting(iConnect,ServerAdr);

	//-send-receiver data
	while (1) {
		printf("server:");
		fgets(SendMsg, 512, stdin);
		if ((strcmp(SendMsg,stopchat)) == 0) {
			break;
		}
		sending(ClientSK, SendMsg, sizeof(SendMsg));
		receiving(ClientSK, RecvMsg, sizeof(RecvMsg));
	}

	//stoping operation
	if ((shutdown(ClientSK, SD_BOTH)) == SOCKET_ERROR) {
		printf("shutdown error %d\n", WSAGetLastError());
	}

	//close sk and cleanup
	closesocket(ClientSK);
	WSACleanup();
	fflush(stdin);
	getchar();
	return 0;
}