#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"
#include "soundDecode.h"


int main(int argc, char *argv[]) {
  //int gamme[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int auClairDeLaLune[] = {0, 0, 0, 1, 2, 1, 0, 2, 1, 1, 0};
  dataBuffer packet;
  memset(&packet, 0, sizeof(packet));
  packet.data = auClairDeLaLune;
  packet.length = 11;
  bytesToSound(&packet);
  return 0;
}
