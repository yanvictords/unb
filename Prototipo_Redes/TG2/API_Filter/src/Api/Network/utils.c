#include "../../../include/Api/Network/utils.h"

struct sockaddr_in mountAddr(unsigned long ipAddr, unsigned int port){
	struct sockaddr_in addr;
	addr.sin_addr.s_addr = ipAddr;
	addr.sin_port = port;
	addr.sin_family = AF_INET;
	memset(addr.sin_zero, 0x0, 8);

	return addr;
}

struct sockaddr_in mountCharAddrInfors(char * ipAddress, unsigned int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}

void getSrcDestAddrFromHeaders(char * buffer, struct sockaddr_in * source, struct sockaddr_in * destiny)
{
	struct iphdr *ip_packet = (struct iphdr *)buffer;
	struct udphdr *udp_header = (struct udphdr *)&buffer[sizeof(struct iphdr)];

	memset(source, 0, sizeof(*source));
	source->sin_addr.s_addr = ip_packet->saddr;
	memset(destiny, 0, sizeof(*destiny));
	destiny->sin_addr.s_addr = ip_packet->daddr;

	source->sin_port = udp_header->uh_sport;
	destiny->sin_port = udp_header->uh_dport;
}

char * getPayload(char * buffer)
{
	return (char *) &buffer[sizeof(struct iphdr) + sizeof(struct udphdr)];
}

/* void getNetworkConfInformations()
{
	FILE *networkConf;
	
	printf("[%s]: ### Reading the networking settings... ###\n", _UTILS_SERVER);

	if(!(networkConf = fopen(_NETWORK_CONF_FILE, "r+")))
	{
		printf("[%s]: File %s was not found!\n", _UTILS_SERVER, _NETWORK_CONF_FILE);
		generateNetworkConfFile(networkConf);
	}
	else
	{
		char lanPort[6];
		char nonLanPort[6];

		fscanf(networkConf, "######## Network Settings ########\n@LOCAL_interface:\nport: %s\n\n@NONLOCAL_interface:\nport: %s\n", lanPort, nonLanPort);

		_local_interface_port = atoi(lanPort);
		_non_local_interface_port = atoi(nonLanPort);

		fclose(networkConf);

		if (invalidPort(_local_interface_port) || invalidPort(_non_local_interface_port))
			exit(1);
	}
}

 void generateNetworkConfFile(FILE * networkConf)
{
	networkConf = fopen(_NETWORK_CONF_FILE, "w+");

	printf("\n[%s]: ### Generating the Networking Settings... ###\n", _UTILS_SERVER);

	do {
		printf("[%s]: Local Port: ", _UTILS_SERVER);
		scanf("%d", &_local_interface_port);
	} while ( invalidPort(_local_interface_port) );

	do {
		printf("[%s]: Non-Local Port: ", _UTILS_SERVER);
		scanf("%d", &_non_local_interface_port);
	} while ( invalidPort(_non_local_interface_port) );

	fprintf(networkConf, "######## Network Settings ########\n@LOCAL_interface:\nport: %d\n\n@NONLOCAL_interface:\nport: %d\n", _local_interface_port, _non_local_interface_port);
	
	fclose(networkConf);
}


bool invalidPort(int port) 
{
	bool isInvalid = (port <= 0 || port > 65535);
	
	if (isInvalid)
		printf("[%s]: [ERROR] The port %d is out of range! Try another port...\n", _UTILS_SERVER, port);

	return isInvalid;
}
*/

void printAllPacketContent(char * buffer) {

	struct sockaddr_in source, destiny;
	struct iphdr *ip_packet = (struct iphdr *)buffer;
	struct udphdr *udp_header = (struct udphdr *)&buffer[sizeof(struct iphdr)];

	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = ip_packet->saddr;
	memset(&destiny, 0, sizeof(destiny));
	destiny.sin_addr.s_addr = ip_packet->daddr;
	char * buf;
	buf = (char *) &buffer[sizeof(struct iphdr) + sizeof(struct udphdr)];

	printf("\n-------------\n");
	printf("Source ip Address: %s\n", (char *)inet_ntoa(source.sin_addr));
	printf("Port source: %d\n", ntohs(udp_header->uh_sport));
	printf("Destination ip Address: %s\n", (char *)inet_ntoa(destiny.sin_addr));
	printf("Port destiny: %d\n", ntohs(udp_header->uh_dport));
	printf("Packet Size (bytes): %d\n",ntohs(ip_packet->tot_len));
	printf("Protocol: %u\n", (unsigned) ip_packet->protocol);
	printf("Identification: %d\n\n", ntohs(ip_packet->id));
	printf("Payload: %s\n-------------\n", buf);
}

void printHost(struct sockaddr_in * host)
{
	char node_addr[4096];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}

void printBuffer(char * buffer, int size, bool localNetHost)
{
	printf("\n");
	if (localNetHost)
		printf("[%s]: A new message was received from local server. Buffer size: %d", _UTILS_SERVER, size);
	else
		printf("[%s]: A new message was received from non-LOCAL server. Buffer size: %d\n", _UTILS_SERVER, size);
}

void printTrace(struct sockaddr_in src, struct sockaddr_in dest)
{
	char src_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(src.sin_addr), src_addr, INET_ADDRSTRLEN);
	char dest_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(dest.sin_addr), dest_addr, INET_ADDRSTRLEN);

	printf("[%s]: [TRACE] -> host[%s:%d] is sending a package to host[%s:%d]\n", 
		_UTILS_SERVER, src_addr, htons(src.sin_port), dest_addr, htons(dest.sin_port));
}
