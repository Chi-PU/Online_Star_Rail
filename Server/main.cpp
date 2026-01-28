#include "database.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::cout << "Gacha Game Database Initialization\n" << std::endl;

    // Database connection parameters
    // These can be overridden by environment variables or command line arguments
    std::string host = std::getenv("DB_HOST") ? std::getenv("DB_HOST") : "localhost";
    std::string port = std::getenv("DB_PORT") ? std::getenv("DB_PORT") : "5432";
    std::string dbname = std::getenv("DB_NAME") ? std::getenv("DB_NAME") : "gacha_game";
    std::string user = std::getenv("DB_USER") ? std::getenv("DB_USER") : "postgres";
    std::string password = std::getenv("DB_PASSWORD") ? std::getenv("DB_PASSWORD") : "password";

    // Parse command line arguments if provided
    if (argc > 1) host = argv[1];
    if (argc > 2) port = argv[2];
    if (argc > 3) dbname = argv[3];
    if (argc > 4) user = argv[4];
    if (argc > 5) password = argv[5];

    std::cout << "Connection Parameters:" << std::endl;
    std::cout << "  Host: " << host << std::endl;
    std::cout << "  Port: " << port << std::endl;
    std::cout << "  Database: " << dbname << std::endl;
    std::cout << "  User: " << user << std::endl;
    std::cout << std::endl;

    // Create database instance
    Database db(host, port, dbname, user, password);

    // Connect to database
    if (!db.connect()) {
        std::cerr << "Failed to connect to database!" << std::endl;
        return 1;
    }

    // Initialize database
    if (!db.initializeDatabase()) {
        std::cerr << "Failed to initialize database!" << std::endl;
        db.disconnect();
        return 1;
    }

    std::cout << "\nDatabase initialization completed successfully!" << std::endl;
    std::cout << "You can now start using the gacha game database." << std::endl;

    // Disconnect
    db.disconnect();

    return 0;
}