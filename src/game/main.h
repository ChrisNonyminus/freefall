#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/boolean.h"

extern void *main_selfrun_list;
extern int main_selfrun_count;
extern int main_selfrun_index;
extern BOOL game_in_mapper;

int main_selfrun_exit();
int selfrun_get_list(void **list, int *count);

static inline int main_selfrun_init() {
  if (main_selfrun_list) {
    main_selfrun_exit();
  }
  if (!selfrun_get_list(&main_selfrun_list, &main_selfrun_count)) {
    main_selfrun_index = 0;
  }
}

int main_init_system(int argc, char **argv);
int game_init(char *windowName, BOOL use_mapper, int a2, int a3, int argc,
              char **argv);

#endif