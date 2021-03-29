#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"
#include "utils.h"
#include "sniffer.h"
#include "parse.h"
#include "const.h"
#include "tun.h"

#define COMMAND_DELAY 0.085

int main(int argc, char *argv[]) {

  float command_delay = 0;

  if (argc > 1) {
    command_delay = atof(argv[1]);
  }
  else command_delay = COMMAND_DELAY;

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

      bytesToSound(&buff, command_delay);
      printf("\n");
    }

  }
  return 0;
}
