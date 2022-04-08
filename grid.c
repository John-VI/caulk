// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <stdlib.h>

#include "clkfont.h"
#include "monster.h"

#include "grid.h"

monsterlist *createMonsterlist() {
  monsterlist *output = malloc(sizeof(monsterlist));
  output->size = 0;
  output->start = NULL;
  return output;
}

void monsterlist_Destroy(monsterlist *list) {
  monster *cmonster = list->start;
  monster *nextmonst;
  for (int i = 0; i < list->size; i++) {
    if (cmonster == NULL)
      break;
    nextmonst = cmonster->next;
    monster_Destroy(cmonster);
    cmonster = nextmonst;
  }
  free(list);
}

void monsterlist_Append(monsterlist *list, monster *m) {
  if (list->size) {
    monster *cmonster = list->start;
    while (cmonster->next)
      cmonster = cmonster->next;
    cmonster->next = m;
  }
  else {
    list->start = m;
  }
  list->size++;
}

void tile_Destroy(tile *tile) {
  // monsterform_Destroy(tile->monster); //Ensure there's no orphaned monsters
  free(tile);
}

void grid_Destroy(grid *grid) {
  /* for (int i < w * h) */
  /*   tile_Destroy(grid->tiles[i]); */
  monsterlist_Destroy(grid->mlist);
  free(grid->tiles);
  free(grid);
}

grid *newGrid(int w, int h) {
  grid *output = malloc(sizeof(grid));
  output->tiles = calloc(w * h, sizeof(tile));
  output->w = w;
  output->h = h;
  output->mlist = createMonsterlist();
  output->blocking = 0;
  output->inputblock = NULL;
  return output;
}

tile *getGridTile(grid *grid, int x, int y) {
  return grid->tiles + (grid->w * y + x);
}

coords spawnMonster(grid *g, monsterform *form, int x, int y) {
  monster *nmonster = createMonsterFromForm(form, x, y);
  monsterlist_Append(g->mlist, nmonster);
  getGridTile(g, x, y)->monster = nmonster;
  coords output = { nmonster->x, nmonster->y };
  return output;
}

int grid_Tick(grid *g) {
  int moves = 0;
  monster *monster;
  if (g->blocking) {
    return 0;
  }
  if (g->inputblock) {
    monster = g->inputblock->next;
    g->inputblock = NULL;
  } else {
    monster = g->mlist->start;
  }
  
  while (monster) {
    if (moves += monster_Tick(monster))
      monster->form->aifunc(monster, g);
    monster = monster->next;
  }
  return moves;
}

int tile_Draw(grid *g, int x, int y) {
  tile *t = getGridTile(g, x, y);
  return CLK_DrawGridChar('.', NULL, x, y);
}

void grid_Draw(grid *g) {
  for (int x = 0; x < g->w; x++)
    for (int y = 0; y < g->h; y++)
      if (getGridTile(g, x, y)->monster)
	monster_Draw(getGridTile(g, x, y)->monster);
      else
	tile_Draw(g, x, y);
}

coords grid_MoveMonster(grid *g, monster *m, int x, int y) {
  getGridTile(g, m->x, m->y)->monster = NULL;
  getGridTile(g, x, y)->monster = m;
  m->x = x;
  m->y = y;
  coords output = { x, y };
  return output;
}

