#include "../../include/DetectorTool/detectorTool.h"

#include "../../include/DetectorTool/ui.h"
#include "../../include/DetectorTool/analyzer.h"

int detectorTool(struct sockaddr_in addr, char * buffer)
{
	int status;

	printBegin();
	status =		analyzer(addr, buffer, false);
	printEnd();
	
	return status;
}

