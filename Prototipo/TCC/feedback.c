#include "feedback.h"

void printQueryTypeAndProtocol(char * module, int operation, int protocol)
{
	if (operation == 0)
		printf("[%s]: The package is a QUERY/REQUEST :: %s protocol.\n", module, getProtocolName(protocol));
	else if (operation == 1)
		printf("[%s]: The package is a RESPONSE :: %s protocol.\n", module, getProtocolName(protocol));
	else
		printf("[%s]: The package type is UNKNOWN :: %s protocol.\n", module, getProtocolName(protocol));
}

void printUnknownProtocol(char * module)
{
	printf("[%s]: Unknown protocol. The packet can't be decoded...\n", module);
}

void printOkStatus(char * module, int status)
{
	printf("[%s]: Status %d. The package can be forwarded without problems!\n", module, status);
}

void printErrorStatus(char * module, int status, char * exception)
{
	printf("[%s]: Status %d. Error: A problem was detected!\nThrown Exception: %s\n", module, status, exception); 	
}

void printAnotherStatus(char * module, int status, char * event)
{
	printf("[%s]: Status %d. A different event occurred.\nEvent Description: %s\n", module, status, event);
}

void printProtocolName(char * module, int protocol)
{
	printf("[%s]: %s protocol detected.\n", module, getProtocolName(protocol));
}

void printAlert(char * module, struct sockaddr_in addr, int protocol, int counter)
{
	char node_addr[_LEN];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\n************************ALERT****************************\n");
	printf("%s: The non-local server is being a reflector candidate!\n", module);
	printf("Host: %s:%d :: %s protocol package", node_addr, htons(addr.sin_port), getProtocolName(protocol));
	printf("Counter: %d\n", counter);
	printf("************************ALERT****************************\n\n");
}

char * getProtocolName(int protocol){
	switch (protocol)
	{
		case 1: //dns
			return "DNS";
		case 2: //ntp
			return "NTP";		
		case 3: //snmp
			return "SNMP";
		case 4: //ssdp
			return "SSDP";
	}
	return "UNKNOWN";
}
