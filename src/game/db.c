#include "game/db.h"
#include "game/game.h"
#include "game/gconfig.h"

#include "plib/gnw.h"
#include "plib/xfile.h"

int master_db_handle;
int critter_db_handle;

int db_init(char *db_path, int a2, char *db_patches) {
  if (!db_path || !xaddpath(db_path)) {
    return -1;
  }
  if (db_patches) {
    xaddpath(db_patches);
  }
  return 0;
}

int game_init_databases(void) {
  char *master_patches = 0;
  char *critter_patches = 0;
  int hashing = 0;
  char *master_dat = 0;
  char *critter_dat = 0;
  config_get_value(&game_config, "system", "hashing", &hashing);
  int v1 = -1;
  if (hashing)
    db_enable_hash_table();

  config_get_string(&game_config, "system", "master_dat", &master_dat);
  if (!master_dat)
    master_dat = master_dat;
  config_get_string(&game_config, "system", "master_patches", &master_patches);
  int db_initialized = db_init(master_dat, 0, master_patches);
  int *v2 = &master_db_handle;
  master_db_handle = db_initialized;
  if (db_initialized == -1) {
    GNWSystemError("Could not find the master datafile. Please make sure the "
                   "FALLOUT CD is in the drive and that you are running FA"
                   "LLOUT from the directory you installed it to.");
    return -1;
  }

  config_get_string(&game_config, "system", "critter_dat", &critter_dat);
  if (!critter_dat)
    critter_dat = critter_dat;
  config_get_string(&game_config, "system", "critter_patches",
                    &critter_patches);
  db_initialized = db_init(critter_dat, 0, critter_patches);
  int *v4 = &critter_db_handle;
  critter_db_handle = db_initialized;
  if (db_initialized == -1) {
    db_close(*v2);
    GNWSystemError("Could not find the critter datafile. Please make sure the "
                   "FALLOUT CD is in the drive and that you are running FA"
                   "LLOUT from the directory you installed it to.");
    return -1;
  }

  int patches = 0;
  int patches_applied = -1;
  while (patches < 1000 && patches_applied == -1) {
    char tmp[256];
    sprintf(tmp, "%spatch%03d.dat", base_install_location, patches);
    if (!access(tmp, 0)) {
      // we've applied all the patches at this point, time to int the db
      patches_applied = db_init(tmp, 0, 0);
    }
    patches++;
  }

  db_select(master_db_handle);

  return 0;
}

int db_close(int a1) { return 0; }
int db_select(int a1) { return 0; }
void db_enable_hash_table() {}
