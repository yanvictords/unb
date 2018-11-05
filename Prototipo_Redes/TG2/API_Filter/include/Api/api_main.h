#include <pthread.h>
#include <time.h>

#include "../essential.h"
#include "./Network/api_server.h"

//===== MODULE
#define _API_MAIN "API_MAIN"

// This API was created to filter data traffic between a LAN and the Internet
// If a reflector is detected then it will be blacklisted