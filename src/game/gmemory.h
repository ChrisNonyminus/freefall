#ifndef GMEMORY_H
#define GMEMORY_H
#include <stdint.h>
int gmalloc(size_t size);
int grealloc(void *ptr, size_t size);
int gfree(void *ptr);
int gmemory_init();
#endif