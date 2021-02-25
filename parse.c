#include "parse.h"
#include "utils.h"
#include <string.h>

void parse_packet(packet *packet, packet_info *info) {
    
    // The first 4 bits encode the version

    info->version = (packet->data)[0] / 16;
    //printf("IPV%d\n", info->version);

    // Protocole

    if ((int) packet->data[9] == 17) strcpy(info->protocole, "UDP");
    else strcpy(info->protocole, "TCP");
    //printf("\nprotocole: %s\n\n", info->protocole);

    // Source address

    int i = 0;
    for (int j = 12; j < 16; ++j) {
        unsigned char x = (unsigned char) (packet->data)[j];
        int n = nbdigits((int) x), e = 10;
        for (int k = n-1; k >= 0; --k) {
            (info->from)[i+k] = (unsigned char) (x%e) + 48;
            x /= e;
            e *= 10;
        }
        i += n;
        (info->from)[i++] = '.';
    }
    (info->from)[i-1] = '\0';
    //printf("from: %s\n\n", info->from);

    // dest address

    i = 0;
    for (int j = 16; j < 20; ++j) {
        unsigned char x = (unsigned char) (packet->data)[j];
        int n = nbdigits((int) x), e = 10;
        for (int k = n-1; k >= 0; --k) {
            (info->dest)[i+k] = (unsigned char) (x%e) + 48;
            x /= e;
            e *= 10;
        }
        i += n;
        (info->dest)[i++] = '.';
    }
    (info->dest)[i-1] = '\0';
    //printf("to: %s\n\n", info->dest);

    // payload

    for (i = 28; i < packet->length; ++i) {
        (info->payload)[i-28] = (char) (packet->data)[i];
    }

    //printf("payload: %s\n\n", info->payload);
}

void print_packet_info(packet_info *info) {
    printf("#############################\n\n");
    printf("Version: IPV%d\n\n", info->version);
    printf("Protocole: %s\n\n", info->protocole);
    printf("From: %s\n\n", info->from);
    printf("To: %s\n\n", info->dest);
    printf("Payload:\n\n%s\n\n", info->payload);
}