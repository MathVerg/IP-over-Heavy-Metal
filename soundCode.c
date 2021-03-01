#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "soundCode.h"


void bytesToSound(metalBuffer *buffer) {
  FILE* growlPointer;
  if (GROWL) {
    char growlCommand[100];
    int reps = (int) floor(buffer->length * (NOTE_DURATION + COMMAND_DELAY)/GROWL_DURATION);
    sprintf(growlCommand, "/usr/bin/play -v %f growl.wav repeat %d 2>/dev/null", GROWL_VOLUME, reps);
    growlPointer = popen(growlCommand, "r");
  }
  for (int i = 0; i < buffer->length; i++) {
    char command[100];
    printf("%d ", buffer->data[i]);
    sprintf(command, "/usr/bin/play -n synth %f sine %f > /dev/null 2>&1", NOTE_DURATION, freqTable[buffer->data[i]]);
    system(command);
  }
  if (GROWL) {
    pclose(growlPointer);
  }
}
