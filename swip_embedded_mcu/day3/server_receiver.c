#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024

void receiveFile(int sockfd, const char *filename) {
    char buffer[SIZE] = {0};
    int bytesRead;

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("[Error] in creating file");
        exit(1);
    }

    while ((bytesRead = recv(sockfd, buffer, SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesRead, fp);
        fwrite(buffer, 1, bytesRead, stdout);  // Print to stdout
    }

    printf("\n");

    fclose(fp);
}

int main() {
    int port = 8080;
    int ret;

    int serverSocket, newSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t addrSize = sizeof(clientAddress);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("[Error] in socket");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    ret = bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (ret < 0) {
        perror("[Error] in binding");
        exit(1);
    }

    ret = listen(serverSocket, 10);
    if (ret == 0) {
        printf("[INFO] Server listening on port %d...\n", port);
    } else {
        perror("[Error] in listening");
        exit(1);
    }

    newSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &addrSize);
    if (newSocket < 0) {
        perror("[Error] in accepting");
        exit(1);
    }

    char *filename = "received.txt";
    receiveFile(newSocket, filename);

    printf("[CLOSING] Closing server.\n");
    close(newSocket);
    close(serverSocket);
    return 0;
}
