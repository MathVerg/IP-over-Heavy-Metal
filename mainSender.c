#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundCode.h"

int main(int argc, char *argv[]) {
  //int gamme[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int auClairDeLaLune[] = {3, 9, 5, 2, 6, 8, 11, 4, 11, 11, 0};
  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));
  buff.data = auClairDeLaLune;
  buff.length = 11;
  bytesToSound(&buff);
  return 0;
}
