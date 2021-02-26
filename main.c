#include "tun.h"
#include "sniffer.h"
#include "utils.h"
#include "parse.h"

int main() {
    packet packet;
    packet_info info;
    packet.data = malloc(MTU);
    intercept_packet(&packet);
    //print_packet(&packet);
    parse_packet(&packet, &info);
    print_packet_info(&info);
    free(packet.data);
    return 0;
}