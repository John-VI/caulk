#include "sdlhelper.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_ttf.h>

SDL_Window *newwin(const std::string name,  int width,
		    int height) {
  SDL_Window *win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
				     SDL_WINDOWPOS_UNDEFINED, width, height,
				     SDL_WINDOW_SHOWN);
  if (win == NULL) {
    logger->critical("Window failed! {}", SDL_GetError());
  }
  return win;
}

SDL_Renderer *newren( SDL_Window *win,  Uint8 r,  Uint8 g,
		      Uint8 b,  Uint8 a) {
  SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (rend == NULL)
    logger->critical("Could not create renderer! {}", SDL_GetError());
  else {
    SDL_SetRenderDrawColor(rend, r, g, b, a);
  }
  return rend;
}
