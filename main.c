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

#define INTWID 320
#define INTHEI 240

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
  IMG_Init(IMG_INIT_PNG);

  SDL_Window *win = newwin("Regalism", INTWID, INTHEI);
  SDL_Renderer *ren = newren(win, 0, 0, 0, 255);

  SDL_Surface *frogsurf = IMG_Load("frog.png");
  SDL_Texture *frog = SDL_CreateTextureFromSurface(ren, frogsurf);
  SDL_FreeSurface(frogsurf);

  SDL_Event e;
  
  int quit = 0;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)
	quit = 1;
    }
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, frog, NULL, NULL);
    SDL_RenderPresent(ren);
  }
  SDL_DestroyTexture(frog);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  
  IMG_Quit();
  SDL_Quit();
  return 0;
}
