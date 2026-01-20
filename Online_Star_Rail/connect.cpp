#include <iostream>

#define PORT 8080
const char* server_ip = "172.27.201.62";

#if defined(_WIN32) || defined(_WIN64)
// Windows implementation
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

int close_socket(SOCKET& sock) {
    // Close socket
    closesocket(sock);
    WSACleanup();
    return 0;
}

int start_socket() {
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation error" << std::endl;
        WSACleanup();
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Send data
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent" << std::endl;

    close_socket(sock);

    return 0;
}



#else
// Unix/Linux implementation
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

int close_socket(SOCKET& sock) {
    // Close socket
    close(sock);
    return 0;
}

int start_socket() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        close(sock);
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        close(sock);
        return -1;
    }

    // Send data
    send(sock, hello, strlen(hello), 0);
    std::cout << "Message sent" << std::endl;

	close_socket(sock);

    return 0;
}



#endif