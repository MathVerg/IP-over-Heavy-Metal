#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"
#include "utils.h"
#include "sniffer.h"
#include "parse.h"
#include "const.h"
#include "tun.h"

int main(int argc, char *argv[]) {
  packet packet;
  packet_info info;
  int tun_fd = tun_link();
  while (1) {
    memset(&packet, 0, sizeof(packet));
    memset(&info, 0, sizeof(info));
    intercept_packet(tun_fd, &packet);
    parse_packet(&packet, &info);
    print_packet_info(&info);

    if (info.version == 4) {
      metalBuffer buff;
      memset(&buff, 0, sizeof(buff));

      packet_to_metalBuffer(&buff, &packet);

      bytesToSound(&buff);
      printf("\n");
    }

  }
  return 0;
}
