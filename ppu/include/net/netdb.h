#ifndef __NETDB_H__
#define __NETDB_H__

#include <net/socket.h>

#define NETDB_INTERNAL		-1
#define NETDB_SUCCESS		0x00
#define HOST_NOT_FOUND		0x01
#define TRY_AGAIN			0x02
#define NO_RECOVERY			0x03
#define NO_DATA				0x04
#define NO_ADDRESS			NO_DATA

extern int h_errno;

#ifdef __cplusplus
extern "C" {
#endif

struct hostent
{
	char *h_name;
	char **h_aliases;
	int h_addrtype;
	int h_length;
	char **h_addr_list;
	#define h_addr h_addr_list[0]
};

struct hostent* gethostbyaddr(const char *addr,socklen_t len,int tpye);
struct hostent* gethostbyname(const char *name);

#ifdef __cplusplus
	}
#endif

#endif
