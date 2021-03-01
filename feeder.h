#ifndef FEEDER_H
#define FEEDER_H

#include "const.h"

/*
Writes an ip âcket to the tun interface
*/

void write_packet(int *tun_fd, packet *packet);

#endif // FEEDER_H
