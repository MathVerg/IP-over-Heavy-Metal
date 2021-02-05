#include <stdlib.h>
#include <stdio.h>
#include "soundDecode.h"

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buffer) {

  char recordCommand[100];
  sprintf(recordCommand, "rec %s silence 0 1 %f %f%%", RECORD_PATH, FINAL_SILENCE_TIME, SILENCE_THRESHOLD); //stop recording after 3.0 s of silence
  printf("%s", recordCommand);
  system(recordCommand);

  char trimmingCommand[100];
  sprintf(trimmingCommand, "sox %s %s trim %f silence 1 0.1 %f", RECORD_PATH, TRIMMED_PATH, BEGINNING_SILENCE_TIME, SILENCE_THRESHOLD); //remove the silence at the beginning
  system(trimmingCommand);
  /*

  FILE *commandPointer;
  char freqString[50] = "";
  int frequency = 0;
  commandPointer = popen("/usr/bin/rec /home/matheo/record.wav trim 0.5 2.0 stat 2>&1", "r");

  if (commandPointer == NULL) {
    fprintf(stderr, "Error while launhing the command\n");
  }
  for (int k = 0; k < 13; k ++) {
    fgets(freqString, 50, commandPointer);
    printf("%s", freqString);
  }
  fscanf(commandPointer, "Rough   frequency:%d", &frequency);
  printf("%d\n", frequency);
  pclose(commandPointer);
  */
  return -1;
}
