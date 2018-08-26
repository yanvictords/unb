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

#include "decoder.h"
#include "record.h"
#include "identifier.h"
#include "feedback.h"

//===== PACKAGES
#define _QUERY 0
#define _RESPONSE 1
#define _UNKNOWN_QUERY_TYPE -1

//===== STATUS
#define _OK 1
#define _REF_ATTACK_ALERT -1

//===== BORDERS
#define _LOW_LIMIT -5
#define _HIGH_LIMIT 500

//===== MODULE
#define _MODULE_ANALYZER "ANALYZER"

int package_analyzer(struct sockaddr_in addr, char * buffer, bool localNetHost);
int analyzePackageCounter(int counter, struct sockaddr_in addr, int protocol);
