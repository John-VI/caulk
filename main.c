// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

//#include <features.h>

#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_ttf.h>

/* #ifndef __GLIBC__ */

/* #include "gnu.h" */

/* #endif */

#include "clkwin.h"
#include "clktex.h"
#include "clkfont.h"

#define INTWID 320
#define INTHEI 240

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
  IMG_Init(IMG_INIT_PNG);

  SDL_Window *win = CLK_NewWindow("Regalism", INTWID, INTHEI);
  SDL_Renderer *ren = CLK_NewRenderer(win, 0, 0, 0, 255);
  CLK_SetRenderer(ren);
  CLK_SetWindow(win);

  /* SDL_Surface *frogsurf = IMG_Load("frog.png"); */
  /* SDL_Texture *frog = SDL_CreateTextureFromSurface(ren, frogsurf); */
  /* SDL_FreeSurface(frogsurf); */

  CLK_Sprite *frog = CLK_SpriteFromFile("frog.png", 0b10000000);
  /* CLK_Font *vga = CLK_FontFromFile("") */

  SDL_Event e;
  
  int quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)
	quit = 1;
    }
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, frog->texture, NULL, NULL);
    SDL_RenderPresent(ren);
  }
  CLK_DestroySprite(frog);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  
  IMG_Quit();
  SDL_Quit();
  return 0;
}
