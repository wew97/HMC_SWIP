#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024

void sendFile(FILE *fp, int sockfd)
{
    char buffer[SIZE] = {0};

    while(fgets(buffer, SIZE, fp)!=NULL) {
        if(send(sockfd, buffer, sizeof(buffer), 0)== -1) {
            perror("[Error] in sendung data");
            exit(1);
        }

        printf("[SENT] %s", buffer);
        bzero(buffer, SIZE);
    }

    fclose(fp);
}

int main()
{
    char *ip = "172.16.0.137";       // IP address of server (RPi)
    int port = 8080;
    int ret;

    int clientSocket;
    struct sockaddr_in serverAddress;
    FILE *fp;
    char *filename = "message.txt";
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0) {
        perror("[Error] in socket");
        exit(1);
    }
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    serverAddress.sin_addr.s_addr = inet_addr(ip);
    
    ret = connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if(ret < 0) {
        perror("[Error] in Connecting");
        exit(1);
    }
     
    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("[Error] in reading file.");
        exit(1);
    }

    sendFile(fp, clientSocket);
    
    printf("\n[CLOSING] Disconnecting from the server.\n");
    close(clientSocket);
    return 0;
}