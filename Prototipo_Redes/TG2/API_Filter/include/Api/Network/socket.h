#include "../../essential.h"

#include <netinet/in.h>

#define _TCP 0
#define _UDP 1
#define _RAW_UDP 2

//===== MODULE
#define _SOCKET "SOCKET"

int createSocket(int type);
void closeSocket(int * socket);
void setIpHeaderInSocket(int socket);
void bindPort(int sck, struct sockaddr_in addr);
ssize_t listenToPackages(int socket, char *buffer, int bufferSize, struct sockaddr_in source);
ssize_t sendPackage(int socket, char * buffer, int bufferSize, struct sockaddr_in destiny);
