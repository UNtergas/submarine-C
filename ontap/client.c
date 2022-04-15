#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 1234
int main()
{
    int sock = 0, valread, errcode=0;
    struct sockaddr_in serv_addr;
    char *msg = "Bonjour server";
    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
//Convert IPv4 and IPv6 addresses from text to binary form
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock , msg , strlen(msg) , 0 );
    valread = read( sock , buffer, 1024);
    printf("RCV From server:%s\n",buffer );
    return 0;
}