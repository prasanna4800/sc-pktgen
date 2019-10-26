#ifndef __PKTGEN__
#define __PKTGEN__

#include <netinet/if_ether.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>

#include "utils.h"

/* basic encap. func for ethernet header */
void encap_eth_default(char *pkt);
void encap_ipv4_default(char *pkt);
void encap_tcp_default(char *pkt);

/* generate dummy pkt */ 
void gen_dummy_pkt(char *pkt);

#endif 