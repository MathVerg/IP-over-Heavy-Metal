#include <string.h>
#include <stdio.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#include "parse.h"
#include "utils.h"

void parse_packet(packet *packet, packet_info *info) {

    // // The first 4 bits encode the version

    // info->version = (packet->data)[0] / 16;

    // // Protocole

    // if ((int) packet->data[9] == 17) strcpy(info->protocole, "UDP");
    // else if (packet->data[9] == 6) strcpy(info->protocole, "TCP");
    // else strcpy(info->protocole, "UNKNOWN");
    // //printf("\nprotocole: %s\n\n", info->protocole);

    // // Source address

    // int i = 0;
    // for (int j = 12; j < 16; ++j) {
    //     unsigned char x = (packet->data)[j];

    //     int n = nbdigits((int) x);
    //     for (int k = n-1; k >= 0; --k) {
    //         (info->from)[i+k] = (x%10) + 48;
    //         x /= 10;
    //     }
    //     i += n;
    //     (info->from)[i++] = '.';
    // }
    // (info->from)[i-1] = '\0';
    // //printf("from: %s\n\n", info->from);

    // // dest address

    // i = 0;
    // for (int j = 16; j < 20; ++j) {
    //     unsigned char x = (packet->data)[j];
    //     int n = nbdigits((int) x);
    //     for (int k = n-1; k >= 0; --k) {
    //         (info->dest)[i+k] = (x%10) + 48;
    //         x /= 10;
    //     }
    //     i += n;
    //     (info->dest)[i++] = '.';
    // }
    // (info->dest)[i-1] = '\0';
    // //printf("to: %s\n\n", info->dest);

    // // payload

    // for (i = 28; i < packet->length; ++i) {
    //     (info->payload)[i-28] = (char) (packet->data)[i];
    // }

    // //printf("payload: %s\n\n", info->payload);

    struct ip *ip_header = (struct ip *) (packet->data);
    info->version = ip_header->ip_v;

    // debug
    printf("version: %d\n", info->version);

    switch(ip_header->ip_p) {
        case IPPROTO_UDP:
            strcat(info->protocol, "UDP");
            break;

        case IPPROTO_TCP:
            strcat(info->protocol, "TCP");
            break;

        default:
            printf("default\n");
            break;
    }

    strcat(info->from, inet_ntoa(ip_header->ip_src));
    strcat(info->dest, inet_ntoa(ip_header->ip_dst));

    int size_ip = ip_header->ip_len*4;
    memcpy(info->payload, packet->data + size_ip, packet->length);
}

void print_packet_info(packet_info *info) {
    printf("Version: IPV%d\n\n", info->version);
    printf("Protocole: %s\n\n", info->protocol);
    printf("From: %s\n\n", info->from);
    printf("To: %s\n\n", info->dest);
    printf("Payload:\n\n%s\n\n", info->payload);
}

void print_packet(packet *packet) {
    //FILE * file = fopen("file.txt", "wb");
    for (int i = 0; i < packet->length; ++i) {
        printf("byte number %d: 0x%x    // %d   ", i, (unsigned char) (packet->data)[i], (unsigned char) (packet->data)[i]);
        print_byte((packet->data)[i]);
        printf("\n");
    }
    //fwrite(packet->data, 1, packet->length, file);
    //fclose(file);
}
