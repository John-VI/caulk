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
#include "inputs.h"
#include "monster.h"
#include "grid.h"
#include "player.h"
#include "messaging.h"

#define INTWID 480
#define INTHEI 416

int quit = 0;
int inc = 0;
grid *cgrid;
SDL_Color white = { 255, 255, 255 };

void exeunt() {
  quit = 1;
}

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
  CLK_Font *vga = CLK_FontFromFile("compac.png", 8, 16, 96, 1);
  CLK_SetFont(vga);

  setquitaction(exeunt);
  keycell keybinds[8] = { { SDLK_KP_1, move }, { SDLK_KP_2, move }, { SDLK_KP_3, move }, { SDLK_KP_4, move },
			  { SDLK_KP_9, move }, { SDLK_KP_6, move }, { SDLK_KP_7, move }, { SDLK_KP_8, move } };

  cgrid = newGrid(40, 24);
  monsterform form = { 100, '@', &white, AI_Player, 1, 50, 0 };
  spawnMonster(cgrid, &form, 4, 4);
  SDL_Rect messrect = { 0, 0, 20 * 8, 26 * 16 };
  SDL_Rect gamerect = { 20 * 8, 0, 40 * 8, 24 * 16 };
  SDL_Rect statrect = { 20 * 8, 24 * 16, 40 * 8, 2 * 16 };

  messaging_Init();
  
  while (!quit) {
    processinputs(keybinds, 8);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, frog->texture, NULL, NULL);

    CLK_SetRect(&gamerect);
    grid_Tick(cgrid);
    grid_Draw(cgrid);

    CLK_SetRect(&messrect);
    drawnewmessages();

    CLK_SetRect(&statrect);
    CLK_DrawGridStr("Status", NULL, 0, 0, 0);
    
    SDL_RenderPresent(ren);
  }

  messaging_Deinit();
  grid_Destroy(cgrid);
  CLK_DestroySprite(frog);
  CLK_DestroyFont(vga);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  
  IMG_Quit();
  SDL_Quit();
  return 0;
}
