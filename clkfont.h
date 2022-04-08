// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef CLK_FONT_H
#define CLK_FONT_H

#include "clktex.h"

CLK_Font *CLK_SetFont(CLK_Font *newfont);
int CLK_RenderChar(const char character, const SDL_Color *altcolor, const int x, const int y);
int CLK_DrawGridChar(const char character, const SDL_Color *altcolor, const int r, const int d);
int CLK_SetRect(SDL_Rect *newrect);

#endif /* CLK_FONT_H */
