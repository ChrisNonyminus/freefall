#include <string.h>

#include "common/time.h"

#include "plib/debug.h"

#include "game/gsound.h"
#include "game/palette.h"

color black_pallete[256];
color white_pallete[256];
color current_palette[256];
float fade_steps;

int palette_init() {
  memset(&black_pallete, 0, sizeof(black_pallete));
  memset(&white_pallete, 63, sizeof(white_pallete));
  memcpy(&current_palette, &cmap, sizeof(cmap));
  int time = get_time();
  // Does nothing but check how long it takes to fade? And calculates the
  // fade_steps from that?
  fadeSystemPalette(&current_palette, &current_palette, 60);
  int elapsed = elapsed_time(time);
  fade_steps = (60.0 / (elapsed / 10.0));
  debug_printf("\nFade time is %u\nFade steps are %d\n", elapsed, fade_steps);
}