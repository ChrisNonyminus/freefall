

#include "minGlue-stdio.h"
#include "minIni.h"

#include "game/game.h"
#include "game/gconfig.h"
#include "game/mem.h"

gconfig game_config;
BOOL gconfig_initialized;
char *gconfig_file_name;

BOOL config_init(gconfig *config) {
  if (!config || assoc_init(config, 10, sizeof(gconfig), 0)) {
    return FALSE;
  }
  return TRUE;
}

BOOL config_set_string(gconfig *config, char *section, char *key, char *value) {
  if (!section || !key || !value) {
    return FALSE;
  }
  if (!gconfig_initialized && ini_haskey(section, key, gconfig_file_name)) {
    return FALSE;
  }
  return ini_puts(section, key, value, gconfig_file_name);
}

BOOL config_set_value(gconfig *config, char *section, char *key, long value) {
  if (!section || !key) {
    return FALSE;
  }
  if (!gconfig_initialized && ini_haskey(section, key, gconfig_file_name)) {
    return FALSE;
  }
  return ini_putl(section, key, value, gconfig_file_name);
}

BOOL config_set_double(gconfig *config, char *section, char *key, float value) {
  if (!section || !key) {
    return FALSE;
  }
  if (!gconfig_initialized && ini_haskey(section, key, gconfig_file_name)) {
    return FALSE;
  }
  return ini_putf(section, key, value, gconfig_file_name);
}

BOOL config_set_bool(gconfig *config, char *section, char *key, BOOL value) {
  if (!section || !key) {
    return FALSE;
  }
  if (!gconfig_initialized && ini_haskey(section, key, gconfig_file_name)) {
    return FALSE;
  }
  return ini_putl(section, key, value, gconfig_file_name);
}

BOOL config_get_string(gconfig *config, char *section, char *key,
                       char **value) {
  if (!section || !key || !value) {
    return FALSE;
  }
  char *tmp;
  ini_gets(section, key, "", tmp, 1024, gconfig_file_name);
  *value = tmp;
  return TRUE;
}

BOOL config_get_value(gconfig *config, char *section, char *key, long *value) {
  if (!section || !key || !value) {
    return FALSE;
  }
  *value = ini_getl(section, key, 0, gconfig_file_name);
  return TRUE;
}

BOOL config_get_double(gconfig *config, char *section, char *key,
                       float *value) {
  if (!section || !key || !value) {
    return FALSE;
  }
  *value = ini_getf(section, key, 0.0, gconfig_file_name);
  return TRUE;
}

BOOL config_get_bool(gconfig *config, char *section, char *key, BOOL *value) {
  if (!section || !key || !value) {
    return FALSE;
  }
  *value = ini_getl(section, key, FALSE, gconfig_file_name);
  return TRUE;
}

int gconfig_init(BOOL use_mapper, int argc, char **argv) {
  gconfig *config = &game_config;
  if (gconfig_initialized || config_init(config) != -1) {
    return 0;
  }
  char config_file_name[256];
  sprintf(config_file_name, "%sfallout2.cfg", base_install_location);
  gconfig_file_name = config_file_name;

  config_set_string(config, "system", "executable", "game");
  config_set_string(config, "system", "master_dat", "master.dat");
  config_set_string(config, "system", "master_patches", "data/");
  config_set_string(config, "system", "critter_dat", "critter.dat");
  config_set_string(config, "system", "critter_patches", "data/");
  config_set_string(config, "system", "language", "english");
  config_set_value(config, "system", "scroll_lock", 0);
  config_set_value(config, "system", "interrupt_walk", 1);
  config_set_value(config, "system", "art_cache_size", 8);
  config_set_value(config, "system", "color_cycling", 1);
  config_set_value(config, "system", "hashing", 1);
  config_set_value(config, "system", "splash", 0);
  config_set_value(config, "system", "free_space", 20480);
  config_set_value(config, "system", "times_run", 0);

  config_set_value(config, "preferences", "game_difficulty", 1);
  config_set_value(config, "preferences", "combat_difficulty", 1);
  config_set_value(config, "preferences", "violence_level", 3);
  config_set_value(config, "preferences", "target_highlight", 2);
  config_set_value(config, "preferences", "item_highlight", 1);
  config_set_value(config, "preferences", "combat_looks", 0);
  config_set_value(config, "preferences", "combat_messages", 1);
  config_set_value(config, "preferences", "combat_taunts", 1);
  config_set_value(config, "preferences", "language_filter", 0);
  config_set_value(config, "preferences", "running", 0);
  config_set_value(config, "preferences", "subtitles", 0);
  config_set_value(config, "preferences", "combat_speed", 0);
  config_set_value(config, "preferences", "player_speedup", 0);
  config_set_double(config, "preferences", "text_base_delay", 3.5);
  config_set_double(config, "preferences", "text_line_delay", 1.399994);
  config_set_double(config, "preferences", "brightness", 1.0);
  config_set_double(config, "preferences", "mouse_sensitivity", 1.0);

  config_set_value(config, "sound", "initialize", 1);
  config_set_value(config, "sound", "device", -1);
  config_set_value(config, "sound", "port", -1);
  config_set_value(config, "sound", "irq", -1);
  config_set_value(config, "sound", "dma", -1);
  config_set_value(config, "sound", "sounds", 1);
  config_set_value(config, "sound", "music", 1);
  config_set_value(config, "sound", "speech", 1);
  config_set_value(config, "sound", "master_volume", 22281);
  config_set_value(config, "sound", "music_volume", 22281);
  config_set_value(config, "sound", "sndfx_volume", 22281);
  config_set_value(config, "sound", "speech_volume", 22281);
  config_set_value(config, "sound", "cache_size", 448);
  config_set_value(config, "sound", "pipboy_speech", 1);
  config_set_string(config, "sound", "music_path1", "sound/music/");
  config_set_string(config, "sound", "music_path2", "sound/music/");

  config_set_string(config, "debug", "mode", "mono");
  config_set_value(config, "debug", "show_tile_num", 0);
  config_set_value(config, "debug", "show_script_messages", 0);
  config_set_value(config, "debug", "show_load_info", 0);
  config_set_value(config, "debug", "output_map_data_info", 0);

  if (use_mapper) {
    config_set_string(config, "system", "executable", "mapper");

    config_set_value(config, "mapper", "override_librarian", 0);
    config_set_value(config, "mapper", "librarian", 0);
    config_set_value(config, "mapper", "use_art_not_protos", 0);
    config_set_value(config, "mapper", "rebuild_protos", 0);
    config_set_value(config, "mapper", "fix_map_objects", 0);
    config_set_value(config, "mapper", "fix_map_inventory", 0);
    config_set_value(config, "mapper", "ignore_rebuild_errors", 0);
    config_set_value(config, "mapper", "show_pid_numbers", 0);
    config_set_value(config, "mapper", "save_text_maps", 0);
    config_set_value(config, "mapper", "run_mapper_as_game", 0);
    config_set_value(config, "mapper", "default_f8_as_game", 1);
    config_set_value(config, "mapper", "sort_script_list", 0);
  }
  // TODO: implement config_cmd_line_parse
  gconfig_initialized = TRUE;
  return 1;
}

BOOL gconfig_exit(BOOL save_config) {
  if (!gconfig_initialized) {
    return FALSE;
  }
  gconfig_initialized = FALSE;
  return TRUE;
}