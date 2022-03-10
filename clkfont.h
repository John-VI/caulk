#ifndef CLK_FONT_H
#define CLK_FONT_H

CLK_Font *CLK_SetFont(CLK_Font *newfont);
int CLK_RenderChar(const char character, SDL_Color *altcolor, int x, int y);

#endif /* CLK_FONT_H */
