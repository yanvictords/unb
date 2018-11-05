#include "../../include/DetectorTool/detectorTool.h"

int detectorTool(struct sockaddr_in addr, char * buffer, bool localNetHost)
{
	int status;

	printBegin();
	status =		analyzer(addr, buffer, localNetHost);
	printEnd();
	
	return status;
}

