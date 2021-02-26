#include "tun.h"
#include "sniffer.h"
#include "utils.h"
#include "parse.h"

int main() {
    packet packet;
    packet_info info;
    memset(&packet, 0, sizeof(packet));
    intercept_packet(&packet);
    //print_packet(&packet);
    parse_packet(&packet, &info);
    print_packet_info(&info);
    return 0;
}
