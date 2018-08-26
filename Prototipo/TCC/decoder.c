#include "decoder.h"

int packageDecoder(int protocol,  char * buffer)
{
	int operation;
	switch (protocol)
	{
		case _DNS:
			operation = getDnsOperation(buffer);
			break;
		case _NTP:
			operation = getNtpOperation(buffer);
			break;
		case _SNMP:
			operation = getSnmpOperation(buffer);
			break;
		case _SSDP:
			operation =	getSsdpOperation(buffer);
			break;
		default:
			operation = 	_UNKNOWN_QUERY_TYPE;
	}

	printQueryTypeAndProtocol(_MODULE_DECODER, operation, protocol);
	return operation;
}

int getDnsOperation(char * buffer)
{
	struct DNS_HEADER *dns;
    dns = (struct DNS_HEADER*) buffer;
	return (int) dns->qr;
}

int getNtpOperation(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}

int getSnmpOperation(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}

int getSsdpOperation(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}

