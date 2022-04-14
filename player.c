// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include "monster.h"
#include "grid.h"
#include "messaging.h"

#include "player.h"

extern grid *cgrid;

int AI_Player(monster *mon, grid *g) {
  g->blocking = 1;
  g->inputblock = mon;
  return 0;
}

int move(SDL_Event e) {
  if (cgrid->blocking) {
    int destx = cgrid->inputblock->x;
    int desty = cgrid->inputblock->y;

    switch (e.key.keysym.sym) {
    case SDLK_KP_1:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx - 1, desty + 1);
      pushmessage("Folga wolga womp imp.");
      cgrid->blocking = 0;
      break;
    case SDLK_KP_4:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx - 1, desty);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_7:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx - 1, desty - 1);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_8:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx, desty - 1);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_9:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx + 1, desty - 1);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_6:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx + 1, desty);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_3:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx + 1, desty + 1);
      cgrid->blocking = 0;
      break;
    case SDLK_KP_2:
      grid_MoveMonster(cgrid, cgrid->inputblock, destx, desty + 1);
      cgrid->blocking = 0;
      break;
    }
  }
  return 0;
}
 
