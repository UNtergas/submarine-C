#include<winsock2.h>
#include<stdio.h>
#include<WS2tcpip.h.>
#include<stringapiset.h>
#include<string.h>

#define PORT 9000

void binding(int bnd,SOCKET a, struct sockaddr_in b){
	if((bnd = bind (a,(SOCKADDR*)&b,sizeof (b))) == SOCKET_ERROR ){
		printf("bind failed-code %d\n",WSAGetLastError());
	}
	printf("bind success\n");
}

void listening(int lis,SOCKET a){
	if((lis=listen(a,3)) == SOCKET_ERROR){
		printf("listen error - %d\n",WSAGetLastError());
	}
	printf("listen success\n");
}
void sending(SOCKET sAcpt, char* mesg, int size ){
	send(sAcpt, mesg, size ,0);
}

void receiving(SOCKET sAcpt, char* mesg, int size){
	recv(sAcpt,mesg,size,0);
}

int main(){
	const char i4[]="127.0.0.1";
	wchar_t ipv4[40];
	MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,i4,-1,ipv4,40);

	WSADATA winsockdata;
	int iwsastart;
	int iwsaclean;

	SOCKET ServerSK;
	int icloseSK;
	struct sockaddr_in ServerAdr;
	struct sockaddr_in ClientAdr;
	int iClientAdr = sizeof(ClientAdr);

	int iBind;
	int iListen;
	
	int iSend;
	char SendMsg[512];
	//int iSendMsg = sizeof(SendMsg);

	int iRecv;
	char RecvMsg[512];
	//int iRecvMsg = sizeof(RecvMsg);

	SOCKET sAcceptSK;
	// structure
	ServerAdr.sin_family =AF_INET;
	ServerAdr.sin_port = PORT;
	InetPton(AF_INET,(LPCWSTR)ipv4,&ServerAdr.sin_addr.s_addr);

	// wsa-startup
	if((iwsastart=WSAStartup(MAKEWORD(2,2),&winsockdata))!= 0){
		printf("wsa start failed-code %d\n",WSAGetLastError());
	}
	printf("wsa started\n");

	//sk -initializing 
	if((ServerSK = socket(AF_INET, SOCK_STREAM),IPPROTO_TCP) == INVALID_SOCKET ){
		printf("initalizing error %d\n",WSAGetLastError());
	}
	printf("intialized\n");

	binding(iBind,ServerSK,ServerAdr);
	listening(iListen,ServerSK);

	//-accept connect
	if ((sAcceptSK = accecpt(ServerSK,(SOCKADDR*)&ClientAdr,&iClientAdr)) == INVALID_SOCKET){
		printf("accept error %d\n",WSAGetLastError() );
	}
	printf("connetc\n");

	//-send-receiver data
	while(true){
		printf("server:");
		fgets(SendMsg,512,stdin);
		if(SendMsg == 'done'){
			break;
		}
		sending(sAcceptSK,SendMsg,sizeof (SendMsg));
		receiving(sAcceptSK,RecvMsg,sizeof(RecvMsg));
	}

	//stoping operation
	if((shutdown(ServerSK,SD_BOTH))== SOCKET_ERROR){
		printf("shutdown error %d\n",WSAGetLastError() );
	}

	//close sk and cleanup
	closesocket(ServerSK);
	WSACleaup();
	fflush(stdin);
	getchar();
	return 0;
}