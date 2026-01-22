#pragma once
#include <atomic>
namespace Global{
	// Global variables
	std::atomic<int> active_threads(0);
	std::atomic<bool> server_running(true);
	int server_fd;
}