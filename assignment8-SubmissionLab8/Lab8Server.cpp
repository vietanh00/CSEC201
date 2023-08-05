#define WIN32_LEAN_AND_MEAN

#include<windows.h>
#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<ws2tcpip.h>
#include<stdbool.h>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFFLEN 512
#define DEFAULT_PORT "27015"

typedef struct client {
    SOCKET client_socket;
    int client_id;
}CLIENT;

DWORD WINAPI handle_client(LPVOID client_info) {
    CLIENT* info = (CLIENT*)client_info;
    int id = info->client_id;
    SOCKET client_socket = info->client_socket;
    if (client_socket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    printf("Connecting Client %d.\n", id);
    char messageRecv[DEFAULT_BUFFLEN];
    ZeroMemory(messageRecv, DEFAULT_BUFFLEN);
    
    //Send greetings to client
    char hi[DEFAULT_BUFFLEN];
    sprintf_s(hi, "Client %d, Thank you for connecting!\n", id);
    send(client_socket, hi, DEFAULT_BUFFLEN, 0);

    //while loop until the client send 'quit'
    int iResult = recv(client_socket, messageRecv, DEFAULT_BUFFLEN, 0);
    while (strcmp(messageRecv, "quit") != 0) {
        //print out received data
        printf("From client %d:  %s\n", id, messageRecv);

        //send out confirmation to client N times
        //N is a random number between 2 and 10
        int count = (rand()% (10 - 2 + 1) + 1) ;
        for (int i = 0; i < count; i++) {
            iResult = send(client_socket, messageRecv, DEFAULT_BUFFLEN, 0);
        }

        //start receiving after sending
        ZeroMemory(messageRecv, DEFAULT_BUFFLEN);
        iResult = recv(client_socket, messageRecv, DEFAULT_BUFFLEN, 0);
    }

    //close connection
    shutdown(client_socket, SD_SEND);
    closesocket(client_socket);
    printf("Client %d disconnected.\n", id);
    return 0;
}


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

    //create server socket
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

    //ready to accept client connection
    HANDLE threads[100];
    int i = 0;
    bool going = true;

    while (going) {
        SOCKET client_socket = accept(serverSocket, NULL, NULL);
        //handle error
        if (client_socket == INVALID_SOCKET) {
            printf("No more clients.\n");
            closesocket(client_socket);
            WSACleanup();
            going = false;
            return 1;
        }
        CLIENT info;
        info.client_id = i + 1;
        info.client_socket = client_socket;
        threads[i] = CreateThread(NULL, 0, handle_client, &info, 0, NULL);

        if (threads[i] == NULL) {
            printf("CreateThread number %d failed with error code %d\n", i + 1, GetLastError());
            return 1;
        }
        i++;
    }
    WaitForMultipleObjects(i + 1, threads, TRUE, INFINITE);
}
