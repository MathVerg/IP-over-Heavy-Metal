#include "tun.h"
#include "const.h"

// the following function comes from the tuto on https://backreference.org/2010/03/26/tuntap-interface-tutorial/


int tun_alloc(char *dev, int flags) {

  struct ifreq ifr;
  int fd, err;
  char clonedev[] = "/dev/net/tun";

  /* Arguments taken by the function:
   *
   * char *dev: the name of an interface (or '\0'). MUST have enough
   *   space to hold the interface name if '\0' is passed
   * int flags: interface flags (eg, IFF_TUN etc.)
   */

   /* open the clone device */
   if( (fd = open(clonedev, O_RDWR)) < 0 ) {
     return fd;
   }

   /* preparation of the struct ifr, of type "struct ifreq" */
   memset(&ifr, 0, sizeof(ifr));

   ifr.ifr_flags = flags;   /* IFF_TUN or IFF_TAP, plus maybe IFF_NO_PI */

   if (*dev) {
     /* if a device name was specified, put it in the structure; otherwise,
      * the kernel will try to allocate the "next" device of the
      * specified type */
     strncpy(ifr.ifr_name, dev, IFNAMSIZ);
   }

   /* try to create the device */
   if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ) {
     close(fd);
     return err;
   }

   if(ioctl(fd, TUNSETPERSIST, 1) < 0)
    fprintf(stderr, "ioctl");

  /* if the operation was successful, write back the name of the
   * interface to the variable "dev", so the caller can know
   * it. Note that the caller MUST reserve space in *dev (see calling
   * code below) */

  strcpy(dev, ifr.ifr_name);


  /* this is the special file descriptor that the caller will use to talk
   * with the virtual interface */
  return fd;
}

int tun_link() {
  // get the tun interface file descriptor
  char tun_name[IFNAMSIZ];
  strcpy(tun_name, TUN_NAME);

  int tun_fd = tun_alloc(tun_name, IFF_TUN | IFF_NO_PI);
  if (tun_fd < 0) {
      fprintf(stderr, "Error allocating interface\n");
      exit(EXIT_FAILURE);
  }
  return tun_fd;
}
