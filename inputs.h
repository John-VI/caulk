// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef INPUTS_H
#define INPUTS_H

enum translatedinput { I_NONE, I_QUIT, I_DOWNLEFT, I_DOWN, I_DOWNRIGHT, I_LEFT,
  I_POWERGAP /* PLACEHOLDER: Don't question it */, I_RIGHT, I_UPLEFT, I_UP, I_UPRIGHT };

enum translatedinput TranslateInputs();

#endif /* INPUTS_H */
