#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "soundDecode.h"
#include "parse.h"
#include "feeder.h"
#include "tun.h"

#define COMMAND_DELAY 0.085

int main(int argc, char *argv[]) {
  float command_delay = 0;

  if (argc > 1) {
    command_delay = atof(argv[1]);
  }
  else command_delay = COMMAND_DELAY;
  printf("%f\n", command_delay);

  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));
  //buff.length = 66;
  soundToBytes(&buff, command_delay);
  //int packet_lol[] = {4, 5, 0, 0, 0, 0, 2, 1, 2, 14, 13, 7, 4, 0, 0, 0, 4, 0, 1, 1, 15, 7, 14, 15, 0, 10, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 0, 0, 5, 9, 13, 5, 0, 0, 4, 13, 2, 0, 0, 0, 13, 6, 8, 13, 13, 6, 2, 6, 9, 7, 4, 6, 5, 0, 10};
  //memcpy(&(buff.data), packet_lol, buff.length * sizeof(int));

  for (int i = 0; i < buff.length; ++i)
    printf("%d, ", buff.data[i]);

  packet packet;
  packet_info info;

  memset(&packet, 0, sizeof(packet));
  memset(&info, 0, sizeof(info));

  metalBuffer_to_packet(&packet, &buff);
  printf("Affichage du paquet :\n\n");
  // print_packet(&packet);
  parse_packet(&packet, &info);
  print_packet_info(&info);

  int tun_fd = tun_link();

  write_packet(tun_fd, &packet);


  return 0;
}
