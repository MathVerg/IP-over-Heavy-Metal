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
