#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "soundDecode.h"

int main(int argc, char *argv[]) {
  metalBuffer buff;
  memset(&buff, 0, sizeof(buff));
  buff.length = 30;
  soundToBytes(&buff);
  return 0;
}
