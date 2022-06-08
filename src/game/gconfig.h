#ifndef CONFIG_H
#define CONFIG_H

#include "common/boolean.h"

typedef struct _gconfig {
  char unknown[40];
} gconfig;

extern gconfig *game_config;
extern BOOL gconfig_initialized;
extern char *gconfig_file_name;

int config_init(gconfig *config);
int gconfig_init(BOOL use_mapper, int argc, char **argv);

void config_set_string(gconfig *config, char *section, char *key, char *value);

void config_set_value(gconfig *config, char *section, char *key, long value);

void config_set_double(gconfig *config, char *section, char *key, float value);

void config_set_bool(gconfig *config, char *section, char *key, BOOL value);

void config_get_string(gconfig *config, char *section, char *key, char *value);

void config_get_value(gconfig *config, char *section, char *key, long *value);

void config_get_double(gconfig *config, char *section, char *key, float *value);

void config_get_bool(gconfig *config, char *section, char *key, BOOL *value);

#endif