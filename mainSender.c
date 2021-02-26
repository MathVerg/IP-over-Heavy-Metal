#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"
#include "utils.h"
#include "sniffer.h"
#include "parse.h"
#include "const.h"

int main(int argc, char *argv[]) {
  packet packet;
  packet_info info;
  memset(&packet, 0, sizeof(packet));
  intercept_packet(&packet);
  parse_packet(&packet, &info);
  print_packet_info(&info);

  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));

  packet_to_metalBuffer(&buff, &packet);

  bytesToSound(&buff);
  return 0;
}
