#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>

#include "../../essential.h"

#define _TCP 0
#define _UDP 1
#define _RAW 2

//===== MODULE
#define _SOCKET "SOCKET"

int createSocket(int type);
void bindPort(int sck, struct sockaddr_in addr);
ssize_t sendPackage(int sockfd, struct sockaddr_in * host, void * buf, int szBuf);
ssize_t rcvPackage(int sockfd, struct sockaddr_in * host, void * buf, int szBuf);
struct sockaddr_in setAddrInfors(unsigned int ipAddress, unsigned int port);
struct sockaddr_in setCharAddrInfors(char * ipAddress, unsigned int port);
