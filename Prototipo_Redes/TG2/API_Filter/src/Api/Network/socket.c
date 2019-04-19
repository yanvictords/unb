#include "../../../include/Api/Network/socket.h"

#include <netdb.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#define ETH_P_ALL	0x0003	
int createSocket(int type)
{
	int sck;
	char sckTypeName[8];
	
	switch (type) {
		case _TCP:
			sck = socket(AF_INET, SOCK_STREAM, 0);
			strcpy(sckTypeName, "TCP");
			break;
		case _UDP:
			sck = socket(AF_INET, SOCK_DGRAM, 0);
			strcpy(sckTypeName, "UDP");
			break;
		case _RAW_UDP:
			sck = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
			strcpy(sckTypeName, "RAW UDP");
			break;
		case _RAW_ETH:
			sck = socket(AF_PACKET , SOCK_RAW , htons(ETH_P_ALL));
			strcpy(sckTypeName, "RAW ETH");
			break;
	}

	if (sck < 0) 
	{
		printf("[%s]: There was a problem creating the socket.\n", _SOCKET);
		exit(1);
	} else
		printf("[%s]: Socket %s was successfully created!\n", _SOCKET, sckTypeName);

	return sck;
}

void closeSocket(int * socket)
{
	close(*socket);
}

void setIpHeaderInSocket(int socket)
{
    int one = 1;
    const int *val = &one;
    if (setsockopt (socket, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
		printf ("Warning: Cannot set HDRINCL!\n");
}

void setEthHeaderInSocket(int socket, char * interface)
{
	setsockopt(socket , SOL_SOCKET , SO_BINDTODEVICE , interface , strlen(interface)+ 1 );
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

ssize_t listenToPackages(int socket, char *buffer, int bufferSize, struct sockaddr_in * source)
{
	int sizeAddr = sizeof(*source);
	return recvfrom(socket, buffer, bufferSize, 0, (struct sockaddr*) source, &sizeAddr);
}

ssize_t sendPackage(int socket, char * buffer, struct sockaddr_in destiny)
{
	return sendto(socket, buffer, strlen(buffer), 0, (struct sockaddr*)&destiny, sizeof(destiny));
}
