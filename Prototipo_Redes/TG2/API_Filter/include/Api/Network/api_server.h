#include "../../essential.h"

#include <stdbool.h>

#define _TCP 0
#define _UDP 1
#define _RAW 2

#define _BUFFER_SIZE 65536
#define _LOW_BUFFER_SIZE 4096

//===== MODULE
#define _API_SERVER "API_SERVER"

struct sockaddr_in _sourceAddr;
struct sockaddr_in _destinyAddr;
int _sckRaw;
int _sckUdp;
bool _running;
bool _isLan;

void apiServer();
void startApiServer();
bool lanWanVerifier(struct sockaddr_in _sourceAddr);
