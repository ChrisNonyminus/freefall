#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "game/palette.h"

GLuint cmap_texture;

int setSystemPalette(color **newPalette) {
  if (newPalette == NULL) {
    return -1;
  }

  int i;
  for (i = 0; i < 256; i++) {
    current_palette[i].r = newPalette[i]->r;
    current_palette[i].g = newPalette[i]->g;
    current_palette[i].b = newPalette[i]->b;
  }

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  if (cmap_texture == 0) {
    glGenTextures(1, &cmap_texture);
  }
  glBindTexture(GL_TEXTURE_2D, cmap_texture);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 256, 1, GL_RGB, GL_UNSIGNED_BYTE,
                  current_palette);

  return 0;
}

int fadeSystemPalette(color **oldPalette, color **newPalette, int delay) {
  int i;
  int time = get_time();
  int elapsed = elapsed_time(time);
  int fade = elapsed / delay;
  color fadePalette[256];
  if (fade > 255) {
    fade = 255;
  }
  while (fade > 0) {
    for (i = 0; i < 256; i++) {
      int r =
          ((newPalette[i]->r * fade) + (oldPalette[i]->r * (255 - fade))) / 255;
      int g =
          ((newPalette[i]->g * fade) + (oldPalette[i]->g * (255 - fade))) / 255;
      int b =
          ((newPalette[i]->b * fade) + (oldPalette[i]->b * (255 - fade))) / 255;
      fadePalette[i] = (color){r, g, b};
    }
    setSystemPalette(fadePalette);
    fade--;
  }
  return setSystemPalette(newPalette);
}