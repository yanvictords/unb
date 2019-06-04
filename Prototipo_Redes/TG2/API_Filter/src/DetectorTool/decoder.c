#include "../../include/DetectorTool/decoder.h"

#include "../../include/DetectorTool/ui.h"
#include "../../include/DetectorTool/identifier.h"

int decoder(int protocol, char * buffer)
{
	return packageDecoder(protocol, buffer);
}

int packageDecoder(int protocol,  char * buffer)
{
	int operation;
	switch (protocol)
	{
		case _DNS:
			operation = getDnsQueryType(buffer);
			break;
		case _NTP:
			operation = getNtpQueryType(buffer);
			break;
		case _SNMP:
			operation = getSnmpQueryType(buffer);
			break;
		case _SSDP:
			operation =	getSsdpQueryType(buffer);
			break;
		default:
			operation = 	_UNKNOWN_QUERY_TYPE;
	}

	printQueryType(_MODULE_DECODER, operation);
	return operation;
}

int getDnsQueryType(char * buffer)
{
	struct DNS_HEADER *dns;
    dns = (struct DNS_HEADER*) buffer;
	if(dns->qr == _DNS_RESPONSE)
		return _RESPONSE;
	if( dns->qr == _DNS_REQUEST)
		return _REQUEST;

	return _UNKNOWN_QUERY_TYPE;
}

int getNtpQueryType(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}

int getSnmpQueryType(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}

int getSsdpQueryType(char * buffer)
{
	return _UNKNOWN_QUERY_TYPE;
}


