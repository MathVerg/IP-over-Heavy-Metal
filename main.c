#include "tun.h"
#include "sniffer.h"
#include "utils.h"

int main() {
    packet packet;
    dataBuffer buf;
    packet.data = malloc(MTU);
    buf.data = malloc(MAX_DATA_SIZE);
    intercept_packet(&packet);
    packet_to_dataBuffer(&packet, &buf);
    dataBuffer_to_packet(&packet, &buf);
    print_packet(&packet);
    free(packet.data);
    free(buf.data);
    return 0;
}