#include "tun.h"
#include "sniffer.h"
#include "utils.h"

void intercept_packet(packet *packet) {
    
    // get the tun interface file descriptor
    char tun_name[IFNAMSIZ];
    strcpy(tun_name, TUN_NAME);

    int tun_fd = tun_alloc(tun_name, IFF_TUN | IFF_NO_PI);
    if (tun_fd < 0) {
        fprintf(stderr, "Error allocating interface\n");
        exit(EXIT_FAILURE);
    }

    int nread = read(tun_fd, packet->data, MTU);
    if (nread < 0) {
        fprintf(stderr, "read returned error\n");
        close(tun_fd);
        exit(EXIT_FAILURE);
    }

    packet->length = nread;
}

void print_packet(packet *packet) {
    FILE * file = fopen("file.txt", "wb");
    printf("packet size: %d\n", packet->length);
    for (int i = 0; i < packet->length; ++i) {
        printf("byte number %d: 0x%x    // %d   ", i, (unsigned char) (packet->data)[i], (unsigned char) (packet->data)[i]);
        print_byte((packet->data)[i]);
        printf("\n");
    }
    fwrite(packet->data, 1, packet->length, file);
    fclose(file);
}