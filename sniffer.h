#ifndef SNIFFER_H
#define SNIFFER_H

#include "sound.h"

/*
An ip packet is sent to the tun interface
intercept_packet returns a pointer to a structure representing this packet
*/

void intercept_packet(packet *packet);

void print_packet(packet *packet);

#endif // SNIFFER_H