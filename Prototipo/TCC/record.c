#include "record.h"

int packageRegistration(struct in_addr sin_addr, int operation, int protocol)
{
	int counter = updateCountersList(sin_addr, operation, protocol);
	return counter;
}

int updateCountersList(struct in_addr sin_addr, int operation, int protocol)
{
	unsigned long sAddr = sin_addr.s_addr;

	struct COUNT_ADDR * root;
	root = getProtocolRoot(protocol); // gets the list by protocol

	struct COUNT_ADDR * listAux, *predecessor;
	listAux = root;	
	predecessor = NULL;

	// if the list isn't empty, but the IP already registered in the list. Updates the root to updated counter node
	while (listAux!=NULL)
	{
		// If IP found
		if (listAux->sin_addr.s_addr == sAddr)
		{
			listAux->count += operation;
			
			// if the node isn't the root node, moves it off the list
			if (predecessor != NULL)
				predecessor->next = listAux->next;

			// Checks whether the host should be dropped from the list (black list or no more pending requests)
			if (mustKeepHostOnTheList(listAux))
			{
				// making the swap (putting the node at root of the list)
				listAux->next = root;
				root = listAux;
			}
			else
			{
				if (predecessor == NULL) // if the node which will be dropped is the root
					root = listAux->next;
				free(listAux);
			}

			setProtocolRoot(protocol, root);
			return root->count;
		}
		predecessor = listAux;
		listAux=listAux->next;
	}

	// If IP isn't registered yet. Updates the root to be the newer counter node
	root = create_node(root, sAddr);
	root->count += operation;
	setProtocolRoot(protocol, root);

	return root->count;
}

bool mustKeepHostOnTheList(struct COUNT_ADDR * listAux)
{
	if (listAux->count > 0) // if there is a pendant request
		return true;

	if (listAux->count == 0) // if all requests were responded
	{
		printAnotherStatus(_MODULE_RECORD, _ANOMALOUS_OP, "Matching: all operations with this IP address were resolved.");
		return false;
	}

	if (listAux->count < _LOW_LIMIT) // if the counter demonstrate a characteristic of DDoS attack by reflection
	{
		printAnotherStatus(_MODULE_RECORD, _ANOMALOUS_OP, "[WARNING] Anomalous operation: the counter negative value is less than allowed.");
		return false;
	}

	if (listAux->count < 0) // stay alert
	{
		printAnotherStatus(_MODULE_RECORD, _ANOMALOUS_OP, "[WARNING] Anomalous operation: a negative counter was detected.");
		return true;
	}
}

void setProtocolRoot(int protocol, struct COUNT_ADDR * root)
{
	switch (protocol)
	{
		case _DNS:
			p_dns = root;
			break;
		case _NTP:
			p_ntp = root;
			break;
		case _SNMP:
			p_snmp = root;
			break;
		case _SSDP:
			p_ssdp = root;
			break;
	}
}

struct COUNT_ADDR * getProtocolRoot(int protocol)
{
	switch (protocol)
	{
		case _DNS:
			return p_dns;
		case _NTP:
			return p_ntp;
		case _SNMP:
			return p_snmp;
		case _SSDP:
			return p_ssdp;
	}
}

struct COUNT_ADDR * create_node(struct COUNT_ADDR * next, unsigned long addr)
{
	struct COUNT_ADDR * newRoot = (struct COUNT_ADDR*) malloc(sizeof(struct COUNT_ADDR*));
	newRoot->next = next;
	newRoot->count = 0;
	newRoot->sin_addr.s_addr = addr;
	return newRoot;
}

void printAllCounters(int protocol)
{
	char aux[_LEN];
	int size=0;
	struct COUNT_ADDR * listAux;
	listAux = getProtocolRoot(protocol);

	printf("\n***Listing All Counters***\n");

	while(listAux!=NULL){
		inet_ntop(AF_INET, &(listAux->sin_addr), aux, _LEN);
		printf("IP: %s - Counter: %d\n", aux, listAux->count); 
		listAux=listAux->next;
		size++;
	}
	printf("*** Size: %d\n***End Counters***\n\n", size);
}
