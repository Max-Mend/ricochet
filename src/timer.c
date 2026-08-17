#include "timer.h"

#include <time.h>

#define _POSIX_C_SOURCE 199309L

double clock_get_time(void) {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);

  return ts.tv_sec + ts.tv_nsec / 1e9;
}