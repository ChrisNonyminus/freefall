#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern void *main_selfrun_list;
extern int main_selfrun_count;
extern int main_selfrun_index;

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
int game_init(char *windowName, int a1, int a2, int a3, int argc, char **argv);

#endif