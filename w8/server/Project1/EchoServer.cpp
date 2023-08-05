#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFFLEN 512
#define DEFAULT_PORT "27015"

int main() {
    WSADATA wsaData;
    //initialize use of WSA_32.dll
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints)); //memset(&hints, 0, sizeof(hints))  in c
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    int iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error %d\n", iResult);
        WSACleanup();
        return 1;
    }

    //create server socket. Different in Windows
    SOCKET serverSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (serverSocket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    freeaddrinfo(result);
    //bind this socket to address
    iResult = bind(serverSocket, result->ai_addr, (int) result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //listen 
    listen(serverSocket, SOMAXCONN);
    printf("server is listening.\n");

    //while loop (infinite)
    //whenever this accepts: we create a thread to handle a client

    //ready to accept client connection
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //receive n send
    char messageRecv[DEFAULT_BUFFLEN];
    //ZeroMemory(messageRecv, DEFAULT_BUFFLEN);
    recv(clientSocket, messageRecv, DEFAULT_BUFFLEN, 0);
    printf("received message: %s ", messageRecv);
    send(clientSocket, messageRecv, DEFAULT_BUFFLEN, 0);
    //close connection
    shutdown(clientSocket, SD_SEND);
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
