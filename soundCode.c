#include <stdlib.h>
#include <stdio.h>

#include "soundCode.h"


int bytesToSound(dataBuffer *buffer) {
  for (int i = 0; i < buffer->length; i++) {
    char command[100];
    sprintf(command, "/usr/bin/play -n synth %f sine %f > /dev/null 2>&1", NOTE_DURATION, freqTable[buffer->data[i]]);
    system(command);
  }
  return -1;
}
