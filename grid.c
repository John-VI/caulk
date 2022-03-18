// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

typedef tile;

typedef struct {
  int maxhp;
  char c;
  SDL_Color *color;
  int (*aifunc)(*monster);
  int damage;
} monsterform;

typedef struct {
  int maxhp;
  int hp;
  monsterform *form;
  int damage;
  uint16_t status;
  tile *tile;
} monster;

typedef struct {
  int x;
  int y;
  monster *monster;
} tile;

typedef struct {
  int w;
  int h;
  tile **tiles; //This should always be equal to w * h
} grid;

grid currentgrid;

void monsterform_Destroy(monsterform *form) {
  free(form);
}

void monster_Destroy(monster *monster) {
  monster->tile->monster = NULL;
  free(monster);
}

void tile_Destroy(tile *tile) {
  monsterform_Destroy(tile->monster); //Ensure there's no orphaned monsters
  free(tile);
}

void grid_Destroy(grid *grid) {
  for (int i < w * h)
    tile_Destroy(grid->tiles[i]);
  free(grid->tiles);
  free(grid);
}

grid *newGrid(int w, int h) {
  grid *output = malloc(sizeof(grid));
  output->tiles = calloc(w * h, sizeof(tile*));
  output->w = w;
  output->h = h;
  return output;
}

tile *getGridTile(grid *grid, int x, int y) {
  return grid->tiles[grid->w * y + x];
}

monster *createMonsterFromForm(monsterform *form, int x, int y) {
  monster *output = malloc(sizeof(monster));
  output->maxhp = form->maxhp;
  output->hp = output->maxhp;
  output->form = form;
  output->damage = form->damage;
  output->status = 0;
  output->tile = getGridTile(currentgrid, x, y);
  output->tile->monster = output;
  return output;
}

