#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "const.h"

#define BEGINNING_SILENCE_TIME 4.0
#define FINAL_SILENCE_TIME 5.0
#define SILENCE_THRESHOLD 5.0


/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
void soundToBytes(metalBuffer *buff, float command_delay);

#endif // SOUND_DECODE_H
