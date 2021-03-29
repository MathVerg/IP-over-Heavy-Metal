#ifndef CONST_H
#define CONST_H

#define MTU 1500

#define NOTE_DURATION 0.75

// #define COMMAND_DELAY 0.085

// name of tun interface: tunX

#define TUN_NAME "tunX"

// by default, mtu = 1500 bytes (max transmission unit)

#define MAX_METAL_SIZE 2*MTU // 1 byte = 2 notes


/* frequecy code */
static float freqTable[] = {261.63, 293.66, 329.63, 349.23, 392.0, 440.0, 493.88, 523.25, 587.33, 659.26, 698.46, 783.99, 880.0, 987.77, 1046.50, 1108.73};
#define FREQ_NUMBER 16
#define FREQ_LOW_BOUND 21 //first line of the frequency file to look at
#define FREQ_LINES 83 //number of lines of this file that we have to consider


/* holds ints that represent indexes for the freq table */
typedef struct metalBuffer {
  int data[MAX_METAL_SIZE];
  int length;
} metalBuffer;


/*
this struct represents the packet
we always suppose that data = malloc(MTU)
*/

typedef struct packet {
  unsigned char data[MTU];
  int length;
} packet;

#endif // CONST_H
