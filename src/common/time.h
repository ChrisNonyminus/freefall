#ifndef COMMON_TIME_H
#define COMMON_TIME_H

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

inline int get_time() {
#ifdef _WIN32
  return GetTickCount();
#else
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
}

inline int elapsed_time(int start_time) {
  int cur_time = get_time();
  if (start_time > cur_time) {
    return -1;
  } else {
    return cur_time - start_time;
  }
}

#endif