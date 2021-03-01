#include "tun.h"
#include "sniffer.h"
#include "utils.h"

void intercept_packet(int *tun_fd, packet *packet) {

    int nread = read(*tun_fd, packet->data, MTU);
    if (nread < 0) {
        fprintf(stderr, "read returned error\n");
        close(*tun_fd);
        exit(EXIT_FAILURE);
    }

    packet->length = nread;
}
