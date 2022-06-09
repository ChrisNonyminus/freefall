#include "int/intlib.h"

int numCallbacks;
void **callbacks;

void *interpretRegisterProgramDeleteCallback(void *callback) {
  int index = 0;
  if (numCallbacks > 0 && *callbacks) {
    while (index < numCallbacks && callbacks[index]) {
      ++index;
    }
  }
  if (index == numCallbacks) {
    if (callbacks)
      callbacks = myrealloc(callbacks, sizeof(callback) * (index + 1));
    else
      callbacks = mymalloc(sizeof(callback));
    ++numCallbacks;
  }
  callbacks[index] = callback;
  return callback;
}