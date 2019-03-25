#include "../../include/DetectorTool/identifier.h"

#include "../../include/DetectorTool/ui.h"

int identifier(unsigned short port)
{
	return protocolIdentifier(port);
}

int protocolIdentifier(unsigned short port)
{
	int protocol = identifyByPort(htons(port));
	printProtocolName(_MODULE_IDENTIFIER, protocol);
	return protocol;
}

int identifyByPort(int port)
{
	switch (port)	
	{
		case _DNS_PORT:
		case 503: // just for testing. Should be removed shortly
			return _DNS;
		case _NTP_PORT:
			return _NTP;		
		case _SNMP_PORT:
			return _SNMP;
		case _SSDP_PORT:
			return _SSDP;
		// default:  just for testing. Should be removed shortly
			// return _DNS;
	}
	return _UNKNOWN_PROTOCOL;
}
