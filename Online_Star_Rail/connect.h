//#pragma once
//#include <iostream>
//#include <cstring>
//#define PORT 8080
//
//#include "json.h"
//
//#if defined(_WIN32) || defined(_WIN64)
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#pragma comment(lib, "ws2_32.lib")
//typedef SOCKET socket_t;
//#define INVALID_SOCK INVALID_SOCKET
//#else
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <netdb.h>
//typedef int socket_t;
//#define INVALID_SOCK -1
//#define closesocket close
//#endif
//int start_socket();
//
//class SQL {
//public:
//		static void init();
//		static void close();
//};
//class Connestion {
//public:
//    Connestion();
//	~Connestion();
//};
