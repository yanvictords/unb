// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// SERVIDOR DE TESTE

#include "refdec.h"
#include "dns_decoder.h"
#include <netinet/ip.h>
#include <sys/cdefs.h>

struct udphdr {
         u_int16_t uh_sport;           /* source port */
         u_int16_t uh_dport;           /* destination port */
         u_int16_t uh_ulen;            /* udp length */
         u_int16_t uh_sum;             /* udp checksum */
};
#

struct sockaddr_in servidor;
struct sockaddr_in source_socket_address, dest_socket_address;


void printHost(struct sockaddr_in * host)
{
	char node_addr[4096];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}

struct sockaddr_in mountAddr(unsigned long ipAddr, unsigned short port){
	struct sockaddr_in addr;
	addr.sin_addr.s_addr = ipAddr;
	addr.sin_port = port;
	addr.sin_family = AF_INET;
	memset(addr.sin_zero, 0x0, 8);

	return addr;
}

#define PORTA 9000
#define LEN 65536
int main()
{
	int sckRaw = socket(AF_INET, SOCK_RAW, IPPROTO_UDP); // AF_INET = protocolo usado
	int sckUdp = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET = protocolo usado
	int tam_buff;
	char buffer[LEN];

	printf("================ SERVIDOR - UDP =================\n\n");
//--- tenta criar socket pra linux + UDP
	if(sckRaw == -1 || sckUdp == -1)
	{
		printf("Houve problema ao criar socket\n");
		exit(1);
	}
	else
		printf("Socket criado com sucesso!\n");
//--- socket criado acima

    int one = 1;
    const int *val = &one;
    if (setsockopt (sckRaw, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
      printf ("Warning: Cannot set HDRINCL!\n");

//--- preenche struct com informações do seu endereço (servidor que vc esta desenvolvendo)
	servidor.sin_family = AF_INET; // *seu servidor roda em linux
	servidor.sin_port = htons(PORTA); // *seu servidor escutara nesta porte
	memset(servidor.sin_zero, 0x0, 8);

	int tam_addr_serv = sizeof(servidor); // tamanho da struct

//--- bind() associa o IP do socket criado la em cima à uma porta (literalmente). Aqui sua porta realmente estará aberta para aquele socket
	while(1) // A PARTIR DAQUI OCORREM AS TROCAS DE MENSAGENS
	{ 
		memset(buffer, 0x0, LEN);
		if((tam_buff = recvfrom(sckRaw, buffer, LEN, 0, (struct sockaddr*)&servidor, &tam_addr_serv)) > 0) // *RECV: FICA TRAVADO AQUI ATÉ RECEBER UMA MENSAGEM DO CLIENTE, salva em "buffer"
		{
			struct iphdr *ip_packet = (struct iphdr *)buffer;
			struct udphdr *udp_header = (struct udphdr *)&buffer[sizeof(struct iphdr)];

			memset(&source_socket_address, 0, sizeof(source_socket_address));
			source_socket_address.sin_addr.s_addr = ip_packet->saddr;
			memset(&dest_socket_address, 0, sizeof(dest_socket_address));
			dest_socket_address.sin_addr.s_addr = ip_packet->daddr;
			char * buf;
			buf = (char *) &buffer[sizeof(struct iphdr) + 8];

			if(ntohs(udp_header->uh_dport) == 9000){
			struct sockaddr_in addr = mountAddr(ip_packet->saddr, udp_header->uh_sport);
			printHost(&addr);

			printf("\n-------------\n");
			printf("Port source: %d\n", ntohs(udp_header->uh_sport));
			printf("Port destiny: %d\n", ntohs(udp_header->uh_dport));
			printf("Incoming Packet: \n");
			printf("Packet Size (bytes): %d\n",ntohs(ip_packet->tot_len));
			printf("Protocol: %u\n", (unsigned) ip_packet->protocol);
			printf("Source Address: %s\n", (char *)inet_ntoa(source_socket_address.sin_addr));
			printf("Destination Address: %s\n", (char *)inet_ntoa(dest_socket_address.sin_addr));
			printf("Identification: %d\n\n", ntohs(ip_packet->id));
   			printf("Mensagem: %s\n-------------\n", buf);
			printf("\n\nEsperando por novo cliente...\n");
			sendto(sckUdp, "DEU CERTO", sizeof("DEU CERTO"), 0, (struct sockaddr*)&addr, tam_addr_serv);
			}
		} //AQUI ELE OLTA PARA LOOP INFINITO, E VAI PARA O RECV FICAR TRAVADO ESPERANDO OUTRA MENSAGEM DO CLIENTE.
	}

	printf("\n\nFinalizando o servidor...\n");
	return 0;
}
