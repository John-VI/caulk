// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef CLK_FONT_H
#define CLK_FONT_H

#include "clktex.h"

CLK_Font *CLK_SetFont(CLK_Font *newfont);
int CLK_RenderChar(const char character, SDL_Color *altcolor, int x, int y);

#endif /* CLK_FONT_H */
