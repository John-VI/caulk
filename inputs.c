// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <SDL2/SDL.h>

#include "inputs.h"

void (*quitaction)();

int processinputs(keycell keybinds[], int keybindsl) {
  SDL_Event e;
  int processed;
  
  while (SDL_PollEvent(&e) != 0) {
    switch (e.type) {

    case SDL_QUIT:
      quitaction();
      processed++;
      break;
    
    case SDL_KEYDOWN:
      for (int i = 0; i < keybindsl; i++)
	if (keybinds[i].code == e.key.keysym.sym) {
	  keybinds[i].action();
	  processed++;
	}
      break;
    }
  }
  return processed;
}

void setquitaction(void (exitfunc())) {
  quitaction = exitfunc;
}
