#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>

#define UDP SOCK_DGRAM
#define PORT 9999

int main(int argc, char* argv[]){
    int socketFD = socket(AF_INET, UDP,0);
    printf("SOCKET SUCCESS\n");
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(INADDR_ANY);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    int bindResult = bind(socketFD, &address, sizeof(address));
    printf("[BIND SUCCESSS]\n");

    char *ip = argv[1];
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    const char *message ="12191713 이재훈";
    sendto(socketFD, message, strlen(message),0,&serverAddr,sizeof(serverAddr));
    printf("[SENT]: %s\n",message);

    int serverAddresSize = sizeof(serverAddr);
    char buffer[512];
    size_t recvSize = recvfrom(socketFD,buffer,sizeof(buffer),0,&serverAddr,&serverAddresSize);
    printf("[RECEIVED]: \"%s\"\n",buffer);
    close(socketFD);
    return 0;
}