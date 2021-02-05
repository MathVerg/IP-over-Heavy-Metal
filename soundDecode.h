#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "sound.h"

#define BEGINNING_SILENCE_TIME 5.0
#define FINAL_SILENCE_TIME 3.0
#define SILENCE_THRESHOLD 2.0

static char recordPath[] = "/tmp/record.wav";
static char trimmedPath[] =  "/tmp/trimmed.wav";

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);

/*get the frequency of the sound file for duration seconds from start */
float freqBetween(char *audioFile, float start, float duration);

#endif // SOUND_DECODE_H
