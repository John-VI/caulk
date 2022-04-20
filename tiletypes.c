// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include "monster.h"
#include "grid.h"

#include "tiletypes.h"

coords triggertile(grid *g, monster *m, coords c) {
  tile *t = getGridTile(g, m->x, m->y);
  switch (t->info.tile_info->type) {
      case TILE_TELEPORT:
	c = grid_MoveMonster(g, m, t->info.tile_teleport->x, t->info.tile_teleport->y);
	break;
  }
  return c;
}

void makewall(grid *g, int x, int y) {
  tile *t = getGridTile(g, x, y);
  t->info = malloc(sizeof(tile_wall));
  t->info.wall->type = TILE_WALL;
  t->info.wall->flags = 0;
  t->info.wall->c = '#';
  t->info.wall->maxhp = 100;
  t->info.wall->hp = 100;
}

void makefloor(grid *g, int x, int y) {
  tile *t = getGridTile(g, x, y);
  t->info = malloc(sizeof(tile_floor));
  t->info.floor->type = TILE_FLOOR;
  t->info.floor->flags = 0;
  t->info.floor->c = '.';
}

void maketeleport(grid *g, int x, int y) {
  tile *t = getGridTile(g, x, y);
  t->info = malloc(sizeof(tile_teleport));
  t->info.teleport->type = TILE_TELEPORT;
  t->info.teleport->flags = 0;
  t->info.teleport->c = '^';
  t->info.teleport->x = 0;
  t->info.teleport->y = 0;
}
