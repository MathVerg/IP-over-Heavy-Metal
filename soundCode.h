#ifndef SOUND_CODE_H

#define SOUND_CODE_H
#define MAX_DATA_SIZE 1024
#define SOUND_TIMING 0.25


/* frequecy code */
static const float freqTable[] = {261.63, 293.66, 329.63, 349.23, 392.0, 440.0, 493.88, 523.25};

typedef struct dataBuffer {
  int* data;
  int length;
} dataBuffer;

/* Plays the sounds corresponding to the data in the buffer.
/ Returns the number of bytes that were sent */
int bytesToSound(dataBuffer *buff);

/* Writes the data recorded as sound in the buffer.
/ Returns the number of bytes that were written */
int soundToBytes(dataBuffer *buff);


#endif //SOUND_CODE_H
