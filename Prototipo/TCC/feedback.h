#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <arpa/inet.h>

#define _LEN 65536

void printQueryTypeAndProtocol(char * module, int operation, int protocol);
void printUnknownProtocol(char * module);
void printOkStatus(char * module, int status);
void printErrorStatus(char * module, int status, char * exception);
void printAnotherStatus(char * module, int status, char * event);
void printProtocolName(char * module, int protocol);
void printAlert(char * module, struct sockaddr_in addr, int protocol, int counter);
char * getProtocolName(int protocol);
