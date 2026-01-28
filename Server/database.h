#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include <libpq-fe.h>

class Database {
public:
    Database(const std::string& host, const std::string& port,
        const std::string& dbname, const std::string& user,
        const std::string& password);
    ~Database();

    bool connect();
    void disconnect();
    bool isConnected() const;

    bool initializeDatabase();
    bool dropAllTables();

private:
    std::string host_;
    std::string port_;
    std::string dbname_;
    std::string user_;
    std::string password_;
    PGconn* conn_;

    bool executeQuery(const std::string& query);
    bool createTables();
    bool createIndexes();
    bool createForeignKeys();
    void printError(const std::string& message);
};

#endif // DATABASE_H