// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// CLIENTE DE TESTE 

#include "refdec.h"

struct addrinfo hints, *results;

#define PORTA "80"
#define LEN 4096
int main()
{
	FILE *arq;
	arq=fopen("entrada.txt", "r+");

	printf("================ CLIENTE - TCP =================\n\n");

	int sockfd;
	int slen;
	char buffer[LEN];
	char domain[100];

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	
	printf("Digite o endereco: \n");
	scanf("%s", domain);
	
	if(getaddrinfo(domain, PORTA, &hints, &results) != 0)
	{
		printf("Deu ruim na hora de pegar o IP do dominio\n");
		exit(1);
	}

	sockfd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

	if(sockfd == -1)
	{
		perror("O socket nao foi criado com sucesso!\n");
		exit(1);	
	}
	else
	{
		printf("O socket foi criado com sucesso!\n");
	}

	if(connect(sockfd, results->ai_addr, results->ai_addrlen)==-1)
	{
		perror("O servidor final nao conectou!\n");	
		exit(1);
	}
	else
		perror("Conexao com o servidor final feita com sucesso!");

	while(1)
	{
		memset(buffer, 0x0, LEN);
		printf("Lendo arquivo\n");
		fread(buffer, sizeof(buffer), 1, arq);

		if(send(sockfd, buffer, sizeof(buffer), 0)) // faz um pedido ao proxy
		{
			if(!strcmp(buffer, "exit"))
				break;

			printf("Aguardando resposta do servidor...\n");
		}
		else
			printf("O servidor nao recebeu a mensagem...\n");
		if((slen = recv(sockfd, buffer, LEN, 0)) > 0) // Na primeira vez, espera a mensagem de bem-vindo do proxy; Recebe pedidos do proxy
		{
			buffer[slen] = '\0';
			printf("\n=> Mensagem Recebida do proxy: %s\n", buffer);
		}
		break;
	}
	
	close(sockfd);

	printf("\n\nFinalizando o cliente...\n");
	return 0;
}
