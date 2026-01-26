#pragma once

#include "socket.h"
#include <iostream>
#include <cstdio>
#include <cerrno>
#define PORT 8080
const char* server_ip = "172.27.201.62";

class ConnectManager {
public:
	ConnectManager();
};