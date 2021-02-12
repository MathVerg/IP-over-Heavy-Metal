#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"

int main(int argc, char *argv[]) {
  //int gamme[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int auClairDeLaLune[] = {5, 5, 11, 5, 11, 12, 5, 11, 9, 5, 10, 10, 9, 8, 9, 2, 2, 8, 2, 8, 9, 2, 11, 2, 9, 11, 11, 9, 11, 12};
  dataBuffer packet;
  memset(&packet, 0, sizeof(packet));
  packet.data = auClairDeLaLune;
  packet.length = 30;
  bytesToSound(&packet);
  return 0;
}
