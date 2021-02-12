#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "sound.h"

#define BEGINNING_SILENCE_TIME 4.0
#define FINAL_SILENCE_TIME 5.0
#define SILENCE_THRESHOLD 5.0

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);

#endif // SOUND_DECODE_H
