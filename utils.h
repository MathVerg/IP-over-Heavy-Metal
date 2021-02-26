#ifndef UTILS_H
#define UTILS_H

#include "const.h"

/* Index of the max of a float array */
int indMaxFloatArray(float *t, int t_length);

/* Index of the closest number in a sorted array */
int indClosestInArray(float needle, float *t, int t_length);

/* conversions between packet and metalBuffer */

void packet_to_metalBuffer(metalBuffer *data, packet *packet);
void metalBuffer_to_packet(packet *packet, metalBuffer *data);

/* prints a byte */

void print_byte(unsigned char b);

void packet_binary(char *buf, packet *packet);

int nbdigits(unsigned int x);

#endif //UTILS_H
