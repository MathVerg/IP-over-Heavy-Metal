#ifndef SOUND_CODE_H

#define SOUND_CODE_H

#include "const.h"

#define GROWL 1

#define GROWL_DURATION 0.247

#define GROWL_VOLUME 0.5


/* Plays the sounds corresponding to the data in the buffer.
/ Returns the number of bytes that were sent */
void bytesToSound(metalBuffer *buff);




#endif //SOUND_CODE_H
