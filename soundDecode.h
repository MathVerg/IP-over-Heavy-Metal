#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "sound.h"

#define RECORD_PATH "/tmp/record.wav"
#define TRIMMED_PATH "/tmp/trimmed.wav"
#define BEGINNING_SILENCE_TIME 5.0
#define FINAL_SILENCE_TIME 3.0
#define SILENCE_THRESHOLD 2.0

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);

#endif // SOUND_DECODE_H
