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
	tile *tiles; //This should always be equal to w * h
} grid;

grid currentgrid;

tile *getGridTile(grid *grid, int x, int y) {
	return grid->tiles[grid->w * y + x];

void monsterform_Destroy(monsterform *form) {
	free(form);
}

void monster_Destroy(monster *monster) {
	free(monster);
}

void tile_Destroy(tile *tile) {
	free(tile->monster); //Ensure there's no orphaned monsters
	free(tile);
}

monster *createMonsterFromForm(monsterform *form, int x, int y) {
	monster *output = malloc(sizeof(monster));
	output->maxhp = form->maxhp;
	output->hp = output->maxhp;
	output->form = form;
	output->damage = form->damage;
	output->status = 0;
	output->tile = getGridTile(currentgrid, x, y);
	return output;
}