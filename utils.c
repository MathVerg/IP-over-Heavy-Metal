#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int indMaxFloatArray(float *t, int t_length) {
  int i_max = 0;
  for (int i = 0; i < t_length; i++) {
    if (t[i] > t[i_max]) {
      i_max = i;
    }
  }
  return i_max;
}

int indClosestInArray(float needle, float *t, int t_length) {
  int i = 0;
  while (i < t_length && t[i] < needle) {
    i++;
  }
  if (i == t_length) {
    return t_length;
  } else if (i == 0) {
    return 0;
  } else if (needle - t[i - 1] > t[i] - needle) {
    return i;
  } else {
    return i - 1;
  }

}
