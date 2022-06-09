#ifndef INT_INTLIB_H
#define INT_INTLIB_H

extern int numCallbacks;
extern void **callbacks;

void *myrealloc(void *ptr, int size);
void *mymalloc(int size);

void *interpretRegisterProgramDeleteCallback(void *callback);

#endif