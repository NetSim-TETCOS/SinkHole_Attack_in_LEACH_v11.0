

/****************************************************
         This file contains code for generation of Malicious Node(SinkHole) for networks running DSR in Layer3.
		 This works only for UDP and not for TCP.
		 
		 
		 The function fn_NetSim_DSR_MaliciousNode(NetSim_EVENTDETAILS*) 
		 return 1 when the deviceID is the malicious node which is mentioned in the if statement in the function definition.

		
		 The function fn_NetSim_DSR_MaliciousProcessSourceRouteOption(NetSim_EVENTDETAILS*)
		 does not call the NetworkOut Event and destroys the packet.

		 Code Flow - 
		 If The Node is a Malicious Node, Then when a Route Request is Received, the Function adds the route from itself 
		 to the target in the route cache and sends a false route reply.
		 When a malicious node receives a data packet, it gives acknowledge reply and frees the packet.
		
		 
*****************************************************/


	/* Malicious Node */


#include "main.h"
#include "DSR.h"
#include "List.h"
#define MALICIOUS_NODE1 4

int fn_NetSim_DSR_MaliciousNode(NETSIM_ID DevId);
int fn_NetSim_DSR_MaliciousRouteAddToCache(NetSim_EVENTDETAILS*);
int fn_NetSim_DSR_MaliciousProcessSourceRouteOption(NetSim_EVENTDETAILS*);


int fn_NetSim_DSR_MaliciousNode(NETSIM_ID DevId)
{
	if(DevId == MALICIOUS_NODE1 )
		{//for 3 malicious nodes if(pstruEventDetails->nDeviceId ==28||pstruEventDetails->nDeviceId ==22||pstruEventDetails->nDeviceId ==34)
		//just mention in the if statement the id of the device you want to be malicious node)
		return 1;
		}
	return 0;
}

int fn_NetSim_DSR_MaliciousProcessSourceRouteOption(NetSim_EVENTDETAILS* pstruEventDetails)
{
	NetSim_PACKET* packet = pstruEventDetails->pPacket;
	fn_NetSim_Packet_FreePacket(pstruEventDetails->pPacket);
	return 0;
}
