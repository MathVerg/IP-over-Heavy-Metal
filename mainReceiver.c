#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundDecode.h"

int main(int argc, char *argv[]) {
  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));
  buff.length = 30;
  soundToBytes(&buff);
  for (int i = 0; i < buff.length; i++) {
    printf("%d, ", buff.data[i]);
  }
  return 0;
}
