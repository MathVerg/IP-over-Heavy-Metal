#ifndef SNIFFER_H
#define SNIFFER_H

#include "const.h"

/* gets the tun file dexcirptor */
int set_sniffer();

/*
Intercepts an ip packet sent to the tun interface
*/

void intercept_packet(int *tun_fd, packet *packet);

void print_packet(packet *packet);

#endif // SNIFFER_H
