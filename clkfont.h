// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef CLK_FONT_H
#define CLK_FONT_H

#include "clktex.h"

CLK_Font *CLK_SetFont(CLK_Font *newfont);
int CLK_RenderChar(char character, const SDL_Color *altcolor, int x, int y);
int CLK_DrawGridChar(char character, const SDL_Color *altcolor, int r, int d);
int CLK_SetRect(SDL_Rect *newrect);
int CLK_RenderStr(const char str[], const SDL_Color *altcolor, int x, int y, unsigned int maxlen);
int CLK_DrawGridStr(const char str[], const SDL_Color *altcolor, int r, int d, unsigned int maxlen);

#endif /* CLK_FONT_H */
