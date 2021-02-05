#include <stdlib.h>
#include <stdio.h>
#include "soundDecode.h"
#include "utils.h"

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buffer) {

  char recordCommand[100];
  sprintf(recordCommand, "/usr/bin/rec %s silence 0 1 %f %f%%", recordPath, FINAL_SILENCE_TIME, SILENCE_THRESHOLD); //stop recording after 3.0 s of silence
  printf("%s", recordCommand);
  system(recordCommand);

  char trimmingCommand[100];
  sprintf(trimmingCommand, "/usr/bin/sox %s %s trim %f silence 1 0.1 %f", recordPath, trimmedPath, BEGINNING_SILENCE_TIME, SILENCE_THRESHOLD); //remove the silence at the beginning
  system(trimmingCommand);

  for (float t = 0.0; t < 10.0; t += SOUND_TIMING) {
    printf("%f\n", freqBetween(trimmedPath, t, SOUND_TIMING) );
  }

  return -1;
}

float freqBetween(char *audioFile, float start, float duration) {
  FILE *resultPointer;

  char getFreqCommand[100];
  sprintf(getFreqCommand, "/usr/bin/sox %s -n trim %f %f stat -freq 2>&1 | head -n %d | tail -n %d",
    audioFile, start, duration, FREQ_LOW_BOUND + FREQ_LINES, FREQ_LINES);
  resultPointer = popen(getFreqCommand, "r");

  if (resultPointer == NULL) {
    fprintf(stderr, "Error while launching the command\n");
    return -1;
  }

  float recordedFrequencies[FREQ_LINES];
  float recordedPower[FREQ_LINES];

  for (int k = 0; k < FREQ_LINES; k ++) {
    fscanf(resultPointer, "%f %f", &recordedFrequencies[k], &recordedPower[k]);
  }
  pclose(resultPointer);

  int i_max  = indMaxFloatArray(recordedPower, FREQ_LINES);
  return recordedFrequencies[i_max];

  return 0;
}
