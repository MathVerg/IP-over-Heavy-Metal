#include "tun.h"
#include "feeder.h"

void write_packet(int tun_fd, packet *packet) {
  int nwrite = write(tun_fd, packet->data, packet->length);
  if (nwrite < 0) {
    fprintf(stderr, "write returned error\n");
    close(tun_fd);
    exit(EXIT_FAILURE);
  }
}
