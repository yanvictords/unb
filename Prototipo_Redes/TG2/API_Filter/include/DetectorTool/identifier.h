#include "../essential.h"
#include "ui.h"

//===== PROTOCOLS
#define _DNS 1
#define _NTP 2
#define _SNMP 3
#define _SSDP 4
#define _UNKNOWN_PROTOCOL 0

//===== PROTOCOLS PORTS
#define _DNS_PORT 5003 // just for testings. Should be removed shortly. Please, remember to change back to 53 soon
#define _NTP_PORT 123
#define _SNMP_PORT 161
#define _SSDP_PORT 1900
#define _UNKNOWN_PROTOCOL 0

//===== MODULE
#define _MODULE_IDENTIFIER "IDENTIFIER"

int identifier(unsigned short port);
int protocolIdentifier(unsigned short port);
int identifyByPort(int port);
