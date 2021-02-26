#ifndef UTILS_H
#define UTILS_H

#include "const.h"

/* Index of the max of a float array */
int indMaxFloatArray(float *t, int t_length);

/* Index of the closest number in a sorted array */
int indClosestInArray(float needle, float *t, int t_length);

/* packet to dataBuffer */

void packet_to_dataBuffer(packet *packet, dataBuffer *data);
void dataBuffer_to_packet(packet *packet, dataBuffer *data);

/* prints a byte */

void print_byte(unsigned char b);

void packet_binary(char *buf, packet *packet);

int nbdigits(unsigned int x);

#endif //UTILS_H
