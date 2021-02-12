#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "sound.h"

#define BEGINNING_SILENCE_TIME 4.0
#define FINAL_SILENCE_TIME 3.0
#define SILENCE_THRESHOLD 15.0

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);

/*get the frequency of the sound file for duration seconds from start */
float freqBetween(char *audioFile, float start, float duration);

#endif // SOUND_DECODE_H
