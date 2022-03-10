#ifndef CLK_TEXTURE_H
#define CLK_TEXTURE_H

typedef struct {
  SDL_Rect scaleposition;
  SDL_Rect spritesheetpos;
  uint8_t mode;
  SDL_Texture *texture;
} CLK_Sprite;

typedef struct {
  unsigned int charw;
  unsigned int charh;
  unsigned int cperr;
  unsigned int cperc;
  SDL_Texture *texture;
  SDL_Color *color;
} CLK_Font;

void CLK_DestroySprite(CLK_Sprite *sprite);
void CLK_DestroyFont(CLK_Font *font);

CLK_Sprite *CLK_SpriteFromTexture(SDL_Texture *texture, uint8_t mode);
CLK_Sprite *CLK_SpriteFromFile(const char filename[], uint8_t mode);
CLK_Font *CLK_FontFromFile(const char filename[], const unsigned int charwidth, const unsigned int charheight,
			   const unsigned int charsperrow, const unsigned int charspercol);

#endif /* CLK_TEXTURE_H */
