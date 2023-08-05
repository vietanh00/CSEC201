#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<WS2tcpip.h>
#include<stdbool.h>

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
    DWORD timeout = 1000;
    setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    char message[DEFAULT_BUFFLEN];

    //Receive welcome message
    iResult = recv(clientSocket, message, DEFAULT_BUFFLEN, 0);
    printf("%s", message);
    ZeroMemory(message, DEFAULT_BUFFLEN);

    //Prompt the user to send message
    printf("Enter your message to server, or 'quit': \n");
    scanf_s("%s", message, DEFAULT_BUFFLEN);

    //Loop until the user quits
    while (strcmp(message, "quit") != 0) {
        //send the message
        iResult = send(clientSocket, message, DEFAULT_BUFFLEN, 0);
        ZeroMemory(message, DEFAULT_BUFFLEN);

        bool receiving = true;
        //receive message and print it out until server stops sending (iResult = 0)
        //this is fine since the client is the one initiating the shutdown, not the server
        while (receiving) {
            iResult = recv(clientSocket, message, DEFAULT_BUFFLEN, 0);
            if (iResult > 0) {
                printf("Received message: %s\n", message);
                ZeroMemory(message, DEFAULT_BUFFLEN);
            }
            else {
                receiving = false;
                continue;
            }

            /*iResult = recv(clientSocket, message, DEFAULT_BUFFLEN, 0);
            printf("received: %s\n", message);
            ZeroMemory(message, DEFAULT_BUFFLEN);*/
        }

        //prompt the user for a message again
        printf("Enter your message to server, or 'quit': \n");
        scanf_s("%s", message, DEFAULT_BUFFLEN);
    }
    //Send quit message to server
    send(clientSocket, message, DEFAULT_BUFFLEN, 0);
    //shutdown and cleanup
    iResult = shutdown(clientSocket, SD_SEND);
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
