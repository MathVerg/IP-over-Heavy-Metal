#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"


int main(int argc, char *argv[]) {
  int gamme[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  dataBuffer packet;
  memset(&packet, 0, sizeof(packet));
  packet.data = gamme;
  packet.length = 8;
  bytesToSound(&packet);
  return 0;
}
