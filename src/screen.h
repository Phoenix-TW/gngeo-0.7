
#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "SDL.h"
#include "list.h"

typedef struct RGB2YUV
{
  Uint16 y;
  Uint8  u;
  Uint8  v;
  Uint32 yuy2;
}RGB2YUV;

extern RGB2YUV rgb2yuv[65536];

void init_rgb2yuv_table(void);

extern SDL_Surface *screen;
extern SDL_Rect visible_area;

extern Uint8 interpolation;
extern Uint8 nblitter;
extern Uint8 neffect;
extern Uint8 scale;
extern Uint8 fullscreen;

Uint8 get_effect_by_name(char *name);
Uint8 get_blitter_by_name(char *name);
void print_blitter_list(void);
void print_effect_list(void);
void screen_change_blitter_and_effect(char *bname,char *ename);
LIST* create_effect_list(void);
LIST* create_blitter_list(void);

SDL_bool screen_init();
SDL_bool screen_resize(int w, int h);
void screen_update();
void screen_close();

void screen_fullscreen();

#endif
