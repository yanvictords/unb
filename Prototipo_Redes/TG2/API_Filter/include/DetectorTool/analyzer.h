#include "../../include/essential.h"

#include <stdbool.h>

#define _DEBUGGER_MODE

//===== STATUS
#define _OK 1
#define _REF_ATTACK_ALERT -1
#define _REJECT_ADDR 0

//===== BORDERS
#define _HIGH_LIMIT 500

//===== MODULE
#define _MODULE_ANALYZER "ANALYZER"

//===== FILE
#define _BLACK_LIST_FILE "blacklist.txt"

int analyzer(struct sockaddr_in addr, char * buffer, bool localNetHost);
int packageAnalyzer(struct sockaddr_in addr, char * buffer, bool localNetHost);
int analyzePackageCounter(int counter, struct sockaddr_in addr, int protocol);
bool getAddrInBlackList(struct sockaddr_in addr);
void putAddrInBlackList(struct sockaddr_in addr);
