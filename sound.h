#ifndef SOUND_H
#define SOUND_H

#define MAX_DATA_SIZE 1024
#define SOUND_TIMING 0.25


/* frequecy code */
static const float freqTable[] = {261.63, 293.66, 329.63, 349.23, 392.0, 440.0, 493.88, 523.25};

typedef struct dataBuffer {
  int* data;
  int length;
} dataBuffer;


#endif // SOUND_H