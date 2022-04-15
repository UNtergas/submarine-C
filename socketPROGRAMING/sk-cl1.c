#include<winsock2.h>
#include<stdio.h>

#define PORT 9002
int main(){
	printf("------------client-------------/n");
	//local variable
	WSADATA winsockdata;
	int iwsastartup;
	int iwsacleanup;

	SOCKET TCPclientSocket;
	int icloseSK;

	struct sockaddr_in TCPserverAdd;
	//struct sockaddr_in TCPclientAdd;
	//int iTCPclientAdd = sizeof(TCPclientAdd);

	int iConnect;


	//SOCKET sAcceptSocket;

	int iSend;
	char SenderBuffer[512]="bien etendu";
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
	InetPton(AF_INET,("127.0.0.1"),&TCPserverAdd.sin_addr.s_addr);
	TCPserverAdd.sin_port = htons(PORT);

	//3- socket initiallizing
	TCPclientSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(TCPclientSocket == INVALID_SOCKET){
		printf("tcp server socket failled to create\n");
		printf("error code %d \n",WSAGetLastError());
	}
	printf("tcp server created success\n");
	
	//4- connect client to server function
	iConnect = connect (TCPclientSocket,(SOCKADDR*)&TCPserverAdd,sizeof(TCPserverAdd));
	if (iConnect == SOCKET_ERROR){
		printf("connect failled error code %d\n",WSAGetLastError());
	}
	printf("connect success\n");

	// //5- listen to client function
	// iListen = listen(TCPclientSocket,2);
	// if(iListen == SOCKET_ERROR){
	// 	printf("failed to listen error code %d\n",WSAGetLastError());
	// }
	// printf("listen sucess\n");

	// //6-accept connection
	// sAcceptSocket = accept(TCPclientSocket,(SOCKADDR*)&TCPclientAdd,&iTCPclientAdd);
	// if(sAcceptSocket == INVALID_SOCKET){
	// 	printf("connection not accepted error code %d\n",WSAGetLastError());
	// }
	// printf("connection accepted\n");

	//7-receive data
	iRecv=recv(TCPclientSocket,RecvBuffer,iRecvBuffer,0);
	if (iRecv == SOCKET_ERROR){
		printf("receive error code %d\n",WSAGetLastError() );
	}
	printf("received sucess %s\n",RecvBuffer);

	//8-Send Data to Client
	iSend=send(TCPclientSocket,SenderBuffer,iSenderBuffer,0);
	if (iSend == SOCKET_ERROR){
		printf("send file failed error code %d\n",WSAGetLastError());
	}
	printf("data sended success\n");

	//9-close socket
	icloseSK = closesocket(TCPclientSocket);
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