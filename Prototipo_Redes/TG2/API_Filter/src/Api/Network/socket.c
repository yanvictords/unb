#include "../../../include/Api/Network/socket.h"

int createSocket(int type)
{
	int sck;
	
	switch (type) {
		case _TCP:
			sck = socket(AF_INET, SOCK_STREAM, 0);
			break;
		case _UDP:
			sck = socket(AF_INET, SOCK_DGRAM, 0);
			break;
		case _RAW:
			sck = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
			break;
	}

	if (sck < 0) 
	{
		printf("[%s]: There was a problem creating the socket.\n", _SOCKET);
		exit(1);
	}
	// else
		// printf("[%s]: Socket was successfully created!\n", _SOCKET);
	
	return sck;
}

void bindPort(int sck, struct sockaddr_in addr)
{
	if (bind(sck, (struct sockaddr *) &addr, sizeof(addr)) == -1 )
	{	
		printf("[%s]: There was a problem opening the port %d...\n", _SOCKET, htons(addr.sin_port));
		exit(1);
	}
	else
		printf("[%s]: Port %d was successfully opened! Listening...\n", _SOCKET, htons(addr.sin_port));
}

ssize_t sendPackage(int sockfd, struct sockaddr_in * host, void * buf, int szBuf)
{
	return sendto(sockfd, buf, szBuf, 0, (struct sockaddr*) host, sizeof(*host));
}

ssize_t rcvPackage(int sockfd, struct sockaddr_in * host, void *buf, int szBuf)
{
	int sizeHost = sizeof(host);
	return recvfrom(sockfd, buf, szBuf, 0, (struct sockaddr*) host, &sizeHost);
}

struct sockaddr_in setAddrInfors(unsigned int ipAddress, unsigned int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}

struct sockaddr_in setCharAddrInfors(char * ipAddress, unsigned int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}