#include "analyzer.h"

int main(){


return 0;
}

int package_analyzer(struct sockaddr_in addr, char * buffer, bool localNetHost)
{
	int protocol =		protocolIdentifier(addr.sin_port); // gets the protocol
	
	if (!protocol) // the protocol isn't able to be analyzed by this framework. The package will be forwarded without problems
	{
		printUnknownProtocol(_MODULE_ANALYZER);		
		printOkStatus(_MODULE_ANALYZER, _OK);	
		return _OK;
	}
	int operation =		packageDecoder(protocol, buffer); // gets the type of operation (RESPONSE OR QUERY)

	// alter the counter if the local server is querying or the outside server (maybe a reflector) is responding
	if ((localNetHost && operation == _QUERY) || (!localNetHost && operation == _RESPONSE))
	{
		int counter = 		packageRegistration(addr.sin_addr, operation, protocol);
		if (!localNetHost) // analyze the counter if the package comes from outside
			return analyzePackageCounter(counter, addr, protocol);

		printAllCounters(protocol);
	}

	// int this case, the package can be forwarded without problems
	printOkStatus(_MODULE_ANALYZER, _OK);	
	return _OK;
}

int analyzePackageCounter(int counter, struct sockaddr_in addr, int protocol)
{
	if (counter < _LOW_LIMIT) // if negative counter, probably the server is a reflector
	{
		printErrorStatus(_MODULE_ANALYZER, _REF_ATTACK_ALERT, "More replies than requests was detected (Outside->Inside).");
		printAlert(_MODULE_ANALYZER, addr, protocol, counter);
		return _REF_ATTACK_ALERT;
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK; // the package can ben forward without problems
}
