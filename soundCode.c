#include <stdlib.h>
#include <stdio.h>

#include "soundCode.h"


int bytesToSound(dataBuffer *buffer) {
  for (int i = 0; i < buffer->length; i++) {
    printf("%d : %f", i, freqTable[i]);
    char command[100];
    sprintf(command, "play -n synth %f sine %f > /dev/null 2>&1", SOUND_TIMING, freqTable[i]);
    system(command);
  }
  return -1;
}

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buffer) {
  return -1;
}
