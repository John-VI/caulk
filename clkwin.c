// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <SDL2/SDL.h>
#include <stdint.h>

#include "clkwin.h"

SDL_Window *CLK_Window;
SDL_Renderer *CLK_Renderer;

SDL_Window *CLK_NewWindow(const char name[],  int width,
		    int height) {
  SDL_Window *win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
				     SDL_WINDOWPOS_UNDEFINED, width, height,
				     SDL_WINDOW_SHOWN);
  if (win == NULL) {
    // TODO: Implement logging
  }
  return win;
}

SDL_Renderer *CLK_NewRenderer( SDL_Window *win,  uint8_t r,  uint8_t g,
		      uint8_t b,  uint8_t a) {
  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (rend == NULL) { }
    // TODO: Implement logging
  else {
    SDL_SetRenderDrawColor(rend, r, g, b, a);
  }
  return rend;
}

SDL_Renderer *CLK_SetRenderer(SDL_Renderer *newren) {
  CLK_Renderer = newren;
  return CLK_Renderer;
}

SDL_Window *CLK_SetWindow(SDL_Window *newwin) {
  CLK_Window = newwin;
  return CLK_Window;
}
