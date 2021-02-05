#ifndef SOUND_DECODE_H
#define SOUND_DECODE_H

#include "sound.h"

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);

#endif // SOUND_DECODE_H