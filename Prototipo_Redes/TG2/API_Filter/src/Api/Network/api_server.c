#include "../../../include/Api/Network/api_server.h"

#include "../../../include/Api/Network/utils.h"
#include "../../../include/Api/Network/socket.h"
#include "../../../include/DetectorTool/detectorTool.h"

#include <pthread.h>
#include <time.h>

void apiServer()
{
	// getNetworkConfInformations();
	_running = true;
	startApiServer();
}

void startApiServer()
{
	char buffer[_BUFFER_SIZE];
	long bufferSize;

	printf("[%s]: Starting Api server...\n", _API_SERVER);
	_sckRaw = createSocket(_RAW_UDP);
	_sckUdp = createSocket(_UDP);

	setIpHeaderInSocket(_sckRaw);

	_sourceAddr = mountCharAddrInfors("127.0.0.1", htons(8080));

	while(_running)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);

		if(bufferSize = listenToPackages(_sckRaw, buffer, _BUFFER_SIZE, _sourceAddr) > 0)
		{	
			getSrcDestAddrFromHeaders(buffer, &_sourceAddr, &_destinyAddr);
			if(ntohs(_destinyAddr.sin_port) == 9000)
			{
				printAllPacketContent(buffer);
				detectorTool(_sourceAddr, getPayload(buffer));
				_destinyAddr = mountAddr(_destinyAddr.sin_addr.s_addr, _sourceAddr.sin_port);
				sendPackage(_sckUdp, "Deu certo yan victor dos santos!\n", _LOW_BUFFER_SIZE, _destinyAddr);
			}
		}
	}
}
