// connection_manager.hpp
#pragma once
#include <memory>
#include <unordered_map>
#include <mutex>
#include <openssl/ssl.h>
#include <libpq-fe.h> // PostgreSQL C API
#include "json.h"
#include <queue>

//socket lib
#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
typedef SOCKET socket_t;
#define INVALID_SOCK INVALID_SOCKET
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
typedef int socket_t;
#define INVALID_SOCK -1
#define closesocket close
#endif


class ClientSession {
public:
    int socket_fd;
    SSL* ssl;
    std::string auth_token;
    std::string user_id;
    bool authenticated = false;

    ClientSession(int fd, SSL* s) : socket_fd(fd), ssl(s) {}
    ~ClientSession();

    bool send_json(const SimpleJSON& data);
    SimpleJSON receive_json();
};

class DatabasePool {
    std::vector<PGconn*> connections;
    std::queue<PGconn*> available;
    std::mutex pool_mutex;

public:
    DatabasePool(const std::string& conn_string, size_t pool_size);
    ~DatabasePool();

    // RAII wrapper for getting/releasing connections
    class ScopedConnection {
        DatabasePool& pool;
        PGconn* conn;
    public:
        ScopedConnection(DatabasePool& p);
        ~ScopedConnection() { pool.release(conn); }
        PGconn* get() { return conn; }
    };

    PGconn* acquire();
    void release(PGconn* conn);
};

class GameServer {
    SSL_CTX* ssl_ctx;
    std::unique_ptr<DatabasePool> db_pool;

    // Thread-safe session management
    std::unordered_map<int, std::shared_ptr<ClientSession>> sessions;
    std::mutex sessions_mutex;

public:
    void initialize();
    void handle_client(int client_fd);
    void process_message(std::shared_ptr<ClientSession> session,
        const SimpleJSON& msg);
};