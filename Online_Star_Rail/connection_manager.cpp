#include "connection_manager.h"



//ClientSession::ClientSession(int fd, SSL* s)
//	: socket_fd(fd), ssl(s) {
//}
//ClientSession::~ClientSession() {
//	if (ssl) {
//		SSL_shutdown(ssl);
//		SSL_free(ssl);
//	}
//	if (socket_fd != INVALID_SOCK) {
//		closesocket(socket_fd);
//	}
//}