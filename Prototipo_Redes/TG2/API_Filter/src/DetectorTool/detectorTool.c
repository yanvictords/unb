#include "../../include/DetectorTool/detectorTool.h"

#include "../../include/DetectorTool/ui.h"
#include "../../include/DetectorTool/analyzer.h"

int detectorTool(struct sockaddr_in addr, char * buffer, _Bool isLan)
{
	int status;

	printBegin();
	status =		analyzer(addr, buffer, isLan);
	printEnd();
	
	return status;
}

