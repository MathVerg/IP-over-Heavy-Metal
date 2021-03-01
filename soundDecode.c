#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "soundDecode.h"
#include "utils.h"


static char recordPath[] = "/tmp/record.wav";
static char trimmedPath[] =  "/tmp/trimmed.wav";

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
void soundToBytes(metalBuffer *buffer) {

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
    exit(EXIT_FAILURE);
  }

  float timestamp = 0.0, freq = 1.0, t = 0.0;

  int receivedNotes[MAX_METAL_SIZE];
  memset(receivedNotes, 0, MAX_METAL_SIZE*sizeof(int));
  int noteIndex = 0;

  int end = 0;

  while (!end && freq > 0.001 && noteIndex < MAX_METAL_SIZE) {
    if (fscanf(resultPointer, "%f %f", &timestamp, &freq) == 2) {
      if (timestamp >= t) {
        //printf("%f : %d\n", freq, indClosestInArray(freq, freqTable, FREQ_NUMBER));
        receivedNotes[noteIndex] = indClosestInArray(freq, freqTable, FREQ_NUMBER);
        noteIndex ++;
        t += NOTE_DURATION + COMMAND_DELAY;
      }
    } else {
      end = 1;
    }

  }
  pclose(resultPointer);

  memcpy(buffer->data, receivedNotes, noteIndex*sizeof(int));

  buffer->length = noteIndex;

}
