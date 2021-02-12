#include <stdlib.h>
#include <stdio.h>
#include "soundDecode.h"
#include "utils.h"


static char recordPath[] = "/tmp/record.wav";
static char trimmedPath[] =  "/tmp/trimmed.wav";

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buffer) {

  char recordCommand[100];
  sprintf(recordCommand, "/usr/bin/rec %s silence 0 1 %f %f%%", recordPath, FINAL_SILENCE_TIME, SILENCE_THRESHOLD); //stop recording after 3.0 s of silence
  system(recordCommand);

  char trimmingCommand[100];
  sprintf(trimmingCommand, "/usr/bin/sox %s %s trim %f silence 1 0.1 %f%%", recordPath, trimmedPath, BEGINNING_SILENCE_TIME, SILENCE_THRESHOLD); //remove the silence at the beginning
  system(trimmingCommand);

  FILE *resultPointer;

  char getFreqCommand[100];
  sprintf(getFreqCommand, "/usr/bin/aubiopitch -i %s -B 4096 -H 4096", trimmedPath);
  resultPointer = popen(getFreqCommand, "r");

  if (resultPointer == NULL) {
    fprintf(stderr, "Error while launching the command\n");
    return -1;
  }

  float timestamp = 0.0, freq = 1.0, t = 0.0;

  while (freq > 0.001) {
    fscanf(resultPointer, "%f %f", &timestamp, &freq);
    if (timestamp >= t) {
      printf("%f : %d\n", freq, indClosestInArray(freq, freqTable, FREQ_NUMBER));
      t += NOTE_DURATION;
    }
  }

  pclose(resultPointer);

  return -1;
}
