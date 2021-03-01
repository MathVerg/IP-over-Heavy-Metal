#ifndef TUN_H
#define TUN_H

#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Goal : create a TUN interface (tun for ip packets, tap for ethernet)
Some stuff has to be done in a terminal using sudo
*/


// This function comes from https://backreference.org/2010/03/26/tuntap-interface-tutorial/,
// more precisely, from Documentation/networking/tuntap.txt "in the kernel source tree"

int tun_alloc(char *dev, int flags);

/* gets the tun file dexcirptor */

int tun_link();


#endif // TUN_H
