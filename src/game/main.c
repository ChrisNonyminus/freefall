#include "game/main.h"

void *main_selfrun_list;
int main_selfrun_count;
int main_selfrun_index;
BOOL game_in_mapper;

int main_init_system(int argc, char **argv) {
  if (game_init("FALLOUT II", FALSE, 0, 0, argc, argv) != -1) {
    main_selfrun_init();
    return 1;
  }
  return 0;
}

int game_init(char *windowName, BOOL use_mapper, int a2, int a3, int argc,
              char **argv) {}