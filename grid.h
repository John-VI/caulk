// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef GRID_H
#define GRID_H

#include "monster.h"

typedef struct tile {
  monster *monster;
  int type;
} tile;

typedef struct monsterlist {
  int size;
  monster *start;
} monsterlist;

typedef struct grid {
  int w;
  int h;
  monsterlist *mlist;
  tile *tiles; //This should always be equal to w * h
  int blocking;
  monster *inputblock;
} grid;

typedef struct coords {
  int x;
  int y;
} coords;

void tile_Destroy(tile*);
void grid_Destroy(grid*);
grid *newGrid(int w, int h);
tile *getGridTile(const grid *g, int x, int y);
coords spawnMonster(grid *g, const monsterform *form, int x, int y);
int grid_Tick(grid*);
int tile_Draw(const grid *g, int x, int y);
void grid_Draw(const grid*);
coords grid_MoveMonster(grid *g, monster *m, int x, int y);
monsterlist *createMonsterList();
void monsterlist_Destroy(monsterlist*);

#endif /* GRID_H */
