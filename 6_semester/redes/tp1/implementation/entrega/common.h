#ifdef __cplusplus
extern "C"
{
#endif

#pragma once

#include <stdlib.h>

#include <arpa/inet.h>

	void logexit(const char *msg);

	int addrparse(const char *addrstr, const char *portstr,
				  struct sockaddr_storage *storage);

	void addrtostr(const struct sockaddr *addr, char *str, size_t strsize);

	int server_sockaddr_init(const char *proto, const char *portstr,
							 struct sockaddr_storage *storage);

	int is_valid_char(char c);

	int is_valid_message(const char *msg);

#ifdef __cplusplus
}
#endif
