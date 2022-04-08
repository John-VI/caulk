// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <SDL2/SDL.h>

#include "clktex.h"

#include "clkfont.h"

#define START_CHAR 32

CLK_Font *_CLK_Current_Font = NULL;
SDL_Color _CLK_Default_Font_Color = { 255, 255, 255, 255 };
extern SDL_Renderer *CLK_Renderer;
SDL_Rect *_CLK_Current_Grid = NULL;

CLK_Font *CLK_SetFont(CLK_Font *newfont) {
  return _CLK_Current_Font = newfont;
}

int CLK_SetRect(SDL_Rect *newrect) {
  return _CLK_Current_Grid = newrect;
}

int CLK_RenderChar(const char character, const SDL_Color *altcolor, const int x, const int y) {
  const SDL_Color *ccolor = altcolor ? altcolor :
    (_CLK_Current_Font->color ? _CLK_Current_Font->color : &_CLK_Default_Font_Color);
  SDL_Rect srcrect = { (character - 32) % _CLK_Current_Font->cperr * _CLK_Current_Font->charw,
    (character - 32) / _CLK_Current_Font->cperr * _CLK_Current_Font->charh,
    _CLK_Current_Font->charw, _CLK_Current_Font->charh };
  SDL_Rect destrect = { x, y, _CLK_Current_Font->charw, _CLK_Current_Font->charh };

  return SDL_RenderCopy(CLK_Renderer,
			_CLK_Current_Font->texture,
			&srcrect, &destrect);
}

int CLK_DrawGridChar(const char character, const SDL_Color *altcolor, const int r, const int d) {
  return CLK_RenderChar(character, altcolor, _CLK_Current_Grid->x + (r * _CLK_Current_Font->charw),
			_CLK_Current_Grid->y + (d * _CLK_Current_Font->charh));
}
