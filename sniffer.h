#ifndef SNIFFER_H
#define SNIFFER_H

#include "const.h"


/*
Intercepts an ip packet sent to the tun interface
*/

void intercept_packet(int tun_fd, packet *packet);

#endif // SNIFFER_H
