#include "../../../include/Api/Network/api_server.h"

#include "../../../include/Api/Network/utils.h"
#include "../../../include/Api/Network/socket.h"
#include "../../../include/DetectorTool/detectorTool.h"

void apiServer()
{
	// getNetworkConfInformations();
	_running = true;
	startApiServer();
}

void startApiServer()
{
	struct sockaddr_in * hostToAnalyzer;
	char * ipInterface;
	char buffer[_BUFFER_SIZE];
	long bufferSize;

	printf("[%s]: Starting Api server...\n", _API_SERVER);
	_sckRaw = createSocket(_RAW_ETH);
	_sckUdp = createSocket(_UDP);

	setEthHeaderInSocket(_sckRaw);
	
	ipInterface = getIpByInterfaceName(_sckRaw, _API_INTERFACE);
	printf("[%s] interface %s IP: %s\n", _API_SERVER, _API_INTERFACE, ipInterface);
	// _sourceAddr = mountCharAddrInfors(ipInterface, 9001);

//	bindPort(_sckRaw, _sourceAddr);

	while(_running)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		if(bufferSize = listenToPackages(_sckRaw, buffer, _BUFFER_SIZE, &_destinyAddr) > 0)
		{	 
			if(shouldAnalyzePackage(_sckRaw, buffer))
			{
				
				setSrcDestAddrs(buffer);
				_isLocal = ifLanIpAddress(inet_ntoa(getSAddrFromBuffer(buffer)));
				hostToAnalyzer = getAddrByAreaNetwork(_isLocal);

				// if (strcmp("192.168.15.2", (char *)inet_ntoa(getSAddrFromBuffer(buffer)))) { // For testing in lab
					printAllPacketContent(buffer);
					detectorTool(*hostToAnalyzer, getPayload(buffer), _isLocal);
					fflush(stdout);
				// }
				
				// sendPackage(_sckUdp, getPayload(buffer), _destinyAddr);
			}
		}
	}
}

_Bool shouldAnalyzePackage(int sck, char * buffer)
{
	return  (!ifLocalIpAddress(sck, buffer) && 
			ifIsUdpProtocol(buffer));
}

void setSrcDestAddrs(char * buffer)
{
	_sourceAddr = mountAddr(getSAddrFromBuffer(buffer).s_addr, getSPortFromBuffer(buffer));
	_destinyAddr = mountAddr(getDAddrFromBuffer(buffer).s_addr, getDPortFromBuffer(buffer));
}

struct sockaddr_in * getAddrByAreaNetwork(_Bool _isLocal)
{
	return _isLocal ? &_destinyAddr : &_sourceAddr;
}
