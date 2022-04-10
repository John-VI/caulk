// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef MONSTER_H
#define MONSTER_H

#include <SDL2/SDL.h>

typedef struct monster monster;
typedef struct grid grid;

typedef struct monsterform {
  int maxhp;
  char c;
  SDL_Color *color;
  int (*aifunc)(monster*, grid*);
  int damage;
  int speed;
  uint16_t status;
} monsterform;

typedef struct monster {
  int maxhp;
  int hp;
  monsterform *form;
  int damage;
  uint16_t status;
  int x;
  int y;
  int speed;
  int meter;
  monster *next;
} monster;

void monster_Destroy(monster*);
int monster_Tick(monster*);
monster *createMonsterFromForm(const monsterform *form, int x, int y);
int monster_Draw(monster *m);

#endif /* MONSTER_H */
