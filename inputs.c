// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <SDL2/SDL.h>

#include "inputs.h"

enum translatedinput TranslateInputs() {
  SDL_Event e;
  int diff = SDLK_KP_1 - I_DOWNLEFT;
  
  if (SDL_PollEvent(&e) == 0)
    return I_NONE;
  
  switch (e.type) {

  case SDL_QUIT:
    return I_QUIT;
    
  case SDL_KEYDOWN:
    if (e.key.keysym.sym >= SDLK_KP_1 && e.key.keysym.sym <= SDLK_KP_9)
      return e.key.keysym.sym - diff;
  default:
    return TranslateInputs();
  }
}
