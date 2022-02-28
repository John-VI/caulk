// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

/* SDL_Surface *CLK_LoadSurface(const char filename[]) { */
/*   SDL_Surface *img = NULL; */
/*   //if ((img = IMG_Load(filename)) == NULL) */
/*     //logger->warn("Failed to load media {}: {}", filename, SDL_GetError()); */
/*   img = IMG_Load(filename); */
/*   return img; */
/* } */

/* SDL_Texture *CLK_LoadTexture(SDL_Renderer *ren, const char filename[]) { */
/*   SDL_Texture *tex = NULL; */
/*   SDL_Surface *surf = loadmedia(filename); */
/*   tex = SDL_CreateTextureFromSurface(ren, surf); */
/*   //if (tex == NULL)  */
/*   //  logger->warn("Couldn't load texture: {}", SDL_GetError()); */

/*   /\* SDL_FreeSurface(surf); *\/ */
/*   return tex; */
/* } */

#define CLK_DEFAULT_SPRITE_MODE 0b10000000
/* #define CLK_SpriteFromTextureDFLG(SDL_Renderer *ren, SDL_Texture *texture) \ */
/*   CLK_SpriteFromTextureCFLG(ren, texture, CLK_DEFAULT_SPRITE_MODE) */
/* #define _CLK_GET_SFT_OVERLOAD(_1,_2,_3,NAME,...) NAME */
/* #define CLK_SpriteFromTexture(...) _CLK_GET_SFT_OVERLOAD(__VA_ARGS__, CLK_SpriteFromTextureCFLG, \ */
/* 							 CLK_SpriteFromTextureDFLG)(__VA_ARGS__) */

typedef struct {
  SDL_Rect scalepostition;
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
} CLK_Font;

SDL_Texture *CLK_LoadTexture(SDL_Renderer *ren, const char[] filename) {
  SDL_Surface *surface = IMG_Load(filename);
  SDL_Texture *outputtexture = SDL_CreateTextureFromSurface(ren, surf);
  SDL_FreeSurface(surface);
  return outputtexture;
}

CLK_Sprite *CLK_SpriteFromTexture/*CFLG*/(SDL_Renderer *ren, SDL_Texture *texture, uint8_t mode) {
  CLK_Sprite *output = malloc(sizeof(CLK_Sprite));
  int w;
  int h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  output->scalepostition = { 0, 0, w, h };
  output->spritesheetpos = { 0, 0, 0, 0 };
  output->texture = texture;
  output->mode = mode;
  return output;
}

CLK_Sprite *CLK_SpriteFromFile(SDL_Renderer *ren, const char[] filename, uint8_t mode) {
  return CLK_SpriteFromTexture(ren, CLK_LoadTexture(ren, filename), mode);
}
