// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <stdlib.h>

#include "clkfont.h"
#include "grid.h"

#include "monster.h"

void monster_Destroy(monster *monster) {
  free(monster);
}

int monster_Tick(monster *monster) {
  if (monster == NULL)
    return 0;
  if ((monster->meter -= monster->speed) <= 0) {
    monster->meter += 100;
    return 1;
  }
  return 0;
}

int monster_Render(monster *monster) {
  return CLK_DrawGridChar(monster->form->c, monster->form->color, monster->x, monster->y);
}

void monsterform_Destroy(monsterform *form) {
  free(form);
}

monster *createMonsterFromForm(const monsterform *form, int x, int y) {
  monster *output = malloc(sizeof(monster));
  output->maxhp = form->maxhp;
  output->hp = output->maxhp;
  output->form = form;
  output->damage = form->damage;
  output->status = 0;
  output->speed = form->speed;
  output->meter = 0;
  output->status = form->status;
  output->x = x;
  output->y = y;
  output->next = NULL;
  return output;
}

int monster_Draw(monster *m) {
  return CLK_DrawGridChar(m->form->c, m->form->color, m->x, m->y);
}
