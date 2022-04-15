#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 1234
int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *msg="Bonjour client!";
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;//internet
    address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons( PORT );
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    new_socket = accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen);
    valread = read(new_socket , buffer, 1024);
    if(valread>0)  printf("RCV from client:%s\n",buffer );
    send(new_socket , msg , strlen(msg) , 0 );
    close(new_socket);
    return 0;
}