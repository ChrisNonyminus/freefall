#include "main.h"

int main_init_system(int argc, char **argv) {
  if (game_init("FALLOUT II", 0, 0, 0, argc, argv) != -1) {
    main_selfrun_init();
    return 1;
  }
  return 0;
}

int game_init(char *windowName, int a1, int a2, int a3, int argc, char **argv) {

}