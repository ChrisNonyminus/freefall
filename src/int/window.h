#ifndef INT_WINDOW_H
#define INT_WINDOW_H

extern int currentTextColorR;
extern int currentTextColorG;
extern int currentTextColorB;

extern int currentHighlightColorR;
extern int currentHighlightColorG;
extern int currentHighlightColorB;

extern int currentTextFlags;

extern int xres;
extern int yres;

typedef struct _screen_size {
  int x;
  int y;
} screen_size;

static screen_size sizes[] = {
    {320, 200}, {640, 480}, {640, 400}, {800, 600}, {1024, 768}, {1280, 1024},
};

#endif