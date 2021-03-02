#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "soundDecode.h"
#include "parse.h"
#include "feeder.h"
#include "tun.h"

int main(int argc, char *argv[]) {

  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));
  buff.length = 64;
  //soundToBytes(&buff);
  int packet_lol[] = {4, 5, 0, 0, 0, 0, 2, 0, 12, 13, 7, 2, 4, 0, 0, 0, 4, 0, 1, 1, 9, 2, 8, 2, 8, 1, 6, 8, 14, 12, 0, 1, 8, 1, 6, 8, 14, 12, 0, 5, 10, 15, 11, 2, 0, 4, 13, 2, 0, 0, 0, 12, 9, 7, 15, 15, 6, 12, 6, 15, 6, 12, 0, 10};
  memcpy(&(buff.data), packet_lol, buff.length * sizeof(int));

  packet packet;
  packet_info info;

  memset(&packet, 0, sizeof(packet));
  memset(&info, 0, sizeof(info));

  metalBuffer_to_packet(&packet, &buff);
  printf("Affichage du paquet :\n\n");
  print_packet(&packet);
  parse_packet(&packet, &info);
  print_packet_info(&info);

  int tun_fd = tun_link();

  write_packet(tun_fd, &packet);


  return 0;
}
