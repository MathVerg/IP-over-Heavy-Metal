#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int indMaxFloatArray(float *t, int t_length) {
  int i_max = 0;
  for (int i = 0; i < t_length; i++) {
    if (t[i] > t[i_max]) {
      i_max = i;
    }
  }
  return i_max;
}

int indClosestInArray(float needle, float *t, int t_length) {
  int i = 0;
  while (i < t_length && t[i] < needle) {
    i++;
  }
  if (i == t_length) {
    return t_length - 1;
  } else if (i == 0) {
    return 0;
  } else if (needle - t[i - 1] > t[i] - needle) {
    return i;
  } else {
    return i - 1;
  }

}

void packet_to_metalBuffer(metalBuffer *data, packet *packet) {
  data->length = 2*packet->length;
  for (int i = 0; i < packet->length; ++i) {
    unsigned char x = (packet->data)[i];
    (data->data)[2*i] = x / 16;
    (data->data)[2*i+1] = x % 16;
  }
}

void metalBuffer_to_packet(packet *packet, metalBuffer *data) {
  packet->length = data->length/2;
  for (int i = 0; i < packet->length; ++i)
    (packet->data)[i] = (unsigned char) ((data->data)[2*i]*16+(data->data)[2*i+1]);
}

// useful for debugging

void print_byte(unsigned char b) {
  for (int i = 7; i >= 0; --i) {
    printf("%c", (b & (1 << i)) ? '1' : '0');
  }
}

void packet_binary(char *buf, packet *packet) { // sizeof(buf) = 8*packet->length +1
  for (int i = 0; i < packet->length; ++i) {
    for (int j = 7; j >= 0; --j) {
      buf[8*i+7-j] = ((packet->data)[i] & (1 << j)) ? '1' : '0';
    }
  }
}

int nbdigits(unsigned int x) {
  int res = 0;
  int i = 1;
  while (x/i > 0) {
    i *= 10;
    res++;
  }
  if (res == 0) return 1;
  return res;
}
