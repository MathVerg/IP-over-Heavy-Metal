#ifndef SOUND_CODE_H

#define SOUND_CODE_H

/* Plays the sounds corresponding to the data in the buffer.
/ Returns the number of bytes that were sent */
int bytesToSound(void *buffer, int buffLength);

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(void *buffer, int buffLength);


#endif //SOUND_CODE_H
