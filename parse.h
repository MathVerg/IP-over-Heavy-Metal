#ifndef PARSE_H
#define PARSE_H

#include "const.h"

/*
Once the byte sequence is received, the program must "forward it".
The program simply parses the packet, and then creates a new socket
*/

typedef struct packet_info {
    char dest[16]; // eg "129.104.201.123"
    char from[16];
    char protocole[4]; // TCP or UDP
    int version; // 4 or 6
    char payload[MTU];
} packet_info;

/* Parses a dataBuffer and fills a packet_info */

void parse_packet(packet *packet, packet_info *info);

void print_packet_info(packet_info *info);

#endif // PARSE_H