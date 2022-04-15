#include<winsock2.h>
#include<stdio.h>

#define PORT 9002
int main(){
	printf("------------server-------------/n");
	//local variable
	WSADATA winsockdata;
	int iwsastartup;
	int iwsacleanup;

	SOCKET TCPserverSK;
	int icloseSK;
	struct sockaddr_in TCPserverAdd;
	struct sockaddr_in TCPclientAdd;
	int iTCPclientAdd = sizeof(TCPclientAdd);

	int iBind;

	int iListen;

	SOCKET sAcceptSocket;

	int iSend;
	char SenderBuffer[512]="server is calling, do you hear";
	int iSenderBuffer = sizeof ( SenderBuffer );

	int iRecv;
	char RecvBuffer[512];
	int iRecvBuffer = sizeof (RecvBuffer);
	
	//1- WSA-startingup
	iwsastartup = WSAStartup(MAKEWORD(2,2),&winsockdata);
	if(iwsastartup != 0){
		printf("wsa start up failed/n");
		printf("error code %d",WSAGetLastError());
	}
	printf("wsa start up success\n");

	//2- structure of the socket

	TCPserverAdd.sin_family = AF_INET;
	TCPserverAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	TCPserverAdd.sin_port = htons(PORT);

	//3- socket initiallizing
	TCPserverSK = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(TCPserverSK == INVALID_SOCKET){
		printf("tcp server socket failled to create\n");
		printf("error code %d \n",WSAGetLastError());
	}
	printf("tcp server created success\n");
	
	//4- binding to client function
	iBind = bind(TCPserverSK,(SOCKADDR*)&TCPserverAdd,sizeof(TCPserverAdd));
	if (iBind == SOCKET_ERROR){
		printf("binding failled error code %d\n",WSAGetLastError());
	}
	printf("binding success\n");

	//5- listen to client function
	iListen = listen(TCPserverSK,2);
	if(iListen == SOCKET_ERROR){
		printf("failed to listen error code %d\n",WSAGetLastError());
	}
	printf("listen sucess\n");

	//6-accept connection
	sAcceptSocket = accept(TCPserverSK,(SOCKADDR*)&TCPclientAdd,&iTCPclientAdd);
	if(sAcceptSocket == INVALID_SOCKET){
		printf("connection not accepted error code %d\n",WSAGetLastError());
	}
	printf("connection accepted\n");

	//7-Send Data to Client
	iSend=send(sAcceptSocket,SenderBuffer,iSenderBuffer,0);
	if (iSend == SOCKET_ERROR){
		printf("send file failed error code %d\n",WSAGetLastError());
	}
	printf("data sended success\n");

	//8-receive data
	iRecv=recv(sAcceptSocket,RecvBuffer,iRecvBuffer,0);
	if (iRecv == SOCKET_ERROR){
		printf("receive error code %d\n",WSAGetLastError() );
	}
	printf("received sucess %s\n",RecvBuffer);

	//9-close socket
	icloseSK = closesocket(TCPserverSK);
	if(icloseSK == SOCKET_ERROR){
		printf("closing error %d\n",WSAGetLastError() );
	}
	printf("closing done \n");

	//10-cleanup
	iwsacleanup=WSACleanup();
	if(iwsacleanup == SOCKET_ERROR){
		printf("cleaup failed error code %d\n",WSAGetLastError() );
	}
	printf("celanup succes\n");
	getchar();
	return 0;
}