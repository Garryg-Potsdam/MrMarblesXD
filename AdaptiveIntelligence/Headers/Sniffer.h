/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sniffer.h
 * Author: garry
 *
 * Created on March 19, 2017, 10:57 AM
 */

#include <stddef.h>
#include <pcap.h>
#include <string.h> //for memset

#include <sys/socket.h>
#include <arpa/inet.h> // for inet_ntoa()
#include <net/ethernet.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <mpi.h>
#include <pthread.h>

#include "../Headers/PacketQueue.h"


// Parameters:  Queue* - a queue of packets
// Post-Condition: establishes connections to network ports and then
//                 adds packet traffic to the queue
void storePackets(Queue*);

// Parameters: Queue* - queue of packets
// Post-Condition: delivers packets to other rank
void sendPackets(Queue*);

// Parameters:      u_char* - the parameters passed from pcap_loop call
//             pcap_pkthdr* - a struct with packet header data
//                  u_char* - the buffer of the body of the packet data
void process_packet(u_char*, const struct pcap_pkthdr*, const u_char*);

/*
void process_ip_packet(const u_char * , int);
void print_ip_packet(const u_char * , int);
void print_tcp_packet(const u_char *  , int );
void print_udp_packet(const u_char * , int);
void print_icmp_packet(const u_char * , int );
*/


