#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "const.h"

#define BEGINNING_SILENCE_TIME 4.0
#define FINAL_SILENCE_TIME 5.0
#define SILENCE_THRESHOLD 5.0

#define COMMAND_DELAY 0.15

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(metalBuffer *buff);

#endif // SOUND_DECODE_H
