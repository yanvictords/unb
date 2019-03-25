#include "../../essential.h"

#define _BUFFER_SIZE 65536

//===== NETWORK CONFIGURATION FILE
#define _NETWORK_CONF_FILE "network.conf"

//===== NETWORK CONFIGURATION FILE
#define _NETWORK_CONF_FILE "network.conf"

//===== MODULE
#define _UTILS_SERVER "UTILS"

//===== VARIABLES
#define _HEADER_ADDR_SZ sizeof(struct sockaddr)

//===== STRUCT's
struct udphdr {
         u_int16_t uh_sport;           /* source port */
         u_int16_t uh_dport;           /* destination port */
         u_int16_t uh_ulen;            /* udp length */
         u_int16_t uh_sum;             /* udp checksum */
};

struct sockaddr_in mountAddr(unsigned long ipAddr, unsigned int port);
struct sockaddr_in mountCharAddrInfors(char * ipAddress, unsigned int port);
void getSrcDestAddrFromHeaders(char * buffer, struct sockaddr_in * source, struct sockaddr_in * destiny);
char * getPayload(char * buffer);
void getNetworkConfInformations();
void generateNetworkConfFile(FILE * networkConf);
bool invalidPort(int port);
void printAllPacketContent(char * buffer);
void printHost(struct sockaddr_in * host);
void printBuffer(char * buffer, int size, bool localNetHost);
void printTrace(struct sockaddr_in src, struct sockaddr_in dest);
