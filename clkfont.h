// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef CLK_FONT_H
#define CLK_FONT_H

#include "clktex.h"

const CLK_Font *CLK_SetFont(CLK_Font *newfont);
const CLK_Font *CLK_GetFont();
int CLK_RenderChar(char character, const SDL_Color *altcolor, int x, int y);
int CLK_DrawGridChar(char character, const SDL_Color *altcolor, int r, int d);
const SDL_Rect *CLK_SetRect(SDL_Rect *newrect);
const SDL_Rect *CLK_GetRect();
int CLK_RenderStr(const char str[], const SDL_Color *altcolor, int x, int y, unsigned int maxlen);
int CLK_DrawGridStr(const char str[], const SDL_Color *altcolor, int r, int d, unsigned int maxlen);

#endif /* CLK_FONT_H */
