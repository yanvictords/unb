#include "../../essential.h"
#include "api_server.h"

#define _BUFFER_SIZE 65536

//===== NETWORK CONFIGURATION FILE
#define _NETWORK_CONF_FILE "network.conf"

//===== MODULE
#define _UTILS_SERVER "UTILS"

//===== VARIABLES
#define _HEADER_ADDR_SZ sizeof(struct sockaddr)
#define _SOURCE 0
#define _DESTINY 1

//===== SIZEOF's
#define _SIZE_OF_ETH sizeof(struct ethhdr)
#define _SIZE_OF_IP sizeof(struct iphdr)
#define _SIZE_OF_UDP sizeof(struct udphdr)

#define _LOCAL_IP_ADDRESS "127.0.0.1"
#define _UDP_PROTOCOL 17

char * convertAddrToChar(struct in_addr ipAddr);

struct sockaddr_in mountAddr(unsigned long ipAddr, unsigned int port);
struct sockaddr_in mountCharAddrInfors(char * ipAddress, unsigned int port);

char * getPayload(char * buffer);
unsigned int getSPortFromBuffer(char * buffer);
unsigned int getDPortFromBuffer(char * buffer);
struct in_addr getSAddrFromBuffer(char * buffer);
struct in_addr getDAddrFromBuffer(char * buffer);
char * getIpByInterfaceName(int sck, char * interface);

void printAllPacketContent(char * buffer);
void printHost(struct sockaddr_in * host);
void printBuffer(char * buffer, int size, bool localNetHost);
void printTrace(struct sockaddr_in src, struct sockaddr_in dest);

_Bool ifLocalIpAddress(int sck, char * buffer);
_Bool ifLanIpAddress(char * ipAddr);
_Bool ifIsUdpProtocol(char * buffer);
