#include "game/game.h"
#include "game/db.h"
#include "game/gconfig.h"
#include "game/gmemory.h"

void *main_selfrun_list;
int main_selfrun_count;
int main_selfrun_index;
BOOL game_in_mapper;
char *base_install_location;

int main_init_system(int argc, char **argv) {
  base_install_location = "";
  if (game_init("FALLOUT II", FALSE, 0, 0, argc, argv) != -1) {
    main_selfrun_init();
    return 1;
  }
  return 0;
}

int game_check_disk_space(void) { return 0; }

int game_init(char *windowName, BOOL use_mapper, int a2, int a3, int argc,
              char **argv) {
  if (gmemory_init() == -1) {
    return -1;
  }
  gconfig_init(use_mapper, argc, argv);
  game_in_mapper = use_mapper;
  if (game_check_disk_space() == -1 || game_init_databases() == -1) {
    gconfig_exit(FALSE);
    return -1;
  }
  char *language;
  if (config_get_string(&game_config, "system", "language", &language)) {
  }
}