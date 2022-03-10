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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>

#include "clktex.h"

#define CLK_DEFAULT_SPRITE_MODE 0b10000000
/* #define CLK_SpriteFromTextureDFLG(SDL_Renderer *ren, SDL_Texture *texture) \ */
/*   CLK_SpriteFromTextureCFLG(ren, texture, CLK_DEFAULT_SPRITE_MODE) */
/* #define _CLK_GET_SFT_OVERLOAD(_1,_2,_3,NAME,...) NAME */
/* #define CLK_SpriteFromTexture(...) _CLK_GET_SFT_OVERLOAD(__VA_ARGS__, CLK_SpriteFromTextureCFLG, \ */
/* 							 CLK_SpriteFromTextureDFLG)(__VA_ARGS__) */

extern SDL_Renderer *CLK_Renderer;

void CLK_DestroySprite(CLK_Sprite *sprite) {
  SDL_DestroyTexture(sprite->texture);
  free(sprite);
}

void CLK_DestroyFont(CLK_Font *font) {
  SDL_DestroyTexture(font->texture);
  free(font);
}

SDL_Texture *CLK_LoadTexture(const char filename[]) {
  SDL_Surface *surface = IMG_Load(filename);
  SDL_Texture *outputtexture = SDL_CreateTextureFromSurface(CLK_Renderer, surface);
  SDL_FreeSurface(surface);
  return outputtexture;
}

CLK_Sprite *CLK_SpriteFromTexture/*CFLG*/(SDL_Texture *texture, uint8_t mode) {
  CLK_Sprite *output = malloc(sizeof(CLK_Sprite));
  int w;
  int h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  output->scaleposition.x = 0;
  output->scaleposition.y = 0;
  output->scaleposition.w = w;
  output->scaleposition.h = h;
  output->spritesheetpos.x = 0;
  output->spritesheetpos.y = 0;
  output->spritesheetpos.w = 0;
  output->spritesheetpos.h = 0;
  output->texture = texture;
  output->mode = mode;
  return output;
}

CLK_Sprite *CLK_SpriteFromFile(const char filename[], uint8_t mode) {
  return CLK_SpriteFromTexture(CLK_LoadTexture(filename), mode);
}

CLK_Font *CLK_FontFromFile(const char filename[], const unsigned int charwidth, const unsigned int charheight,
			   const unsigned int charsperrow, const unsigned int charspercol) {
  SDL_Texture *texture = CLK_LoadTexture(filename);
  if (!texture)
    return NULL;
  
  CLK_Font *output = malloc(sizeof(CLK_Font));
  output->charw = charwidth;
  output->charh = charheight;
  output->cperr = charsperrow;
  output->cperc = charspercol;
  output->texture = texture;
  output->color = NULL;

  return output;
}
