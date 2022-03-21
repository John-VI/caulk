// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef INPUTS_H
#define INPUTS_H

typedef struct {
  SDL_Keycode code;
  int (*action)();
} keycell;

int processinputs(keycell keybinds[], int keybindsl);
void setquitaction(void (exitfunc()));

#endif /* INPUTS_H */
