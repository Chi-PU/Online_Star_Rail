#pragma once

int connect();
int disconnect();
class Connection {
public:
	Connection();
	~Connection();
	bool isConnected() const;

private:	
	bool connected;
	int socket_fd;
};

class Queue {
	public:
	Queue();
	~Queue();
	void enqueue(const std::string& message);
	std::string dequeue();
	bool isEmpty() const;
};