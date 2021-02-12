#ifndef SOUND_H
#define SOUND_H

#define MAX_DATA_SIZE 1024
#define NOTE_DURATION 0.1


/* frequecy code */
static float freqTable[] = {261.63, 293.66, 329.63, 349.23, 392.0, 440.0, 493.88, 523.25, 587.33, 659.26, 698.46, 783.99, 880.0, 987.77, 104650, 1108.73};
#define FREQ_NUMBER 16
#define FREQ_LOW_BOUND 21 //first line of the frequency file to look at
#define FREQ_LINES 83 //number of lines of this file that we have to consider

typedef struct dataBuffer {
  int* data;
  int length;
} dataBuffer;


#endif // SOUND_H
