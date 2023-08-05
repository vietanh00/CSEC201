#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
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

    int iResult = getaddrinfo("localhost", DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error %d\n", iResult);
        WSACleanup();
        return 1;
    }

    SOCKET clientSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    connect(clientSocket, result->ai_addr, (int)result->ai_addrlen);
    freeaddrinfo(result);

    //msg to be sent
    char message[DEFAULT_BUFFLEN] = "hello";
    printf("hello server\n");
    iResult = send(clientSocket, message, DEFAULT_BUFFLEN, 0);

    ZeroMemory(message, DEFAULT_BUFFLEN);
    iResult = shutdown(clientSocket, SD_SEND);

    recv(clientSocket, message, DEFAULT_BUFFLEN, 0);
    printf("Received message: %s\n", message);
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
